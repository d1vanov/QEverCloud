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

#ifndef QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONBUILDER
#define QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EDAMNotFoundException.h>
#include <qevercloud/exceptions/EvernoteException.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT EDAMNotFoundExceptionBuilder
{
public:
    EDAMNotFoundExceptionBuilder();

    EDAMNotFoundExceptionBuilder(EDAMNotFoundExceptionBuilder && other) noexcept;

    ~EDAMNotFoundExceptionBuilder() noexcept;

    EDAMNotFoundExceptionBuilder & operator=(EDAMNotFoundExceptionBuilder && other) noexcept;

    EDAMNotFoundExceptionBuilder & setIdentifier(std::optional<QString> identifier);
    EDAMNotFoundExceptionBuilder & setKey(std::optional<QString> key);

    [[nodiscard]] EDAMNotFoundException build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONBUILDER
