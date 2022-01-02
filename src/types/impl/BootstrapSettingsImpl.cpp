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

#include "BootstrapSettingsImpl.h"

#include "../../Impl.h"

#include <QTextStream>

namespace qevercloud {

void BootstrapSettings::Impl::print(QTextStream & strm) const
{
    strm << "BootstrapSettings: {\n";
    strm << "    serviceHost = "
        << m_serviceHost << "\n";
    strm << "    marketingUrl = "
        << m_marketingUrl << "\n";
    strm << "    supportUrl = "
        << m_supportUrl << "\n";
    strm << "    accountEmailDomain = "
        << m_accountEmailDomain << "\n";

    if (m_enableFacebookSharing) {
        strm << "    enableFacebookSharing = "
            << *m_enableFacebookSharing << "\n";
    }
    else {
        strm << "    enableFacebookSharing is not set\n";
    }

    if (m_enableGiftSubscriptions) {
        strm << "    enableGiftSubscriptions = "
            << *m_enableGiftSubscriptions << "\n";
    }
    else {
        strm << "    enableGiftSubscriptions is not set\n";
    }

    if (m_enableSupportTickets) {
        strm << "    enableSupportTickets = "
            << *m_enableSupportTickets << "\n";
    }
    else {
        strm << "    enableSupportTickets is not set\n";
    }

    if (m_enableSharedNotebooks) {
        strm << "    enableSharedNotebooks = "
            << *m_enableSharedNotebooks << "\n";
    }
    else {
        strm << "    enableSharedNotebooks is not set\n";
    }

    if (m_enableSingleNoteSharing) {
        strm << "    enableSingleNoteSharing = "
            << *m_enableSingleNoteSharing << "\n";
    }
    else {
        strm << "    enableSingleNoteSharing is not set\n";
    }

    if (m_enableSponsoredAccounts) {
        strm << "    enableSponsoredAccounts = "
            << *m_enableSponsoredAccounts << "\n";
    }
    else {
        strm << "    enableSponsoredAccounts is not set\n";
    }

    if (m_enableTwitterSharing) {
        strm << "    enableTwitterSharing = "
            << *m_enableTwitterSharing << "\n";
    }
    else {
        strm << "    enableTwitterSharing is not set\n";
    }

    if (m_enableLinkedInSharing) {
        strm << "    enableLinkedInSharing = "
            << *m_enableLinkedInSharing << "\n";
    }
    else {
        strm << "    enableLinkedInSharing is not set\n";
    }

    if (m_enablePublicNotebooks) {
        strm << "    enablePublicNotebooks = "
            << *m_enablePublicNotebooks << "\n";
    }
    else {
        strm << "    enablePublicNotebooks is not set\n";
    }

    if (m_enableGoogle) {
        strm << "    enableGoogle = "
            << *m_enableGoogle << "\n";
    }
    else {
        strm << "    enableGoogle is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
