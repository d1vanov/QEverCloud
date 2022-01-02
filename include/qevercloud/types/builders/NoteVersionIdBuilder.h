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

#ifndef QEVERCLOUD_GENERATED_NOTEVERSIONIDBUILDER
#define QEVERCLOUD_GENERATED_NOTEVERSIONIDBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteVersionId.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteVersionIdBuilder
{
public:
    NoteVersionIdBuilder();

    NoteVersionIdBuilder(NoteVersionIdBuilder && other) noexcept;

    ~NoteVersionIdBuilder() noexcept;

    NoteVersionIdBuilder & operator=(NoteVersionIdBuilder && other) noexcept;

    NoteVersionIdBuilder & setUpdateSequenceNum(qint32 updateSequenceNum);
    NoteVersionIdBuilder & setUpdated(Timestamp updated);
    NoteVersionIdBuilder & setSaved(Timestamp saved);
    NoteVersionIdBuilder & setTitle(QString title);
    NoteVersionIdBuilder & setLastEditorId(std::optional<UserID> lastEditorId);

    [[nodiscard]] NoteVersionId build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEVERSIONIDBUILDER
