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

#ifndef QEVERCLOUD_GENERATED_NOTEATTRIBUTES_H
#define QEVERCLOUD_GENERATED_NOTEATTRIBUTES_H

#include <qevercloud/Export.h>

#include "LazyMap.h"
#include "QMap"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <optional>

namespace qevercloud {

/**
 * The list of optional attributes that can be stored on a note.
 * */
class QEVERCLOUD_EXPORT NoteAttributes: public Printable
{
    Q_GADGET
public:
    NoteAttributes();
    NoteAttributes(const NoteAttributes & other);
    NoteAttributes(NoteAttributes && other) noexcept;
    ~NoteAttributes() noexcept override;

    NoteAttributes & operator=(const NoteAttributes & other);
    NoteAttributes & operator=(NoteAttributes && other) noexcept;

    /**
    time that the note refers to
    */
    [[nodiscard]] const std::optional<Timestamp> & subjectDate() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableSubjectDate();
    void setSubjectDate(std::optional<Timestamp> subjectDate);

    /**
    the latitude where the note was taken
    */
    [[nodiscard]] const std::optional<double> & latitude() const noexcept;
    [[nodiscard]] std::optional<double> & mutableLatitude();
    void setLatitude(std::optional<double> latitude);

    /**
    the longitude where the note was taken
    */
    [[nodiscard]] const std::optional<double> & longitude() const noexcept;
    [[nodiscard]] std::optional<double> & mutableLongitude();
    void setLongitude(std::optional<double> longitude);

    /**
    the altitude where the note was taken
    */
    [[nodiscard]] const std::optional<double> & altitude() const noexcept;
    [[nodiscard]] std::optional<double> & mutableAltitude();
    void setAltitude(std::optional<double> altitude);

    /**
    the author of the content of the note
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    [[nodiscard]] const std::optional<QString> & author() const noexcept;
    void setAuthor(std::optional<QString> author);

    /**
    the method that the note was added to the account, if the
       note wasn't directly authored in an Evernote desktop client.
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    [[nodiscard]] const std::optional<QString> & source() const noexcept;
    void setSource(std::optional<QString> source);

    /**
    the original location where the resource was hosted. For web clips,
       this will be the URL of the page that was clipped.
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    [[nodiscard]] const std::optional<QString> & sourceURL() const noexcept;
    void setSourceURL(std::optional<QString> sourceURL);

    /**
    an identifying string for the application that
       created this note.  This string does not have a guaranteed syntax or
       structure -- it is intended for human inspection and tracking.
       <br/>
       Length:  EDAM_ATTRIBUTE_LEN_MIN - EDAM_ATTRIBUTE_LEN_MAX
    */
    [[nodiscard]] const std::optional<QString> & sourceApplication() const noexcept;
    void setSourceApplication(std::optional<QString> sourceApplication);

    /**
    The date and time when this note was directly shared via its own URL.
      This is only set on notes that were individually shared - it is independent
      of any notebook-level sharing of the containing notebook. This field
      is treated as "read-only" for clients; the server will ignore changes
      to this field from an external client.
    */
    [[nodiscard]] const std::optional<Timestamp> & shareDate() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableShareDate();
    void setShareDate(std::optional<Timestamp> shareDate);

    /**
    The set of notes with this parameter set are considered
     "reminders" and are to be treated specially by clients to give them
     higher UI prominence within a notebook.  The value is used to sort
     the reminder notes within the notebook with higher values
     representing greater prominence.  Outside of the context of a
     notebook, the value of this parameter is undefined.  The value is
     not intended to be compared to the values of reminder notes in
     other notebooks.  In order to allow clients to place a note at a
     higher precedence than other notes, you should never set a value
     greater than the current time (as defined for a Timetstamp). To
     place a note at higher precedence than existing notes, set the
     value to the current time as defined for a timestamp (milliseconds
     since the epoch).  Synchronizing clients must remember the time when
     the update was performed, using the local clock on the client,
     and use that value when they later upload the note to the service.
     Clients must not set the reminderOrder to the reminderTime as the
     reminderTime could be in the future.  Those two fields are never
     intended to be related.  The correct value for reminderOrder field
     for new notes is the "current" time when the user indicated that
     the note is a reminder.  Clients may implement a separate
     "sort by date" feature to show notes ordered by reminderTime.
     Whenever a reminderDoneTime or reminderTime is set but a
     reminderOrder is not set, the server will fill in the current
     server time for the reminderOrder field.
    */
    [[nodiscard]] const std::optional<qint64> & reminderOrder() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableReminderOrder();
    void setReminderOrder(std::optional<qint64> reminderOrder);

    /**
    The date and time when a user dismissed/"marked done" the reminder
     on the note.  Users typically do not manually set this value directly
     as it is set to the time when the user dismissed/"marked done" the
     reminder.
    */
    [[nodiscard]] const std::optional<Timestamp> & reminderDoneTime() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableReminderDoneTime();
    void setReminderDoneTime(std::optional<Timestamp> reminderDoneTime);

    /**
    The date and time a user has selected to be reminded of the note.
     A note with this value set is known as a "reminder" and the user can
     be reminded, via e-mail or client-specific notifications, of the note
     when the time is reached or about to be reached.  When a user sets
     a reminder time on a note that has a reminder done time, and that
     reminder time is in the future, then the reminder done time should be
     cleared.  This should happen regardless of any existing reminder time
     that may have previously existed on the note.
    */
    [[nodiscard]] const std::optional<Timestamp> & reminderTime() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableReminderTime();
    void setReminderTime(std::optional<Timestamp> reminderTime);

    /**
    Allows the user to assign a human-readable location name associated
     with a note. Users may assign values like 'Home' and 'Work'. Place
     names may also be populated with values from geonames database
     (e.g., a restaurant name). Applications are encouraged to normalize values
     so that grouping values by place name provides a useful result. Applications
     MUST NOT automatically add place name values based on geolocation without
     confirmation from the user; that is, the value in this field should be
     more useful than a simple automated lookup based on the note's latitude
     and longitude.
    */
    [[nodiscard]] const std::optional<QString> & placeName() const noexcept;
    void setPlaceName(std::optional<QString> placeName);

    /**
    The class (or type) of note. This field is used to indicate to
     clients that special structured information is represented within
     the note such that special rules apply when making
     modifications. If contentClass is set and the client
     application does not specifically support the specified class,
     the client MUST treat the note as read-only. In this case, the
     client MAY modify the note's notebook and tags via the
     Note.notebookGuid and Note.tagGuids fields.  The client MAY also
     modify the reminderOrder field as well as the reminderTime and
     reminderDoneTime fields.
     <p>Applications should set contentClass only when they are creating notes
     that contain structured information that needs to be maintained in order
     for the user to be able to use the note within that application.
     Setting contentClass makes a note read-only in other applications, so
     there is a trade-off when an application chooses to use contentClass.
     Applications that set contentClass when creating notes must use a contentClass
     string of the form <i>CompanyName.ApplicationName</i> to ensure uniqueness.</p>
     Length restrictions: EDAM_NOTE_CONTENT_CLASS_LEN_MIN, EDAM_NOTE_CONTENT_CLASS_LEN_MAX
     <br/>
     Regex: EDAM_NOTE_CONTENT_CLASS_REGEX
    */
    [[nodiscard]] const std::optional<QString> & contentClass() const noexcept;
    void setContentClass(std::optional<QString> contentClass);

    /**
    Provides a location for applications to store a relatively small
     (4kb) blob of data that is not meant to be visible to the user and
     that is opaque to the Evernote service. A single application may use at most
     one entry in this map, using its API consumer key as the map key. See the
     documentation for LazyMap for a description of when the actual map values
     are returned by the service.
     <p>To safely add or modify your application's entry in the map, use
     NoteStore.setNoteApplicationDataEntry. To safely remove your application's
     entry from the map, use NoteStore.unsetNoteApplicationDataEntry.</p>
     Minimum length of a name (key): EDAM_APPLICATIONDATA_NAME_LEN_MIN
     <br/>
     Sum max size of key and value: EDAM_APPLICATIONDATA_ENTRY_LEN_MAX
     <br/>
     Syntax regex for name (key): EDAM_APPLICATIONDATA_NAME_REGEX
    */
    [[nodiscard]] const std::optional<LazyMap> & applicationData() const noexcept;
    [[nodiscard]] std::optional<LazyMap> & mutableApplicationData();
    void setApplicationData(std::optional<LazyMap> applicationData);

    /**
    An indication of who made the last change to the note.  If you are
     accessing the note via a shared notebook to which you have modification
     rights, or if you are the owner of the notebook to which the note belongs,
     then you have access to the value.  In this case, the value will be
     unset if the owner of the notebook containing the note was the last to
     make the modification, else it will be a string describing the
     guest who made the last edit.  If you do not have access to this value,
     it will be left unset.  This field is read-only by clients.  The server
     will ignore all values set by clients into this field.
    */
    [[nodiscard]] const std::optional<QString> & lastEditedBy() const noexcept;
    void setLastEditedBy(std::optional<QString> lastEditedBy);

    /**
    A map of classifications applied to the note by clients or by the
     Evernote service. The key is the string name of the classification type,
     and the value is a constant that begins with CLASSIFICATION_.
    */
    [[nodiscard]] const std::optional<QMap<QString, QString>> & classifications() const noexcept;
    [[nodiscard]] std::optional<QMap<QString, QString>> & mutableClassifications();
    void setClassifications(std::optional<QMap<QString, QString>> classifications);

    /**
    The numeric user ID of the user who originally created the note.
    */
    [[nodiscard]] const std::optional<UserID> & creatorId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableCreatorId();
    void setCreatorId(std::optional<UserID> creatorId);

    /**
    The numeric user ID of the user described in lastEditedBy.
    */
    [[nodiscard]] const std::optional<UserID> & lastEditorId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableLastEditorId();
    void setLastEditorId(std::optional<UserID> lastEditorId);

    /**
    When this flag is set on a business note, any user in that business
     may view the note if they request it by GUID. This field is read-only by
     clients. The server will ignore all values set by clients into this field.
    
     To share a note with the business, use NoteStore.shareNoteWithBusiness and
     to stop sharing a note with the business, use NoteStore.stopSharingNoteWithBusiness.
    */
    [[nodiscard]] const std::optional<bool> & sharedWithBusiness() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableSharedWithBusiness();
    void setSharedWithBusiness(std::optional<bool> sharedWithBusiness);

    /**
    If set, this specifies the GUID of a note that caused a sync conflict
     resulting in the creation of a duplicate note. The duplicated note contains
     the user's changes that could not be applied as a result of the sync conflict,
     and uses the conflictSourceNoteGuid field to specify the note that caused the
     conflict. This allows clients to provide a customized user experience for note
     conflicts.
    */
    [[nodiscard]] const std::optional<Guid> & conflictSourceNoteGuid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableConflictSourceNoteGuid();
    void setConflictSourceNoteGuid(std::optional<Guid> conflictSourceNoteGuid);

    /**
    If set, this specifies that the note's title was automatically generated
     and indicates the likelihood that the generated title is useful for display to
     the user. If not set, the note's title was manually entered by the user.
    
     Clients MUST set this attribute to one of the following values when the
     corresponding note's title was not manually entered by the user:
     EDAM_NOTE_TITLE_QUALITY_UNTITLED, EDAM_NOTE_TITLE_QUALITY_LOW,
     EDAM_NOTE_TITLE_QUALITY_MEDIUM or EDAM_NOTE_TITLE_QUALITY_HIGH.
    
     When a user edits a note's title, clients MUST unset this value.
    */
    [[nodiscard]] const std::optional<qint32> & noteTitleQuality() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableNoteTitleQuality();
    void setNoteTitleQuality(std::optional<qint32> noteTitleQuality);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NoteAttributes & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteAttributes & other) const noexcept;

    using Classifications = QMap<QString, QString>;

    Q_PROPERTY(std::optional<Timestamp> subjectDate READ subjectDate WRITE setSubjectDate)
    Q_PROPERTY(std::optional<double> latitude READ latitude WRITE setLatitude)
    Q_PROPERTY(std::optional<double> longitude READ longitude WRITE setLongitude)
    Q_PROPERTY(std::optional<double> altitude READ altitude WRITE setAltitude)
    Q_PROPERTY(std::optional<QString> author READ author WRITE setAuthor)
    Q_PROPERTY(std::optional<QString> source READ source WRITE setSource)
    Q_PROPERTY(std::optional<QString> sourceURL READ sourceURL WRITE setSourceURL)
    Q_PROPERTY(std::optional<QString> sourceApplication READ sourceApplication WRITE setSourceApplication)
    Q_PROPERTY(std::optional<Timestamp> shareDate READ shareDate WRITE setShareDate)
    Q_PROPERTY(std::optional<qint64> reminderOrder READ reminderOrder WRITE setReminderOrder)
    Q_PROPERTY(std::optional<Timestamp> reminderDoneTime READ reminderDoneTime WRITE setReminderDoneTime)
    Q_PROPERTY(std::optional<Timestamp> reminderTime READ reminderTime WRITE setReminderTime)
    Q_PROPERTY(std::optional<QString> placeName READ placeName WRITE setPlaceName)
    Q_PROPERTY(std::optional<QString> contentClass READ contentClass WRITE setContentClass)
    Q_PROPERTY(std::optional<LazyMap> applicationData READ applicationData WRITE setApplicationData)
    Q_PROPERTY(std::optional<QString> lastEditedBy READ lastEditedBy WRITE setLastEditedBy)
    Q_PROPERTY(std::optional<Classifications> classifications READ classifications WRITE setClassifications)
    Q_PROPERTY(std::optional<UserID> creatorId READ creatorId WRITE setCreatorId)
    Q_PROPERTY(std::optional<UserID> lastEditorId READ lastEditorId WRITE setLastEditorId)
    Q_PROPERTY(std::optional<bool> sharedWithBusiness READ sharedWithBusiness WRITE setSharedWithBusiness)
    Q_PROPERTY(std::optional<Guid> conflictSourceNoteGuid READ conflictSourceNoteGuid WRITE setConflictSourceNoteGuid)
    Q_PROPERTY(std::optional<qint32> noteTitleQuality READ noteTitleQuality WRITE setNoteTitleQuality)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteAttributes)

#endif // QEVERCLOUD_GENERATED_NOTEATTRIBUTES_H
