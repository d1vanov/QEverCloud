/**
 * Copyright (c) 2019-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/exceptions/NetworkException.h>

namespace qevercloud {

NetworkException::NetworkException() :
    m_type(QNetworkReply::UnknownNetworkError)
{}

NetworkException::NetworkException(QNetworkReply::NetworkError type) :
    m_type(type)
{}

NetworkException::NetworkException(
        QNetworkReply::NetworkError type,
        QString message) :
    EverCloudException(message),
    m_type(type)
{}

void NetworkException::raise() const
{
    throw *this;
}

NetworkException * NetworkException::clone() const
{
    return new NetworkException(m_type);
}

NetworkException::~NetworkException() noexcept
{}

bool NetworkException::operator==(const NetworkException & other) const noexcept
{
    return m_type == other.m_type && m_error == other.m_error;
}

bool NetworkException::operator!=(const NetworkException & other) const noexcept
{
    return !operator==(other);
}

QNetworkReply::NetworkError NetworkException::type() const
{
    return m_type;
}

const char * NetworkException::what() const noexcept
{
    if (m_error.isEmpty())
    {
        switch (m_type)
        {
        case QNetworkReply::NoError:
            return "NetworkException: No error";
        case QNetworkReply::ConnectionRefusedError:
            return "NetworkException: Connection refused";
        case QNetworkReply::RemoteHostClosedError:
            return "NetworkException: Remote host closed";
        case QNetworkReply::HostNotFoundError:
            return "NetworkException: Host not found";
        case QNetworkReply::TimeoutError:
            return "NetworkException: The connection to remote host timed out";
        case QNetworkReply::OperationCanceledError:
            return "NetworkException: Operation canceled";
        case QNetworkReply::SslHandshakeFailedError:
            return "NetworkError: SSL handshake failed";
        case QNetworkReply::TemporaryNetworkFailureError:
            return "NetworkError: Temporary network failure";
        case QNetworkReply::NetworkSessionFailedError:
            return "NetworkError: Network session failed";
        case QNetworkReply::BackgroundRequestNotAllowedError:
            return "NetworkError: Background request not allowed";
#if QT_VERSION >= QT_VERSION_CHECK(5, 6, 0)
        case QNetworkReply::TooManyRedirectsError:
            return "NetworkError: Too many redirects";
        case QNetworkReply::InsecureRedirectError:
            return "NetworkError: Insecure redirect";
#endif
        case QNetworkReply::ProxyConnectionRefusedError:
            return "NetworkError: Proxy connection refused";
        case QNetworkReply::ProxyConnectionClosedError:
            return "NetworkError: Proxy connection closed";
        case QNetworkReply::ProxyNotFoundError:
            return "NetworkError: Proxy not found";
        case QNetworkReply::ProxyTimeoutError:
            return "NetworkError: Proxy timeout";
        case QNetworkReply::ProxyAuthenticationRequiredError:
            return "NetworkError: Proxy authentication required";
        case QNetworkReply::ContentAccessDenied:
            return "NetworkError: Content access denied";
        case QNetworkReply::ContentOperationNotPermittedError:
            return "NetworkError: Content operation not permitted";
        case QNetworkReply::ContentNotFoundError:
            return "NetworkError: Content not found";
        case QNetworkReply::AuthenticationRequiredError:
            return "NetworkError: Authentication required";
        case QNetworkReply::ContentReSendError:
            return "NetworkError: Content resend failed";
        case QNetworkReply::ContentConflictError:
            return "NetworkError: Content conflict error";
        case QNetworkReply::ContentGoneError:
            return "NetworkError: Content gone";
        case QNetworkReply::InternalServerError:
            return "NetworkError: Internal server error";
        case QNetworkReply::OperationNotImplementedError:
            return "NetworkError: Operation not implemented error";
        case QNetworkReply::ServiceUnavailableError:
            return "NetworkError: Service unavailable";
        case QNetworkReply::ProtocolUnknownError:
            return "NetworkError: Protocol unknown";
        case QNetworkReply::ProtocolInvalidOperationError:
            return "NetworkError: Protocol invalid operation";
        case QNetworkReply::UnknownNetworkError:
            return "NetworkError: Unknown network";
        case QNetworkReply::UnknownProxyError:
            return "NetworkError: Unknown proxy";
        case QNetworkReply::UnknownContentError:
            return "NetworkError: Unknown content";
        case QNetworkReply::ProtocolFailure:
            return "NetworkError: Protocol failure";
        case QNetworkReply::UnknownServerError:
            return "NetworkError: Unknown server";
        default:
            return "NetworkError: (Invlaid exception type)";
        }
    }
    else
    {
        return m_error.constData();
    }
}

EverCloudExceptionDataPtr NetworkException::exceptionData() const
{
    return std::make_shared<NetworkExceptionData>(
        QString::fromUtf8(what()), type());
}

NetworkExceptionData::NetworkExceptionData(
        QString error,
        QNetworkReply::NetworkError type) :
    EverCloudExceptionData(error),
    m_type(type)
{}

void NetworkExceptionData::throwException() const
{
    throw NetworkException(m_type, errorMessage);
}

} // namespace qevercloud
