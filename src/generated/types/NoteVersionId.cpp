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

#include <qevercloud/generated/types/NoteVersionId.h>

#include "impl/NoteVersionIdImpl.h"

namespace qevercloud {

NoteVersionId::NoteVersionId() :
    d(new NoteVersionId::Impl)
 {}

NoteVersionId::NoteVersionId(const NoteVersionId & other) :
    d(other.d)
{}

NoteVersionId::NoteVersionId(NoteVersionId && other) noexcept :
    d(std::move(other.d))
{}

NoteVersionId::~NoteVersionId() noexcept {}

NoteVersionId & NoteVersionId::operator=(const NoteVersionId & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteVersionId & NoteVersionId::operator=(NoteVersionId && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

qint32 NoteVersionId::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

void NoteVersionId::setUpdateSequenceNum(qint32 updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

Timestamp NoteVersionId::updated() const noexcept
{
    return d->m_updated;
}

void NoteVersionId::setUpdated(Timestamp updated)
{
    d->m_updated = updated;
}

Timestamp NoteVersionId::saved() const noexcept
{
    return d->m_saved;
}

void NoteVersionId::setSaved(Timestamp saved)
{
    d->m_saved = saved;
}

const QString & NoteVersionId::title() const noexcept
{
    return d->m_title;
}

void NoteVersionId::setTitle(QString title)
{
    d->m_title = title;
}

const std::optional<UserID> & NoteVersionId::lastEditorId() const noexcept
{
    return d->m_lastEditorId;
}

std::optional<UserID> & NoteVersionId::mutableLastEditorId()
{
    return d->m_lastEditorId;
}

void NoteVersionId::setLastEditorId(std::optional<UserID> lastEditorId)
{
    d->m_lastEditorId = lastEditorId;
}

void NoteVersionId::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteVersionId::operator==(const NoteVersionId & other) const noexcept
{
    return *d == *other.d;
}

bool NoteVersionId::operator!=(const NoteVersionId & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
