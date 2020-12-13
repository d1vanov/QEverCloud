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

#ifndef QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGEIMPL_H
#define QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGEIMPL_H

#include <qevercloud/generated/types/RelatedContentImage.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN RelatedContentImage::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const RelatedContentImage::Impl & other) = default;
    Impl(RelatedContentImage::Impl && other) noexcept = default;

    RelatedContentImage::Impl & operator=(const RelatedContentImage::Impl & other) = delete;
    RelatedContentImage::Impl & operator=(RelatedContentImage::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const RelatedContentImage::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const RelatedContentImage::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_url;
    std::optional<qint32> m_width;
    std::optional<qint32> m_height;
    std::optional<double> m_pixelRatio;
    std::optional<qint32> m_fileSize;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_RELATEDCONTENTIMAGEIMPL_H
