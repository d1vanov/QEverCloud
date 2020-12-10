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

#ifndef QEVERCLOUD_GENERATED_BOOTSTRAPPROFILE_H
#define QEVERCLOUD_GENERATED_BOOTSTRAPPROFILE_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "BootstrapSettings.h"
#include "TypeAliases.h"

namespace qevercloud {

/**
 * This structure describes a collection of bootstrap settings.
 **/
class QEVERCLOUD_EXPORT BootstrapProfile: public Printable
{
    Q_GADGET
public:
    BootstrapProfile();
    BootstrapProfile(const BootstrapProfile & other);
    BootstrapProfile(BootstrapProfile && other) noexcept;
    ~BootstrapProfile() noexcept override;

    BootstrapProfile & operator=(const BootstrapProfile & other);
    BootstrapProfile & operator=(BootstrapProfile && other) noexcept;

    /**
    The unique name of the profile, which is guaranteed to remain consistent across
       calls to getBootstrapInfo.
    */
    [[nodiscard]] const QString & name() const noexcept;
    void setName(QString name);

    /**
    The settings for this profile.
    */
    [[nodiscard]] const BootstrapSettings & settings() const noexcept;
    [[nodiscard]] BootstrapSettings & mutableSettings();
    void setSettings(BootstrapSettings settings);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const BootstrapProfile & other) const noexcept;
    [[nodiscard]] bool operator!=(const BootstrapProfile & other) const noexcept;

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(BootstrapSettings settings READ settings WRITE setSettings)

private:
    class BootstrapProfileData;
    QSharedDataPointer<BootstrapProfileData> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::BootstrapProfile)

#endif // QEVERCLOUD_GENERATED_BOOTSTRAPPROFILE_H
