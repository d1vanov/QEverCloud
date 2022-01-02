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

#include <qevercloud/types/builders/ContactBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ContactBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_name;
    std::optional<QString> m_id;
    std::optional<ContactType> m_type;
    std::optional<QString> m_photoUrl;
    std::optional<Timestamp> m_photoLastUpdated;
    std::optional<QByteArray> m_messagingPermit;
    std::optional<Timestamp> m_messagingPermitExpires;
};

ContactBuilder::ContactBuilder() :
    d(new ContactBuilder::Impl)
{}

ContactBuilder::ContactBuilder(ContactBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ContactBuilder::~ContactBuilder() noexcept = default;

ContactBuilder & ContactBuilder::operator=(ContactBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ContactBuilder & ContactBuilder::setName(std::optional<QString> name)
{
    d->m_name = std::move(name);
    return *this;
}

ContactBuilder & ContactBuilder::setId(std::optional<QString> id)
{
    d->m_id = std::move(id);
    return *this;
}

ContactBuilder & ContactBuilder::setType(std::optional<ContactType> type)
{
    d->m_type = std::move(type);
    return *this;
}

ContactBuilder & ContactBuilder::setPhotoUrl(std::optional<QString> photoUrl)
{
    d->m_photoUrl = std::move(photoUrl);
    return *this;
}

ContactBuilder & ContactBuilder::setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated)
{
    d->m_photoLastUpdated = std::move(photoLastUpdated);
    return *this;
}

ContactBuilder & ContactBuilder::setMessagingPermit(std::optional<QByteArray> messagingPermit)
{
    d->m_messagingPermit = std::move(messagingPermit);
    return *this;
}

ContactBuilder & ContactBuilder::setMessagingPermitExpires(std::optional<Timestamp> messagingPermitExpires)
{
    d->m_messagingPermitExpires = std::move(messagingPermitExpires);
    return *this;
}

Contact ContactBuilder::build()
{
    Contact result;

    result.setName(std::move(d->m_name));
    result.setId(std::move(d->m_id));
    result.setType(std::move(d->m_type));
    result.setPhotoUrl(std::move(d->m_photoUrl));
    result.setPhotoLastUpdated(std::move(d->m_photoLastUpdated));
    result.setMessagingPermit(std::move(d->m_messagingPermit));
    result.setMessagingPermitExpires(std::move(d->m_messagingPermitExpires));

    d->m_name = {};
    d->m_id = {};
    d->m_type = {};
    d->m_photoUrl = {};
    d->m_photoLastUpdated = {};
    d->m_messagingPermit = {};
    d->m_messagingPermitExpires = {};

    return result;
}

} // namespace qevercloud
