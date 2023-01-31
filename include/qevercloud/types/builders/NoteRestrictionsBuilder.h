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

#ifndef QEVERCLOUD_GENERATED_NOTERESTRICTIONSBUILDER
#define QEVERCLOUD_GENERATED_NOTERESTRICTIONSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteRestrictions.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteRestrictionsBuilder
{
public:
    NoteRestrictionsBuilder();

    NoteRestrictionsBuilder(NoteRestrictionsBuilder && other) noexcept;

    ~NoteRestrictionsBuilder() noexcept;

    NoteRestrictionsBuilder & operator=(NoteRestrictionsBuilder && other) noexcept;

    NoteRestrictionsBuilder & setNoUpdateTitle(std::optional<bool> noUpdateTitle);
    NoteRestrictionsBuilder & setNoUpdateContent(std::optional<bool> noUpdateContent);
    NoteRestrictionsBuilder & setNoEmail(std::optional<bool> noEmail);
    NoteRestrictionsBuilder & setNoShare(std::optional<bool> noShare);
    NoteRestrictionsBuilder & setNoSharePublicly(std::optional<bool> noSharePublicly);

    [[nodiscard]] NoteRestrictions build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTERESTRICTIONSBUILDER
