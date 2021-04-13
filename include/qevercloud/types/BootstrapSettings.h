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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGS
#define QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGS

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure describes a collection of bootstrap settings.
 **/
class QEVERCLOUD_EXPORT BootstrapSettings: public Printable
{
    Q_GADGET
public:
    BootstrapSettings();
    BootstrapSettings(const BootstrapSettings & other);
    BootstrapSettings(BootstrapSettings && other) noexcept;
    ~BootstrapSettings() noexcept override;

    BootstrapSettings & operator=(const BootstrapSettings & other);
    BootstrapSettings & operator=(BootstrapSettings && other) noexcept;

    /**
     * The hostname and optional port for composing Evernote web service URLs.
     * This URL can be used to access the UserStore and related services,
     * but must not be used to compose the NoteStore URL. Client applications
     * must handle serviceHost values that include only the hostname
     * (e.g. www.evernote.com) or both the hostname and port (e.g. www.evernote.com:8080).
     * If no port is specified, or if port 443 is specified, client applications must
     * use the scheme "https" when composing URLs. Otherwise, a client must use the
     * scheme "http".
     */
    [[nodiscard]] const QString & serviceHost() const noexcept;
    void setServiceHost(QString serviceHost);

    /**
     * The URL stem for the Evernote corporate marketing website, e.g. http://www.evernote.com.
     * This stem can be used to compose website URLs. For example, the URL of the Evernote
     * Trunk is composed by appending "/about/trunk/" to the value of marketingUrl.
     */
    [[nodiscard]] const QString & marketingUrl() const noexcept;
    void setMarketingUrl(QString marketingUrl);

    /**
     * The full URL for the Evernote customer support website, e.g. https://support.evernote.com.
     */
    [[nodiscard]] const QString & supportUrl() const noexcept;
    void setSupportUrl(QString supportUrl);

    /**
     * The domain used for an Evernote user's incoming email address, which allows notes to
     * be emailed into an account. E.g. m.evernote.com.
     */
    [[nodiscard]] const QString & accountEmailDomain() const noexcept;
    void setAccountEmailDomain(QString accountEmailDomain);

    /**
     * Whether the client application should enable sharing of notes on Facebook.
     */
    [[nodiscard]] const std::optional<bool> & enableFacebookSharing() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableFacebookSharing();
    void setEnableFacebookSharing(std::optional<bool> enableFacebookSharing);

    /**
     * Whether the client application should enable gift subscriptions.
     */
    [[nodiscard]] const std::optional<bool> & enableGiftSubscriptions() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableGiftSubscriptions();
    void setEnableGiftSubscriptions(std::optional<bool> enableGiftSubscriptions);

    /**
     * Whether the client application should enable in-client creation of support tickets.
     */
    [[nodiscard]] const std::optional<bool> & enableSupportTickets() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableSupportTickets();
    void setEnableSupportTickets(std::optional<bool> enableSupportTickets);

    /**
     * Whether the client application should enable shared notebooks.
     */
    [[nodiscard]] const std::optional<bool> & enableSharedNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableSharedNotebooks();
    void setEnableSharedNotebooks(std::optional<bool> enableSharedNotebooks);

    /**
     * Whether the client application should enable single note sharing.
     */
    [[nodiscard]] const std::optional<bool> & enableSingleNoteSharing() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableSingleNoteSharing();
    void setEnableSingleNoteSharing(std::optional<bool> enableSingleNoteSharing);

    /**
     * Whether the client application should enable sponsored accounts.
     */
    [[nodiscard]] const std::optional<bool> & enableSponsoredAccounts() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableSponsoredAccounts();
    void setEnableSponsoredAccounts(std::optional<bool> enableSponsoredAccounts);

    /**
     * Whether the client application should enable sharing of notes on Twitter.
     */
    [[nodiscard]] const std::optional<bool> & enableTwitterSharing() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableTwitterSharing();
    void setEnableTwitterSharing(std::optional<bool> enableTwitterSharing);

    [[nodiscard]] const std::optional<bool> & enableLinkedInSharing() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableLinkedInSharing();
    void setEnableLinkedInSharing(std::optional<bool> enableLinkedInSharing);

    [[nodiscard]] const std::optional<bool> & enablePublicNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnablePublicNotebooks();
    void setEnablePublicNotebooks(std::optional<bool> enablePublicNotebooks);

    /**
     * Whether the client application should enable authentication with Google,
     * for example to allow integration with a user's Gmail contacts.
     */
    [[nodiscard]] const std::optional<bool> & enableGoogle() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableEnableGoogle();
    void setEnableGoogle(std::optional<bool> enableGoogle);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(QString serviceHost READ serviceHost WRITE setServiceHost)
    Q_PROPERTY(QString marketingUrl READ marketingUrl WRITE setMarketingUrl)
    Q_PROPERTY(QString supportUrl READ supportUrl WRITE setSupportUrl)
    Q_PROPERTY(QString accountEmailDomain READ accountEmailDomain WRITE setAccountEmailDomain)
    Q_PROPERTY(std::optional<bool> enableFacebookSharing READ enableFacebookSharing WRITE setEnableFacebookSharing)
    Q_PROPERTY(std::optional<bool> enableGiftSubscriptions READ enableGiftSubscriptions WRITE setEnableGiftSubscriptions)
    Q_PROPERTY(std::optional<bool> enableSupportTickets READ enableSupportTickets WRITE setEnableSupportTickets)
    Q_PROPERTY(std::optional<bool> enableSharedNotebooks READ enableSharedNotebooks WRITE setEnableSharedNotebooks)
    Q_PROPERTY(std::optional<bool> enableSingleNoteSharing READ enableSingleNoteSharing WRITE setEnableSingleNoteSharing)
    Q_PROPERTY(std::optional<bool> enableSponsoredAccounts READ enableSponsoredAccounts WRITE setEnableSponsoredAccounts)
    Q_PROPERTY(std::optional<bool> enableTwitterSharing READ enableTwitterSharing WRITE setEnableTwitterSharing)
    Q_PROPERTY(std::optional<bool> enableLinkedInSharing READ enableLinkedInSharing WRITE setEnableLinkedInSharing)
    Q_PROPERTY(std::optional<bool> enablePublicNotebooks READ enablePublicNotebooks WRITE setEnablePublicNotebooks)
    Q_PROPERTY(std::optional<bool> enableGoogle READ enableGoogle WRITE setEnableGoogle)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const BootstrapSettings & lhs, const BootstrapSettings & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const BootstrapSettings & lhs, const BootstrapSettings & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::BootstrapSettings)

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPSETTINGS
