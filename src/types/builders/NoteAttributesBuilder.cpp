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

#include <qevercloud/types/builders/NoteAttributesBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteAttributesBuilder::Impl final:
    public QSharedData
{
public:
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

NoteAttributesBuilder::NoteAttributesBuilder() :
    d(new NoteAttributesBuilder::Impl)
{}

NoteAttributesBuilder::NoteAttributesBuilder(NoteAttributesBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteAttributesBuilder::~NoteAttributesBuilder() noexcept = default;

NoteAttributesBuilder & NoteAttributesBuilder::operator=(NoteAttributesBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setSubjectDate(std::optional<Timestamp> subjectDate)
{
    d->m_subjectDate = std::move(subjectDate);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setLatitude(std::optional<double> latitude)
{
    d->m_latitude = std::move(latitude);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setLongitude(std::optional<double> longitude)
{
    d->m_longitude = std::move(longitude);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setAltitude(std::optional<double> altitude)
{
    d->m_altitude = std::move(altitude);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setAuthor(std::optional<QString> author)
{
    d->m_author = std::move(author);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setSource(std::optional<QString> source)
{
    d->m_source = std::move(source);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setSourceURL(std::optional<QString> sourceURL)
{
    d->m_sourceURL = std::move(sourceURL);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setSourceApplication(std::optional<QString> sourceApplication)
{
    d->m_sourceApplication = std::move(sourceApplication);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setShareDate(std::optional<Timestamp> shareDate)
{
    d->m_shareDate = std::move(shareDate);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setReminderOrder(std::optional<qint64> reminderOrder)
{
    d->m_reminderOrder = std::move(reminderOrder);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setReminderDoneTime(std::optional<Timestamp> reminderDoneTime)
{
    d->m_reminderDoneTime = std::move(reminderDoneTime);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setReminderTime(std::optional<Timestamp> reminderTime)
{
    d->m_reminderTime = std::move(reminderTime);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setPlaceName(std::optional<QString> placeName)
{
    d->m_placeName = std::move(placeName);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setContentClass(std::optional<QString> contentClass)
{
    d->m_contentClass = std::move(contentClass);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setApplicationData(std::optional<LazyMap> applicationData)
{
    d->m_applicationData = std::move(applicationData);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setLastEditedBy(std::optional<QString> lastEditedBy)
{
    d->m_lastEditedBy = std::move(lastEditedBy);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setClassifications(std::optional<QMap<QString, QString>> classifications)
{
    d->m_classifications = std::move(classifications);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setCreatorId(std::optional<UserID> creatorId)
{
    d->m_creatorId = std::move(creatorId);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setLastEditorId(std::optional<UserID> lastEditorId)
{
    d->m_lastEditorId = std::move(lastEditorId);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setSharedWithBusiness(std::optional<bool> sharedWithBusiness)
{
    d->m_sharedWithBusiness = std::move(sharedWithBusiness);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setConflictSourceNoteGuid(std::optional<Guid> conflictSourceNoteGuid)
{
    d->m_conflictSourceNoteGuid = std::move(conflictSourceNoteGuid);
    return *this;
}

NoteAttributesBuilder & NoteAttributesBuilder::setNoteTitleQuality(std::optional<qint32> noteTitleQuality)
{
    d->m_noteTitleQuality = std::move(noteTitleQuality);
    return *this;
}

NoteAttributes NoteAttributesBuilder::build()
{
    NoteAttributes result;

    result.setSubjectDate(std::move(d->m_subjectDate));
    result.setLatitude(std::move(d->m_latitude));
    result.setLongitude(std::move(d->m_longitude));
    result.setAltitude(std::move(d->m_altitude));
    result.setAuthor(std::move(d->m_author));
    result.setSource(std::move(d->m_source));
    result.setSourceURL(std::move(d->m_sourceURL));
    result.setSourceApplication(std::move(d->m_sourceApplication));
    result.setShareDate(std::move(d->m_shareDate));
    result.setReminderOrder(std::move(d->m_reminderOrder));
    result.setReminderDoneTime(std::move(d->m_reminderDoneTime));
    result.setReminderTime(std::move(d->m_reminderTime));
    result.setPlaceName(std::move(d->m_placeName));
    result.setContentClass(std::move(d->m_contentClass));
    result.setApplicationData(std::move(d->m_applicationData));
    result.setLastEditedBy(std::move(d->m_lastEditedBy));
    result.setClassifications(std::move(d->m_classifications));
    result.setCreatorId(std::move(d->m_creatorId));
    result.setLastEditorId(std::move(d->m_lastEditorId));
    result.setSharedWithBusiness(std::move(d->m_sharedWithBusiness));
    result.setConflictSourceNoteGuid(std::move(d->m_conflictSourceNoteGuid));
    result.setNoteTitleQuality(std::move(d->m_noteTitleQuality));

    d->m_subjectDate = {};
    d->m_latitude = {};
    d->m_longitude = {};
    d->m_altitude = {};
    d->m_author = {};
    d->m_source = {};
    d->m_sourceURL = {};
    d->m_sourceApplication = {};
    d->m_shareDate = {};
    d->m_reminderOrder = {};
    d->m_reminderDoneTime = {};
    d->m_reminderTime = {};
    d->m_placeName = {};
    d->m_contentClass = {};
    d->m_applicationData = {};
    d->m_lastEditedBy = {};
    d->m_classifications = {};
    d->m_creatorId = {};
    d->m_lastEditorId = {};
    d->m_sharedWithBusiness = {};
    d->m_conflictSourceNoteGuid = {};
    d->m_noteTitleQuality = {};

    return result;
}

} // namespace qevercloud
