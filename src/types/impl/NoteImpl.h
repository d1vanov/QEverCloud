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

#ifndef QEVERCLOUD_GENERATED_NOTEIMPL
#define QEVERCLOUD_GENERATED_NOTEIMPL

#include <qevercloud/types/Note.h>
#include <QHash>
#include <QSharedData>
#include <QVariant>

namespace qevercloud {

class Q_DECL_HIDDEN Note::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl();
    Impl(const Note::Impl & other) = default;
    Impl(Note::Impl && other) noexcept = default;

    Note::Impl & operator=(const Note::Impl & other) = delete;
    Note::Impl & operator=(Note::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    QString m_localId;
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    QString m_notebookLocalId;
    QStringList m_tagLocalIds;
    QByteArray m_thumbnailData;
    std::optional<Guid> m_guid;
    std::optional<QString> m_title;
    std::optional<QString> m_content;
    std::optional<QByteArray> m_contentHash;
    std::optional<qint32> m_contentLength;
    std::optional<Timestamp> m_created;
    std::optional<Timestamp> m_updated;
    std::optional<Timestamp> m_deleted;
    std::optional<bool> m_active;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<QString> m_notebookGuid;
    std::optional<QList<Guid>> m_tagGuids;
    std::optional<QList<Resource>> m_resources;
    std::optional<NoteAttributes> m_attributes;
    std::optional<QStringList> m_tagNames;
    std::optional<QList<SharedNote>> m_sharedNotes;
    std::optional<NoteRestrictions> m_restrictions;
    std::optional<NoteLimits> m_limits;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEIMPL
