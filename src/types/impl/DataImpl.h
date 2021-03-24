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

#ifndef QEVERCLOUD_GENERATED_DATAIMPL_H
#define QEVERCLOUD_GENERATED_DATAIMPL_H

#include <qevercloud/types/Data.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Data::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const Data::Impl & other) = default;
    Impl(Data::Impl && other) noexcept = default;

    Data::Impl & operator=(const Data::Impl & other) = delete;
    Data::Impl & operator=(Data::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QByteArray> m_bodyHash;
    std::optional<qint32> m_size;
    std::optional<QByteArray> m_body;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_DATAIMPL_H
