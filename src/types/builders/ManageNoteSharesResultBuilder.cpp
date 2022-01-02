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

#include <qevercloud/types/builders/ManageNoteSharesResultBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN ManageNoteSharesResultBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QList<ManageNoteSharesError>> m_errors;
};

ManageNoteSharesResultBuilder::ManageNoteSharesResultBuilder() :
    d(new ManageNoteSharesResultBuilder::Impl)
{}

ManageNoteSharesResultBuilder::ManageNoteSharesResultBuilder(ManageNoteSharesResultBuilder && other) noexcept :
    d{std::move(other.d)}
{}

ManageNoteSharesResultBuilder::~ManageNoteSharesResultBuilder() noexcept = default;

ManageNoteSharesResultBuilder & ManageNoteSharesResultBuilder::operator=(ManageNoteSharesResultBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

ManageNoteSharesResultBuilder & ManageNoteSharesResultBuilder::setErrors(std::optional<QList<ManageNoteSharesError>> errors)
{
    d->m_errors = std::move(errors);
    return *this;
}

ManageNoteSharesResult ManageNoteSharesResultBuilder::build()
{
    ManageNoteSharesResult result;

    result.setErrors(std::move(d->m_errors));

    d->m_errors = {};

    return result;
}

} // namespace qevercloud
