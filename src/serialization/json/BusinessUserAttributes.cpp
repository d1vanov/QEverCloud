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

#include <qevercloud/serialization/json/BusinessUserAttributes.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const BusinessUserAttributes & value)
{
    QJsonObject object;

    if (value.title()) {
        object[QStringLiteral("title")] = *value.title();
    }

    if (value.location()) {
        object[QStringLiteral("location")] = *value.location();
    }

    if (value.department()) {
        object[QStringLiteral("department")] = *value.department();
    }

    if (value.mobilePhone()) {
        object[QStringLiteral("mobilePhone")] = *value.mobilePhone();
    }

    if (value.linkedInProfileUrl()) {
        object[QStringLiteral("linkedInProfileUrl")] = *value.linkedInProfileUrl();
    }

    if (value.workPhone()) {
        object[QStringLiteral("workPhone")] = *value.workPhone();
    }

    if (value.companyStartDate()) {
        object[QStringLiteral("companyStartDate")] = *value.companyStartDate();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, BusinessUserAttributes & value)
{
    if (object.contains(QStringLiteral("title"))) {
        const auto v = object[QStringLiteral("title")];
        if (v.isString()) {
            auto s = v.toString();
            value.setTitle(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("location"))) {
        const auto v = object[QStringLiteral("location")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLocation(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("department"))) {
        const auto v = object[QStringLiteral("department")];
        if (v.isString()) {
            auto s = v.toString();
            value.setDepartment(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("mobilePhone"))) {
        const auto v = object[QStringLiteral("mobilePhone")];
        if (v.isString()) {
            auto s = v.toString();
            value.setMobilePhone(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("linkedInProfileUrl"))) {
        const auto v = object[QStringLiteral("linkedInProfileUrl")];
        if (v.isString()) {
            auto s = v.toString();
            value.setLinkedInProfileUrl(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("workPhone"))) {
        const auto v = object[QStringLiteral("workPhone")];
        if (v.isString()) {
            auto s = v.toString();
            value.setWorkPhone(std::move(s));
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("companyStartDate"))) {
        const auto v = object[QStringLiteral("companyStartDate")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setCompanyStartDate(static_cast<qint64>(d));
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
