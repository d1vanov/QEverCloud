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

#ifndef QEVERCLOUD_GENERATED_NOTELIMITSBUILDER
#define QEVERCLOUD_GENERATED_NOTELIMITSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteLimits.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteLimitsBuilder
{
public:
    NoteLimitsBuilder();

    NoteLimitsBuilder(NoteLimitsBuilder && other) noexcept;

    ~NoteLimitsBuilder() noexcept;

    NoteLimitsBuilder & operator=(NoteLimitsBuilder && other) noexcept;

    NoteLimitsBuilder & setNoteResourceCountMax(std::optional<qint32> noteResourceCountMax);
    NoteLimitsBuilder & setUploadLimit(std::optional<qint64> uploadLimit);
    NoteLimitsBuilder & setResourceSizeMax(std::optional<qint64> resourceSizeMax);
    NoteLimitsBuilder & setNoteSizeMax(std::optional<qint64> noteSizeMax);
    NoteLimitsBuilder & setUploaded(std::optional<qint64> uploaded);

    [[nodiscard]] NoteLimits build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTELIMITSBUILDER
