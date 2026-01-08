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

#include <qevercloud/types/builders/BootstrapProfileBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BootstrapProfileBuilder::Impl final:
    public QSharedData
{
public:
    QString m_name;
    BootstrapSettings m_settings;
};

BootstrapProfileBuilder::BootstrapProfileBuilder() :
    d(new BootstrapProfileBuilder::Impl)
{}

BootstrapProfileBuilder::BootstrapProfileBuilder(BootstrapProfileBuilder && other) noexcept :
    d{std::move(other.d)}
{}

BootstrapProfileBuilder::~BootstrapProfileBuilder() noexcept = default;

BootstrapProfileBuilder & BootstrapProfileBuilder::operator=(BootstrapProfileBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

BootstrapProfileBuilder & BootstrapProfileBuilder::setName(QString name)
{
    d->m_name = std::move(name);
    return *this;
}

BootstrapProfileBuilder & BootstrapProfileBuilder::setSettings(BootstrapSettings settings)
{
    d->m_settings = std::move(settings);
    return *this;
}

BootstrapProfile BootstrapProfileBuilder::build()
{
    BootstrapProfile result;

    result.setName(std::move(d->m_name));
    result.setSettings(std::move(d->m_settings));

    d->m_name = QString{};
    d->m_settings = {};

    return result;
}

} // namespace qevercloud
