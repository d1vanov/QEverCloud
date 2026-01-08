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

#ifndef QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONIMPL
#define QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONIMPL

#include <qevercloud/exceptions/EDAMSystemException.h>
#include <QSharedData>
#include <string>

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
    std::string m_strMessage;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTIONIMPL
