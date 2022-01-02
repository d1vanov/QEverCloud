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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOKBUILDER
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOKBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/SharedNotebook.h>
#include <qevercloud/types/SharedNotebookRecipientSettings.h>
#include <qevercloud/types/TypeAliases.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SharedNotebookBuilder
{
public:
    SharedNotebookBuilder();

    SharedNotebookBuilder(SharedNotebookBuilder && other) noexcept;

    ~SharedNotebookBuilder() noexcept;

    SharedNotebookBuilder & operator=(SharedNotebookBuilder && other) noexcept;

    SharedNotebookBuilder & setId(std::optional<qint64> id);
    SharedNotebookBuilder & setUserId(std::optional<UserID> userId);
    SharedNotebookBuilder & setNotebookGuid(std::optional<Guid> notebookGuid);
    SharedNotebookBuilder & setEmail(std::optional<QString> email);
    SharedNotebookBuilder & setRecipientIdentityId(std::optional<IdentityID> recipientIdentityId);
    SharedNotebookBuilder & setNotebookModifiable(std::optional<bool> notebookModifiable);
    SharedNotebookBuilder & setServiceCreated(std::optional<Timestamp> serviceCreated);
    SharedNotebookBuilder & setServiceUpdated(std::optional<Timestamp> serviceUpdated);
    SharedNotebookBuilder & setGlobalId(std::optional<QString> globalId);
    SharedNotebookBuilder & setUsername(std::optional<QString> username);
    SharedNotebookBuilder & setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege);
    SharedNotebookBuilder & setRecipientSettings(std::optional<SharedNotebookRecipientSettings> recipientSettings);
    SharedNotebookBuilder & setSharerUserId(std::optional<UserID> sharerUserId);
    SharedNotebookBuilder & setRecipientUsername(std::optional<QString> recipientUsername);
    SharedNotebookBuilder & setRecipientUserId(std::optional<UserID> recipientUserId);
    SharedNotebookBuilder & setServiceAssigned(std::optional<Timestamp> serviceAssigned);
    SharedNotebookBuilder & setLocallyModified(bool locallyModified);
    SharedNotebookBuilder & setLocalOnly(bool localOnly);
    SharedNotebookBuilder & setLocallyFavorited(bool favorited);
    SharedNotebookBuilder & setLocalData(QHash<QString, QVariant> localData);

    [[nodiscard]] SharedNotebook build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOKBUILDER
