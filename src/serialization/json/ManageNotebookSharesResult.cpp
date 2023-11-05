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

#include <qevercloud/serialization/json/ManageNotebookSharesResult.h>

#include <qevercloud/serialization/json/ManageNotebookSharesError.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const ManageNotebookSharesResult & value)
{
    QJsonObject object;

    if (value.errors())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.errors()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("errors")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ManageNotebookSharesResult & value)
{
    if (object.contains(QStringLiteral("errors"))) {
        const auto v = object[QStringLiteral("errors")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<ManageNotebookSharesError> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    ManageNotebookSharesError f;
                    if (deserializeFromJson(o, f)) {
                        values.push_back(std::move(f));
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setErrors(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
