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

#include <qevercloud/serialization/json/NoteList.h>

#include <qevercloud/serialization/json/Note.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const NoteList & value)
{
    QJsonObject object;

    object[QStringLiteral("startIndex")] = value.startIndex();
    object[QStringLiteral("totalNotes")] = value.totalNotes();
    {
        QJsonArray array;
        for (const auto & v: std::as_const(value.notes()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("notes")] = array;
    }

    if (value.stoppedWords())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.stoppedWords()))
        {
            array << v;
        }

        object[QStringLiteral("stoppedWords")] = array;
    }

    if (value.searchedWords())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.searchedWords()))
        {
            array << v;
        }

        object[QStringLiteral("searchedWords")] = array;
    }

    if (value.updateCount()) {
        object[QStringLiteral("updateCount")] = *value.updateCount();
    }

    if (value.searchContextBytes()) {
        object[QStringLiteral("searchContextBytes")] = QString::fromUtf8(value.searchContextBytes()->toBase64());
    }

    if (value.debugInfo()) {
        object[QStringLiteral("debugInfo")] = *value.debugInfo();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteList & value)
{
    if (object.contains(QStringLiteral("startIndex"))) {
        const auto v = object[QStringLiteral("startIndex")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setStartIndex(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("totalNotes"))) {
        const auto v = object[QStringLiteral("totalNotes")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setTotalNotes(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("notes"))) {
        const auto v = object[QStringLiteral("notes")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Note> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    Note f;
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
            value.setNotes(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("stoppedWords"))) {
        const auto v = object[QStringLiteral("stoppedWords")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QStringList values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setStoppedWords(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("searchedWords"))) {
        const auto v = object[QStringLiteral("searchedWords")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QStringList values;
            for (const auto & item: std::as_const(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setSearchedWords(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("updateCount"))) {
        const auto v = object[QStringLiteral("updateCount")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUpdateCount(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("searchContextBytes"))) {
        const auto v = object[QStringLiteral("searchContextBytes")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSearchContextBytes(QByteArray::fromBase64(s.toUtf8()));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("debugInfo"))) {
        const auto v = object[QStringLiteral("debugInfo")];
        if (v.isString()) {
            auto s = v.toString();
            value.setDebugInfo(std::move(s));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
