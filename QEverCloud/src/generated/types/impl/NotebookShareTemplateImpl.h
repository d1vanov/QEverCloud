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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATEIMPL_H
#define QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATEIMPL_H

#include <generated/types/NotebookShareTemplate.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotebookShareTemplate::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NotebookShareTemplate::Impl & other) = default;
    Impl(NotebookShareTemplate::Impl && other) noexcept = default;

    NotebookShareTemplate::Impl & operator=(const NotebookShareTemplate::Impl & other) = delete;
    NotebookShareTemplate::Impl & operator=(NotebookShareTemplate::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const NotebookShareTemplate::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const NotebookShareTemplate::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<Guid> m_notebookGuid;
    std::optional<MessageThreadID> m_recipientThreadId;
    std::optional<QList<Contact>> m_recipientContacts;
    std::optional<SharedNotebookPrivilegeLevel> m_privilege;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKSHARETEMPLATEIMPL_H
