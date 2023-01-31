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

#ifndef QEVERCLOUD_GENERATED_PUBLISHINGBUILDER
#define QEVERCLOUD_GENERATED_PUBLISHINGBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Publishing.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT PublishingBuilder
{
public:
    PublishingBuilder();

    PublishingBuilder(PublishingBuilder && other) noexcept;

    ~PublishingBuilder() noexcept;

    PublishingBuilder & operator=(PublishingBuilder && other) noexcept;

    PublishingBuilder & setUri(std::optional<QString> uri);
    PublishingBuilder & setOrder(std::optional<NoteSortOrder> order);
    PublishingBuilder & setAscending(std::optional<bool> ascending);
    PublishingBuilder & setPublicDescription(std::optional<QString> publicDescription);

    [[nodiscard]] Publishing build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_PUBLISHINGBUILDER