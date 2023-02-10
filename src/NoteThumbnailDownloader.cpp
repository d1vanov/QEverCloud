/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "NoteThumbnailDownloader.h"

#include "Http.h"
#include "QtFutureContinuations.h"

#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/RequestContext.h>
#include <qevercloud/utility/Log.h>

#include <QtGlobal>

namespace qevercloud {

[[nodiscard]] QString toString(
    const INoteThumbnailDownloader::ImageType imageType)
{
    switch (imageType) {
    case INoteThumbnailDownloader::ImageType::PNG:
        return QStringLiteral("PNG");
    case INoteThumbnailDownloader::ImageType::JPEG:
        return QStringLiteral("JPEG");
    case INoteThumbnailDownloader::ImageType::GIF:
        return QStringLiteral("GIF");
    case INoteThumbnailDownloader::ImageType::BMP:
        return QStringLiteral("BMP");
    }

    Q_ASSERT_X(false, "NoteThumbnailDownloader", "Unreachable code");
    return QString{};
}

NoteThumbnailDownloader::NoteThumbnailDownloader(
    QString host, QString shardId, IRequestContextPtr ctx) :
    m_host{std::move(host)},
    m_shardId{std::move(shardId)},
    m_ctx{std::move(ctx)}
{
    Q_ASSERT_X(
        m_ctx,
        "NoteThumbnailDownloader",
        "Null request context passed to NoteThumbnailDownloader");
}

QByteArray NoteThumbnailDownloader::downloadNoteThumbnail(
    Guid guid, const int size, const ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    return downloadThumbnail(
        std::move(guid), GuidKind::Note, size, imageType, std::move(ctx));
}

QByteArray NoteThumbnailDownloader::downloadResourceThumbnail(
    Guid guid, const int size, const ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    return downloadThumbnail(
        std::move(guid), GuidKind::Resource, size, imageType, std::move(ctx));
}

QFuture<QByteArray> NoteThumbnailDownloader::downloadNoteThumbnailAsync(
    Guid guid, const int size, const ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    return downloadThumbnailAsync(
        std::move(guid), GuidKind::Note, size, imageType, std::move(ctx));
}

QFuture<QByteArray> NoteThumbnailDownloader::downloadResourceThumbnailAsync(
    Guid guid, const int size, const ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    return downloadThumbnailAsync(
        std::move(guid), GuidKind::Resource, size, imageType, std::move(ctx));
}

std::pair<QNetworkRequest, QByteArray> NoteThumbnailDownloader::createPostRequest(
    const qevercloud::Guid & guid, GuidKind guidKind, const ImageType imageType,
    const int size, const QString & authToken)
{
    QNetworkRequest request;

    QString scheme = m_host.startsWith(QStringLiteral("http"))
        ? QString{}
        : QStringLiteral("https://");

    QString guidKindStr = guidKind == GuidKind::Resource
        ? QStringLiteral("res")
        : QStringLiteral("note");

    QString urlPattern = QStringLiteral("%1%2/shard/%3/thm/%4/%5");
    QString url = urlPattern.arg(scheme, m_host, m_shardId, guidKindStr, guid);

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

    // not QByteArray()! or else ReplyFetcher will not work.
    QByteArray postData = "";
    if (!authToken.isEmpty()) {
        postData = QByteArray("auth=") +
            QUrl::toPercentEncoding(authToken);
    }

    return std::make_pair(request, postData);
}

QByteArray NoteThumbnailDownloader::downloadThumbnail(
    Guid guid, const GuidKind guidKind, int size, ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = m_ctx;
    }

    Q_ASSERT(ctx);

    QEC_DEBUG(
        "NoteThumbnailDownloader",
        "Downloading thumbnail image: guid = " << guid << ", "
            << (ctx->authenticationToken().isEmpty()
                ? "public" : "non-public")
            << ", image type = " << toString(imageType)
            << ", guid kind = "
            << (guidKind == GuidKind::Note ? "note" : "resource"));

    auto pair = createPostRequest(
        guid, guidKind, imageType, size, ctx->authenticationToken());

    QEC_DEBUG(
        "NoteThumbnailDownloader",
        "Sending thumbnail download request to url: "
            << pair.first.url());

    int httpStatusCode = 0;
    QByteArray reply = simpleDownload(
        std::move(pair.first),
        ctx->requestTimeout(),
        std::move(pair.second),
        &httpStatusCode);

    if (httpStatusCode != 200) {
        QEC_WARNING(
            "NoteThumbnailDownloader",
            "Failed to download thumbnail: "
                << "guid  = " << guid << ", "
                << (ctx->authenticationToken().isEmpty()
                    ? "public" : "non-public")
                << ", image type = "
                << toString(imageType)
                << ", guid kind = "
                << (guidKind == GuidKind::Note ? "note" : "resource"));

        throw EverCloudException(QString::fromUtf8(
            "Failed to download thumbnail, HTTP Status Code = %1")
            .arg(httpStatusCode));
    }

    QEC_DEBUG(
        "NoteThumbnailDownloader",
        "Finished thumbnail download for guid "
            << guid << ", " << (ctx->authenticationToken().isEmpty()
                ? "public" : "non-public")
            << ", image type = " << toString(imageType)
            << ", guid kind = "
            << (guidKind == GuidKind::Note ? "note" : "resource"));
    return reply;
}

QFuture<QByteArray> NoteThumbnailDownloader::downloadThumbnailAsync(
    Guid guid, GuidKind guidKind, int size, ImageType imageType,
    qevercloud::IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = m_ctx;
    }

    Q_ASSERT(ctx);

    QEC_DEBUG(
        "NoteThumbnailDownloader",
        "Async downloading thumbnail image: guid = " << guid << ", "
            << (ctx->authenticationToken().isEmpty()
                ? "public" : "non-public")
            << ", image type = "
            << toString(imageType)
            << ", guid kind = "
            << (guidKind == GuidKind::Note ? "note" : "resource"));

    auto promise = std::make_shared<QPromise<QByteArray>>();
    auto future = promise->future();
    promise->start();

    auto pair = createPostRequest(
        guid, guidKind, imageType, size, ctx->authenticationToken());

    QEC_DEBUG(
        "NoteThumbnailDownloader",
        "Sending thumbnail download request to url: "
            << pair.first.url());

    auto requestFuture =
        sendRequest(pair.first, pair.second, ctx);

    auto requestThenFuture = then(
        std::move(requestFuture),
        [promise, guid = std::move(guid), ctx = std::move(ctx),
         imageType, guidKind](const QVariant & data) mutable
        {
            QEC_DEBUG(
                "NoteThumbnailDownloader",
                "Finished async downloading thumbnail image: guid = " << guid
                    << ", " << (ctx->authenticationToken().isEmpty()
                        ? "public" : "non-public")
                    << ", image type = " << toString(imageType)
                    << ", guid kind = "
                    << (guidKind == GuidKind::Note ? "note" : "resource"));

            QByteArray reply = data.toByteArray();
            promise->addResult(std::move(reply));
            promise->finish();
        });

    onFailed(
        std::move(requestThenFuture),
        [promise](const QException & e)
        {
            promise->setException(e);
            promise->finish();
        });

    return future;
}

} // namespace qevercloud
