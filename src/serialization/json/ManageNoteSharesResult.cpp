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

#include <qevercloud/serialization/json/ManageNoteSharesResult.h>

#include <qevercloud/serialization/json/ManageNoteSharesError.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const ManageNoteSharesResult & value)
{
    QJsonObject object;

    if (value.errors())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.errors()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("errors")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ManageNoteSharesResult & value)
{
    if (object.contains(QStringLiteral("errors"))) {
        const auto v = object[QStringLiteral("errors")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<ManageNoteSharesError> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    ManageNoteSharesError f;
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
