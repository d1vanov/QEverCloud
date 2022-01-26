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

#include <qevercloud/serialization/json/Notebook.h>

#include <qevercloud/serialization/json/BusinessNotebook.h>
#include <qevercloud/serialization/json/NotebookRecipientSettings.h>
#include <qevercloud/serialization/json/NotebookRestrictions.h>
#include <qevercloud/serialization/json/Publishing.h>
#include <qevercloud/serialization/json/SharedNotebook.h>
#include <qevercloud/serialization/json/User.h>

#include <qevercloud/utility/ToRange.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const Notebook & value)
{
    QJsonObject object;

    object[QStringLiteral("localId")] = value.localId();
    object[QStringLiteral("isLocallyModified")] = value.isLocallyModified();
    object[QStringLiteral("isLocalOnly")] = value.isLocalOnly();
    object[QStringLiteral("isLocallyFavorited")] = value.isLocallyFavorited();
    {
        QJsonObject subobject;
        for (auto it: toRange(qAsConst(value.localData())))
        {
            subobject[it.key()] = QJsonValue::fromVariant(it.value());
        }
        object[QStringLiteral("localData")] = subobject;
    }

    if (value.linkedNotebookGuid()) {
        object[QStringLiteral("linkedNotebookGuid")] = *value.linkedNotebookGuid();
    }

    if (value.guid()) {
        object[QStringLiteral("guid")] = *value.guid();
    }

    if (value.name()) {
        object[QStringLiteral("name")] = *value.name();
    }

    if (value.updateSequenceNum()) {
        object[QStringLiteral("updateSequenceNum")] = *value.updateSequenceNum();
    }

    if (value.defaultNotebook()) {
        object[QStringLiteral("defaultNotebook")] = *value.defaultNotebook();
    }

    if (value.serviceCreated()) {
        object[QStringLiteral("serviceCreated")] = QString::number(*value.serviceCreated());
    }

    if (value.serviceUpdated()) {
        object[QStringLiteral("serviceUpdated")] = QString::number(*value.serviceUpdated());
    }

    if (value.publishing()) {
        object[QStringLiteral("publishing")] = serializeToJson(*value.publishing());
    }

    if (value.published()) {
        object[QStringLiteral("published")] = *value.published();
    }

    if (value.stack()) {
        object[QStringLiteral("stack")] = *value.stack();
    }

    if (value.sharedNotebookIds())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.sharedNotebookIds()))
        {
            array << QString::number(v);
        }

        object[QStringLiteral("sharedNotebookIds")] = array;
    }

    if (value.sharedNotebooks())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.sharedNotebooks()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("sharedNotebooks")] = array;
    }

    if (value.businessNotebook()) {
        object[QStringLiteral("businessNotebook")] = serializeToJson(*value.businessNotebook());
    }

    if (value.contact()) {
        object[QStringLiteral("contact")] = serializeToJson(*value.contact());
    }

    if (value.restrictions()) {
        object[QStringLiteral("restrictions")] = serializeToJson(*value.restrictions());
    }

    if (value.recipientSettings()) {
        object[QStringLiteral("recipientSettings")] = serializeToJson(*value.recipientSettings());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, Notebook & value)
{
    if (object.contains(QStringLiteral("localId"))) {
        const auto v = object[QStringLiteral("localId")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLocalId(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocallyModified"))) {
        const auto v = object[QStringLiteral("isLocallyModified")];
        if (v.isBool()) {
            value.setLocallyModified(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocalOnly"))) {
        const auto v = object[QStringLiteral("isLocalOnly")];
        if (v.isBool()) {
            value.setLocalOnly(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("isLocallyFavorited"))) {
        const auto v = object[QStringLiteral("isLocallyFavorited")];
        if (v.isBool()) {
            value.setLocallyFavorited(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("localData"))) {
        auto v = object[QStringLiteral("localData")];
        if (v.isObject()) {
            const auto o = v.toObject();
            QHash<QString, QVariant> map;
            for (auto it: toRange(qAsConst(o))) {
                QVariant f = it.value().toVariant();
                map[it.key()] = f;
            }
            value.setLocalData(std::move(map));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("linkedNotebookGuid"))) {
        const auto v = object[QStringLiteral("linkedNotebookGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLinkedNotebookGuid(std::move(s));
        }
        else {
            return false;
        }
    }

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

    if (object.contains(QStringLiteral("name"))) {
        const auto v = object[QStringLiteral("name")];
        if (v.isString()) {
            auto s = v.toString();
            value.setName(std::move(s));
        }
        else {
            return false;
        }
    }

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

    if (object.contains(QStringLiteral("defaultNotebook"))) {
        const auto v = object[QStringLiteral("defaultNotebook")];
        if (v.isBool()) {
            value.setDefaultNotebook(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("serviceCreated"))) {
        const auto v = object[QStringLiteral("serviceCreated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setServiceCreated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("serviceUpdated"))) {
        const auto v = object[QStringLiteral("serviceUpdated")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setServiceUpdated(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("publishing"))) {
        const auto v = object[QStringLiteral("publishing")];
        if (v.isObject()) {
            auto o = v.toObject();
            Publishing f;
            if (deserializeFromJson(o, f)) {
                value.setPublishing(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("published"))) {
        const auto v = object[QStringLiteral("published")];
        if (v.isBool()) {
            value.setPublished(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("stack"))) {
        const auto v = object[QStringLiteral("stack")];
        if (v.isString()) {
            auto s = v.toString();
            value.setStack(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sharedNotebookIds"))) {
        const auto v = object[QStringLiteral("sharedNotebookIds")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<qint64> values;
            for (const auto & item: qAsConst(a)) {
                if (item.isString()) {
                    const auto s = item.toString();
                    bool conversionResult = false;
                    qint64 i = s.toLongLong(&conversionResult);
                    if (!conversionResult) {
                        return false;
                    }

                    values.push_back(i);
                }
                else {
                    return false;
                }
            }
            value.setSharedNotebookIds(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("sharedNotebooks"))) {
        const auto v = object[QStringLiteral("sharedNotebooks")];
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
            value.setSharedNotebooks(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("businessNotebook"))) {
        const auto v = object[QStringLiteral("businessNotebook")];
        if (v.isObject()) {
            auto o = v.toObject();
            BusinessNotebook f;
            if (deserializeFromJson(o, f)) {
                value.setBusinessNotebook(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("contact"))) {
        const auto v = object[QStringLiteral("contact")];
        if (v.isObject()) {
            auto o = v.toObject();
            User f;
            if (deserializeFromJson(o, f)) {
                value.setContact(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("restrictions"))) {
        const auto v = object[QStringLiteral("restrictions")];
        if (v.isObject()) {
            auto o = v.toObject();
            NotebookRestrictions f;
            if (deserializeFromJson(o, f)) {
                value.setRestrictions(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("recipientSettings"))) {
        const auto v = object[QStringLiteral("recipientSettings")];
        if (v.isObject()) {
            auto o = v.toObject();
            NotebookRecipientSettings f;
            if (deserializeFromJson(o, f)) {
                value.setRecipientSettings(std::move(f));
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
