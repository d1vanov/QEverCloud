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

#ifndef QEVERCLOUD_GENERATED_USERURLSIMPL
#define QEVERCLOUD_GENERATED_USERURLSIMPL

#include <qevercloud/types/UserUrls.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN UserUrls::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const UserUrls::Impl & other) = default;
    Impl(UserUrls::Impl && other) noexcept = default;

    UserUrls::Impl & operator=(const UserUrls::Impl & other) = delete;
    UserUrls::Impl & operator=(UserUrls::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_noteStoreUrl;
    std::optional<QString> m_webApiUrlPrefix;
    std::optional<QString> m_userStoreUrl;
    std::optional<QString> m_utilityUrl;
    std::optional<QString> m_messageStoreUrl;
    std::optional<QString> m_userWebSocketUrl;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERURLSIMPL
