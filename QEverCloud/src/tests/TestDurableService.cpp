/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "TestDurableService.h"

#include <DurableService.h>

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

} // namespace qevercloud
