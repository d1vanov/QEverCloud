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

#include <qevercloud/exceptions/builders/EDAMNotFoundExceptionBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMNotFoundExceptionBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_identifier;
    std::optional<QString> m_key;
};

EDAMNotFoundExceptionBuilder::EDAMNotFoundExceptionBuilder() :
    d(new EDAMNotFoundExceptionBuilder::Impl)
{}

EDAMNotFoundExceptionBuilder::EDAMNotFoundExceptionBuilder(EDAMNotFoundExceptionBuilder && other) noexcept :
    d{std::move(other.d)}
{}

EDAMNotFoundExceptionBuilder::~EDAMNotFoundExceptionBuilder() noexcept = default;

EDAMNotFoundExceptionBuilder & EDAMNotFoundExceptionBuilder::operator=(EDAMNotFoundExceptionBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

EDAMNotFoundExceptionBuilder & EDAMNotFoundExceptionBuilder::setIdentifier(std::optional<QString> identifier)
{
    d->m_identifier = std::move(identifier);
    return *this;
}

EDAMNotFoundExceptionBuilder & EDAMNotFoundExceptionBuilder::setKey(std::optional<QString> key)
{
    d->m_key = std::move(key);
    return *this;
}

EDAMNotFoundException EDAMNotFoundExceptionBuilder::build()
{
    EDAMNotFoundException result;

    result.setIdentifier(std::move(d->m_identifier));
    result.setKey(std::move(d->m_key));

    d->m_identifier = {};
    d->m_key = {};

    return result;
}

} // namespace qevercloud
