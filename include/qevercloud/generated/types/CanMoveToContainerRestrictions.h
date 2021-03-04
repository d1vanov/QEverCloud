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

#ifndef QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONS_H
#define QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONS_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * Specifies if the client can move a Notebook to a Workspace.
 */
class QEVERCLOUD_EXPORT CanMoveToContainerRestrictions: public Printable
{
    Q_GADGET
public:
    CanMoveToContainerRestrictions();
    CanMoveToContainerRestrictions(const CanMoveToContainerRestrictions & other);
    CanMoveToContainerRestrictions(CanMoveToContainerRestrictions && other) noexcept;
    ~CanMoveToContainerRestrictions() noexcept override;

    CanMoveToContainerRestrictions & operator=(const CanMoveToContainerRestrictions & other);
    CanMoveToContainerRestrictions & operator=(CanMoveToContainerRestrictions && other) noexcept;

    [[nodiscard]] const std::optional<CanMoveToContainerStatus> & canMoveToContainer() const noexcept;
    [[nodiscard]] std::optional<CanMoveToContainerStatus> & mutableCanMoveToContainer();
    void setCanMoveToContainer(std::optional<CanMoveToContainerStatus> canMoveToContainer);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(std::optional<CanMoveToContainerStatus> canMoveToContainer READ canMoveToContainer WRITE setCanMoveToContainer)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] bool operator==(const CanMoveToContainerRestrictions & lhs, const CanMoveToContainerRestrictions & rhs) noexcept;
[[nodiscard]] bool operator!=(const CanMoveToContainerRestrictions & lhs, const CanMoveToContainerRestrictions & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::CanMoveToContainerRestrictions)

#endif // QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONS_H
