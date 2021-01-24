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

#include <qevercloud/generated/types/BootstrapSettings.h>

#include "impl/BootstrapSettingsImpl.h"

namespace qevercloud {

BootstrapSettings::BootstrapSettings() :
    d(new BootstrapSettings::Impl)
 {}

BootstrapSettings::BootstrapSettings(const BootstrapSettings & other) :
    d(other.d)
{}

BootstrapSettings::BootstrapSettings(BootstrapSettings && other) noexcept :
    d(std::move(other.d))
{}

BootstrapSettings::~BootstrapSettings() noexcept {}

BootstrapSettings & BootstrapSettings::operator=(const BootstrapSettings & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

BootstrapSettings & BootstrapSettings::operator=(BootstrapSettings && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const QString & BootstrapSettings::serviceHost() const noexcept
{
    return d->m_serviceHost;
}

void BootstrapSettings::setServiceHost(QString serviceHost)
{
    d->m_serviceHost = serviceHost;
}

const QString & BootstrapSettings::marketingUrl() const noexcept
{
    return d->m_marketingUrl;
}

void BootstrapSettings::setMarketingUrl(QString marketingUrl)
{
    d->m_marketingUrl = marketingUrl;
}

const QString & BootstrapSettings::supportUrl() const noexcept
{
    return d->m_supportUrl;
}

void BootstrapSettings::setSupportUrl(QString supportUrl)
{
    d->m_supportUrl = supportUrl;
}

const QString & BootstrapSettings::accountEmailDomain() const noexcept
{
    return d->m_accountEmailDomain;
}

void BootstrapSettings::setAccountEmailDomain(QString accountEmailDomain)
{
    d->m_accountEmailDomain = accountEmailDomain;
}

const std::optional<bool> & BootstrapSettings::enableFacebookSharing() const noexcept
{
    return d->m_enableFacebookSharing;
}

std::optional<bool> & BootstrapSettings::mutableEnableFacebookSharing()
{
    return d->m_enableFacebookSharing;
}

void BootstrapSettings::setEnableFacebookSharing(std::optional<bool> enableFacebookSharing)
{
    d->m_enableFacebookSharing = enableFacebookSharing;
}

const std::optional<bool> & BootstrapSettings::enableGiftSubscriptions() const noexcept
{
    return d->m_enableGiftSubscriptions;
}

std::optional<bool> & BootstrapSettings::mutableEnableGiftSubscriptions()
{
    return d->m_enableGiftSubscriptions;
}

void BootstrapSettings::setEnableGiftSubscriptions(std::optional<bool> enableGiftSubscriptions)
{
    d->m_enableGiftSubscriptions = enableGiftSubscriptions;
}

const std::optional<bool> & BootstrapSettings::enableSupportTickets() const noexcept
{
    return d->m_enableSupportTickets;
}

std::optional<bool> & BootstrapSettings::mutableEnableSupportTickets()
{
    return d->m_enableSupportTickets;
}

void BootstrapSettings::setEnableSupportTickets(std::optional<bool> enableSupportTickets)
{
    d->m_enableSupportTickets = enableSupportTickets;
}

const std::optional<bool> & BootstrapSettings::enableSharedNotebooks() const noexcept
{
    return d->m_enableSharedNotebooks;
}

std::optional<bool> & BootstrapSettings::mutableEnableSharedNotebooks()
{
    return d->m_enableSharedNotebooks;
}

void BootstrapSettings::setEnableSharedNotebooks(std::optional<bool> enableSharedNotebooks)
{
    d->m_enableSharedNotebooks = enableSharedNotebooks;
}

const std::optional<bool> & BootstrapSettings::enableSingleNoteSharing() const noexcept
{
    return d->m_enableSingleNoteSharing;
}

std::optional<bool> & BootstrapSettings::mutableEnableSingleNoteSharing()
{
    return d->m_enableSingleNoteSharing;
}

void BootstrapSettings::setEnableSingleNoteSharing(std::optional<bool> enableSingleNoteSharing)
{
    d->m_enableSingleNoteSharing = enableSingleNoteSharing;
}

const std::optional<bool> & BootstrapSettings::enableSponsoredAccounts() const noexcept
{
    return d->m_enableSponsoredAccounts;
}

std::optional<bool> & BootstrapSettings::mutableEnableSponsoredAccounts()
{
    return d->m_enableSponsoredAccounts;
}

void BootstrapSettings::setEnableSponsoredAccounts(std::optional<bool> enableSponsoredAccounts)
{
    d->m_enableSponsoredAccounts = enableSponsoredAccounts;
}

const std::optional<bool> & BootstrapSettings::enableTwitterSharing() const noexcept
{
    return d->m_enableTwitterSharing;
}

std::optional<bool> & BootstrapSettings::mutableEnableTwitterSharing()
{
    return d->m_enableTwitterSharing;
}

void BootstrapSettings::setEnableTwitterSharing(std::optional<bool> enableTwitterSharing)
{
    d->m_enableTwitterSharing = enableTwitterSharing;
}

const std::optional<bool> & BootstrapSettings::enableLinkedInSharing() const noexcept
{
    return d->m_enableLinkedInSharing;
}

std::optional<bool> & BootstrapSettings::mutableEnableLinkedInSharing()
{
    return d->m_enableLinkedInSharing;
}

void BootstrapSettings::setEnableLinkedInSharing(std::optional<bool> enableLinkedInSharing)
{
    d->m_enableLinkedInSharing = enableLinkedInSharing;
}

const std::optional<bool> & BootstrapSettings::enablePublicNotebooks() const noexcept
{
    return d->m_enablePublicNotebooks;
}

std::optional<bool> & BootstrapSettings::mutableEnablePublicNotebooks()
{
    return d->m_enablePublicNotebooks;
}

void BootstrapSettings::setEnablePublicNotebooks(std::optional<bool> enablePublicNotebooks)
{
    d->m_enablePublicNotebooks = enablePublicNotebooks;
}

const std::optional<bool> & BootstrapSettings::enableGoogle() const noexcept
{
    return d->m_enableGoogle;
}

std::optional<bool> & BootstrapSettings::mutableEnableGoogle()
{
    return d->m_enableGoogle;
}

void BootstrapSettings::setEnableGoogle(std::optional<bool> enableGoogle)
{
    d->m_enableGoogle = enableGoogle;
}

void BootstrapSettings::print(QTextStream & strm) const
{
    d->print(strm);
}

bool BootstrapSettings::operator==(const BootstrapSettings & other) const noexcept
{
    return *d == *other.d;
}

bool BootstrapSettings::operator!=(const BootstrapSettings & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
