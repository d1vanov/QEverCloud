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

#ifndef QEVERCLOUD_GENERATED_LAZYMAPDATA_H
#define QEVERCLOUD_GENERATED_LAZYMAPDATA_H

#include <generated/types/LazyMap.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN LazyMap::LazyMapData final:
    public QSharedData,
    public Printable
{
public:
    LazyMapData() = default;
    LazyMapData(const LazyMapData & other) = default;
    LazyMapData(LazyMapData && other) noexcept = default;

    LazyMapData & operator=(const LazyMapData & other) = delete;
    LazyMapData & operator=(LazyMapData && other) = delete;

    ~LazyMapData() noexcept override = default;

    [[nodiscard]] bool operator==(const LazyMapData & other) const noexcept;
    [[nodiscard]] bool operator!=(const LazyMapData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QSet<QString>> m_keysOnly;
    std::optional<QMap<QString, QString>> m_fullMap;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_LAZYMAPDATA_H
