/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "TestDurableService.h"

#include <DurableService.h>
#include <Exceptions.h>

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

    auto result = durableService->executeSyncRequest(
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            serviceCallDetected = true;
            return {value, {}};
        },
        newRequestContext());

    QVERIFY(serviceCallDetected);
    QVERIFY(result.first == value);
    QVERIFY(result.second.isNull());
}

void DurableServiceTester::shouldExecuteAsyncServiceCall()
{
    auto durableService = newDurableService();

    bool serviceCallDetected = false;

    AsyncResult * res = new AsyncResult(QString(), QByteArray());
    auto * result = durableService->executeAsyncRequest(
        [&] (IRequestContextPtr ctx) -> AsyncResult* {
            Q_ASSERT(ctx);
            serviceCallDetected = true;
            return res;
        },
        newRequestContext());

    QVERIFY(serviceCallDetected);
    res->deleteLater();
}

void DurableServiceTester::shouldRetrySyncServiceCalls()
{
    auto durableService = newDurableService();

    int serviceCallCounter = 0;
    int maxServiceCallCounter = 3;

    auto ctx = newRequestContext(
        QString(),
        DEFAULT_REQUEST_TIMEOUT_MSEC,
        DEFAULT_REQUEST_TIMEOUT_EXPONENTIAL_ICREASE,
        DEFAULT_MAX_REQUEST_TIMEOUT_MSEC,
        maxServiceCallCounter);

    QVariant value = QStringLiteral("value");

    auto result = durableService->executeSyncRequest(
        [&] (IRequestContextPtr ctx) -> IDurableService::SyncResult {
            Q_ASSERT(ctx);
            ++serviceCallCounter;
            if (serviceCallCounter < maxServiceCallCounter)
            {
                QSharedPointer<EverCloudExceptionData> data;
                try {
                    throw ThriftException(ThriftException::Type::INTERNAL_ERROR);
                }
                catch(const EverCloudException & e) {
                    data = e.exceptionData();
                }

                return {{}, data};
            }

            return {value, {}};
        },
        ctx);

    QVERIFY(serviceCallCounter == maxServiceCallCounter);
    QVERIFY(result.first == value);
    QVERIFY(result.second.isNull());
}

} // namespace qevercloud
