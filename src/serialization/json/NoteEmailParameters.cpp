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

#include <qevercloud/serialization/json/NoteEmailParameters.h>

#include <qevercloud/serialization/json/Note.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const NoteEmailParameters & value)
{
    QJsonObject object;

    if (value.guid()) {
        object[QStringLiteral("guid")] = *value.guid();
    }

    if (value.note()) {
        object[QStringLiteral("note")] = serializeToJson(*value.note());
    }

    if (value.toAddresses())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.toAddresses()))
        {
            array << v;
        }

        object[QStringLiteral("toAddresses")] = array;
    }

    if (value.ccAddresses())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.ccAddresses()))
        {
            array << v;
        }

        object[QStringLiteral("ccAddresses")] = array;
    }

    if (value.subject()) {
        object[QStringLiteral("subject")] = *value.subject();
    }

    if (value.message()) {
        object[QStringLiteral("message")] = *value.message();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteEmailParameters & value)
{
    if (object.contains(QStringLiteral("guid"))) {
        const auto v = object[QStringLiteral("guid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("note"))) {
        const auto v = object[QStringLiteral("note")];
        if (v.isObject()) {
            auto o = v.toObject();
            Note f;
            if (deserializeFromJson(o, f)) {
                value.setNote(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("toAddresses"))) {
        const auto v = object[QStringLiteral("toAddresses")];
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
            value.setToAddresses(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("ccAddresses"))) {
        const auto v = object[QStringLiteral("ccAddresses")];
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
            value.setCcAddresses(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("subject"))) {
        const auto v = object[QStringLiteral("subject")];
        if (v.isString()) {
            auto s = v.toString();
            value.setSubject(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("message"))) {
        const auto v = object[QStringLiteral("message")];
        if (v.isString()) {
            auto s = v.toString();
            value.setMessage(std::move(s));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
