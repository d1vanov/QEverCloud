/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/exceptions/EDAMSystemExceptionAuthExpired.h>

#include <memory>

namespace qevercloud {

void EDAMSystemExceptionAuthExpired::raise() const
{
    throw *this;
}

EDAMSystemExceptionAuthExpired * EDAMSystemExceptionAuthExpired::clone() const
{
    auto e = std::make_unique<EDAMSystemExceptionAuthExpired>();
    e->setErrorCode(errorCode());
    e->setMessage(message());
    e->setRateLimitDuration(rateLimitDuration());
    return e.release();
}

EverCloudExceptionDataPtr EDAMSystemExceptionAuthExpired::exceptionData() const
{
    return std::make_shared<EDAMSystemExceptionAuthExpiredData>(
        QString::fromUtf8(what()),
        errorCode(),
        message(),
        rateLimitDuration());
}

EDAMSystemExceptionAuthExpiredData::EDAMSystemExceptionAuthExpiredData(
        QString error,
        EDAMErrorCode errorCode,
        std::optional<QString> message,
        std::optional<qint32> rateLimitDuration) :
    EDAMSystemExceptionData(error, errorCode, message, rateLimitDuration)
{}

void EDAMSystemExceptionAuthExpiredData::throwException() const
{
    EDAMSystemExceptionAuthExpired e;
    e.setErrorCode(errorCode());
    e.setMessage(message());
    e.setRateLimitDuration(rateLimitDuration());
    throw e;
}

} // namespace qevercloud
