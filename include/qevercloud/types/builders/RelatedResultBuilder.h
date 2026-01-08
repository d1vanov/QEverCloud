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

#ifndef QEVERCLOUD_GENERATED_RELATEDRESULTBUILDER
#define QEVERCLOUD_GENERATED_RELATEDRESULTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Note.h>
#include <qevercloud/types/Notebook.h>
#include <qevercloud/types/NotebookDescriptor.h>
#include <qevercloud/types/RelatedContent.h>
#include <qevercloud/types/RelatedResult.h>
#include <qevercloud/types/Tag.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UserProfile.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT RelatedResultBuilder
{
public:
    RelatedResultBuilder();

    RelatedResultBuilder(RelatedResultBuilder && other) noexcept;

    ~RelatedResultBuilder() noexcept;

    RelatedResultBuilder & operator=(RelatedResultBuilder && other) noexcept;

    RelatedResultBuilder & setNotes(std::optional<QList<Note>> notes);
    RelatedResultBuilder & setNotebooks(std::optional<QList<Notebook>> notebooks);
    RelatedResultBuilder & setTags(std::optional<QList<Tag>> tags);
    RelatedResultBuilder & setContainingNotebooks(std::optional<QList<NotebookDescriptor>> containingNotebooks);
    RelatedResultBuilder & setDebugInfo(std::optional<QString> debugInfo);
    RelatedResultBuilder & setExperts(std::optional<QList<UserProfile>> experts);
    RelatedResultBuilder & setRelatedContent(std::optional<QList<RelatedContent>> relatedContent);
    RelatedResultBuilder & setCacheKey(std::optional<QString> cacheKey);
    RelatedResultBuilder & setCacheExpires(std::optional<qint32> cacheExpires);

    [[nodiscard]] RelatedResult build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDRESULTBUILDER
