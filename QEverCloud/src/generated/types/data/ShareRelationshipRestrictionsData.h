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

#ifndef QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONSDATA_H
#define QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONSDATA_H

#include <generated/types/ShareRelationshipRestrictions.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ShareRelationshipRestrictions::ShareRelationshipRestrictionsData final:
    public QSharedData,
    public Printable
{
public:
    ShareRelationshipRestrictionsData() = default;
    ShareRelationshipRestrictionsData(const ShareRelationshipRestrictionsData & other) = default;
    ShareRelationshipRestrictionsData(ShareRelationshipRestrictionsData && other) noexcept = default;

    ShareRelationshipRestrictionsData & operator=(const ShareRelationshipRestrictionsData & other) = delete;
    ShareRelationshipRestrictionsData & operator=(ShareRelationshipRestrictionsData && other) = delete;

    ~ShareRelationshipRestrictionsData() noexcept override = default;

    [[nodiscard]] bool operator==(const ShareRelationshipRestrictionsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ShareRelationshipRestrictionsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_noSetReadOnly;
    std::optional<bool> m_noSetReadPlusActivity;
    std::optional<bool> m_noSetModify;
    std::optional<bool> m_noSetFullAccess;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONSDATA_H
