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

#ifndef QEVERCLOUD_GENERATED_RELATEDQUERYDATA_H
#define QEVERCLOUD_GENERATED_RELATEDQUERYDATA_H

#include <generated/types/RelatedQuery.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedQuery::RelatedQueryData final:
    public QSharedData,
    public Printable
{
public:
    RelatedQueryData() = default;
    RelatedQueryData(const RelatedQueryData & other) = default;
    RelatedQueryData(RelatedQueryData && other) noexcept = default;

    RelatedQueryData & operator=(const RelatedQueryData & other) = delete;
    RelatedQueryData & operator=(RelatedQueryData && other) = delete;

    ~RelatedQueryData() noexcept override = default;

    [[nodiscard]] bool operator==(const RelatedQueryData & other) const noexcept;
    [[nodiscard]] bool operator!=(const RelatedQueryData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_noteGuid;
    std::optional<QString> m_plainText;
    std::optional<NoteFilter> m_filter;
    std::optional<QString> m_referenceUri;
    std::optional<QString> m_context;
    std::optional<QString> m_cacheKey;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDQUERYDATA_H
