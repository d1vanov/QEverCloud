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

#ifndef QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONDATA_H
#define QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONDATA_H

#include <generated/exceptions/EDAMUserException.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMUserException::EDAMUserExceptionData final:
    public QSharedData,
    public Printable
{
public:
    EDAMUserExceptionData() = default;
    EDAMUserExceptionData(const EDAMUserExceptionData & other) = default;
    EDAMUserExceptionData(EDAMUserExceptionData && other) noexcept = default;

    EDAMUserExceptionData & operator=(const EDAMUserExceptionData & other) = delete;
    EDAMUserExceptionData & operator=(EDAMUserExceptionData && other) = delete;

    ~EDAMUserExceptionData() noexcept override = default;

    [[nodiscard]] bool operator==(const EDAMUserExceptionData & other) const noexcept;
    [[nodiscard]] bool operator!=(const EDAMUserExceptionData & other) const noexcept;

    void print(QTextStream & strm) const override;

    EDAMErrorCode m_errorCode = EDAMErrorCode::UNKNOWN;
    std::optional<QString> m_parameter;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONDATA_H
