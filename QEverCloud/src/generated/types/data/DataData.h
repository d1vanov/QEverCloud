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

#ifndef QEVERCLOUD_GENERATED_DATADATA_H
#define QEVERCLOUD_GENERATED_DATADATA_H

#include <generated/types/Data.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Data::DataData final:
    public QSharedData,
    public Printable
{
public:
    DataData() = default;
    DataData(const DataData & other) = default;
    DataData(DataData && other) noexcept = default;

    DataData & operator=(const DataData & other) = delete;
    DataData & operator=(DataData && other) = delete;

    ~DataData() noexcept override = default;

    [[nodiscard]] bool operator==(const DataData & other) const noexcept;
    [[nodiscard]] bool operator!=(const DataData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QByteArray> m_bodyHash;
    std::optional<qint32> m_size;
    std::optional<QByteArray> m_body;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_DATADATA_H
