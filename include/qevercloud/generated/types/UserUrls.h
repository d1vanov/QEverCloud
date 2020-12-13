/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_USERURLS_H
#define QEVERCLOUD_GENERATED_USERURLS_H

#include "../../Export.h"

#include <qevercloud/EverCloudException.h>
#include <qevercloud/Printable.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <optional>

namespace qevercloud {

/**
 * */
class QEVERCLOUD_EXPORT UserUrls: public Printable
{
    Q_GADGET
public:
    UserUrls();
    UserUrls(const UserUrls & other);
    UserUrls(UserUrls && other) noexcept;
    ~UserUrls() noexcept override;

    UserUrls & operator=(const UserUrls & other);
    UserUrls & operator=(UserUrls && other) noexcept;

    /**
    This field will contain the full URL that clients should use to make
       NoteStore requests to the server shard that contains that user's data.
       I.e. this is the URL that should be used to create the Thrift HTTP client
       transport to send messages to the NoteStore service for the account.
    */
    [[nodiscard]] const std::optional<QString> & noteStoreUrl() const noexcept;
    void setNoteStoreUrl(std::optional<QString> noteStoreUrl);

    /**
    This field will contain the initial part of the URLs that should be used
       to make requests to Evernote's thin client "web API", which provide
       optimized operations for clients that aren't capable of manipulating
       the full contents of accounts via the full Thrift data model. Clients
       should concatenate the relative path for the various servlets onto the
       end of this string to construct the full URL, as documented on our
       developer web site.
    */
    [[nodiscard]] const std::optional<QString> & webApiUrlPrefix() const noexcept;
    void setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix);

    /**
    This field will contain the full URL that clients should use to make UserStore
       requests after successfully authenticating. I.e. this is the URL that should be used
       to create the Thrift HTTP client transport to send messages to the UserStore service
       for this account.
    */
    [[nodiscard]] const std::optional<QString> & userStoreUrl() const noexcept;
    void setUserStoreUrl(std::optional<QString> userStoreUrl);

    /**
    This field will contain the full URL that clients should use to make Utility requests
       to the server shard that contains that user's data. I.e. this is the URL that should
       be used to create the Thrift HTTP client transport to send messages to the Utility
       service for the account.
    */
    [[nodiscard]] const std::optional<QString> & utilityUrl() const noexcept;
    void setUtilityUrl(std::optional<QString> utilityUrl);

    /**
    This field will contain the full URL that clients should use to make MessageStore
       requests to the server. I.e. this is the URL that should be used to create the
       Thrift HTTP client transport to send messages to the MessageStore service for the
       account.
    */
    [[nodiscard]] const std::optional<QString> & messageStoreUrl() const noexcept;
    void setMessageStoreUrl(std::optional<QString> messageStoreUrl);

    /**
    This field will contain the full URL that clients should use when opening a
       persistent web socket to receive notification of events for the authenticated user.
    */
    [[nodiscard]] const std::optional<QString> & userWebSocketUrl() const noexcept;
    void setUserWebSocketUrl(std::optional<QString> userWebSocketUrl);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const UserUrls & other) const noexcept;
    [[nodiscard]] bool operator!=(const UserUrls & other) const noexcept;

    Q_PROPERTY(std::optional<QString> noteStoreUrl READ noteStoreUrl WRITE setNoteStoreUrl)
    Q_PROPERTY(std::optional<QString> webApiUrlPrefix READ webApiUrlPrefix WRITE setWebApiUrlPrefix)
    Q_PROPERTY(std::optional<QString> userStoreUrl READ userStoreUrl WRITE setUserStoreUrl)
    Q_PROPERTY(std::optional<QString> utilityUrl READ utilityUrl WRITE setUtilityUrl)
    Q_PROPERTY(std::optional<QString> messageStoreUrl READ messageStoreUrl WRITE setMessageStoreUrl)
    Q_PROPERTY(std::optional<QString> userWebSocketUrl READ userWebSocketUrl WRITE setUserWebSocketUrl)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::UserUrls)

#endif // QEVERCLOUD_GENERATED_USERURLS_H
