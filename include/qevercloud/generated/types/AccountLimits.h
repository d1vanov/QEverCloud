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

#ifndef QEVERCLOUD_GENERATED_ACCOUNTLIMITS_H
#define QEVERCLOUD_GENERATED_ACCOUNTLIMITS_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * This structure is used to provide account limits that are in effect for this user.
 **/
class QEVERCLOUD_EXPORT AccountLimits: public Printable
{
    Q_GADGET
public:
    AccountLimits();
    AccountLimits(const AccountLimits & other);
    AccountLimits(AccountLimits && other) noexcept;
    ~AccountLimits() noexcept override;

    AccountLimits & operator=(const AccountLimits & other);
    AccountLimits & operator=(AccountLimits && other) noexcept;

    /**
     * The number of emails of any type that can be sent by a user from the
     * service per day. If an email is sent to two different recipients, this
     * counts as two emails.
     */
    [[nodiscard]] const std::optional<qint32> & userMailLimitDaily() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUserMailLimitDaily();
    void setUserMailLimitDaily(std::optional<qint32> userMailLimitDaily);

    /**
     * Maximum total size of a Note that can be added. The size of a note is
     * calculated as:
     * ENML content length (in Unicode characters) plus the sum of all resource
     * sizes (in bytes).
     */
    [[nodiscard]] const std::optional<qint64> & noteSizeMax() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableNoteSizeMax();
    void setNoteSizeMax(std::optional<qint64> noteSizeMax);

    /**
     * Maximum size of a resource, in bytes
     */
    [[nodiscard]] const std::optional<qint64> & resourceSizeMax() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableResourceSizeMax();
    void setResourceSizeMax(std::optional<qint64> resourceSizeMax);

    /**
     * Maximum number of linked notebooks per account.
     */
    [[nodiscard]] const std::optional<qint32> & userLinkedNotebookMax() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUserLinkedNotebookMax();
    void setUserLinkedNotebookMax(std::optional<qint32> userLinkedNotebookMax);

    /**
     * The number of bytes that can be uploaded to the account
     * in the current month. For new notes that are created, this is the length
     * of the note content (in Unicode characters) plus the size of each resource
     * (in bytes). For edited notes, this is the the difference between the old
     * length and the new length (if this is greater than 0) plus the size of
     * each new resource.
     */
    [[nodiscard]] const std::optional<qint64> & uploadLimit() const noexcept;
    [[nodiscard]] std::optional<qint64> & mutableUploadLimit();
    void setUploadLimit(std::optional<qint64> uploadLimit);

    /**
     * Maximum number of Notes per user
     */
    [[nodiscard]] const std::optional<qint32> & userNoteCountMax() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUserNoteCountMax();
    void setUserNoteCountMax(std::optional<qint32> userNoteCountMax);

    /**
     * Maximum number of Notebooks per user
     */
    [[nodiscard]] const std::optional<qint32> & userNotebookCountMax() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUserNotebookCountMax();
    void setUserNotebookCountMax(std::optional<qint32> userNotebookCountMax);

    /**
     * Maximum number of Tags per account
     */
    [[nodiscard]] const std::optional<qint32> & userTagCountMax() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUserTagCountMax();
    void setUserTagCountMax(std::optional<qint32> userTagCountMax);

    /**
     * Maximum number of Tags per Note
     */
    [[nodiscard]] const std::optional<qint32> & noteTagCountMax() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableNoteTagCountMax();
    void setNoteTagCountMax(std::optional<qint32> noteTagCountMax);

    /**
     * Maximum number of SavedSearches per account
     */
    [[nodiscard]] const std::optional<qint32> & userSavedSearchesMax() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUserSavedSearchesMax();
    void setUserSavedSearchesMax(std::optional<qint32> userSavedSearchesMax);

    /**
     * The maximum number of Resources per Note
     */
    [[nodiscard]] const std::optional<qint32> & noteResourceCountMax() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableNoteResourceCountMax();
    void setNoteResourceCountMax(std::optional<qint32> noteResourceCountMax);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<qint32> userMailLimitDaily READ userMailLimitDaily WRITE setUserMailLimitDaily)
    Q_PROPERTY(std::optional<qint64> noteSizeMax READ noteSizeMax WRITE setNoteSizeMax)
    Q_PROPERTY(std::optional<qint64> resourceSizeMax READ resourceSizeMax WRITE setResourceSizeMax)
    Q_PROPERTY(std::optional<qint32> userLinkedNotebookMax READ userLinkedNotebookMax WRITE setUserLinkedNotebookMax)
    Q_PROPERTY(std::optional<qint64> uploadLimit READ uploadLimit WRITE setUploadLimit)
    Q_PROPERTY(std::optional<qint32> userNoteCountMax READ userNoteCountMax WRITE setUserNoteCountMax)
    Q_PROPERTY(std::optional<qint32> userNotebookCountMax READ userNotebookCountMax WRITE setUserNotebookCountMax)
    Q_PROPERTY(std::optional<qint32> userTagCountMax READ userTagCountMax WRITE setUserTagCountMax)
    Q_PROPERTY(std::optional<qint32> noteTagCountMax READ noteTagCountMax WRITE setNoteTagCountMax)
    Q_PROPERTY(std::optional<qint32> userSavedSearchesMax READ userSavedSearchesMax WRITE setUserSavedSearchesMax)
    Q_PROPERTY(std::optional<qint32> noteResourceCountMax READ noteResourceCountMax WRITE setNoteResourceCountMax)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const AccountLimits & lhs, const AccountLimits & rhs) noexcept;
[[nodiscard]] bool operator!=(const AccountLimits & lhs, const AccountLimits & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::AccountLimits)

#endif // QEVERCLOUD_GENERATED_ACCOUNTLIMITS_H
