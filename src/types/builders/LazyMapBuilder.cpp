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

#include <qevercloud/types/builders/LazyMapBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN LazyMapBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QSet<QString>> m_keysOnly;
    std::optional<QMap<QString, QString>> m_fullMap;
};

LazyMapBuilder::LazyMapBuilder() :
    d(new LazyMapBuilder::Impl)
{}

LazyMapBuilder::LazyMapBuilder(LazyMapBuilder && other) noexcept :
    d{std::move(other.d)}
{}

LazyMapBuilder::~LazyMapBuilder() noexcept = default;

LazyMapBuilder & LazyMapBuilder::operator=(LazyMapBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

LazyMapBuilder & LazyMapBuilder::setKeysOnly(std::optional<QSet<QString>> keysOnly)
{
    d->m_keysOnly = std::move(keysOnly);
    return *this;
}

LazyMapBuilder & LazyMapBuilder::setFullMap(std::optional<QMap<QString, QString>> fullMap)
{
    d->m_fullMap = std::move(fullMap);
    return *this;
}

LazyMap LazyMapBuilder::build()
{
    LazyMap result;

    result.setKeysOnly(std::move(d->m_keysOnly));
    result.setFullMap(std::move(d->m_fullMap));

    d->m_keysOnly = {};
    d->m_fullMap = {};

    return result;
}

} // namespace qevercloud
