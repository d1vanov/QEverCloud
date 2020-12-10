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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOK_H
#define QEVERCLOUD_GENERATED_NOTEBOOK_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "BusinessNotebook.h"
#include "NotebookRecipientSettings.h"
#include "NotebookRestrictions.h"
#include "Publishing.h"
#include "SharedNotebook.h"
#include "TypeAliases.h"
#include "User.h"
#include <QList>
#include <optional>

namespace qevercloud {

/**
 * A unique container for a set of notes.
 * */
class QEVERCLOUD_EXPORT Notebook: public Printable
{
    Q_GADGET
public:
    Notebook();
    Notebook(const Notebook & other);
    Notebook(Notebook && other) noexcept;
    ~Notebook() noexcept override;

    Notebook & operator=(const Notebook & other);
    Notebook & operator=(Notebook && other) noexcept;

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
    The unique identifier of this notebook.
       <br/>
       Length:  EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
       <br/>
       Regex:  EDAM_GUID_REGEX
    */
    [[nodiscard]] const std::optional<Guid> & guid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableGuid();
    void setGuid(std::optional<Guid> guid);

    /**
    A sequence of characters representing the name of the
       notebook.  May be changed by clients, but the account may not contain two
       notebooks with names that are equal via a case-insensitive comparison.
       Can't begin or end with a space.
       <br/>
       Length:  EDAM_NOTEBOOK_NAME_LEN_MIN - EDAM_NOTEBOOK_NAME_LEN_MAX
       <br/>
       Regex:  EDAM_NOTEBOOK_NAME_REGEX
    */
    [[nodiscard]] const std::optional<QString> & name() const noexcept;
    void setName(std::optional<QString> name);

    /**
    A number identifying the last transaction to
       modify the state of this object.  The USN values are sequential within an
       account, and can be used to compare the order of modifications within the
       service.
    */
    [[nodiscard]] const std::optional<qint32> & updateSequenceNum() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUpdateSequenceNum();
    void setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);

    /**
    If true, this notebook should be used for new notes
       whenever the user has not (or cannot) specify a desired target notebook.
       For example, if a note is submitted via SMTP email.
       The service will maintain at most one defaultNotebook per account.
       If a second notebook is created or updated with defaultNotebook set to
       true, the service will automatically update the prior notebook's
       defaultNotebook field to false.  If the default notebook is deleted
       (i.e. "active" set to false), the "defaultNotebook" field will be
       set to false by the service.  If the account has no default notebook
       set, the service will use the most recent notebook as the default.
    */
    [[nodiscard]] const std::optional<bool> & defaultNotebook() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableDefaultNotebook();
    void setDefaultNotebook(std::optional<bool> defaultNotebook);

    /**
    The time when this notebook was created on the
       service. This will be set on the service during creation, and the service
       will provide this value when it returns a Notebook to a client.
       The service will ignore this value if it is sent by clients.
    */
    [[nodiscard]] const std::optional<Timestamp> & serviceCreated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceCreated();
    void setServiceCreated(std::optional<Timestamp> serviceCreated);

    /**
    The time when this notebook was last modified on the
       service.  This will be set on the service during creation, and the service
       will provide this value when it returns a Notebook to a client.
       The service will ignore this value if it is sent by clients.
    */
    [[nodiscard]] const std::optional<Timestamp> & serviceUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceUpdated();
    void setServiceUpdated(std::optional<Timestamp> serviceUpdated);

    /**
    If the Notebook has been opened for public access, then this will point to the set of
       publishing information for the Notebook (URI, description, etc.). A Notebook cannot be
       published without providing this information, but it will persist for later use if publishing
       is ever disabled on the Notebook. Clients that do not wish to change the publishing behavior
       of a Notebook should not set this value when calling NoteStore.updateNotebook().
       Note that this structure is never populated for business notebooks, see the businessNotebook
       field.
    */
    [[nodiscard]] const std::optional<Publishing> & publishing() const noexcept;
    [[nodiscard]] std::optional<Publishing> & mutablePublishing();
    void setPublishing(std::optional<Publishing> publishing);

    /**
    If this is set to true, then the Notebook will be
       accessible either to the public, or for business users to their business,
       via the 'publishing' or 'businessNotebook' specifications, which must also be set. If this is
       set to false, the Notebook will not be available to the public (or business).
       Clients that do not wish to change the publishing behavior of a Notebook
       should not set this value when calling NoteStore.updateNotebook().
    */
    [[nodiscard]] const std::optional<bool> & published() const noexcept;
    [[nodiscard]] std::optional<bool> & mutablePublished();
    void setPublished(std::optional<bool> published);

    /**
    If this is set, then the notebook is visually contained within a stack
       of notebooks with this name.  All notebooks in the same account with the
       same 'stack' field are considered to be in the same stack.
       Notebooks with no stack set are "top level" and not contained within a
       stack.
    */
    [[nodiscard]] const std::optional<QString> & stack() const noexcept;
    void setStack(std::optional<QString> stack);

    /**
    <i>DEPRECATED</i> - replaced by sharedNotebooks.
    */
    [[nodiscard]] const std::optional<QList<qint64>> & sharedNotebookIds() const noexcept;
    [[nodiscard]] std::optional<QList<qint64>> & mutableSharedNotebookIds();
    void setSharedNotebookIds(std::optional<QList<qint64>> sharedNotebookIds);

    /**
    The list of recipients to whom this notebook has been shared
       (one SharedNotebook object per recipient email address). This field will
       be unset if you do not have permission to access this data. If you are
       accessing the notebook as the owner or via a shared notebook that is
       modifiable, then you have access to this data and the value will be set.
       This field is read-only. Clients may not make changes to shared notebooks
       via this field.
    */
    [[nodiscard]] const std::optional<QList<SharedNotebook>> & sharedNotebooks() const noexcept;
    [[nodiscard]] std::optional<QList<SharedNotebook>> & mutableSharedNotebooks();
    void setSharedNotebooks(std::optional<QList<SharedNotebook>> sharedNotebooks);

    /**
    If the notebook is part of a business account and has been shared with the entire
       business, this will contain sharing information. The presence or absence of this field
       is not a reliable test of whether a given notebook is in fact a business notebook - the
       field is only used when a notebook is or has been shared with the entire business.
    */
    [[nodiscard]] const std::optional<BusinessNotebook> & businessNotebook() const noexcept;
    [[nodiscard]] std::optional<BusinessNotebook> & mutableBusinessNotebook();
    void setBusinessNotebook(std::optional<BusinessNotebook> businessNotebook);

    /**
    Intended for use with Business accounts, this field identifies the user who
       has been designated as the "contact".  For notebooks created in business
       accounts, the server will automatically set this value to the user who created
       the notebook unless Notebook.contact.username has been set, in which that value
       will be used.  When updating a notebook, it is common to leave Notebook.contact
       field unset, indicating that no change to the value is being requested and that
       the existing value, if any, should be preserved.
    */
    [[nodiscard]] const std::optional<User> & contact() const noexcept;
    [[nodiscard]] std::optional<User> & mutableContact();
    void setContact(std::optional<User> contact);

    [[nodiscard]] const std::optional<NotebookRestrictions> & restrictions() const noexcept;
    [[nodiscard]] std::optional<NotebookRestrictions> & mutableRestrictions();
    void setRestrictions(std::optional<NotebookRestrictions> restrictions);

    /**
    This represents the preferences/settings that a recipient has set for this
       notebook. These are intended to be changed only by the recipient, and each
       recipient has their own recipient settings.
    */
    [[nodiscard]] const std::optional<NotebookRecipientSettings> & recipientSettings() const noexcept;
    [[nodiscard]] std::optional<NotebookRecipientSettings> & mutableRecipientSettings();
    void setRecipientSettings(std::optional<NotebookRecipientSettings> recipientSettings);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const Notebook & other) const noexcept;
    [[nodiscard]] bool operator!=(const Notebook & other) const noexcept;

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(QString parentLocalId READ parentLocalId WRITE setParentLocalId)
    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<Guid> guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<QString> name READ name WRITE setName)
    Q_PROPERTY(std::optional<qint32> updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(std::optional<bool> defaultNotebook READ defaultNotebook WRITE setDefaultNotebook)
    Q_PROPERTY(std::optional<Timestamp> serviceCreated READ serviceCreated WRITE setServiceCreated)
    Q_PROPERTY(std::optional<Timestamp> serviceUpdated READ serviceUpdated WRITE setServiceUpdated)
    Q_PROPERTY(std::optional<Publishing> publishing READ publishing WRITE setPublishing)
    Q_PROPERTY(std::optional<bool> published READ published WRITE setPublished)
    Q_PROPERTY(std::optional<QString> stack READ stack WRITE setStack)
    Q_PROPERTY(std::optional<QList<qint64>> sharedNotebookIds READ sharedNotebookIds WRITE setSharedNotebookIds)
    Q_PROPERTY(std::optional<QList<SharedNotebook>> sharedNotebooks READ sharedNotebooks WRITE setSharedNotebooks)
    Q_PROPERTY(std::optional<BusinessNotebook> businessNotebook READ businessNotebook WRITE setBusinessNotebook)
    Q_PROPERTY(std::optional<User> contact READ contact WRITE setContact)
    Q_PROPERTY(std::optional<NotebookRestrictions> restrictions READ restrictions WRITE setRestrictions)
    Q_PROPERTY(std::optional<NotebookRecipientSettings> recipientSettings READ recipientSettings WRITE setRecipientSettings)

private:
    class NotebookData;
    QSharedDataPointer<NotebookData> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::Notebook)

#endif // QEVERCLOUD_GENERATED_NOTEBOOK_H
