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

#ifndef QEVERCLOUD_GENERATED_USERIDENTITYDATA_H
#define QEVERCLOUD_GENERATED_USERIDENTITYDATA_H

#include <generated/types/UserIdentity.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserIdentity::UserIdentityData final:
    public QSharedData,
    public Printable
{
public:
    UserIdentityData() = default;
    UserIdentityData(const UserIdentityData & other) = default;
    UserIdentityData(UserIdentityData && other) noexcept = default;

    UserIdentityData & operator=(const UserIdentityData & other) = delete;
    UserIdentityData & operator=(UserIdentityData && other) = delete;

    ~UserIdentityData() noexcept override = default;

    [[nodiscard]] bool operator==(const UserIdentityData & other) const noexcept;
    [[nodiscard]] bool operator!=(const UserIdentityData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<UserIdentityType> m_type;
    std::optional<QString> m_stringIdentifier;
    std::optional<qint64> m_longIdentifier;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERIDENTITYDATA_H
