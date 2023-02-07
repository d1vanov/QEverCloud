/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "NoteThumbnailDownloader.h"

#include <qevercloud/utility/Log.h>

namespace qevercloud {

NoteThumbnailDownloader::NoteThumbnailDownloader(
    QString host, QString shardId, IRequestContextPtr ctx) :
    m_host{std::move(host)},
    m_shardId{std::move(shardId)},
    m_ctx{std::move(ctx)}
{}

QByteArray NoteThumbnailDownloader::downloadNoteThumbnail(
    Guid guid, int size, ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    // TODO: implement
    return {};
}

QByteArray NoteThumbnailDownloader::downloadResourceThumbnail(
    Guid guid, int size, ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    // TODO: implement
    return {};
}

QFuture<QByteArray> NoteThumbnailDownloader::downloadNoteThumbnailAsync(
    Guid guid, int size, ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    // TODO: implement
    return {};
}

QFuture<QByteArray> NoteThumbnailDownloader::downloadResourceThumbnailAsync(
    Guid guid, int size, ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    // TODO: implement
    return {};
}

std::pair<QNetworkRequest, QByteArray> NoteThumbnailDownloader::createPostRequest(
    const qevercloud::Guid & guid, GuidKind guidKind, const ImageType imageType,
    const int size, const QString & authToken)
{
    QNetworkRequest request;

    QString urlPattern;
    if (guidKind == GuidKind::Resource) {
        urlPattern = QStringLiteral("https://%1/shard/%2/thm/res/%3");
    }
    else {
        urlPattern = QStringLiteral("https://%1/shard/%2/thm/note/%3");
    }

    QString url = urlPattern.arg(m_host, m_shardId, guid);

    QString ext;
    switch(imageType)
    {
    case INoteThumbnailDownloader::ImageType::BMP:
        ext = QStringLiteral(".bmp");
        break;
    case INoteThumbnailDownloader::ImageType::GIF:
        ext = QStringLiteral(".gif");
        break;
    case INoteThumbnailDownloader::ImageType::JPEG:
        ext = QStringLiteral(".jpg");
        break;
    default:
        ext = QStringLiteral(".png");
        break;
    }
    url += ext;

    if (size != 300) {
        url += QString::fromUtf8("?size=%1").arg(size);
    }

    QEC_TRACE(
        "NoteThumbnailDownloader",
        "Sending thumbnail download request: url = " << url);

    request.setUrl(QUrl(url));
    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        QStringLiteral("application/x-www-form-urlencoded"));

    QByteArray postData;
    if (!authToken.isEmpty()) {
        postData = QByteArray("auth=") +
            QUrl::toPercentEncoding(authToken);
    }

    return std::make_pair(request, postData);
}

} // namespace qevercloud
