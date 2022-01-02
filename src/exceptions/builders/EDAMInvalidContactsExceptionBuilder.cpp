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

#include <qevercloud/exceptions/builders/EDAMInvalidContactsExceptionBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMInvalidContactsExceptionBuilder::Impl final:
    public QSharedData
{
public:
    QList<Contact> m_contacts;
    std::optional<QString> m_parameter;
    std::optional<QList<EDAMInvalidContactReason>> m_reasons;
};

EDAMInvalidContactsExceptionBuilder::EDAMInvalidContactsExceptionBuilder() :
    d(new EDAMInvalidContactsExceptionBuilder::Impl)
{}

EDAMInvalidContactsExceptionBuilder::EDAMInvalidContactsExceptionBuilder(EDAMInvalidContactsExceptionBuilder && other) noexcept :
    d{std::move(other.d)}
{}

EDAMInvalidContactsExceptionBuilder::~EDAMInvalidContactsExceptionBuilder() noexcept = default;

EDAMInvalidContactsExceptionBuilder & EDAMInvalidContactsExceptionBuilder::operator=(EDAMInvalidContactsExceptionBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

EDAMInvalidContactsExceptionBuilder & EDAMInvalidContactsExceptionBuilder::setContacts(QList<Contact> contacts)
{
    d->m_contacts = std::move(contacts);
    return *this;
}

EDAMInvalidContactsExceptionBuilder & EDAMInvalidContactsExceptionBuilder::setParameter(std::optional<QString> parameter)
{
    d->m_parameter = std::move(parameter);
    return *this;
}

EDAMInvalidContactsExceptionBuilder & EDAMInvalidContactsExceptionBuilder::setReasons(std::optional<QList<EDAMInvalidContactReason>> reasons)
{
    d->m_reasons = std::move(reasons);
    return *this;
}

EDAMInvalidContactsException EDAMInvalidContactsExceptionBuilder::build()
{
    EDAMInvalidContactsException result;

    result.setContacts(std::move(d->m_contacts));
    result.setParameter(std::move(d->m_parameter));
    result.setReasons(std::move(d->m_reasons));

    d->m_contacts = {};
    d->m_parameter = {};
    d->m_reasons = {};

    return result;
}

} // namespace qevercloud
