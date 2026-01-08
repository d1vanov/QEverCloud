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

#include <qevercloud/exceptions/builders/EDAMSystemExceptionBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMSystemExceptionBuilder::Impl final:
    public QSharedData
{
public:
    EDAMErrorCode m_errorCode = EDAMErrorCode::UNKNOWN;
    std::optional<QString> m_message;
    std::optional<qint32> m_rateLimitDuration;
};

EDAMSystemExceptionBuilder::EDAMSystemExceptionBuilder() :
    d(new EDAMSystemExceptionBuilder::Impl)
{}

EDAMSystemExceptionBuilder::EDAMSystemExceptionBuilder(EDAMSystemExceptionBuilder && other) noexcept :
    d{std::move(other.d)}
{}

EDAMSystemExceptionBuilder::~EDAMSystemExceptionBuilder() noexcept = default;

EDAMSystemExceptionBuilder & EDAMSystemExceptionBuilder::operator=(EDAMSystemExceptionBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

EDAMSystemExceptionBuilder & EDAMSystemExceptionBuilder::setErrorCode(EDAMErrorCode errorCode)
{
    d->m_errorCode = errorCode;
    return *this;
}

EDAMSystemExceptionBuilder & EDAMSystemExceptionBuilder::setMessage(std::optional<QString> message)
{
    d->m_message = std::move(message);
    return *this;
}

EDAMSystemExceptionBuilder & EDAMSystemExceptionBuilder::setRateLimitDuration(std::optional<qint32> rateLimitDuration)
{
    d->m_rateLimitDuration = std::move(rateLimitDuration);
    return *this;
}

EDAMSystemException EDAMSystemExceptionBuilder::build()
{
    EDAMSystemException result;

    result.setErrorCode(d->m_errorCode);
    result.setMessage(std::move(d->m_message));
    result.setRateLimitDuration(std::move(d->m_rateLimitDuration));

    d->m_errorCode = EDAMErrorCode::UNKNOWN;
    d->m_message = {};
    d->m_rateLimitDuration = {};

    return result;
}

} // namespace qevercloud
