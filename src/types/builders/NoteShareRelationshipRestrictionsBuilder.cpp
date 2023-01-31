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

#include <qevercloud/types/builders/NoteShareRelationshipRestrictionsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteShareRelationshipRestrictionsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_noSetReadNote;
    std::optional<bool> m_noSetModifyNote;
    std::optional<bool> m_noSetFullAccess;
};

NoteShareRelationshipRestrictionsBuilder::NoteShareRelationshipRestrictionsBuilder() :
    d(new NoteShareRelationshipRestrictionsBuilder::Impl)
{}

NoteShareRelationshipRestrictionsBuilder::NoteShareRelationshipRestrictionsBuilder(NoteShareRelationshipRestrictionsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteShareRelationshipRestrictionsBuilder::~NoteShareRelationshipRestrictionsBuilder() noexcept = default;

NoteShareRelationshipRestrictionsBuilder & NoteShareRelationshipRestrictionsBuilder::operator=(NoteShareRelationshipRestrictionsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteShareRelationshipRestrictionsBuilder & NoteShareRelationshipRestrictionsBuilder::setNoSetReadNote(std::optional<bool> noSetReadNote)
{
    d->m_noSetReadNote = std::move(noSetReadNote);
    return *this;
}

NoteShareRelationshipRestrictionsBuilder & NoteShareRelationshipRestrictionsBuilder::setNoSetModifyNote(std::optional<bool> noSetModifyNote)
{
    d->m_noSetModifyNote = std::move(noSetModifyNote);
    return *this;
}

NoteShareRelationshipRestrictionsBuilder & NoteShareRelationshipRestrictionsBuilder::setNoSetFullAccess(std::optional<bool> noSetFullAccess)
{
    d->m_noSetFullAccess = std::move(noSetFullAccess);
    return *this;
}

NoteShareRelationshipRestrictions NoteShareRelationshipRestrictionsBuilder::build()
{
    NoteShareRelationshipRestrictions result;

    result.setNoSetReadNote(std::move(d->m_noSetReadNote));
    result.setNoSetModifyNote(std::move(d->m_noSetModifyNote));
    result.setNoSetFullAccess(std::move(d->m_noSetFullAccess));

    d->m_noSetReadNote = {};
    d->m_noSetModifyNote = {};
    d->m_noSetFullAccess = {};

    return result;
}

} // namespace qevercloud
