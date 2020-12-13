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

#ifndef QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULT_H
#define QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULT_H

#include "../../Export.h"

#include "SharedNotebook.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/Printable.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <QList>
#include <optional>

namespace qevercloud {

/**
 * A structure containing the results of a call to createOrUpdateNotebookShares.
 *
 * */
class QEVERCLOUD_EXPORT CreateOrUpdateNotebookSharesResult: public Printable
{
    Q_GADGET
public:
    CreateOrUpdateNotebookSharesResult();
    CreateOrUpdateNotebookSharesResult(const CreateOrUpdateNotebookSharesResult & other);
    CreateOrUpdateNotebookSharesResult(CreateOrUpdateNotebookSharesResult && other) noexcept;
    ~CreateOrUpdateNotebookSharesResult() noexcept override;

    CreateOrUpdateNotebookSharesResult & operator=(const CreateOrUpdateNotebookSharesResult & other);
    CreateOrUpdateNotebookSharesResult & operator=(CreateOrUpdateNotebookSharesResult && other) noexcept;

    /**
    The USN of the notebook after the call.
    */
    [[nodiscard]] const std::optional<qint32> & updateSequenceNum() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUpdateSequenceNum();
    void setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);

    /**
    A list of SharedNotebook records that match the desired recipients. These
           records may have been either created or updated by the call to
           createOrUpdateNotebookShares, or they may have been at the desired privilege
           privilege level prior to the call.
    */
    [[nodiscard]] const std::optional<QList<SharedNotebook>> & matchingShares() const noexcept;
    [[nodiscard]] std::optional<QList<SharedNotebook>> & mutableMatchingShares();
    void setMatchingShares(std::optional<QList<SharedNotebook>> matchingShares);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const CreateOrUpdateNotebookSharesResult & other) const noexcept;
    [[nodiscard]] bool operator!=(const CreateOrUpdateNotebookSharesResult & other) const noexcept;

    Q_PROPERTY(std::optional<qint32> updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(std::optional<QList<SharedNotebook>> matchingShares READ matchingShares WRITE setMatchingShares)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::CreateOrUpdateNotebookSharesResult)

#endif // QEVERCLOUD_GENERATED_CREATEORUPDATENOTEBOOKSHARESRESULT_H
