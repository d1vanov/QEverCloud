/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/BootstrapSettingsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BootstrapSettingsBuilder::Impl final:
    public QSharedData
{
public:
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

BootstrapSettingsBuilder::BootstrapSettingsBuilder() :
    d(new BootstrapSettingsBuilder::Impl)
{}

BootstrapSettingsBuilder::BootstrapSettingsBuilder(BootstrapSettingsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

BootstrapSettingsBuilder::~BootstrapSettingsBuilder() noexcept = default;

BootstrapSettingsBuilder & BootstrapSettingsBuilder::operator=(BootstrapSettingsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setServiceHost(QString serviceHost)
{
    d->m_serviceHost = std::move(serviceHost);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setMarketingUrl(QString marketingUrl)
{
    d->m_marketingUrl = std::move(marketingUrl);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setSupportUrl(QString supportUrl)
{
    d->m_supportUrl = std::move(supportUrl);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setAccountEmailDomain(QString accountEmailDomain)
{
    d->m_accountEmailDomain = std::move(accountEmailDomain);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableFacebookSharing(std::optional<bool> enableFacebookSharing)
{
    d->m_enableFacebookSharing = std::move(enableFacebookSharing);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableGiftSubscriptions(std::optional<bool> enableGiftSubscriptions)
{
    d->m_enableGiftSubscriptions = std::move(enableGiftSubscriptions);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableSupportTickets(std::optional<bool> enableSupportTickets)
{
    d->m_enableSupportTickets = std::move(enableSupportTickets);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableSharedNotebooks(std::optional<bool> enableSharedNotebooks)
{
    d->m_enableSharedNotebooks = std::move(enableSharedNotebooks);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableSingleNoteSharing(std::optional<bool> enableSingleNoteSharing)
{
    d->m_enableSingleNoteSharing = std::move(enableSingleNoteSharing);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableSponsoredAccounts(std::optional<bool> enableSponsoredAccounts)
{
    d->m_enableSponsoredAccounts = std::move(enableSponsoredAccounts);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableTwitterSharing(std::optional<bool> enableTwitterSharing)
{
    d->m_enableTwitterSharing = std::move(enableTwitterSharing);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableLinkedInSharing(std::optional<bool> enableLinkedInSharing)
{
    d->m_enableLinkedInSharing = std::move(enableLinkedInSharing);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnablePublicNotebooks(std::optional<bool> enablePublicNotebooks)
{
    d->m_enablePublicNotebooks = std::move(enablePublicNotebooks);
    return *this;
}

BootstrapSettingsBuilder & BootstrapSettingsBuilder::setEnableGoogle(std::optional<bool> enableGoogle)
{
    d->m_enableGoogle = std::move(enableGoogle);
    return *this;
}

BootstrapSettings BootstrapSettingsBuilder::build()
{
    BootstrapSettings result;

    result.setServiceHost(std::move(d->m_serviceHost));
    result.setMarketingUrl(std::move(d->m_marketingUrl));
    result.setSupportUrl(std::move(d->m_supportUrl));
    result.setAccountEmailDomain(std::move(d->m_accountEmailDomain));
    result.setEnableFacebookSharing(std::move(d->m_enableFacebookSharing));
    result.setEnableGiftSubscriptions(std::move(d->m_enableGiftSubscriptions));
    result.setEnableSupportTickets(std::move(d->m_enableSupportTickets));
    result.setEnableSharedNotebooks(std::move(d->m_enableSharedNotebooks));
    result.setEnableSingleNoteSharing(std::move(d->m_enableSingleNoteSharing));
    result.setEnableSponsoredAccounts(std::move(d->m_enableSponsoredAccounts));
    result.setEnableTwitterSharing(std::move(d->m_enableTwitterSharing));
    result.setEnableLinkedInSharing(std::move(d->m_enableLinkedInSharing));
    result.setEnablePublicNotebooks(std::move(d->m_enablePublicNotebooks));
    result.setEnableGoogle(std::move(d->m_enableGoogle));

    d->m_serviceHost = QString{};
    d->m_marketingUrl = QString{};
    d->m_supportUrl = QString{};
    d->m_accountEmailDomain = QString{};
    d->m_enableFacebookSharing = {};
    d->m_enableGiftSubscriptions = {};
    d->m_enableSupportTickets = {};
    d->m_enableSharedNotebooks = {};
    d->m_enableSingleNoteSharing = {};
    d->m_enableSponsoredAccounts = {};
    d->m_enableTwitterSharing = {};
    d->m_enableLinkedInSharing = {};
    d->m_enablePublicNotebooks = {};
    d->m_enableGoogle = {};

    return result;
}

} // namespace qevercloud
