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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONS
#define QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONS

#include <qevercloud/Export.h>

#include "CanMoveToContainerRestrictions.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure captures information about the types of operations
 * that cannot be performed on a given notebook with a type of
 * authenticated access and credentials.  The values filled into this
 * structure are based on then-current values in the server database
 * for shared notebooks and notebook publishing records, as well as
 * information related to the authentication token.  Information from
 * the authentication token includes the application that is accessing
 * the server, as defined by the permissions granted by consumer (api)
 * key, and the method used to obtain the token, for example via
 * authenticateToSharedNotebook, authenticateToBusiness, etc.  Note
 * that changes to values in this structure that are the result of
 * shared notebook or publishing record changes are communicated to
 * the client via a change in the notebook USN during sync.  It is
 * important to use the same access method, parameters, and consumer
 * key in order obtain correct results from the sync engine.
 *
 * The server has the final say on what is allowed as values may
 * change between calls to obtain NotebookRestrictions instances
 * and to operate on data on the service.
 *
 * If the following are set and true, then the given restriction is
 * in effect, as accessed by the same authentication token from which
 * the values were obtained.
 *
 * */
class QEVERCLOUD_EXPORT NotebookRestrictions: public Printable
{
    Q_GADGET
public:
    NotebookRestrictions();
    NotebookRestrictions(const NotebookRestrictions & other);
    NotebookRestrictions(NotebookRestrictions && other) noexcept;
    ~NotebookRestrictions() noexcept override;

    NotebookRestrictions & operator=(const NotebookRestrictions & other);
    NotebookRestrictions & operator=(NotebookRestrictions && other) noexcept;

    /**
     * The client is not able to read notes from the service and
     * the notebook is write-only.
     */
    [[nodiscard]] const std::optional<bool> & noReadNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoReadNotes();
    void setNoReadNotes(std::optional<bool> noReadNotes);

    /**
     * The client may not create new notes in the notebook.
     */
    [[nodiscard]] const std::optional<bool> & noCreateNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoCreateNotes();
    void setNoCreateNotes(std::optional<bool> noCreateNotes);

    /**
     * The client may not update notes currently in the notebook.
     */
    [[nodiscard]] const std::optional<bool> & noUpdateNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoUpdateNotes();
    void setNoUpdateNotes(std::optional<bool> noUpdateNotes);

    /**
     * The client may not expunge notes currently in the notebook.
     */
    [[nodiscard]] const std::optional<bool> & noExpungeNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoExpungeNotes();
    void setNoExpungeNotes(std::optional<bool> noExpungeNotes);

    /**
     * The client may not share notes in the notebook via the
     * shareNote or createOrUpdateSharedNotes methods.
     */
    [[nodiscard]] const std::optional<bool> & noShareNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoShareNotes();
    void setNoShareNotes(std::optional<bool> noShareNotes);

    /**
     * The client may not e-mail notes by guid via the Evernote
     * service by using the emailNote method. Email notes by value
     * by populating the note parameter instead.
     */
    [[nodiscard]] const std::optional<bool> & noEmailNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoEmailNotes();
    void setNoEmailNotes(std::optional<bool> noEmailNotes);

    /**
     * The client may not send messages to the share recipients of
     * the notebook.
     */
    [[nodiscard]] const std::optional<bool> & noSendMessageToRecipients() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSendMessageToRecipients();
    void setNoSendMessageToRecipients(std::optional<bool> noSendMessageToRecipients);

    /**
     * The client may not update the Notebook object itself, for
     * example, via the updateNotebook method.
     */
    [[nodiscard]] const std::optional<bool> & noUpdateNotebook() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoUpdateNotebook();
    void setNoUpdateNotebook(std::optional<bool> noUpdateNotebook);

    /**
     * The client may not expunge the Notebook object itself, for
     * example, via the expungeNotebook method.
     */
    [[nodiscard]] const std::optional<bool> & noExpungeNotebook() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoExpungeNotebook();
    void setNoExpungeNotebook(std::optional<bool> noExpungeNotebook);

    /**
     * The client may not set this notebook to be the default notebook.
     * The caller should leave Notebook.defaultNotebook unset.
     */
    [[nodiscard]] const std::optional<bool> & noSetDefaultNotebook() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetDefaultNotebook();
    void setNoSetDefaultNotebook(std::optional<bool> noSetDefaultNotebook);

    /**
     * If the client is able to update the Notebook, the Notebook.stack
     * value may not be set.
     */
    [[nodiscard]] const std::optional<bool> & noSetNotebookStack() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetNotebookStack();
    void setNoSetNotebookStack(std::optional<bool> noSetNotebookStack);

    /**
     * The client may not publish the notebook to the public.
     * For example, business notebooks may not be shared publicly.
     */
    [[nodiscard]] const std::optional<bool> & noPublishToPublic() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoPublishToPublic();
    void setNoPublishToPublic(std::optional<bool> noPublishToPublic);

    /**
     * The client may not publish the notebook to the business library.
     */
    [[nodiscard]] const std::optional<bool> & noPublishToBusinessLibrary() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoPublishToBusinessLibrary();
    void setNoPublishToBusinessLibrary(std::optional<bool> noPublishToBusinessLibrary);

    /**
     * The client may not complete an operation that results in a new tag
     * being created in the owner's account.
     */
    [[nodiscard]] const std::optional<bool> & noCreateTags() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoCreateTags();
    void setNoCreateTags(std::optional<bool> noCreateTags);

    /**
     * The client may not update tags in the owner's account.
     */
    [[nodiscard]] const std::optional<bool> & noUpdateTags() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoUpdateTags();
    void setNoUpdateTags(std::optional<bool> noUpdateTags);

    /**
     * The client may not expunge tags in the owner's account.
     */
    [[nodiscard]] const std::optional<bool> & noExpungeTags() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoExpungeTags();
    void setNoExpungeTags(std::optional<bool> noExpungeTags);

    /**
     * If the client is able to create or update tags in the owner's account,
     * then they will not be able to set the parent tag. Leave the value unset.
     */
    [[nodiscard]] const std::optional<bool> & noSetParentTag() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetParentTag();
    void setNoSetParentTag(std::optional<bool> noSetParentTag);

    /**
     * The client is unable to create shared notebooks for the notebook.
     */
    [[nodiscard]] const std::optional<bool> & noCreateSharedNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoCreateSharedNotebooks();
    void setNoCreateSharedNotebooks(std::optional<bool> noCreateSharedNotebooks);

    /**
     * Restrictions on which shared notebook instances can be updated. If the
     * value is not set or null, then the client can update any of the shared notebooks
     * associated with the notebook on which the NotebookRestrictions are defined.
     * See the enumeration for further details.
     */
    [[nodiscard]] const std::optional<SharedNotebookInstanceRestrictions> & updateWhichSharedNotebookRestrictions() const noexcept;
    [[nodiscard]] std::optional<SharedNotebookInstanceRestrictions> & mutableUpdateWhichSharedNotebookRestrictions();
    void setUpdateWhichSharedNotebookRestrictions(std::optional<SharedNotebookInstanceRestrictions> updateWhichSharedNotebookRestrictions);

    /**
     * Restrictions on which shared notebook instances can be expunged. If the
     * value is not set or null, then the client can expunge any of the shared notebooks
     * associated with the notebook on which the NotebookRestrictions are defined.
     * See the enumeration for further details.
     */
    [[nodiscard]] const std::optional<SharedNotebookInstanceRestrictions> & expungeWhichSharedNotebookRestrictions() const noexcept;
    [[nodiscard]] std::optional<SharedNotebookInstanceRestrictions> & mutableExpungeWhichSharedNotebookRestrictions();
    void setExpungeWhichSharedNotebookRestrictions(std::optional<SharedNotebookInstanceRestrictions> expungeWhichSharedNotebookRestrictions);

    /**
     * The client may not share notes in the notebook via the shareNoteWithBusiness
     * method.
     */
    [[nodiscard]] const std::optional<bool> & noShareNotesWithBusiness() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoShareNotesWithBusiness();
    void setNoShareNotesWithBusiness(std::optional<bool> noShareNotesWithBusiness);

    /**
     * The client may not rename this notebook.
     */
    [[nodiscard]] const std::optional<bool> & noRenameNotebook() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoRenameNotebook();
    void setNoRenameNotebook(std::optional<bool> noRenameNotebook);

    /**
     * clients may not change the NotebookRecipientSettings.inMyList settings for
     * this notebook.
     */
    [[nodiscard]] const std::optional<bool> & noSetInMyList() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetInMyList();
    void setNoSetInMyList(std::optional<bool> noSetInMyList);

    [[nodiscard]] const std::optional<bool> & noChangeContact() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoChangeContact();
    void setNoChangeContact(std::optional<bool> noChangeContact);

    /**
     * Specifies if the client can move this notebook to a container and if not,
     * the reason why.
     */
    [[nodiscard]] const std::optional<CanMoveToContainerRestrictions> & canMoveToContainerRestrictions() const noexcept;
    [[nodiscard]] std::optional<CanMoveToContainerRestrictions> & mutableCanMoveToContainerRestrictions();
    void setCanMoveToContainerRestrictions(std::optional<CanMoveToContainerRestrictions> canMoveToContainerRestrictions);

    [[nodiscard]] const std::optional<bool> & noSetReminderNotifyEmail() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetReminderNotifyEmail();
    void setNoSetReminderNotifyEmail(std::optional<bool> noSetReminderNotifyEmail);

    [[nodiscard]] const std::optional<bool> & noSetReminderNotifyInApp() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetReminderNotifyInApp();
    void setNoSetReminderNotifyInApp(std::optional<bool> noSetReminderNotifyInApp);

    [[nodiscard]] const std::optional<bool> & noSetRecipientSettingsStack() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetRecipientSettingsStack();
    void setNoSetRecipientSettingsStack(std::optional<bool> noSetRecipientSettingsStack);

    /**
     * If set, the client cannot move a Note into or out of the Notebook.
     */
    [[nodiscard]] const std::optional<bool> & noCanMoveNote() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoCanMoveNote();
    void setNoCanMoveNote(std::optional<bool> noCanMoveNote);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const NotebookRestrictions & notebookRestrictions);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const NotebookRestrictions & notebookRestrictions);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const NotebookRestrictions & notebookRestrictions);

    Q_PROPERTY(std::optional<bool> noReadNotes READ noReadNotes WRITE setNoReadNotes)
    Q_PROPERTY(std::optional<bool> noCreateNotes READ noCreateNotes WRITE setNoCreateNotes)
    Q_PROPERTY(std::optional<bool> noUpdateNotes READ noUpdateNotes WRITE setNoUpdateNotes)
    Q_PROPERTY(std::optional<bool> noExpungeNotes READ noExpungeNotes WRITE setNoExpungeNotes)
    Q_PROPERTY(std::optional<bool> noShareNotes READ noShareNotes WRITE setNoShareNotes)
    Q_PROPERTY(std::optional<bool> noEmailNotes READ noEmailNotes WRITE setNoEmailNotes)
    Q_PROPERTY(std::optional<bool> noSendMessageToRecipients READ noSendMessageToRecipients WRITE setNoSendMessageToRecipients)
    Q_PROPERTY(std::optional<bool> noUpdateNotebook READ noUpdateNotebook WRITE setNoUpdateNotebook)
    Q_PROPERTY(std::optional<bool> noExpungeNotebook READ noExpungeNotebook WRITE setNoExpungeNotebook)
    Q_PROPERTY(std::optional<bool> noSetDefaultNotebook READ noSetDefaultNotebook WRITE setNoSetDefaultNotebook)
    Q_PROPERTY(std::optional<bool> noSetNotebookStack READ noSetNotebookStack WRITE setNoSetNotebookStack)
    Q_PROPERTY(std::optional<bool> noPublishToPublic READ noPublishToPublic WRITE setNoPublishToPublic)
    Q_PROPERTY(std::optional<bool> noPublishToBusinessLibrary READ noPublishToBusinessLibrary WRITE setNoPublishToBusinessLibrary)
    Q_PROPERTY(std::optional<bool> noCreateTags READ noCreateTags WRITE setNoCreateTags)
    Q_PROPERTY(std::optional<bool> noUpdateTags READ noUpdateTags WRITE setNoUpdateTags)
    Q_PROPERTY(std::optional<bool> noExpungeTags READ noExpungeTags WRITE setNoExpungeTags)
    Q_PROPERTY(std::optional<bool> noSetParentTag READ noSetParentTag WRITE setNoSetParentTag)
    Q_PROPERTY(std::optional<bool> noCreateSharedNotebooks READ noCreateSharedNotebooks WRITE setNoCreateSharedNotebooks)
    Q_PROPERTY(std::optional<SharedNotebookInstanceRestrictions> updateWhichSharedNotebookRestrictions READ updateWhichSharedNotebookRestrictions WRITE setUpdateWhichSharedNotebookRestrictions)
    Q_PROPERTY(std::optional<SharedNotebookInstanceRestrictions> expungeWhichSharedNotebookRestrictions READ expungeWhichSharedNotebookRestrictions WRITE setExpungeWhichSharedNotebookRestrictions)
    Q_PROPERTY(std::optional<bool> noShareNotesWithBusiness READ noShareNotesWithBusiness WRITE setNoShareNotesWithBusiness)
    Q_PROPERTY(std::optional<bool> noRenameNotebook READ noRenameNotebook WRITE setNoRenameNotebook)
    Q_PROPERTY(std::optional<bool> noSetInMyList READ noSetInMyList WRITE setNoSetInMyList)
    Q_PROPERTY(std::optional<bool> noChangeContact READ noChangeContact WRITE setNoChangeContact)
    Q_PROPERTY(std::optional<CanMoveToContainerRestrictions> canMoveToContainerRestrictions READ canMoveToContainerRestrictions WRITE setCanMoveToContainerRestrictions)
    Q_PROPERTY(std::optional<bool> noSetReminderNotifyEmail READ noSetReminderNotifyEmail WRITE setNoSetReminderNotifyEmail)
    Q_PROPERTY(std::optional<bool> noSetReminderNotifyInApp READ noSetReminderNotifyInApp WRITE setNoSetReminderNotifyInApp)
    Q_PROPERTY(std::optional<bool> noSetRecipientSettingsStack READ noSetRecipientSettingsStack WRITE setNoSetRecipientSettingsStack)
    Q_PROPERTY(std::optional<bool> noCanMoveNote READ noCanMoveNote WRITE setNoCanMoveNote)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const NotebookRestrictions & lhs, const NotebookRestrictions & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const NotebookRestrictions & lhs, const NotebookRestrictions & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NotebookRestrictions)

#endif // QEVERCLOUD_GENERATED_NOTEBOOKRESTRICTIONS
