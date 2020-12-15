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

#ifndef QEVERCLOUD_GENERATED_DATA_H
#define QEVERCLOUD_GENERATED_DATA_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QByteArray>
#include <optional>

namespace qevercloud {

/**
 * In several places, EDAM exchanges blocks of bytes of data for a component
 * which may be relatively large.  For example:  the contents of a clipped
 * HTML note, the bytes of an embedded image, or the recognition XML for
 * a large image.  This structure is used in the protocol to represent
 * any of those large blocks of data when they are transmitted or when
 * they are only referenced their metadata.
 *
 **/
class QEVERCLOUD_EXPORT Data: public Printable
{
    Q_GADGET
public:
    Data();
    Data(const Data & other);
    Data(Data && other) noexcept;
    ~Data() noexcept override;

    Data & operator=(const Data & other);
    Data & operator=(Data && other) noexcept;

    /**
    This field carries a one-way hash of the contents of the
       data body, in binary form.  The hash function is MD5<br/>
       Length:  EDAM_HASH_LEN (exactly)
    */
    [[nodiscard]] const std::optional<QByteArray> & bodyHash() const noexcept;
    void setBodyHash(std::optional<QByteArray> bodyHash);

    /**
    The length, in bytes, of the data body.
    */
    [[nodiscard]] const std::optional<qint32> & size() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableSize();
    void setSize(std::optional<qint32> size);

    /**
    This field is set to contain the binary contents of the data
       whenever the resource is being transferred.  If only metadata is
       being exchanged, this field will be empty.  For example, a client could
       notify the service about the change to an attribute for a resource
       without transmitting the binary resource contents.
    */
    [[nodiscard]] const std::optional<QByteArray> & body() const noexcept;
    void setBody(std::optional<QByteArray> body);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const Data & other) const noexcept;
    [[nodiscard]] bool operator!=(const Data & other) const noexcept;

    Q_PROPERTY(std::optional<QByteArray> bodyHash READ bodyHash WRITE setBodyHash)
    Q_PROPERTY(std::optional<qint32> size READ size WRITE setSize)
    Q_PROPERTY(std::optional<QByteArray> body READ body WRITE setBody)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::Data)

#endif // QEVERCLOUD_GENERATED_DATA_H