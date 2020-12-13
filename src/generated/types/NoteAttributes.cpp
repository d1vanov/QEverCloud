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

#include <qevercloud/generated/types/NoteAttributes.h>

#include "impl/NoteAttributesImpl.h"

namespace qevercloud {

NoteAttributes::NoteAttributes() :
    d(new NoteAttributes::Impl)
 {}

NoteAttributes::NoteAttributes(const NoteAttributes & other) :
    d(other.d)
{}

NoteAttributes::NoteAttributes(NoteAttributes && other) noexcept :
    d(std::move(other.d))
{}

NoteAttributes::~NoteAttributes() noexcept {}

NoteAttributes & NoteAttributes::operator=(const NoteAttributes & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteAttributes & NoteAttributes::operator=(NoteAttributes && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<Timestamp> & NoteAttributes::subjectDate() const noexcept
{
    return d->m_subjectDate;
}

std::optional<Timestamp> & NoteAttributes::mutableSubjectDate()
{
    return d->m_subjectDate;
}

void NoteAttributes::setSubjectDate(std::optional<Timestamp> subjectDate)
{
    d->m_subjectDate = subjectDate;
}

const std::optional<double> & NoteAttributes::latitude() const noexcept
{
    return d->m_latitude;
}

std::optional<double> & NoteAttributes::mutableLatitude()
{
    return d->m_latitude;
}

void NoteAttributes::setLatitude(std::optional<double> latitude)
{
    d->m_latitude = latitude;
}

const std::optional<double> & NoteAttributes::longitude() const noexcept
{
    return d->m_longitude;
}

std::optional<double> & NoteAttributes::mutableLongitude()
{
    return d->m_longitude;
}

void NoteAttributes::setLongitude(std::optional<double> longitude)
{
    d->m_longitude = longitude;
}

const std::optional<double> & NoteAttributes::altitude() const noexcept
{
    return d->m_altitude;
}

std::optional<double> & NoteAttributes::mutableAltitude()
{
    return d->m_altitude;
}

void NoteAttributes::setAltitude(std::optional<double> altitude)
{
    d->m_altitude = altitude;
}

const std::optional<QString> & NoteAttributes::author() const noexcept
{
    return d->m_author;
}

void NoteAttributes::setAuthor(std::optional<QString> author)
{
    d->m_author = author;
}

const std::optional<QString> & NoteAttributes::source() const noexcept
{
    return d->m_source;
}

void NoteAttributes::setSource(std::optional<QString> source)
{
    d->m_source = source;
}

const std::optional<QString> & NoteAttributes::sourceURL() const noexcept
{
    return d->m_sourceURL;
}

void NoteAttributes::setSourceURL(std::optional<QString> sourceURL)
{
    d->m_sourceURL = sourceURL;
}

const std::optional<QString> & NoteAttributes::sourceApplication() const noexcept
{
    return d->m_sourceApplication;
}

void NoteAttributes::setSourceApplication(std::optional<QString> sourceApplication)
{
    d->m_sourceApplication = sourceApplication;
}

const std::optional<Timestamp> & NoteAttributes::shareDate() const noexcept
{
    return d->m_shareDate;
}

std::optional<Timestamp> & NoteAttributes::mutableShareDate()
{
    return d->m_shareDate;
}

void NoteAttributes::setShareDate(std::optional<Timestamp> shareDate)
{
    d->m_shareDate = shareDate;
}

const std::optional<qint64> & NoteAttributes::reminderOrder() const noexcept
{
    return d->m_reminderOrder;
}

std::optional<qint64> & NoteAttributes::mutableReminderOrder()
{
    return d->m_reminderOrder;
}

void NoteAttributes::setReminderOrder(std::optional<qint64> reminderOrder)
{
    d->m_reminderOrder = reminderOrder;
}

const std::optional<Timestamp> & NoteAttributes::reminderDoneTime() const noexcept
{
    return d->m_reminderDoneTime;
}

std::optional<Timestamp> & NoteAttributes::mutableReminderDoneTime()
{
    return d->m_reminderDoneTime;
}

void NoteAttributes::setReminderDoneTime(std::optional<Timestamp> reminderDoneTime)
{
    d->m_reminderDoneTime = reminderDoneTime;
}

const std::optional<Timestamp> & NoteAttributes::reminderTime() const noexcept
{
    return d->m_reminderTime;
}

std::optional<Timestamp> & NoteAttributes::mutableReminderTime()
{
    return d->m_reminderTime;
}

void NoteAttributes::setReminderTime(std::optional<Timestamp> reminderTime)
{
    d->m_reminderTime = reminderTime;
}

const std::optional<QString> & NoteAttributes::placeName() const noexcept
{
    return d->m_placeName;
}

void NoteAttributes::setPlaceName(std::optional<QString> placeName)
{
    d->m_placeName = placeName;
}

const std::optional<QString> & NoteAttributes::contentClass() const noexcept
{
    return d->m_contentClass;
}

void NoteAttributes::setContentClass(std::optional<QString> contentClass)
{
    d->m_contentClass = contentClass;
}

const std::optional<LazyMap> & NoteAttributes::applicationData() const noexcept
{
    return d->m_applicationData;
}

std::optional<LazyMap> & NoteAttributes::mutableApplicationData()
{
    return d->m_applicationData;
}

void NoteAttributes::setApplicationData(std::optional<LazyMap> applicationData)
{
    d->m_applicationData = applicationData;
}

const std::optional<QString> & NoteAttributes::lastEditedBy() const noexcept
{
    return d->m_lastEditedBy;
}

void NoteAttributes::setLastEditedBy(std::optional<QString> lastEditedBy)
{
    d->m_lastEditedBy = lastEditedBy;
}

const std::optional<QMap<QString, QString>> & NoteAttributes::classifications() const noexcept
{
    return d->m_classifications;
}

std::optional<QMap<QString, QString>> & NoteAttributes::mutableClassifications()
{
    return d->m_classifications;
}

void NoteAttributes::setClassifications(std::optional<QMap<QString, QString>> classifications)
{
    d->m_classifications = classifications;
}

const std::optional<UserID> & NoteAttributes::creatorId() const noexcept
{
    return d->m_creatorId;
}

std::optional<UserID> & NoteAttributes::mutableCreatorId()
{
    return d->m_creatorId;
}

void NoteAttributes::setCreatorId(std::optional<UserID> creatorId)
{
    d->m_creatorId = creatorId;
}

const std::optional<UserID> & NoteAttributes::lastEditorId() const noexcept
{
    return d->m_lastEditorId;
}

std::optional<UserID> & NoteAttributes::mutableLastEditorId()
{
    return d->m_lastEditorId;
}

void NoteAttributes::setLastEditorId(std::optional<UserID> lastEditorId)
{
    d->m_lastEditorId = lastEditorId;
}

const std::optional<bool> & NoteAttributes::sharedWithBusiness() const noexcept
{
    return d->m_sharedWithBusiness;
}

std::optional<bool> & NoteAttributes::mutableSharedWithBusiness()
{
    return d->m_sharedWithBusiness;
}

void NoteAttributes::setSharedWithBusiness(std::optional<bool> sharedWithBusiness)
{
    d->m_sharedWithBusiness = sharedWithBusiness;
}

const std::optional<Guid> & NoteAttributes::conflictSourceNoteGuid() const noexcept
{
    return d->m_conflictSourceNoteGuid;
}

std::optional<Guid> & NoteAttributes::mutableConflictSourceNoteGuid()
{
    return d->m_conflictSourceNoteGuid;
}

void NoteAttributes::setConflictSourceNoteGuid(std::optional<Guid> conflictSourceNoteGuid)
{
    d->m_conflictSourceNoteGuid = conflictSourceNoteGuid;
}

const std::optional<qint32> & NoteAttributes::noteTitleQuality() const noexcept
{
    return d->m_noteTitleQuality;
}

std::optional<qint32> & NoteAttributes::mutableNoteTitleQuality()
{
    return d->m_noteTitleQuality;
}

void NoteAttributes::setNoteTitleQuality(std::optional<qint32> noteTitleQuality)
{
    d->m_noteTitleQuality = noteTitleQuality;
}

void NoteAttributes::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteAttributes::operator==(const NoteAttributes & other) const noexcept
{
    return *d == *other.d;
}

bool NoteAttributes::operator!=(const NoteAttributes & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
