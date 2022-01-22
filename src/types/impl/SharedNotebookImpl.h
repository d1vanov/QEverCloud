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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEBOOKIMPL
#define QEVERCLOUD_GENERATED_SHAREDNOTEBOOKIMPL

#include <qevercloud/types/SharedNotebook.h>
#include <QHash>
#include <QSharedData>
#include <QVariant>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNotebook::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const SharedNotebook::Impl & other) = default;
    Impl(SharedNotebook::Impl && other) noexcept = default;

    SharedNotebook::Impl & operator=(const SharedNotebook::Impl & other) = delete;
    SharedNotebook::Impl & operator=(SharedNotebook::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
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

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEBOOKIMPL
