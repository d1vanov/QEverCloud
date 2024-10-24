/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_INK_NOTE_IMAGE_DOWNLOADER_H
#define QEVERCLOUD_INK_NOTE_IMAGE_DOWNLOADER_H

#include <qevercloud/Fwd.h>
#include <qevercloud/IInkNoteImageDownloader.h>

#include <QSize>
#include <QString>

namespace qevercloud {

class InkNoteImageDownloader final : public IInkNoteImageDownloader
{
public:
    InkNoteImageDownloader(
        QString host, QString shardId, IRequestContextPtr ctx);

public: // IInkNoteImageDownloader
    [[nodiscard]] QByteArray download(
        Guid guid, QSize size, IRequestContextPtr ctx) override;

    [[nodiscard]] QFuture<QByteArray> downloadAsync(
        Guid guid, QSize size, IRequestContextPtr ctx) override;

private:
    [[nodiscard]] QFuture<QImage> downloadInkNoteImage(
        Guid guid, QSize size, IRequestContextPtr ctx);

private:
    QString m_host;
    QString m_shardId;
    IRequestContextPtr m_ctx;
};

} // namespace qevercloud

#endif // QEVERCLOUD_INK_NOTE_IMAGE_DOWNLOADER_H