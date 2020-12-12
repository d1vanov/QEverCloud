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

#ifndef QEVERCLOUD_GENERATED_NOTELIMITS_H
#define QEVERCLOUD_GENERATED_NOTELIMITS_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "TypeAliases.h"
#include <optional>

namespace qevercloud {

/**
 * Represents the owner's account related limits on a Note.
 * The field uploaded represents the total number of bytes that have been uploaded
 * to this account and is taken from the SyncState struct. All other fields
 * represent account related limits and are taken from the AccountLimits struct.
 * <p />
 * See SyncState and AccountLimits struct field definitions for more details.
 */
class QEVERCLOUD_EXPORT NoteLimits: public Printable
{
    Q_GADGET
public:
    NoteLimits();
    NoteLimits(const NoteLimits & other);
    NoteLimits(NoteLimits && other) noexcept;
    ~NoteLimits() noexcept override;

    NoteLimits & operator=(const NoteLimits & other);
    NoteLimits & operator=(NoteLimits && other) noexcept;

    [[nodiscard]] const std::optional<qint32> & noteResourceCountMax() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableNoteResourceCountMax();
    void setNoteResourceCountMax(std::optional<qint32> noteResourceCountMax);

    [[nodiscard]] const std::optional<qint64> & uploadLimit() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableUploadLimit();
    void setUploadLimit(std::optional<qint64> uploadLimit);

    [[nodiscard]] const std::optional<qint64> & resourceSizeMax() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableResourceSizeMax();
    void setResourceSizeMax(std::optional<qint64> resourceSizeMax);

    [[nodiscard]] const std::optional<qint64> & noteSizeMax() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableNoteSizeMax();
    void setNoteSizeMax(std::optional<qint64> noteSizeMax);

    [[nodiscard]] const std::optional<qint64> & uploaded() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableUploaded();
    void setUploaded(std::optional<qint64> uploaded);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NoteLimits & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteLimits & other) const noexcept;

    Q_PROPERTY(std::optional<qint32> noteResourceCountMax READ noteResourceCountMax WRITE setNoteResourceCountMax)
    Q_PROPERTY(std::optional<qint64> uploadLimit READ uploadLimit WRITE setUploadLimit)
    Q_PROPERTY(std::optional<qint64> resourceSizeMax READ resourceSizeMax WRITE setResourceSizeMax)
    Q_PROPERTY(std::optional<qint64> noteSizeMax READ noteSizeMax WRITE setNoteSizeMax)
    Q_PROPERTY(std::optional<qint64> uploaded READ uploaded WRITE setUploaded)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteLimits)

#endif // QEVERCLOUD_GENERATED_NOTELIMITS_H
