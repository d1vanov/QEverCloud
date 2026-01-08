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

#ifndef QEVERCLOUD_GENERATED_RELATEDRESULTSPECBUILDER
#define QEVERCLOUD_GENERATED_RELATEDRESULTSPECBUILDER

#include <qevercloud/Export.h>

#include "QSet"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/RelatedResultSpec.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT RelatedResultSpecBuilder
{
public:
    RelatedResultSpecBuilder();

    RelatedResultSpecBuilder(RelatedResultSpecBuilder && other) noexcept;

    ~RelatedResultSpecBuilder() noexcept;

    RelatedResultSpecBuilder & operator=(RelatedResultSpecBuilder && other) noexcept;

    RelatedResultSpecBuilder & setMaxNotes(std::optional<qint32> maxNotes);
    RelatedResultSpecBuilder & setMaxNotebooks(std::optional<qint32> maxNotebooks);
    RelatedResultSpecBuilder & setMaxTags(std::optional<qint32> maxTags);
    RelatedResultSpecBuilder & setWritableNotebooksOnly(std::optional<bool> writableNotebooksOnly);
    RelatedResultSpecBuilder & setIncludeContainingNotebooks(std::optional<bool> includeContainingNotebooks);
    RelatedResultSpecBuilder & setIncludeDebugInfo(std::optional<bool> includeDebugInfo);
    RelatedResultSpecBuilder & setMaxExperts(std::optional<qint32> maxExperts);
    RelatedResultSpecBuilder & setMaxRelatedContent(std::optional<qint32> maxRelatedContent);
    RelatedResultSpecBuilder & setRelatedContentTypes(std::optional<QSet<RelatedContentType>> relatedContentTypes);

    [[nodiscard]] RelatedResultSpec build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDRESULTSPECBUILDER
