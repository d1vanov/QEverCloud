/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_I_NOTE_THUMBNAIL_DOWNLOADER_H
#define QEVERCLOUD_I_NOTE_THUMBNAIL_DOWNLOADER_H

#include <qevercloud/Export.h>
#include <qevercloud/Fwd.h>
#include <qevercloud/types/TypeAliases.h>

#include <QByteArray>
#include <QFuture>

namespace qevercloud {

/**
 * @brief The INoteThumbnailDownloader class represents the interface for
 * downloading of note thumbnail images
 */
class QEVERCLOUD_EXPORT INoteThumbnailDownloader
{
public:
    virtual ~INoteThumbnailDownloader();

    /**
     * Types of note thumbnail images
     */
    enum class ImageType
    {
        PNG,
        JPEG,
        GIF,
        BMP
    };

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const ImageType imageType);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const ImageType imageType);

    /**
     * @brief Synchronously downloads thumbnail image for a note with given guid
     * @throw exception in case of failure to download the thumbnail image.
     *
     * @warning Unlike most methods of QEverCloud services this method doesn't
     * perform retries in case of network failures!
     *
     * @param guid      Guid of note for which thumbnail is downloaded
     * @param size      Size of downloaded thumbnail. Evernote supports values
     *                  from from 1 to 300. Values outside this range would
     *                  likely result in errors
     * @param imageType Type of the thumbnail image to download
     * @param ctx       Request context. If not set, the default context
     *                  passed to newNoteThumbnailDownloader is used.
     *                  For non-public notes request context needs to be present
     *                  either way and to contain valid authentication token
     */
    [[nodiscard]] virtual QByteArray downloadNoteThumbnail(
        Guid guid, int size = 300, ImageType imageType = ImageType::PNG,
        qevercloud::IRequestContextPtr ctx = {}) = 0;

    /**
     * @brief Synchronously downloads thumbnail image for a note with given guid
     * @throw Exception in case of failure to download the thumbnail image.
     *
     * @warning Unlike most methods of QEverCloud services this method doesn't
     * perform retries in case of network failures!
     *
     * @param guid      Guid of resource for which thumbnail is downloaded
     * @param size      Size of downloaded thumbnail. Evernote supports values
     *                  from from 1 to 300. Values outside this range would
     *                  likely result in errors
     * @param imageType Type of the thumbnail image to download
     * @param ctx       Request context. If not set, the default context
     *                  passed to newNoteThumbnailDownloader is used.
     *                  For non-public notes request context needs to be present
     *                  either way and to contain valid authentication token
     */
    [[nodiscard]] virtual QByteArray downloadResourceThumbnail(
        Guid guid, int size = 300, ImageType imageType = ImageType::PNG,
        qevercloud::IRequestContextPtr ctx = {}) = 0;

    /**
     * @brief Asynchronously downloads thumbnail image for a note with given
     *        guid
     * @throw Exception in case of failure to download the thumbnail image.
     *
     * @warning Unlike most methods of QEverCloud services this method doesn't
     * perform retries in case of network failures!
     *
     * @param guid      Guid of note for which thumbnail is downloaded
     * @param size      Size of downloaded thumbnail. Evernote supports values
     *                  from from 1 to 300. Values outside this range would
     *                  likely result in errors
     * @param imageType Type of the thumbnail image to download
     * @param ctx       Request context. If not set, the default context
     *                  passed to newNoteThumbnailDownloader is used.
     *                  For non-public notes request context needs to be present
     *                  either way and to contain valid authentication token
     * @return          Future with downloaded thumbnail image data or exception
     *                  in case of error.
     */
    [[nodiscard]] virtual QFuture<QByteArray> downloadNoteThumbnailAsync(
        Guid guid, int size = 300, ImageType imageType = ImageType::PNG,
        qevercloud::IRequestContextPtr ctx = {}) = 0;

    /**
     * @brief Asynchronously downloads thumbnail image for a resource with given
     *        guid
     * @throw Exception in case of failure to download the thumbnail image.
     *
     * @warning Unlike most methods of QEverCloud services this method doesn't
     * perform retries in case of network failures!
     *
     * @param guid      Guid of resource for which thumbnail is downloaded
     * @param size      Size of downloaded thumbnail. Evernote supports values
     *                  from from 1 to 300. Values outside this range would
     *                  likely result in errors
     * @param imageType Type of the thumbnail image to download
     * @param ctx       Request context. If not set, the default context
     *                  passed to newNoteThumbnailDownloader is used.
     *                  For non-public notes request context needs to be present
     *                  either way and to contain valid authentication token
     * @return          Future with downloaded thumbnail image data or exception
     *                  in case of error.
     */
    [[nodiscard]] virtual QFuture<QByteArray> downloadResourceThumbnailAsync(
        Guid guid, int size = 300, ImageType imageType = ImageType::PNG,
        qevercloud::IRequestContextPtr ctx = {}) = 0;
};

/**
 * @brief Creates note thumbnail image downloader instance
 * @param host      www.evernote.com or sandbox.evernote.com or app.yinxiang.com
 * @param shardId   Shard id received either from UserStore service or as a
 *                  result of authentication.
 * @param ctx       Request context. It would be used if no request context is
 *                  provided in the calls to methods of INoteThumbnailDownloader
 */
[[nodiscard]] INoteThumbnailDownloaderPtr newNoteThumbnailDownloader(
    QString host, QString shardId);

} // namespace qevercloud

#endif // QEVERCLOUD_I_NOTE_THUMBNAIL_DOWNLOADER_H
