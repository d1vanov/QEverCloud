/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_INK_NOTE_IMAGE_DOWNLOADER_TESTER_H
#define QEVERCLOUD_TEST_INK_NOTE_IMAGE_DOWNLOADER_TESTER_H

#include <QObject>

namespace qevercloud {

class InkNoteImageDownloaderTester : public QObject
{
    Q_OBJECT
public:
    explicit InkNoteImageDownloaderTester(QObject * parent = nullptr);

private Q_SLOTS:
    void downloadInkNoteImageWithSingleStripeSynchronously();
    void downloadInkNoteImageWithSingleStripeAsynchronously();
    void downloadInkNoteImageWithSeveralStripesSynchronously();
    void downloadInkNoteImageWithSeveralStripesAsynchronously();
};

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_INK_NOTE_IMAGE_DOWNLOADER_TESTER_H
