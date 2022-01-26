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

#include <qevercloud/serialization/json/ManageNoteSharesError.h>

#include <qevercloud/serialization/json/EDAMNotFoundException.h>
#include <qevercloud/serialization/json/EDAMUserException.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const ManageNoteSharesError & value)
{
    QJsonObject object;

    if (value.identityID()) {
        object[QStringLiteral("identityID")] = QString::number(*value.identityID());
    }

    if (value.userID()) {
        object[QStringLiteral("userID")] = *value.userID();
    }

    if (value.userException()) {
        object[QStringLiteral("userException")] = serializeToJson(*value.userException());
    }

    if (value.notFoundException()) {
        object[QStringLiteral("notFoundException")] = serializeToJson(*value.notFoundException());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ManageNoteSharesError & value)
{
    if (object.contains(QStringLiteral("identityID"))) {
        const auto v = object[QStringLiteral("identityID")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            value.setIdentityID(i);
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userID"))) {
        const auto v = object[QStringLiteral("userID")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUserID(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userException"))) {
        const auto v = object[QStringLiteral("userException")];
        if (v.isObject()) {
            auto o = v.toObject();
            EDAMUserException f;
            if (deserializeFromJson(o, f)) {
                value.setUserException(std::move(f));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("notFoundException"))) {
        const auto v = object[QStringLiteral("notFoundException")];
        if (v.isObject()) {
            auto o = v.toObject();
            EDAMNotFoundException f;
            if (deserializeFromJson(o, f)) {
                value.setNotFoundException(std::move(f));
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
