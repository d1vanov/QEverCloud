/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONSIMPL
#define QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONSIMPL

#include <qevercloud/types/ShareRelationshipRestrictions.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ShareRelationshipRestrictions::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const ShareRelationshipRestrictions::Impl & other) = default;
    Impl(ShareRelationshipRestrictions::Impl && other) noexcept = default;

    ShareRelationshipRestrictions::Impl & operator=(const ShareRelationshipRestrictions::Impl & other) = delete;
    ShareRelationshipRestrictions::Impl & operator=(ShareRelationshipRestrictions::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_noSetReadOnly;
    std::optional<bool> m_noSetReadPlusActivity;
    std::optional<bool> m_noSetModify;
    std::optional<bool> m_noSetFullAccess;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHARERELATIONSHIPRESTRICTIONSIMPL
