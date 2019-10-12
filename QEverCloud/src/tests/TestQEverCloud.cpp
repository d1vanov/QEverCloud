/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "TestQEverCloud.h"

namespace qevercloud {

TestEverCloudTest::TestEverCloudTest(QObject * parent) :
    QObject(parent)
{}

} // namespace qevercloud

#if QT_VERSION < QT_VERSION_CHECK(5, 6, 0)
#ifdef QT_GUI_LIB
#undef QT_GUI_LIB
QTEST_MAIN(qevercloud::TestEverCloudTest)
#define QT_GUI_LIB
#endif // QT_GUI_LIB
#else
QTEST_GUILESS_MAIN(qevercloud::TestEverCloudTest)
#endif
