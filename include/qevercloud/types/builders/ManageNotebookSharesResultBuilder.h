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

#ifndef QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTBUILDER
#define QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/ManageNotebookSharesError.h>
#include <qevercloud/types/ManageNotebookSharesResult.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ManageNotebookSharesResultBuilder
{
public:
    ManageNotebookSharesResultBuilder();

    ManageNotebookSharesResultBuilder(ManageNotebookSharesResultBuilder && other) noexcept;

    ~ManageNotebookSharesResultBuilder() noexcept;

    ManageNotebookSharesResultBuilder & operator=(ManageNotebookSharesResultBuilder && other) noexcept;

    ManageNotebookSharesResultBuilder & setErrors(std::optional<QList<ManageNotebookSharesError>> errors);

    [[nodiscard]] ManageNotebookSharesResult build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTEBOOKSHARESRESULTBUILDER
