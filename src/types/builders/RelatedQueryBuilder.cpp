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

#include <qevercloud/types/builders/RelatedQueryBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedQueryBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_noteGuid;
    std::optional<QString> m_plainText;
    std::optional<NoteFilter> m_filter;
    std::optional<QString> m_referenceUri;
    std::optional<QString> m_context;
    std::optional<QString> m_cacheKey;
};

RelatedQueryBuilder::RelatedQueryBuilder() :
    d(new RelatedQueryBuilder::Impl)
{}

RelatedQueryBuilder::RelatedQueryBuilder(RelatedQueryBuilder && other) noexcept :
    d{std::move(other.d)}
{}

RelatedQueryBuilder::~RelatedQueryBuilder() noexcept = default;

RelatedQueryBuilder & RelatedQueryBuilder::operator=(RelatedQueryBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

RelatedQueryBuilder & RelatedQueryBuilder::setNoteGuid(std::optional<QString> noteGuid)
{
    d->m_noteGuid = std::move(noteGuid);
    return *this;
}

RelatedQueryBuilder & RelatedQueryBuilder::setPlainText(std::optional<QString> plainText)
{
    d->m_plainText = std::move(plainText);
    return *this;
}

RelatedQueryBuilder & RelatedQueryBuilder::setFilter(std::optional<NoteFilter> filter)
{
    d->m_filter = std::move(filter);
    return *this;
}

RelatedQueryBuilder & RelatedQueryBuilder::setReferenceUri(std::optional<QString> referenceUri)
{
    d->m_referenceUri = std::move(referenceUri);
    return *this;
}

RelatedQueryBuilder & RelatedQueryBuilder::setContext(std::optional<QString> context)
{
    d->m_context = std::move(context);
    return *this;
}

RelatedQueryBuilder & RelatedQueryBuilder::setCacheKey(std::optional<QString> cacheKey)
{
    d->m_cacheKey = std::move(cacheKey);
    return *this;
}

RelatedQuery RelatedQueryBuilder::build()
{
    RelatedQuery result;

    result.setNoteGuid(std::move(d->m_noteGuid));
    result.setPlainText(std::move(d->m_plainText));
    result.setFilter(std::move(d->m_filter));
    result.setReferenceUri(std::move(d->m_referenceUri));
    result.setContext(std::move(d->m_context));
    result.setCacheKey(std::move(d->m_cacheKey));

    d->m_noteGuid = {};
    d->m_plainText = {};
    d->m_filter = {};
    d->m_referenceUri = {};
    d->m_context = {};
    d->m_cacheKey = {};

    return result;
}

} // namespace qevercloud
