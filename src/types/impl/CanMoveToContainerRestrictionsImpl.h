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

#ifndef QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSIMPL
#define QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSIMPL

#include <qevercloud/types/CanMoveToContainerRestrictions.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN CanMoveToContainerRestrictions::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const CanMoveToContainerRestrictions::Impl & other) = default;
    Impl(CanMoveToContainerRestrictions::Impl && other) noexcept = default;

    CanMoveToContainerRestrictions::Impl & operator=(const CanMoveToContainerRestrictions::Impl & other) = delete;
    CanMoveToContainerRestrictions::Impl & operator=(CanMoveToContainerRestrictions::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<CanMoveToContainerStatus> m_canMoveToContainer;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONSIMPL
