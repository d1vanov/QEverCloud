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

#ifndef QEVERCLOUD_GENERATED_LINKEDNOTEBOOKIMPL_H
#define QEVERCLOUD_GENERATED_LINKEDNOTEBOOKIMPL_H

#include <qevercloud/generated/types/LinkedNotebook.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN LinkedNotebook::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const LinkedNotebook::Impl & other) = default;
    Impl(LinkedNotebook::Impl && other) noexcept = default;

    LinkedNotebook::Impl & operator=(const LinkedNotebook::Impl & other) = delete;
    LinkedNotebook::Impl & operator=(LinkedNotebook::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const LinkedNotebook::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const LinkedNotebook::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_localId;
    QString m_parentLocalId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;

    std::optional<QString> m_shareName;
    std::optional<QString> m_username;
    std::optional<QString> m_shardId;
    std::optional<QString> m_sharedNotebookGlobalId;
    std::optional<QString> m_uri;
    std::optional<Guid> m_guid;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
    std::optional<QString> m_stack;
    std::optional<qint32> m_businessId;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_LINKEDNOTEBOOKIMPL_H