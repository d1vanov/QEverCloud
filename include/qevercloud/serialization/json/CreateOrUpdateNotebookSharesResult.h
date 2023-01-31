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

#ifndef QEVERCLOUD_GENERATED_SERIALIZATION_JSON_CREATEORUPDATENOTEBOOKSHARESRESULT
#define QEVERCLOUD_GENERATED_SERIALIZATION_JSON_CREATEORUPDATENOTEBOOKSHARESRESULT

#include <qevercloud/Export.h>

#include <qevercloud/types/CreateOrUpdateNotebookSharesResult.h>
#include <QJsonObject>
#include <optional>

namespace qevercloud {

[[nodiscard]] QEVERCLOUD_EXPORT QJsonObject serializeToJson(
    const CreateOrUpdateNotebookSharesResult & value);

[[nodiscard]] QEVERCLOUD_EXPORT bool deserializeFromJson(
    const QJsonObject & object, CreateOrUpdateNotebookSharesResult & value);

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SERIALIZATION_JSON_CREATEORUPDATENOTEBOOKSHARESRESULT
