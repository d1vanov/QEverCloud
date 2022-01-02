/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTBUILDER
#define QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/ManageNoteSharesError.h>
#include <qevercloud/types/ManageNoteSharesResult.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT ManageNoteSharesResultBuilder
{
public:
    ManageNoteSharesResultBuilder();

    ManageNoteSharesResultBuilder(ManageNoteSharesResultBuilder && other) noexcept;

    ~ManageNoteSharesResultBuilder() noexcept;

    ManageNoteSharesResultBuilder & operator=(ManageNoteSharesResultBuilder && other) noexcept;

    ManageNoteSharesResultBuilder & setErrors(std::optional<QList<ManageNoteSharesError>> errors);

    [[nodiscard]] ManageNoteSharesResult build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_MANAGENOTESHARESRESULTBUILDER
