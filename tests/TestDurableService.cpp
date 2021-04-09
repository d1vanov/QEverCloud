/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "TestDurableService.h"

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include "../src/Qt5Promise.h"
#endif

#include <qevercloud/DurableService.h>
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/NetworkException.h>
#include <qevercloud/exceptions/EDAMUserException.h>
#include <qevercloud/utility/Log.h>

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QPromise>
#endif

#include <QEventLoop>
#include <QFutureWatcher>
#include <QNetworkReply>
#include <QtTest/QtTest>

namespace qevercloud {

DurableServiceTester::DurableServiceTester(QObject * parent) :
    QObject(parent)
{}

void DurableServiceTester::shouldExecuteSyncServiceCall()
{
    auto durableService = newDurableService();

    bool serviceCallDetected = false;
    QVariant value = QStringLiteral("value");

    IDurableService::SyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            serviceCallDetected = true;
            return {value, {}};
        });

    auto result = durableService->executeSyncRequest(
        std::move(request),
        newRequestContext());

    QVERIFY(serviceCallDetected);
    QVERIFY(result.first == value);
    QVERIFY(!result.second);
}

void DurableServiceTester::shouldExecuteAsyncServiceCall()
{
    auto durableService = newDurableService();

    bool serviceCallDetected = false;
    QVariant value = QStringLiteral("value");

    IDurableService::AsyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> QFuture<QVariant> {
            Q_ASSERT(ctx);
            QPromise<QVariant> promise;
            promise.start();
            serviceCallDetected = true;
            promise.addResult(value);
            promise.finish();
            auto future = promise.future();
            return future;
        });

    auto result = durableService->executeAsyncRequest(
        std::move(request),
        newRequestContext());

    QFutureWatcher<QVariant> watcher;
    QEventLoop loop;
    QObject::connect(
        &watcher, &QFutureWatcher<QVariant>::finished, &loop,
        &QEventLoop::quit);

    watcher.setFuture(result);
    loop.exec();

    QVERIFY(serviceCallDetected);
    QVERIFY(result.result() == value);
}

void DurableServiceTester::shouldRetrySyncServiceCalls()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    QVariant value = QStringLiteral("value");

    IDurableService::SyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            if (serviceCallCounter < maxServiceCallCounter)
            {
                EverCloudExceptionDataPtr data;
                try {
                    throw NetworkException(QNetworkReply::TimeoutError);
                }
                catch(const EverCloudException & e) {
                    data = e.exceptionData();
                }

                return {{}, data};
            }

            return {value, {}};
        });

    auto result = durableService->executeSyncRequest(std::move(request), ctx);

    QVERIFY(serviceCallCounter == maxServiceCallCounter);
    QVERIFY(result.first == value);
    QVERIFY(!result.second);
}

void DurableServiceTester::shouldRetryAsyncServiceCalls()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    QVariant value = QStringLiteral("value");

    IDurableService::AsyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> QFuture<QVariant> {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            QPromise<QVariant> promise;
            auto future = promise.future();
            promise.start();

            ++serviceCallCounter;
            if (serviceCallCounter < maxServiceCallCounter)
            {
                promise.setException(NetworkException(QNetworkReply::TimeoutError));
                promise.finish();
                return future;
            }

            promise.addResult(value);
            promise.finish();
            return future;
        });

    auto result = durableService->executeAsyncRequest(
        std::move(request),
        ctx);

    QFutureWatcher<QVariant> watcher;
    QEventLoop loop;
    QObject::connect(
        &watcher, &QFutureWatcher<QVariant>::finished, &loop,
        &QEventLoop::quit);

    watcher.setFuture(result);
    loop.exec();

    QVERIFY(serviceCallCounter == maxServiceCallCounter);
    QVERIFY(result.result() == value);
}

void DurableServiceTester::shouldNotRetrySyncServiceCallMoreThanMaxTimes()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    IDurableService::SyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            EverCloudExceptionDataPtr data;
            try {
                throw NetworkException(QNetworkReply::TimeoutError);
            }
            catch(const EverCloudException & e) {
                data = e.exceptionData();
            }

            return {{}, data};
        });

    auto result = durableService->executeSyncRequest(std::move(request), ctx);

    QVERIFY(serviceCallCounter == maxServiceCallCounter);
    QVERIFY(!result.first.isValid());
    QVERIFY(result.second.get() != nullptr);

    bool exceptionCaught = false;
    try {
        result.second->throwException();
    }
    catch(const NetworkException & e) {
        exceptionCaught = true;
        QVERIFY(e.type() == QNetworkReply::TimeoutError);
    }
    QVERIFY(exceptionCaught);
}

void DurableServiceTester::shouldNotRetryAsyncServiceCallMoreThanMaxTimes()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    IDurableService::AsyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> QFuture<QVariant> {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;

            QPromise<QVariant> promise;
            auto future = promise.future();
            promise.start();
            promise.setException(NetworkException(QNetworkReply::TimeoutError));
            promise.finish();
            return future;
        });

    auto result = durableService->executeAsyncRequest(
        std::move(request),
        ctx);

    bool exceptionCaught = false;
    try
    {
        result.waitForFinished();
    }
    catch (const NetworkException & e)
    {
        exceptionCaught = true;
        QVERIFY(e.type() == QNetworkReply::TimeoutError);
    }
    QVERIFY(exceptionCaught);
}

void DurableServiceTester::shouldNotRetrySyncServiceCallInCaseOfUnretriableError()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    IDurableService::SyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;
            EverCloudExceptionDataPtr data;
            try {
                EDAMUserException e;
                e.setErrorCode(EDAMErrorCode::AUTH_EXPIRED);
                throw e;
            }
            catch(const EverCloudException & e) {
                data = e.exceptionData();
            }

            return {{}, data};
        });

    auto result = durableService->executeSyncRequest(std::move(request), ctx);

    QVERIFY(serviceCallCounter == 1);
    QVERIFY(!result.first.isValid());
    QVERIFY(result.second.get() != nullptr);

    bool exceptionCaught = false;
    try {
        result.second->throwException();
    }
    catch(const EDAMUserException & e) {
        exceptionCaught = true;
        QVERIFY(e.errorCode() == EDAMErrorCode::AUTH_EXPIRED);
    }
    QVERIFY(exceptionCaught);
}

void DurableServiceTester::shouldNotRetryAsyncServiceCallInCaseOfUnretriableError()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_INCREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    IDurableService::AsyncRequest request("request", {},
        [&] (IRequestContextPtr ctx) -> QFuture<QVariant> {
            Q_ASSERT(ctx);
            Q_ASSERT(ctx->maxRequestRetryCount() == maxServiceCallCounter);

            ++serviceCallCounter;

            QPromise<QVariant> promise;
            auto future = promise.future();
            promise.start();

            EDAMUserException e;
            e.setErrorCode(EDAMErrorCode::AUTH_EXPIRED);
            promise.setException(e);

            promise.finish();
            return future;
        });

    auto result = durableService->executeAsyncRequest(
        std::move(request),
        ctx);

    bool exceptionCaught = false;
    try
    {
        result.waitForFinished();
    }
    catch(const EDAMUserException & e) {
        exceptionCaught = true;
        QVERIFY(e.errorCode() == EDAMErrorCode::AUTH_EXPIRED);
    }
    QVERIFY(exceptionCaught);
}

} // namespace qevercloud
