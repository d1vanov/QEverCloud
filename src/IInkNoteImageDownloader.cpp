/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "InkNoteImageDownloader.h"

#include <qevercloud/RequestContext.h>

namespace qevercloud {

IInkNoteImageDownloader::~IInkNoteImageDownloader() noexcept = default;

IInkNoteImageDownloaderPtr newInkNoteImageDownloader(
    QString host, QString shardId, IRequestContextPtr ctx)
{
    if (!ctx) {
        ctx = newRequestContext();
    }

    return std::make_shared<InkNoteImageDownloader>(
        std::move(host), std::move(shardId), std::move(ctx));
}

} // namespace qevercloud
