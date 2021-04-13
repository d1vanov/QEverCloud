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

#ifndef QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONS
#define QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONS

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ShareRelationshipRestrictions: public Printable
{
    Q_GADGET
public:
    ShareRelationshipRestrictions();
    ShareRelationshipRestrictions(const ShareRelationshipRestrictions & other);
    ShareRelationshipRestrictions(ShareRelationshipRestrictions && other) noexcept;
    ~ShareRelationshipRestrictions() noexcept override;

    ShareRelationshipRestrictions & operator=(const ShareRelationshipRestrictions & other);
    ShareRelationshipRestrictions & operator=(ShareRelationshipRestrictions && other) noexcept;

    [[nodiscard]] const std::optional<bool> & noSetReadOnly() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetReadOnly();
    void setNoSetReadOnly(std::optional<bool> noSetReadOnly);

    [[nodiscard]] const std::optional<bool> & noSetReadPlusActivity() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetReadPlusActivity();
    void setNoSetReadPlusActivity(std::optional<bool> noSetReadPlusActivity);

    [[nodiscard]] const std::optional<bool> & noSetModify() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetModify();
    void setNoSetModify(std::optional<bool> noSetModify);

    [[nodiscard]] const std::optional<bool> & noSetFullAccess() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetFullAccess();
    void setNoSetFullAccess(std::optional<bool> noSetFullAccess);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<bool> noSetReadOnly READ noSetReadOnly WRITE setNoSetReadOnly)
    Q_PROPERTY(std::optional<bool> noSetReadPlusActivity READ noSetReadPlusActivity WRITE setNoSetReadPlusActivity)
    Q_PROPERTY(std::optional<bool> noSetModify READ noSetModify WRITE setNoSetModify)
    Q_PROPERTY(std::optional<bool> noSetFullAccess READ noSetFullAccess WRITE setNoSetFullAccess)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const ShareRelationshipRestrictions & lhs, const ShareRelationshipRestrictions & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const ShareRelationshipRestrictions & lhs, const ShareRelationshipRestrictions & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ShareRelationshipRestrictions)

#endif // QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONS
