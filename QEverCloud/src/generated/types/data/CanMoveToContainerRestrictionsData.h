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

#ifndef QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSDATA_H
#define QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSDATA_H

#include <generated/types/CanMoveToContainerRestrictions.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN CanMoveToContainerRestrictions::CanMoveToContainerRestrictionsData final:
    public QSharedData,
    public Printable
{
public:
    CanMoveToContainerRestrictionsData() = default;
    CanMoveToContainerRestrictionsData(const CanMoveToContainerRestrictionsData & other) = default;
    CanMoveToContainerRestrictionsData(CanMoveToContainerRestrictionsData && other) noexcept = default;

    CanMoveToContainerRestrictionsData & operator=(const CanMoveToContainerRestrictionsData & other) = delete;
    CanMoveToContainerRestrictionsData & operator=(CanMoveToContainerRestrictionsData && other) = delete;

    ~CanMoveToContainerRestrictionsData() noexcept override = default;

    [[nodiscard]] bool operator==(const CanMoveToContainerRestrictionsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const CanMoveToContainerRestrictionsData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<CanMoveToContainerStatus> m_canMoveToContainer;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSDATA_H
