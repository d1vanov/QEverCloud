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

#include <qevercloud/serialization/json/NoteShareRelationshipRestrictions.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NoteShareRelationshipRestrictions & value)
{
    QJsonObject object;

    if (value.noSetReadNote()) {
        object[QStringLiteral("noSetReadNote")] = *value.noSetReadNote();
    }

    if (value.noSetModifyNote()) {
        object[QStringLiteral("noSetModifyNote")] = *value.noSetModifyNote();
    }

    if (value.noSetFullAccess()) {
        object[QStringLiteral("noSetFullAccess")] = *value.noSetFullAccess();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteShareRelationshipRestrictions & value)
{
    if (object.contains(QStringLiteral("noSetReadNote"))) {
        const auto v = object[QStringLiteral("noSetReadNote")];
        if (v.isBool()) {
            value.setNoSetReadNote(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSetModifyNote"))) {
        const auto v = object[QStringLiteral("noSetModifyNote")];
        if (v.isBool()) {
            value.setNoSetModifyNote(v.toBool());
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
