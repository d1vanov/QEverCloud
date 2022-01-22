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

#ifndef QEVERCLOUD_GENERATED_LINKEDNOTEBOOKBUILDER
#define QEVERCLOUD_GENERATED_LINKEDNOTEBOOKBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/LinkedNotebook.h>
#include <qevercloud/types/TypeAliases.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT LinkedNotebookBuilder
{
public:
    LinkedNotebookBuilder();

    LinkedNotebookBuilder(LinkedNotebookBuilder && other) noexcept;

    ~LinkedNotebookBuilder() noexcept;

    LinkedNotebookBuilder & operator=(LinkedNotebookBuilder && other) noexcept;

    LinkedNotebookBuilder & setLocallyModified(bool isLocallyModified);
    LinkedNotebookBuilder & setLocalOnly(bool isLocalOnly);
    LinkedNotebookBuilder & setLocallyFavorited(bool isLocallyFavorited);
    LinkedNotebookBuilder & setLocalData(QHash<QString, QVariant> localData);
    LinkedNotebookBuilder & setShareName(std::optional<QString> shareName);
    LinkedNotebookBuilder & setUsername(std::optional<QString> username);
    LinkedNotebookBuilder & setShardId(std::optional<QString> shardId);
    LinkedNotebookBuilder & setSharedNotebookGlobalId(std::optional<QString> sharedNotebookGlobalId);
    LinkedNotebookBuilder & setUri(std::optional<QString> uri);
    LinkedNotebookBuilder & setGuid(std::optional<Guid> guid);
    LinkedNotebookBuilder & setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);
    LinkedNotebookBuilder & setNoteStoreUrl(std::optional<QString> noteStoreUrl);
    LinkedNotebookBuilder & setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix);
    LinkedNotebookBuilder & setStack(std::optional<QString> stack);
    LinkedNotebookBuilder & setBusinessId(std::optional<qint32> businessId);

    [[nodiscard]] LinkedNotebook build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_LINKEDNOTEBOOKBUILDER
