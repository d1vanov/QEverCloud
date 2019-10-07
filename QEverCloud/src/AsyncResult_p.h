/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_ASYNC_RESULT_PRIVATE_H
#define QEVERCLOUD_ASYNC_RESULT_PRIVATE_H

#include <AsyncResult.h>

namespace qevercloud {

class AsyncResultPrivate: public QObject
{
    Q_OBJECT
public:
    explicit AsyncResultPrivate(bool autoDelete, AsyncResult * q);

    explicit AsyncResultPrivate(QString url, QByteArray postData,
                                AsyncResult::ReadFunctionType readFunction,
                                bool autoDelete, AsyncResult * q);

    explicit AsyncResultPrivate(QNetworkRequest request, QByteArray postData,
                                AsyncResult::ReadFunctionType readFunction,
                                bool autoDelete, AsyncResult * q);

    virtual ~AsyncResultPrivate();

Q_SIGNALS:
    void finished(QVariant result, QSharedPointer<EverCloudExceptionData> error);

public Q_SLOTS:
    void start();

    void onReplyFetched(QObject * rp);

    void setValue(QVariant result, QSharedPointer<EverCloudExceptionData> error);

public:
    QNetworkRequest                 m_request;
    QByteArray                      m_postData;
    AsyncResult::ReadFunctionType   m_readFunction;
    bool                            m_autoDelete;

private:
    AsyncResult * const q_ptr;
    Q_DECLARE_PUBLIC(AsyncResult)
};

} // namespace qevercloud

#endif // QEVERCLOUD_ASYNC_RESULT_PRIVATE_H
