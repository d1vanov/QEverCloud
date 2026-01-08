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

#ifndef QEVERCLOUD_GENERATED_TAGBUILDER
#define QEVERCLOUD_GENERATED_TAGBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Tag.h>
#include <qevercloud/types/TypeAliases.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT TagBuilder
{
public:
    TagBuilder();

    TagBuilder(TagBuilder && other) noexcept;

    ~TagBuilder() noexcept;

    TagBuilder & operator=(TagBuilder && other) noexcept;

    TagBuilder & setLocalId(QString localId);
    TagBuilder & setLocallyModified(bool isLocallyModified);
    TagBuilder & setLocalOnly(bool isLocalOnly);
    TagBuilder & setLocallyFavorited(bool isLocallyFavorited);
    TagBuilder & setLocalData(QHash<QString, QVariant> localData);
    TagBuilder & setLinkedNotebookGuid(std::optional<Guid> linkedNotebookGuid);
    TagBuilder & setParentTagLocalId(QString parentTagLocalId);
    TagBuilder & setGuid(std::optional<Guid> guid);
    TagBuilder & setName(std::optional<QString> name);
    TagBuilder & setParentGuid(std::optional<Guid> parentGuid);
    TagBuilder & setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);

    [[nodiscard]] Tag build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TAGBUILDER
