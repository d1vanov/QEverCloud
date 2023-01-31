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

#ifndef QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTBUILDER
#define QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Note.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UpdateNoteIfUsnMatchesResult.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT UpdateNoteIfUsnMatchesResultBuilder
{
public:
    UpdateNoteIfUsnMatchesResultBuilder();

    UpdateNoteIfUsnMatchesResultBuilder(UpdateNoteIfUsnMatchesResultBuilder && other) noexcept;

    ~UpdateNoteIfUsnMatchesResultBuilder() noexcept;

    UpdateNoteIfUsnMatchesResultBuilder & operator=(UpdateNoteIfUsnMatchesResultBuilder && other) noexcept;

    UpdateNoteIfUsnMatchesResultBuilder & setNote(std::optional<Note> note);
    UpdateNoteIfUsnMatchesResultBuilder & setUpdated(std::optional<bool> updated);

    [[nodiscard]] UpdateNoteIfUsnMatchesResult build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_UPDATENOTEIFUSNMATCHESRESULTBUILDER
