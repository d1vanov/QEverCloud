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

#ifndef QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTION_H
#define QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTION_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "../types/TypeAliases.h"
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
    [[nodiscard]] const char * what() const noexcept override;
    [[nodiscard]] EverCloudExceptionDataPtr exceptionData() const override;

    [[nodiscard]] bool operator==(const EDAMNotFoundException & other) const noexcept;
    [[nodiscard]] bool operator!=(const EDAMNotFoundException & other) const noexcept;

    Q_PROPERTY(std::optional<QString> identifier READ identifier WRITE setIdentifier)
    Q_PROPERTY(std::optional<QString> key READ key WRITE setKey)

private:
    class EDAMNotFoundExceptionData;
    QSharedDataPointer<EDAMNotFoundExceptionData> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::EDAMNotFoundException)

#endif // QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTION_H
