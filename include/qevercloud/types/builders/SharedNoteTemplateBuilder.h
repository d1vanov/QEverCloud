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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEBUILDER
#define QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Contact.h>
#include <qevercloud/types/SharedNoteTemplate.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SharedNoteTemplateBuilder
{
public:
    SharedNoteTemplateBuilder();

    SharedNoteTemplateBuilder(SharedNoteTemplateBuilder && other) noexcept;

    ~SharedNoteTemplateBuilder() noexcept;

    SharedNoteTemplateBuilder & operator=(SharedNoteTemplateBuilder && other) noexcept;

    SharedNoteTemplateBuilder & setNoteGuid(std::optional<Guid> noteGuid);
    SharedNoteTemplateBuilder & setRecipientThreadId(std::optional<MessageThreadID> recipientThreadId);
    SharedNoteTemplateBuilder & setRecipientContacts(std::optional<QList<Contact>> recipientContacts);
    SharedNoteTemplateBuilder & setPrivilege(std::optional<SharedNotePrivilegeLevel> privilege);

    [[nodiscard]] SharedNoteTemplate build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEBUILDER
