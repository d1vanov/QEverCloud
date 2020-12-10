/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2020 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEDATA_H
#define QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEDATA_H

#include <generated/types/SavedSearchScope.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN SavedSearchScope::SavedSearchScopeData final:
    public QSharedData,
    public Printable
{
public:
    SavedSearchScopeData() = default;
    SavedSearchScopeData(const SavedSearchScopeData & other) = default;
    SavedSearchScopeData(SavedSearchScopeData && other) noexcept = default;

    SavedSearchScopeData & operator=(const SavedSearchScopeData & other) = delete;
    SavedSearchScopeData & operator=(SavedSearchScopeData && other) = delete;

    ~SavedSearchScopeData() noexcept override = default;

    [[nodiscard]] bool operator==(const SavedSearchScopeData & other) const noexcept;
    [[nodiscard]] bool operator!=(const SavedSearchScopeData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_includeAccount;
    std::optional<bool> m_includePersonalLinkedNotebooks;
    std::optional<bool> m_includeBusinessLinkedNotebooks;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPEDATA_H
