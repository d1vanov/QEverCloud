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

#include <qevercloud/types/builders/RelatedResultBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedResultBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QList<Note>> m_notes;
    std::optional<QList<Notebook>> m_notebooks;
    std::optional<QList<Tag>> m_tags;
    std::optional<QList<NotebookDescriptor>> m_containingNotebooks;
    std::optional<QString> m_debugInfo;
    std::optional<QList<UserProfile>> m_experts;
    std::optional<QList<RelatedContent>> m_relatedContent;
    std::optional<QString> m_cacheKey;
    std::optional<qint32> m_cacheExpires;
};

RelatedResultBuilder::RelatedResultBuilder() :
    d(new RelatedResultBuilder::Impl)
{}

RelatedResultBuilder::RelatedResultBuilder(RelatedResultBuilder && other) noexcept :
    d{std::move(other.d)}
{}

RelatedResultBuilder::~RelatedResultBuilder() noexcept = default;

RelatedResultBuilder & RelatedResultBuilder::operator=(RelatedResultBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setNotes(std::optional<QList<Note>> notes)
{
    d->m_notes = std::move(notes);
    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setNotebooks(std::optional<QList<Notebook>> notebooks)
{
    d->m_notebooks = std::move(notebooks);
    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setTags(std::optional<QList<Tag>> tags)
{
    d->m_tags = std::move(tags);
    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setContainingNotebooks(std::optional<QList<NotebookDescriptor>> containingNotebooks)
{
    d->m_containingNotebooks = std::move(containingNotebooks);
    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setDebugInfo(std::optional<QString> debugInfo)
{
    d->m_debugInfo = std::move(debugInfo);
    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setExperts(std::optional<QList<UserProfile>> experts)
{
    d->m_experts = std::move(experts);
    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setRelatedContent(std::optional<QList<RelatedContent>> relatedContent)
{
    d->m_relatedContent = std::move(relatedContent);
    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setCacheKey(std::optional<QString> cacheKey)
{
    d->m_cacheKey = std::move(cacheKey);
    return *this;
}

RelatedResultBuilder & RelatedResultBuilder::setCacheExpires(std::optional<qint32> cacheExpires)
{
    d->m_cacheExpires = std::move(cacheExpires);
    return *this;
}

RelatedResult RelatedResultBuilder::build()
{
    RelatedResult result;

    result.setNotes(std::move(d->m_notes));
    result.setNotebooks(std::move(d->m_notebooks));
    result.setTags(std::move(d->m_tags));
    result.setContainingNotebooks(std::move(d->m_containingNotebooks));
    result.setDebugInfo(std::move(d->m_debugInfo));
    result.setExperts(std::move(d->m_experts));
    result.setRelatedContent(std::move(d->m_relatedContent));
    result.setCacheKey(std::move(d->m_cacheKey));
    result.setCacheExpires(std::move(d->m_cacheExpires));

    d->m_notes = {};
    d->m_notebooks = {};
    d->m_tags = {};
    d->m_containingNotebooks = {};
    d->m_debugInfo = {};
    d->m_experts = {};
    d->m_relatedContent = {};
    d->m_cacheKey = {};
    d->m_cacheExpires = {};

    return result;
}

} // namespace qevercloud
