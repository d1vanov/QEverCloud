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

#ifndef QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONBUILDER
#define QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EDAMUserException.h>
#include <qevercloud/exceptions/EvernoteException.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT EDAMUserExceptionBuilder
{
public:
    EDAMUserExceptionBuilder();

    EDAMUserExceptionBuilder(EDAMUserExceptionBuilder && other) noexcept;

    ~EDAMUserExceptionBuilder() noexcept;

    EDAMUserExceptionBuilder & operator=(EDAMUserExceptionBuilder && other) noexcept;

    EDAMUserExceptionBuilder & setErrorCode(EDAMErrorCode errorCode);
    EDAMUserExceptionBuilder & setParameter(std::optional<QString> parameter);

    [[nodiscard]] EDAMUserException build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONBUILDER
