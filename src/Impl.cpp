/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Impl.h"

#include <qevercloud/exceptions/EDAMSystemExceptionAuthExpired.h>
#include <qevercloud/exceptions/EDAMSystemExceptionRateLimitReached.h>

namespace qevercloud {

void throwEDAMSystemException(const EDAMSystemException & baseException)
{
    if (baseException.errorCode() == EDAMErrorCode::AUTH_EXPIRED) {
        EDAMSystemExceptionAuthExpired e;
        e.setErrorCode(baseException.errorCode());
        e.setMessage(baseException.message());
        e.setRateLimitDuration(baseException.rateLimitDuration());
        throw e;
    }

    if (baseException.errorCode() == EDAMErrorCode::RATE_LIMIT_REACHED) {
        EDAMSystemExceptionRateLimitReached e;
        e.setErrorCode(baseException.errorCode());
        e.setMessage(baseException.message());
        e.setRateLimitDuration(baseException.rateLimitDuration());
        throw e;
    }

    throw baseException;
}

} // namespace qevercloud
