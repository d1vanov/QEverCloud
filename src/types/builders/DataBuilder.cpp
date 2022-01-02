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

#include <qevercloud/types/builders/DataBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN DataBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QByteArray> m_bodyHash;
    std::optional<qint32> m_size;
    std::optional<QByteArray> m_body;
};

DataBuilder::DataBuilder() :
    d(new DataBuilder::Impl)
{}

DataBuilder::DataBuilder(DataBuilder && other) noexcept :
    d{std::move(other.d)}
{}

DataBuilder::~DataBuilder() noexcept = default;

DataBuilder & DataBuilder::operator=(DataBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

DataBuilder & DataBuilder::setBodyHash(std::optional<QByteArray> bodyHash)
{
    d->m_bodyHash = std::move(bodyHash);
    return *this;
}

DataBuilder & DataBuilder::setSize(std::optional<qint32> size)
{
    d->m_size = std::move(size);
    return *this;
}

DataBuilder & DataBuilder::setBody(std::optional<QByteArray> body)
{
    d->m_body = std::move(body);
    return *this;
}

Data DataBuilder::build()
{
    Data result;

    result.setBodyHash(std::move(d->m_bodyHash));
    result.setSize(std::move(d->m_size));
    result.setBody(std::move(d->m_body));

    d->m_bodyHash = {};
    d->m_size = {};
    d->m_body = {};

    return result;
}

} // namespace qevercloud
