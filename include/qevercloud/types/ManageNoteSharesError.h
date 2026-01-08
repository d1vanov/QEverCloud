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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESERROR
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESERROR

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EDAMNotFoundException.h>
#include <qevercloud/exceptions/EDAMUserException.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Captures errors that occur during a call to manageNoteShares. That
 * function can be run best-effort, meaning that some change requests can
 * be applied while others fail. Note that some errors such as system
 * exceptions may still cause the entire call to fail.
 *
 * Only one of the two ID fields will be set on a given error.
 *
 * Only one of the two exception fields will be set on a given error.
 *
 * */
class QEVERCLOUD_EXPORT ManageNoteSharesError: public Printable
{
    Q_GADGET
public:
    ManageNoteSharesError();
    ManageNoteSharesError(const ManageNoteSharesError & other);
    ManageNoteSharesError(ManageNoteSharesError && other) noexcept;
    ~ManageNoteSharesError() noexcept override;

    ManageNoteSharesError & operator=(const ManageNoteSharesError & other);
    ManageNoteSharesError & operator=(ManageNoteSharesError && other) noexcept;

    /**
     * The identity ID of an outstanding invitation that was not updated
     * due to the error.
     */
    [[nodiscard]] const std::optional<IdentityID> & identityID() const noexcept;
    [[nodiscard]] std::optional<IdentityID> & mutableIdentityID();
    void setIdentityID(std::optional<IdentityID> identityID);

    /**
     * The user ID of an existing membership that was not updated due
     * to the error.
     */
    [[nodiscard]] const std::optional<UserID> & userID() const noexcept;
    [[nodiscard]] std::optional<UserID> & mutableUserID();
    void setUserID(std::optional<UserID> userID);

    /**
     * If the error is represented as an EDAMUserException that would
     * have otherwise been thrown without best-effort execution.
     */
    [[nodiscard]] const std::optional<EDAMUserException> & userException() const noexcept;
    [[nodiscard]] std::optional<EDAMUserException> & mutableUserException();
    void setUserException(std::optional<EDAMUserException> userException);

    /**
     * If the error is represented as an EDAMNotFoundException that
     * would have otherwise been thrown without best-effort execution.
     * The identifier field of the exception will be either "Identity.id"
     * or "User.id", indicating that no existing share could be found for
     * the specified recipient.
     */
    [[nodiscard]] const std::optional<EDAMNotFoundException> & notFoundException() const noexcept;
    [[nodiscard]] std::optional<EDAMNotFoundException> & mutableNotFoundException();
    void setNotFoundException(std::optional<EDAMNotFoundException> notFoundException);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const ManageNoteSharesError & manageNoteSharesError);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const ManageNoteSharesError & manageNoteSharesError);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const ManageNoteSharesError & manageNoteSharesError);

    Q_PROPERTY(std::optional<IdentityID> identityID READ identityID WRITE setIdentityID)
    Q_PROPERTY(std::optional<UserID> userID READ userID WRITE setUserID)
    Q_PROPERTY(std::optional<EDAMUserException> userException READ userException WRITE setUserException)
    Q_PROPERTY(std::optional<EDAMNotFoundException> notFoundException READ notFoundException WRITE setNotFoundException)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const ManageNoteSharesError & lhs, const ManageNoteSharesError & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const ManageNoteSharesError & lhs, const ManageNoteSharesError & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESERROR
