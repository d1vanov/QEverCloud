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

#ifndef QEVERCLOUD_GENERATED_BUSINESSUSERINFO_H
#define QEVERCLOUD_GENERATED_BUSINESSUSERINFO_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure is used to provide information about an Evernote Business
 * membership, for members who are part of a business.
 *
 * */
class QEVERCLOUD_EXPORT BusinessUserInfo: public Printable
{
    Q_GADGET
public:
    BusinessUserInfo();
    BusinessUserInfo(const BusinessUserInfo & other);
    BusinessUserInfo(BusinessUserInfo && other) noexcept;
    ~BusinessUserInfo() noexcept override;

    BusinessUserInfo & operator=(const BusinessUserInfo & other);
    BusinessUserInfo & operator=(BusinessUserInfo && other) noexcept;

    /**
     * The ID of the Evernote Business account that the user is a member of.
     * <dt>businessName
     * The human-readable name of the Evernote Business account that the user
     * is a member of.
     */
    [[nodiscard]] const std::optional<qint32> & businessId() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableBusinessId();
    void setBusinessId(std::optional<qint32> businessId);

    [[nodiscard]] const std::optional<QString> & businessName() const noexcept;
    void setBusinessName(std::optional<QString> businessName);

    /**
     * The role of the user within the Evernote Business account that
     * they are a member of.
     */
    [[nodiscard]] const std::optional<BusinessUserRole> & role() const noexcept;
    [[nodiscard]] std::optional<BusinessUserRole> & mutableRole();
    void setRole(std::optional<BusinessUserRole> role);

    /**
     * An e-mail address that will be used by the service in the context of your
     * Evernote Business activities. For example, this e-mail address will be used
     * when you e-mail a business note, when you update notes in the account of
     * your business, etc. The business e-mail cannot be used for identification
     * purposes such as for logging into the service.
     */
    [[nodiscard]] const std::optional<QString> & email() const noexcept;
    void setEmail(std::optional<QString> email);

    /**
     * Last time the business user or business user attributes were updated.
     */
    [[nodiscard]] const std::optional<Timestamp> & updated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableUpdated();
    void setUpdated(std::optional<Timestamp> updated);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const BusinessUserInfo & other) const noexcept;
    [[nodiscard]] bool operator!=(const BusinessUserInfo & other) const noexcept;

    Q_PROPERTY(std::optional<qint32> businessId READ businessId WRITE setBusinessId)
    Q_PROPERTY(std::optional<QString> businessName READ businessName WRITE setBusinessName)
    Q_PROPERTY(std::optional<BusinessUserRole> role READ role WRITE setRole)
    Q_PROPERTY(std::optional<QString> email READ email WRITE setEmail)
    Q_PROPERTY(std::optional<Timestamp> updated READ updated WRITE setUpdated)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::BusinessUserInfo)

#endif // QEVERCLOUD_GENERATED_BUSINESSUSERINFO_H
