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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTORIMPL_H
#define QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTORIMPL_H

#include <qevercloud/generated/types/NotebookDescriptor.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookDescriptor::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NotebookDescriptor::Impl & other) = default;
    Impl(NotebookDescriptor::Impl && other) noexcept = default;

    NotebookDescriptor::Impl & operator=(const NotebookDescriptor::Impl & other) = delete;
    NotebookDescriptor::Impl & operator=(NotebookDescriptor::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const NotebookDescriptor::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const NotebookDescriptor::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_localId;
    QString m_parentLocalId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;

    std::optional<Guid> m_guid;
    std::optional<QString> m_notebookDisplayName;
    std::optional<QString> m_contactName;
    std::optional<bool> m_hasSharedNotebook;
    std::optional<qint32> m_joinedUserCount;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTORIMPL_H
