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

#ifndef QEVERCLOUD_GENERATED_NOTEMETADATAIMPL_H
#define QEVERCLOUD_GENERATED_NOTEMETADATAIMPL_H

#include <qevercloud/types/NoteMetadata.h>
#include <QHash>
#include <QSharedData>
#include <QVariant>

namespace qevercloud {

class Q_DECL_HIDDEN NoteMetadata::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl();
    Impl(const NoteMetadata::Impl & other) = default;
    Impl(NoteMetadata::Impl && other) noexcept = default;

    NoteMetadata::Impl & operator=(const NoteMetadata::Impl & other) = delete;
    NoteMetadata::Impl & operator=(NoteMetadata::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    QString m_localId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;
    QHash<QString, QVariant> m_localData;

    Guid m_guid;
    std::optional<QString> m_title;
    std::optional<qint32> m_contentLength;
    std::optional<Timestamp> m_created;
    std::optional<Timestamp> m_updated;
    std::optional<Timestamp> m_deleted;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<QString> m_notebookGuid;
    std::optional<QList<Guid>> m_tagGuids;
    std::optional<NoteAttributes> m_attributes;
    std::optional<QString> m_largestResourceMime;
    std::optional<qint32> m_largestResourceSize;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEMETADATAIMPL_H
