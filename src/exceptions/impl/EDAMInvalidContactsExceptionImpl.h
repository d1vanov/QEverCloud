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

#ifndef QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONIMPL
#define QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONIMPL

#include <qevercloud/exceptions/EDAMInvalidContactsException.h>
#include <QSharedData>
#include <string>

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

    void print(QTextStream & strm) const override;

    QList<Contact> m_contacts;
    std::optional<QString> m_parameter;
    std::optional<QList<EDAMInvalidContactReason>> m_reasons;
    std::string m_strMessage;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTIONIMPL
