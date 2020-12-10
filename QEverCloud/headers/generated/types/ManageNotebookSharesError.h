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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERROR_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERROR_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "../exceptions/EDAMNotFoundException.h"
#include "../exceptions/EDAMUserException.h"
#include "TypeAliases.h"
#include "UserIdentity.h"
#include <optional>

namespace qevercloud {

/**
 * A structure to capture certain errors that occurred during a call
 * to manageNotebookShares.  That method can be run best-effort,
 * meaning that some change requests can be applied while others fail.
 * Note that some errors such as system errors will still fail the
 * entire transaction regardless of running best effort.  When some
 * change requests do not succeed, the error conditions are captured
 * in instances of this class, captured by the identity of the share
 * relationship and one of the exception fields.
 *
 * */
class QEVERCLOUD_EXPORT ManageNotebookSharesError: public Printable
{
    Q_GADGET
public:
    ManageNotebookSharesError();
    ManageNotebookSharesError(const ManageNotebookSharesError & other);
    ManageNotebookSharesError(ManageNotebookSharesError && other) noexcept;
    ~ManageNotebookSharesError() noexcept override;

    ManageNotebookSharesError & operator=(const ManageNotebookSharesError & other);
    ManageNotebookSharesError & operator=(ManageNotebookSharesError && other) noexcept;

    /**
    The identity of the share relationship whose update encountered
     an error.
    */
    [[nodiscard]] const std::optional<UserIdentity> & userIdentity() const noexcept;
    [[nodiscard]] std::optional<UserIdentity> & mutableUserIdentity();
    void setUserIdentity(std::optional<UserIdentity> userIdentity);

    /**
    If the error is represented as an EDAMUserException that would
     have otherwise been thrown without best-effort execution.  Only one
     exception field will be set.
    */
    [[nodiscard]] const std::optional<EDAMUserException> & userException() const noexcept;
    [[nodiscard]] std::optional<EDAMUserException> & mutableUserException();
    void setUserException(std::optional<EDAMUserException> userException);

    /**
    If the error is represented as an EDAMNotFoundException that would
     have otherwise been thrown without best-effort execution.  Only one
     exception field will be set.
    */
    [[nodiscard]] const std::optional<EDAMNotFoundException> & notFoundException() const noexcept;
    [[nodiscard]] std::optional<EDAMNotFoundException> & mutableNotFoundException();
    void setNotFoundException(std::optional<EDAMNotFoundException> notFoundException);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const ManageNotebookSharesError & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNotebookSharesError & other) const noexcept;

    Q_PROPERTY(std::optional<UserIdentity> userIdentity READ userIdentity WRITE setUserIdentity)
    Q_PROPERTY(std::optional<EDAMUserException> userException READ userException WRITE setUserException)
    Q_PROPERTY(std::optional<EDAMNotFoundException> notFoundException READ notFoundException WRITE setNotFoundException)

private:
    class ManageNotebookSharesErrorData;
    QSharedDataPointer<ManageNotebookSharesErrorData> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ManageNotebookSharesError)

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESERROR_H
