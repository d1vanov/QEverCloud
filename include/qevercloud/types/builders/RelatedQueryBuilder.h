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

#ifndef QEVERCLOUD_GENERATED_RELATEDQUERYBUILDER
#define QEVERCLOUD_GENERATED_RELATEDQUERYBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteFilter.h>
#include <qevercloud/types/RelatedQuery.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT RelatedQueryBuilder
{
public:
    RelatedQueryBuilder();

    RelatedQueryBuilder(RelatedQueryBuilder && other) noexcept;

    ~RelatedQueryBuilder() noexcept;

    RelatedQueryBuilder & operator=(RelatedQueryBuilder && other) noexcept;

    RelatedQueryBuilder & setNoteGuid(std::optional<QString> noteGuid);
    RelatedQueryBuilder & setPlainText(std::optional<QString> plainText);
    RelatedQueryBuilder & setFilter(std::optional<NoteFilter> filter);
    RelatedQueryBuilder & setReferenceUri(std::optional<QString> referenceUri);
    RelatedQueryBuilder & setContext(std::optional<QString> context);
    RelatedQueryBuilder & setCacheKey(std::optional<QString> cacheKey);

    [[nodiscard]] RelatedQuery build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDQUERYBUILDER
