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

#ifndef QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPE_H
#define QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPE_H

#include "../../Export.h"

#include <qevercloud/EverCloudException.h>
#include <qevercloud/Printable.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
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
    The search should include notes from the account that contains the SavedSearch.
    */
    [[nodiscard]] const std::optional<bool> & includeAccount() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeAccount();
    void setIncludeAccount(std::optional<bool> includeAccount);

    /**
    The search should include notes within those shared notebooks
       that the user has joined that are NOT business notebooks.
    */
    [[nodiscard]] const std::optional<bool> & includePersonalLinkedNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludePersonalLinkedNotebooks();
    void setIncludePersonalLinkedNotebooks(std::optional<bool> includePersonalLinkedNotebooks);

    /**
    The search should include notes within those shared notebooks
       that the user has joined that are business notebooks in the business that
       the user is currently a member of.
    */
    [[nodiscard]] const std::optional<bool> & includeBusinessLinkedNotebooks() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeBusinessLinkedNotebooks();
    void setIncludeBusinessLinkedNotebooks(std::optional<bool> includeBusinessLinkedNotebooks);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const SavedSearchScope & other) const noexcept;
    [[nodiscard]] bool operator!=(const SavedSearchScope & other) const noexcept;

    Q_PROPERTY(std::optional<bool> includeAccount READ includeAccount WRITE setIncludeAccount)
    Q_PROPERTY(std::optional<bool> includePersonalLinkedNotebooks READ includePersonalLinkedNotebooks WRITE setIncludePersonalLinkedNotebooks)
    Q_PROPERTY(std::optional<bool> includeBusinessLinkedNotebooks READ includeBusinessLinkedNotebooks WRITE setIncludeBusinessLinkedNotebooks)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::SavedSearchScope)

#endif // QEVERCLOUD_GENERATED_SAVEDSEARCHSCOPE_H
