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

#ifndef QEVERCLOUD_GENERATED_SHAREDNOTEIMPL
#define QEVERCLOUD_GENERATED_SHAREDNOTEIMPL

#include <qevercloud/types/SharedNote.h>
#include <QHash>
#include <QSharedData>
#include <QVariant>

namespace qevercloud {

class Q_DECL_HIDDEN SharedNote::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const SharedNote::Impl & other) = default;
    Impl(SharedNote::Impl && other) noexcept = default;

    SharedNote::Impl & operator=(const SharedNote::Impl & other) = delete;
    SharedNote::Impl & operator=(SharedNote::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    Guid m_noteGuid;
    std::optional<UserID> m_sharerUserID;
    std::optional<Identity> m_recipientIdentity;
    std::optional<SharedNotePrivilegeLevel> m_privilege;
    std::optional<Timestamp> m_serviceCreated;
    std::optional<Timestamp> m_serviceUpdated;
    std::optional<Timestamp> m_serviceAssigned;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SHAREDNOTEIMPL
