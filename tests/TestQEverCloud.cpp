/**
 * Copyright (c) 2019-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "TestDurableService.h"
#include "TestTypeBuilders.h"
#include "services/TestNoteStore.h"
#include "services/TestUserStore.h"

#include <qevercloud/QEverCloud.h>

#include <QCoreApplication>
#include <QtTest/QtTest>

#include <cstdlib>

using namespace qevercloud;

int main(int argc, char *argv[])
{
    // Fixed seed for rand() calls
    std::srand(1575003691);

    QCoreApplication app(argc, argv);

    setLogger(newStdErrLogger(LogLevel::Error));

    int res = 0;
#define RUN_TESTS(tester)                                                      \
    res = QTest::qExec(new tester);                                            \
    if (res != 0) {                                                            \
        return res;                                                            \
    }                                                                          \
// RUN_TESTS

    RUN_TESTS(DurableServiceTester)
    RUN_TESTS(TypeBuildersTester)
    RUN_TESTS(NoteStoreTester)
    RUN_TESTS(UserStoreTester)

    return 0;
}
