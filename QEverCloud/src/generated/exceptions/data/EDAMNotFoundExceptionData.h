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

#ifndef QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONDATA_H
#define QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONDATA_H

#include <generated/exceptions/EDAMNotFoundException.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN EDAMNotFoundException::EDAMNotFoundExceptionData final:
    public QSharedData,
    public Printable
{
public:
    EDAMNotFoundExceptionData() = default;
    EDAMNotFoundExceptionData(const EDAMNotFoundExceptionData & other) = default;
    EDAMNotFoundExceptionData(EDAMNotFoundExceptionData && other) noexcept = default;

    EDAMNotFoundExceptionData & operator=(const EDAMNotFoundExceptionData & other) = delete;
    EDAMNotFoundExceptionData & operator=(EDAMNotFoundExceptionData && other) = delete;

    ~EDAMNotFoundExceptionData() noexcept override = default;

    [[nodiscard]] bool operator==(const EDAMNotFoundExceptionData & other) const noexcept;
    [[nodiscard]] bool operator!=(const EDAMNotFoundExceptionData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_identifier;
    std::optional<QString> m_key;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_EDAMNOTFOUNDEXCEPTIONDATA_H
