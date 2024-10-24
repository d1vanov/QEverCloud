/**
 * Copyright (c) 2016-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_I_INK_NOTE_IMAGE_DOWNLOADER_H
#define QEVERCLOUD_I_INK_NOTE_IMAGE_DOWNLOADER_H

#include <qevercloud/Export.h>
#include <qevercloud/Fwd.h>
#include <qevercloud/Types.h>

#include <QByteArray>
#include <QFuture>
#include <QNetworkAccessManager>
#include <QSize>
#include <QString>

namespace qevercloud {

/**
 * @brief the InkNoteImageDownloader class is for downloading the images of ink
 * notes which can be created with the official Evernote client on Windows
 * (only with it, at least at the time of this writing).
 *
 * On all other platforms the most one can get instead of the actual ink note
 * is its non-editable image. This class retrieves just these, exclusively in
 * PNG format.
 *
 * NOTE: almost the entirety of this class' content represents an ad-hoc solution
 * to a completely undocumented feature of Evernote service. A very small glimpse
 * of information was once available on Evernote forums but it's deleted now...
 * I collected an even smaller glimpse of information in this SO question:
 * https://stackoverflow.com/q/39179012/1217285. For all practical purposes
 * it is the only piece of information on this feature in existence now.
 */
class QEVERCLOUD_EXPORT IInkNoteImageDownloader
{
public:
    virtual ~IInkNoteImageDownloader() noexcept;

    /**
     * @brief Synchronously downloads image for an ink note.
     * @throw Exception in case of failure to download the image.
     *
     * @warning Unlike most methods of QEverCloud services this method doesn't
     * perform retries in case of network failures!
     *
     * @param guid          Guid of the ink note's resource
     * @param size          Size of the ink note's resource
     * @param ctx           Request context. If not set, the default context
     *                      passed to newInkNoteImageDownloader is used.
     *                      For non-public notes request context needs to be
     *                      present either way and to contain valid
     *                      authentication token
     * @return downloaded data.
     */
    [[nodiscard]] virtual QByteArray download(
        Guid guid, QSize size, IRequestContextPtr ctx = {}) = 0;

    /**
     * @brief Asynchronously downloads image for an ink note.
     *
     * @warning Unlike most methods of QEverCloud services this method doesn't
     * perform retries in case of network failures!
     *
     * @param guid          Guid of the ink note's resource
     * @param size          Size of the ink note's resource
     * @param ctx           Request context. If not set, the default context
     *                      passed to newInkNoteImageDownloader is used.
     *                      For non-public notes request context needs to be
     *                      present either way and to contain valid
     *                      authentication token
     * @return future with downloaded data or exception in case of error.
     */
    [[nodiscard]] virtual QFuture<QByteArray> downloadAsync(
        Guid guid, QSize size, IRequestContextPtr ctx = {}) = 0;
};

/**
 * @brief Creates ink note image downloader instance
 * @param host      www.evernote.com or sandbox.evernote.com or app.yinxiang.com
 * @param shardId   Shard id received either from UserStore service or as a
 *                  result of authentication.
 * @param ctx       Request context. It would be used if no request context is
 *                  provided in the calls to methods of IInkNoteImageDownloader
 */
[[nodiscard]] QEVERCLOUD_EXPORT IInkNoteImageDownloaderPtr newInkNoteImageDownloader(
    QString host, QString shardId, IRequestContextPtr ctx = {});

} // namespace qevercloud

#endif // QEVERCLOUD_I_INK_NOTE_IMAGE_DOWNLOADER_H