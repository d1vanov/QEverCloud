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

#ifndef QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSBUILDER
#define QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteShareRelationshipRestrictions.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteShareRelationshipRestrictionsBuilder
{
public:
    NoteShareRelationshipRestrictionsBuilder();

    NoteShareRelationshipRestrictionsBuilder(NoteShareRelationshipRestrictionsBuilder && other) noexcept;

    ~NoteShareRelationshipRestrictionsBuilder() noexcept;

    NoteShareRelationshipRestrictionsBuilder & operator=(NoteShareRelationshipRestrictionsBuilder && other) noexcept;

    NoteShareRelationshipRestrictionsBuilder & setNoSetReadNote(std::optional<bool> noSetReadNote);
    NoteShareRelationshipRestrictionsBuilder & setNoSetModifyNote(std::optional<bool> noSetModifyNote);
    NoteShareRelationshipRestrictionsBuilder & setNoSetFullAccess(std::optional<bool> noSetFullAccess);

    [[nodiscard]] NoteShareRelationshipRestrictions build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONSBUILDER
