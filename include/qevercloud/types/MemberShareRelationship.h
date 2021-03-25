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

#ifndef QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIP
#define QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIP

#include <qevercloud/Export.h>

#include "ShareRelationshipRestrictions.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Describes the association between a Notebook and an Evernote User who is
 * a member of that notebook.
 *
 * */
class QEVERCLOUD_EXPORT MemberShareRelationship: public Printable
{
    Q_GADGET
public:
    MemberShareRelationship();
    MemberShareRelationship(const MemberShareRelationship & other);
    MemberShareRelationship(MemberShareRelationship && other) noexcept;
    ~MemberShareRelationship() noexcept override;

    MemberShareRelationship & operator=(const MemberShareRelationship & other);
    MemberShareRelationship & operator=(MemberShareRelationship && other) noexcept;

    /**
     * The string that clients should show to users to represent this
     * member.
     */
    [[nodiscard]] const std::optional<QString> & displayName() const noexcept;
    void setDisplayName(std::optional<QString> displayName);

    /**
     * The Evernote User ID of the recipient of this notebook share.
     */
    [[nodiscard]] const std::optional<UserID> & recipientUserId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableRecipientUserId();
    void setRecipientUserId(std::optional<UserID> recipientUserId);

    /**
     * The privilege at which the member can access the notebook,
     * which is the best privilege granted either individually or to a
     * group to which a member belongs, such as a business. This field is
     * used by the service to convey information to the user, so clients
     * should treat it as read-only.
     */
    [[nodiscard]] const std::optional<ShareRelationshipPrivilegeLevel> & bestPrivilege() const noexcept;
    [[nodiscard]] std::optional<ShareRelationshipPrivilegeLevel> & mutableBestPrivilege();
    void setBestPrivilege(std::optional<ShareRelationshipPrivilegeLevel> bestPrivilege);

    /**
     * The individually granted privilege for the member, which does
     * not take GROUP privileges into account. This value may be unset if
     * only a group-assigned privilege has been granted to the member.
     * This value can be managed by others with sufficient rights using
     * the manageNotebookShares method. The valid values that clients
     * should present to users for selection are given via the the
     * 'restrictions' field.
     */
    [[nodiscard]] const std::optional<ShareRelationshipPrivilegeLevel> & individualPrivilege() const noexcept;
    [[nodiscard]] std::optional<ShareRelationshipPrivilegeLevel> & mutableIndividualPrivilege();
    void setIndividualPrivilege(std::optional<ShareRelationshipPrivilegeLevel> individualPrivilege);

    /**
     * The restrictions on which privileges may be individually
     * assigned to the recipient of this share relationship.
     */
    [[nodiscard]] const std::optional<ShareRelationshipRestrictions> & restrictions() const noexcept;
    [[nodiscard]] std::optional<ShareRelationshipRestrictions> & mutableRestrictions();
    void setRestrictions(std::optional<ShareRelationshipRestrictions> restrictions);

    /**
     * The user id of the user who most recently shared the notebook
     * to this user. This field is currently unset for a MemberShareRelationship
     * created by joining a notebook that has been published to the business
     * (MemberShareRelationships where the individual privilege is unset).
     * This field is used by the service to convey information to the user, so
     * clients should treat it as read-only.
     */
    [[nodiscard]] const std::optional<UserID> & sharerUserId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableSharerUserId();
    void setSharerUserId(std::optional<UserID> sharerUserId);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<QString> displayName READ displayName WRITE setDisplayName)
    Q_PROPERTY(std::optional<UserID> recipientUserId READ recipientUserId WRITE setRecipientUserId)
    Q_PROPERTY(std::optional<ShareRelationshipPrivilegeLevel> bestPrivilege READ bestPrivilege WRITE setBestPrivilege)
    Q_PROPERTY(std::optional<ShareRelationshipPrivilegeLevel> individualPrivilege READ individualPrivilege WRITE setIndividualPrivilege)
    Q_PROPERTY(std::optional<ShareRelationshipRestrictions> restrictions READ restrictions WRITE setRestrictions)
    Q_PROPERTY(std::optional<UserID> sharerUserId READ sharerUserId WRITE setSharerUserId)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const MemberShareRelationship & lhs, const MemberShareRelationship & rhs) noexcept;
[[nodiscard]] bool operator!=(const MemberShareRelationship & lhs, const MemberShareRelationship & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::MemberShareRelationship)

#endif // QEVERCLOUD_GENERATED_MEMBERSHARERELATIONSHIP
