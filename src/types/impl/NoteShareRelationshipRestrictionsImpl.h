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

#ifndef QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSIMPL
#define QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSIMPL

#include <qevercloud/types/NoteShareRelationshipRestrictions.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteShareRelationshipRestrictions::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteShareRelationshipRestrictions::Impl & other) = default;
    Impl(NoteShareRelationshipRestrictions::Impl && other) noexcept = default;

    NoteShareRelationshipRestrictions::Impl & operator=(const NoteShareRelationshipRestrictions::Impl & other) = delete;
    NoteShareRelationshipRestrictions::Impl & operator=(NoteShareRelationshipRestrictions::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_noSetReadNote;
    std::optional<bool> m_noSetModifyNote;
    std::optional<bool> m_noSetFullAccess;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSIMPL
