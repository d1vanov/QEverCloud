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

#ifndef QEVERCLOUD_GENERATED_NOTEATTRIBUTESBUILDER
#define QEVERCLOUD_GENERATED_NOTEATTRIBUTESBUILDER

#include <qevercloud/Export.h>

#include "QMap"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/LazyMap.h>
#include <qevercloud/types/NoteAttributes.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteAttributesBuilder
{
public:
    NoteAttributesBuilder();

    NoteAttributesBuilder(NoteAttributesBuilder && other) noexcept;

    ~NoteAttributesBuilder() noexcept;

    NoteAttributesBuilder & operator=(NoteAttributesBuilder && other) noexcept;

    NoteAttributesBuilder & setSubjectDate(std::optional<Timestamp> subjectDate);
    NoteAttributesBuilder & setLatitude(std::optional<double> latitude);
    NoteAttributesBuilder & setLongitude(std::optional<double> longitude);
    NoteAttributesBuilder & setAltitude(std::optional<double> altitude);
    NoteAttributesBuilder & setAuthor(std::optional<QString> author);
    NoteAttributesBuilder & setSource(std::optional<QString> source);
    NoteAttributesBuilder & setSourceURL(std::optional<QString> sourceURL);
    NoteAttributesBuilder & setSourceApplication(std::optional<QString> sourceApplication);
    NoteAttributesBuilder & setShareDate(std::optional<Timestamp> shareDate);
    NoteAttributesBuilder & setReminderOrder(std::optional<qint64> reminderOrder);
    NoteAttributesBuilder & setReminderDoneTime(std::optional<Timestamp> reminderDoneTime);
    NoteAttributesBuilder & setReminderTime(std::optional<Timestamp> reminderTime);
    NoteAttributesBuilder & setPlaceName(std::optional<QString> placeName);
    NoteAttributesBuilder & setContentClass(std::optional<QString> contentClass);
    NoteAttributesBuilder & setApplicationData(std::optional<LazyMap> applicationData);
    NoteAttributesBuilder & setLastEditedBy(std::optional<QString> lastEditedBy);
    NoteAttributesBuilder & setClassifications(std::optional<QMap<QString, QString>> classifications);
    NoteAttributesBuilder & setCreatorId(std::optional<UserID> creatorId);
    NoteAttributesBuilder & setLastEditorId(std::optional<UserID> lastEditorId);
    NoteAttributesBuilder & setSharedWithBusiness(std::optional<bool> sharedWithBusiness);
    NoteAttributesBuilder & setConflictSourceNoteGuid(std::optional<Guid> conflictSourceNoteGuid);
    NoteAttributesBuilder & setNoteTitleQuality(std::optional<qint32> noteTitleQuality);

    [[nodiscard]] NoteAttributes build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEATTRIBUTESBUILDER
