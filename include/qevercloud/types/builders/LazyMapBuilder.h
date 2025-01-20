/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_LAZYMAPBUILDER
#define QEVERCLOUD_GENERATED_LAZYMAPBUILDER

#include <qevercloud/Export.h>

#include "QMap"
#include "QSet"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/LazyMap.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT LazyMapBuilder
{
public:
    LazyMapBuilder();

    LazyMapBuilder(LazyMapBuilder && other) noexcept;

    ~LazyMapBuilder() noexcept;

    LazyMapBuilder & operator=(LazyMapBuilder && other) noexcept;

    LazyMapBuilder & setKeysOnly(std::optional<QSet<QString>> keysOnly);
    LazyMapBuilder & setFullMap(std::optional<QMap<QString, QString>> fullMap);

    [[nodiscard]] LazyMap build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_LAZYMAPBUILDER
