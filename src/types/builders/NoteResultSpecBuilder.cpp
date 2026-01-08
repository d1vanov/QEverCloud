/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/NoteResultSpecBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteResultSpecBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_includeContent;
    std::optional<bool> m_includeResourcesData;
    std::optional<bool> m_includeResourcesRecognition;
    std::optional<bool> m_includeResourcesAlternateData;
    std::optional<bool> m_includeSharedNotes;
    std::optional<bool> m_includeNoteAppDataValues;
    std::optional<bool> m_includeResourceAppDataValues;
    std::optional<bool> m_includeAccountLimits;
};

NoteResultSpecBuilder::NoteResultSpecBuilder() :
    d(new NoteResultSpecBuilder::Impl)
{}

NoteResultSpecBuilder::NoteResultSpecBuilder(NoteResultSpecBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteResultSpecBuilder::~NoteResultSpecBuilder() noexcept = default;

NoteResultSpecBuilder & NoteResultSpecBuilder::operator=(NoteResultSpecBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteResultSpecBuilder & NoteResultSpecBuilder::setIncludeContent(std::optional<bool> includeContent)
{
    d->m_includeContent = std::move(includeContent);
    return *this;
}

NoteResultSpecBuilder & NoteResultSpecBuilder::setIncludeResourcesData(std::optional<bool> includeResourcesData)
{
    d->m_includeResourcesData = std::move(includeResourcesData);
    return *this;
}

NoteResultSpecBuilder & NoteResultSpecBuilder::setIncludeResourcesRecognition(std::optional<bool> includeResourcesRecognition)
{
    d->m_includeResourcesRecognition = std::move(includeResourcesRecognition);
    return *this;
}

NoteResultSpecBuilder & NoteResultSpecBuilder::setIncludeResourcesAlternateData(std::optional<bool> includeResourcesAlternateData)
{
    d->m_includeResourcesAlternateData = std::move(includeResourcesAlternateData);
    return *this;
}

NoteResultSpecBuilder & NoteResultSpecBuilder::setIncludeSharedNotes(std::optional<bool> includeSharedNotes)
{
    d->m_includeSharedNotes = std::move(includeSharedNotes);
    return *this;
}

NoteResultSpecBuilder & NoteResultSpecBuilder::setIncludeNoteAppDataValues(std::optional<bool> includeNoteAppDataValues)
{
    d->m_includeNoteAppDataValues = std::move(includeNoteAppDataValues);
    return *this;
}

NoteResultSpecBuilder & NoteResultSpecBuilder::setIncludeResourceAppDataValues(std::optional<bool> includeResourceAppDataValues)
{
    d->m_includeResourceAppDataValues = std::move(includeResourceAppDataValues);
    return *this;
}

NoteResultSpecBuilder & NoteResultSpecBuilder::setIncludeAccountLimits(std::optional<bool> includeAccountLimits)
{
    d->m_includeAccountLimits = std::move(includeAccountLimits);
    return *this;
}

NoteResultSpec NoteResultSpecBuilder::build()
{
    NoteResultSpec result;

    result.setIncludeContent(std::move(d->m_includeContent));
    result.setIncludeResourcesData(std::move(d->m_includeResourcesData));
    result.setIncludeResourcesRecognition(std::move(d->m_includeResourcesRecognition));
    result.setIncludeResourcesAlternateData(std::move(d->m_includeResourcesAlternateData));
    result.setIncludeSharedNotes(std::move(d->m_includeSharedNotes));
    result.setIncludeNoteAppDataValues(std::move(d->m_includeNoteAppDataValues));
    result.setIncludeResourceAppDataValues(std::move(d->m_includeResourceAppDataValues));
    result.setIncludeAccountLimits(std::move(d->m_includeAccountLimits));

    d->m_includeContent = {};
    d->m_includeResourcesData = {};
    d->m_includeResourcesRecognition = {};
    d->m_includeResourcesAlternateData = {};
    d->m_includeSharedNotes = {};
    d->m_includeNoteAppDataValues = {};
    d->m_includeResourceAppDataValues = {};
    d->m_includeAccountLimits = {};

    return result;
}

} // namespace qevercloud
