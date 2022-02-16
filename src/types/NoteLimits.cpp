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

#include <qevercloud/types/NoteLimits.h>

#include "impl/NoteLimitsImpl.h"

namespace qevercloud {

NoteLimits::NoteLimits() :
    d(new NoteLimits::Impl)
{}

NoteLimits::NoteLimits(const NoteLimits & other) :
    d(other.d)
{}

NoteLimits::NoteLimits(NoteLimits && other) noexcept :
    d(std::move(other.d))
{}

NoteLimits::~NoteLimits() noexcept {}

NoteLimits & NoteLimits::operator=(const NoteLimits & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteLimits & NoteLimits::operator=(NoteLimits && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<qint32> & NoteLimits::noteResourceCountMax() const noexcept
{
    return d->m_noteResourceCountMax;
}

std::optional<qint32> & NoteLimits::mutableNoteResourceCountMax()
{
    return d->m_noteResourceCountMax;
}

void NoteLimits::setNoteResourceCountMax(std::optional<qint32> noteResourceCountMax)
{
    d->m_noteResourceCountMax = noteResourceCountMax;
}

const std::optional<qint64> & NoteLimits::uploadLimit() const noexcept
{
    return d->m_uploadLimit;
}

std::optional<qint64> & NoteLimits::mutableUploadLimit()
{
    return d->m_uploadLimit;
}

void NoteLimits::setUploadLimit(std::optional<qint64> uploadLimit)
{
    d->m_uploadLimit = uploadLimit;
}

const std::optional<qint64> & NoteLimits::resourceSizeMax() const noexcept
{
    return d->m_resourceSizeMax;
}

std::optional<qint64> & NoteLimits::mutableResourceSizeMax()
{
    return d->m_resourceSizeMax;
}

void NoteLimits::setResourceSizeMax(std::optional<qint64> resourceSizeMax)
{
    d->m_resourceSizeMax = resourceSizeMax;
}

const std::optional<qint64> & NoteLimits::noteSizeMax() const noexcept
{
    return d->m_noteSizeMax;
}

std::optional<qint64> & NoteLimits::mutableNoteSizeMax()
{
    return d->m_noteSizeMax;
}

void NoteLimits::setNoteSizeMax(std::optional<qint64> noteSizeMax)
{
    d->m_noteSizeMax = noteSizeMax;
}

const std::optional<qint64> & NoteLimits::uploaded() const noexcept
{
    return d->m_uploaded;
}

std::optional<qint64> & NoteLimits::mutableUploaded()
{
    return d->m_uploaded;
}

void NoteLimits::setUploaded(std::optional<qint64> uploaded)
{
    d->m_uploaded = uploaded;
}

void NoteLimits::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const NoteLimits & noteLimits)
{
    strm << static_cast<const Printable&>(noteLimits);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const NoteLimits & noteLimits)
{
    dbg << static_cast<const Printable&>(noteLimits);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const NoteLimits & noteLimits)
{
    strm << static_cast<const Printable&>(noteLimits);
    return strm;
}

bool operator==(const NoteLimits & lhs, const NoteLimits & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.noteResourceCountMax() == rhs.noteResourceCountMax() &&
        lhs.uploadLimit() == rhs.uploadLimit() &&
        lhs.resourceSizeMax() == rhs.resourceSizeMax() &&
        lhs.noteSizeMax() == rhs.noteSizeMax() &&
        lhs.uploaded() == rhs.uploaded();
}

bool operator!=(const NoteLimits & lhs, const NoteLimits & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud