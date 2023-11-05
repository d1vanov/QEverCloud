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

#ifndef QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTION
#define QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTION

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EvernoteException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This exception is thrown by EDAM procedures when a caller asks to perform
 * an operation on an object that does not exist.  This may be thrown based on an invalid
 * primary identifier (e.g. a bad GUID), or when the caller refers to an object
 * by another unique identifier (e.g. a User's email address).
 *
 * identifier:  A description of the object that was not found on the server.
 *   For example, "Note.notebookGuid" when a caller attempts to create a note in a
 *   notebook that does not exist in the user's account.
 *
 * key:  The value passed from the client in the identifier, which was not
 *   found. For example, the GUID that was not found.
 */
class QEVERCLOUD_EXPORT EDAMNotFoundException: public EvernoteException, public Printable
{
    Q_GADGET
public:
    EDAMNotFoundException();
    EDAMNotFoundException(
        std::optional<QString> identifier,
        std::optional<QString> key);

    EDAMNotFoundException(const EDAMNotFoundException & other);
    EDAMNotFoundException(EDAMNotFoundException && other) noexcept;
    ~EDAMNotFoundException() noexcept override;

    EDAMNotFoundException & operator=(const EDAMNotFoundException & other);
    EDAMNotFoundException & operator=(EDAMNotFoundException && other) noexcept;

    [[nodiscard]] const std::optional<QString> & identifier() const noexcept;
    void setIdentifier(std::optional<QString> identifier);

    [[nodiscard]] const std::optional<QString> & key() const noexcept;
    void setKey(std::optional<QString> key);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const EDAMNotFoundException & eDAMNotFoundException);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const EDAMNotFoundException & eDAMNotFoundException);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const EDAMNotFoundException & eDAMNotFoundException);

    [[nodiscard]] const char * what() const noexcept override;
    void raise() const override;
    [[nodiscard]] EDAMNotFoundException * clone() const override;

    Q_PROPERTY(std::optional<QString> identifier READ identifier WRITE setIdentifier)
    Q_PROPERTY(std::optional<QString> key READ key WRITE setKey)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const EDAMNotFoundException & lhs, const EDAMNotFoundException & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const EDAMNotFoundException & lhs, const EDAMNotFoundException & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTION
