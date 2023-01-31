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

#include <qevercloud/types/builders/NoteVersionIdBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteVersionIdBuilder::Impl final:
    public QSharedData
{
public:
    qint32 m_updateSequenceNum = 0;
    Timestamp m_updated = 0;
    Timestamp m_saved = 0;
    QString m_title;
    std::optional<UserID> m_lastEditorId;
};

NoteVersionIdBuilder::NoteVersionIdBuilder() :
    d(new NoteVersionIdBuilder::Impl)
{}

NoteVersionIdBuilder::NoteVersionIdBuilder(NoteVersionIdBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteVersionIdBuilder::~NoteVersionIdBuilder() noexcept = default;

NoteVersionIdBuilder & NoteVersionIdBuilder::operator=(NoteVersionIdBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteVersionIdBuilder & NoteVersionIdBuilder::setUpdateSequenceNum(qint32 updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
    return *this;
}

NoteVersionIdBuilder & NoteVersionIdBuilder::setUpdated(Timestamp updated)
{
    d->m_updated = updated;
    return *this;
}

NoteVersionIdBuilder & NoteVersionIdBuilder::setSaved(Timestamp saved)
{
    d->m_saved = saved;
    return *this;
}

NoteVersionIdBuilder & NoteVersionIdBuilder::setTitle(QString title)
{
    d->m_title = std::move(title);
    return *this;
}

NoteVersionIdBuilder & NoteVersionIdBuilder::setLastEditorId(std::optional<UserID> lastEditorId)
{
    d->m_lastEditorId = std::move(lastEditorId);
    return *this;
}

NoteVersionId NoteVersionIdBuilder::build()
{
    NoteVersionId result;

    result.setUpdateSequenceNum(d->m_updateSequenceNum);
    result.setUpdated(d->m_updated);
    result.setSaved(d->m_saved);
    result.setTitle(std::move(d->m_title));
    result.setLastEditorId(std::move(d->m_lastEditorId));

    d->m_updateSequenceNum = 0;
    d->m_updated = 0;
    d->m_saved = 0;
    d->m_title = QString{};
    d->m_lastEditorId = {};

    return result;
}

} // namespace qevercloud
