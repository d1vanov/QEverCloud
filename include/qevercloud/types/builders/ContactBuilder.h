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

#ifndef QEVERCLOUD_GENERATED_CONTACTBUILDER
#define QEVERCLOUD_GENERATED_CONTACTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Contact.h>
#include <qevercloud/types/TypeAliases.h>
#include <QByteArray>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ContactBuilder
{
public:
    ContactBuilder();

    ContactBuilder(ContactBuilder && other) noexcept;

    ~ContactBuilder() noexcept;

    ContactBuilder & operator=(ContactBuilder && other) noexcept;

    ContactBuilder & setName(std::optional<QString> name);
    ContactBuilder & setId(std::optional<QString> id);
    ContactBuilder & setType(std::optional<ContactType> type);
    ContactBuilder & setPhotoUrl(std::optional<QString> photoUrl);
    ContactBuilder & setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated);
    ContactBuilder & setMessagingPermit(std::optional<QByteArray> messagingPermit);
    ContactBuilder & setMessagingPermitExpires(std::optional<Timestamp> messagingPermitExpires);

    [[nodiscard]] Contact build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CONTACTBUILDER
