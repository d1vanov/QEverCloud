/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_NOTEATTRIBUTESIMPL
#define QEVERCLOUD_GENERATED_NOTEATTRIBUTESIMPL

#include <qevercloud/types/NoteAttributes.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteAttributes::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteAttributes::Impl & other) = default;
    Impl(NoteAttributes::Impl && other) noexcept = default;

    NoteAttributes::Impl & operator=(const NoteAttributes::Impl & other) = delete;
    NoteAttributes::Impl & operator=(NoteAttributes::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<Timestamp> m_subjectDate;
    std::optional<double> m_latitude;
    std::optional<double> m_longitude;
    std::optional<double> m_altitude;
    std::optional<QString> m_author;
    std::optional<QString> m_source;
    std::optional<QString> m_sourceURL;
    std::optional<QString> m_sourceApplication;
    std::optional<Timestamp> m_shareDate;
    std::optional<qint64> m_reminderOrder;
    std::optional<Timestamp> m_reminderDoneTime;
    std::optional<Timestamp> m_reminderTime;
    std::optional<QString> m_placeName;
    std::optional<QString> m_contentClass;
    std::optional<LazyMap> m_applicationData;
    std::optional<QString> m_lastEditedBy;
    std::optional<QMap<QString, QString>> m_classifications;
    std::optional<UserID> m_creatorId;
    std::optional<UserID> m_lastEditorId;
    std::optional<bool> m_sharedWithBusiness;
    std::optional<Guid> m_conflictSourceNoteGuid;
    std::optional<qint32> m_noteTitleQuality;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEATTRIBUTESIMPL
