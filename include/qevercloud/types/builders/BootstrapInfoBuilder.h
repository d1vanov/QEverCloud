/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPINFOBUILDER
#define QEVERCLOUD_GENERATED_BOOTSTRAPINFOBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BootstrapInfo.h>
#include <qevercloud/types/BootstrapProfile.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>

namespace qevercloud {

class QEVERCLOUD_EXPORT BootstrapInfoBuilder
{
public:
    BootstrapInfoBuilder();

    BootstrapInfoBuilder(BootstrapInfoBuilder && other) noexcept;

    ~BootstrapInfoBuilder() noexcept;

    BootstrapInfoBuilder & operator=(BootstrapInfoBuilder && other) noexcept;

    BootstrapInfoBuilder & setProfiles(QList<BootstrapProfile> profiles);

    [[nodiscard]] BootstrapInfo build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPINFOBUILDER
