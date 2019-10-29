/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "AsyncResult_p.h"
#include "Http.h"

#include <AsyncResult.h>
#include <EventLoopFinisher.h>

#include <QEventLoop>
#include <QSignalMapper>

#include <typeinfo>

namespace qevercloud {

QVariant AsyncResult::asIs(QByteArray replyData)
{
    return replyData;
}

AsyncResult::AsyncResult(
        QString url, QByteArray postData, qint64 timeoutMsec,
        AsyncResult::ReadFunctionType readFunction, bool autoDelete,
        QObject * parent) :
    QObject(parent),
    d_ptr(new AsyncResultPrivate(
        url, postData, timeoutMsec, readFunction, autoDelete, this))
{
    if (!url.isEmpty()) {
        QMetaObject::invokeMethod(d_ptr, "start", Qt::QueuedConnection);
    }
}

AsyncResult::AsyncResult(
        QNetworkRequest request, QByteArray postData, qint64 timeoutMsec,
        qevercloud::AsyncResult::ReadFunctionType readFunction, bool autoDelete,
        QObject * parent) :
    QObject(parent),
    d_ptr(new AsyncResultPrivate(
        request, postData, timeoutMsec, readFunction, autoDelete, this))
{
    QMetaObject::invokeMethod(d_ptr, "start", Qt::QueuedConnection);
}

AsyncResult::AsyncResult(QVariant result, EverCloudExceptionDataPtr error,
                         bool autoDelete, QObject * parent) :
    QObject(parent),
    d_ptr(new AsyncResultPrivate(result, error, autoDelete, this))
{}

AsyncResult::~AsyncResult()
{
    delete d_ptr;
}

bool AsyncResult::waitForFinished(int timeout)
{
    QEventLoop loop;
    QObject::connect(this,
                     SIGNAL(finished(QVariant,EverCloudExceptionDataPtr)),
                     &loop, SLOT(quit()));

    if(timeout >= 0) {
        QTimer timer;
        EventLoopFinisher finisher(&loop, 1);
        connect(&timer, SIGNAL(timeout()), &finisher, SLOT(stopEventLoop()));
        timer.setSingleShot(true);
        timer.setInterval(timeout);
        timer.start();
    }

    bool res = (loop.exec(QEventLoop::ExcludeUserInputEvents) == 0);
    return res;
}

} // namespace qevercloud
