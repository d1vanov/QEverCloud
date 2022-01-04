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

#ifndef QEVERCLOUD_GENERATED_METATYPES
#define QEVERCLOUD_GENERATED_METATYPES

#include <qevercloud/types/All.h>
#include <QMetaType>

namespace qevercloud {

QEVERCLOUD_EXPORT void registerMetatypes();

} // namespace qevercloud

Q_DECLARE_METATYPE(std::optional<QByteArray>);
Q_DECLARE_METATYPE(std::optional<QList<QString>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::Contact>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::EDAMInvalidContactReason>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::InvitationShareRelationship>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::LinkedNotebook>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::ManageNoteSharesError>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::ManageNotebookSharesError>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::MemberShareRelationship>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::Note>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::NoteInvitationShareRelationship>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::NoteMemberShareRelationship>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::Notebook>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::NotebookDescriptor>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::RelatedContent>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::RelatedContentImage>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::Resource>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::SavedSearch>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::SharedNote>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::SharedNotebook>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::Tag>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::UserIdentity>>);
Q_DECLARE_METATYPE(std::optional<QList<qevercloud::UserProfile>>);
Q_DECLARE_METATYPE(std::optional<QList<qint32>>);
Q_DECLARE_METATYPE(std::optional<QList<qint64>>);
Q_DECLARE_METATYPE(std::optional<QSet<QString>>);
Q_DECLARE_METATYPE(std::optional<QSet<qevercloud::RelatedContentType>>);
Q_DECLARE_METATYPE(std::optional<QString>);
Q_DECLARE_METATYPE(std::optional<bool>);
Q_DECLARE_METATYPE(std::optional<double>);
Q_DECLARE_METATYPE(std::optional<qevercloud::AccountLimits>);
Q_DECLARE_METATYPE(std::optional<qevercloud::Accounting>);
Q_DECLARE_METATYPE(std::optional<qevercloud::BusinessInvitationStatus>);
Q_DECLARE_METATYPE(std::optional<qevercloud::BusinessNotebook>);
Q_DECLARE_METATYPE(std::optional<qevercloud::BusinessUserAttributes>);
Q_DECLARE_METATYPE(std::optional<qevercloud::BusinessUserInfo>);
Q_DECLARE_METATYPE(std::optional<qevercloud::BusinessUserRole>);
Q_DECLARE_METATYPE(std::optional<qevercloud::BusinessUserStatus>);
Q_DECLARE_METATYPE(std::optional<qevercloud::CanMoveToContainerRestrictions>);
Q_DECLARE_METATYPE(std::optional<qevercloud::CanMoveToContainerStatus>);
Q_DECLARE_METATYPE(std::optional<qevercloud::Contact>);
Q_DECLARE_METATYPE(std::optional<qevercloud::ContactType>);
Q_DECLARE_METATYPE(std::optional<qevercloud::Data>);
Q_DECLARE_METATYPE(std::optional<qevercloud::EDAMNotFoundException>);
Q_DECLARE_METATYPE(std::optional<qevercloud::EDAMUserException>);
Q_DECLARE_METATYPE(std::optional<qevercloud::Identity>);
Q_DECLARE_METATYPE(std::optional<qevercloud::LazyMap>);
Q_DECLARE_METATYPE(std::optional<qevercloud::Note>);
Q_DECLARE_METATYPE(std::optional<qevercloud::NoteAttributes>);
Q_DECLARE_METATYPE(std::optional<qevercloud::NoteFilter>);
Q_DECLARE_METATYPE(std::optional<qevercloud::NoteLimits>);
Q_DECLARE_METATYPE(std::optional<qevercloud::NoteRestrictions>);
Q_DECLARE_METATYPE(std::optional<qevercloud::NoteShareRelationshipRestrictions>);
Q_DECLARE_METATYPE(std::optional<qevercloud::NoteSortOrder>);
Q_DECLARE_METATYPE(std::optional<qevercloud::NotebookRecipientSettings>);
Q_DECLARE_METATYPE(std::optional<qevercloud::NotebookRestrictions>);
Q_DECLARE_METATYPE(std::optional<qevercloud::PremiumOrderStatus>);
Q_DECLARE_METATYPE(std::optional<qevercloud::PrivilegeLevel>);
Q_DECLARE_METATYPE(std::optional<qevercloud::PublicUserInfo>);
Q_DECLARE_METATYPE(std::optional<qevercloud::Publishing>);
Q_DECLARE_METATYPE(std::optional<qevercloud::QueryFormat>);
Q_DECLARE_METATYPE(std::optional<qevercloud::RecipientStatus>);
Q_DECLARE_METATYPE(std::optional<qevercloud::RelatedContentAccess>);
Q_DECLARE_METATYPE(std::optional<qevercloud::RelatedContentType>);
Q_DECLARE_METATYPE(std::optional<qevercloud::ReminderEmailConfig>);
Q_DECLARE_METATYPE(std::optional<qevercloud::ResourceAttributes>);
Q_DECLARE_METATYPE(std::optional<qevercloud::SavedSearchScope>);
Q_DECLARE_METATYPE(std::optional<qevercloud::ServiceLevel>);
Q_DECLARE_METATYPE(std::optional<qevercloud::ShareRelationshipPrivilegeLevel>);
Q_DECLARE_METATYPE(std::optional<qevercloud::ShareRelationshipRestrictions>);
Q_DECLARE_METATYPE(std::optional<qevercloud::SharedNotePrivilegeLevel>);
Q_DECLARE_METATYPE(std::optional<qevercloud::SharedNotebookInstanceRestrictions>);
Q_DECLARE_METATYPE(std::optional<qevercloud::SharedNotebookPrivilegeLevel>);
Q_DECLARE_METATYPE(std::optional<qevercloud::SharedNotebookRecipientSettings>);
Q_DECLARE_METATYPE(std::optional<qevercloud::User>);
Q_DECLARE_METATYPE(std::optional<qevercloud::UserAttributes>);
Q_DECLARE_METATYPE(std::optional<qevercloud::UserIdentity>);
Q_DECLARE_METATYPE(std::optional<qevercloud::UserIdentityType>);
Q_DECLARE_METATYPE(std::optional<qevercloud::UserUrls>);
Q_DECLARE_METATYPE(std::optional<qint16>);
Q_DECLARE_METATYPE(std::optional<qint32>);
Q_DECLARE_METATYPE(std::optional<qint64>);

using MapQStringToQString = QMap<QString, QString>;
Q_DECLARE_METATYPE(std::optional<MapQStringToQString>);

using MapQStringToQint32 = QMap<QString, qint32>;
Q_DECLARE_METATYPE(std::optional<MapQStringToQint32>);

#endif // QEVERCLOUD_GENERATED_METATYPES
