/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOK
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOK

#include <qevercloud/Export.h>

#include "SharedNotebookRecipientSettings.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

/**
 * Shared notebooks represent a relationship between a notebook and a single
 * share invitation recipient.
 * */
class QEVERCLOUD_EXPORT SharedNotebook: public Printable
{
    Q_GADGET
public:
    SharedNotebook();
    SharedNotebook(const SharedNotebook & other);
    SharedNotebook(SharedNotebook && other) noexcept;
    ~SharedNotebook() noexcept override;

    SharedNotebook & operator=(const SharedNotebook & other);
    SharedNotebook & operator=(SharedNotebook && other) noexcept;

    /**
     * @brief locallyModified flag can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocallyModified() const noexcept;
    void setLocallyModified(bool modified = true);

    /**
     * @brief localOnly flag can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocalOnly() const noexcept;
    void setLocalOnly(bool localOnly = true);

    /**
     * @brief locallyFavorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * a property between different clients
     */
    [[nodiscard]] bool isLocallyFavorited() const noexcept;
    void setLocallyFavorited(bool favorited = true);

    /**
     * @brief localData property can be used to store any additional
     * data which might be needed to be set for the type object
     * by QEverCloud's client code
     */
    [[nodiscard]] const QHash<QString, QVariant> & localData() const noexcept;
    [[nodiscard]] QHash<QString, QVariant> & mutableLocalData();
    void setLocalData(QHash<QString, QVariant> localData);

    /**
     * The primary identifier of the share, which is not globally unique.
     */
    [[nodiscard]] const std::optional<qint64> & id() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableId();
    void setId(std::optional<qint64> id);

    /**
     * The user id of the owner of the notebook.
     */
    [[nodiscard]] const std::optional<UserID> & userId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableUserId();
    void setUserId(std::optional<UserID> userId);

    /**
     * The GUID of the notebook that has been shared.
     */
    [[nodiscard]] const std::optional<Guid> & notebookGuid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableNotebookGuid();
    void setNotebookGuid(std::optional<Guid> notebookGuid);

    /**
     * A string containing a display name for the recipient of the share. This may
     * be an email address, a phone number, a full name, or some other descriptive
     * string This field is read-only to clients. It will be filled in by the service
     * when returning shared notebooks.
     */
    [[nodiscard]] const std::optional<QString> & email() const noexcept;
    void setEmail(std::optional<QString> email);

    /**
     * The IdentityID of the share recipient. If present, only the user who has
     * claimed that identity may access this share.
     */
    [[nodiscard]] const std::optional<IdentityID> & recipientIdentityId() const noexcept;
    [[nodiscard]] std::optional<IdentityID> & mutableRecipientIdentityId();
    void setRecipientIdentityId(std::optional<IdentityID> recipientIdentityId);

    /**
     * DEPRECATED
     */
    [[nodiscard]] const std::optional<bool> & notebookModifiable() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNotebookModifiable();
    void setNotebookModifiable(std::optional<bool> notebookModifiable);

    /**
     * The date that the owner first created the share with the specific email
     * address.
     */
    [[nodiscard]] const std::optional<Timestamp> & serviceCreated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceCreated();
    void setServiceCreated(std::optional<Timestamp> serviceCreated);

    /**
     * The date the shared notebook was last updated on the service. This
     * will be updated when authenticateToSharedNotebook is called the first
     * time with a shared notebook (i.e. when the username is bound to that
     * shared notebook), and also when the SharedNotebook privilege is updated
     * as part of a shareNotebook(...) call, as well as on any calls to
     * updateSharedNotebook(...).
     */
    [[nodiscard]] const std::optional<Timestamp> & serviceUpdated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceUpdated();
    void setServiceUpdated(std::optional<Timestamp> serviceUpdated);

    /**
     * An immutable, opaque string that acts as a globally unique
     * identifier for this shared notebook record. You can use this field to
     * match linked notebook and shared notebook records as well as to
     * create new LinkedNotebook records. This field replaces the deprecated
     * shareKey field.
     */
    [[nodiscard]] const std::optional<QString> & globalId() const noexcept;
    void setGlobalId(std::optional<QString> globalId);

    /**
     * DEPRECATED. The username of the user who can access this share. This
     * value is read-only to clients. It will be filled in by the service when
     * returning shared notebooks.
     */
    [[nodiscard]] const std::optional<QString> & username() const noexcept;
    void setUsername(std::optional<QString> username);

    /**
     * The privilege level granted to the notebook, activity stream, and
     * invitations. See the corresponding enumeration for details.
     */
    [[nodiscard]] const std::optional<SharedNotebookPrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<SharedNotebookPrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege);

    /**
     * Settings intended for use only by the recipient of this shared
     * notebook. You should skip setting this value unless you want
     * to change the value contained inside the structure, and only if
     * you are the recipient.
     */
    [[nodiscard]] const std::optional<SharedNotebookRecipientSettings> & recipientSettings() const noexcept;
    [[nodiscard]] std::optional<SharedNotebookRecipientSettings> & mutableRecipientSettings();
    void setRecipientSettings(std::optional<SharedNotebookRecipientSettings> recipientSettings);

    /**
     * The user id of the user who shared a notebook via this shared notebook
     * instance. This may not be the same as userId, since a user with full
     * access to a notebook may have created a new share for that notebook. For
     * Business, this represents the user who shared the business notebook. This
     * field is currently unset for a SharedNotebook created by joining a
     * notebook that has been published to the business.
     */
    [[nodiscard]] const std::optional<UserID> & sharerUserId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableSharerUserId();
    void setSharerUserId(std::optional<UserID> sharerUserId);

    /**
     * The username of the user who can access this share. This is the username
     * for the user with the id in recipientUserId. This value can be set
     * by clients when calling shareNotebook(...), and that will result in the
     * created SharedNotebook being assigned to a user. This value is always set
     * if serviceAssigned is set.
     */
    [[nodiscard]] const std::optional<QString> & recipientUsername() const noexcept;
    void setRecipientUsername(std::optional<QString> recipientUsername);

    /**
     * The id of the user who can access this share. This is the id for the user
     * with the username in recipientUsername. This value is read-only and set
     * by the service. Value set by clients will be ignored. This field may be unset
     * for unjoined notebooks and is always set if serviceAssigned is set. Clients should
     * prefer this field over recipientUsername unless they need to use usernames
     * directly.
     */
    [[nodiscard]] const std::optional<UserID> & recipientUserId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableRecipientUserId();
    void setRecipientUserId(std::optional<UserID> recipientUserId);

    /**
     * The date this SharedNotebook was assigned (i.e. has been associated with an
     * Evernote user whose user ID is set in recipientUserId). Unset if the SharedNotebook
     * is not assigned. This field is a read-only value that is set by the service.
     */
    [[nodiscard]] const std::optional<Timestamp> & serviceAssigned() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableServiceAssigned();
    void setServiceAssigned(std::optional<Timestamp> serviceAssigned);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const SharedNotebook & sharedNotebook);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const SharedNotebook & sharedNotebook);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const SharedNotebook & sharedNotebook);

    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<qint64> id READ id WRITE setId)
    Q_PROPERTY(std::optional<UserID> userId READ userId WRITE setUserId)
    Q_PROPERTY(std::optional<Guid> notebookGuid READ notebookGuid WRITE setNotebookGuid)
    Q_PROPERTY(std::optional<QString> email READ email WRITE setEmail)
    Q_PROPERTY(std::optional<IdentityID> recipientIdentityId READ recipientIdentityId WRITE setRecipientIdentityId)
    Q_PROPERTY(std::optional<bool> notebookModifiable READ notebookModifiable WRITE setNotebookModifiable)
    Q_PROPERTY(std::optional<Timestamp> serviceCreated READ serviceCreated WRITE setServiceCreated)
    Q_PROPERTY(std::optional<Timestamp> serviceUpdated READ serviceUpdated WRITE setServiceUpdated)
    Q_PROPERTY(std::optional<QString> globalId READ globalId WRITE setGlobalId)
    Q_PROPERTY(std::optional<QString> username READ username WRITE setUsername)
    Q_PROPERTY(std::optional<SharedNotebookPrivilegeLevel> privilege READ privilege WRITE setPrivilege)
    Q_PROPERTY(std::optional<SharedNotebookRecipientSettings> recipientSettings READ recipientSettings WRITE setRecipientSettings)
    Q_PROPERTY(std::optional<UserID> sharerUserId READ sharerUserId WRITE setSharerUserId)
    Q_PROPERTY(std::optional<QString> recipientUsername READ recipientUsername WRITE setRecipientUsername)
    Q_PROPERTY(std::optional<UserID> recipientUserId READ recipientUserId WRITE setRecipientUserId)
    Q_PROPERTY(std::optional<Timestamp> serviceAssigned READ serviceAssigned WRITE setServiceAssigned)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const SharedNotebook & lhs, const SharedNotebook & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const SharedNotebook & lhs, const SharedNotebook & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::SharedNotebook)

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOK
