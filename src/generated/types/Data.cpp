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

#include <qevercloud/generated/types/Data.h>

#include "impl/DataImpl.h"

namespace qevercloud {

Data::Data() :
    d(new Data::Impl)
 {}

Data::Data(const Data & other) :
    d(other.d)
{}

Data::Data(Data && other) noexcept :
    d(std::move(other.d))
{}

Data::~Data() noexcept {}

Data & Data::operator=(const Data & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

Data & Data::operator=(Data && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QByteArray> & Data::bodyHash() const noexcept
{
    return d->m_bodyHash;
}

void Data::setBodyHash(std::optional<QByteArray> bodyHash)
{
    d->m_bodyHash = bodyHash;
}

const std::optional<qint32> & Data::size() const noexcept
{
    return d->m_size;
}

std::optional<qint32> & Data::mutableSize()
{
    return d->m_size;
}

void Data::setSize(std::optional<qint32> size)
{
    d->m_size = size;
}

const std::optional<QByteArray> & Data::body() const noexcept
{
    return d->m_body;
}

void Data::setBody(std::optional<QByteArray> body)
{
    d->m_body = body;
}

void Data::print(QTextStream & strm) const
{
    d->print(strm);
}

bool operator==(const Data & lhs, const Data & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.bodyHash() == rhs.bodyHash() &&
        lhs.size() == rhs.size() &&
        lhs.body() == rhs.body();
}

bool operator!=(const Data & lhs, const Data & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
