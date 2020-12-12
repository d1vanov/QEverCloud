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

#include <generated/types/ManageNoteSharesResult.h>

#include "impl/ManageNoteSharesResultImpl.h"

namespace qevercloud {

ManageNoteSharesResult::ManageNoteSharesResult() : d(new ManageNoteSharesResult::Impl) {}

ManageNoteSharesResult::ManageNoteSharesResult(const ManageNoteSharesResult & other) : d(other.d) {}

ManageNoteSharesResult::ManageNoteSharesResult(ManageNoteSharesResult && other) noexcept : d(std::move(other.d))
{}

ManageNoteSharesResult::~ManageNoteSharesResult() noexcept {}

ManageNoteSharesResult & ManageNoteSharesResult::operator=(const ManageNoteSharesResult & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

ManageNoteSharesResult & ManageNoteSharesResult::operator=(ManageNoteSharesResult && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QList<ManageNoteSharesError>> & ManageNoteSharesResult::errors() const noexcept
{
    return d->m_errors;
}

std::optional<QList<ManageNoteSharesError>> & ManageNoteSharesResult::mutableErrors()
{
    return d->m_errors;
}

void ManageNoteSharesResult::setErrors(std::optional<QList<ManageNoteSharesError>> errors)
{
    d->m_errors = errors;
}

void ManageNoteSharesResult::print(QTextStream & strm) const
{
    d->print(strm);
}

bool ManageNoteSharesResult::operator==(const ManageNoteSharesResult & other) const noexcept
{
    return *d == *other.d;
}

bool ManageNoteSharesResult::operator!=(const ManageNoteSharesResult & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
