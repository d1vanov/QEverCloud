/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "TestDurableService.h"
#include "TestOptional.h"

#include <QtTest/QtTest>

using namespace qevercloud;

int main(int argc, char *argv[])
{
    int res = 0;

#define RUN_TESTS(tester)                                                      \
    res = QTest::qExec(new tester);                                            \
    if (res != 0) {                                                            \
        return res;                                                            \
    }                                                                          \
// RUN_TESTS

    RUN_TESTS(DurableServiceTester)
    RUN_TESTS(OptionalTester)
}
