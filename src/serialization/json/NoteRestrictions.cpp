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

#include <qevercloud/serialization/json/NoteRestrictions.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const NoteRestrictions & value)
{
    QJsonObject object;

    if (value.noUpdateTitle()) {
        object[QStringLiteral("noUpdateTitle")] = *value.noUpdateTitle();
    }

    if (value.noUpdateContent()) {
        object[QStringLiteral("noUpdateContent")] = *value.noUpdateContent();
    }

    if (value.noEmail()) {
        object[QStringLiteral("noEmail")] = *value.noEmail();
    }

    if (value.noShare()) {
        object[QStringLiteral("noShare")] = *value.noShare();
    }

    if (value.noSharePublicly()) {
        object[QStringLiteral("noSharePublicly")] = *value.noSharePublicly();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, NoteRestrictions & value)
{
    if (object.contains(QStringLiteral("noUpdateTitle"))) {
        const auto v = object[QStringLiteral("noUpdateTitle")];
        if (v.isBool()) {
            value.setNoUpdateTitle(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noUpdateContent"))) {
        const auto v = object[QStringLiteral("noUpdateContent")];
        if (v.isBool()) {
            value.setNoUpdateContent(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noEmail"))) {
        const auto v = object[QStringLiteral("noEmail")];
        if (v.isBool()) {
            value.setNoEmail(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noShare"))) {
        const auto v = object[QStringLiteral("noShare")];
        if (v.isBool()) {
            value.setNoShare(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noSharePublicly"))) {
        const auto v = object[QStringLiteral("noSharePublicly")];
        if (v.isBool()) {
            value.setNoSharePublicly(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
