/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONBUILDER
#define QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EDAMSystemException.h>
#include <qevercloud/exceptions/EvernoteException.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT EDAMSystemExceptionBuilder
{
public:
    EDAMSystemExceptionBuilder();

    EDAMSystemExceptionBuilder(EDAMSystemExceptionBuilder && other) noexcept;

    ~EDAMSystemExceptionBuilder() noexcept;

    EDAMSystemExceptionBuilder & operator=(EDAMSystemExceptionBuilder && other) noexcept;

    EDAMSystemExceptionBuilder & setErrorCode(EDAMErrorCode errorCode);
    EDAMSystemExceptionBuilder & setMessage(std::optional<QString> message);
    EDAMSystemExceptionBuilder & setRateLimitDuration(std::optional<qint32> rateLimitDuration);

    [[nodiscard]] EDAMSystemException build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONBUILDER
