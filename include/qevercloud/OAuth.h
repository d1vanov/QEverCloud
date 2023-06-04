/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_OAUTH_H
#define QEVERCLOUD_OAUTH_H

#include <qevercloud/Export.h>
#include <qevercloud/Types.h>
#include <qevercloud/utility/Printable.h>

#include <QDialog>
#include <QList>
#include <QNetworkCookie>
#include <QString>
#include <QUrl>

namespace qevercloud {

/** @cond HIDDEN_SYMBOLS  */
class EvernoteOAuthWidgetPrivate;
/** @endcond */

/**
 * @brief The class is tailored specifically for OAuth authorization with Evernote.
 *
 * While it is functional by itself it would probably be easier to use
 * EvernoteOAuthDialog as it provides simpler higher level API for OAuth.
 */
class QEVERCLOUD_EXPORT EvernoteOAuthWidget: public QWidget
{
    Q_OBJECT
public:
    EvernoteOAuthWidget(QWidget * parent = nullptr);

    /**
     * This function starts the OAuth sequence. In the end of the sequence one of
     * the following signals would be emitted: authenticationSuceeded or authenticationFailed.
     *
     * Do not call the function while its call is already in effect, i.e. before one of
     * the signals is emitted after the previous call.
     *
     * @param serverUrl
     * Evernote server url to authorize with. You probably need one of these:
     * <ul>
     * <li>"https://www.evernote.com" - Evernote production server</li>
     * <li>"https://sandox.evernote.com" - "Sandbox" server for developers</li>
     * <li>"https://yinxiang.com" - Chinese Evernote server</li>
     * </ul>
     * @param consumerKey
     * get it <a href="http://dev.evernote.com/doc/">from the Evernote</a>
     * @param consumerSecret
     * along with this
     * @param connectionTimeoutMsec
     * Networl connection timeout in milliseconds
     */
    void authenticate(
        QUrl serverUrl, QString consumerKey, QString consumerSecret,
        const qint64 connectionTimeoutMsec = 30000);

    /**
      * @return true if the last call to authenticate resulted in a successful
      * authentication.
     */
    [[nodiscard]] bool isSucceeded() const noexcept;

    /**
     * @return error message resulted from the last call to authenticate.
     */
    [[nodiscard]] QString oauthError() const;

    /**
     * Holds the data returned by Evernote on a successful authentication
     */
    struct QEVERCLOUD_EXPORT OAuthResult: public Printable
    {
        /// note store url for the user; no need to call IUserStore::getNoteStoreUrl
        QString noteStoreUrl;
        Timestamp expires; ///< authenticationToken time of expiration.
        QString shardId; ///< usually is not used
        UserID userId; ///< same as PublicUserInfo::userId
        QString webApiUrlPrefix; ///< see PublicUserInfo::webApiUrlPrefix
        QString authenticationToken; ///< This is what this all was for!

        /**
         * Cookies set by Evernote during OAuth procedure. In April 2020 these
         * cookies silently started to be required for UserStore API calls.
         * Probably it was a bug on Evernote side which hopefully would be
         * fixed at some point but nevertheless cookies set during OAuth
         * procedure are now available as a part of OAuth result and can be
         * used in subsequent calls to Evernote service. These cookies can
         * be set when creating an instance of IRequestContext. Then this
         * context can be used in QEverCloud calls. Cookies from context would
         * propagate to HTTP requests performed by QEverCloud.
         * See this thread on Evernote discussions for more details:
         * https://discussion.evernote.com/topic/124257-calls-to-userstore-from-evernote-api-stopped-working
         */
        QList<QNetworkCookie> cookies;

        void print(QTextStream & strm) const override;
    };

    /**
     * @return the result of the last authentication, i.e. authenticate() call.
     */
    [[nodiscard]] OAuthResult oauthResult() const;

    /**
     * The method is useful to specify default size for a EverOAuthWidget.
     */
    void setSizeHint(QSize sizeHint);

    [[nodiscard]] QSize sizeHint() const override;

Q_SIGNALS:
    /** Emitted when the OAuth sequence started with authenticate() call is finished */
    void authenticationFinished(bool success);

    /**
     * Emitted when the OAuth sequence is successfully finished. Call
     * oauthResult() to get the data.
     */
    void authenticationSuceeded();

    /**
     * Emitted when the OAuth sequence is finished with a failure. Some error
     * info may be available with errorText().
     */
    void authenticationFailed();

private:
    EvernoteOAuthWidgetPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(EvernoteOAuthWidget)
};

/** @cond HIDDEN_SYMBOLS  */
class EvernoteOAuthDialogPrivate;
/** @endcond */

/**
 * @brief Authorizes your app with the Evernote service by means of OAuth
 * authentication.
 *
 * Intended usage:
 *
@code
#include <qevercloud/OAuth.h>

EvernoteOAuthDialog d{myConsumerKey, myConsumerSecret, QUrl{QStringLiteral("https://www.evernote.com")}};
if (d.exec() == QDialog::Accepted) {
    auto result = d.oauthResult();
    // Connect to Evernote
    ...
}
else {
    QString errorText = d.oauthError();
    // handle authentication error
    ...
}
@endcode
 */

class QEVERCLOUD_EXPORT EvernoteOAuthDialog: public QDialog
{
    Q_OBJECT
public:
    using OAuthResult = EvernoteOAuthWidget::OAuthResult;

    /** Constructs the dialog.
     *
     * @param serverUrl
     * Evernote server url to authorize with. You probably need one of these:
     * <ul>
     * <li>"https://www.evernote.com" - Evernote production server</li>
     * <li>"https://sandox.evernote.com" - "Sandbox" server for developers</li>
     * <li>"https://yinxiang.com" - Chinese Evernote server</li>
     * </ul>
     * @param consumerKey
     * get it <a href="http://dev.evernote.com/doc/">from the Evernote</a>
     * @param consumerSecret
     * along with this
    */
    EvernoteOAuthDialog(
        QString consumerKey, QString consumerSecret,
        QUrl serverUrl = QUrl{QStringLiteral("https://www.evernote.com")},
        QWidget * parent = nullptr);

    ~EvernoteOAuthDialog() override;

    /**
     * The dialog adjusts its initial size automatically based on the contained
     * QWidget preffered size. Use this method to set the size.
     *
     * @param sizeHint will be used as the preffered size of the contained QWidget
     */
    void setWidgetSizeHint(QSize sizeHint);

    /** @return true in case of a successful authentication.
     *          You probably better check exec() return value instead.
     */
    [[nodiscard]] bool isSucceeded() const noexcept;

    /**
     * @return In case of an authentification error may return some information
     *         about the error.
     */
    [[nodiscard]] QString oauthError() const;

    /**
     * @return the result of a successful authentication.
     */
    [[nodiscard]] OAuthResult oauthResult() const;

    /**
     * @return
     *   QDialog::Accepted on a successful authentication.
     */
    [[nodiscard]] int exec() override;

    /** Shows the dialog as a window modal dialog, returning immediately.
     */
    void open() override;

private:
    EvernoteOAuthDialogPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(EvernoteOAuthDialog)
};

} // namespace qevercloud

#endif // QEVERCLOUD_OAUTH_H
