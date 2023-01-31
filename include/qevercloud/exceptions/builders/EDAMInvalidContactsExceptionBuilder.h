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

#ifndef QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONBUILDER
#define QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EDAMInvalidContactsException.h>
#include <qevercloud/exceptions/EvernoteException.h>
#include <qevercloud/types/Contact.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT EDAMInvalidContactsExceptionBuilder
{
public:
    EDAMInvalidContactsExceptionBuilder();

    EDAMInvalidContactsExceptionBuilder(EDAMInvalidContactsExceptionBuilder && other) noexcept;

    ~EDAMInvalidContactsExceptionBuilder() noexcept;

    EDAMInvalidContactsExceptionBuilder & operator=(EDAMInvalidContactsExceptionBuilder && other) noexcept;

    EDAMInvalidContactsExceptionBuilder & setContacts(QList<Contact> contacts);
    EDAMInvalidContactsExceptionBuilder & setParameter(std::optional<QString> parameter);
    EDAMInvalidContactsExceptionBuilder & setReasons(std::optional<QList<EDAMInvalidContactReason>> reasons);

    [[nodiscard]] EDAMInvalidContactsException build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONBUILDER
