/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/INoteThumbnailDownloader.h>

#include "NoteThumbnailDownloader.h"

#include <qevercloud/Fwd.h>
#include <qevercloud/RequestContext.h>

namespace qevercloud {

namespace {

template <class T>
void printImageType(T & strm, const INoteThumbnailDownloader::ImageType type)
{
    switch (type)
    {
    case INoteThumbnailDownloader::ImageType::PNG:
        strm << "PNG";
        break;
    case INoteThumbnailDownloader::ImageType::JPEG:
        strm << "JPEG";
        break;
    case INoteThumbnailDownloader::ImageType::GIF:
        strm << "GIF";
        break;
    case INoteThumbnailDownloader::ImageType::BMP:
        strm << "BMP";
        break;
    }
}

} // namespace

INoteThumbnailDownloader::~INoteThumbnailDownloader() noexcept = default;

INoteThumbnailDownloaderPtr newNoteThumbnailDownloader(
    QString host, QString shardId, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = newRequestContext();
    }

    return std::make_shared<NoteThumbnailDownloader>(
        std::move(host), std::move(shardId), std::move(ctx));
}

QTextStream & operator<<(
    QTextStream & strm, const INoteThumbnailDownloader::ImageType type)
{
    printImageType<QTextStream>(strm, type);
    return strm;
}

QDebug & operator<<(
    QDebug & dbg, const INoteThumbnailDownloader::ImageType type)
{
    printImageType<QDebug>(dbg, type);
    return dbg;
}

} // namespace qevercloud
