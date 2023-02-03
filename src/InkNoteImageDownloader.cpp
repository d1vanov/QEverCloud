/**
 * Copyright (c) 2016-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Http.h"
#include "QtFutureContinuations.h"

#include <qevercloud/InkNoteImageDownloader.h>
#include <qevercloud/RequestContextBuilder.h>
#include <qevercloud/utility/Log.h>

#include <QBuffer>
#include <QImage>
#include <QPainter>
#include <QSize>

#include <memory>
#include <utility>

namespace qevercloud {

namespace {

[[nodiscard]] std::pair<QNetworkRequest, QByteArray> createPostRequest(
    const QString & urlPart, const QString & authToken, const int sliceNumber,
    const bool isPublic = false)
{
    QNetworkRequest request;
    request.setUrl(QUrl(urlPart + QString::number(sliceNumber)));
    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        QStringLiteral("application/x-www-form-urlencoded"));

    // not QByteArray()! or else ReplyFetcher will not work.
    QByteArray postData = "";
    if (!isPublic) {
        postData = QByteArray("auth=") +
            QUrl::toPercentEncoding(authToken);
    }

    return std::make_pair(request, postData);
}

void downloadInkNoteImagePart(
    std::shared_ptr<QPromise<QImage>> promise, QImage currentImage,
    QString urlPart, const bool isPublic, const IRequestContextPtr & ctx,
    int painterPosition = 0, int sliceCounter = 1)
{
    auto postRequest = createPostRequest(
        urlPart, ctx->authenticationToken(), sliceCounter, isPublic);

    QEC_DEBUG("ink_note_image", "Sending download request to url: "
        << postRequest.first.url());

    auto requestFuture =
        sendRequest(postRequest.first, postRequest.second, ctx);

    auto requestThenFuture = then(
        std::move(requestFuture),
        [promise = promise, urlPart = std::move(urlPart),
         currentImage = std::move(currentImage), isPublic, ctx, painterPosition,
         sliceCounter](const QVariant & data) mutable
        {
            QByteArray reply = data.toByteArray();
            QImage replyImagePart;
            Q_UNUSED(replyImagePart.loadFromData(reply, "PNG"))
            if (replyImagePart.isNull()) {
                promise->addResult(std::move(currentImage));
                promise->finish();
                return;
            }

            if (replyImagePart.format() != currentImage.format()) {
                currentImage = currentImage.convertToFormat(
                    replyImagePart.format());
            }

            QRect painterCurrentRect(
                0,
                painterPosition,
                replyImagePart.width(),
                replyImagePart.height());

            painterPosition += replyImagePart.height();

            QPainter painter(&currentImage);
            painter.setRenderHints(QPainter::Antialiasing);
            painter.drawImage(painterCurrentRect, replyImagePart);

            if (painterPosition >= currentImage.height()) {
                promise->addResult(std::move(currentImage));
                promise->finish();
                return;
            }

            // Recursive call with the next slice and updated painter position
            downloadInkNoteImagePart(
                std::move(promise), std::move(currentImage), std::move(urlPart),
                isPublic, ctx, painterPosition, sliceCounter + 1);
        });

    onFailed(
        std::move(requestThenFuture),
        [promise](const QException & e)
        {
            promise->setException(e);
            promise->finish();
        });
}

} // namespace

struct InkNoteImageDownloaderPrivate
{
    [[nodiscard]] QFuture<QImage> downloadInkNoteImage(
        Guid guid, const bool isPublic, const qint64 timeoutMsec)
    {
        QString scheme = m_host.startsWith(QStringLiteral("http"))
            ? QLatin1Literal("")
            : QStringLiteral("https://");

        QString urlPattern = QStringLiteral("%1%2/shard/%3/res/%4.ink?slice=");
        QString urlPart = urlPattern.arg(scheme, m_host, m_shardId, guid);

        auto promise = std::make_shared<QPromise<QImage>>();
        auto future = promise->future();
        promise->start();

        QSize size{m_width, m_height};
        QImage inkNoteImage{size, QImage::Format_RGB32};

        auto ctx = RequestContextBuilder{}
            .setAuthenticationToken(m_authenticationToken)
            .setRequestTimeout(timeoutMsec)
            .build();

        downloadInkNoteImagePart(
            std::move(promise), std::move(inkNoteImage), std::move(urlPart),
            isPublic, std::move(ctx));

        return future;
    }

    QString m_host;
    QString m_shardId;
    QString m_authenticationToken;
    int m_width;
    int m_height;
};

InkNoteImageDownloader::InkNoteImageDownloader() :
    d_ptr(new InkNoteImageDownloaderPrivate)
{}

InkNoteImageDownloader::InkNoteImageDownloader(
        QString host, QString shardId, QString authenticationToken,
        int width, int height) :
    d_ptr(new InkNoteImageDownloaderPrivate)
{
    d_ptr->m_host = host;
    d_ptr->m_shardId = shardId;
    d_ptr->m_authenticationToken = authenticationToken;
    d_ptr->m_width = width;
    d_ptr->m_height = height;
}

InkNoteImageDownloader::~InkNoteImageDownloader()
{
    delete d_ptr;
}

InkNoteImageDownloader & InkNoteImageDownloader::setHost(QString host)
{
    d_ptr->m_host = host;
    return *this;
}

InkNoteImageDownloader & InkNoteImageDownloader::setShardId(QString shardId)
{
    d_ptr->m_shardId = shardId;
    return *this;
}

InkNoteImageDownloader & InkNoteImageDownloader::setAuthenticationToken(
    QString authenticationToken)
{
    d_ptr->m_authenticationToken = authenticationToken;
    return *this;
}

InkNoteImageDownloader & InkNoteImageDownloader::setWidth(int width)
{
    d_ptr->m_width = width;
    return *this;
}

InkNoteImageDownloader & InkNoteImageDownloader::setHeight(int height)
{
    d_ptr->m_height = height;
    return *this;
}

QByteArray InkNoteImageDownloader::download(
    Guid guid, const bool isPublic, const qint64 timeoutMsec)
{
    QEC_DEBUG("ink_note_image", "Downloading ink note image: guid = " << guid
        << (isPublic ? "public" : "non-public"));

    Q_D(InkNoteImageDownloader);

    QSize size(d_ptr->m_width, d_ptr->m_height);
    QImage inkNoteImage(size, QImage::Format_RGB32);

    QString scheme = d->m_host.startsWith(QStringLiteral("http"))
        ? QLatin1Literal("")
        : QStringLiteral("https://");

    QString urlPattern = QStringLiteral("%1%2/shard/%3/res/%4.ink?slice=");
    QString urlPart = urlPattern.arg(scheme, d->m_host, d->m_shardId, guid);

    int painterPosition = 0;
    int sliceCounter = 1;
    while(true)
    {
        int httpStatusCode = 0;
        auto postRequest = createPostRequest(
            urlPart, d->m_authenticationToken, sliceCounter, isPublic);

        QEC_DEBUG("ink_note_image", "Sending download request to url: "
            << postRequest.first.url());

        QByteArray reply = simpleDownload(
            postRequest.first,
            timeoutMsec,
            postRequest.second,
            &httpStatusCode);

        if (httpStatusCode != 200) {
            QEC_WARNING("ink_note_image", "Failed to download slice "
                << sliceCounter << " for guid " << guid
                << ": http status code = " << httpStatusCode);

            throw EverCloudException(
                QStringLiteral("HTTP Status Code = %1").arg(httpStatusCode));
        }

        QImage replyImagePart;
        Q_UNUSED(replyImagePart.loadFromData(reply, "PNG"))
        if (replyImagePart.isNull())
        {
            if (Q_UNLIKELY(inkNoteImage.isNull()))
            {
                QEC_WARNING("ink_note_image", "Failed to read downloaded data "
                    << "as a png image");

                throw EverCloudException(
                    QStringLiteral("Ink note's image part is null before even "
                                   "starting to assemble"));
            }

            break;
        }

        if (replyImagePart.format() != inkNoteImage.format()) {
            inkNoteImage = inkNoteImage.convertToFormat(replyImagePart.format());
        }

        QRect painterCurrentRect(
            0,
            painterPosition,
            replyImagePart.width(),
            replyImagePart.height());

        painterPosition += replyImagePart.height();

        QPainter painter(&inkNoteImage);
        painter.setRenderHints(QPainter::Antialiasing);
        painter.drawImage(painterCurrentRect, replyImagePart);

        if (painterPosition >= size.height()) {
            break;
        }

        ++sliceCounter;
    }

    if (inkNoteImage.isNull()) {
        return QByteArray();
    }

    QByteArray imageData;
    QBuffer buffer(&imageData);
    Q_UNUSED(buffer.open(QIODevice::WriteOnly))
    inkNoteImage.save(&buffer, "PNG");

    QEC_DEBUG("ink_note_image", "Finished download for guid " << guid);
    return imageData;
}

QFuture<QByteArray> InkNoteImageDownloader::downloadAsync(
    Guid guid, const bool isPublic, const qint64 timeoutMsec)
{
    QEC_DEBUG("ink_note_image", "Async downloading ink note image: guid = "
        << guid << ", " << (isPublic ? "public" : "non-public"));

    Q_D(InkNoteImageDownloader);

    auto promise = std::make_shared<QPromise<QByteArray>>();
    auto future = promise->future();
    promise->start();

    auto downloadInkNoteImageFuture = d->downloadInkNoteImage(
        guid, isPublic, timeoutMsec);

    auto downloadInkNoteImageThenFuture = then(
        std::move(downloadInkNoteImageFuture),
        [promise, guid](const QImage & image)
        {
            QByteArray imageData;
            QBuffer buffer(&imageData);
            Q_UNUSED(buffer.open(QIODevice::WriteOnly))
            image.save(&buffer, "PNG");

            QEC_DEBUG("ink_note_image", "Finished download for guid " << guid);
            promise->addResult(std::move(imageData));
            promise->finish();
        });

    onFailed(
        std::move(downloadInkNoteImageThenFuture),
        [promise](const QException & e)
        {
            promise->setException(e);
            promise->finish();
        });

    return future;
}

} // namespace qevercloud
