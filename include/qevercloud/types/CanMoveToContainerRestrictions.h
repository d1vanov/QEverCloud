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

#ifndef QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONS
#define QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONS

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
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

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const CanMoveToContainerRestrictions & canMoveToContainerRestrictions);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const CanMoveToContainerRestrictions & canMoveToContainerRestrictions);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const CanMoveToContainerRestrictions & canMoveToContainerRestrictions);

    Q_PROPERTY(std::optional<CanMoveToContainerStatus> canMoveToContainer READ canMoveToContainer WRITE setCanMoveToContainer)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const CanMoveToContainerRestrictions & lhs, const CanMoveToContainerRestrictions & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const CanMoveToContainerRestrictions & lhs, const CanMoveToContainerRestrictions & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CANMOVETOCONTAINERRESTRICTIONS