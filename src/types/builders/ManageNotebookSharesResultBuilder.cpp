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

#include <qevercloud/types/builders/ManageNotebookSharesResultBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNotebookSharesResultBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QList<ManageNotebookSharesError>> m_errors;
};

ManageNotebookSharesResultBuilder::ManageNotebookSharesResultBuilder() :
    d(new ManageNotebookSharesResultBuilder::Impl)
{}

ManageNotebookSharesResultBuilder::ManageNotebookSharesResultBuilder(ManageNotebookSharesResultBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ManageNotebookSharesResultBuilder::~ManageNotebookSharesResultBuilder() noexcept = default;

ManageNotebookSharesResultBuilder & ManageNotebookSharesResultBuilder::operator=(ManageNotebookSharesResultBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ManageNotebookSharesResultBuilder & ManageNotebookSharesResultBuilder::setErrors(std::optional<QList<ManageNotebookSharesError>> errors)
{
    d->m_errors = std::move(errors);
    return *this;
}

ManageNotebookSharesResult ManageNotebookSharesResultBuilder::build()
{
    ManageNotebookSharesResult result;

    result.setErrors(std::move(d->m_errors));

    d->m_errors = {};

    return result;
}

} // namespace qevercloud
