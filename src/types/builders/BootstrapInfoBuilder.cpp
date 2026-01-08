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

#include <qevercloud/types/builders/BootstrapInfoBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BootstrapInfoBuilder::Impl final:
    public QSharedData
{
public:
    QList<BootstrapProfile> m_profiles;
};

BootstrapInfoBuilder::BootstrapInfoBuilder() :
    d(new BootstrapInfoBuilder::Impl)
{}

BootstrapInfoBuilder::BootstrapInfoBuilder(BootstrapInfoBuilder && other) noexcept :
    d{std::move(other.d)}
{}

BootstrapInfoBuilder::~BootstrapInfoBuilder() noexcept = default;

BootstrapInfoBuilder & BootstrapInfoBuilder::operator=(BootstrapInfoBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

BootstrapInfoBuilder & BootstrapInfoBuilder::setProfiles(QList<BootstrapProfile> profiles)
{
    d->m_profiles = std::move(profiles);
    return *this;
}

BootstrapInfo BootstrapInfoBuilder::build()
{
    BootstrapInfo result;

    result.setProfiles(std::move(d->m_profiles));

    d->m_profiles = {};

    return result;
}

} // namespace qevercloud
