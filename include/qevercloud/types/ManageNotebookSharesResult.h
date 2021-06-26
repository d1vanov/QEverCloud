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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULT
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULT

#include <qevercloud/Export.h>

#include "ManageNotebookSharesError.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * The return value of a call to the manageNotebookShares method.
 *
 * */
class QEVERCLOUD_EXPORT ManageNotebookSharesResult: public Printable
{
    Q_GADGET
public:
    ManageNotebookSharesResult();
    ManageNotebookSharesResult(const ManageNotebookSharesResult & other);
    ManageNotebookSharesResult(ManageNotebookSharesResult && other) noexcept;
    ~ManageNotebookSharesResult() noexcept override;

    ManageNotebookSharesResult & operator=(const ManageNotebookSharesResult & other);
    ManageNotebookSharesResult & operator=(ManageNotebookSharesResult && other) noexcept;

    /**
     * If the method completed without throwing exceptions, some errors
     * might still have occurred, and in that case, this field will contain
     * the list of those errors the occurred.
     */
    [[nodiscard]] const std::optional<QList<ManageNotebookSharesError>> & errors() const noexcept;
    [[nodiscard]] std::optional<QList<ManageNotebookSharesError>> & mutableErrors();
    void setErrors(std::optional<QList<ManageNotebookSharesError>> errors);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const ManageNotebookSharesResult & manageNotebookSharesResult);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const ManageNotebookSharesResult & manageNotebookSharesResult);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const ManageNotebookSharesResult & manageNotebookSharesResult);

    Q_PROPERTY(std::optional<QList<ManageNotebookSharesError>> errors READ errors WRITE setErrors)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const ManageNotebookSharesResult & lhs, const ManageNotebookSharesResult & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const ManageNotebookSharesResult & lhs, const ManageNotebookSharesResult & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ManageNotebookSharesResult)

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULT
