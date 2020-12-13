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

#ifndef QEVERCLOUD_GENERATED_LAZYMAP_H
#define QEVERCLOUD_GENERATED_LAZYMAP_H

#include "../../Export.h"

#include "QMap"
#include "QSet"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/Printable.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <optional>

namespace qevercloud {

/**
 * A structure that wraps a map of name/value pairs whose values are not
 * always present in the structure in order to reduce space when obtaining
 * batches of entities that contain the map.
 *
 * When the server provides the client with a LazyMap, it will fill in either
 * the keysOnly field or the fullMap field, but never both, based on the API
 * and parameters.
 *
 * When a client provides a LazyMap to the server as part of an update to
 * an object, the server will only update the LazyMap if the fullMap field is
 * set. If the fullMap field is not set, the server will not make any changes
 * to the map.
 *
 * Check the API documentation of the individual calls involving the LazyMap
 * for full details including the constraints of the names and values of the
 * map.
 *
 * */
class QEVERCLOUD_EXPORT LazyMap: public Printable
{
    Q_GADGET
public:
    LazyMap();
    LazyMap(const LazyMap & other);
    LazyMap(LazyMap && other) noexcept;
    ~LazyMap() noexcept override;

    LazyMap & operator=(const LazyMap & other);
    LazyMap & operator=(LazyMap && other) noexcept;

    /**
    The set of keys for the map.  This field is ignored by the
           server when set.
    */
    [[nodiscard]] const std::optional<QSet<QString>> & keysOnly() const noexcept;
    [[nodiscard]] std::optional<QSet<QString>> & mutableKeysOnly();
    void setKeysOnly(std::optional<QSet<QString>> keysOnly);

    /**
    The complete map, including all keys and values.
    */
    [[nodiscard]] const std::optional<QMap<QString, QString>> & fullMap() const noexcept;
    [[nodiscard]] std::optional<QMap<QString, QString>> & mutableFullMap();
    void setFullMap(std::optional<QMap<QString, QString>> fullMap);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const LazyMap & other) const noexcept;
    [[nodiscard]] bool operator!=(const LazyMap & other) const noexcept;

    using FullMap = QMap<QString, QString>;

    Q_PROPERTY(std::optional<QSet<QString>> keysOnly READ keysOnly WRITE setKeysOnly)
    Q_PROPERTY(std::optional<FullMap> fullMap READ fullMap WRITE setFullMap)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::LazyMap)

#endif // QEVERCLOUD_GENERATED_LAZYMAP_H
