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

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPE
#define QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPE

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * A structure defining the scope of a SavedSearch.
 *
 * */
class QEVERCLOUD_EXPORT SavedSearchScope: public Printable
{
    Q_GADGET
public:
    SavedSearchScope();
    SavedSearchScope(const SavedSearchScope & other);
    SavedSearchScope(SavedSearchScope && other) noexcept;
    ~SavedSearchScope() noexcept override;

    SavedSearchScope & operator=(const SavedSearchScope & other);
    SavedSearchScope & operator=(SavedSearchScope && other) noexcept;

    /**
     * The search should include notes from the account that contains the SavedSearch.
     */
    [[nodiscard]] const std::optional<bool> & includeAccount() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeAccount();
    void setIncludeAccount(std::optional<bool> includeAccount);

    /**
     * The search should include notes within those shared notebooks
     * that the user has joined that are NOT business notebooks.
     */
    [[nodiscard]] const std::optional<bool> & includePersonalLinkedNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludePersonalLinkedNotebooks();
    void setIncludePersonalLinkedNotebooks(std::optional<bool> includePersonalLinkedNotebooks);

    /**
     * The search should include notes within those shared notebooks
     * that the user has joined that are business notebooks in the business that
     * the user is currently a member of.
     */
    [[nodiscard]] const std::optional<bool> & includeBusinessLinkedNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeBusinessLinkedNotebooks();
    void setIncludeBusinessLinkedNotebooks(std::optional<bool> includeBusinessLinkedNotebooks);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const SavedSearchScope & savedSearchScope);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const SavedSearchScope & savedSearchScope);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const SavedSearchScope & savedSearchScope);

    Q_PROPERTY(std::optional<bool> includeAccount READ includeAccount WRITE setIncludeAccount)
    Q_PROPERTY(std::optional<bool> includePersonalLinkedNotebooks READ includePersonalLinkedNotebooks WRITE setIncludePersonalLinkedNotebooks)
    Q_PROPERTY(std::optional<bool> includeBusinessLinkedNotebooks READ includeBusinessLinkedNotebooks WRITE setIncludeBusinessLinkedNotebooks)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const SavedSearchScope & lhs, const SavedSearchScope & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const SavedSearchScope & lhs, const SavedSearchScope & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPE
