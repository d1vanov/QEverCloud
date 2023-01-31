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

#include <qevercloud/serialization/json/ShareRelationshipRestrictions.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const ShareRelationshipRestrictions & value)
{
    QJsonObject object;

    if (value.noSetReadOnly()) {
        object[QStringLiteral("noSetReadOnly")] = *value.noSetReadOnly();
    }

    if (value.noSetReadPlusActivity()) {
        object[QStringLiteral("noSetReadPlusActivity")] = *value.noSetReadPlusActivity();
    }

    if (value.noSetModify()) {
        object[QStringLiteral("noSetModify")] = *value.noSetModify();
    }

    if (value.noSetFullAccess()) {
        object[QStringLiteral("noSetFullAccess")] = *value.noSetFullAccess();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ShareRelationshipRestrictions & value)
{
    if (object.contains(QStringLiteral("noSetReadOnly"))) {
        const auto v = object[QStringLiteral("noSetReadOnly")];
        if (v.isBool()) {
            value.setNoSetReadOnly(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetReadPlusActivity"))) {
        const auto v = object[QStringLiteral("noSetReadPlusActivity")];
        if (v.isBool()) {
            value.setNoSetReadPlusActivity(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetModify"))) {
        const auto v = object[QStringLiteral("noSetModify")];
        if (v.isBool()) {
            value.setNoSetModify(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetFullAccess"))) {
        const auto v = object[QStringLiteral("noSetFullAccess")];
        if (v.isBool()) {
            value.setNoSetFullAccess(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
