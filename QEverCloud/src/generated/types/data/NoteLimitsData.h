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

#ifndef QEVERCLOUD_GENERATED_NOTELIMITSDATA_H
#define QEVERCLOUD_GENERATED_NOTELIMITSDATA_H

#include <generated/types/NoteLimits.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteLimits::NoteLimitsData final:
    public QSharedData,
    public Printable
{
public:
    NoteLimitsData() = default;
    NoteLimitsData(const NoteLimitsData & other) = default;
    NoteLimitsData(NoteLimitsData && other) noexcept = default;

    NoteLimitsData & operator=(const NoteLimitsData & other) = delete;
    NoteLimitsData & operator=(NoteLimitsData && other) = delete;

    ~NoteLimitsData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteLimitsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteLimitsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<qint32> m_noteResourceCountMax;
    std::optional<qint64> m_uploadLimit;
    std::optional<qint64> m_resourceSizeMax;
    std::optional<qint64> m_noteSizeMax;
    std::optional<qint64> m_uploaded;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTELIMITSDATA_H
