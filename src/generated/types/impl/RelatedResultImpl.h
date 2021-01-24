/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_RELATEDRESULTIMPL_H
#define QEVERCLOUD_GENERATED_RELATEDRESULTIMPL_H

#include <qevercloud/generated/types/RelatedResult.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedResult::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const RelatedResult::Impl & other) = default;
    Impl(RelatedResult::Impl && other) noexcept = default;

    RelatedResult::Impl & operator=(const RelatedResult::Impl & other) = delete;
    RelatedResult::Impl & operator=(RelatedResult::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const RelatedResult::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const RelatedResult::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

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

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDRESULTIMPL_H
