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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATEBUILDER
#define QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Contact.h>
#include <qevercloud/types/NotebookShareTemplate.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NotebookShareTemplateBuilder
{
public:
    NotebookShareTemplateBuilder();

    NotebookShareTemplateBuilder(NotebookShareTemplateBuilder && other) noexcept;

    ~NotebookShareTemplateBuilder() noexcept;

    NotebookShareTemplateBuilder & operator=(NotebookShareTemplateBuilder && other) noexcept;

    NotebookShareTemplateBuilder & setNotebookGuid(std::optional<Guid> notebookGuid);
    NotebookShareTemplateBuilder & setRecipientThreadId(std::optional<MessageThreadID> recipientThreadId);
    NotebookShareTemplateBuilder & setRecipientContacts(std::optional<QList<Contact>> recipientContacts);
    NotebookShareTemplateBuilder & setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege);

    [[nodiscard]] NotebookShareTemplate build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATEBUILDER
