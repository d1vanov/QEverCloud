/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "AsyncResult_p.h"
#include "Http.h"

#include <Log.h>

namespace qevercloud {

AsyncResultPrivate::AsyncResultPrivate(
        QString url, QByteArray postData, IRequestContextPtr ctx,
        AsyncResult::ReadFunctionType readFunction, bool autoDelete,
        AsyncResult * q) :
    m_request(createEvernoteRequest(url)),
    m_postData(std::move(postData)),
    m_ctx(std::move(ctx)),
    m_readFunction(std::move(readFunction)),
    m_autoDelete(autoDelete),
    q_ptr(q)
{}

AsyncResultPrivate::AsyncResultPrivate(
        QNetworkRequest request, QByteArray postData, IRequestContextPtr ctx,
        AsyncResult::ReadFunctionType readFunction, bool autoDelete,
        AsyncResult * q) :
    m_request(std::move(request)),
    m_postData(std::move(postData)),
    m_ctx(std::move(ctx)),
    m_readFunction(std::move(readFunction)),
    m_autoDelete(autoDelete),
    q_ptr(q)
{}

AsyncResultPrivate::AsyncResultPrivate(
        QVariant result, QSharedPointer<EverCloudExceptionData> error,
        IRequestContextPtr ctx, bool autoDelete, AsyncResult * q) :
    m_ctx(std::move(ctx)),
    m_autoDelete(autoDelete),
    q_ptr(q)
{
    QMetaObject::invokeMethod(this, "setValue", Qt::QueuedConnection,
                              Q_ARG(QVariant, result),
                              Q_ARG(QSharedPointer<EverCloudExceptionData>, error));
}

AsyncResultPrivate::~AsyncResultPrivate()
{}

void AsyncResultPrivate::start()
{
    if (m_request.url().isEmpty() && m_postData.isEmpty()) {
        // No network request to start, will wait for value to be set explicitly
        return;
    }

    ReplyFetcher * replyFetcher = new ReplyFetcher;
    QObject::connect(replyFetcher, &ReplyFetcher::replyFetched,
                     this, &AsyncResultPrivate::onReplyFetched);
    replyFetcher->start(
        evernoteNetworkAccessManager(),
        m_request,
        m_ctx->requestTimeout(),
        m_postData);
}

void AsyncResultPrivate::onReplyFetched(QObject * rp)
{
    QEC_DEBUG("async_result", "received reply for request with id "
        << m_ctx->requestId());

    ReplyFetcher * reply = qobject_cast<ReplyFetcher*>(rp);
    QSharedPointer<EverCloudExceptionData> error;
    QVariant result;

    try
    {
        if (reply->isError())
        {
            error = QSharedPointer<EverCloudExceptionData>::create(
                reply->errorText());
        }
        else if (reply->httpStatusCode() != 200)
        {
            error = QSharedPointer<EverCloudExceptionData>::create(
                QString::fromUtf8("HTTP Status Code = %1")
                .arg(reply->httpStatusCode()));
        }
        else
        {
            result = m_readFunction(reply->receivedData());
        }
    }
    catch(const EverCloudException & e)
    {
        error = e.exceptionData();
    }
    catch(const std::exception & e)
    {
        error = QSharedPointer<EverCloudExceptionData>::create(
            QString::fromUtf8("Exception of type \"%1\" with the message: %2")
            .arg(QString::fromUtf8(typeid(e).name()), QString::fromUtf8(e.what())));
    }
    catch(...)
    {
        error = QSharedPointer<EverCloudExceptionData>::create(
            QStringLiteral("Unknown exception"));
    }

    setValue(result, error);
}

void AsyncResultPrivate::setValue(
    QVariant result, QSharedPointer<EverCloudExceptionData> error)
{
    Q_Q(AsyncResult);
    QObject::connect(this, &AsyncResultPrivate::finished,
                     q, &AsyncResult::finished,
                     Qt::DirectConnection);

    Q_EMIT finished(result, error, m_ctx);

    if (m_autoDelete) {
        q->deleteLater();
    }
}

} // namespace qevercloud
