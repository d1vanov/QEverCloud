/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_TEST_NOTE_THUMBNAIL_DOWNLOADER_TESTER_H
#define QEVERCLOUD_TEST_NOTE_THUMBNAIL_DOWNLOADER_TESTER_H

#include <QByteArray>
#include <QObject>

class QTcpServer;

namespace qevercloud {

class NoteThumbnailDownloaderTester : public QObject
{
    Q_OBJECT
public:
    explicit NoteThumbnailDownloaderTester(QObject * parent = nullptr);

private Q_SLOTS:
    void initTestCase();

    void downloadNotePngThumbnailSynchronously();
    void downloadNoteJpegThumbnailSynchronously();
    void downloadNoteGifThumbnailSynchronously();
    void downloadNoteBmpThumbnailSynchronously();

    void downloadNotePngThumbnailAsynchronously();
    void downloadNoteJpegThumbnailAsynchronously();
    void downloadNoteGifThumbnailAsynchronously();
    void downloadNoteBmpThumbnailAsynchronously();

    void downloadResourcePngThumbnailSynchronously();
    void downloadResourceJpegThumbnailSynchronously();
    void downloadResourceGifThumbnailSynchronously();
    void downloadResourceBmpThumbnailSynchronously();

    void downloadResourcePngThumbnailAsynchronously();
    void downloadResourceJpegThumbnailAsynchronously();
    void downloadResourceGifThumbnailAsynchronously();
    void downloadResourceBmpThumbnailAsynchronously();

private:
    [[nodiscard]] quint16 setupServer(
        QTcpServer & tcpServer, QByteArray & requestBody, QString urlPart,
        QString extension);

    void runDownloadSynchronouslyTest(QString urlPart, QString extension);
    void runDownloadAsynchronouslyTest(QString urlPart, QString extension);

private:
    QByteArray m_thumbnailData;

    QString m_shardId;
    QString m_guid;
    QString m_authToken;
};

} // namespace qevercloud

#endif // QEVERCLOUD_TEST_NOTE_THUMBNAIL_DOWNLOADER_TESTER_H
