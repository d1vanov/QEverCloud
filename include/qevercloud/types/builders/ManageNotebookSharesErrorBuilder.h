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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORBUILDER
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EDAMNotFoundException.h>
#include <qevercloud/exceptions/EDAMUserException.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/ManageNotebookSharesError.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/UserIdentity.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ManageNotebookSharesErrorBuilder
{
public:
    ManageNotebookSharesErrorBuilder();

    ManageNotebookSharesErrorBuilder(ManageNotebookSharesErrorBuilder && other) noexcept;

    ~ManageNotebookSharesErrorBuilder() noexcept;

    ManageNotebookSharesErrorBuilder & operator=(ManageNotebookSharesErrorBuilder && other) noexcept;

    ManageNotebookSharesErrorBuilder & setUserIdentity(std::optional<UserIdentity> userIdentity);
    ManageNotebookSharesErrorBuilder & setUserException(std::optional<EDAMUserException> userException);
    ManageNotebookSharesErrorBuilder & setNotFoundException(std::optional<EDAMNotFoundException> notFoundException);

    [[nodiscard]] ManageNotebookSharesError build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERRORBUILDER
