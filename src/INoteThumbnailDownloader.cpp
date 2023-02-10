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

} // namespace qevercloud
