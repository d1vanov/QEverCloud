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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGSIMPL_H
#define QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGSIMPL_H

#include <generated/types/BootstrapSettings.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BootstrapSettings::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const BootstrapSettings::Impl & other) = default;
    Impl(BootstrapSettings::Impl && other) noexcept = default;

    BootstrapSettings::Impl & operator=(const BootstrapSettings::Impl & other) = delete;
    BootstrapSettings::Impl & operator=(BootstrapSettings::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const BootstrapSettings::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const BootstrapSettings::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_serviceHost;
    QString m_marketingUrl;
    QString m_supportUrl;
    QString m_accountEmailDomain;
    std::optional<bool> m_enableFacebookSharing;
    std::optional<bool> m_enableGiftSubscriptions;
    std::optional<bool> m_enableSupportTickets;
    std::optional<bool> m_enableSharedNotebooks;
    std::optional<bool> m_enableSingleNoteSharing;
    std::optional<bool> m_enableSponsoredAccounts;
    std::optional<bool> m_enableTwitterSharing;
    std::optional<bool> m_enableLinkedInSharing;
    std::optional<bool> m_enablePublicNotebooks;
    std::optional<bool> m_enableGoogle;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGSIMPL_H
