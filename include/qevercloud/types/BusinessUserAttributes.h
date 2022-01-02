/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTES
#define QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTES

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure holding the optional attributes associated with users
 * in a business.
 *
 * */
class QEVERCLOUD_EXPORT BusinessUserAttributes: public Printable
{
    Q_GADGET
public:
    BusinessUserAttributes();
    BusinessUserAttributes(const BusinessUserAttributes & other);
    BusinessUserAttributes(BusinessUserAttributes && other) noexcept;
    ~BusinessUserAttributes() noexcept override;

    BusinessUserAttributes & operator=(const BusinessUserAttributes & other);
    BusinessUserAttributes & operator=(BusinessUserAttributes && other) noexcept;

    /**
     * Free form text of this user's title in the business
     */
    [[nodiscard]] const std::optional<QString> & title() const noexcept;
    void setTitle(std::optional<QString> title);

    /**
     * City, State (for US) or City / Province for other countries
     */
    [[nodiscard]] const std::optional<QString> & location() const noexcept;
    void setLocation(std::optional<QString> location);

    /**
     * Free form text of the department this user belongs to.
     */
    [[nodiscard]] const std::optional<QString> & department() const noexcept;
    void setDepartment(std::optional<QString> department);

    /**
     * User's mobile phone number. Stored as plain text without any formatting.
     */
    [[nodiscard]] const std::optional<QString> & mobilePhone() const noexcept;
    void setMobilePhone(std::optional<QString> mobilePhone);

    /**
     * URL to user's public LinkedIn profile page. This should only contain
     * the portion relative to the base LinkedIn URL. For example: "/pub/john-smith/".
     */
    [[nodiscard]] const std::optional<QString> & linkedInProfileUrl() const noexcept;
    void setLinkedInProfileUrl(std::optional<QString> linkedInProfileUrl);

    /**
     * User's work phone number. Stored as plain text without any formatting.
     */
    [[nodiscard]] const std::optional<QString> & workPhone() const noexcept;
    void setWorkPhone(std::optional<QString> workPhone);

    /**
     * The date on which the user started working at their company.
     */
    [[nodiscard]] const std::optional<Timestamp> & companyStartDate() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableCompanyStartDate();
    void setCompanyStartDate(std::optional<Timestamp> companyStartDate);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const BusinessUserAttributes & businessUserAttributes);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const BusinessUserAttributes & businessUserAttributes);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const BusinessUserAttributes & businessUserAttributes);

    Q_PROPERTY(std::optional<QString> title READ title WRITE setTitle)
    Q_PROPERTY(std::optional<QString> location READ location WRITE setLocation)
    Q_PROPERTY(std::optional<QString> department READ department WRITE setDepartment)
    Q_PROPERTY(std::optional<QString> mobilePhone READ mobilePhone WRITE setMobilePhone)
    Q_PROPERTY(std::optional<QString> linkedInProfileUrl READ linkedInProfileUrl WRITE setLinkedInProfileUrl)
    Q_PROPERTY(std::optional<QString> workPhone READ workPhone WRITE setWorkPhone)
    Q_PROPERTY(std::optional<Timestamp> companyStartDate READ companyStartDate WRITE setCompanyStartDate)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const BusinessUserAttributes & lhs, const BusinessUserAttributes & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const BusinessUserAttributes & lhs, const BusinessUserAttributes & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::BusinessUserAttributes)

#endif // QEVERCLOUD_GENERATED_BUSINESSUSERATTRIBUTES
