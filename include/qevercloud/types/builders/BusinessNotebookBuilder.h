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

#ifndef QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKBUILDER
#define QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BusinessNotebook.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT BusinessNotebookBuilder
{
public:
    BusinessNotebookBuilder();

    BusinessNotebookBuilder(BusinessNotebookBuilder && other) noexcept;

    ~BusinessNotebookBuilder() noexcept;

    BusinessNotebookBuilder & operator=(BusinessNotebookBuilder && other) noexcept;

    BusinessNotebookBuilder & setNotebookDescription(std::optional<QString> notebookDescription);
    BusinessNotebookBuilder & setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege);
    BusinessNotebookBuilder & setRecommended(std::optional<bool> recommended);

    [[nodiscard]] BusinessNotebook build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKBUILDER
