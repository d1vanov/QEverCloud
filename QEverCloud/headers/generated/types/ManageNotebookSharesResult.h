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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULT_H
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULT_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "ManageNotebookSharesError.h"
#include "TypeAliases.h"
#include <QList>
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
    If the method completed without throwing exceptions, some errors
     might still have occurred, and in that case, this field will contain
     the list of those errors the occurred.
    */
    [[nodiscard]] const std::optional<QList<ManageNotebookSharesError>> & errors() const noexcept;
    [[nodiscard]] std::optional<QList<ManageNotebookSharesError>> & mutableErrors();
    void setErrors(std::optional<QList<ManageNotebookSharesError>> errors);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const ManageNotebookSharesResult & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNotebookSharesResult & other) const noexcept;

    Q_PROPERTY(std::optional<QList<ManageNotebookSharesError>> errors READ errors WRITE setErrors)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ManageNotebookSharesResult)

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULT_H
