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

#ifndef QEVERCLOUD_GENERATED_PUBLISHINGIMPL
#define QEVERCLOUD_GENERATED_PUBLISHINGIMPL

#include <qevercloud/types/Publishing.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Publishing::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const Publishing::Impl & other) = default;
    Impl(Publishing::Impl && other) noexcept = default;

    Publishing::Impl & operator=(const Publishing::Impl & other) = delete;
    Publishing::Impl & operator=(Publishing::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_uri;
    std::optional<NoteSortOrder> m_order;
    std::optional<bool> m_ascending;
    std::optional<QString> m_publicDescription;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_PUBLISHINGIMPL
