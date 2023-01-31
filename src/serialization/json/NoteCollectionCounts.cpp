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

#include <qevercloud/serialization/json/NoteCollectionCounts.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NoteCollectionCounts & value)
{
    QJsonObject object;

    if (value.notebookCounts())
    {
        QJsonObject subobject;
        for (auto it: toRange(qAsConst(*value.notebookCounts())))
        {
            subobject[it.key()] = it.value();
        }
        object[QStringLiteral("notebookCounts")] = subobject;
    }

    if (value.tagCounts())
    {
        QJsonObject subobject;
        for (auto it: toRange(qAsConst(*value.tagCounts())))
        {
            subobject[it.key()] = it.value();
        }
        object[QStringLiteral("tagCounts")] = subobject;
    }

    if (value.trashCount()) {
        object[QStringLiteral("trashCount")] = *value.trashCount();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteCollectionCounts & value)
{
    if (object.contains(QStringLiteral("notebookCounts"))) {
        auto v = object[QStringLiteral("notebookCounts")];
        if (v.isObject()) {
            const auto o = v.toObject();
            QMap<Guid, qint32> map;
            for (auto it: toRange(qAsConst(o))) {
                if (it.value().isDouble()) {
                    const auto d = it.value().toDouble();
                    if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                        (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
                    {
                        map[it.key()] = static_cast<qint32>(d);
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setNotebookCounts(std::move(map));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("tagCounts"))) {
        auto v = object[QStringLiteral("tagCounts")];
        if (v.isObject()) {
            const auto o = v.toObject();
            QMap<Guid, qint32> map;
            for (auto it: toRange(qAsConst(o))) {
                if (it.value().isDouble()) {
                    const auto d = it.value().toDouble();
                    if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                        (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
                    {
                        map[it.key()] = static_cast<qint32>(d);
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setTagCounts(std::move(map));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("trashCount"))) {
        const auto v = object[QStringLiteral("trashCount")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setTrashCount(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
