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

#ifndef QEVERCLOUD_GENERATED_USERIDENTITYIMPL_H
#define QEVERCLOUD_GENERATED_USERIDENTITYIMPL_H

#include <qevercloud/generated/types/UserIdentity.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserIdentity::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const UserIdentity::Impl & other) = default;
    Impl(UserIdentity::Impl && other) noexcept = default;

    UserIdentity::Impl & operator=(const UserIdentity::Impl & other) = delete;
    UserIdentity::Impl & operator=(UserIdentity::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const UserIdentity::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const UserIdentity::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<UserIdentityType> m_type;
    std::optional<QString> m_stringIdentifier;
    std::optional<qint64> m_longIdentifier;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERIDENTITYIMPL_H
