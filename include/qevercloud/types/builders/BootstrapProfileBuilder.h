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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEBUILDER
#define QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BootstrapProfile.h>
#include <qevercloud/types/BootstrapSettings.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>

namespace qevercloud {

class QEVERCLOUD_EXPORT BootstrapProfileBuilder
{
public:
    BootstrapProfileBuilder();

    BootstrapProfileBuilder(BootstrapProfileBuilder && other) noexcept;

    ~BootstrapProfileBuilder() noexcept;

    BootstrapProfileBuilder & operator=(BootstrapProfileBuilder && other) noexcept;

    BootstrapProfileBuilder & setName(QString name);
    BootstrapProfileBuilder & setSettings(BootstrapSettings settings);

    [[nodiscard]] BootstrapProfile build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPPROFILEBUILDER
