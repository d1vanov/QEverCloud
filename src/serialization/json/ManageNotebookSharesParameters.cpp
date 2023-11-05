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

#include <qevercloud/serialization/json/ManageNotebookSharesParameters.h>

#include <qevercloud/serialization/json/InvitationShareRelationship.h>
#include <qevercloud/serialization/json/MemberShareRelationship.h>
#include <qevercloud/serialization/json/UserIdentity.h>

#include <QJsonArray>

#include <limits>
#include <utility>

namespace qevercloud {

QJsonObject serializeToJson(const ManageNotebookSharesParameters & value)
{
    QJsonObject object;

    if (value.notebookGuid()) {
        object[QStringLiteral("notebookGuid")] = *value.notebookGuid();
    }

    if (value.inviteMessage()) {
        object[QStringLiteral("inviteMessage")] = *value.inviteMessage();
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

    if (value.invitationsToCreateOrUpdate())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.invitationsToCreateOrUpdate()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("invitationsToCreateOrUpdate")] = array;
    }

    if (value.unshares())
    {
        QJsonArray array;
        for (const auto & v: std::as_const(*value.unshares()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("unshares")] = array;
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ManageNotebookSharesParameters & value)
{
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

    if (object.contains(QStringLiteral("inviteMessage"))) {
        const auto v = object[QStringLiteral("inviteMessage")];
        if (v.isString()) {
            auto s = v.toString();
            value.setInviteMessage(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("membershipsToUpdate"))) {
        const auto v = object[QStringLiteral("membershipsToUpdate")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<MemberShareRelationship> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    MemberShareRelationship f;
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

    if (object.contains(QStringLiteral("invitationsToCreateOrUpdate"))) {
        const auto v = object[QStringLiteral("invitationsToCreateOrUpdate")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<InvitationShareRelationship> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    InvitationShareRelationship f;
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
            value.setInvitationsToCreateOrUpdate(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("unshares"))) {
        const auto v = object[QStringLiteral("unshares")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<UserIdentity> values;
            for (const auto & item: std::as_const(a)) {
                if (item.isObject()) {
                    auto o = item.toObject();
                    UserIdentity f;
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
            value.setUnshares(std::move(values));
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
