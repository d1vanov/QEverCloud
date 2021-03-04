/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTION_H
#define QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTION_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/Contact.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * An exception thrown when the provided Contacts fail validation. For instance,
 * email domains could be invalid, phone numbers might not be valid for SMS,
 * etc.
 *
 * We will not provide individual reasons for each Contact's validation failure.
 * The presence of the Contact in this exception means that the user must figure
 * out how to take appropriate action to fix this Contact.
 *
 * <dl>
 *   <dt>contacts</dt>
 *   <dd>The list of Contacts that are considered invalid by the service</dd>
 *
 *   <dt>parameter</dt>
 *   <dd>If the error applied to a particular input parameter, this will
 *   indicate which parameter.</dd>
 *
 *   <dt>reasons</dt>
 *   <dd>If supplied, the list of reasons why the server considered a contact invalid,
 *   matching, in order, the list returned in the contacts field.</dd>
 * </dl>
 */
class QEVERCLOUD_EXPORT EDAMInvalidContactsException: public EvernoteException, public Printable
{
    Q_GADGET
public:
    EDAMInvalidContactsException();
    EDAMInvalidContactsException(const EDAMInvalidContactsException & other);
    EDAMInvalidContactsException(EDAMInvalidContactsException && other) noexcept;
    ~EDAMInvalidContactsException() noexcept override;

    EDAMInvalidContactsException & operator=(const EDAMInvalidContactsException & other);
    EDAMInvalidContactsException & operator=(EDAMInvalidContactsException && other) noexcept;

    [[nodiscard]] const QList<Contact> & contacts() const noexcept;
    [[nodiscard]] QList<Contact> & mutableContacts();
    void setContacts(QList<Contact> contacts);

    [[nodiscard]] const std::optional<QString> & parameter() const noexcept;
    void setParameter(std::optional<QString> parameter);

    [[nodiscard]] const std::optional<QList<EDAMInvalidContactReason>> & reasons() const noexcept;
    [[nodiscard]] std::optional<QList<EDAMInvalidContactReason>> & mutableReasons();
    void setReasons(std::optional<QList<EDAMInvalidContactReason>> reasons);

    void print(QTextStream & strm) const override;

    [[nodiscard]] const char * what() const noexcept override;
    [[nodiscard]] EverCloudExceptionDataPtr exceptionData() const override;

    Q_PROPERTY(QList<Contact> contacts READ contacts WRITE setContacts)
    Q_PROPERTY(std::optional<QString> parameter READ parameter WRITE setParameter)
    Q_PROPERTY(std::optional<QList<EDAMInvalidContactReason>> reasons READ reasons WRITE setReasons)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const EDAMInvalidContactsException & lhs, const EDAMInvalidContactsException & rhs) noexcept;
[[nodiscard]] bool operator!=(const EDAMInvalidContactsException & lhs, const EDAMInvalidContactsException & rhs) noexcept;

/**
 * Asynchronous API counterpart of EDAMInvalidContactsException. See EverCloudExceptionData
 * for more details.
 */
class QEVERCLOUD_EXPORT EDAMInvalidContactsExceptionData: public EvernoteExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EDAMInvalidContactsExceptionData)
public:
    explicit EDAMInvalidContactsExceptionData(
        QString error,
        QList<Contact> contacts,
        std::optional<QString> parameter,
        std::optional<QList<EDAMInvalidContactReason>> reasons);

    ~EDAMInvalidContactsExceptionData() noexcept override;

    [[nodiscard]] const QList<Contact> & contacts() const noexcept;
    [[nodiscard]] QList<Contact> & mutableContacts();
    void setContacts(QList<Contact> contacts);

    [[nodiscard]] const std::optional<QString> & parameter() const noexcept;
    void setParameter(std::optional<QString> parameter);

    [[nodiscard]] const std::optional<QList<EDAMInvalidContactReason>> & reasons() const noexcept;
    [[nodiscard]] std::optional<QList<EDAMInvalidContactReason>> & mutableReasons();
    void setReasons(std::optional<QList<EDAMInvalidContactReason>> reasons);

    virtual void throwException() const override;

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::EDAMInvalidContactsException)

#endif // QEVERCLOUD_GENERATED_EDAMINVALIDCONTACTSEXCEPTION_H
