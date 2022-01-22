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

#include <qevercloud/serialization/json/NoteFilter.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NoteFilter & value)
{
    QJsonObject object;

    if (value.order()) {
        object[QStringLiteral("order")] = *value.order();
    }

    if (value.ascending()) {
        object[QStringLiteral("ascending")] = *value.ascending();
    }

    if (value.words()) {
        object[QStringLiteral("words")] = *value.words();
    }

    if (value.notebookGuid()) {
        object[QStringLiteral("notebookGuid")] = *value.notebookGuid();
    }

    if (value.tagGuids())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.tagGuids()))
        {
            array << v;
        }

        object[QStringLiteral("tagGuids")] = array;
    }

    if (value.timeZone()) {
        object[QStringLiteral("timeZone")] = *value.timeZone();
    }

    if (value.inactive()) {
        object[QStringLiteral("inactive")] = *value.inactive();
    }

    if (value.emphasized()) {
        object[QStringLiteral("emphasized")] = *value.emphasized();
    }

    if (value.includeAllReadableNotebooks()) {
        object[QStringLiteral("includeAllReadableNotebooks")] = *value.includeAllReadableNotebooks();
    }

    if (value.includeAllReadableWorkspaces()) {
        object[QStringLiteral("includeAllReadableWorkspaces")] = *value.includeAllReadableWorkspaces();
    }

    if (value.context()) {
        object[QStringLiteral("context")] = *value.context();
    }

    if (value.rawWords()) {
        object[QStringLiteral("rawWords")] = *value.rawWords();
    }

    if (value.searchContextBytes()) {
        object[QStringLiteral("searchContextBytes")] = QString::fromUtf8(value.searchContextBytes()->toBase64());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteFilter & value)
{
    if (object.contains(QStringLiteral("order"))) {
        const auto v = object[QStringLiteral("order")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setOrder(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("ascending"))) {
        const auto v = object[QStringLiteral("ascending")];
        if (v.isBool()) {
            value.setAscending(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("words"))) {
        const auto v = object[QStringLiteral("words")];
        if (v.isString()) {
            auto s = v.toString();
            value.setWords(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("notebookGuid"))) {
        const auto v = object[QStringLiteral("notebookGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNotebookGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("tagGuids"))) {
        const auto v = object[QStringLiteral("tagGuids")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<Guid> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isString()) {
                    auto s = item.toString();
                    values.push_back(std::move(s));
                }
                else {
                    return false;
                }
            }
            value.setTagGuids(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("timeZone"))) {
        const auto v = object[QStringLiteral("timeZone")];
        if (v.isString()) {
            auto s = v.toString();
            value.setTimeZone(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("inactive"))) {
        const auto v = object[QStringLiteral("inactive")];
        if (v.isBool()) {
            value.setInactive(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("emphasized"))) {
        const auto v = object[QStringLiteral("emphasized")];
        if (v.isString()) {
            auto s = v.toString();
            value.setEmphasized(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeAllReadableNotebooks"))) {
        const auto v = object[QStringLiteral("includeAllReadableNotebooks")];
        if (v.isBool()) {
            value.setIncludeAllReadableNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeAllReadableWorkspaces"))) {
        const auto v = object[QStringLiteral("includeAllReadableWorkspaces")];
        if (v.isBool()) {
            value.setIncludeAllReadableWorkspaces(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("context"))) {
        const auto v = object[QStringLiteral("context")];
        if (v.isString()) {
            auto s = v.toString();
            value.setContext(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("rawWords"))) {
        const auto v = object[QStringLiteral("rawWords")];
        if (v.isString()) {
            auto s = v.toString();
            value.setRawWords(std::move(s));
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

    return true;
}

} // namespace qevercloud
