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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKIMPL_H
#define QEVERCLOUD_GENERATED_NOTEBOOKIMPL_H

#include <qevercloud/generated/types/Notebook.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Notebook::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const Notebook::Impl & other) = default;
    Impl(Notebook::Impl && other) noexcept = default;

    Notebook::Impl & operator=(const Notebook::Impl & other) = delete;
    Notebook::Impl & operator=(Notebook::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const Notebook::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const Notebook::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_localId;
    QString m_parentLocalId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;

    std::optional<Guid> m_guid;
    std::optional<QString> m_name;
    std::optional<qint32> m_updateSequenceNum;
    std::optional<bool> m_defaultNotebook;
    std::optional<Timestamp> m_serviceCreated;
    std::optional<Timestamp> m_serviceUpdated;
    std::optional<Publishing> m_publishing;
    std::optional<bool> m_published;
    std::optional<QString> m_stack;
    std::optional<QList<qint64>> m_sharedNotebookIds;
    std::optional<QList<SharedNotebook>> m_sharedNotebooks;
    std::optional<BusinessNotebook> m_businessNotebook;
    std::optional<User> m_contact;
    std::optional<NotebookRestrictions> m_restrictions;
    std::optional<NotebookRecipientSettings> m_recipientSettings;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKIMPL_H
