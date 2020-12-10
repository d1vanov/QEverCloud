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

#ifndef QEVERCLOUD_GENERATED_NOTEDATA_H
#define QEVERCLOUD_GENERATED_NOTEDATA_H

#include <generated/types/Note.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Note::NoteData final:
    public QSharedData,
    public Printable
{
public:
    NoteData() = default;
    NoteData(const NoteData & other) = default;
    NoteData(NoteData && other) noexcept = default;

    NoteData & operator=(const NoteData & other) = delete;
    NoteData & operator=(NoteData && other) = delete;

    ~NoteData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteData & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_localId;
    QString m_parentLocalId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;

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

#endif // QEVERCLOUD_GENERATED_NOTEDATA_H
