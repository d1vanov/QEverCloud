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

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEIMPL
#define QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEIMPL

#include <qevercloud/types/SavedSearchScope.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SavedSearchScope::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const SavedSearchScope::Impl & other) = default;
    Impl(SavedSearchScope::Impl && other) noexcept = default;

    SavedSearchScope::Impl & operator=(const SavedSearchScope::Impl & other) = delete;
    SavedSearchScope::Impl & operator=(SavedSearchScope::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_includeAccount;
    std::optional<bool> m_includePersonalLinkedNotebooks;
    std::optional<bool> m_includeBusinessLinkedNotebooks;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEIMPL
