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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEDATA_H
#define QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEDATA_H

#include <generated/types/BootstrapProfile.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BootstrapProfile::BootstrapProfileData final:
    public QSharedData,
    public Printable
{
public:
    BootstrapProfileData() = default;
    BootstrapProfileData(const BootstrapProfileData & other) = default;
    BootstrapProfileData(BootstrapProfileData && other) noexcept = default;

    BootstrapProfileData & operator=(const BootstrapProfileData & other) = delete;
    BootstrapProfileData & operator=(BootstrapProfileData && other) = delete;

    ~BootstrapProfileData() noexcept override = default;

    [[nodiscard]] bool operator==(const BootstrapProfileData & other) const noexcept;
    [[nodiscard]] bool operator!=(const BootstrapProfileData & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_name;
    BootstrapSettings m_settings;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEDATA_H
