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

#include <qevercloud/serialization/json/CreateOrUpdateNotebookSharesResult.h>

#include <qevercloud/serialization/json/SharedNotebook.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const CreateOrUpdateNotebookSharesResult & value)
{
    QJsonObject object;

    if (value.updateSequenceNum()) {
        object[QStringLiteral("updateSequenceNum")] = *value.updateSequenceNum();
    }

    if (value.matchingShares())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.matchingShares()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("matchingShares")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, CreateOrUpdateNotebookSharesResult & value)
{
    if (object.contains(QStringLiteral("updateSequenceNum"))) {
        const auto v = object[QStringLiteral("updateSequenceNum")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUpdateSequenceNum(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("matchingShares"))) {
        const auto v = object[QStringLiteral("matchingShares")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<SharedNotebook> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    SharedNotebook f;
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
            value.setMatchingShares(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
