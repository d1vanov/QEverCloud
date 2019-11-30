/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_TESTUSERSTORE_H
#define QEVERCLOUD_GENERATED_TESTUSERSTORE_H

#include "../SocketHelpers.h"
#include <QObject>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

class UserStoreTester: public QObject
{
    Q_OBJECT
public:
    explicit UserStoreTester(QObject * parent = nullptr);

private Q_SLOTS:
    void shouldExecuteCheckVersion();
    void shouldDeliverThriftExceptionInCheckVersion();
    void shouldExecuteGetBootstrapInfo();
    void shouldDeliverThriftExceptionInGetBootstrapInfo();
    void shouldExecuteAuthenticateLongSession();
    void shouldDeliverEDAMUserExceptionInAuthenticateLongSession();
    void shouldDeliverEDAMSystemExceptionInAuthenticateLongSession();
    void shouldDeliverThriftExceptionInAuthenticateLongSession();
    void shouldExecuteCompleteTwoFactorAuthentication();
    void shouldDeliverEDAMUserExceptionInCompleteTwoFactorAuthentication();
    void shouldDeliverEDAMSystemExceptionInCompleteTwoFactorAuthentication();
    void shouldDeliverThriftExceptionInCompleteTwoFactorAuthentication();
    void shouldExecuteRevokeLongSession();
    void shouldDeliverEDAMUserExceptionInRevokeLongSession();
    void shouldDeliverEDAMSystemExceptionInRevokeLongSession();
    void shouldDeliverThriftExceptionInRevokeLongSession();
    void shouldExecuteAuthenticateToBusiness();
    void shouldDeliverEDAMUserExceptionInAuthenticateToBusiness();
    void shouldDeliverEDAMSystemExceptionInAuthenticateToBusiness();
    void shouldDeliverThriftExceptionInAuthenticateToBusiness();
    void shouldExecuteGetUser();
    void shouldDeliverEDAMUserExceptionInGetUser();
    void shouldDeliverEDAMSystemExceptionInGetUser();
    void shouldDeliverThriftExceptionInGetUser();
    void shouldExecuteGetPublicUserInfo();
    void shouldDeliverEDAMNotFoundExceptionInGetPublicUserInfo();
    void shouldDeliverEDAMSystemExceptionInGetPublicUserInfo();
    void shouldDeliverEDAMUserExceptionInGetPublicUserInfo();
    void shouldDeliverThriftExceptionInGetPublicUserInfo();
    void shouldExecuteGetUserUrls();
    void shouldDeliverEDAMUserExceptionInGetUserUrls();
    void shouldDeliverEDAMSystemExceptionInGetUserUrls();
    void shouldDeliverThriftExceptionInGetUserUrls();
    void shouldExecuteInviteToBusiness();
    void shouldDeliverEDAMUserExceptionInInviteToBusiness();
    void shouldDeliverEDAMSystemExceptionInInviteToBusiness();
    void shouldDeliverThriftExceptionInInviteToBusiness();
    void shouldExecuteRemoveFromBusiness();
    void shouldDeliverEDAMUserExceptionInRemoveFromBusiness();
    void shouldDeliverEDAMSystemExceptionInRemoveFromBusiness();
    void shouldDeliverEDAMNotFoundExceptionInRemoveFromBusiness();
    void shouldDeliverThriftExceptionInRemoveFromBusiness();
    void shouldExecuteUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMUserExceptionInUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMSystemExceptionInUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMNotFoundExceptionInUpdateBusinessUserIdentifier();
    void shouldDeliverThriftExceptionInUpdateBusinessUserIdentifier();
    void shouldExecuteListBusinessUsers();
    void shouldDeliverEDAMUserExceptionInListBusinessUsers();
    void shouldDeliverEDAMSystemExceptionInListBusinessUsers();
    void shouldDeliverThriftExceptionInListBusinessUsers();
    void shouldExecuteListBusinessInvitations();
    void shouldDeliverEDAMUserExceptionInListBusinessInvitations();
    void shouldDeliverEDAMSystemExceptionInListBusinessInvitations();
    void shouldDeliverThriftExceptionInListBusinessInvitations();
    void shouldExecuteGetAccountLimits();
    void shouldDeliverEDAMUserExceptionInGetAccountLimits();
    void shouldDeliverThriftExceptionInGetAccountLimits();
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TESTUSERSTORE_H
