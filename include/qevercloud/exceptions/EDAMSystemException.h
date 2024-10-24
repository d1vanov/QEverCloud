/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTION
#define QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTION

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EvernoteException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This exception is thrown by EDAM procedures when a call fails as a result of
 * a problem in the service that could not be changed through caller action.
 *
 * errorCode:  The numeric code indicating the type of error that occurred.
 *   must be one of the values of EDAMErrorCode.
 *
 * message:  This may contain additional information about the error
 *
 * rateLimitDuration:  Indicates the minimum number of seconds that an application should
 *   expect subsequent API calls for this user to fail. The application should not retry
 *   API requests for the user until at least this many seconds have passed. Present only
 *   when errorCode is RATE_LIMIT_REACHED,
 */
class QEVERCLOUD_EXPORT EDAMSystemException: public EvernoteException, public Printable
{
    Q_GADGET
public:
    EDAMSystemException();
    EDAMSystemException(
        EDAMErrorCode errorCode,
        std::optional<QString> message,
        std::optional<qint32> rateLimitDuration);

    EDAMSystemException(const EDAMSystemException & other);
    EDAMSystemException(EDAMSystemException && other) noexcept;
    ~EDAMSystemException() noexcept override;

    EDAMSystemException & operator=(const EDAMSystemException & other);
    EDAMSystemException & operator=(EDAMSystemException && other) noexcept;

    [[nodiscard]] EDAMErrorCode errorCode() const noexcept;
    void setErrorCode(EDAMErrorCode errorCode);

    [[nodiscard]] const std::optional<QString> & message() const noexcept;
    void setMessage(std::optional<QString> message);

    [[nodiscard]] const std::optional<qint32> & rateLimitDuration() const noexcept;
    void setRateLimitDuration(std::optional<qint32> rateLimitDuration);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const EDAMSystemException & eDAMSystemException);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const EDAMSystemException & eDAMSystemException);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const EDAMSystemException & eDAMSystemException);

    [[nodiscard]] const char * what() const noexcept override;
    void raise() const override;
    [[nodiscard]] EDAMSystemException * clone() const override;

    Q_PROPERTY(EDAMErrorCode errorCode READ errorCode WRITE setErrorCode)
    Q_PROPERTY(std::optional<QString> message READ message WRITE setMessage)
    Q_PROPERTY(std::optional<qint32> rateLimitDuration READ rateLimitDuration WRITE setRateLimitDuration)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const EDAMSystemException & lhs, const EDAMSystemException & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const EDAMSystemException & lhs, const EDAMSystemException & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMSYSTEMEXCEPTION