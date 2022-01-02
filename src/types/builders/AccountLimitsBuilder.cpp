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

#include <qevercloud/types/builders/AccountLimitsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN AccountLimitsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<qint32> m_userMailLimitDaily;
    std::optional<qint64> m_noteSizeMax;
    std::optional<qint64> m_resourceSizeMax;
    std::optional<qint32> m_userLinkedNotebookMax;
    std::optional<qint64> m_uploadLimit;
    std::optional<qint32> m_userNoteCountMax;
    std::optional<qint32> m_userNotebookCountMax;
    std::optional<qint32> m_userTagCountMax;
    std::optional<qint32> m_noteTagCountMax;
    std::optional<qint32> m_userSavedSearchesMax;
    std::optional<qint32> m_noteResourceCountMax;
};

AccountLimitsBuilder::AccountLimitsBuilder() :
    d(new AccountLimitsBuilder::Impl)
{}

AccountLimitsBuilder::AccountLimitsBuilder(AccountLimitsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

AccountLimitsBuilder::~AccountLimitsBuilder() noexcept = default;

AccountLimitsBuilder & AccountLimitsBuilder::operator=(AccountLimitsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setUserMailLimitDaily(std::optional<qint32> userMailLimitDaily)
{
    d->m_userMailLimitDaily = std::move(userMailLimitDaily);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setNoteSizeMax(std::optional<qint64> noteSizeMax)
{
    d->m_noteSizeMax = std::move(noteSizeMax);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setResourceSizeMax(std::optional<qint64> resourceSizeMax)
{
    d->m_resourceSizeMax = std::move(resourceSizeMax);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setUserLinkedNotebookMax(std::optional<qint32> userLinkedNotebookMax)
{
    d->m_userLinkedNotebookMax = std::move(userLinkedNotebookMax);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setUploadLimit(std::optional<qint64> uploadLimit)
{
    d->m_uploadLimit = std::move(uploadLimit);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setUserNoteCountMax(std::optional<qint32> userNoteCountMax)
{
    d->m_userNoteCountMax = std::move(userNoteCountMax);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setUserNotebookCountMax(std::optional<qint32> userNotebookCountMax)
{
    d->m_userNotebookCountMax = std::move(userNotebookCountMax);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setUserTagCountMax(std::optional<qint32> userTagCountMax)
{
    d->m_userTagCountMax = std::move(userTagCountMax);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setNoteTagCountMax(std::optional<qint32> noteTagCountMax)
{
    d->m_noteTagCountMax = std::move(noteTagCountMax);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setUserSavedSearchesMax(std::optional<qint32> userSavedSearchesMax)
{
    d->m_userSavedSearchesMax = std::move(userSavedSearchesMax);
    return *this;
}

AccountLimitsBuilder & AccountLimitsBuilder::setNoteResourceCountMax(std::optional<qint32> noteResourceCountMax)
{
    d->m_noteResourceCountMax = std::move(noteResourceCountMax);
    return *this;
}

AccountLimits AccountLimitsBuilder::build()
{
    AccountLimits result;

    result.setUserMailLimitDaily(std::move(d->m_userMailLimitDaily));
    result.setNoteSizeMax(std::move(d->m_noteSizeMax));
    result.setResourceSizeMax(std::move(d->m_resourceSizeMax));
    result.setUserLinkedNotebookMax(std::move(d->m_userLinkedNotebookMax));
    result.setUploadLimit(std::move(d->m_uploadLimit));
    result.setUserNoteCountMax(std::move(d->m_userNoteCountMax));
    result.setUserNotebookCountMax(std::move(d->m_userNotebookCountMax));
    result.setUserTagCountMax(std::move(d->m_userTagCountMax));
    result.setNoteTagCountMax(std::move(d->m_noteTagCountMax));
    result.setUserSavedSearchesMax(std::move(d->m_userSavedSearchesMax));
    result.setNoteResourceCountMax(std::move(d->m_noteResourceCountMax));

    d->m_userMailLimitDaily = {};
    d->m_noteSizeMax = {};
    d->m_resourceSizeMax = {};
    d->m_userLinkedNotebookMax = {};
    d->m_uploadLimit = {};
    d->m_userNoteCountMax = {};
    d->m_userNotebookCountMax = {};
    d->m_userTagCountMax = {};
    d->m_noteTagCountMax = {};
    d->m_userSavedSearchesMax = {};
    d->m_noteResourceCountMax = {};

    return result;
}

} // namespace qevercloud
