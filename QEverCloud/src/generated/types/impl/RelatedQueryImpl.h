/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_RELATEDQUERYIMPL_H
#define QEVERCLOUD_GENERATED_RELATEDQUERYIMPL_H

#include <generated/types/RelatedQuery.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedQuery::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const RelatedQuery::Impl & other) = default;
    Impl(RelatedQuery::Impl && other) noexcept = default;

    RelatedQuery::Impl & operator=(const RelatedQuery::Impl & other) = delete;
    RelatedQuery::Impl & operator=(RelatedQuery::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const RelatedQuery::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const RelatedQuery::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_noteGuid;
    std::optional<QString> m_plainText;
    std::optional<NoteFilter> m_filter;
    std::optional<QString> m_referenceUri;
    std::optional<QString> m_context;
    std::optional<QString> m_cacheKey;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDQUERYIMPL_H
