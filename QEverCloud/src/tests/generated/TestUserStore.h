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
    void shouldExecuteGetBootstrapInfo();
    void shouldExecuteAuthenticateLongSession();
    void shouldDeliverEDAMUserExceptionInAuthenticateLongSession();
    void shouldDeliverEDAMSystemExceptionInAuthenticateLongSession();
    void shouldExecuteCompleteTwoFactorAuthentication();
    void shouldDeliverEDAMUserExceptionInCompleteTwoFactorAuthentication();
    void shouldDeliverEDAMSystemExceptionInCompleteTwoFactorAuthentication();
    void shouldExecuteRevokeLongSession();
    void shouldDeliverEDAMUserExceptionInRevokeLongSession();
    void shouldDeliverEDAMSystemExceptionInRevokeLongSession();
    void shouldExecuteAuthenticateToBusiness();
    void shouldDeliverEDAMUserExceptionInAuthenticateToBusiness();
    void shouldDeliverEDAMSystemExceptionInAuthenticateToBusiness();
    void shouldExecuteGetUser();
    void shouldDeliverEDAMUserExceptionInGetUser();
    void shouldDeliverEDAMSystemExceptionInGetUser();
    void shouldExecuteGetPublicUserInfo();
    void shouldDeliverEDAMNotFoundExceptionInGetPublicUserInfo();
    void shouldDeliverEDAMSystemExceptionInGetPublicUserInfo();
    void shouldDeliverEDAMUserExceptionInGetPublicUserInfo();
    void shouldExecuteGetUserUrls();
    void shouldDeliverEDAMUserExceptionInGetUserUrls();
    void shouldDeliverEDAMSystemExceptionInGetUserUrls();
    void shouldExecuteInviteToBusiness();
    void shouldDeliverEDAMUserExceptionInInviteToBusiness();
    void shouldDeliverEDAMSystemExceptionInInviteToBusiness();
    void shouldExecuteRemoveFromBusiness();
    void shouldDeliverEDAMUserExceptionInRemoveFromBusiness();
    void shouldDeliverEDAMSystemExceptionInRemoveFromBusiness();
    void shouldDeliverEDAMNotFoundExceptionInRemoveFromBusiness();
    void shouldExecuteUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMUserExceptionInUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMSystemExceptionInUpdateBusinessUserIdentifier();
    void shouldDeliverEDAMNotFoundExceptionInUpdateBusinessUserIdentifier();
    void shouldExecuteListBusinessUsers();
    void shouldDeliverEDAMUserExceptionInListBusinessUsers();
    void shouldDeliverEDAMSystemExceptionInListBusinessUsers();
    void shouldExecuteListBusinessInvitations();
    void shouldDeliverEDAMUserExceptionInListBusinessInvitations();
    void shouldDeliverEDAMSystemExceptionInListBusinessInvitations();
    void shouldExecuteGetAccountLimits();
    void shouldDeliverEDAMUserExceptionInGetAccountLimits();
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TESTUSERSTORE_H
