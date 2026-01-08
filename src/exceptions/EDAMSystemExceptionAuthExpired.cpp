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

} // namespace qevercloud
