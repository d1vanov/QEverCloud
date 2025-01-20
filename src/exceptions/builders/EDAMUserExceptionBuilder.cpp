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

#include <qevercloud/exceptions/builders/EDAMUserExceptionBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMUserExceptionBuilder::Impl final:
    public QSharedData
{
public:
    EDAMErrorCode m_errorCode = EDAMErrorCode::UNKNOWN;
    std::optional<QString> m_parameter;
};

EDAMUserExceptionBuilder::EDAMUserExceptionBuilder() :
    d(new EDAMUserExceptionBuilder::Impl)
{}

EDAMUserExceptionBuilder::EDAMUserExceptionBuilder(EDAMUserExceptionBuilder && other) noexcept :
    d{std::move(other.d)}
{}

EDAMUserExceptionBuilder::~EDAMUserExceptionBuilder() noexcept = default;

EDAMUserExceptionBuilder & EDAMUserExceptionBuilder::operator=(EDAMUserExceptionBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

EDAMUserExceptionBuilder & EDAMUserExceptionBuilder::setErrorCode(EDAMErrorCode errorCode)
{
    d->m_errorCode = errorCode;
    return *this;
}

EDAMUserExceptionBuilder & EDAMUserExceptionBuilder::setParameter(std::optional<QString> parameter)
{
    d->m_parameter = std::move(parameter);
    return *this;
}

EDAMUserException EDAMUserExceptionBuilder::build()
{
    EDAMUserException result;

    result.setErrorCode(d->m_errorCode);
    result.setParameter(std::move(d->m_parameter));

    d->m_errorCode = EDAMErrorCode::UNKNOWN;
    d->m_parameter = {};

    return result;
}

} // namespace qevercloud
