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

#include <qevercloud/types/builders/PublishingBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN PublishingBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_uri;
    std::optional<NoteSortOrder> m_order;
    std::optional<bool> m_ascending;
    std::optional<QString> m_publicDescription;
};

PublishingBuilder::PublishingBuilder() :
    d(new PublishingBuilder::Impl)
{}

PublishingBuilder::PublishingBuilder(PublishingBuilder && other) noexcept :
    d{std::move(other.d)}
{}

PublishingBuilder::~PublishingBuilder() noexcept = default;

PublishingBuilder & PublishingBuilder::operator=(PublishingBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

PublishingBuilder & PublishingBuilder::setUri(std::optional<QString> uri)
{
    d->m_uri = std::move(uri);
    return *this;
}

PublishingBuilder & PublishingBuilder::setOrder(std::optional<NoteSortOrder> order)
{
    d->m_order = std::move(order);
    return *this;
}

PublishingBuilder & PublishingBuilder::setAscending(std::optional<bool> ascending)
{
    d->m_ascending = std::move(ascending);
    return *this;
}

PublishingBuilder & PublishingBuilder::setPublicDescription(std::optional<QString> publicDescription)
{
    d->m_publicDescription = std::move(publicDescription);
    return *this;
}

Publishing PublishingBuilder::build()
{
    Publishing result;

    result.setUri(std::move(d->m_uri));
    result.setOrder(std::move(d->m_order));
    result.setAscending(std::move(d->m_ascending));
    result.setPublicDescription(std::move(d->m_publicDescription));

    d->m_uri = {};
    d->m_order = {};
    d->m_ascending = {};
    d->m_publicDescription = {};

    return result;
}

} // namespace qevercloud
