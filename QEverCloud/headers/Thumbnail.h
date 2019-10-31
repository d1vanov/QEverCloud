/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_THUMBNAIL_H
#define QEVERCLOUD_THUMBNAIL_H

#include "AsyncResult.h"
#include "Export.h"
#include "generated/Types.h"

#include <QByteArray>
#include <QNetworkAccessManager>
#include <QString>

#include <utility>

namespace qevercloud {

/** @cond HIDDEN_SYMBOLS  */
class ThumbnailPrivate;
/** @endcond */

/**
 * @brief The class is for downloading thumbnails for notes and resources from
 * Evernote servers.
 *
 * These thumbnails are not available with general EDAM Thrift interface as
 * explained in the
 * <a href="http://dev.evernote.com/doc/articles/thumbnails.php">documentation.</a>
 *
 * Usage:
@code

Thumbnail thumb("www.evernote.com", sharId, authenticationToken);
QByteArray pngImage = thumb.download(noteGuid);

@endcode
 *
 * By defualt 300x300 PNG images are requested.
 */
class QEVERCLOUD_EXPORT Thumbnail
{
public:
    /**
     * Specifies image type of the returned thumbnail.
     *
     * Can be PNG, JPEG, GIF or BMP.
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
     * @brief Default constructor.
     *
     * host, shardId, authenticationToken have to be specified before calling
     * @link download @endlink or @link createPostRequest @endlink
     */
    Thumbnail();

    /**
     * @brief Constructs Thumbnail.
     * @param host
     * www.evernote.com or sandbox.evernote.com
     * @param shardId
     * You can get the value from UserStore service or as a result of an
     * authentication.
     * @param authenticationToken
     * For working private notes/resources you must supply a valid
     * authentication token.
     * For public resources the value specified is not used.
     * @param size
     * The size of the thumbnail. Evernote supports values from from 1 to 300.
     * By default 300 is used.
     * @param imageType
     * Thumbnail image type. See ImageType. By default PNG is used.
     */
    Thumbnail(QString host, QString shardId, QString authenticationToken,
              int size = 300, ImageType imageType = ImageType::PNG);

    virtual ~Thumbnail();

    /**
     * @param host
     * www.evernote.com or sandbox.evernote.com
     */
    Thumbnail & setHost(QString host);

    /**
     * @param shardId
     * You can get the value from UserStore service or as a result of an
     * authentication.
     */
    Thumbnail & setShardId(QString shardId);

    /**
     * @param authenticationToken
     * For working private notes/resources you must supply a valid
     * authentication token.
     * For public resources the value specified is not used.
     */
    Thumbnail & setAuthenticationToken(QString authenticationToken);

    /**
     * @param size
     * The size of the thumbnail. Evernote supports values from from 1 to 300.
     * By defualt 300 is used.
     */
    Thumbnail & setSize(int size);

    /**
     * @param imageType
     * Thumbnail image type. See ImageType. By default PNG is used.
     */
    Thumbnail & setImageType(ImageType imageType);

    /**
     * @brief Downloads the thumbnail for a resource or a note.
     * @param guid
     * The note or resource guid
     * @param isPublic
     * Specify true for public notes/resources. In this case authentication
     * token is not sent to with the request as it shoud be according to the docs.
     * @param isResourceGuid
     * true if guid denotes a resource and false if it denotes a note.
     * @param timeoutMsec
     * Timeout for download request in milliseconds
     * @return downloaded data.
     *
     */
    QByteArray download(
        Guid guid, const bool isPublic = false, const bool isResourceGuid = false,
        const qint64 timeoutMsec = 30000);

    /** Asynchronous version of @link download @endlink function*/
    AsyncResult * downloadAsync(
        Guid guid, const bool isPublic = false, const bool isResourceGuid = false,
        const qint64 timeoutMsec = 30000);

    /**
     * @brief Prepares a POST request for a thumbnail download.
     * @param guid
     * The note or resource guid
     * @param isPublic
     * Specify true for public notes/resources. In this case authentication
     * token is not sent to with the request as it shoud be according to the docs.
     * @param isResourceGuid
     * true if guid denotes a resource and false if it denotes a note.
     * @return a pair of QNetworkRequest for the POST request and data that must
     * be posted with the request.
     */
    std::pair<QNetworkRequest, QByteArray> createPostRequest(
        qevercloud::Guid guid, bool isPublic = false, bool isResourceGuid = false);

private:
    ThumbnailPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(Thumbnail)
};

} // namespace qevercloud

#endif // QEVERCLOUD_THUMBNAIL_H
