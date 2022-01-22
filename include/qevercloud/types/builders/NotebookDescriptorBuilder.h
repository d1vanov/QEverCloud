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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTORBUILDER
#define QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTORBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NotebookDescriptor.h>
#include <qevercloud/types/TypeAliases.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NotebookDescriptorBuilder
{
public:
    NotebookDescriptorBuilder();

    NotebookDescriptorBuilder(NotebookDescriptorBuilder && other) noexcept;

    ~NotebookDescriptorBuilder() noexcept;

    NotebookDescriptorBuilder & operator=(NotebookDescriptorBuilder && other) noexcept;

    NotebookDescriptorBuilder & setLocalId(QString localId);
    NotebookDescriptorBuilder & setLocallyModified(bool isLocallyModified);
    NotebookDescriptorBuilder & setLocalOnly(bool isLocalOnly);
    NotebookDescriptorBuilder & setLocallyFavorited(bool isLocallyFavorited);
    NotebookDescriptorBuilder & setLocalData(QHash<QString, QVariant> localData);
    NotebookDescriptorBuilder & setGuid(std::optional<Guid> guid);
    NotebookDescriptorBuilder & setNotebookDisplayName(std::optional<QString> notebookDisplayName);
    NotebookDescriptorBuilder & setContactName(std::optional<QString> contactName);
    NotebookDescriptorBuilder & setHasSharedNotebook(std::optional<bool> hasSharedNotebook);
    NotebookDescriptorBuilder & setJoinedUserCount(std::optional<qint32> joinedUserCount);

    [[nodiscard]] NotebookDescriptor build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTORBUILDER
