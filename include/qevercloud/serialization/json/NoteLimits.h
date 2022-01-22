/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SERIALIZATION_JSON_NOTELIMITS
#define QEVERCLOUD_GENERATED_SERIALIZATION_JSON_NOTELIMITS

#include <qevercloud/Export.h>

#include <qevercloud/types/NoteLimits.h>
#include <QJsonObject>
#include <optional>

namespace qevercloud {

[[nodiscard]] QEVERCLOUD_EXPORT QJsonObject serializeToJson(
    const NoteLimits & value);

[[nodiscard]] QEVERCLOUD_EXPORT bool deserializeFromJson(
    const QJsonObject & object, NoteLimits & value);

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SERIALIZATION_JSON_NOTELIMITS
