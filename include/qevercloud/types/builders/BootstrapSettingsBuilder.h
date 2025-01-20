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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGSBUILDER
#define QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BootstrapSettings.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT BootstrapSettingsBuilder
{
public:
    BootstrapSettingsBuilder();

    BootstrapSettingsBuilder(BootstrapSettingsBuilder && other) noexcept;

    ~BootstrapSettingsBuilder() noexcept;

    BootstrapSettingsBuilder & operator=(BootstrapSettingsBuilder && other) noexcept;

    BootstrapSettingsBuilder & setServiceHost(QString serviceHost);
    BootstrapSettingsBuilder & setMarketingUrl(QString marketingUrl);
    BootstrapSettingsBuilder & setSupportUrl(QString supportUrl);
    BootstrapSettingsBuilder & setAccountEmailDomain(QString accountEmailDomain);
    BootstrapSettingsBuilder & setEnableFacebookSharing(std::optional<bool> enableFacebookSharing);
    BootstrapSettingsBuilder & setEnableGiftSubscriptions(std::optional<bool> enableGiftSubscriptions);
    BootstrapSettingsBuilder & setEnableSupportTickets(std::optional<bool> enableSupportTickets);
    BootstrapSettingsBuilder & setEnableSharedNotebooks(std::optional<bool> enableSharedNotebooks);
    BootstrapSettingsBuilder & setEnableSingleNoteSharing(std::optional<bool> enableSingleNoteSharing);
    BootstrapSettingsBuilder & setEnableSponsoredAccounts(std::optional<bool> enableSponsoredAccounts);
    BootstrapSettingsBuilder & setEnableTwitterSharing(std::optional<bool> enableTwitterSharing);
    BootstrapSettingsBuilder & setEnableLinkedInSharing(std::optional<bool> enableLinkedInSharing);
    BootstrapSettingsBuilder & setEnablePublicNotebooks(std::optional<bool> enablePublicNotebooks);
    BootstrapSettingsBuilder & setEnableGoogle(std::optional<bool> enableGoogle);

    [[nodiscard]] BootstrapSettings build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGSBUILDER
