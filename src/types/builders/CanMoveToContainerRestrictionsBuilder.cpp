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

#include <qevercloud/types/builders/CanMoveToContainerRestrictionsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN CanMoveToContainerRestrictionsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<CanMoveToContainerStatus> m_canMoveToContainer;
};

CanMoveToContainerRestrictionsBuilder::CanMoveToContainerRestrictionsBuilder() :
    d(new CanMoveToContainerRestrictionsBuilder::Impl)
{}

CanMoveToContainerRestrictionsBuilder::CanMoveToContainerRestrictionsBuilder(CanMoveToContainerRestrictionsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

CanMoveToContainerRestrictionsBuilder::~CanMoveToContainerRestrictionsBuilder() noexcept = default;

CanMoveToContainerRestrictionsBuilder & CanMoveToContainerRestrictionsBuilder::operator=(CanMoveToContainerRestrictionsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

CanMoveToContainerRestrictionsBuilder & CanMoveToContainerRestrictionsBuilder::setCanMoveToContainer(std::optional<CanMoveToContainerStatus> canMoveToContainer)
{
    d->m_canMoveToContainer = std::move(canMoveToContainer);
    return *this;
}

CanMoveToContainerRestrictions CanMoveToContainerRestrictionsBuilder::build()
{
    CanMoveToContainerRestrictions result;

    result.setCanMoveToContainer(std::move(d->m_canMoveToContainer));

    d->m_canMoveToContainer = {};

    return result;
}

} // namespace qevercloud
