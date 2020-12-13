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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPINFOIMPL_H
#define QEVERCLOUD_GENERATED_BOOTSTRAPINFOIMPL_H

#include <qevercloud/generated/types/BootstrapInfo.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BootstrapInfo::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const BootstrapInfo::Impl & other) = default;
    Impl(BootstrapInfo::Impl && other) noexcept = default;

    BootstrapInfo::Impl & operator=(const BootstrapInfo::Impl & other) = delete;
    BootstrapInfo::Impl & operator=(BootstrapInfo::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const BootstrapInfo::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const BootstrapInfo::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    QList<BootstrapProfile> m_profiles;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPINFOIMPL_H
