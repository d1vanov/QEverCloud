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

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEBUILDER
#define QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/SavedSearchScope.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT SavedSearchScopeBuilder
{
public:
    SavedSearchScopeBuilder();

    SavedSearchScopeBuilder(SavedSearchScopeBuilder && other) noexcept;

    ~SavedSearchScopeBuilder() noexcept;

    SavedSearchScopeBuilder & operator=(SavedSearchScopeBuilder && other) noexcept;

    SavedSearchScopeBuilder & setIncludeAccount(std::optional<bool> includeAccount);
    SavedSearchScopeBuilder & setIncludePersonalLinkedNotebooks(std::optional<bool> includePersonalLinkedNotebooks);
    SavedSearchScopeBuilder & setIncludeBusinessLinkedNotebooks(std::optional<bool> includeBusinessLinkedNotebooks);

    [[nodiscard]] SavedSearchScope build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEBUILDER
