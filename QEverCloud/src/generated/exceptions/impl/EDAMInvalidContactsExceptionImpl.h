/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONIMPL_H
#define QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONIMPL_H

#include <generated/exceptions/EDAMInvalidContactsException.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMInvalidContactsException::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const EDAMInvalidContactsException::Impl & other) = default;
    Impl(EDAMInvalidContactsException::Impl && other) noexcept = default;

    EDAMInvalidContactsException::Impl & operator=(const EDAMInvalidContactsException::Impl & other) = delete;
    EDAMInvalidContactsException::Impl & operator=(EDAMInvalidContactsException::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const EDAMInvalidContactsException::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const EDAMInvalidContactsException::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    QList<Contact> m_contacts;
    std::optional<QString> m_parameter;
    std::optional<QList<EDAMInvalidContactReason>> m_reasons;
};

class Q_DECL_HIDDEN EDAMInvalidContactsExceptionData::Impl final:
    public QSharedData
{
public:
    Impl() = default;
    Impl(const EDAMInvalidContactsExceptionData::Impl & other) = default;
    Impl(EDAMInvalidContactsExceptionData::Impl && other) noexcept = default;

    EDAMInvalidContactsExceptionData::Impl & operator=(const EDAMInvalidContactsExceptionData::Impl & other) = delete;
    EDAMInvalidContactsExceptionData::Impl & operator=(EDAMInvalidContactsExceptionData::Impl && other) = delete;

    ~Impl() noexcept = default;

    QList<Contact> m_contacts;
    std::optional<QString> m_parameter;
    std::optional<QList<EDAMInvalidContactReason>> m_reasons;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONIMPL_H
