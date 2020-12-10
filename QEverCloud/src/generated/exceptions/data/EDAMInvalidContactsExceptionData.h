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

#ifndef QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONDATA_H
#define QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONDATA_H

#include <generated/exceptions/EDAMInvalidContactsException.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMInvalidContactsException::EDAMInvalidContactsExceptionData final:
    public QSharedData,
    public Printable
{
public:
    EDAMInvalidContactsExceptionData() = default;
    EDAMInvalidContactsExceptionData(const EDAMInvalidContactsExceptionData & other) = default;
    EDAMInvalidContactsExceptionData(EDAMInvalidContactsExceptionData && other) noexcept = default;

    EDAMInvalidContactsExceptionData & operator=(const EDAMInvalidContactsExceptionData & other) = delete;
    EDAMInvalidContactsExceptionData & operator=(EDAMInvalidContactsExceptionData && other) = delete;

    ~EDAMInvalidContactsExceptionData() noexcept override = default;

    [[nodiscard]] bool operator==(const EDAMInvalidContactsExceptionData & other) const noexcept;
    [[nodiscard]] bool operator!=(const EDAMInvalidContactsExceptionData & other) const noexcept;

    void print(QTextStream & strm) const override;

    QList<Contact> m_contacts;
    std::optional<QString> m_parameter;
    std::optional<QList<EDAMInvalidContactReason>> m_reasons;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONDATA_H
