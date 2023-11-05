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

#include <qevercloud/serialization/json/ManageNoteSharesParameters.h>

#include <qevercloud/serialization/json/NoteInvitationShareRelationship.h>
#include <qevercloud/serialization/json/NoteMemberShareRelationship.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const ManageNoteSharesParameters & value)
{
    QJsonObject object;

    if (value.noteGuid()) {
        object[QStringLiteral("noteGuid")] = *value.noteGuid();
    }

    if (value.membershipsToUpdate())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.membershipsToUpdate()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("membershipsToUpdate")] = array;
    }

    if (value.invitationsToUpdate())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.invitationsToUpdate()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("invitationsToUpdate")] = array;
    }

    if (value.membershipsToUnshare())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.membershipsToUnshare()))
        {
            array << v;
        }

        object[QStringLiteral("membershipsToUnshare")] = array;
    }

    if (value.invitationsToUnshare())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.invitationsToUnshare()))
        {
            array << QString::number(v);
        }

        object[QStringLiteral("invitationsToUnshare")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ManageNoteSharesParameters & value)
{
    if (object.contains(QStringLiteral("noteGuid"))) {
        const auto v = object[QStringLiteral("noteGuid")];
        if (v.isString()) {
            auto s = v.toString();
            value.setNoteGuid(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("membershipsToUpdate"))) {
        const auto v = object[QStringLiteral("membershipsToUpdate")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<NoteMemberShareRelationship> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    NoteMemberShareRelationship f;
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
            value.setMembershipsToUpdate(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("invitationsToUpdate"))) {
        const auto v = object[QStringLiteral("invitationsToUpdate")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<NoteInvitationShareRelationship> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    NoteInvitationShareRelationship f;
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
            value.setInvitationsToUpdate(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("membershipsToUnshare"))) {
        const auto v = object[QStringLiteral("membershipsToUnshare")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<UserID> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isDouble()) {
                    const auto d = item.toDouble();
                    if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                        (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
                    {
                        values.push_back(static_cast<qint32>(d));
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
            value.setMembershipsToUnshare(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("invitationsToUnshare"))) {
        const auto v = object[QStringLiteral("invitationsToUnshare")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<IdentityID> values;
            for (const auto & item: std::as_const(a)) {
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
            value.setInvitationsToUnshare(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
