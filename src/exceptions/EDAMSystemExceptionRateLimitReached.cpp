/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/exceptions/EDAMSystemExceptionRateLimitReached.h>

#include <memory>

namespace qevercloud {

void EDAMSystemExceptionRateLimitReached::raise() const
{
    throw *this;
}

EDAMSystemExceptionRateLimitReached * EDAMSystemExceptionRateLimitReached::clone() const
{
    auto e = std::make_unique<EDAMSystemExceptionRateLimitReached>();
    e->setErrorCode(errorCode());
    e->setMessage(message());
    e->setRateLimitDuration(rateLimitDuration());
    return e.release();
}

EverCloudExceptionDataPtr EDAMSystemExceptionRateLimitReached::exceptionData() const
{
    return std::make_shared<EDAMSystemExceptionRateLimitReachedData>(
        QString::fromUtf8(what()),
        errorCode(),
        message(),
        rateLimitDuration());
}

EDAMSystemExceptionRateLimitReachedData::EDAMSystemExceptionRateLimitReachedData(
        QString error, EDAMErrorCode errorCode,
        std::optional<QString> message,
        std::optional<qint32> rateLimitDuration) :
    EDAMSystemExceptionData(error, errorCode, message, rateLimitDuration)
{}

void EDAMSystemExceptionRateLimitReachedData::throwException() const
{
    EDAMSystemExceptionRateLimitReached e;
    e.setErrorCode(errorCode());
    e.setMessage(message());
    e.setRateLimitDuration(rateLimitDuration());
    throw e;
}

} // namespace qevercloud
