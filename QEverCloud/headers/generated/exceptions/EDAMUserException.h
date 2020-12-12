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

#ifndef QEVERCLOUD_GENERATED_EDAMUSEREXCEPTION_H
#define QEVERCLOUD_GENERATED_EDAMUSEREXCEPTION_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "../types/TypeAliases.h"
#include <optional>

namespace qevercloud {

/**
 * This exception is thrown by EDAM procedures when a call fails as a result of 
 * a problem that a caller may be able to resolve.  For example, if the user
 * attempts to add a note to their account which would exceed their storage
 * quota, this type of exception may be thrown to indicate the source of the
 * error so that they can choose an alternate action.
 *
 * This exception would not be used for internal system errors that do not
 * reflect user actions, but rather reflect a problem within the service that
 * the user cannot resolve.
 *
 * errorCode:  The numeric code indicating the type of error that occurred.
 *   must be one of the values of EDAMErrorCode.
 *
 * parameter:  If the error applied to a particular input parameter, this will
 *   indicate which parameter. For some errors (USER_NOT_ASSOCIATED, USER_NOT_REGISTERED,
 *   SSO_AUTHENTICATION_REQUIRED), this is the user's email.
 */
class QEVERCLOUD_EXPORT EDAMUserException: public EvernoteException, public Printable
{
    Q_GADGET
public:
    EDAMUserException();
    EDAMUserException(const EDAMUserException & other);
    EDAMUserException(EDAMUserException && other) noexcept;
    ~EDAMUserException() noexcept override;

    EDAMUserException & operator=(const EDAMUserException & other);
    EDAMUserException & operator=(EDAMUserException && other) noexcept;

    [[nodiscard]] EDAMErrorCode errorCode() const noexcept;
    void setErrorCode(EDAMErrorCode errorCode);

    [[nodiscard]] const std::optional<QString> & parameter() const noexcept;
    void setParameter(std::optional<QString> parameter);

    void print(QTextStream & strm) const override;
    [[nodiscard]] const char * what() const noexcept override;
    [[nodiscard]] EverCloudExceptionDataPtr exceptionData() const override;

    [[nodiscard]] bool operator==(const EDAMUserException & other) const noexcept;
    [[nodiscard]] bool operator!=(const EDAMUserException & other) const noexcept;

    Q_PROPERTY(EDAMErrorCode errorCode READ errorCode WRITE setErrorCode)
    Q_PROPERTY(std::optional<QString> parameter READ parameter WRITE setParameter)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

/**
 * Asynchronous API counterpart of EDAMUserException. See EverCloudExceptionData
 * for more details.
 */
class QEVERCLOUD_EXPORT EDAMUserExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMUserExceptionData)
public:
    explicit EDAMUserExceptionData(
        QString error,
        EDAMErrorCode errorCode,
        std::optional<QString> parameter);

    ~EDAMUserExceptionData() noexcept override;

    [[nodiscard]] EDAMErrorCode errorCode() const noexcept;
    void setErrorCode(EDAMErrorCode errorCode);

    [[nodiscard]] const std::optional<QString> & parameter() const noexcept;
    void setParameter(std::optional<QString> parameter);

    virtual void throwException() const override;

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::EDAMUserException)

#endif // QEVERCLOUD_GENERATED_EDAMUSEREXCEPTION_H
