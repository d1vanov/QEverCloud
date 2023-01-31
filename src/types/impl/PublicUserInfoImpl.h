/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_PUBLICUSERINFOIMPL
#define QEVERCLOUD_GENERATED_PUBLICUSERINFOIMPL

#include <qevercloud/types/PublicUserInfo.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN PublicUserInfo::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const PublicUserInfo::Impl & other) = default;
    Impl(PublicUserInfo::Impl && other) noexcept = default;

    PublicUserInfo::Impl & operator=(const PublicUserInfo::Impl & other) = delete;
    PublicUserInfo::Impl & operator=(PublicUserInfo::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    UserID m_userId = 0;
    std::optional<ServiceLevel> m_serviceLevel;
    std::optional<QString> m_username;
    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_PUBLICUSERINFOIMPL
