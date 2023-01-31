/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/CreateOrUpdateNotebookSharesResultBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN CreateOrUpdateNotebookSharesResultBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<qint32> m_updateSequenceNum;
    std::optional<QList<SharedNotebook>> m_matchingShares;
};

CreateOrUpdateNotebookSharesResultBuilder::CreateOrUpdateNotebookSharesResultBuilder() :
    d(new CreateOrUpdateNotebookSharesResultBuilder::Impl)
{}

CreateOrUpdateNotebookSharesResultBuilder::CreateOrUpdateNotebookSharesResultBuilder(CreateOrUpdateNotebookSharesResultBuilder && other) noexcept :
    d{std::move(other.d)}
{}

CreateOrUpdateNotebookSharesResultBuilder::~CreateOrUpdateNotebookSharesResultBuilder() noexcept = default;

CreateOrUpdateNotebookSharesResultBuilder & CreateOrUpdateNotebookSharesResultBuilder::operator=(CreateOrUpdateNotebookSharesResultBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

CreateOrUpdateNotebookSharesResultBuilder & CreateOrUpdateNotebookSharesResultBuilder::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = std::move(updateSequenceNum);
    return *this;
}

CreateOrUpdateNotebookSharesResultBuilder & CreateOrUpdateNotebookSharesResultBuilder::setMatchingShares(std::optional<QList<SharedNotebook>> matchingShares)
{
    d->m_matchingShares = std::move(matchingShares);
    return *this;
}

CreateOrUpdateNotebookSharesResult CreateOrUpdateNotebookSharesResultBuilder::build()
{
    CreateOrUpdateNotebookSharesResult result;

    result.setUpdateSequenceNum(std::move(d->m_updateSequenceNum));
    result.setMatchingShares(std::move(d->m_matchingShares));

    d->m_updateSequenceNum = {};
    d->m_matchingShares = {};

    return result;
}

} // namespace qevercloud
