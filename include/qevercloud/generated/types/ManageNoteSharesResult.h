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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULT_H
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULT_H

#include <qevercloud/Export.h>

#include "ManageNoteSharesError.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
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
    If the call succeeded without throwing an exception, some errors
         might still have occurred. In that case, this field will contain the
         list of errors.
    */
    [[nodiscard]] const std::optional<QList<ManageNoteSharesError>> & errors() const noexcept;
    [[nodiscard]] std::optional<QList<ManageNoteSharesError>> & mutableErrors();
    void setErrors(std::optional<QList<ManageNoteSharesError>> errors);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const ManageNoteSharesResult & other) const noexcept;
    [[nodiscard]] bool operator!=(const ManageNoteSharesResult & other) const noexcept;

    Q_PROPERTY(std::optional<QList<ManageNoteSharesError>> errors READ errors WRITE setErrors)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::ManageNoteSharesResult)

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULT_H
