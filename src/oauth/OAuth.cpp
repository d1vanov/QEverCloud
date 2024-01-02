/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2024 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <qevercloud/OAuth.h>
#include <qevercloud/VersionInfo.h>
#include <qevercloud/utility/Log.h>

#if QEVERCLOUD_USE_QT_WEB_ENGINE
#include "OAuthWebEngine.h"
#elif QEVERCLOUD_USE_SYSTEM_BROWSER
#include "OAuthSystemBrowser.h"
#endif

#include <QVBoxLayout>

namespace qevercloud {

EvernoteOAuthWidget::EvernoteOAuthWidget(QWidget * parent) :
    QWidget(parent),
    d_ptr(new EvernoteOAuthWidgetPrivate(this))
{
    QObject::connect(
        d_ptr, &EvernoteOAuthWidgetPrivate::authenticationFinished,
        this,
        [this](const bool success)
        {
            Q_EMIT authenticationFinished(success);

            if (success) {
                Q_EMIT authenticationSuceeded();
            }
            else {
                Q_EMIT authenticationFailed();
            }
        });

    QVBoxLayout * pLayout = new QVBoxLayout(this);
    pLayout->addWidget(d_ptr);
    setLayout(pLayout);
}

void EvernoteOAuthWidget::authenticate(
    QUrl serverUrl, QString consumerKey, QString consumerSecret,
    const qint64 timeoutMsec)
{
    QEC_DEBUG("oauth", "Sending request to acquire temporary token");

    Q_D(EvernoteOAuthWidget);
    d->authenticate(
        std::move(serverUrl), std::move(consumerKey), std::move(consumerSecret),
        timeoutMsec);
}

bool EvernoteOAuthWidget::isSucceeded() const noexcept
{
    Q_D(const EvernoteOAuthWidget);
    return d->isSucceeded();
}

QString EvernoteOAuthWidget::oauthError() const
{
    Q_D(const EvernoteOAuthWidget);
    return d->oauthError();
}

EvernoteOAuthWidget::OAuthResult EvernoteOAuthWidget::oauthResult() const
{
    Q_D(const EvernoteOAuthWidget);
    return d->oauthResult();
}

void EvernoteOAuthWidget::setSizeHint(QSize sizeHint)
{
    Q_D(EvernoteOAuthWidget);
    d->setSizeHint(sizeHint);
    updateGeometry();
}

QSize EvernoteOAuthWidget::sizeHint() const
{
    Q_D(const EvernoteOAuthWidget);
    return d->sizeHintValue();
}

////////////////////////////////////////////////////////////////////////////////

void EvernoteOAuthWidget::OAuthResult::print(QTextStream & strm) const
{
    strm << "qevercloud::EvernoteOAuthWidget::OAuthResult {\n";

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
    EvernoteOAuthDialogPrivate(
        QUrl serverUrl, QString consumerKey, QString consumerSecret) :
        m_pWidget{nullptr},
        m_serverUrl{std::move(serverUrl)},
        m_consumerKey{std::move(consumerKey)},
        m_consumerSecret{std::move(consumerSecret)}
    {}

    EvernoteOAuthWidget *   m_pWidget;
    QUrl                    m_serverUrl;
    QString                 m_consumerKey;
    QString                 m_consumerSecret;
};

////////////////////////////////////////////////////////////////////////////////

EvernoteOAuthDialog::EvernoteOAuthDialog(
    QString consumerKey, QString consumerSecret, QUrl serverUrl,
    QWidget * parent) :
    QDialog(parent),
    d_ptr(new EvernoteOAuthDialogPrivate(
        std::move(serverUrl), std::move(consumerKey), std::move(consumerSecret)))
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    d_ptr->m_pWidget = new EvernoteOAuthWidget(this);

    QObject::connect(
        d_ptr->m_pWidget, &EvernoteOAuthWidget::authenticationSuceeded,
        this, &EvernoteOAuthDialog::accept, Qt::QueuedConnection);

    QObject::connect(
        d_ptr->m_pWidget, &EvernoteOAuthWidget::authenticationFailed,
        this, &EvernoteOAuthDialog::reject, Qt::QueuedConnection);

    QVBoxLayout * pLayout = new QVBoxLayout(this);
    pLayout->addWidget(d_ptr->m_pWidget);
    setLayout(pLayout);

    d_ptr->m_pWidget->setSizeHint(QSize(768,576));
    adjustSize();
}

EvernoteOAuthDialog::~EvernoteOAuthDialog()
{
    delete d_ptr;
}

void EvernoteOAuthDialog::setWidgetSizeHint(QSize sizeHint)
{
    Q_D(EvernoteOAuthDialog);
    d->m_pWidget->setSizeHint(sizeHint);
}

bool EvernoteOAuthDialog::isSucceeded() const noexcept
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWidget->isSucceeded();
}

QString EvernoteOAuthDialog::oauthError() const
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWidget->oauthError();
}

EvernoteOAuthDialog::OAuthResult EvernoteOAuthDialog::oauthResult() const
{
    Q_D(const EvernoteOAuthDialog);
    return d->m_pWidget->oauthResult();
}

int EvernoteOAuthDialog::exec()
{
    Q_D(EvernoteOAuthDialog);
    d->m_pWidget->authenticate(d->m_serverUrl, d->m_consumerKey, d->m_consumerSecret);
    return QDialog::exec();
}

void EvernoteOAuthDialog::open()
{
    Q_D(EvernoteOAuthDialog);
    QDialog::open();
    d->m_pWidget->authenticate(d->m_serverUrl, d->m_consumerKey, d->m_consumerSecret);
}

} // namespace qevercloud

/** @endcond */
