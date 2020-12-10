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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPINFODATA_H
#define QEVERCLOUD_GENERATED_BOOTSTRAPINFODATA_H

#include <generated/types/BootstrapInfo.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BootstrapInfo::BootstrapInfoData final:
    public QSharedData,
    public Printable
{
public:
    BootstrapInfoData() = default;
    BootstrapInfoData(const BootstrapInfoData & other) = default;
    BootstrapInfoData(BootstrapInfoData && other) noexcept = default;

    BootstrapInfoData & operator=(const BootstrapInfoData & other) = delete;
    BootstrapInfoData & operator=(BootstrapInfoData && other) = delete;

    ~BootstrapInfoData() noexcept override = default;

    [[nodiscard]] bool operator==(const BootstrapInfoData & other) const noexcept;
    [[nodiscard]] bool operator!=(const BootstrapInfoData & other) const noexcept;

    void print(QTextStream & strm) const override;

    QList<BootstrapProfile> m_profiles;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPINFODATA_H
