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

#include <qevercloud/serialization/json/ShareRelationships.h>

#include <qevercloud/serialization/json/InvitationShareRelationship.h>
#include <qevercloud/serialization/json/MemberShareRelationship.h>
#include <qevercloud/serialization/json/ShareRelationshipRestrictions.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const ShareRelationships & value)
{
    QJsonObject object;

    if (value.invitations())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.invitations()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("invitations")] = array;
    }

    if (value.memberships())
    {
        QJsonArray array;
        for (const auto & v: qAsConst(*value.memberships()))
        {
            array << serializeToJson(v);
        }

        object[QStringLiteral("memberships")] = array;
    }

    if (value.invitationRestrictions()) {
        object[QStringLiteral("invitationRestrictions")] = serializeToJson(*value.invitationRestrictions());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ShareRelationships & value)
{
    if (object.contains(QStringLiteral("invitations"))) {
        const auto v = object[QStringLiteral("invitations")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<InvitationShareRelationship> values;
            for (const auto & item: qAsConst(a)) {
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
            value.setInvitations(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("memberships"))) {
        const auto v = object[QStringLiteral("memberships")];
        if (v.isArray()) {
            const auto a = v.toArray();
            QList<MemberShareRelationship> values;
            for (const auto & item: qAsConst(a)) {
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
            value.setMemberships(std::move(values));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("invitationRestrictions"))) {
        const auto v = object[QStringLiteral("invitationRestrictions")];
        if (v.isObject()) {
            auto o = v.toObject();
            ShareRelationshipRestrictions f;
            if (deserializeFromJson(o, f)) {
                value.setInvitationRestrictions(std::move(f));
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
