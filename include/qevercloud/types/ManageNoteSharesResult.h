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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULT
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULT

#include <qevercloud/Export.h>

#include "ManageNoteSharesError.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * The return value of a call to the manageNoteShares function.
 *
 * */
class QEVERCLOUD_EXPORT ManageNoteSharesResult: public Printable
{
    Q_GADGET
public:
    ManageNoteSharesResult();
    ManageNoteSharesResult(const ManageNoteSharesResult & other);
    ManageNoteSharesResult(ManageNoteSharesResult && other) noexcept;
    ~ManageNoteSharesResult() noexcept override;

    ManageNoteSharesResult & operator=(const ManageNoteSharesResult & other);
    ManageNoteSharesResult & operator=(ManageNoteSharesResult && other) noexcept;

    /**
     * If the call succeeded without throwing an exception, some errors
     * might still have occurred. In that case, this field will contain the
     * list of errors.
     */
    [[nodiscard]] const std::optional<QList<ManageNoteSharesError>> & errors() const noexcept;
    [[nodiscard]] std::optional<QList<ManageNoteSharesError>> & mutableErrors();
    void setErrors(std::optional<QList<ManageNoteSharesError>> errors);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const ManageNoteSharesResult & manageNoteSharesResult);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const ManageNoteSharesResult & manageNoteSharesResult);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const ManageNoteSharesResult & manageNoteSharesResult);

    Q_PROPERTY(std::optional<QList<ManageNoteSharesError>> errors READ errors WRITE setErrors)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const ManageNoteSharesResult & lhs, const ManageNoteSharesResult & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const ManageNoteSharesResult & lhs, const ManageNoteSharesResult & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULT
