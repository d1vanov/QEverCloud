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

#include <qevercloud/types/builders/ShareRelationshipRestrictionsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ShareRelationshipRestrictionsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_noSetReadOnly;
    std::optional<bool> m_noSetReadPlusActivity;
    std::optional<bool> m_noSetModify;
    std::optional<bool> m_noSetFullAccess;
};

ShareRelationshipRestrictionsBuilder::ShareRelationshipRestrictionsBuilder() :
    d(new ShareRelationshipRestrictionsBuilder::Impl)
{}

ShareRelationshipRestrictionsBuilder::ShareRelationshipRestrictionsBuilder(ShareRelationshipRestrictionsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ShareRelationshipRestrictionsBuilder::~ShareRelationshipRestrictionsBuilder() noexcept = default;

ShareRelationshipRestrictionsBuilder & ShareRelationshipRestrictionsBuilder::operator=(ShareRelationshipRestrictionsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ShareRelationshipRestrictionsBuilder & ShareRelationshipRestrictionsBuilder::setNoSetReadOnly(std::optional<bool> noSetReadOnly)
{
    d->m_noSetReadOnly = std::move(noSetReadOnly);
    return *this;
}

ShareRelationshipRestrictionsBuilder & ShareRelationshipRestrictionsBuilder::setNoSetReadPlusActivity(std::optional<bool> noSetReadPlusActivity)
{
    d->m_noSetReadPlusActivity = std::move(noSetReadPlusActivity);
    return *this;
}

ShareRelationshipRestrictionsBuilder & ShareRelationshipRestrictionsBuilder::setNoSetModify(std::optional<bool> noSetModify)
{
    d->m_noSetModify = std::move(noSetModify);
    return *this;
}

ShareRelationshipRestrictionsBuilder & ShareRelationshipRestrictionsBuilder::setNoSetFullAccess(std::optional<bool> noSetFullAccess)
{
    d->m_noSetFullAccess = std::move(noSetFullAccess);
    return *this;
}

ShareRelationshipRestrictions ShareRelationshipRestrictionsBuilder::build()
{
    ShareRelationshipRestrictions result;

    result.setNoSetReadOnly(std::move(d->m_noSetReadOnly));
    result.setNoSetReadPlusActivity(std::move(d->m_noSetReadPlusActivity));
    result.setNoSetModify(std::move(d->m_noSetModify));
    result.setNoSetFullAccess(std::move(d->m_noSetFullAccess));

    d->m_noSetReadOnly = {};
    d->m_noSetReadPlusActivity = {};
    d->m_noSetModify = {};
    d->m_noSetFullAccess = {};

    return result;
}

} // namespace qevercloud
