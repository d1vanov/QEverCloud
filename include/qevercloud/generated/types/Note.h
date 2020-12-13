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

#ifndef QEVERCLOUD_GENERATED_NOTE_H
#define QEVERCLOUD_GENERATED_NOTE_H

#include "../../Export.h"

#include "NoteAttributes.h"
#include "NoteLimits.h"
#include "NoteRestrictions.h"
#include "Resource.h"
#include "SharedNote.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/Printable.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <QByteArray>
#include <QList>
#include <optional>

namespace qevercloud {

/**
 * Represents a single note in the user's account.
 *
 * */
class QEVERCLOUD_EXPORT Note: public Printable
{
    Q_GADGET
public:
    Note();
    Note(const Note & other);
    Note(Note && other) noexcept;
    ~Note() noexcept override;

    Note & operator=(const Note & other);
    Note & operator=(Note && other) noexcept;

    /**
     * @brief localId can be used as a local unique identifier
     * for any data item before it has been synchronized with
     * Evernote and thus before it can be identified using its guid.
     *
     * localId is generated automatically on
     * construction for convenience but can be overridden manually
     */
    [[nodiscard]] QString localId() const;
    void setLocalId(QString id);

    /**
     * @brief parentLocalId can be used as a local unique identifier
     * of the data item being a parent to this data item.
     *
     * For example, a note is a parent to a resource, a notebook
     * is a parent to a note. So note's localId is a parentLocalId for a
     * resource, notebook's localId is a parentLocalId for a note,
     * tag's localId is a parentLocalId to a child tag.
     *
     * By default the parentLocalId property is empty
     */
    [[nodiscard]] QString parentLocalId() const;
    void setParentLocalId(QString id);

    /**
     * @brief locallyModified flag can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocallyModified() const;
    void setLocallyModified(bool modified = true);

    /**
     * @brief localOnly flag can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocalOnly() const;
    void setLocalOnly(bool localOnly = true);

    /**
     * @brief locallyFavorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * a property between different clients
     */
    [[nodiscard]] bool isLocallyFavorited() const;
    void setLocallyFavorited(bool favorited = true);

    /**
    The unique identifier of this note.  Will be set by the
       server, but will be omitted by clients calling NoteStore.createNote()
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    [[nodiscard]] const std::optional<Guid> & guid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableGuid();
    void setGuid(std::optional<Guid> guid);

    /**
    The subject of the note.  Can't begin or end with a space.
       <br/>
       Length:  EDAM_NOTE_TITLE_LEN_MIN - EDAM_NOTE_TITLE_LEN_MAX
       <br/>
       Regex:  EDAM_NOTE_TITLE_REGEX
    */
    [[nodiscard]] const std::optional<QString> & title() const noexcept;
    void setTitle(std::optional<QString> title);

    /**
    The XHTML block that makes up the note.  This is
       the canonical form of the note's contents, so will include abstract
       Evernote tags for internal resource references.  A client may create
       a separate transformed version of this content for internal presentation,
       but the same canonical bytes should be used for transmission and
       comparison unless the user chooses to modify their content.
       <br/>
       Length:  EDAM_NOTE_CONTENT_LEN_MIN - EDAM_NOTE_CONTENT_LEN_MAX
    */
    [[nodiscard]] const std::optional<QString> & content() const noexcept;
    void setContent(std::optional<QString> content);

    /**
    The binary MD5 checksum of the UTF-8 encoded content
       body. This will always be set by the server, but clients may choose to omit
       this when they submit a note with content.
       <br/>
       Length:  EDAM_HASH_LEN (exactly)
    */
    [[nodiscard]] const std::optional<QByteArray> & contentHash() const noexcept;
    void setContentHash(std::optional<QByteArray> contentHash);

    /**
    The number of Unicode characters in the content of
       the note.  This will always be set by the service, but clients may choose
       to omit this value when they submit a Note.
    */
    [[nodiscard]] const std::optional<qint32> & contentLength() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableContentLength();
    void setContentLength(std::optional<qint32> contentLength);

    /**
    The date and time when the note was created in one of the
       clients.  In most cases, this will match the user's sense of when
       the note was created, and ordering between notes will be based on
       ordering of this field.  However, this is not a "reliable" timestamp
       if a client has an incorrect clock, so it cannot provide a true absolute
       ordering between notes.  Notes created directly through the service
       (e.g. via the web GUI) will have an absolutely ordered "created" value.
    */
    [[nodiscard]] const std::optional<Timestamp> & created() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableCreated();
    void setCreated(std::optional<Timestamp> created);

    /**
    The date and time when the note was last modified in one of
       the clients.  In most cases, this will match the user's sense of when
       the note was modified, but this field may not be absolutely reliable
       due to the possibility of client clock errors.
    */
    [[nodiscard]] const std::optional<Timestamp> & updated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableUpdated();
    void setUpdated(std::optional<Timestamp> updated);

    /**
    If present, the note is considered "deleted", and this
       stores the date and time when the note was deleted by one of the clients.
       In most cases, this will match the user's sense of when the note was
       deleted, but this field may be unreliable due to the possibility of
       client clock errors.
    */
    [[nodiscard]] const std::optional<Timestamp> & deleted() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableDeleted();
    void setDeleted(std::optional<Timestamp> deleted);

    /**
    If the note is available for normal actions and viewing,
       this flag will be set to true.
    */
    [[nodiscard]] const std::optional<bool> & active() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableActive();
    void setActive(std::optional<bool> active);

    /**
    A number identifying the last transaction to
       modify the state of this note (including changes to the note's attributes
       or resources).  The USN values are sequential within an account,
       and can be used to compare the order of modifications within the service.
    */
    [[nodiscard]] const std::optional<qint32> & updateSequenceNum() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUpdateSequenceNum();
    void setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);

    /**
    The unique identifier of the notebook that contains
       this note.  If no notebookGuid is provided on a call to createNote(), the
       default notebook will be used instead.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    [[nodiscard]] const std::optional<QString> & notebookGuid() const noexcept;
    void setNotebookGuid(std::optional<QString> notebookGuid);

    /**
    A list of the GUID identifiers for tags that are applied to this note.
       This may be provided in a call to createNote() to unambiguously declare
       the tags that should be assigned to the new note.  Alternately, clients
       may pass the names of desired tags via the 'tagNames' field during
       note creation.
       If the list of tags are omitted on a call to createNote(), then
       the server will assume that no changes have been made to the resources.
       Maximum:  EDAM_NOTE_TAGS_MAX tags per note
    */
    [[nodiscard]] const std::optional<QList<Guid>> & tagGuids() const noexcept;
    [[nodiscard]] std::optional<QList<Guid>> & mutableTagGuids();
    void setTagGuids(std::optional<QList<Guid>> tagGuids);

    /**
    The list of resources that are embedded within this note.
       If the list of resources are omitted on a call to updateNote(), then
       the server will assume that no changes have been made to the resources.
       The binary contents of the resources must be provided when the resource
       is first sent to the service, but it will be omitted by the service when
       the Note is returned in the future.
       Maximum:  EDAM_NOTE_RESOURCES_MAX resources per note
    */
    [[nodiscard]] const std::optional<QList<Resource>> & resources() const noexcept;
    [[nodiscard]] std::optional<QList<Resource>> & mutableResources();
    void setResources(std::optional<QList<Resource>> resources);

    /**
    A list of the attributes for this note.
       If the list of attributes are omitted on a call to updateNote(), then
       the server will assume that no changes have been made to the resources.
    */
    [[nodiscard]] const std::optional<NoteAttributes> & attributes() const noexcept;
    [[nodiscard]] std::optional<NoteAttributes> & mutableAttributes();
    void setAttributes(std::optional<NoteAttributes> attributes);

    /**
    May be provided by clients during calls to createNote() as an
       alternative to providing the tagGuids of existing tags.  If any tagNames
       are provided during createNote(), these will be found, or created if they
       don't already exist.  Created tags will have no parent (they will be at
       the top level of the tag panel).
    */
    [[nodiscard]] const std::optional<QStringList> & tagNames() const noexcept;
    [[nodiscard]] std::optional<QStringList> & mutableTagNames();
    void setTagNames(std::optional<QStringList> tagNames);

    /**
    The list of recipients with whom this note has been shared. This field will be unset if
         the caller has access to the note via the containing notebook, but does not have activity
         feed permission for that notebook. This field is read-only. Clients may not make changes to
         a note's sharing state via this field.
    */
    [[nodiscard]] const std::optional<QList<SharedNote>> & sharedNotes() const noexcept;
    [[nodiscard]] std::optional<QList<SharedNote>> & mutableSharedNotes();
    void setSharedNotes(std::optional<QList<SharedNote>> sharedNotes);

    /**
    If this field is set, the user has note-level permissions that may differ from their
         notebook-level permissions. In this case, the restrictions structure specifies
         a set of restrictions limiting the actions that a user may take on the note based
         on their note-level permissions. If this field is unset, then there are no
         note-specific restrictions. However, a client may still be limited based on the user's
         notebook permissions.
    */
    [[nodiscard]] const std::optional<NoteRestrictions> & restrictions() const noexcept;
    [[nodiscard]] std::optional<NoteRestrictions> & mutableRestrictions();
    void setRestrictions(std::optional<NoteRestrictions> restrictions);

    [[nodiscard]] const std::optional<NoteLimits> & limits() const noexcept;
    [[nodiscard]] std::optional<NoteLimits> & mutableLimits();
    void setLimits(std::optional<NoteLimits> limits);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const Note & other) const noexcept;
    [[nodiscard]] bool operator!=(const Note & other) const noexcept;

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(QString parentLocalId READ parentLocalId WRITE setParentLocalId)
    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<Guid> guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<QString> title READ title WRITE setTitle)
    Q_PROPERTY(std::optional<QString> content READ content WRITE setContent)
    Q_PROPERTY(std::optional<QByteArray> contentHash READ contentHash WRITE setContentHash)
    Q_PROPERTY(std::optional<qint32> contentLength READ contentLength WRITE setContentLength)
    Q_PROPERTY(std::optional<Timestamp> created READ created WRITE setCreated)
    Q_PROPERTY(std::optional<Timestamp> updated READ updated WRITE setUpdated)
    Q_PROPERTY(std::optional<Timestamp> deleted READ deleted WRITE setDeleted)
    Q_PROPERTY(std::optional<bool> active READ active WRITE setActive)
    Q_PROPERTY(std::optional<qint32> updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(std::optional<QString> notebookGuid READ notebookGuid WRITE setNotebookGuid)
    Q_PROPERTY(std::optional<QList<Guid>> tagGuids READ tagGuids WRITE setTagGuids)
    Q_PROPERTY(std::optional<QList<Resource>> resources READ resources WRITE setResources)
    Q_PROPERTY(std::optional<NoteAttributes> attributes READ attributes WRITE setAttributes)
    Q_PROPERTY(std::optional<QStringList> tagNames READ tagNames WRITE setTagNames)
    Q_PROPERTY(std::optional<QList<SharedNote>> sharedNotes READ sharedNotes WRITE setSharedNotes)
    Q_PROPERTY(std::optional<NoteRestrictions> restrictions READ restrictions WRITE setRestrictions)
    Q_PROPERTY(std::optional<NoteLimits> limits READ limits WRITE setLimits)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::Note)

#endif // QEVERCLOUD_GENERATED_NOTE_H
