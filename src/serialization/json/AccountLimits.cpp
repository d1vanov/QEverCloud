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

#include <qevercloud/serialization/json/AccountLimits.h>

#include <QJsonArray>

#include <limits>

namespace qevercloud {

QJsonObject serializeToJson(const AccountLimits & value)
{
    QJsonObject object;

    if (value.userMailLimitDaily()) {
        object[QStringLiteral("userMailLimitDaily")] = *value.userMailLimitDaily();
    }

    if (value.noteSizeMax()) {
        object[QStringLiteral("noteSizeMax")] = *value.noteSizeMax();
    }

    if (value.resourceSizeMax()) {
        object[QStringLiteral("resourceSizeMax")] = *value.resourceSizeMax();
    }

    if (value.userLinkedNotebookMax()) {
        object[QStringLiteral("userLinkedNotebookMax")] = *value.userLinkedNotebookMax();
    }

    if (value.uploadLimit()) {
        object[QStringLiteral("uploadLimit")] = *value.uploadLimit();
    }

    if (value.userNoteCountMax()) {
        object[QStringLiteral("userNoteCountMax")] = *value.userNoteCountMax();
    }

    if (value.userNotebookCountMax()) {
        object[QStringLiteral("userNotebookCountMax")] = *value.userNotebookCountMax();
    }

    if (value.userTagCountMax()) {
        object[QStringLiteral("userTagCountMax")] = *value.userTagCountMax();
    }

    if (value.noteTagCountMax()) {
        object[QStringLiteral("noteTagCountMax")] = *value.noteTagCountMax();
    }

    if (value.userSavedSearchesMax()) {
        object[QStringLiteral("userSavedSearchesMax")] = *value.userSavedSearchesMax();
    }

    if (value.noteResourceCountMax()) {
        object[QStringLiteral("noteResourceCountMax")] = *value.noteResourceCountMax();
    }

    return object;
}

bool deserializeFromJson(const QJsonObject & object, AccountLimits & value)
{
    if (object.contains(QStringLiteral("userMailLimitDaily"))) {
        const auto v = object[QStringLiteral("userMailLimitDaily")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUserMailLimitDaily(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noteSizeMax"))) {
        const auto v = object[QStringLiteral("noteSizeMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setNoteSizeMax(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("resourceSizeMax"))) {
        const auto v = object[QStringLiteral("resourceSizeMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setResourceSizeMax(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userLinkedNotebookMax"))) {
        const auto v = object[QStringLiteral("userLinkedNotebookMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUserLinkedNotebookMax(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("uploadLimit"))) {
        const auto v = object[QStringLiteral("uploadLimit")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint64>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint64>::max())))
            {
                value.setUploadLimit(static_cast<qint64>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userNoteCountMax"))) {
        const auto v = object[QStringLiteral("userNoteCountMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUserNoteCountMax(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userNotebookCountMax"))) {
        const auto v = object[QStringLiteral("userNotebookCountMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUserNotebookCountMax(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userTagCountMax"))) {
        const auto v = object[QStringLiteral("userTagCountMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUserTagCountMax(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noteTagCountMax"))) {
        const auto v = object[QStringLiteral("noteTagCountMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setNoteTagCountMax(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("userSavedSearchesMax"))) {
        const auto v = object[QStringLiteral("userSavedSearchesMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setUserSavedSearchesMax(static_cast<qint32>(d));
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    if (object.contains(QStringLiteral("noteResourceCountMax"))) {
        const auto v = object[QStringLiteral("noteResourceCountMax")];
        if (v.isDouble()) {
            const auto d = v.toDouble();
            if ((d >= static_cast<double>(std::numeric_limits<qint32>::min())) &&
                (d <= static_cast<double>(std::numeric_limits<qint32>::max())))
            {
                value.setNoteResourceCountMax(static_cast<qint32>(d));
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
