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

#ifndef QEVERCLOUD_GENERATED_USERIDENTITY_H
#define QEVERCLOUD_GENERATED_USERIDENTITY_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure that holds user identifying information such as an
 * email address, Evernote user ID, or an identifier from a 3rd party
 * service.  An instance consists of a type and a value, where the
 * value will be stored in one of the value fields depending upon the
 * data type required for the identity type.
 *
 * When used with shared notebook invitations, a UserIdentity
 * identifies a particular person who may not (yet) have an Evernote
 * UserID UserIdentity but who has (almost) unique access to the
 * service endpoint described by the UserIdentity.  For example, an
 * e-mail UserIdentity can identify the person who receives e-mail at
 * the given address, and who can therefore read the share key that
 * has a cryptographic signature from the Evernote service. With the
 * share key, this person can supply their Evernote UserID via an
 * authentication token to join the notebook
 * (authenticateToSharedNotebook), at which time we have associated
 * the e-mail UserIdentity with an Evernote UserID UserIdentity. Note
 * that using shared notebook records, the relationship between
 * Evernote UserIDs and e-mail addresses is many to many.
 *
 * Note that the identifier may not directly identify a
 * particular Evernote UserID UserIdentity without further
 * verification.  For example, an e-mail UserIdentity may be
 * associated with an invitation to join a notebook (via a shared
 * notebook record), but until a user uses a share key, that was sent
 * to that e-mail address, to join the notebook, we do not know an
 * Evernote UserID UserIdentity ID to match the e-mail address.
 */
class QEVERCLOUD_EXPORT UserIdentity: public Printable
{
    Q_GADGET
public:
    UserIdentity();
    UserIdentity(const UserIdentity & other);
    UserIdentity(UserIdentity && other) noexcept;
    ~UserIdentity() noexcept override;

    UserIdentity & operator=(const UserIdentity & other);
    UserIdentity & operator=(UserIdentity && other) noexcept;

    [[nodiscard]] const std::optional<UserIdentityType> & type() const noexcept;
    [[nodiscard]] std::optional<UserIdentityType> & mutableType();
    void setType(std::optional<UserIdentityType> type);

    [[nodiscard]] const std::optional<QString> & stringIdentifier() const noexcept;
    void setStringIdentifier(std::optional<QString> stringIdentifier);

    [[nodiscard]] const std::optional<qint64> & longIdentifier() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableLongIdentifier();
    void setLongIdentifier(std::optional<qint64> longIdentifier);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<UserIdentityType> type READ type WRITE setType)
    Q_PROPERTY(std::optional<QString> stringIdentifier READ stringIdentifier WRITE setStringIdentifier)
    Q_PROPERTY(std::optional<qint64> longIdentifier READ longIdentifier WRITE setLongIdentifier)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const UserIdentity & lhs, const UserIdentity & rhs) noexcept;
[[nodiscard]] bool operator!=(const UserIdentity & lhs, const UserIdentity & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::UserIdentity)

#endif // QEVERCLOUD_GENERATED_USERIDENTITY_H
