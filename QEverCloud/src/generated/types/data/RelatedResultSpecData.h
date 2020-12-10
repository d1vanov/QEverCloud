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

#ifndef QEVERCLOUD_GENERATED_RELATEDRESULTSPECDATA_H
#define QEVERCLOUD_GENERATED_RELATEDRESULTSPECDATA_H

#include <generated/types/RelatedResultSpec.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedResultSpec::RelatedResultSpecData final:
    public QSharedData,
    public Printable
{
public:
    RelatedResultSpecData() = default;
    RelatedResultSpecData(const RelatedResultSpecData & other) = default;
    RelatedResultSpecData(RelatedResultSpecData && other) noexcept = default;

    RelatedResultSpecData & operator=(const RelatedResultSpecData & other) = delete;
    RelatedResultSpecData & operator=(RelatedResultSpecData && other) = delete;

    ~RelatedResultSpecData() noexcept override = default;

    [[nodiscard]] bool operator==(const RelatedResultSpecData & other) const noexcept;
    [[nodiscard]] bool operator!=(const RelatedResultSpecData & other) const noexcept;

    void print(QTextStream & strm) const override;

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

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDRESULTSPECDATA_H
