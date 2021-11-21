/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Http.h"

#include "NetworkCookieJar.h"

#include <Globals.h>
#include <Helpers.h>
#include <Log.h>
#include <OAuth.h>

#include <QLocale>
#include <QNetworkCookie>
#include <QNetworkCookieJar>
#include <QNetworkReply>
#include <QVBoxLayout>
#include <QUuid>

#if QEVERCLOUD_USE_QT_WEB_ENGINE
#include <QWebEngineProfile>
#include <QWebEngineView>
#include <QWebEngineHistory>
#else
#include <QNetworkRequest>
#include <QWebView>
#include <QWebSettings>
#include <QWebHistory>
#endif

#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
#include <QRandomGenerator>
#endif

#include <cstring>

/** @cond HIDDEN_SYMBOLS  */

namespace {

////////////////////////////////////////////////////////////////////////////////

quint64 random64()
{
    quint64 res = 0;
    for(int i = 0; i < 8; i++) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 10, 0)
        res += (QRandomGenerator::global()->generate64() % 256) << i*8;
#else
        res += static_cast<quint64>(qrand() % 256) << i*8;
#endif
    }

    QByteArray randomData = QUuid::createUuid().toRfc4122();
    quint64 random;
    std::memcpy(&random, &randomData.constData()[0], sizeof(random));

    res ^= random;

    std::memcpy(
        &random,
        &randomData.constData()[sizeof(random)],
        sizeof(random));

    res ^= random;
    return res;
}

typedef quint64 (*NonceGenerator)();
NonceGenerator nonceGenerator_ = random64;

NonceGenerator nonceGenerator() {return nonceGenerator_;}

QString httpAcceptLanguage()
{
    auto uiLanguages = QLocale::system().uiLanguages();
    const QString en = QStringLiteral("en");
    if (!uiLanguages.contains(en)) {
        uiLanguages << en;
    }

    return uiLanguages.join(QStringLiteral(", "));
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

void setNonceGenerator(quint64 (*nonceGenerator)())
{
    nonceGenerator_ = nonceGenerator;
}

////////////////////////////////////////////////////////////////////////////////

#if QEVERCLOUD_USE_QT_WEB_ENGINE
class EvernoteOAuthWebViewPrivate: public QWebEngineView
#else
class EvernoteOAuthWebViewPrivate: public QWebView
#endif
{
    Q_OBJECT
public:
    EvernoteOAuthWebViewPrivate(QWidget * parent = Q_NULLPTR);

Q_SIGNALS:
    void authenticationFinished(bool success);
    void authenticationSuceeded();
    void authenticationFailed();

public Q_SLOTS:
    void temporaryFinished(QObject * rf);
    void permanentFinished(QObject * rf);
    void onUrlChanged(const QUrl & url);
    void clearHtml();

private:
    void extractCookies(ReplyFetcher * pReplyFetcher);

public:
    void setError(QString error);

    bool        m_isSucceeded = false;
    QSize       m_sizeHint;
    QString     m_errorText;
    QString     m_oauthUrlBase;
    QString     m_host;
    qint64      m_timeoutMsec = 0;
    EvernoteOAuthWebView::OAuthResult   m_oauthResult;

#if QEVERCLOUD_USE_QT_WEB_ENGINE
    NetworkCookieJar * m_pCookieJar;
#endif
};

////////////////////////////////////////////////////////////////////////////////

EvernoteOAuthWebViewPrivate::EvernoteOAuthWebViewPrivate(QWidget * parent)
#if QEVERCLOUD_USE_QT_WEB_ENGINE
    : QWebEngineView(parent)
#else
    : QWebView(parent)
#endif
{
#if !QEVERCLOUD_USE_QT_WEB_ENGINE
    page()->networkAccessManager()->setProxy(evernoteNetworkProxy());
    page()->networkAccessManager()->setCookieJar(new NetworkCookieJar);
#else
    m_pCookieJar = new NetworkCookieJar(this);
    m_pCookieJar->loadStore();

    page()->profile()->defaultProfile()->setHttpAcceptLanguage(
        httpAcceptLanguage());
#endif
}

void EvernoteOAuthWebViewPrivate::setError(QString errorText)
{
    m_isSucceeded = false;
    this->setHtml(QLatin1String(""));
    this->history()->clear();
    m_errorText = errorText;
    emit authenticationFinished(false);
    emit authenticationFailed();
}

void EvernoteOAuthWebViewPrivate::temporaryFinished(QObject * rf)
{
    ReplyFetcher * replyFetcher = qobject_cast<ReplyFetcher*>(rf);
    if (replyFetcher->isError())
    {
        QEC_WARNING("oauth", "Failed to acquire temporary token: "
            << replyFetcher->errorText());
        setError(replyFetcher->errorText());
    }
    else
    {
        QEC_DEBUG("oauth", "Successfully acquired temporary token");
        QString reply = QString::fromUtf8(replyFetcher->receivedData().constData());
        int index = reply.indexOf(QStringLiteral("&oauth_token_secret"));
        QString token = reply.left(index);

        // step 2: directing a user to the login page
        QEC_DEBUG("oauth", "Setting up login window");
        QObject::connect(this, &EvernoteOAuthWebViewPrivate::urlChanged,
                         this, &EvernoteOAuthWebViewPrivate::onUrlChanged);
        QUrl loginUrl(QString::fromUtf8("https://%1//OAuth.action?%2")
                      .arg(m_host, token));

#if QEVERCLOUD_USE_QT_WEB_ENGINE
        setUrl(loginUrl);
#else
        QNetworkRequest request;
        request.setUrl(loginUrl);
        request.setRawHeader(
            QByteArray("Accept-Language"), httpAcceptLanguage().toUtf8());

        load(request);
#endif
    }

    replyFetcher->deleteLater();
}

void EvernoteOAuthWebViewPrivate::onUrlChanged(const QUrl & url)
{
    // step 3: catch the redirect to our callback url (nnoauth)
    QString s = url.toString();
    QString oauthMarker = QStringLiteral("?oauth_token=");
    if (s.contains(QStringLiteral("nnoauth?")) && s.contains(oauthMarker))
    {
        if (s.contains(QStringLiteral("&oauth_verifier=")))
        {
            QEC_DEBUG("oauth", "Received approval for permanent token receipt");

            QString token = s.mid(s.indexOf(oauthMarker) + oauthMarker.length());

            // step 4: acquire permanent token
            QEC_DEBUG("oauth", "Sending request to acquire permanent token");
            ReplyFetcher * replyFetcher = new ReplyFetcher();
            QObject::connect(replyFetcher, &ReplyFetcher::replyFetched,
                             this, &EvernoteOAuthWebViewPrivate::permanentFinished);
            QUrl url(m_oauthUrlBase + QStringLiteral("&oauth_token=%1").arg(token));
#if QEVERCLOUD_USE_QT_WEB_ENGINE
            auto * pNam = new QNetworkAccessManager(replyFetcher);
            pNam->setCookieJar(new NetworkCookieJar);
#else
            auto * pNam = page()->networkAccessManager();
#endif
            pNam->setProxy(evernoteNetworkProxy());
            replyFetcher->start(pNam, url, m_timeoutMsec);
        }
        else
        {
            QEC_WARNING("oauth", "Authentication failed");
            setError(QStringLiteral("Authentification failed."));
        }

        QObject::disconnect(this, &EvernoteOAuthWebViewPrivate::urlChanged,
                            this, &EvernoteOAuthWebViewPrivate::onUrlChanged);
        QMetaObject::invokeMethod(this, "clearHtml", Qt::QueuedConnection);
    }
}

void EvernoteOAuthWebViewPrivate::permanentFinished(QObject * rf)
{
    ReplyFetcher * pReplyFetcher = qobject_cast<ReplyFetcher*>(rf);
    if (pReplyFetcher->isError())
    {
        QEC_WARNING("oauth", "Failed to acquire permanent token");
        setError(pReplyFetcher->errorText());
    }
    else
    {
        QEC_DEBUG("oauth", "Successfully acquired permanent token");

        m_isSucceeded = true;

        QByteArray reply = pReplyFetcher->receivedData();
        QMap<QString, QString> params;
        QList<QByteArray> vals = reply.split('&');

        for(int i = 0, size = vals.length(); i < size; i++)  {
            QString decoded = QUrl::fromPercentEncoding(vals[i]);
            int pos = decoded.indexOf(QStringLiteral("="));
            params[decoded.left(pos).trimmed()] = decoded.mid(pos + 1);
        }

        m_oauthResult.noteStoreUrl = params[QStringLiteral("edam_noteStoreUrl")];
        m_oauthResult.expires =
            Timestamp(params[QStringLiteral("edam_expires")].toLongLong());
        m_oauthResult.shardId = params[QStringLiteral("edam_shard")];
        m_oauthResult.userId = params[QStringLiteral("edam_userId")].toInt();
        m_oauthResult.webApiUrlPrefix =
            params[QStringLiteral("edam_webApiUrlPrefix")];
        m_oauthResult.authenticationToken = params[QStringLiteral("oauth_token")];

        extractCookies(pReplyFetcher);

        emit authenticationFinished(true);
        emit authenticationSuceeded();
    }

    pReplyFetcher->deleteLater();
}

void EvernoteOAuthWebViewPrivate::clearHtml()
{
    setHtml(QLatin1String(""));
}

void EvernoteOAuthWebViewPrivate::extractCookies(ReplyFetcher * pReplyFetcher)
{
#if QEVERCLOUD_USE_QT_WEB_ENGINE
    Q_UNUSED(pReplyFetcher)
    m_oauthResult.cookies = m_pCookieJar->allCookies();
#else
    QNetworkAccessManager * pNam = pReplyFetcher->networkAccessManager();
    if (Q_UNLIKELY(!pNam)) {
        QEC_WARNING("oauth", "Failed to extract cookies after OAuth: "
            << "network access manager instance expired");
        return;
    }

    auto * pCookieJar = qobject_cast<NetworkCookieJar*>(pNam->cookieJar());
    if (Q_UNLIKELY(!pCookieJar)) {
        QEC_WARNING("oauth", "Failed to extract cookies after OAuth: "
            << "unexpected instance of cookie jar");
        return;
    }

    m_oauthResult.cookies = pCookieJar->allCookies();
#endif

    QEC_DEBUG("oauth", "Got " << m_oauthResult.cookies.size()
        << " cookies after OAuth");
}

////////////////////////////////////////////////////////////////////////////////

EvernoteOAuthWebView::EvernoteOAuthWebView(QWidget * parent) :
    QWidget(parent),
    d_ptr(new EvernoteOAuthWebViewPrivate(this))
{
    QObject::connect(d_ptr, &EvernoteOAuthWebViewPrivate::authenticationFinished,
                     this, &EvernoteOAuthWebView::authenticationFinished);
    QObject::connect(d_ptr, &EvernoteOAuthWebViewPrivate::authenticationSuceeded,
                     this, &EvernoteOAuthWebView::authenticationSuceeded);
    QObject::connect(d_ptr, &EvernoteOAuthWebViewPrivate::authenticationFailed,
                     this, &EvernoteOAuthWebView::authenticationFailed);

    QVBoxLayout * pLayout = new QVBoxLayout(this);
    pLayout->addWidget(d_ptr);
    setLayout(pLayout);
}

void EvernoteOAuthWebView::authenticate(
    QString host, QString consumerKey, QString consumerSecret,
    const qint64 timeoutMsec)
{
    QEC_DEBUG("oauth", "Sending request to acquire temporary token");

    Q_D(EvernoteOAuthWebView);
    d->m_host = host;
    d->m_isSucceeded = false;
    d->m_timeoutMsec = timeoutMsec;
    d->setHtml(QLatin1String(""));
    d->history()->clear();

    qint64 timestamp = QDateTime::currentMSecsSinceEpoch()/1000;
    quint64 nonce = nonceGenerator()();
    d->m_oauthUrlBase =
        QString::fromUtf8("https://%1/oauth?oauth_consumer_key=%2&"
                          "oauth_signature=%3&"
                          "oauth_signature_method=PLAINTEXT&"
                          "oauth_timestamp=%4&oauth_nonce=%5")
        .arg(host, consumerKey, consumerSecret).arg(timestamp).arg(nonce);

    // step 1: acquire temporary token
    ReplyFetcher * replyFetcher = new ReplyFetcher();
    QObject::connect(replyFetcher, &ReplyFetcher::replyFetched,
                     d, &EvernoteOAuthWebViewPrivate::temporaryFinished);
    QUrl url(d->m_oauthUrlBase + QStringLiteral("&oauth_callback=nnoauth"));
#if QEVERCLOUD_USE_QT_WEB_ENGINE
    auto * pNam = new QNetworkAccessManager(replyFetcher);
#else
    auto * pNam = d->page()->networkAccessManager();
#endif
    pNam->setProxy(evernoteNetworkProxy());
    replyFetcher->start(pNam, url, timeoutMsec);
}

bool EvernoteOAuthWebView::isSucceeded() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->m_isSucceeded;
}

QString EvernoteOAuthWebView::oauthError() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->m_errorText;
}

EvernoteOAuthWebView::OAuthResult EvernoteOAuthWebView::oauthResult() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->m_oauthResult;
}

void EvernoteOAuthWebView::setSizeHint(QSize sizeHint)
{
    Q_D(EvernoteOAuthWebView);
    d->m_sizeHint = sizeHint;
    updateGeometry();
}

QSize EvernoteOAuthWebView::sizeHint() const
{
    Q_D(const EvernoteOAuthWebView);
    return d->m_sizeHint;
}

////////////////////////////////////////////////////////////////////////////////

void EvernoteOAuthWebView::OAuthResult::print(QTextStream & strm) const
{
    strm << "qevercloud::EvernoteOAuthWebView::OAuthResult {\n";

    strm << "  noteStoreUrl = " << noteStoreUrl << ";\n";
    strm << "  expires = " << expires << ";\n";
    strm << "  shardId = " << shardId << ";\n";
    strm << "  userId = " << QString::number(userId) << ";\n";
    strm << "  webApiUrlPrefix = " << webApiUrlPrefix << ";\n";
    strm << "  authenticationToken "
        << (authenticationToken.isEmpty()
            ? "is empty"
            : "is not empty") << ";\n";
    strm << "  cookies count: " << cookies.size() << ";\n";

    strm << "};\n";
}

////////////////////////////////////////////////////////////////////////////////

class EvernoteOAuthDialogPrivate
{
public:
    EvernoteOAuthDialogPrivate(const QString & host, const QString & consumerKey,
                               const QString & consumerSecret) :
        m_pWebView(Q_NULLPTR),
        m_host(host),
        m_consumerKey(consumerKey),
        m_consumerSecret(consumerSecret)
    {}

    EvernoteOAuthWebView*   m_pWebView;
    QString                 m_host;
    QString                 m_consumerKey;
    QString                 m_consumerSecret;
};

////////////////////////////////////////////////////////////////////////////////

EvernoteOAuthDialog::EvernoteOAuthDialog(QString consumerKey,
                                         QString consumerSecret,
                                         QString host, QWidget  *parent) :
    QDialog(parent),
    d_ptr(new EvernoteOAuthDialogPrivate(host, consumerKey, consumerSecret))
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    d_ptr->m_pWebView = new EvernoteOAuthWebView(this);

    QObject::connect(d_ptr->m_pWebView, &EvernoteOAuthWebView::authenticationSuceeded,
                     this, &EvernoteOAuthDialog::accept, Qt::QueuedConnection);
    QObject::connect(d_ptr->m_pWebView, &EvernoteOAuthWebView::authenticationFailed,
                     this, &EvernoteOAuthDialog::reject, Qt::QueuedConnection);

    QVBoxLayout * pLayout = new QVBoxLayout(this);
    pLayout->addWidget(d_ptr->m_pWebView);
    setLayout(pLayout);

    d_ptr->m_pWebView->setSizeHint(QSize(768,576));
    adjustSize();
}

EvernoteOAuthDialog::~EvernoteOAuthDialog()
{
#if !QEVERCLOUD_USE_QT_WEB_ENGINE
    QWebSettings::clearMemoryCaches();
#endif

    delete d_ptr;
}

void EvernoteOAuthDialog::setWebViewSizeHint(QSize sizeHint)
{
    Q_D(EvernoteOAuthDialog);
    d->m_pWebView->setSizeHint(sizeHint);
}

bool EvernoteOAuthDialog::isSucceeded() const
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWebView->isSucceeded();
}

QString EvernoteOAuthDialog::oauthError() const
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWebView->oauthError();
}

EvernoteOAuthDialog::OAuthResult EvernoteOAuthDialog::oauthResult() const
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWebView->oauthResult();
}

int EvernoteOAuthDialog::exec()
{
    Q_D(EvernoteOAuthDialog);
    d->m_pWebView->authenticate(d->m_host, d->m_consumerKey, d->m_consumerSecret);
    return QDialog::exec();
}

void EvernoteOAuthDialog::open()
{
    Q_D(EvernoteOAuthDialog);
    QDialog::open();
    d->m_pWebView->authenticate(d->m_host, d->m_consumerKey, d->m_consumerSecret);
}

} // namespace qevercloud

/** @endcond */

#include "OAuth.moc"
