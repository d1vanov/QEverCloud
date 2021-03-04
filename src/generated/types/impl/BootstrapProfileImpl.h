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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEIMPL_H
#define QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEIMPL_H

#include <qevercloud/generated/types/BootstrapProfile.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BootstrapProfile::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const BootstrapProfile::Impl & other) = default;
    Impl(BootstrapProfile::Impl && other) noexcept = default;

    BootstrapProfile::Impl & operator=(const BootstrapProfile::Impl & other) = delete;
    BootstrapProfile::Impl & operator=(BootstrapProfile::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    QString m_name;
    BootstrapSettings m_settings;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEIMPL_H
