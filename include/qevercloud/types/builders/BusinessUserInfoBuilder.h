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

#ifndef QEVERCLOUD_GENERATED_BUSINESSUSERINFOBUILDER
#define QEVERCLOUD_GENERATED_BUSINESSUSERINFOBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BusinessUserInfo.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT BusinessUserInfoBuilder
{
public:
    BusinessUserInfoBuilder();

    BusinessUserInfoBuilder(BusinessUserInfoBuilder && other) noexcept;

    ~BusinessUserInfoBuilder() noexcept;

    BusinessUserInfoBuilder & operator=(BusinessUserInfoBuilder && other) noexcept;

    BusinessUserInfoBuilder & setBusinessId(std::optional<qint32> businessId);
    BusinessUserInfoBuilder & setBusinessName(std::optional<QString> businessName);
    BusinessUserInfoBuilder & setRole(std::optional<BusinessUserRole> role);
    BusinessUserInfoBuilder & setEmail(std::optional<QString> email);
    BusinessUserInfoBuilder & setUpdated(std::optional<Timestamp> updated);

    [[nodiscard]] BusinessUserInfo build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSUSERINFOBUILDER
