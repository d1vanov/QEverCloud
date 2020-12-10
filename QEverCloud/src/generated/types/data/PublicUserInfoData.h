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

#ifndef QEVERCLOUD_GENERATED_PUBLICUSERINFODATA_H
#define QEVERCLOUD_GENERATED_PUBLICUSERINFODATA_H

#include <generated/types/PublicUserInfo.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN PublicUserInfo::PublicUserInfoData final:
    public QSharedData,
    public Printable
{
public:
    PublicUserInfoData() = default;
    PublicUserInfoData(const PublicUserInfoData & other) = default;
    PublicUserInfoData(PublicUserInfoData && other) noexcept = default;

    PublicUserInfoData & operator=(const PublicUserInfoData & other) = delete;
    PublicUserInfoData & operator=(PublicUserInfoData && other) = delete;

    ~PublicUserInfoData() noexcept override = default;

    [[nodiscard]] bool operator==(const PublicUserInfoData & other) const noexcept;
    [[nodiscard]] bool operator!=(const PublicUserInfoData & other) const noexcept;

    void print(QTextStream & strm) const override;

    UserID m_userId = 0;
    std::optional<ServiceLevel> m_serviceLevel;
    std::optional<QString> m_username;
    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_PUBLICUSERINFODATA_H
