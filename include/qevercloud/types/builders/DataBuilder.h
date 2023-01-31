/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_DATABUILDER
#define QEVERCLOUD_GENERATED_DATABUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Data.h>
#include <qevercloud/types/TypeAliases.h>
#include <QByteArray>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT DataBuilder
{
public:
    DataBuilder();

    DataBuilder(DataBuilder && other) noexcept;

    ~DataBuilder() noexcept;

    DataBuilder & operator=(DataBuilder && other) noexcept;

    DataBuilder & setBodyHash(std::optional<QByteArray> bodyHash);
    DataBuilder & setSize(std::optional<qint32> size);
    DataBuilder & setBody(std::optional<QByteArray> body);

    [[nodiscard]] Data build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_DATABUILDER
