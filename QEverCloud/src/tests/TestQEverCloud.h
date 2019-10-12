/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_QEVERCLOUD_H
#define QEVERCLOUD_TEST_QEVERCLOUD_H

#include <QtTest>

#ifdef QEVERCLOUD_SHARED_LIBRARY
#undef QEVERCLOUD_SHARED_LIBRARY
#endif

#ifdef QEVERCLOUD_STATIC_LIBRARY
#undef QEVERCLOUD_STATIC_LIBRARY
#endif

namespace qevercloud {

class TestEverCloudTest: public QObject
{
    Q_OBJECT
public:
    TestEverCloudTest(QObject * parent = nullptr);

private Q_SLOTS:
    void testOptional();
};

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_QEVERCLOUD_H
