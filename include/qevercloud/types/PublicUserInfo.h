/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_PUBLICUSERINFO
#define QEVERCLOUD_GENERATED_PUBLICUSERINFO

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure is used to provide publicly-available user information
 * about a particular account.
 **/
class QEVERCLOUD_EXPORT PublicUserInfo: public Printable
{
    Q_GADGET
public:
    PublicUserInfo();
    PublicUserInfo(const PublicUserInfo & other);
    PublicUserInfo(PublicUserInfo && other) noexcept;
    ~PublicUserInfo() noexcept override;

    PublicUserInfo & operator=(const PublicUserInfo & other);
    PublicUserInfo & operator=(PublicUserInfo && other) noexcept;

    /**
     * The unique numeric user identifier for the user account.
     */
    [[nodiscard]] UserID userId() const noexcept;
    void setUserId(UserID userId);

    /**
     * The service level of the account.
     */
    [[nodiscard]] const std::optional<ServiceLevel> & serviceLevel() const noexcept;
    [[nodiscard]] std::optional<ServiceLevel> & mutableServiceLevel();
    void setServiceLevel(std::optional<ServiceLevel> serviceLevel);

    [[nodiscard]] const std::optional<QString> & username() const noexcept;
    void setUsername(std::optional<QString> username);

    /**
     * This field will contain the full URL that clients should use to make
     * NoteStore requests to the server shard that contains that user's data.
     * I.e. this is the URL that should be used to create the Thrift HTTP client
     * transport to send messages to the NoteStore service for the account.
     */
    [[nodiscard]] const std::optional<QString> & noteStoreUrl() const noexcept;
    void setNoteStoreUrl(std::optional<QString> noteStoreUrl);

    /**
     * This field will contain the initial part of the URLs that should be used
     * to make requests to Evernote's thin client "web API", which provide
     * optimized operations for clients that aren't capable of manipulating
     * the full contents of accounts via the full Thrift data model. Clients
     * should concatenate the relative path for the various servlets onto the
     * end of this string to construct the full URL, as documented on our
     * developer web site.
     */
    [[nodiscard]] const std::optional<QString> & webApiUrlPrefix() const noexcept;
    void setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(UserID userId READ userId WRITE setUserId)
    Q_PROPERTY(std::optional<ServiceLevel> serviceLevel READ serviceLevel WRITE setServiceLevel)
    Q_PROPERTY(std::optional<QString> username READ username WRITE setUsername)
    Q_PROPERTY(std::optional<QString> noteStoreUrl READ noteStoreUrl WRITE setNoteStoreUrl)
    Q_PROPERTY(std::optional<QString> webApiUrlPrefix READ webApiUrlPrefix WRITE setWebApiUrlPrefix)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const PublicUserInfo & lhs, const PublicUserInfo & rhs) noexcept;
[[nodiscard]] bool operator!=(const PublicUserInfo & lhs, const PublicUserInfo & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::PublicUserInfo)

#endif // QEVERCLOUD_GENERATED_PUBLICUSERINFO
