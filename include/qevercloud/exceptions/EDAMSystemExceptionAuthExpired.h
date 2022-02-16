/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EDAM_SYSTEM_EXCEPTION_AUTH_EXPIRED_H
#define QEVERCLOUD_EDAM_SYSTEM_EXCEPTION_AUTH_EXPIRED_H

#include <qevercloud/Export.h>
#include <qevercloud/exceptions/EDAMSystemException.h>

namespace qevercloud {

/**
 *  EDAMSystemException for `errorCode = AUTH_EXPIRED`
 */
class QEVERCLOUD_EXPORT EDAMSystemExceptionAuthExpired: public EDAMSystemException
{
public:
    void raise() const override;
    [[nodiscard]] EDAMSystemExceptionAuthExpired * clone() const override;
};

} // namespace qevercloud

#endif // QEVERCLOUD_EDAM_SYSTEM_EXCEPTION_AUTH_EXPIRED_H