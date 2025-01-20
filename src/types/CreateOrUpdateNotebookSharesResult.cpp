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

#include <qevercloud/types/CreateOrUpdateNotebookSharesResult.h>

#include "impl/CreateOrUpdateNotebookSharesResultImpl.h"

namespace qevercloud {

CreateOrUpdateNotebookSharesResult::CreateOrUpdateNotebookSharesResult() :
    d(new CreateOrUpdateNotebookSharesResult::Impl)
{}

CreateOrUpdateNotebookSharesResult::CreateOrUpdateNotebookSharesResult(const CreateOrUpdateNotebookSharesResult & other) :
    d(other.d)
{}

CreateOrUpdateNotebookSharesResult::CreateOrUpdateNotebookSharesResult(CreateOrUpdateNotebookSharesResult && other) noexcept :
    d(std::move(other.d))
{}

CreateOrUpdateNotebookSharesResult::~CreateOrUpdateNotebookSharesResult() noexcept {}

CreateOrUpdateNotebookSharesResult & CreateOrUpdateNotebookSharesResult::operator=(const CreateOrUpdateNotebookSharesResult & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

CreateOrUpdateNotebookSharesResult & CreateOrUpdateNotebookSharesResult::operator=(CreateOrUpdateNotebookSharesResult && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<qint32> & CreateOrUpdateNotebookSharesResult::updateSequenceNum() const noexcept
{
    return d->m_updateSequenceNum;
}

std::optional<qint32> & CreateOrUpdateNotebookSharesResult::mutableUpdateSequenceNum()
{
    return d->m_updateSequenceNum;
}

void CreateOrUpdateNotebookSharesResult::setUpdateSequenceNum(std::optional<qint32> updateSequenceNum)
{
    d->m_updateSequenceNum = updateSequenceNum;
}

const std::optional<QList<SharedNotebook>> & CreateOrUpdateNotebookSharesResult::matchingShares() const noexcept
{
    return d->m_matchingShares;
}

std::optional<QList<SharedNotebook>> & CreateOrUpdateNotebookSharesResult::mutableMatchingShares()
{
    return d->m_matchingShares;
}

void CreateOrUpdateNotebookSharesResult::setMatchingShares(std::optional<QList<SharedNotebook>> matchingShares)
{
    d->m_matchingShares = std::move(matchingShares);
}

void CreateOrUpdateNotebookSharesResult::print(QTextStream & strm) const
{
    d->print(strm);
}

QTextStream & operator<<(QTextStream & strm, const CreateOrUpdateNotebookSharesResult & createOrUpdateNotebookSharesResult)
{
    strm << static_cast<const Printable&>(createOrUpdateNotebookSharesResult);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const CreateOrUpdateNotebookSharesResult & createOrUpdateNotebookSharesResult)
{
    dbg << static_cast<const Printable&>(createOrUpdateNotebookSharesResult);
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const CreateOrUpdateNotebookSharesResult & createOrUpdateNotebookSharesResult)
{
    strm << static_cast<const Printable&>(createOrUpdateNotebookSharesResult);
    return strm;
}

bool operator==(const CreateOrUpdateNotebookSharesResult & lhs, const CreateOrUpdateNotebookSharesResult & rhs) noexcept
{
    if (&lhs == &rhs) {
        return true;
    }

    return
        lhs.updateSequenceNum() == rhs.updateSequenceNum() &&
        lhs.matchingShares() == rhs.matchingShares();
}

bool operator!=(const CreateOrUpdateNotebookSharesResult & lhs, const CreateOrUpdateNotebookSharesResult & rhs) noexcept
{
    return !operator==(lhs, rhs);
}

} // namespace qevercloud
