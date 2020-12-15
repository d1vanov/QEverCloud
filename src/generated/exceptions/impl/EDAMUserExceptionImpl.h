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

#ifndef QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONIMPL_H
#define QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONIMPL_H

#include <qevercloud/generated/exceptions/EDAMUserException.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMUserException::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const EDAMUserException::Impl & other) = default;
    Impl(EDAMUserException::Impl && other) noexcept = default;

    EDAMUserException::Impl & operator=(const EDAMUserException::Impl & other) = delete;
    EDAMUserException::Impl & operator=(EDAMUserException::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const EDAMUserException::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const EDAMUserException::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    EDAMErrorCode m_errorCode = EDAMErrorCode::UNKNOWN;
    std::optional<QString> m_parameter;
};

class Q_DECL_HIDDEN EDAMUserExceptionData::Impl final:
    public QSharedData
{
public:
    Impl() = default;
    Impl(const EDAMUserExceptionData::Impl & other) = default;
    Impl(EDAMUserExceptionData::Impl && other) noexcept = default;

    explicit Impl(
        EDAMErrorCode errorCode,
        std::optional<QString> parameter) :
        m_errorCode(std::move(errorCode)),
        m_parameter(std::move(parameter))
    {}

    EDAMUserExceptionData::Impl & operator=(const EDAMUserExceptionData::Impl & other) = delete;
    EDAMUserExceptionData::Impl & operator=(EDAMUserExceptionData::Impl && other) = delete;

    ~Impl() noexcept = default;

    EDAMErrorCode m_errorCode;
    std::optional<QString> m_parameter;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMUSEREXCEPTIONIMPL_H