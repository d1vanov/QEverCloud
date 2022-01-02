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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORBUILDER
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EDAMNotFoundException.h>
#include <qevercloud/exceptions/EDAMUserException.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/ManageNoteSharesError.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ManageNoteSharesErrorBuilder
{
public:
    ManageNoteSharesErrorBuilder();

    ManageNoteSharesErrorBuilder(ManageNoteSharesErrorBuilder && other) noexcept;

    ~ManageNoteSharesErrorBuilder() noexcept;

    ManageNoteSharesErrorBuilder & operator=(ManageNoteSharesErrorBuilder && other) noexcept;

    ManageNoteSharesErrorBuilder & setIdentityID(std::optional<IdentityID> identityID);
    ManageNoteSharesErrorBuilder & setUserID(std::optional<UserID> userID);
    ManageNoteSharesErrorBuilder & setUserException(std::optional<EDAMUserException> userException);
    ManageNoteSharesErrorBuilder & setNotFoundException(std::optional<EDAMNotFoundException> notFoundException);

    [[nodiscard]] ManageNoteSharesError build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESERRORBUILDER
