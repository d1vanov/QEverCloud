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

#ifndef QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONIMPL
#define QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONIMPL

#include <qevercloud/exceptions/EDAMNotFoundException.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMNotFoundException::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const EDAMNotFoundException::Impl & other) = default;
    Impl(EDAMNotFoundException::Impl && other) noexcept = default;

    EDAMNotFoundException::Impl & operator=(const EDAMNotFoundException::Impl & other) = delete;
    EDAMNotFoundException::Impl & operator=(EDAMNotFoundException::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_identifier;
    std::optional<QString> m_key;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONIMPL
