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

#include <qevercloud/generated/types/AccountLimits.h>

#include "impl/AccountLimitsImpl.h"

namespace qevercloud {

AccountLimits::AccountLimits() :
    d(new AccountLimits::Impl)
 {}

AccountLimits::AccountLimits(const AccountLimits & other) :
    d(other.d)
{}

AccountLimits::AccountLimits(AccountLimits && other) noexcept :
    d(std::move(other.d))
{}

AccountLimits::~AccountLimits() noexcept {}

AccountLimits & AccountLimits::operator=(const AccountLimits & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

AccountLimits & AccountLimits::operator=(AccountLimits && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<qint32> & AccountLimits::userMailLimitDaily() const noexcept
{
    return d->m_userMailLimitDaily;
}

std::optional<qint32> & AccountLimits::mutableUserMailLimitDaily()
{
    return d->m_userMailLimitDaily;
}

void AccountLimits::setUserMailLimitDaily(std::optional<qint32> userMailLimitDaily)
{
    d->m_userMailLimitDaily = userMailLimitDaily;
}

const std::optional<qint64> & AccountLimits::noteSizeMax() const noexcept
{
    return d->m_noteSizeMax;
}

std::optional<qint64> & AccountLimits::mutableNoteSizeMax()
{
    return d->m_noteSizeMax;
}

void AccountLimits::setNoteSizeMax(std::optional<qint64> noteSizeMax)
{
    d->m_noteSizeMax = noteSizeMax;
}

const std::optional<qint64> & AccountLimits::resourceSizeMax() const noexcept
{
    return d->m_resourceSizeMax;
}

std::optional<qint64> & AccountLimits::mutableResourceSizeMax()
{
    return d->m_resourceSizeMax;
}

void AccountLimits::setResourceSizeMax(std::optional<qint64> resourceSizeMax)
{
    d->m_resourceSizeMax = resourceSizeMax;
}

const std::optional<qint32> & AccountLimits::userLinkedNotebookMax() const noexcept
{
    return d->m_userLinkedNotebookMax;
}

std::optional<qint32> & AccountLimits::mutableUserLinkedNotebookMax()
{
    return d->m_userLinkedNotebookMax;
}

void AccountLimits::setUserLinkedNotebookMax(std::optional<qint32> userLinkedNotebookMax)
{
    d->m_userLinkedNotebookMax = userLinkedNotebookMax;
}

const std::optional<qint64> & AccountLimits::uploadLimit() const noexcept
{
    return d->m_uploadLimit;
}

std::optional<qint64> & AccountLimits::mutableUploadLimit()
{
    return d->m_uploadLimit;
}

void AccountLimits::setUploadLimit(std::optional<qint64> uploadLimit)
{
    d->m_uploadLimit = uploadLimit;
}

const std::optional<qint32> & AccountLimits::userNoteCountMax() const noexcept
{
    return d->m_userNoteCountMax;
}

std::optional<qint32> & AccountLimits::mutableUserNoteCountMax()
{
    return d->m_userNoteCountMax;
}

void AccountLimits::setUserNoteCountMax(std::optional<qint32> userNoteCountMax)
{
    d->m_userNoteCountMax = userNoteCountMax;
}

const std::optional<qint32> & AccountLimits::userNotebookCountMax() const noexcept
{
    return d->m_userNotebookCountMax;
}

std::optional<qint32> & AccountLimits::mutableUserNotebookCountMax()
{
    return d->m_userNotebookCountMax;
}

void AccountLimits::setUserNotebookCountMax(std::optional<qint32> userNotebookCountMax)
{
    d->m_userNotebookCountMax = userNotebookCountMax;
}

const std::optional<qint32> & AccountLimits::userTagCountMax() const noexcept
{
    return d->m_userTagCountMax;
}

std::optional<qint32> & AccountLimits::mutableUserTagCountMax()
{
    return d->m_userTagCountMax;
}

void AccountLimits::setUserTagCountMax(std::optional<qint32> userTagCountMax)
{
    d->m_userTagCountMax = userTagCountMax;
}

const std::optional<qint32> & AccountLimits::noteTagCountMax() const noexcept
{
    return d->m_noteTagCountMax;
}

std::optional<qint32> & AccountLimits::mutableNoteTagCountMax()
{
    return d->m_noteTagCountMax;
}

void AccountLimits::setNoteTagCountMax(std::optional<qint32> noteTagCountMax)
{
    d->m_noteTagCountMax = noteTagCountMax;
}

const std::optional<qint32> & AccountLimits::userSavedSearchesMax() const noexcept
{
    return d->m_userSavedSearchesMax;
}

std::optional<qint32> & AccountLimits::mutableUserSavedSearchesMax()
{
    return d->m_userSavedSearchesMax;
}

void AccountLimits::setUserSavedSearchesMax(std::optional<qint32> userSavedSearchesMax)
{
    d->m_userSavedSearchesMax = userSavedSearchesMax;
}

const std::optional<qint32> & AccountLimits::noteResourceCountMax() const noexcept
{
    return d->m_noteResourceCountMax;
}

std::optional<qint32> & AccountLimits::mutableNoteResourceCountMax()
{
    return d->m_noteResourceCountMax;
}

void AccountLimits::setNoteResourceCountMax(std::optional<qint32> noteResourceCountMax)
{
    d->m_noteResourceCountMax = noteResourceCountMax;
}

void AccountLimits::print(QTextStream & strm) const
{
    d->print(strm);
}

bool AccountLimits::operator==(const AccountLimits & other) const noexcept
{
    return *d == *other.d;
}

bool AccountLimits::operator!=(const AccountLimits & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
