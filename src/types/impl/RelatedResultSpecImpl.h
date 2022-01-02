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

#ifndef QEVERCLOUD_GENERATED_RELATEDRESULTSPECIMPL
#define QEVERCLOUD_GENERATED_RELATEDRESULTSPECIMPL

#include <qevercloud/types/RelatedResultSpec.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedResultSpec::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const RelatedResultSpec::Impl & other) = default;
    Impl(RelatedResultSpec::Impl && other) noexcept = default;

    RelatedResultSpec::Impl & operator=(const RelatedResultSpec::Impl & other) = delete;
    RelatedResultSpec::Impl & operator=(RelatedResultSpec::Impl && other) = delete;

    ~Impl() noexcept override = default;

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

#endif // QEVERCLOUD_GENERATED_RELATEDRESULTSPECIMPL
