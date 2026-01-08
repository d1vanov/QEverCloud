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

#ifndef QEVERCLOUD_GENERATED_ACCOUNTLIMITSBUILDER
#define QEVERCLOUD_GENERATED_ACCOUNTLIMITSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/AccountLimits.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT AccountLimitsBuilder
{
public:
    AccountLimitsBuilder();

    AccountLimitsBuilder(AccountLimitsBuilder && other) noexcept;

    ~AccountLimitsBuilder() noexcept;

    AccountLimitsBuilder & operator=(AccountLimitsBuilder && other) noexcept;

    AccountLimitsBuilder & setUserMailLimitDaily(std::optional<qint32> userMailLimitDaily);
    AccountLimitsBuilder & setNoteSizeMax(std::optional<qint64> noteSizeMax);
    AccountLimitsBuilder & setResourceSizeMax(std::optional<qint64> resourceSizeMax);
    AccountLimitsBuilder & setUserLinkedNotebookMax(std::optional<qint32> userLinkedNotebookMax);
    AccountLimitsBuilder & setUploadLimit(std::optional<qint64> uploadLimit);
    AccountLimitsBuilder & setUserNoteCountMax(std::optional<qint32> userNoteCountMax);
    AccountLimitsBuilder & setUserNotebookCountMax(std::optional<qint32> userNotebookCountMax);
    AccountLimitsBuilder & setUserTagCountMax(std::optional<qint32> userTagCountMax);
    AccountLimitsBuilder & setNoteTagCountMax(std::optional<qint32> noteTagCountMax);
    AccountLimitsBuilder & setUserSavedSearchesMax(std::optional<qint32> userSavedSearchesMax);
    AccountLimitsBuilder & setNoteResourceCountMax(std::optional<qint32> noteResourceCountMax);

    [[nodiscard]] AccountLimits build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_ACCOUNTLIMITSBUILDER
