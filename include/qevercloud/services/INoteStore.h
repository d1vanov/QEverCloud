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

#ifndef QEVERCLOUD_GENERATED_INOTESTORE
#define QEVERCLOUD_GENERATED_INOTESTORE

#include <qevercloud/Export.h>

#include <qevercloud/Constants.h>
#include <qevercloud/DurableService.h>
#include <qevercloud/RequestContext.h>
#include <qevercloud/Types.h>
#include <qevercloud/services/Fwd.h>
#include <QFuture>
#include <QObject>
#include <QVariant>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

/**
 * Service:  NoteStore
 * <p>
 * The NoteStore service is used by EDAM clients to exchange information
 * about the collection of notes in an account. This is primarily used for
 * synchronization, but could also be used by a "thin" client without a full
 * local cache.
 * </p><p>
 * Most functions take an "authenticationToken" parameter, which is the
 * value returned by the UserStore which permits access to the account.
 * </p>
 *
 * Calls which require an authenticationToken may throw an EDAMUserException
 * for the following reasons:
 *  <ul>
 *   <li>DATA_REQUIRED "authenticationToken" - token is empty</li>
 *   <li>BAD_DATA_FORMAT "authenticationToken" - token is malformed</li>
 *   <li>INVALID_AUTH "authenticationToken" - token signature is invalid</li>
 *   <li>AUTH_EXPIRED "authenticationToken" - token has expired or been revoked</li>
 *   <li>PERMISSION_DENIED "authenticationToken" - token does not grant permission
 *       to perform the requested action</li>
 *   <li>BUSINESS_SECURITY_LOGIN_REQUIRED "sso" - the user is a member of a business
 *       that requires single sign-on, and must complete SSO before accessing business
 *       content.
 * </ul>
 */
class QEVERCLOUD_EXPORT INoteStore: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(INoteStore)
protected:
    INoteStore(QObject * parent) :
        QObject(parent)
    {}

public:
    virtual QString noteStoreUrl() const = 0;
    virtual void setNoteStoreUrl(QString url) = 0;

    virtual const std::optional<Guid> & linkedNotebookGuid() const = 0;
    virtual void setLinkedNotebookGuid(std::optional<Guid> linkedNotebookGuid) = 0;

    /**
       * Asks the NoteStore to provide information about the status of the user
       * account corresponding to the provided authentication token.
       */
    virtual SyncState getSyncState(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getSyncState @endlink */
    virtual QFuture<QVariant> getSyncStateAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the NoteStore to provide the state of the account in order of
       * last modification.  This request retrieves one block of the server's
       * state so that a client can make several small requests against a large
       * account rather than getting the entire state in one big message.
       * This call gives fine-grained control of the data that will
       * be received by a client by omitting data elements that a client doesn't
       * need. This may reduce network traffic and sync times.
       *
       * @param afterUSN
       *   The client can pass this value to ask only for objects that
       *   have been updated after a certain point.  This allows the client to
       *   receive updates after its last checkpoint rather than doing a full
       *   synchronization on every pass.  The default value of "0" indicates
       *   that the client wants to get objects from the start of the account.
       *
       * @param maxEntries
       *   The maximum number of modified objects that should be
       *   returned in the result SyncChunk.  This can be used to limit the size
       *   of each individual message to be friendly for network transfer.
       *
       * @param filter
       *   The caller must set some of the flags in this structure to specify which
       *   data types should be returned during the synchronization.  See
       *   the SyncChunkFilter structure for information on each flag.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "afterUSN" - if negative
       *   </li>
       *   <li> BAD_DATA_FORMAT "maxEntries" - if less than 1
       *   </li>
       * </ul>
       */
    virtual SyncChunk getFilteredSyncChunk(
        qint32 afterUSN,
        qint32 maxEntries,
        const SyncChunkFilter & filter,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getFilteredSyncChunk @endlink */
    virtual QFuture<QVariant> getFilteredSyncChunkAsync(
        qint32 afterUSN,
        qint32 maxEntries,
        const SyncChunkFilter & filter,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the NoteStore to provide information about the status of a linked
       * notebook that has been shared with the caller, or that is public to the
       * world.
       * This will return a result that is similar to getSyncState, but may omit
       * SyncState.uploaded if the caller doesn't have permission to write to
       * the linked notebook.
       *
       * This function must be called on the shard that owns the referenced
       * notebook.  (I.e. the shardId in /shard/shardId/edam/note must be the
       * same as LinkedNotebook.shardId.)
       *
       * @param authenticationToken
       *   This should be an authenticationToken for the guest who has received
       *   the invitation to the share.  (I.e. this should not be the result of
       *   NoteStore.authenticateToSharedNotebook)
       *
       * @param linkedNotebook
       *   This structure should contain identifying information and permissions
       *   to access the notebook in question.
       *
       * @throws EDAMUserException <ul>
       *   <li>DATA_REQUIRED "LinkedNotebook.username" - The username field must be
       *       populated with the current username of the owner of the notebook for which
       *       you are obtaining sync state.
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li>"LinkedNotebook.username" - If the LinkedNotebook.username field does not
       *       correspond to a current user on the service.
       *   </li>
       * </ul>
       *
       * @throws SystemException <ul>
       *   <li>SHARD_UNAVAILABLE - If the provided LinkedNotebook.username corresponds to a
       *       user whose account is on a shard other than that on which this method was
       *       invoked.
       *   </li>
       * </ul>
       */
    virtual SyncState getLinkedNotebookSyncState(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getLinkedNotebookSyncState @endlink */
    virtual QFuture<QVariant> getLinkedNotebookSyncStateAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the NoteStore to provide information about the contents of a linked
       * notebook that has been shared with the caller, or that is public to the
       * world.
       * This will return a result that is similar to getSyncChunk, but will only
       * contain entries that are visible to the caller.  I.e. only that particular
       * Notebook will be visible, along with its Notes, and Tags on those Notes.
       *
       * This function must be called on the shard that owns the referenced
       * notebook.  (I.e. the shardId in /shard/shardId/edam/note must be the
       * same as LinkedNotebook.shardId.)
       *
       * @param authenticationToken
       *   This should be an authenticationToken for the guest who has received
       *   the invitation to the share.  (I.e. this should not be the result of
       *   NoteStore.authenticateToSharedNotebook)
       *
       * @param linkedNotebook
       *   This structure should contain identifying information and permissions
       *   to access the notebook in question.  This must contain the valid fields
       *   for either a shared notebook (e.g. shareKey)
       *   or a public notebook (e.g. username, uri)
       *
       * @param afterUSN
       *   The client can pass this value to ask only for objects that
       *   have been updated after a certain point.  This allows the client to
       *   receive updates after its last checkpoint rather than doing a full
       *   synchronization on every pass.  The default value of "0" indicates
       *   that the client wants to get objects from the start of the account.
       *
       * @param maxEntries
       *   The maximum number of modified objects that should be
       *   returned in the result SyncChunk.  This can be used to limit the size
       *   of each individual message to be friendly for network transfer.
       *   Applications should not request more than 256 objects at a time,
       *   and must handle the case where the service returns less than the
       *   requested number of objects in a given request even though more
       *   objects are available on the service.
       *
       * @param fullSyncOnly
       *   If true, then the client only wants initial data for a full sync.
       *   In this case, the service will not return any expunged objects,
       *   and will not return any Resources, since these are also provided
       *   in their corresponding Notes.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "afterUSN" - if negative
       *   </li>
       *   <li> BAD_DATA_FORMAT "maxEntries" - if less than 1
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "LinkedNotebook" - if the provided information doesn't match any
       *     valid notebook
       *   </li>
       *   <li> "LinkedNotebook.uri" - if the provided public URI doesn't match any
       *     valid notebook
       *   </li>
       *   <li> "SharedNotebook.id" - if the provided information indicates a
       *      shared notebook that no longer exists
       *   </li>
       * </ul>
       */
    virtual SyncChunk getLinkedNotebookSyncChunk(
        const LinkedNotebook & linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getLinkedNotebookSyncChunk @endlink */
    virtual QFuture<QVariant> getLinkedNotebookSyncChunkAsync(
        const LinkedNotebook & linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of all of the notebooks in the account.
       */
    virtual QList<Notebook> listNotebooks(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listNotebooks @endlink */
    virtual QFuture<QVariant> listNotebooksAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of all the notebooks in a business that the user has permission to access,
       * regardless of whether the user has joined them. This includes notebooks that have been shared
       * with the entire business as well as notebooks that have been shared directly with the user.
       *
       * @param authenticationToken A business authentication token obtained by calling
       *   UserStore.authenticateToBusiness.
       *
       * @throws EDAMUserException <ul>
       *   <li> INVALID_AUTH "authenticationToken" - if the authentication token is not a
       *     business auth token.</li>
       * </ul>
       */
    virtual QList<Notebook> listAccessibleBusinessNotebooks(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listAccessibleBusinessNotebooks @endlink */
    virtual QFuture<QVariant> listAccessibleBusinessNotebooksAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the current state of the notebook with the provided GUID.
       * The notebook may be active or deleted (but not expunged).
       *
       * @param guid
       *   The GUID of the notebook to be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Notebook.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Notebook" - private notebook, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Notebook.guid" - tag not found, by GUID
       *   </li>
       * </ul>
       */
    virtual Notebook getNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNotebook @endlink */
    virtual QFuture<QVariant> getNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the notebook that should be used to store new notes in the
       * user's account when no other notebooks are specified.
       */
    virtual Notebook getDefaultNotebook(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getDefaultNotebook @endlink */
    virtual QFuture<QVariant> getDefaultNotebookAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the service to make a notebook with the provided name.
       *
       * @param notebook
       *   The desired fields for the notebook must be provided on this
       *   object.  The name of the notebook must be set, and either the 'active'
       *   or 'defaultNotebook' fields may be set by the client at creation.
       *   If a notebook exists in the account with the same name (via
       *   case-insensitive compare), this will throw an EDAMUserException.
       *
       * @return
       *   The newly created Notebook.  The server-side GUID will be
       *   saved in this object's 'guid' field.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Notebook.name" - invalid length or pattern</li>
       *   <li> BAD_DATA_FORMAT "Notebook.stack" - invalid length or pattern</li>
       *   <li> BAD_DATA_FORMAT "Publishing.uri" - if publishing set but bad uri</li>
       *   <li> BAD_DATA_FORMAT "Publishing.publicDescription" - if too long</li>
       *   <li> DATA_CONFLICT "Notebook.name" - name already in use</li>
       *   <li> DATA_CONFLICT "Publishing.uri" - if URI already in use</li>
       *   <li> DATA_REQUIRED "Publishing.uri" - if publishing set but uri missing</li>
       *   <li> DATA_REQUIRED "Notebook" - notebook parameter was null</li>
       *   <li> PERMISSION_DENIED "Notebook.defaultNotebook" - if the 'defaultNotebook' field
       *        is set to 'true' for a Notebook that is not owned by the user identified by
       *        the passed authenticationToken.</li>
       *   <li> LIMIT_REACHED "Notebook" - at max number of notebooks</li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Workspace.guid" - if workspaceGuid set and no Workspace exists for the GUID
       *   </li>
       * </ul>
       */
    virtual Notebook createNotebook(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link createNotebook @endlink */
    virtual QFuture<QVariant> createNotebookAsync(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Submits notebook changes to the service. The provided data must include the
       * notebook's guid field for identification.
       * <p />
       * The Notebook will be moved to the specified Workspace, if a non empty
       * Notebook.workspaceGuid is provided. If an empty Notebook.workspaceGuid is set and the
       * Notebook is in a Workspace, then it will be removed from the Workspace and a full
       * access SharedNotebook record will be ensured for the caller. If the caller does not
       * already have a full access share, either the privilege of an existing share will be
       * upgraded or a new share will be created. It is illegal to set a
       * Notebook.workspaceGuid on a Workspace backing Notebook.
       *
       * @param notebook
       *   The notebook object containing the requested changes.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Notebook.name" - invalid length or pattern</li>
       *   <li> BAD_DATA_FORMAT "Notebook.stack" - invalid length or pattern</li>
       *   <li> BAD_DATA_FORMAT "Publishing.uri" - if publishing set but bad uri</li>
       *   <li> BAD_DATA_FORMAT "Publishing.publicDescription" - if too long</li>
       *   <li> DATA_CONFLICT "Notebook.name" - name already in use</li>
       *   <li> DATA_CONFLICT "Publishing.uri" - if URI already in use</li>
       *   <li> DATA_REQUIRED "Publishing.uri" - if publishing set but uri missing</li>
       *   <li> DATA_REQUIRED "Notebook" - notebook parameter was null</li>
       *   <li> PERMISSION_DENIED "Notebook.defaultNotebook" - if the 'defaultNotebook' field
       *        is set to 'true' for a Notebook that is not owned by the user identified by
       *        the passed authenticationToken.</li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Notebook.guid" - not found, by GUID</li>
       *   <li> "Workspace.guid" - if a non empty workspaceGuid set and no Workspace exists
       *        for the GUID
       *   </li>
       * </ul>
       */
    virtual qint32 updateNotebook(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateNotebook @endlink */
    virtual QFuture<QVariant> updateNotebookAsync(
        const Notebook & notebook,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Permanently removes the notebook from the user's account.
       * After this action, the notebook is no longer available for undeletion, etc.
       * If the notebook contains any Notes, they will be moved to the current
       * default notebook and moved into the trash (i.e. Note.active=false).
       * <p/>
       * NOTE: This function is generally not available to third party applications.
       * Calls will result in an EDAMUserException with the error code
       * PERMISSION_DENIED.
       *
       * @param guid
       *   The GUID of the notebook to delete.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Notebook.guid" - if the parameter is missing
       *   </li>
       *   <li> LIMIT_REACHED "Notebook" - trying to expunge the last Notebook
       *   </li>
       *   <li> PERMISSION_DENIED "Notebook" - private notebook, user doesn't own
       *   </li>
       * </ul>
       */
    virtual qint32 expungeNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link expungeNotebook @endlink */
    virtual QFuture<QVariant> expungeNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of the tags in the account.  Evernote does not support
       * the undeletion of tags, so this will only include active tags.
       */
    virtual QList<Tag> listTags(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listTags @endlink */
    virtual QFuture<QVariant> listTagsAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of the tags that are applied to at least one note within
       * the provided notebook.  If the notebook is public, the authenticationToken
       * may be ignored.
       *
       * @param notebookGuid
       *    the GUID of the notebook to use to find tags
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Notebook.guid" - notebook not found by GUID
       *   </li>
       * </ul>
       */
    virtual QList<Tag> listTagsByNotebook(
        Guid notebookGuid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listTagsByNotebook @endlink */
    virtual QFuture<QVariant> listTagsByNotebookAsync(
        Guid notebookGuid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the current state of the Tag with the provided GUID.
       *
       * @param guid
       *   The GUID of the tag to be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Tag.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Tag" - private Tag, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Tag.guid" - tag not found, by GUID
       *   </li>
       * </ul>
       */
    virtual Tag getTag(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getTag @endlink */
    virtual QFuture<QVariant> getTagAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the service to make a tag with a set of information.
       *
       * @param tag
       *   The desired list of fields for the tag are specified in this
       *   object.  The caller must specify the tag name, and may provide
       *   the parentGUID.
       *
       * @return
       *   The newly created Tag.  The server-side GUID will be
       *   saved in this object.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Tag.name" - invalid length or pattern
       *   </li>
       *   <li> BAD_DATA_FORMAT "Tag.parentGuid" - malformed GUID
       *   </li>
       *   <li> DATA_CONFLICT "Tag.name" - name already in use
       *   </li>
       *   <li> LIMIT_REACHED "Tag" - at max number of tags
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Tag.parentGuid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual Tag createTag(
        const Tag & tag,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link createTag @endlink */
    virtual QFuture<QVariant> createTagAsync(
        const Tag & tag,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Submits tag changes to the service.  The provided data must include
       * the tag's guid field for identification.  The service will apply
       * updates to the following tag fields:  name, parentGuid
       *
       * @param tag
       *   The tag object containing the requested changes.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Tag.name" - invalid length or pattern
       *   </li>
       *   <li> BAD_DATA_FORMAT "Tag.parentGuid" - malformed GUID
       *   </li>
       *   <li> DATA_CONFLICT "Tag.name" - name already in use
       *   </li>
       *   <li> DATA_CONFLICT "Tag.parentGuid" - can't set parent: circular
       *   </li>
       *   <li> PERMISSION_DENIED "Tag" - user doesn't own tag
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Tag.guid" - tag not found, by GUID
       *   </li>
       *   <li> "Tag.parentGuid" - parent not found, by GUID
       *   </li>
       * </ul>
       */
    virtual qint32 updateTag(
        const Tag & tag,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateTag @endlink */
    virtual QFuture<QVariant> updateTagAsync(
        const Tag & tag,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Removes the provided tag from every note that is currently tagged with
       * this tag.  If this operation is successful, the tag will still be in
       * the account, but it will not be tagged on any notes.
       *
       * This function is not indended for use by full synchronizing clients, since
       * it does not provide enough result information to the client to reconcile
       * the local state without performing a follow-up sync from the service.  This
       * is intended for "thin clients" that need to efficiently support this as
       * a UI operation.
       *
       * @param guid
       *   The GUID of the tag to remove from all notes.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Tag.guid" - if the guid parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Tag" - user doesn't own tag
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Tag.guid" - tag not found, by GUID
       *   </li>
       * </ul>
       */
    virtual void untagAll(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link untagAll @endlink */
    virtual QFuture<QVariant> untagAllAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Permanently deletes the tag with the provided GUID, if present.
       * <p/>
       * NOTE: This function is not generally available to third party applications.
       * Calls will result in an EDAMUserException with the error code
       * PERMISSION_DENIED.
       *
       * @param guid
       *   The GUID of the tag to delete.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Tag.guid" - if the guid parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Tag" - user doesn't own tag
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Tag.guid" - tag not found, by GUID
       *   </li>
       * </ul>
       */
    virtual qint32 expungeTag(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link expungeTag @endlink */
    virtual QFuture<QVariant> expungeTagAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of the searches in the account.  Evernote does not support
       * the undeletion of searches, so this will only include active searches.
       */
    virtual QList<SavedSearch> listSearches(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listSearches @endlink */
    virtual QFuture<QVariant> listSearchesAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the current state of the search with the provided GUID.
       *
       * @param guid
       *   The GUID of the search to be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "SavedSearch.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "SavedSearch" - private Tag, user doesn't own
       *   </li>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "SavedSearch.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual SavedSearch getSearch(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getSearch @endlink */
    virtual QFuture<QVariant> getSearchAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the service to make a saved search with a set of information.
       *
       * @param search
       *   The desired list of fields for the search are specified in this
       *   object. The caller must specify the name and query for the
       *   search, and may optionally specify a search scope.
       *   The SavedSearch.format field is ignored by the service.
       *
       * @return
       *   The newly created SavedSearch.  The server-side GUID will be
       *   saved in this object.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "SavedSearch.name" - invalid length or pattern
       *   </li>
       *   <li> BAD_DATA_FORMAT "SavedSearch.query" - invalid length
       *   </li>
       *   <li> DATA_CONFLICT "SavedSearch.name" - name already in use
       *   </li>
       *   <li> LIMIT_REACHED "SavedSearch" - at max number of searches
       *   </li>
       * </ul>
       */
    virtual SavedSearch createSearch(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link createSearch @endlink */
    virtual QFuture<QVariant> createSearchAsync(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Submits search changes to the service. The provided data must include
       * the search's guid field for identification. The service will apply
       * updates to the following search fields: name, query, and scope.
       *
       * @param search
       *   The search object containing the requested changes.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "SavedSearch.name" - invalid length or pattern
       *   </li>
       *   <li> BAD_DATA_FORMAT "SavedSearch.query" - invalid length
       *   </li>
       *   <li> DATA_CONFLICT "SavedSearch.name" - name already in use
       *   </li>
       *   <li> PERMISSION_DENIED "SavedSearch" - user doesn't own tag
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "SavedSearch.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual qint32 updateSearch(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateSearch @endlink */
    virtual QFuture<QVariant> updateSearchAsync(
        const SavedSearch & search,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Permanently deletes the saved search with the provided GUID, if present.
       * <p/>
       * NOTE: This function is generally not available to third party applications.
       * Calls will result in an EDAMUserException with the error code
       * PERMISSION_DENIED.
       *
       * @param guid
       *   The GUID of the search to delete.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "SavedSearch.guid" - if the guid parameter is empty
       *   </li>
       *   <li> PERMISSION_DENIED "SavedSearch" - user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "SavedSearch.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual qint32 expungeSearch(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link expungeSearch @endlink */
    virtual QFuture<QVariant> expungeSearchAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Finds the position of a note within a sorted subset of all of the user's
       * notes. This may be useful for thin clients that are displaying a paginated
       * listing of a large account, which need to know where a particular note
       * sits in the list without retrieving all notes first.
       *
       * @param authenticationToken
       *   Must be a valid token for the user's account unless the NoteFilter
       *   'notebookGuid' is the GUID of a public notebook.
       *
       * @param filter
       *   The list of criteria that will constrain the notes to be returned.
       *
       * @param guid
       *   The GUID of the note to be retrieved.
       *
       * @return
       *   If the note with the provided GUID is found within the matching note
       *   list, this will return the offset of that note within that list (where
       *   the first offset is 0).  If the note is not found within the set of
       *   notes, this will return -1.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "offset" - not between 0 and EDAM_USER_NOTES_MAX
       *   </li>
       *   <li> BAD_DATA_FORMAT "maxNotes" - not between 0 and EDAM_USER_NOTES_MAX
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.notebookGuid" - if malformed
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.tagGuids" - if any are malformed
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.words" - if search string too long
       *   </li>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Notebook.guid" - not found, by GUID
       *   </li>
       *   <li> "Note.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual qint32 findNoteOffset(
        const NoteFilter & filter,
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link findNoteOffset @endlink */
    virtual QFuture<QVariant> findNoteOffsetAsync(
        const NoteFilter & filter,
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Used to find the high-level information about a set of the notes from a
       * user's account based on various criteria specified via a NoteFilter object.
       * <p/>
       * Web applications that wish to periodically check for new content in a user's
       * Evernote account should consider using webhooks instead of polling this API.
       * See http://dev.evernote.com/documentation/cloud/chapters/polling_notification.php
       * for more information.
       *
       * @param authenticationToken
       *   Must be a valid token for the user's account unless the NoteFilter
       *   'notebookGuid' is the GUID of a public notebook.
       *
       * @param filter
       *   The list of criteria that will constrain the notes to be returned.
       *
       * @param offset
       *   The numeric index of the first note to show within the sorted
       *   results.  The numbering scheme starts with "0".  This can be used for
       *   pagination.
       *
       * @param maxNotes
       *   The maximum notes to return in this query.  The service will return a set
       *   of notes that is no larger than this number, but may return fewer notes
       *   if needed.  The NoteList.totalNotes field in the return value will
       *   indicate whether there are more values available after the returned set.
       *   Currently, the service will not return more than 250 notes in a single request,
       *   but this number may change in the future.
       *
       * @param resultSpec
       *   This specifies which information should be returned for each matching
       *   Note. The fields on this structure can be used to eliminate data that
       *   the client doesn't need, which will reduce the time and bandwidth
       *   to receive and process the reply.
       *
       * @return
       *   The list of notes that match the criteria.
       *   The Notes.sharedNotes field will not be set.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "offset" - not between 0 and EDAM_USER_NOTES_MAX
       *   </li>
       *   <li> BAD_DATA_FORMAT "maxNotes" - not between 0 and EDAM_USER_NOTES_MAX
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.notebookGuid" - if malformed
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.tagGuids" - if any are malformed
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.words" - if search string too long
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Notebook.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual NotesMetadataList findNotesMetadata(
        const NoteFilter & filter,
        qint32 offset,
        qint32 maxNotes,
        const NotesMetadataResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link findNotesMetadata @endlink */
    virtual QFuture<QVariant> findNotesMetadataAsync(
        const NoteFilter & filter,
        qint32 offset,
        qint32 maxNotes,
        const NotesMetadataResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * This function is used to determine how many notes are found for each
       * notebook and tag in the user's account, given a current set of filter
       * parameters that determine the current selection.  This function will
       * return a structure that gives the note count for each notebook and tag
       * that has at least one note under the requested filter.  Any notebook or
       * tag that has zero notes in the filtered set will not be listed in the
       * reply to this function (so they can be assumed to be 0).
       *
       * @param authenticationToken
       *   Must be a valid token for the user's account unless the NoteFilter
       *   'notebookGuid' is the GUID of a public notebook.
       *
       * @param filter
       *   The note selection filter that is currently being applied.  The note
       *   counts are to be calculated with this filter applied to the total set
       *   of notes in the user's account.
       *
       * @param withTrash
       *   If true, then the NoteCollectionCounts.trashCount will be calculated
       *   and supplied in the reply. Otherwise, the trash value will be omitted.
       *
       * @throws EDAMUserException <ul>
       *   <li>BAD_DATA_FORMAT "NoteFilter.notebookGuid" - if malformed</li>
       *   <li>BAD_DATA_FORMAT "NoteFilter.notebookGuids" - if any are malformed</li>
       *   <li>BAD_DATA_FORMAT "NoteFilter.words" - if search string too long</li>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Notebook.guid" - not found, by GUID</li>
       * </ul>
       */
    virtual NoteCollectionCounts findNoteCounts(
        const NoteFilter & filter,
        bool withTrash,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link findNoteCounts @endlink */
    virtual QFuture<QVariant> findNoteCountsAsync(
        const NoteFilter & filter,
        bool withTrash,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the current state of the note in the service with the provided
       * GUID.  The ENML contents of the note will only be provided if the
       * 'withContent' parameter is true.  The service will include the meta-data
       * for each resource in the note, but the binary content depends
       * on whether it is explicitly requested in resultSpec parameter.
       * If the Note is found in a public notebook, the authenticationToken
       * will be ignored (so it could be an empty string).  The applicationData
       * fields are returned as keysOnly.
       *
       * @param authenticationToken
       *   An authentication token that grants the caller access to the requested note.
       *
       * @param guid
       *   The GUID of the note to be retrieved.
       *
       * @param resultSpec
       *   A structure specifying the fields of the note that the caller would like to get.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Note.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Note" - private note, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual Note getNoteWithResultSpec(
        Guid guid,
        const NoteResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNoteWithResultSpec @endlink */
    virtual QFuture<QVariant> getNoteWithResultSpecAsync(
        Guid guid,
        const NoteResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * DEPRECATED. See getNoteWithResultSpec.
       *
       * This function is equivalent to getNoteWithResultSpec, with each of the boolean parameters
       * mapping to the equivalent field of a NoteResultSpec. The Note.sharedNotes field is never
       * populated on the returned note. To get a note with its shares, use getNoteWithResultSpec.
       */
    virtual Note getNote(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNote @endlink */
    virtual QFuture<QVariant> getNoteAsync(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Get all of the application data for the note identified by GUID,
       * with values returned within the LazyMap fullMap field.
       * If there are no applicationData entries, then a LazyMap
       * with an empty fullMap will be returned. If your application
       * only needs to fetch its own applicationData entry, use
       * getNoteApplicationDataEntry instead.
       */
    virtual LazyMap getNoteApplicationData(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNoteApplicationData @endlink */
    virtual QFuture<QVariant> getNoteApplicationDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Get the value of a single entry in the applicationData map
       * for the note identified by GUID.
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - note not found, by GUID</li>
       *   <li> "NoteAttributes.applicationData.key" - note not found, by key</li>
       * </ul>
       */
    virtual QString getNoteApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNoteApplicationDataEntry @endlink */
    virtual QFuture<QVariant> getNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Update, or create, an entry in the applicationData map for
       * the note identified by guid.
       */
    virtual qint32 setNoteApplicationDataEntry(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link setNoteApplicationDataEntry @endlink */
    virtual QFuture<QVariant> setNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Remove an entry identified by 'key' from the applicationData map for
       * the note identified by 'guid'. Silently ignores an unset of a
       * non-existing key.
       */
    virtual qint32 unsetNoteApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link unsetNoteApplicationDataEntry @endlink */
    virtual QFuture<QVariant> unsetNoteApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns XHTML contents of the note with the provided GUID.
       * If the Note is found in a public notebook, the authenticationToken
       * will be ignored (so it could be an empty string).
       *
       * @param guid
       *   The GUID of the note to be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Note.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Note" - private note, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual QString getNoteContent(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNoteContent @endlink */
    virtual QFuture<QVariant> getNoteContentAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a block of the extracted plain text contents of the note with the
       * provided GUID.  This text can be indexed for search purposes by a light
       * client that doesn't have capabilities to extract all of the searchable
       * text content from the note and its resources.
       *
       * If the Note is found in a public notebook, the authenticationToken
       * will be ignored (so it could be an empty string).
       *
       * @param guid
       *   The GUID of the note to be retrieved.
       *
       * @param noteOnly
       *   If true, this will only return the text extracted from the ENML contents
       *   of the note itself.  If false, this will also include the extracted text
       *   from any text-bearing resources (PDF, recognized images)
       *
       * @param tokenizeForIndexing
       *   If true, this will break the text into cleanly separated and sanitized
       *   tokens.  If false, this will return the more raw text extraction, with
       *   its original punctuation, capitalization, spacing, etc.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Note.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Note" - private note, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual QString getNoteSearchText(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNoteSearchText @endlink */
    virtual QFuture<QVariant> getNoteSearchTextAsync(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a block of the extracted plain text contents of the resource with
       * the provided GUID.  This text can be indexed for search purposes by a light
       * client that doesn't have capability to extract all of the searchable
       * text content from a resource.
       *
       * If the Resource is found in a public notebook, the authenticationToken
       * will be ignored (so it could be an empty string).
       *
       * @param guid
       *   The GUID of the resource to be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Resource.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Resource" - private resource, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Resource.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual QString getResourceSearchText(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResourceSearchText @endlink */
    virtual QFuture<QVariant> getResourceSearchTextAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of the names of the tags for the note with the provided
       * guid.  This can be used with authentication to get the tags for a
       * user's own note, or can be used without valid authentication to retrieve
       * the names of the tags for a note in a public notebook.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Note.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Note" - private note, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual QStringList getNoteTagNames(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNoteTagNames @endlink */
    virtual QFuture<QVariant> getNoteTagNamesAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the service to make a note with the provided set of information.
       *
       * @param note
       *   A Note object containing the desired fields to be populated on
       *   the service.
       *
       * @return
       *   The newly created Note from the service.  The server-side
       *   GUIDs for the Note and any Resources will be saved in this object.
       *   The service will include the meta-data
       *   for each resource in the note, but the binary contents of the resources
       *   and their recognition data will be omitted (except Recognition Resource body,
       *   for which the behavior is unspecified).
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Note.title" - invalid length or pattern
       *   </li>
       *   <li> BAD_DATA_FORMAT "Note.content" - invalid length for ENML content
       *   </li>
       *   <li> BAD_DATA_FORMAT "Resource.mime" - invalid resource MIME type
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteAttributes.*" - bad resource string
       *   </li>
       *   <li> BAD_DATA_FORMAT "ResourceAttributes.*" - bad resource string
       *   </li>
       *   <li> DATA_CONFLICT "Note.deleted" - deleted time set on active note
       *   </li>
       *   <li> DATA_REQUIRED "Resource.data" - resource data body missing
       *   </li>
       *   <li> ENML_VALIDATION "*" - note content doesn't validate against DTD
       *   </li>
       *   <li> LIMIT_REACHED "Note" - at max number per account
       *   </li>
       *   <li> LIMIT_REACHED "Note.size" - total note size too large
       *   </li>
       *   <li> LIMIT_REACHED "Note.resources" - too many resources on Note
       *   </li>
       *   <li> LIMIT_REACHED "Note.tagGuids" - too many Tags on Note
       *   </li>
       *   <li> LIMIT_REACHED "Resource.data.size" - resource too large
       *   </li>
       *   <li> LIMIT_REACHED "NoteAttribute.*" - attribute string too long
       *   </li>
       *   <li> LIMIT_REACHED "ResourceAttribute.*" - attribute string too long
       *   </li>
       *   <li> PERMISSION_DENIED "Note.notebookGuid" - NB not owned by user
       *   </li>
       *   <li> QUOTA_REACHED "Accounting.uploadLimit" - note exceeds upload quota
       *   </li>
       *   <li> BAD_DATA_FORMAT "Tag.name" - Note.tagNames was provided, and one
       *     of the specified tags had an invalid length or pattern
       *   </li>
       *   <li> LIMIT_REACHED "Tag" - Note.tagNames was provided, and the required
       *     new tags would exceed the maximum number per account
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.notebookGuid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual Note createNote(
        const Note & note,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link createNote @endlink */
    virtual QFuture<QVariant> createNoteAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Submit a set of changes to a note to the service.  The provided data
       * must include the note's guid field for identification. The note's
       * title must also be set.
       *
       * @param note
       *   A Note object containing the desired fields to be populated on
       *   the service. With the exception of the note's title and guid, fields
       *   that are not being changed do not need to be set. If the content is not
       *   being modified, note.content should be left unset. If the list of
       *   resources is not being modified, note.resources should be left unset.
       *
       * @return
       *   The Note.sharedNotes field will not be set.
       *   The service will include the meta-data
       *   for each resource in the note, but the binary contents of the resources
       *   and their recognition data will be omitted.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Note.title" - invalid length or pattern
       *   </li>
       *   <li> BAD_DATA_FORMAT "Note.content" - invalid length for ENML body
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteAttributes.*" - bad resource string
       *   </li>
       *   <li> BAD_DATA_FORMAT "ResourceAttributes.*" - bad resource string
       *   </li>
       *   <li> BAD_DATA_FORMAT "Resource.mime" - invalid resource MIME type
       *   </li>
       *   <li> DATA_CONFLICT "Note.deleted" - deleted time set on active note
       *   </li>
       *   <li> DATA_REQUIRED "Resource.data" - resource data body missing
       *   </li>
       *   <li> ENML_VALIDATION "*" - note content doesn't validate against DTD
       *   </li>
       *   <li> LIMIT_REACHED "Note.tagGuids" - too many Tags on Note
       *   </li>
       *   <li> LIMIT_REACHED "Note.resources" - too many resources on Note
       *   </li>
       *   <li> LIMIT_REACHED "Note.size" - total note size too large
       *   </li>
       *   <li> LIMIT_REACHED "Resource.data.size" - resource too large
       *   </li>
       *   <li> LIMIT_REACHED "NoteAttribute.*" - attribute string too long
       *   </li>
       *   <li> LIMIT_REACHED "ResourceAttribute.*" - attribute string too long
       *   </li>
       *   <li> PERMISSION_DENIED "Note.notebookGuid" - user doesn't own destination
       *   <li> PERMISSION_DENIED "Note.tags" - user doesn't have permission to
       *     modify the note's tags. note.tags must be unset.
       *   </li>
       *   <li> PERMISSION_DENIED "Note.attributes" - user doesn't have permission
       *     to modify the note's attributes. note.attributes must be unset.
       *   </li>
       *   <li> QUOTA_REACHED "Accounting.uploadLimit" - note exceeds upload quota
       *   </li>
       *   <li> BAD_DATA_FORMAT "Tag.name" - Note.tagNames was provided, and one
       *     of the specified tags had an invalid length or pattern
       *   </li>
       *   <li> LIMIT_REACHED "Tag" - Note.tagNames was provided, and the required
       *     new tags would exceed the maximum number per account
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - note not found, by GUID
       *   </li>
       *   <li> "Note.notebookGuid" - if notebookGuid provided, but not found
       *   </li>
       * </ul>
       */
    virtual Note updateNote(
        const Note & note,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateNote @endlink */
    virtual QFuture<QVariant> updateNoteAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Moves the note into the trash. The note may still be undeleted, unless it
       * is expunged.  This is equivalent to calling updateNote() after setting
       * Note.active = false
       *
       * @param guid
       *   The GUID of the note to delete.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> PERMISSION_DENIED "Note" - user doesn't have permission to
       *          update the note.
       *   </li>
       * </ul>
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_CONFLICT "Note.guid" - the note is already deleted
       *   </li>
       * </ul>
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual qint32 deleteNote(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link deleteNote @endlink */
    virtual QFuture<QVariant> deleteNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Permanently removes a Note, and all of its Resources,
       * from the service.
       * <p/>
       * NOTE: This function is not available to third party applications.
       * Calls will result in an EDAMUserException with the error code
       * PERMISSION_DENIED.
       *
       * @param guid
       *   The GUID of the note to delete.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> PERMISSION_DENIED "Note" - user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual qint32 expungeNote(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link expungeNote @endlink */
    virtual QFuture<QVariant> expungeNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Performs a deep copy of the Note with the provided GUID 'noteGuid' into
       * the Notebook with the provided GUID 'toNotebookGuid'.
       * The caller must be the owner of both the Note and the Notebook.
       * This creates a new Note in the destination Notebook with new content and
       * Resources that match all of the content and Resources from the original
       * Note, but with new GUID identifiers.
       * The original Note is not modified by this operation.
       * The copied note is considered as an "upload" for the purpose of upload
       * transfer limit calculation, so its size is added to the upload count for
       * the owner.
       *
       * If the original note has been shared and has SharedNote records, the shares
       * are NOT copied.
       *
       * @param noteGuid
       *   The GUID of the Note to copy.
       *
       * @param toNotebookGuid
       *   The GUID of the Notebook that should receive the new Note.
       *
       * @return
       *   The metadata for the new Note that was created.  This will include the
       *   new GUID for this Note (and any copied Resources), but will not include
       *   the content body or the binary bodies of any Resources.
       *
       * @throws EDAMUserException <ul>
       *   <li> LIMIT_REACHED "Note" - at max number per account
       *   </li>
       *   <li> PERMISSION_DENIED "Notebook.guid" - destination not owned by user
       *   </li>
       *   <li> PERMISSION_DENIED "Note" - user doesn't own
       *   </li>
       *   <li> QUOTA_REACHED "Accounting.uploadLimit" - note exceeds upload quota
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Notebook.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual Note copyNote(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link copyNote @endlink */
    virtual QFuture<QVariant> copyNoteAsync(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of the prior versions of a particular note that are
       * saved within the service.  These prior versions are stored to provide a
       * recovery from unintentional removal of content from a note. The identifiers
       * that are returned by this call can be used with getNoteVersion to retrieve
       * the previous note.
       * The identifiers will be listed from the most recent versions to the oldest.
       * This call is only available for notes in Premium accounts. (I.e. access
       * to past versions of Notes is a Premium-only feature.)
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "Note.guid" - if GUID is null or empty string.
       *   </li>
       *   <li> BAD_DATA_FORMAT "Note.guid" - if GUID is not of correct length.
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID.
       *   </li>
       * </ul>
       */
    virtual QList<NoteVersionId> listNoteVersions(
        Guid noteGuid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listNoteVersions @endlink */
    virtual QFuture<QVariant> listNoteVersionsAsync(
        Guid noteGuid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * This can be used to retrieve a previous version of a Note after it has been
       * updated within the service.  The caller must identify the note (via its
       * guid) and the version (via the updateSequenceNumber of that version).
       * to find a listing of the stored version USNs for a note, call
       * listNoteVersions.
       * This call is only available for notes in Premium accounts. (I.e. access
       * to past versions of Notes is a Premium-only feature.)
       *
       * @param noteGuid
       *   The GUID of the note to be retrieved.
       *
       * @param updateSequenceNum
       *   The USN of the version of the note that is being retrieved
       *
       * @param withResourcesData
       *   If true, any Resource elements in this Note will include the binary
       *   contents of their 'data' field's body.
       *
       * @param withResourcesRecognition
       *   If true, any Resource elements will include the binary contents of the
       *   'recognition' field's body if recognition data is present.
       *
       * @param withResourcesAlternateData
       *   If true, any Resource elements in this Note will include the binary
       *   contents of their 'alternateData' fields' body, if an alternate form
       *   is present.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "Note.guid" - if GUID is null or empty string.
       *   </li>
       *   <li> BAD_DATA_FORMAT "Note.guid" - if GUID is not of correct length.
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID.
       *   </li>
       *   <li> "Note.updateSequenceNumber" - the Note doesn't have a version with
       *      the corresponding USN.
       *   </li>
       * </ul>
       */
    virtual Note getNoteVersion(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNoteVersion @endlink */
    virtual QFuture<QVariant> getNoteVersionAsync(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the current state of the resource in the service with the
       * provided GUID.
       * If the Resource is found in a public notebook, the authenticationToken
       * will be ignored (so it could be an empty string).  Only the
       * keys for the applicationData will be returned.
       *
       * @param guid
       *   The GUID of the resource to be retrieved.
       *
       * @param withData
       *   If true, the Resource will include the binary contents of the
       *   'data' field's body.
       *
       * @param withRecognition
       *   If true, the Resource will include the binary contents of the
       *   'recognition' field's body if recognition data is present.
       *
       * @param withAttributes
       *   If true, the Resource will include the attributes
       *
       * @param withAlternateData
       *   If true, the Resource will include the binary contents of the
       *   'alternateData' field's body, if an alternate form is present.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Resource.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Resource" - private resource, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Resource.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual Resource getResource(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResource @endlink */
    virtual QFuture<QVariant> getResourceAsync(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Get all of the application data for the Resource identified by GUID,
       * with values returned within the LazyMap fullMap field.
       * If there are no applicationData entries, then a LazyMap
       * with an empty fullMap will be returned. If your application
       * only needs to fetch its own applicationData entry, use
       * getResourceApplicationDataEntry instead.
       */
    virtual LazyMap getResourceApplicationData(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResourceApplicationData @endlink */
    virtual QFuture<QVariant> getResourceApplicationDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Get the value of a single entry in the applicationData map
       * for the Resource identified by GUID.
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Resource.guid" - Resource not found, by GUID</li>
       *   <li> "ResourceAttributes.applicationData.key" - Resource not found, by key</li>
       * </ul>
       */
    virtual QString getResourceApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResourceApplicationDataEntry @endlink */
    virtual QFuture<QVariant> getResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Update, or create, an entry in the applicationData map for
       * the Resource identified by guid.
       */
    virtual qint32 setResourceApplicationDataEntry(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link setResourceApplicationDataEntry @endlink */
    virtual QFuture<QVariant> setResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Remove an entry identified by 'key' from the applicationData map for
       * the Resource identified by 'guid'.
       */
    virtual qint32 unsetResourceApplicationDataEntry(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link unsetResourceApplicationDataEntry @endlink */
    virtual QFuture<QVariant> unsetResourceApplicationDataEntryAsync(
        Guid guid,
        QString key,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Submit a set of changes to a resource to the service.  This can be used
       * to update the meta-data about the resource, but cannot be used to change
       * the binary contents of the resource (including the length and hash).  These
       * cannot be changed directly without creating a new resource and removing the
       * old one via updateNote.
       *
       * @param resource
       *   A Resource object containing the desired fields to be populated on
       *   the service.  The service will attempt to update the resource with the
       *   following fields from the client:
       *   <ul>
       *      <li>guid:  must be provided to identify the resource
       *      </li>
       *      <li>mime
       *      </li>
       *      <li>width
       *      </li>
       *      <li>height
       *      </li>
       *      <li>duration
       *      </li>
       *      <li>attributes:  optional.  if present, the set of attributes will
       *           be replaced.
       *      </li>
       *   </ul>
       *
       * @return
       *   The Update Sequence Number of the resource after the changes have been
       *   applied.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Resource.guid" - if the parameter is missing
       *   </li>
       *   <li> BAD_DATA_FORMAT "Resource.mime" - invalid resource MIME type
       *   </li>
       *   <li> BAD_DATA_FORMAT "ResourceAttributes.*" - bad resource string
       *   </li>
       *   <li> LIMIT_REACHED "ResourceAttribute.*" - attribute string too long
       *   </li>
       *   <li> PERMISSION_DENIED "Resource" - private resource, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Resource.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual qint32 updateResource(
        const Resource & resource,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateResource @endlink */
    virtual QFuture<QVariant> updateResourceAsync(
        const Resource & resource,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns binary data of the resource with the provided GUID.  For
       * example, if this were an image resource, this would contain the
       * raw bits of the image.
       * If the Resource is found in a public notebook, the authenticationToken
       * will be ignored (so it could be an empty string).
       *
       * @param guid
       *   The GUID of the resource to be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Resource.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Resource" - private resource, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Resource.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual QByteArray getResourceData(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResourceData @endlink */
    virtual QFuture<QVariant> getResourceDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the current state of a resource, referenced by containing
       * note GUID and resource content hash.
       *
       * @param noteGuid
       *   The GUID of the note that holds the resource to be retrieved.
       *
       * @param contentHash
       *   The MD5 checksum of the resource within that note. Note that
       *   this is the binary checksum, for example from Resource.data.bodyHash,
       *   and not the hex-encoded checksum that is used within an en-media
       *   tag in a note body.
       *
       * @param withData
       *   If true, the Resource will include the binary contents of the
       *   'data' field's body.
       *
       * @param withRecognition
       *   If true, the Resource will include the binary contents of the
       *   'recognition' field's body.
       *
       * @param withAlternateData
       *   If true, the Resource will include the binary contents of the
       *   'alternateData' field's body, if an alternate form is present.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "Note.guid" - noteGuid param missing
       *   </li>
       *   <li> DATA_REQUIRED "Note.contentHash" - contentHash param missing
       *   </li>
       *   <li> PERMISSION_DENIED "Resource" - private resource, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note" - not found, by guid
       *   </li>
       *   <li> "Resource" - not found, by hash
       *   </li>
       * </ul>
       */
    virtual Resource getResourceByHash(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResourceByHash @endlink */
    virtual QFuture<QVariant> getResourceByHashAsync(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the binary contents of the recognition index for the resource
       * with the provided GUID.  If the caller asks about a resource that has
       * no recognition data, this will throw EDAMNotFoundException.
       * If the Resource is found in a public notebook, the authenticationToken
       * will be ignored (so it could be an empty string).
       *
       * @param guid
       *   The GUID of the resource whose recognition data should be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Resource.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Resource" - private resource, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Resource.guid" - not found, by GUID
       *   </li>
       *   <li> "Resource.recognition" - resource has no recognition
       *   </li>
       * </ul>
       */
    virtual QByteArray getResourceRecognition(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResourceRecognition @endlink */
    virtual QFuture<QVariant> getResourceRecognitionAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * If the Resource with the provided GUID has an alternate data representation
       * (indicated via the Resource.alternateData field), then this request can
       * be used to retrieve the binary contents of that alternate data file.
       * If the caller asks about a resource that has no alternate data form, this
       * will throw EDAMNotFoundException.
       *
       * @param guid
       *    The GUID of the resource whose recognition data should be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Resource.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Resource" - private resource, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Resource.guid" - not found, by GUID
       *   </li>
       *   <li> "Resource.alternateData" - resource has no recognition
       *   </li>
       * </ul>
       */
    virtual QByteArray getResourceAlternateData(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResourceAlternateData @endlink */
    virtual QFuture<QVariant> getResourceAlternateDataAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns the set of attributes for the Resource with the provided GUID.
       * If the Resource is found in a public notebook, the authenticationToken
       * will be ignored (so it could be an empty string).
       *
       * @param guid
       *   The GUID of the resource whose attributes should be retrieved.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Resource.guid" - if the parameter is missing
       *   </li>
       *   <li> PERMISSION_DENIED "Resource" - private resource, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Resource.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual ResourceAttributes getResourceAttributes(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getResourceAttributes @endlink */
    virtual QFuture<QVariant> getResourceAttributesAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * <p>
       * Looks for a user account with the provided userId on this NoteStore
       * shard and determines whether that account contains a public notebook
       * with the given URI.  If the account is not found, or no public notebook
       * exists with this URI, this will throw an EDAMNotFoundException,
       * otherwise this will return the information for that Notebook.
       * </p>
       * <p>
       * If a notebook is visible on the web with a full URL like
       * http://www.evernote.com/pub/sethdemo/api
       * Then 'sethdemo' is the username that can be used to look up the userId,
       * and 'api' is the publicUri.
       * </p>
       *
       * @param userId
       *    The numeric identifier for the user who owns the public notebook.
       *    To find this value based on a username string, you can invoke
       *    UserStore.getPublicUserInfo
       *
       * @param publicUri
       *    The uri string for the public notebook, from Notebook.publishing.uri.
       *
       * @throws EDAMNotFoundException <ul>
       *   <li>"Publishing.uri" - not found, by URI</li>
       * </ul>
       *
       * @throws EDAMSystemException <ul>
       *   <li> TAKEN_DOWN "PublicNotebook" - The specified public notebook is
       *     taken down (for all requesters).</li>
       *   <li> TAKEN_DOWN "Country" - The specified public notebook is taken
       *     down for the requester because of an IP-based country lookup.</li>
       * </ul>
       */
    virtual Notebook getPublicNotebook(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getPublicNotebook @endlink */
    virtual QFuture<QVariant> getPublicNotebookAsync(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * @Deprecated for first-party clients. See createOrUpdateNotebookShares.
       *
       * Share a notebook with an email address, and optionally to a specific
       * recipient. If an existing SharedNotebook associated with
       * sharedNotebook.notebookGuid is found by recipientUsername or email, then
       * the values of sharedNotebook will be used to update the existing record,
       * else a new record will be created.
       *
       * If recipientUsername is set and there is already a SharedNotebook
       * for that Notebook with that recipientUsername and the privileges on the
       * existing notebook are lower, than on this one, this will update the
       * privileges and sharerUserId. If there isn't an existing SharedNotebook for
       * recipientUsername, this will create and return a shared notebook for that
       * email and recipientUsername. If recipientUsername is not set and there
       * already is a SharedNotebook for a Notebook for that email address and the
       * privileges on the existing SharedNotebook are lower than on this one, this
       * will update the privileges and sharerUserId, and return the updated
       * SharedNotebook. Otherwise, this will create and return a SharedNotebook for
       * the email address.
       *
       * If the authenticationToken is a Business auth token, recipientUsername is
       * set and the recipient is in the same business as the business auth token,
       * this method will also auto-join the business user to the SharedNotebook -
       * that is it will set serviceJoined on the SharedNotebook and create a
       * LinkedNotebook on the recipient's account pointing to the SharedNotebook.
       * The LinkedNotebook creation happens out-of-band, so there will be a delay
       * on the order of half a minute between the SharedNotebook and LinkedNotebook
       * creation.
       *
       * Also handles sending an email to the email addresses: if a SharedNotebook
       * is being created, this will send the shared notebook invite email, and
       * if a SharedNotebook already exists, it will send the shared notebook
       * reminder email. Both these emails contain a link to join the notebook.
       * If the notebook is being auto-joined, it sends an email with that
       * information to the recipient.
       *
       * @param authenticationToken
       *   Must be an authentication token from the owner or a shared notebook
       *   authentication token or business authentication token with sufficient
       *   permissions to change invitations for a notebook.
       *
       * @param sharedNotebook
       *   A shared notebook object populated with the email address of the share
       *   recipient, the notebook guid and the access permissions. All other
       *   attributes of the shared object are ignored. The SharedNotebook.allowPreview
       *   field must be explicitly set with either a true or false value.
       *
       * @param message
       *   The sharer-defined message to put in the email sent out.
       *
       * @return
       *   The fully populated SharedNotebook object including the server assigned
       *   globalId which can both be used to uniquely identify the SharedNotebook.
       *
       * @throws EDAMUserException <ul>
       *   <li>BAD_DATA_FORMAT "SharedNotebook.email" - if the email was not valid</li>
       *   <li>DATA_REQUIRED "SharedNotebook.privilege" - if the
       *       SharedNotebook.privilegeLevel was not set.</li>
       *   <li>BAD_DATA_FORMAT "SharedNotebook.requireLogin" - if requireLogin was
       *       set. requireLogin is deprecated.</li>
       *   <li>BAD_DATA_FORMAT "SharedNotebook.privilegeLevel" - if the
       *       SharedNotebook.privilegeLevel field was unset or set to GROUP.</li>
       *   <li>PERMISSION_DENIED "user" - if the email address on the authenticationToken's
               owner's account is not confirmed.</li>
       *   <li>PERMISSION_DENIED "SharedNotebook.recipientSettings" - if
       *       recipientSettings is set in the sharedNotebook.  Only the recipient
       *       can set these values via the setSharedNotebookRecipientSettings
       *       method.</li>
       *   <li>EDAMErrorCode.LIMIT_REACHED "SharedNotebook" - The notebook already has
       *       EDAM_NOTEBOOK_SHARED_NOTEBOOK_MAX shares.</li>
       *   </ul>
       * @throws EDAMNotFoundException <ul>
       *   <li>Notebook.guid - if the notebookGuid is not a valid GUID for the user.
       *   </li>
       *   </ul>
       */
    virtual SharedNotebook shareNotebook(
        const SharedNotebook & sharedNotebook,
        QString message,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link shareNotebook @endlink */
    virtual QFuture<QVariant> shareNotebookAsync(
        const SharedNotebook & sharedNotebook,
        QString message,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Share a notebook by a messaging thread ID or a list of contacts. This function is
       * intended to be used in conjunction with Evernote messaging, and as such does not
       * notify the recipient that a notebook has been shared with them.
       *
       * Sharing with a subset of participants on a thread is accomplished by specifying both
       * a thread ID and a list of contacts. This ensures that even if those contacts are
       * on the thread under a deactivated identity, the correct user (the one who has the
       * given contact on the thread) receives the share.
       *
       * @param authenticationToken
       *   An authentication token that grants the caller permission to share the notebook.
       *   This should be an owner token if the notebook is owned by the caller.
       *   If the notebook is a business notebook to which the caller has full access,
       *   this should be their business authentication token. If the notebook is a shared
       *   (non-business) notebook to which the caller has full access, this should be the
       *   shared notebook authentication token returned by NoteStore.authenticateToNotebook.
       *
       * @param shareTemplate
       *   Specifies the GUID of the notebook to be shared, the privilege at which the notebook
       *   should be shared, and the recipient information.
       *
       * @return
       *   A structure containing the USN of the Notebook after the change and a list of created
       *   or updated SharedNotebooks.
       *
       * @throws EDAMUserException <ul>
       *   <li>DATA_REQUIRED "Notebook.guid" - if no notebook GUID was specified</li>
       *   <li>BAD_DATA_FORMAT "Notebook.guid" - if shareTemplate.notebookGuid is not a
       *     valid GUID</li>
       *   <li>DATA_REQUIRED "shareTemplate" - if the shareTemplate parameter was missing</li>
       *   <li>DATA_REQUIRED "NotebookShareTemplate.privilege" - if no privilege was
       *     specified</li>
       *   <li>DATA_CONFLICT "NotebookShareTemplate.privilege" - if the specified privilege
       *     is not allowed.</li>
       *   <li>DATA_REQUIRED "NotebookShareTemplate.recipients" - if no recipients were
       *     specified, either by thread ID or as a list of contacts</li>
       *   <li>LIMIT_REACHED "SharedNotebook" - if the notebook has reached its maximum
       *     number of shares</li>
       * </ul>
       *
       * @throws EDAMInvalidContactsException <ul>
       *   <li>"NotebookShareTemplate.recipients" - if one or more of the recipients specified
       *     in shareTemplate.recipients was not syntactically valid, or if attempting to
       *     share a notebook with an Evernote identity that the sharer does not have a
       *     connection to. The exception will specify which recipients were invalid.</li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li>"Notebook.guid" - if no notebook with the specified GUID was found</li>
       *   <li>"NotebookShareTemplate.recipientThreadId" - if the recipient thread ID was
       *     specified, but no thread with that ID exists</li>
       * </ul>
       */
    virtual CreateOrUpdateNotebookSharesResult createOrUpdateNotebookShares(
        const NotebookShareTemplate & shareTemplate,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link createOrUpdateNotebookShares @endlink */
    virtual QFuture<QVariant> createOrUpdateNotebookSharesAsync(
        const NotebookShareTemplate & shareTemplate,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * @Deprecated See createOrUpdateNotebookShares and manageNotebookShares.
       */
    virtual qint32 updateSharedNotebook(
        const SharedNotebook & sharedNotebook,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateSharedNotebook @endlink */
    virtual QFuture<QVariant> updateSharedNotebookAsync(
        const SharedNotebook & sharedNotebook,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Set values for the recipient settings associated with a notebook share. Only the
       * recipient of the share can update their recipient settings.
       *
       * If you do <i>not</i> wish to, or cannot, change one of the recipient settings fields,
       * you must leave that field unset in recipientSettings.
       * This method will skip that field for updates and attempt to leave the existing value as
       * it is.
       *
       * If recipientSettings.inMyList is false, both reminderNotifyInApp and reminderNotifyEmail
       * will be either left as null or converted to false (if currently true).
       *
       * To unset a notebook's stack, pass in the empty string for the stack field.
       *
       * @param authenticationToken The owner authentication token for the recipient of the share.
       *
       * @return The updated Notebook with the new recipient settings. Note that some of the
       * recipient settings may differ from what was requested. Clients should update their state
       * based on this return value.
       *
       * @throws EDAMNotFoundException <ul>
       *   <li>Notebook.guid - Thrown if the service does not have a notebook record with the
       *       notebookGuid on the given shard.</li>
       *   <li>Publishing.publishState - Thrown if the business notebook is not shared with the
       *       user and is also not published to their business.</li>
       * </ul>
       *
       * @throws EDAMUserException <ul>
       *   <li>PEMISSION_DENIED "authenticationToken" - If the owner of the given token is not
       *       allowed to set recipient settings on the specified notebook.</li>
       *   <li>DATA_CONFLICT "recipientSettings.reminderNotifyEmail" - Setting reminderNotifyEmail
       *       is allowed only for notebooks which belong to the same business as the user.</li>
       *   <li>DATA_CONFLICT "recipientSettings.inMyList" - If the request is setting inMyList
       *       to false and any of reminder* settings to true.</li>
       * </ul>
       */
    virtual Notebook setNotebookRecipientSettings(
        QString notebookGuid,
        const NotebookRecipientSettings & recipientSettings,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link setNotebookRecipientSettings @endlink */
    virtual QFuture<QVariant> setNotebookRecipientSettingsAsync(
        QString notebookGuid,
        const NotebookRecipientSettings & recipientSettings,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Lists the collection of shared notebooks for all notebooks in the
       * users account.
       *
       * @return
       *  The list of all SharedNotebooks for the user
       */
    virtual QList<SharedNotebook> listSharedNotebooks(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listSharedNotebooks @endlink */
    virtual QFuture<QVariant> listSharedNotebooksAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the service to make a linked notebook with the provided name, username
       * of the owner and identifiers provided. A linked notebook can be either a
       * link to a public notebook or to a private shared notebook.
       *
       * @param linkedNotebook
       *   The desired fields for the linked notebook must be provided on this
       *   object.  The name of the linked notebook must be set. Either a username
       *   uri or a shard id and share key must be provided otherwise a
       *   EDAMUserException is thrown.
       *
       * @return
       *   The newly created LinkedNotebook.  The server-side id will be
       *   saved in this object's 'id' field.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "LinkedNotebook.shareName" - missing shareName
       *   <li> BAD_DATA_FORMAT "LinkedNotebook.name" - invalid shareName length or pattern
       *   </li>
       *   <li> BAD_DATA_FORMAT "LinkedNotebook.username" - bad username format
       *   </li>
       *   <li> BAD_DATA_FORMAT "LinkedNotebook.uri" -
       *     if public notebook set but bad uri
       *   </li>
       *   <li> DATA_REQUIRED "LinkedNotebook.shardId" -
       *     if private notebook but shard id not provided
       *   </li>
       *   <li> BAD_DATA_FORMAT "LinkedNotebook.stack" - invalid stack name length or pattern
       *   </li>
       * </ul>
       *
       * @throws EDAMSystemException <ul>
       *   <li> BAD_DATA_FORMAT "LinkedNotebook.sharedNotebookGlobalId" -
       *     if a bad global identifer was set on a private notebook
       *   </li>
       * </ul>
       */
    virtual LinkedNotebook createLinkedNotebook(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link createLinkedNotebook @endlink */
    virtual QFuture<QVariant> createLinkedNotebookAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * @param linkedNotebook
       *   Updates the name of a linked notebook.
       *
       * @return
       *   The Update Sequence Number for this change within the account.
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "LinkedNotebook.shareName" - missing shareName
       *   </li>
       *   <li> BAD_DATA_FORMAT "LinkedNotebook.shareName" - invalid shareName length or pattern
       *   </li>
       *   <li> BAD_DATA_FORMAT "LinkedNotebook.stack" - invalid stack name length or pattern
       *   </li>
       * </ul>
       */
    virtual qint32 updateLinkedNotebook(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateLinkedNotebook @endlink */
    virtual QFuture<QVariant> updateLinkedNotebookAsync(
        const LinkedNotebook & linkedNotebook,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Returns a list of linked notebooks
       */
    virtual QList<LinkedNotebook> listLinkedNotebooks(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link listLinkedNotebooks @endlink */
    virtual QFuture<QVariant> listLinkedNotebooksAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Permanently expunges the linked notebook from the account.
       * <p/>
       * NOTE: This function is generally not available to third party applications.
       * Calls will result in an EDAMUserException with the error code
       * PERMISSION_DENIED.
       *
       * @param guid
       *   The LinkedNotebook.guid field of the LinkedNotebook to permanently remove
       *   from the account.
       */
    virtual qint32 expungeLinkedNotebook(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link expungeLinkedNotebook @endlink */
    virtual QFuture<QVariant> expungeLinkedNotebookAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the service to produce an authentication token that can be used to
       * access the contents of a shared notebook from someone else's account.
       * This authenticationToken can be used with the various other NoteStore
       * calls to find and retrieve notes, and if the permissions in the shared
       * notebook are sufficient, to make changes to the contents of the notebook.
       *
       * @param shareKeyOrGlobalId
       *   May be one of the following:
       *   <ul>
       *     <li>A share key for a shared notebook that was granted to some recipient
       *         Must be used if you are joining a notebook unless it was shared via
       *         createOrUpdateNotebookShares. Share keys are delivered out-of-band
       *         and are generally not available to clients. For security reasons,
       *         share keys may be invalidated at the discretion of the service.
       *     </li>
       *     <li>The shared notebook global identifier. May be used to access a
       *         notebook that is already joined.
       *     </li>
       *     <li>The Notebook GUID. May be used to access a notebook that was already
       *         joined, or to access a notebook that was shared with the recipient
       *         via createOrUpdateNotebookShares.
       *     </li>
       *   </ul>
       *
       * @param authenticationToken
       *   If a non-empty string is provided, this is the full user-based
       *   authentication token that identifies the user who is currently logged in
       *   and trying to access the shared notebook.
       *   If this string is empty, the service will attempt to authenticate to the
       *   shared notebook without any logged in user.
       *
       * @throws EDAMSystemException <ul>
       *   <li> BAD_DATA_FORMAT "shareKey" - invalid shareKey string</li>
       *   <li> INVALID_AUTH "shareKey" - bad signature on shareKey string</li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "SharedNotebook.id" - the shared notebook no longer exists</li>
       * </ul>
       *
       * @throws EDAMUserException <ul>
       *   <li> DATA_REQUIRED "authenticationToken" - the share requires login, and
       *          no valid authentication token was provided.
       *   </li>
       *   <li> PERMISSION_DENIED "SharedNotebook.username" - share requires login,
       *          and another username has already been bound to this notebook.
       *   </li>
       * </ul>
       */
    virtual AuthenticationResult authenticateToSharedNotebook(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link authenticateToSharedNotebook @endlink */
    virtual QFuture<QVariant> authenticateToSharedNotebookAsync(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * This function is used to retrieve extended information about a shared
       * notebook by a guest who has already authenticated to access that notebook.
       * This requires an 'authenticationToken' parameter which should be the
       * resut of a call to authenticateToSharedNotebook(...).
       * I.e. this is the token that gives access to the particular shared notebook
       * in someone else's account -- it's not the authenticationToken for the
       * owner of the notebook itself.
       *
       * @param authenticationToken
       *   Should be the authentication token retrieved from the reply of
       *   authenticateToSharedNotebook(), proving access to a particular shared
       *   notebook.
       *
       * @throws EDAMUserException <ul>
       *   <li> PERMISSION_DENIED "authenticationToken" -
       *          authentication token doesn't correspond to a valid shared notebook
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "SharedNotebook.id" - the shared notebook no longer exists
       *   </li>
       * </ul>
       */
    virtual SharedNotebook getSharedNotebookByAuth(
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getSharedNotebookByAuth @endlink */
    virtual QFuture<QVariant> getSharedNotebookByAuthAsync(
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Attempts to send a single note to one or more email recipients.
       * <p/>
       * NOTE: This function is generally not available to third party applications.
       * Calls will result in an EDAMUserException with the error code
       * PERMISSION_DENIED.
       *
       * @param authenticationToken
       *    The note will be sent as the user logged in via this token, using that
       *    user's registered email address.  If the authenticated user doesn't
       *    have permission to read that note, the emailing will fail.
       *
       * @param parameters
       *    The note must be specified either by GUID (in which case it will be
       *    sent using the existing data in the service), or else the full Note
       *    must be passed to this call.  This also specifies the additional
       *    email fields that will be used in the email.
       *
       * @throws EDAMUserException <ul>
       *   <li> LIMIT_REACHED "NoteEmailParameters.toAddresses" -
       *     The email can't be sent because this would exceed the user's daily
       *     email limit.
       *   </li>
       *   <li> BAD_DATA_FORMAT "(email address)" -
       *     email address malformed
       *   </li>
       *   <li> DATA_REQUIRED "NoteEmailParameters.toAddresses" -
       *     if there are no To: or Cc: addresses provided.
       *   </li>
       *   <li> DATA_REQUIRED "Note.title" -
       *     if the caller provides a Note parameter with no title
       *   </li>
       *   <li> DATA_REQUIRED "Note.content" -
       *     if the caller provides a Note parameter with no content
       *   </li>
       *   <li> ENML_VALIDATION "*" - note content doesn't validate against DTD
       *   </li>
       *   <li> DATA_REQUIRED "NoteEmailParameters.note" -
       *     if no guid or note provided
       *   </li>
       *   <li> PERMISSION_DENIED "Note" - private note, user doesn't own
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID
       *   </li>
       * </ul>
       */
    virtual void emailNote(
        const NoteEmailParameters & parameters,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link emailNote @endlink */
    virtual QFuture<QVariant> emailNoteAsync(
        const NoteEmailParameters & parameters,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * If this note is not already shared publicly (via its own direct URL), then this
       * will start sharing that note.
       * This will return the secret "Note Key" for this note that
       * can currently be used in conjunction with the Note's GUID to gain direct
       * read-only access to the Note.
       * If the note is already shared, then this won't make any changes to the
       * note, and the existing "Note Key" will be returned.  The only way to change
       * the Note Key for an existing note is to stopSharingNote first, and then
       * call this function.
       *
       * @param guid
       *   The GUID of the note to be shared.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Note.guid" - if the parameter is missing</li>
       *   <li> PERMISSION_DENIED "Note" - private note, user doesn't own</li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "Note.guid" - not found, by GUID</li>
       * </ul>
       */
    virtual QString shareNote(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link shareNote @endlink */
    virtual QFuture<QVariant> shareNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * If this note is shared publicly then this will stop sharing that note
       * and invalidate its "Note Key", so any existing URLs to access that Note
       * will stop working.
       *
       * If the Note is not shared, then this function will do nothing.
       *
       * This function does not remove individual shares for the note. To remove
       * individual shares, see stopSharingNoteWithRecipients.
       *
       * @param guid
       *   The GUID of the note to be un-shared.
       *
       * @throws EDAMUserException <ul>
       *   <li> BAD_DATA_FORMAT "Note.guid" - if the parameter is missing</li>
       *   <li> PERMISSION_DENIED "Note" - private note, user doesn't own</li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li>"Note.guid" - not found, by GUID</li>
       * </ul>
       */
    virtual void stopSharingNote(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link stopSharingNote @endlink */
    virtual QFuture<QVariant> stopSharingNoteAsync(
        Guid guid,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Asks the service to produce an authentication token that can be used to
       * access the contents of a single Note which was individually shared
       * from someone's account.
       * This authenticationToken can be used with the various other NoteStore
       * calls to find and retrieve the Note and its directly-referenced children.
       *
       * @param guid
       *   The GUID identifying this Note on this shard.
       *
       * @param noteKey
       *   The 'noteKey' identifier from the Note that was originally created via
       *   a call to shareNote() and then given to a recipient to access.
       *
       * @param authenticationToken
       *   An optional authenticationToken that identifies the user accessing the
       *   shared note. This parameter may be required to access some shared notes.
       *
       * @throws EDAMUserException <ul>
       *   <li> PERMISSION_DENIED "Note" - the Note with that GUID is either not
       *     shared, or the noteKey doesn't match the current key for this note
       *   </li>
       *   <li> PERMISSION_DENIED "authenticationToken" - an authentication token is
       *     required to access this Note, but either no authentication token or a
       *     "non-owner" authentication token was provided.
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li> "guid" - the note with that GUID is not found
       *   </li>
       * </ul>
       *
       * @throws EDAMSystemException <ul>
       *   <li> TAKEN_DOWN "Note" - The specified shared note is taken down (for
       *     all requesters).
       *   </li>
       *   <li> TAKEN_DOWN "Country" - The specified shared note is taken down
       *     for the requester because of an IP-based country lookup.
       *   </ul>
       * </ul>
       */
    virtual AuthenticationResult authenticateToSharedNote(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link authenticateToSharedNote @endlink */
    virtual QFuture<QVariant> authenticateToSharedNoteAsync(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Identify related entities on the service, such as notes,
       * notebooks, tags and users in a business related to notes or content.
       *
       * @param query
       *   The information about which we are finding related entities.
       *
       * @param resultSpec
       *   Allows the client to indicate the type and quantity of
       *   information to be returned, allowing a saving of time and
       *   bandwidth.
       *
       * @return
       *   The result of the query, with information considered
       *   to likely be relevantly related to the information
       *   described by the query.
       *
       * @throws EDAMUserException <ul>
       *   <li>BAD_DATA_FORMAT "RelatedQuery.plainText" - If you provided a
       *     a zero-length plain text value.
       *   </li>
       *   <li>BAD_DATA_FORMAT "RelatedQuery.noteGuid" - If you provided an
       *     invalid Note GUID, that is, one that does not match the constraints
       *     defined by EDAM_GUID_LEN_MIN, EDAM_GUID_LEN_MAX, EDAM_GUID_REGEX.
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.notebookGuid" - if malformed
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.tagGuids" - if any are malformed
       *   </li>
       *   <li> BAD_DATA_FORMAT "NoteFilter.words" - if search string too long
       *   </li>
       *   <li>PERMISSION_DENIED "Note" - If the caller does not have access to
       *     the note identified by RelatedQuery.noteGuid.
       *   </li>
       *   <li>PERMISSION_DENIED "authenticationToken" - If the caller has requested to
       *     findExperts in the context of a non business user (i.e. The authenticationToken
       *     is not a business auth token).
       *   </li>
       *   <li>DATA_REQUIRED "RelatedResultSpec" - If you did not not set any values
       *     in the result spec.
       *   </li>
       * </ul>
       *
       * @throws EDAMNotFoundException <ul>
       *   <li>"RelatedQuery.noteGuid" - the note with that GUID is not
       *     found, if that field has been set in the query.
       *   </li>
       * </ul>
       */
    virtual RelatedResult findRelated(
        const RelatedQuery & query,
        const RelatedResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link findRelated @endlink */
    virtual QFuture<QVariant> findRelatedAsync(
        const RelatedQuery & query,
        const RelatedResultSpec & resultSpec,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Perform the same operation as updateNote() would provided that the update
       * sequence number on the parameter Note object matches the current update sequence
       * number that the service has for the note.  If they do <i>not</i> match, then
       * <i>no</i> update is performed and the return value will have the current server
       * state in the note field and updated will be false.  If the update sequence
       * numbers between the client and server do match, then the note will be updated
       * and the note field of the return value will be returned as it would be for the
       * updateNote method.  This method allows you to check for an update to the note
       * on the service, by another client instance, from when you obtained the
       * note state as a baseline for your edits and the time when you wish to save your
       * edits.  If your client can merge the conflict, you can avoid overwriting changes
       * that were saved to the service by the other client.
       *
       * See the updateNote method for information on the exceptions and parameters for
       * this method.  The only difference is that you must have an update sequence number
       * defined on the note parameter (equal to the USN of the note as synched to the
       * client), and the following additional exceptions might be thrown.
       *
       * @throws EDAMUserException <ul>
       *   <li>DATA_REQUIRED "Note.updateSequenceNum" - If the update sequence number was
       *       not provided.  This includes a value that is set as 0.</li>
       *   <li>BAD_DATA_FORMAT "Note.updateSequenceNum" - If the note has an update
       *       sequence number that is larger than the current server value, which should
       *       not happen if your client is working correctly.</li>
       * </ul>
       */
    virtual UpdateNoteIfUsnMatchesResult updateNoteIfUsnMatches(
        const Note & note,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link updateNoteIfUsnMatches @endlink */
    virtual QFuture<QVariant> updateNoteIfUsnMatchesAsync(
        const Note & note,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Manage invitations and memberships associated with a given notebook.
       *
       * <i>Note:</i> Beta method! This method is currently intended for
       * limited use by Evernote clients that have discussed using this
       * routine with the platform team.
       *
       * @param parameters A structure containing all parameters for the updates.
       *    See the structure documentation for details.
       *
       * @throws EDAMUserException <ul>
       *   <li>EDAMErrorCode.LIMIT_REACHED "SharedNotebook" - Trying to share a
       *    notebook while the notebook already has EDAM_NOTEBOOK_SHARED_NOTEBOOK_MAX
       *    shares.</li>
       * </ul>
       */
    virtual ManageNotebookSharesResult manageNotebookShares(
        const ManageNotebookSharesParameters & parameters,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link manageNotebookShares @endlink */
    virtual QFuture<QVariant> manageNotebookSharesAsync(
        const ManageNotebookSharesParameters & parameters,
        IRequestContextPtr ctx = {}) = 0;

    /**
       * Return the share relationships for the given notebook, including
       * both the invitations and the memberships.
       *
       * <i>Note:</i> Beta method! This method is currently intended for
       * limited use by Evernote clients that have discussed using this
       * routine with the platform team.
       */
    virtual ShareRelationships getNotebookShares(
        QString notebookGuid,
        IRequestContextPtr ctx = {}) = 0;

    /** Asynchronous version of @link getNotebookShares @endlink */
    virtual QFuture<QVariant> getNotebookSharesAsync(
        QString notebookGuid,
        IRequestContextPtr ctx = {}) = 0;

};

////////////////////////////////////////////////////////////////////////////////

QEVERCLOUD_EXPORT INoteStore * newNoteStore(
    QString noteStoreUrl = {},
    std::optional<Guid> linkedNotebookGuid = {},
    IRequestContextPtr ctx = {},
    QObject * parent = nullptr,
    IRetryPolicyPtr retryPolicy = {});

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_INOTESTORE
