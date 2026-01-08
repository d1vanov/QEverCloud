/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/Contact.h>

#include "impl/ContactImpl.h"

namespace qevercloud {

Contact::Contact() :
    d(new Contact::Impl)
{}

Contact::Contact(const Contact & other) :
    d(other.d)
{}

Contact::Contact(Contact && other) noexcept :
    d(std::move(other.d))
{}

Contact::~Contact() noexcept {}

Contact & Contact::operator=(const Contact & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Contact & Contact::operator=(Contact && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & Contact::name() const noexcept
{
    return d->m_name;
}

void Contact::setName(std::optional<QString> name)
{
    d->m_name = std::move(name);
}

const std::optional<QString> & Contact::id() const noexcept
{
    return d->m_id;
}

void Contact::setId(std::optional<QString> id)
{
    d->m_id = std::move(id);
}

const std::optional<ContactType> & Contact::type() const noexcept
{
    return d->m_type;
}

std::optional<ContactType> & Contact::mutableType()
{
    return d->m_type;
}

void Contact::setType(std::optional<ContactType> type)
{
    d->m_type = type;
}

const std::optional<QString> & Contact::photoUrl() const noexcept
{
    return d->m_photoUrl;
}

void Contact::setPhotoUrl(std::optional<QString> photoUrl)
{
    d->m_photoUrl = std::move(photoUrl);
}

const std::optional<Timestamp> & Contact::photoLastUpdated() const noexcept
{
    return d->m_photoLastUpdated;
}

std::optional<Timestamp> & Contact::mutablePhotoLastUpdated()
{
    return d->m_photoLastUpdated;
}

void Contact::setPhotoLastUpdated(std::optional<Timestamp> photoLastUpdated)
{
    d->m_photoLastUpdated = photoLastUpdated;
}

const std::optional<QByteArray> & Contact::messagingPermit() const noexcept
{
    return d->m_messagingPermit;
}

void Contact::setMessagingPermit(std::optional<QByteArray> messagingPermit)
{
    d->m_messagingPermit = std::move(messagingPermit);
}

const std::optional<Timestamp> & Contact::messagingPermitExpires() const noexcept
{
    return d->m_messagingPermitExpires;
}

std::optional<Timestamp> & Contact::mutableMessagingPermitExpires()
{
    return d->m_messagingPermitExpires;
}

void Contact::setMessagingPermitExpires(std::optional<Timestamp> messagingPermitExpires)
{
    d->m_messagingPermitExpires = messagingPermitExpires;
}

void Contact::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const Contact & contact)
{
    strm << static_cast<const Printable&>(contact);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const Contact & contact)
{
    dbg << static_cast<const Printable&>(contact);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const Contact & contact)
{
    strm << static_cast<const Printable&>(contact);
    return strm;
}

bool operator==(const Contact & lhs, const Contact & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.name() == rhs.name() &&
        lhs.id() == rhs.id() &&
        lhs.type() == rhs.type() &&
        lhs.photoUrl() == rhs.photoUrl() &&
        lhs.photoLastUpdated() == rhs.photoLastUpdated() &&
        lhs.messagingPermit() == rhs.messagingPermit() &&
        lhs.messagingPermitExpires() == rhs.messagingPermitExpires();
}

bool operator!=(const Contact & lhs, const Contact & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
