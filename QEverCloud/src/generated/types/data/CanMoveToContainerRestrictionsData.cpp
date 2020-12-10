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

#include "CanMoveToContainerRestrictionsData.h"

#include <QTextStream>

namespace qevercloud {

bool CanMoveToContainerRestrictions::CanMoveToContainerRestrictionsData::operator==(
    const CanMoveToContainerRestrictionsData & other) const noexcept
{
    if (this == &other) {
        return true;
    }

    return
        m_canMoveToContainer == other.m_canMoveToContainer;
}

bool CanMoveToContainerRestrictions::CanMoveToContainerRestrictionsData::operator!=(
    const CanMoveToContainerRestrictionsData & other) const noexcept
{
    return !(*this == other);
}

void CanMoveToContainerRestrictions::CanMoveToContainerRestrictionsData::print(QTextStream & strm) const
{
    strm << "CanMoveToContainerRestrictions: {\n";

    if (m_canMoveToContainer) {
        strm << "    canMoveToContainer = "
            << *m_canMoveToContainer << "\n";
    }
    else {
        strm << "    canMoveToContainer is not set\n";
    }

    strm << "}\n";
}

} // namespace qevercloud
