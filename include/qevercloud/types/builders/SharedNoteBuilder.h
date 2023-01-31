/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBUILDER
#define QEVERCLOUD_GENERATED_SHAREDNOTEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Identity.h>
#include <qevercloud/types/SharedNote.h>
#include <qevercloud/types/TypeAliases.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SharedNoteBuilder
{
public:
    SharedNoteBuilder();

    SharedNoteBuilder(SharedNoteBuilder && other) noexcept;

    ~SharedNoteBuilder() noexcept;

    SharedNoteBuilder & operator=(SharedNoteBuilder && other) noexcept;

    SharedNoteBuilder & setLocallyModified(bool isLocallyModified);
    SharedNoteBuilder & setLocalOnly(bool isLocalOnly);
    SharedNoteBuilder & setLocallyFavorited(bool isLocallyFavorited);
    SharedNoteBuilder & setLocalData(QHash<QString, QVariant> localData);
    SharedNoteBuilder & setNoteGuid(Guid noteGuid);
    SharedNoteBuilder & setSharerUserID(std::optional<UserID> sharerUserID);
    SharedNoteBuilder & setRecipientIdentity(std::optional<Identity> recipientIdentity);
    SharedNoteBuilder & setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);
    SharedNoteBuilder & setServiceCreated(std::optional<Timestamp> serviceCreated);
    SharedNoteBuilder & setServiceUpdated(std::optional<Timestamp> serviceUpdated);
    SharedNoteBuilder & setServiceAssigned(std::optional<Timestamp> serviceAssigned);

    [[nodiscard]] SharedNote build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBUILDER
