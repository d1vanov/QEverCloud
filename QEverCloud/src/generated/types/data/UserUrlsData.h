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

#ifndef QEVERCLOUD_GENERATED_USERURLSDATA_H
#define QEVERCLOUD_GENERATED_USERURLSDATA_H

#include <generated/types/UserUrls.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserUrls::UserUrlsData final:
    public QSharedData,
    public Printable
{
public:
    UserUrlsData() = default;
    UserUrlsData(const UserUrlsData & other) = default;
    UserUrlsData(UserUrlsData && other) noexcept = default;

    UserUrlsData & operator=(const UserUrlsData & other) = delete;
    UserUrlsData & operator=(UserUrlsData && other) = delete;

    ~UserUrlsData() noexcept override = default;

    [[nodiscard]] bool operator==(const UserUrlsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const UserUrlsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
    std::optional<QString> m_userStoreUrl;
    std::optional<QString> m_utilityUrl;
    std::optional<QString> m_messageStoreUrl;
    std::optional<QString> m_userWebSocketUrl;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERURLSDATA_H
