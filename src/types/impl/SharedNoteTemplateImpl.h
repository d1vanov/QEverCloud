/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEIMPL_H
#define QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEIMPL_H

#include <qevercloud/types/SharedNoteTemplate.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNoteTemplate::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const SharedNoteTemplate::Impl & other) = default;
    Impl(SharedNoteTemplate::Impl && other) noexcept = default;

    SharedNoteTemplate::Impl & operator=(const SharedNoteTemplate::Impl & other) = delete;
    SharedNoteTemplate::Impl & operator=(SharedNoteTemplate::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<Guid> m_noteGuid;
    std::optional<MessageThreadID> m_recipientThreadId;
    std::optional<QList<Contact>> m_recipientContacts;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTETEMPLATEIMPL_H
