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

#include <generated/types/ManageNotebookSharesResult.h>

#include "impl/ManageNotebookSharesResultImpl.h"

namespace qevercloud {

ManageNotebookSharesResult::ManageNotebookSharesResult() : d(new ManageNotebookSharesResult::Impl) {}

ManageNotebookSharesResult::ManageNotebookSharesResult(const ManageNotebookSharesResult & other) : d(other.d) {}

ManageNotebookSharesResult::ManageNotebookSharesResult(ManageNotebookSharesResult && other) noexcept : d(std::move(other.d))
{}

ManageNotebookSharesResult::~ManageNotebookSharesResult() noexcept {}

ManageNotebookSharesResult & ManageNotebookSharesResult::operator=(const ManageNotebookSharesResult & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ManageNotebookSharesResult & ManageNotebookSharesResult::operator=(ManageNotebookSharesResult && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QList<ManageNotebookSharesError>> & ManageNotebookSharesResult::errors() const noexcept
{
    return d->m_errors;
}

std::optional<QList<ManageNotebookSharesError>> & ManageNotebookSharesResult::mutableErrors()
{
    return d->m_errors;
}

void ManageNotebookSharesResult::setErrors(std::optional<QList<ManageNotebookSharesError>> errors)
{
    d->m_errors = errors;
}

void ManageNotebookSharesResult::print(QTextStream & strm) const
{
    d->print(strm);
}

bool ManageNotebookSharesResult::operator==(const ManageNotebookSharesResult & other) const noexcept
{
    return *d == *other.d;
}

bool ManageNotebookSharesResult::operator!=(const ManageNotebookSharesResult & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
