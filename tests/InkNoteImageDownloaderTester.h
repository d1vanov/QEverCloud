/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_INK_NOTE_IMAGE_DOWNLOADER_TESTER_H
#define QEVERCLOUD_TEST_INK_NOTE_IMAGE_DOWNLOADER_TESTER_H

#include <QByteArray>
#include <QImage>
#include <QObject>

namespace qevercloud {

class InkNoteImageDownloaderTester : public QObject
{
    Q_OBJECT
public:
    explicit InkNoteImageDownloaderTester(QObject * parent = nullptr);

private Q_SLOTS:
    void initTestCase();

    void downloadInkNoteImageWithSingleStripeSynchronously();
    void downloadInkNoteImageWithSingleStripeAsynchronously();
    void downloadInkNoteImageWithSeveralStripesSynchronously();
    void downloadInkNoteImageWithSeveralStripesAsynchronously();

private:
    QByteArray m_stripesImageData;
    QImage m_stripesImage;

    QString m_shardId;
    QString m_guid;
    QString m_authToken;
};

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_INK_NOTE_IMAGE_DOWNLOADER_TESTER_H
