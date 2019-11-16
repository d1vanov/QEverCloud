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

#include "../Common.h"
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
    void shouldExecuteCompleteTwoFactorAuthentication();
    void shouldExecuteRevokeLongSession();
    void shouldExecuteAuthenticateToBusiness();
    void shouldExecuteGetUser();
    void shouldExecuteGetPublicUserInfo();
    void shouldExecuteGetUserUrls();
    void shouldExecuteInviteToBusiness();
    void shouldExecuteRemoveFromBusiness();
    void shouldExecuteUpdateBusinessUserIdentifier();
    void shouldExecuteListBusinessUsers();
    void shouldExecuteListBusinessInvitations();
    void shouldExecuteGetAccountLimits();
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TESTUSERSTORE_H
