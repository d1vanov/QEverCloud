/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_USERIDENTITYBUILDER
#define QEVERCLOUD_GENERATED_USERIDENTITYBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UserIdentity.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT UserIdentityBuilder
{
public:
    UserIdentityBuilder();

    UserIdentityBuilder(UserIdentityBuilder && other) noexcept;

    ~UserIdentityBuilder() noexcept;

    UserIdentityBuilder & operator=(UserIdentityBuilder && other) noexcept;

    UserIdentityBuilder & setType(std::optional<UserIdentityType> type);
    UserIdentityBuilder & setStringIdentifier(std::optional<QString> stringIdentifier);
    UserIdentityBuilder & setLongIdentifier(std::optional<qint64> longIdentifier);

    [[nodiscard]] UserIdentity build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_USERIDENTITYBUILDER
