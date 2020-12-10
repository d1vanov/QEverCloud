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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOKDATA_H
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOKDATA_H

#include <generated/types/SharedNotebook.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNotebook::SharedNotebookData final:
    public QSharedData,
    public Printable
{
public:
    SharedNotebookData() = default;
    SharedNotebookData(const SharedNotebookData & other) = default;
    SharedNotebookData(SharedNotebookData && other) noexcept = default;

    SharedNotebookData & operator=(const SharedNotebookData & other) = delete;
    SharedNotebookData & operator=(SharedNotebookData && other) = delete;

    ~SharedNotebookData() noexcept override = default;

    [[nodiscard]] bool operator==(const SharedNotebookData & other) const noexcept;
    [[nodiscard]] bool operator!=(const SharedNotebookData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<qint64> m_id;
    std::optional<UserID> m_userId;
    std::optional<Guid> m_notebookGuid;
    std::optional<QString> m_email;
    std::optional<IdentityID> m_recipientIdentityId;
    std::optional<bool> m_notebookModifiable;
    std::optional<Timestamp> m_serviceCreated;
    std::optional<Timestamp> m_serviceUpdated;
    std::optional<QString> m_globalId;
    std::optional<QString> m_username;
    std::optional<SharedNotebookPrivilegeLevel> m_privilege;
    std::optional<SharedNotebookRecipientSettings> m_recipientSettings;
    std::optional<UserID> m_sharerUserId;
    std::optional<QString> m_recipientUsername;
    std::optional<UserID> m_recipientUserId;
    std::optional<Timestamp> m_serviceAssigned;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOKDATA_H
