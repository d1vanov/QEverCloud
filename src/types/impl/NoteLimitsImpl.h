/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_NOTELIMITSIMPL
#define QEVERCLOUD_GENERATED_NOTELIMITSIMPL

#include <qevercloud/types/NoteLimits.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteLimits::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteLimits::Impl & other) = default;
    Impl(NoteLimits::Impl && other) noexcept = default;

    NoteLimits::Impl & operator=(const NoteLimits::Impl & other) = delete;
    NoteLimits::Impl & operator=(NoteLimits::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<qint32> m_noteResourceCountMax;
    std::optional<qint64> m_uploadLimit;
    std::optional<qint64> m_resourceSizeMax;
    std::optional<qint64> m_noteSizeMax;
    std::optional<qint64> m_uploaded;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTELIMITSIMPL