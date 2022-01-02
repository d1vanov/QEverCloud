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

#include <qevercloud/types/builders/RelatedResultSpecBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedResultSpecBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<qint32> m_maxNotes;
    std::optional<qint32> m_maxNotebooks;
    std::optional<qint32> m_maxTags;
    std::optional<bool> m_writableNotebooksOnly;
    std::optional<bool> m_includeContainingNotebooks;
    std::optional<bool> m_includeDebugInfo;
    std::optional<qint32> m_maxExperts;
    std::optional<qint32> m_maxRelatedContent;
    std::optional<QSet<RelatedContentType>> m_relatedContentTypes;
};

RelatedResultSpecBuilder::RelatedResultSpecBuilder() :
    d(new RelatedResultSpecBuilder::Impl)
{}

RelatedResultSpecBuilder::RelatedResultSpecBuilder(RelatedResultSpecBuilder && other) noexcept :
    d{std::move(other.d)}
{}

RelatedResultSpecBuilder::~RelatedResultSpecBuilder() noexcept = default;

RelatedResultSpecBuilder & RelatedResultSpecBuilder::operator=(RelatedResultSpecBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setMaxNotes(std::optional<qint32> maxNotes)
{
    d->m_maxNotes = std::move(maxNotes);
    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setMaxNotebooks(std::optional<qint32> maxNotebooks)
{
    d->m_maxNotebooks = std::move(maxNotebooks);
    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setMaxTags(std::optional<qint32> maxTags)
{
    d->m_maxTags = std::move(maxTags);
    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setWritableNotebooksOnly(std::optional<bool> writableNotebooksOnly)
{
    d->m_writableNotebooksOnly = std::move(writableNotebooksOnly);
    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setIncludeContainingNotebooks(std::optional<bool> includeContainingNotebooks)
{
    d->m_includeContainingNotebooks = std::move(includeContainingNotebooks);
    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setIncludeDebugInfo(std::optional<bool> includeDebugInfo)
{
    d->m_includeDebugInfo = std::move(includeDebugInfo);
    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setMaxExperts(std::optional<qint32> maxExperts)
{
    d->m_maxExperts = std::move(maxExperts);
    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setMaxRelatedContent(std::optional<qint32> maxRelatedContent)
{
    d->m_maxRelatedContent = std::move(maxRelatedContent);
    return *this;
}

RelatedResultSpecBuilder & RelatedResultSpecBuilder::setRelatedContentTypes(std::optional<QSet<RelatedContentType>> relatedContentTypes)
{
    d->m_relatedContentTypes = std::move(relatedContentTypes);
    return *this;
}

RelatedResultSpec RelatedResultSpecBuilder::build()
{
    RelatedResultSpec result;

    result.setMaxNotes(std::move(d->m_maxNotes));
    result.setMaxNotebooks(std::move(d->m_maxNotebooks));
    result.setMaxTags(std::move(d->m_maxTags));
    result.setWritableNotebooksOnly(std::move(d->m_writableNotebooksOnly));
    result.setIncludeContainingNotebooks(std::move(d->m_includeContainingNotebooks));
    result.setIncludeDebugInfo(std::move(d->m_includeDebugInfo));
    result.setMaxExperts(std::move(d->m_maxExperts));
    result.setMaxRelatedContent(std::move(d->m_maxRelatedContent));
    result.setRelatedContentTypes(std::move(d->m_relatedContentTypes));

    d->m_maxNotes = {};
    d->m_maxNotebooks = {};
    d->m_maxTags = {};
    d->m_writableNotebooksOnly = {};
    d->m_includeContainingNotebooks = {};
    d->m_includeDebugInfo = {};
    d->m_maxExperts = {};
    d->m_maxRelatedContent = {};
    d->m_relatedContentTypes = {};

    return result;
}

} // namespace qevercloud
