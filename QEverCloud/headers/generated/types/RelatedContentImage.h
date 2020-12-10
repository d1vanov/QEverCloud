/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGE_H
#define QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGE_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "TypeAliases.h"
#include <optional>

namespace qevercloud {

/**
 * An external image that can be shown with a related content snippet,
 * usually either a JPEG or PNG image. It is up to the client which image(s) are shown,
 * depending on available screen real estate, resolution and aspect ratio.
 *
 * */
class QEVERCLOUD_EXPORT RelatedContentImage: public Printable
{
    Q_GADGET
public:
    RelatedContentImage();
    RelatedContentImage(const RelatedContentImage & other);
    RelatedContentImage(RelatedContentImage && other) noexcept;
    ~RelatedContentImage() noexcept override;

    RelatedContentImage & operator=(const RelatedContentImage & other);
    RelatedContentImage & operator=(RelatedContentImage && other) noexcept;

    /**
    The external URL of the image
    */
    [[nodiscard]] const std::optional<QString> & url() const noexcept;
    void setUrl(std::optional<QString> url);

    /**
    The width of the image, in pixels.
    */
    [[nodiscard]] const std::optional<qint32> & width() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableWidth();
    void setWidth(std::optional<qint32> width);

    /**
    The height of the image, in pixels.
    */
    [[nodiscard]] const std::optional<qint32> & height() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableHeight();
    void setHeight(std::optional<qint32> height);

    /**
    the pixel ratio (usually either 1.0, 1.5 or 2.0)
    */
    [[nodiscard]] const std::optional<double> & pixelRatio() const noexcept;
    [[nodiscard]] std::optional<double> & mutablePixelRatio();
    void setPixelRatio(std::optional<double> pixelRatio);

    /**
    the size of the image file, in bytes
    */
    [[nodiscard]] const std::optional<qint32> & fileSize() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableFileSize();
    void setFileSize(std::optional<qint32> fileSize);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const RelatedContentImage & other) const noexcept;
    [[nodiscard]] bool operator!=(const RelatedContentImage & other) const noexcept;

    Q_PROPERTY(std::optional<QString> url READ url WRITE setUrl)
    Q_PROPERTY(std::optional<qint32> width READ width WRITE setWidth)
    Q_PROPERTY(std::optional<qint32> height READ height WRITE setHeight)
    Q_PROPERTY(std::optional<double> pixelRatio READ pixelRatio WRITE setPixelRatio)
    Q_PROPERTY(std::optional<qint32> fileSize READ fileSize WRITE setFileSize)

private:
    class RelatedContentImageData;
    QSharedDataPointer<RelatedContentImageData> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::RelatedContentImage)

#endif // QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGE_H
