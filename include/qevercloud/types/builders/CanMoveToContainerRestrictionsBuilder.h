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

#ifndef QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSBUILDER
#define QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/CanMoveToContainerRestrictions.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT CanMoveToContainerRestrictionsBuilder
{
public:
    CanMoveToContainerRestrictionsBuilder();

    CanMoveToContainerRestrictionsBuilder(CanMoveToContainerRestrictionsBuilder && other) noexcept;

    ~CanMoveToContainerRestrictionsBuilder() noexcept;

    CanMoveToContainerRestrictionsBuilder & operator=(CanMoveToContainerRestrictionsBuilder && other) noexcept;

    CanMoveToContainerRestrictionsBuilder & setCanMoveToContainer(std::optional<CanMoveToContainerStatus> canMoveToContainer);

    [[nodiscard]] CanMoveToContainerRestrictions build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSBUILDER
