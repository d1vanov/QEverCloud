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

#ifndef QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKIMPL_H
#define QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKIMPL_H

#include <qevercloud/generated/types/BusinessNotebook.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessNotebook::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const BusinessNotebook::Impl & other) = default;
    Impl(BusinessNotebook::Impl && other) noexcept = default;

    BusinessNotebook::Impl & operator=(const BusinessNotebook::Impl & other) = delete;
    BusinessNotebook::Impl & operator=(BusinessNotebook::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_notebookDescription;
    std::optional<SharedNotebookPrivilegeLevel> m_privilege;
    std::optional<bool> m_recommended;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BUSINESSNOTEBOOKIMPL_H
