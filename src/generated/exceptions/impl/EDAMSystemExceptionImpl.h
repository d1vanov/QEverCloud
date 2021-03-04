/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONIMPL_H
#define QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONIMPL_H

#include <qevercloud/generated/exceptions/EDAMSystemException.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMSystemException::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const EDAMSystemException::Impl & other) = default;
    Impl(EDAMSystemException::Impl && other) noexcept = default;

    EDAMSystemException::Impl & operator=(const EDAMSystemException::Impl & other) = delete;
    EDAMSystemException::Impl & operator=(EDAMSystemException::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    EDAMErrorCode m_errorCode = EDAMErrorCode::UNKNOWN;
    std::optional<QString> m_message;
    std::optional<qint32> m_rateLimitDuration;
};

class Q_DECL_HIDDEN EDAMSystemExceptionData::Impl final:
    public QSharedData
{
public:
    Impl() = default;
    Impl(const EDAMSystemExceptionData::Impl & other) = default;
    Impl(EDAMSystemExceptionData::Impl && other) noexcept = default;

    explicit Impl(
        EDAMErrorCode errorCode,
        std::optional<QString> message,
        std::optional<qint32> rateLimitDuration) :
        m_errorCode(std::move(errorCode)),
        m_message(std::move(message)),
        m_rateLimitDuration(std::move(rateLimitDuration))
    {}

    EDAMSystemExceptionData::Impl & operator=(const EDAMSystemExceptionData::Impl & other) = delete;
    EDAMSystemExceptionData::Impl & operator=(EDAMSystemExceptionData::Impl && other) = delete;

    ~Impl() noexcept = default;

    EDAMErrorCode m_errorCode;
    std::optional<QString> m_message;
    std::optional<qint32> m_rateLimitDuration;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONIMPL_H
