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

#include <qevercloud/generated/types/NoteResultSpec.h>

#include "impl/NoteResultSpecImpl.h"

namespace qevercloud {

NoteResultSpec::NoteResultSpec() :
    d(new NoteResultSpec::Impl)
 {}

NoteResultSpec::NoteResultSpec(const NoteResultSpec & other) :
    d(other.d)
{}

NoteResultSpec::NoteResultSpec(NoteResultSpec && other) noexcept :
    d(std::move(other.d))
{}

NoteResultSpec::~NoteResultSpec() noexcept {}

NoteResultSpec & NoteResultSpec::operator=(const NoteResultSpec & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteResultSpec & NoteResultSpec::operator=(NoteResultSpec && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<bool> & NoteResultSpec::includeContent() const noexcept
{
    return d->m_includeContent;
}

std::optional<bool> & NoteResultSpec::mutableIncludeContent()
{
    return d->m_includeContent;
}

void NoteResultSpec::setIncludeContent(std::optional<bool> includeContent)
{
    d->m_includeContent = includeContent;
}

const std::optional<bool> & NoteResultSpec::includeResourcesData() const noexcept
{
    return d->m_includeResourcesData;
}

std::optional<bool> & NoteResultSpec::mutableIncludeResourcesData()
{
    return d->m_includeResourcesData;
}

void NoteResultSpec::setIncludeResourcesData(std::optional<bool> includeResourcesData)
{
    d->m_includeResourcesData = includeResourcesData;
}

const std::optional<bool> & NoteResultSpec::includeResourcesRecognition() const noexcept
{
    return d->m_includeResourcesRecognition;
}

std::optional<bool> & NoteResultSpec::mutableIncludeResourcesRecognition()
{
    return d->m_includeResourcesRecognition;
}

void NoteResultSpec::setIncludeResourcesRecognition(std::optional<bool> includeResourcesRecognition)
{
    d->m_includeResourcesRecognition = includeResourcesRecognition;
}

const std::optional<bool> & NoteResultSpec::includeResourcesAlternateData() const noexcept
{
    return d->m_includeResourcesAlternateData;
}

std::optional<bool> & NoteResultSpec::mutableIncludeResourcesAlternateData()
{
    return d->m_includeResourcesAlternateData;
}

void NoteResultSpec::setIncludeResourcesAlternateData(std::optional<bool> includeResourcesAlternateData)
{
    d->m_includeResourcesAlternateData = includeResourcesAlternateData;
}

const std::optional<bool> & NoteResultSpec::includeSharedNotes() const noexcept
{
    return d->m_includeSharedNotes;
}

std::optional<bool> & NoteResultSpec::mutableIncludeSharedNotes()
{
    return d->m_includeSharedNotes;
}

void NoteResultSpec::setIncludeSharedNotes(std::optional<bool> includeSharedNotes)
{
    d->m_includeSharedNotes = includeSharedNotes;
}

const std::optional<bool> & NoteResultSpec::includeNoteAppDataValues() const noexcept
{
    return d->m_includeNoteAppDataValues;
}

std::optional<bool> & NoteResultSpec::mutableIncludeNoteAppDataValues()
{
    return d->m_includeNoteAppDataValues;
}

void NoteResultSpec::setIncludeNoteAppDataValues(std::optional<bool> includeNoteAppDataValues)
{
    d->m_includeNoteAppDataValues = includeNoteAppDataValues;
}

const std::optional<bool> & NoteResultSpec::includeResourceAppDataValues() const noexcept
{
    return d->m_includeResourceAppDataValues;
}

std::optional<bool> & NoteResultSpec::mutableIncludeResourceAppDataValues()
{
    return d->m_includeResourceAppDataValues;
}

void NoteResultSpec::setIncludeResourceAppDataValues(std::optional<bool> includeResourceAppDataValues)
{
    d->m_includeResourceAppDataValues = includeResourceAppDataValues;
}

const std::optional<bool> & NoteResultSpec::includeAccountLimits() const noexcept
{
    return d->m_includeAccountLimits;
}

std::optional<bool> & NoteResultSpec::mutableIncludeAccountLimits()
{
    return d->m_includeAccountLimits;
}

void NoteResultSpec::setIncludeAccountLimits(std::optional<bool> includeAccountLimits)
{
    d->m_includeAccountLimits = includeAccountLimits;
}

void NoteResultSpec::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteResultSpec::operator==(const NoteResultSpec & other) const noexcept
{
    return *d == *other.d;
}

bool NoteResultSpec::operator!=(const NoteResultSpec & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
