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

#ifndef QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTBUILDER
#define QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/CreateOrUpdateNotebookSharesResult.h>
#include <qevercloud/types/SharedNotebook.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT CreateOrUpdateNotebookSharesResultBuilder
{
public:
    CreateOrUpdateNotebookSharesResultBuilder();

    CreateOrUpdateNotebookSharesResultBuilder(CreateOrUpdateNotebookSharesResultBuilder && other) noexcept;

    ~CreateOrUpdateNotebookSharesResultBuilder() noexcept;

    CreateOrUpdateNotebookSharesResultBuilder & operator=(CreateOrUpdateNotebookSharesResultBuilder && other) noexcept;

    CreateOrUpdateNotebookSharesResultBuilder & setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);
    CreateOrUpdateNotebookSharesResultBuilder & setMatchingShares(std::optional<QList<SharedNotebook>> matchingShares);

    [[nodiscard]] CreateOrUpdateNotebookSharesResult build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULTBUILDER
