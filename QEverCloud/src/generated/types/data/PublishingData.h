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

#ifndef QEVERCLOUD_GENERATED_PUBLISHINGDATA_H
#define QEVERCLOUD_GENERATED_PUBLISHINGDATA_H

#include <generated/types/Publishing.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Publishing::PublishingData final:
    public QSharedData,
    public Printable
{
public:
    PublishingData() = default;
    PublishingData(const PublishingData & other) = default;
    PublishingData(PublishingData && other) noexcept = default;

    PublishingData & operator=(const PublishingData & other) = delete;
    PublishingData & operator=(PublishingData && other) = delete;

    ~PublishingData() noexcept override = default;

    [[nodiscard]] bool operator==(const PublishingData & other) const noexcept;
    [[nodiscard]] bool operator!=(const PublishingData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_uri;
    std::optional<NoteSortOrder> m_order;
    std::optional<bool> m_ascending;
    std::optional<QString> m_publicDescription;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_PUBLISHINGDATA_H
