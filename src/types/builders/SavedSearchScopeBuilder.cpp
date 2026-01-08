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

#include <qevercloud/types/builders/SavedSearchScopeBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SavedSearchScopeBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_includeAccount;
    std::optional<bool> m_includePersonalLinkedNotebooks;
    std::optional<bool> m_includeBusinessLinkedNotebooks;
};

SavedSearchScopeBuilder::SavedSearchScopeBuilder() :
    d(new SavedSearchScopeBuilder::Impl)
{}

SavedSearchScopeBuilder::SavedSearchScopeBuilder(SavedSearchScopeBuilder && other) noexcept :
    d{std::move(other.d)}
{}

SavedSearchScopeBuilder::~SavedSearchScopeBuilder() noexcept = default;

SavedSearchScopeBuilder & SavedSearchScopeBuilder::operator=(SavedSearchScopeBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

SavedSearchScopeBuilder & SavedSearchScopeBuilder::setIncludeAccount(std::optional<bool> includeAccount)
{
    d->m_includeAccount = std::move(includeAccount);
    return *this;
}

SavedSearchScopeBuilder & SavedSearchScopeBuilder::setIncludePersonalLinkedNotebooks(std::optional<bool> includePersonalLinkedNotebooks)
{
    d->m_includePersonalLinkedNotebooks = std::move(includePersonalLinkedNotebooks);
    return *this;
}

SavedSearchScopeBuilder & SavedSearchScopeBuilder::setIncludeBusinessLinkedNotebooks(std::optional<bool> includeBusinessLinkedNotebooks)
{
    d->m_includeBusinessLinkedNotebooks = std::move(includeBusinessLinkedNotebooks);
    return *this;
}

SavedSearchScope SavedSearchScopeBuilder::build()
{
    SavedSearchScope result;

    result.setIncludeAccount(std::move(d->m_includeAccount));
    result.setIncludePersonalLinkedNotebooks(std::move(d->m_includePersonalLinkedNotebooks));
    result.setIncludeBusinessLinkedNotebooks(std::move(d->m_includeBusinessLinkedNotebooks));

    d->m_includeAccount = {};
    d->m_includePersonalLinkedNotebooks = {};
    d->m_includeBusinessLinkedNotebooks = {};

    return result;
}

} // namespace qevercloud
