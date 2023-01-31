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

#include <qevercloud/serialization/json/SavedSearchScope.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const SavedSearchScope & value)
{
    QJsonObject object;

    if (value.includeAccount()) {
        object[QStringLiteral("includeAccount")] = *value.includeAccount();
    }

    if (value.includePersonalLinkedNotebooks()) {
        object[QStringLiteral("includePersonalLinkedNotebooks")] = *value.includePersonalLinkedNotebooks();
    }

    if (value.includeBusinessLinkedNotebooks()) {
        object[QStringLiteral("includeBusinessLinkedNotebooks")] = *value.includeBusinessLinkedNotebooks();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, SavedSearchScope & value)
{
    if (object.contains(QStringLiteral("includeAccount"))) {
        const auto v = object[QStringLiteral("includeAccount")];
        if (v.isBool()) {
            value.setIncludeAccount(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includePersonalLinkedNotebooks"))) {
        const auto v = object[QStringLiteral("includePersonalLinkedNotebooks")];
        if (v.isBool()) {
            value.setIncludePersonalLinkedNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("includeBusinessLinkedNotebooks"))) {
        const auto v = object[QStringLiteral("includeBusinessLinkedNotebooks")];
        if (v.isBool()) {
            value.setIncludeBusinessLinkedNotebooks(v.toBool());
        }
        else {
            return false;
        }
    }

    return true;
}

} // namespace qevercloud
