/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_NOTE_THUMBNAIL_DOWNLOADER_H
#define QEVERCLOUD_NOTE_THUMBNAIL_DOWNLOADER_H

#include <qevercloud/INoteThumbnailDownloader.h>

#include <QNetworkRequest>

#include <utility>

namespace qevercloud {

class NoteThumbnailDownloader final : public INoteThumbnailDownloader
{
public:
    NoteThumbnailDownloader(
        QString host, QString shardId, IRequestContextPtr ctx);

public: // INoteThumbnailDownloader
    [[nodiscard]] QByteArray downloadNoteThumbnail(
        Guid guid, int size = 300, ImageType imageType = ImageType::PNG,
        qevercloud::IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QByteArray downloadResourceThumbnail(
        Guid guid, int size = 300, ImageType imageType = ImageType::PNG,
        qevercloud::IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QFuture<QByteArray> downloadNoteThumbnailAsync(
        Guid guid, int size = 300, ImageType imageType = ImageType::PNG,
        qevercloud::IRequestContextPtr ctx = {}) override;

    [[nodiscard]] QFuture<QByteArray> downloadResourceThumbnailAsync(
        Guid guid, int size = 300, ImageType imageType = ImageType::PNG,
        qevercloud::IRequestContextPtr ctx = {}) override;

private:
    enum class GuidKind
    {
        Note,
        Resource
    };

    [[nodiscard]] std::pair<QNetworkRequest, QByteArray> createPostRequest(
        const qevercloud::Guid & guid, GuidKind guidKind,
        const ImageType imageType, const int size,
        const QString & authToken);

    [[nodiscard]] QByteArray downloadThumbnail(
        Guid guid, GuidKind guidKind, int size, ImageType imageType,
        qevercloud::IRequestContextPtr ctx);

    [[nodiscard]] QFuture<QByteArray> downloadThumbnailAsync(
        Guid guid, GuidKind guidKind, int size, ImageType imageType,
        qevercloud::IRequestContextPtr ctx);

private:
    const QString m_host;
    const QString m_shardId;
    const IRequestContextPtr m_ctx;
};

} // namespace qevercloud

#endif // QEVERCLOUD_NOTE_THUMBNAIL_DOWNLOADER_H