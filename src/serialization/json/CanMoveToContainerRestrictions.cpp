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

#include <qevercloud/serialization/json/CanMoveToContainerRestrictions.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

namespace {

[[nodiscard]] std::optional<CanMoveToContainerStatus> safeCastCanMoveToContainerStatusToEnum(
    const qint64 value) noexcept
{
    switch (value)
    {
    case static_cast<qint64>(CanMoveToContainerStatus::CAN_BE_MOVED):
        return CanMoveToContainerStatus::CAN_BE_MOVED;
    case static_cast<qint64>(CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE):
        return CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE;
    case static_cast<qint64>(CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE):
        return CanMoveToContainerStatus::INSUFFICIENT_CONTAINER_PRIVILEGE;
    default:
        return std::nullopt;
    }
}

} // namespace

QJsonObject serializeToJson(const CanMoveToContainerRestrictions & value)
{
    QJsonObject object;

    if (value.canMoveToContainer()) {
        object[QStringLiteral("canMoveToContainer")] = QString::number(static_cast<qint64>(*value.canMoveToContainer()));
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, CanMoveToContainerRestrictions & value)
{
    if (object.contains(QStringLiteral("canMoveToContainer"))) {
        const auto v = object[QStringLiteral("canMoveToContainer")];
        if (v.isString()) {
            const auto s = v.toString();
            bool conversionResult = false;
            qint64 i = s.toLongLong(&conversionResult);
            if (!conversionResult) {
                return false;
            }

            const auto e = safeCastCanMoveToContainerStatusToEnum(i);
            if (e) {
                value.setCanMoveToContainer(*e);
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
