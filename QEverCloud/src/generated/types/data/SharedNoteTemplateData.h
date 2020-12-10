/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEDATA_H
#define QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEDATA_H

#include <generated/types/SharedNoteTemplate.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNoteTemplate::SharedNoteTemplateData final:
    public QSharedData,
    public Printable
{
public:
    SharedNoteTemplateData() = default;
    SharedNoteTemplateData(const SharedNoteTemplateData & other) = default;
    SharedNoteTemplateData(SharedNoteTemplateData && other) noexcept = default;

    SharedNoteTemplateData & operator=(const SharedNoteTemplateData & other) = delete;
    SharedNoteTemplateData & operator=(SharedNoteTemplateData && other) = delete;

    ~SharedNoteTemplateData() noexcept override = default;

    [[nodiscard]] bool operator==(const SharedNoteTemplateData & other) const noexcept;
    [[nodiscard]] bool operator!=(const SharedNoteTemplateData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<Guid> m_noteGuid;
    std::optional<MessageThreadID> m_recipientThreadId;
    std::optional<QList<Contact>> m_recipientContacts;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEDATA_H
