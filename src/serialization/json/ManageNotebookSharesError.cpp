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

#include <qevercloud/serialization/json/ManageNotebookSharesError.h>

#include <qevercloud/serialization/json/EDAMNotFoundException.h>
#include <qevercloud/serialization/json/EDAMUserException.h>
#include <qevercloud/serialization/json/UserIdentity.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const ManageNotebookSharesError & value)
{
    QJsonObject object;

    if (value.userIdentity()) {
        object[QStringLiteral("userIdentity")] = serializeToJson(*value.userIdentity());
    }

    if (value.userException()) {
        object[QStringLiteral("userException")] = serializeToJson(*value.userException());
    }

    if (value.notFoundException()) {
        object[QStringLiteral("notFoundException")] = serializeToJson(*value.notFoundException());
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, ManageNotebookSharesError & value)
{
    if (object.contains(QStringLiteral("userIdentity"))) {
        const auto v = object[QStringLiteral("userIdentity")];
        if (v.isObject()) {
            auto o = v.toObject();
            UserIdentity f;
            if (deserializeFromJson(o, f)) {
                value.setUserIdentity(std::move(f));
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
