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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPINFO_H
#define QEVERCLOUD_GENERATED_BOOTSTRAPINFO_H

#include <qevercloud/Export.h>

#include "BootstrapProfile.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QList>
#include <QSharedDataPointer>

namespace qevercloud {

/**
 * This structure describes a collection of bootstrap profiles.
 **/
class QEVERCLOUD_EXPORT BootstrapInfo: public Printable
{
    Q_GADGET
public:
    BootstrapInfo();
    BootstrapInfo(const BootstrapInfo & other);
    BootstrapInfo(BootstrapInfo && other) noexcept;
    ~BootstrapInfo() noexcept override;

    BootstrapInfo & operator=(const BootstrapInfo & other);
    BootstrapInfo & operator=(BootstrapInfo && other) noexcept;

    /**
     * List of one or more bootstrap profiles, in descending
     * preference order.
     */
    [[nodiscard]] const QList<BootstrapProfile> & profiles() const noexcept;
    [[nodiscard]] QList<BootstrapProfile> & mutableProfiles();
    void setProfiles(QList<BootstrapProfile> profiles);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const BootstrapInfo & other) const noexcept;
    [[nodiscard]] bool operator!=(const BootstrapInfo & other) const noexcept;

    Q_PROPERTY(QList<BootstrapProfile> profiles READ profiles WRITE setProfiles)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::BootstrapInfo)

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPINFO_H
