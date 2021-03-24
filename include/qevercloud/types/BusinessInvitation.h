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

#ifndef QEVERCLOUD_GENERATED_BUSINESSINVITATION_H
#define QEVERCLOUD_GENERATED_BUSINESSINVITATION_H

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure describing an invitation to join a business account.
 *
 * */
class QEVERCLOUD_EXPORT BusinessInvitation: public Printable
{
    Q_GADGET
public:
    BusinessInvitation();
    BusinessInvitation(const BusinessInvitation & other);
    BusinessInvitation(BusinessInvitation && other) noexcept;
    ~BusinessInvitation() noexcept override;

    BusinessInvitation & operator=(const BusinessInvitation & other);
    BusinessInvitation & operator=(BusinessInvitation && other) noexcept;

    /**
     * The ID of the business to which the invitation grants access.
     */
    [[nodiscard]] const std::optional<qint32> & businessId() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableBusinessId();
    void setBusinessId(std::optional<qint32> businessId);

    /**
     * The email address that was invited to join the business.
     */
    [[nodiscard]] const std::optional<QString> & email() const noexcept;
    void setEmail(std::optional<QString> email);

    /**
     * The role to grant the user after the invitation is accepted.
     */
    [[nodiscard]] const std::optional<BusinessUserRole> & role() const noexcept;
    [[nodiscard]] std::optional<BusinessUserRole> & mutableRole();
    void setRole(std::optional<BusinessUserRole> role);

    /**
     * The status of the invitation.
     */
    [[nodiscard]] const std::optional<BusinessInvitationStatus> & status() const noexcept;
    [[nodiscard]] std::optional<BusinessInvitationStatus> & mutableStatus();
    void setStatus(std::optional<BusinessInvitationStatus> status);

    /**
     * For invitations that were initially requested by a non-admin member of the business,
     * this field specifies the user ID of the requestor. For all other invitations, this field
     * will be unset.
     */
    [[nodiscard]] const std::optional<UserID> & requesterId() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableRequesterId();
    void setRequesterId(std::optional<UserID> requesterId);

    /**
     * If this invitation was created implicitly via a WorkChat, this field
     * will be true.
     */
    [[nodiscard]] const std::optional<bool> & fromWorkChat() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableFromWorkChat();
    void setFromWorkChat(std::optional<bool> fromWorkChat);

    /**
     * The timestamp at which this invitation was created.
     */
    [[nodiscard]] const std::optional<Timestamp> & created() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableCreated();
    void setCreated(std::optional<Timestamp> created);

    /**
     * The timestamp at which the most recent reminder was sent.
     */
    [[nodiscard]] const std::optional<Timestamp> & mostRecentReminder() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableMostRecentReminder();
    void setMostRecentReminder(std::optional<Timestamp> mostRecentReminder);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<qint32> businessId READ businessId WRITE setBusinessId)
    Q_PROPERTY(std::optional<QString> email READ email WRITE setEmail)
    Q_PROPERTY(std::optional<BusinessUserRole> role READ role WRITE setRole)
    Q_PROPERTY(std::optional<BusinessInvitationStatus> status READ status WRITE setStatus)
    Q_PROPERTY(std::optional<UserID> requesterId READ requesterId WRITE setRequesterId)
    Q_PROPERTY(std::optional<bool> fromWorkChat READ fromWorkChat WRITE setFromWorkChat)
    Q_PROPERTY(std::optional<Timestamp> created READ created WRITE setCreated)
    Q_PROPERTY(std::optional<Timestamp> mostRecentReminder READ mostRecentReminder WRITE setMostRecentReminder)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const BusinessInvitation & lhs, const BusinessInvitation & rhs) noexcept;
[[nodiscard]] bool operator!=(const BusinessInvitation & lhs, const BusinessInvitation & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::BusinessInvitation)

#endif // QEVERCLOUD_GENERATED_BUSINESSINVITATION_H
