/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_LAZYMAPIMPL_H
#define QEVERCLOUD_GENERATED_LAZYMAPIMPL_H

#include <qevercloud/generated/types/LazyMap.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN LazyMap::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const LazyMap::Impl & other) = default;
    Impl(LazyMap::Impl && other) noexcept = default;

    LazyMap::Impl & operator=(const LazyMap::Impl & other) = delete;
    LazyMap::Impl & operator=(LazyMap::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QSet<QString>> m_keysOnly;
    std::optional<QMap<QString, QString>> m_fullMap;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_LAZYMAPIMPL_H
