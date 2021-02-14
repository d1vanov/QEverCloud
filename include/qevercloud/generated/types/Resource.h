/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_RESOURCE_H
#define QEVERCLOUD_GENERATED_RESOURCE_H

#include <qevercloud/Export.h>

#include "Data.h"
#include "ResourceAttributes.h"
#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

/**
 * Every media file that is embedded or attached to a note is represented
 * through a Resource entry.
 * */
class QEVERCLOUD_EXPORT Resource: public Printable
{
    Q_GADGET
public:
    Resource();
    Resource(const Resource & other);
    Resource(Resource && other) noexcept;
    ~Resource() noexcept override;

    Resource & operator=(const Resource & other);
    Resource & operator=(Resource && other) noexcept;

    /**
     * @brief localId can be used as a local unique identifier
     * for any data item before it has been synchronized with
     * Evernote and thus before it can be identified using its guid.
     *
     * localId is generated automatically on
     * construction for convenience but can be overridden manually
     */
    [[nodiscard]] const QString & localId() const noexcept;
    void setLocalId(QString id);

    /**
     * @brief locallyModified flag can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocallyModified() const noexcept;
    void setLocallyModified(bool modified = true);

    /**
     * @brief localOnly flag can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocalOnly() const noexcept;
    void setLocalOnly(bool localOnly = true);

    /**
     * @brief locallyFavorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * a property between different clients
     */
    [[nodiscard]] bool isLocallyFavorited() const noexcept;
    void setLocallyFavorited(bool favorited = true);

    /**
     * @brief localData property can be used to store any additional
     * data which might be needed to be set for the type object
     * by QEverCloud's client code
     */
    [[nodiscard]] const QHash<QString, QVariant> & localData() const noexcept;
    [[nodiscard]] QHash<QString, QVariant> & mutableLocalData();
    void setLocalData(QHash<QString, QVariant> localData);

    /**
     * The unique identifier of this resource. Will be set whenever
     * a resource is retrieved from the service, but may be null when a client
     * is creating a resource.
     * Length: EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
     * Regex: EDAM_GUID_REGEX
     */
    [[nodiscard]] const std::optional<Guid> & guid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableGuid();
    void setGuid(std::optional<Guid> guid);

    /**
     * The unique identifier of the Note that holds this
     * Resource. Will be set whenever the resource is retrieved from the service,
     * but may be null when a client is creating a resource.
     * Length: EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
     * Regex: EDAM_GUID_REGEX
     */
    [[nodiscard]] const std::optional<Guid> & noteGuid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableNoteGuid();
    void setNoteGuid(std::optional<Guid> noteGuid);

    /**
     * The contents of the resource.
     * Maximum length: The data.body is limited to EDAM_RESOURCE_SIZE_MAX_FREE
     * for free accounts and EDAM_RESOURCE_SIZE_MAX_PREMIUM for premium accounts.
     */
    [[nodiscard]] const std::optional<Data> & data() const noexcept;
    [[nodiscard]] std::optional<Data> & mutableData();
    void setData(std::optional<Data> data);

    /**
     * The MIME type for the embedded resource. E.g. "image/gif"
     * Length: EDAM_MIME_LEN_MIN - EDAM_MIME_LEN_MAX
     * Regex: EDAM_MIME_REGEX
     */
    [[nodiscard]] const std::optional<QString> & mime() const noexcept;
    void setMime(std::optional<QString> mime);

    /**
     * If set, this contains the display width of this resource, in
     * pixels.
     */
    [[nodiscard]] const std::optional<qint16> & width() const noexcept;
    [[nodiscard]] std::optional<qint16> & mutableWidth();
    void setWidth(std::optional<qint16> width);

    /**
     * If set, this contains the display height of this resource,
     * in pixels.
     */
    [[nodiscard]] const std::optional<qint16> & height() const noexcept;
    [[nodiscard]] std::optional<qint16> & mutableHeight();
    void setHeight(std::optional<qint16> height);

    /**
     * DEPRECATED: ignored.
     */
    [[nodiscard]] const std::optional<qint16> & duration() const noexcept;
    [[nodiscard]] std::optional<qint16> & mutableDuration();
    void setDuration(std::optional<qint16> duration);

    /**
     * If the resource is active or not.
     */
    [[nodiscard]] const std::optional<bool> & active() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableActive();
    void setActive(std::optional<bool> active);

    /**
     * If set, this will hold the encoded data that provides
     * information on search and recognition within this resource.
     */
    [[nodiscard]] const std::optional<Data> & recognition() const noexcept;
    [[nodiscard]] std::optional<Data> & mutableRecognition();
    void setRecognition(std::optional<Data> recognition);

    /**
     * A list of the attributes for this resource.
     */
    [[nodiscard]] const std::optional<ResourceAttributes> & attributes() const noexcept;
    [[nodiscard]] std::optional<ResourceAttributes> & mutableAttributes();
    void setAttributes(std::optional<ResourceAttributes> attributes);

    /**
     * A number identifying the last transaction to
     * modify the state of this object. The USN values are sequential within an
     * account, and can be used to compare the order of modifications within the
     * service.
     */
    [[nodiscard]] const std::optional<qint32> & updateSequenceNum() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUpdateSequenceNum();
    void setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);

    /**
     * Some Resources may be assigned an alternate data format by the service
     * which may be more appropriate for indexing or rendering than the original
     * data provided by the user. In these cases, the alternate data form will
     * be available via this Data element. If a Resource has no alternate form,
     * this field will be unset.
     */
    [[nodiscard]] const std::optional<Data> & alternateData() const noexcept;
    [[nodiscard]] std::optional<Data> & mutableAlternateData();
    void setAlternateData(std::optional<Data> alternateData);

    /**
     * Methods below correspond to fields which are NOT set by QEverCloud itself.
     * They exist for convenience of client code and are intended to be called
     * and used by QEverCloud's client code if/when appropriate
     */

    /**
     * Local id of a note to which this resource belongs
     */
    [[nodiscard]] QString noteLocalId() const;

    /**
     * Set local id of a note to which this resource belongs
     */
    void setNoteLocalId(QString noteLocalId);

    /**
     * Index of this resource within the note
     */
    [[nodiscard]] const std::optional<int> & indexInNote() const noexcept;

    /**
     * Set index of this resource within the note
     */
    void setIndexInNote(std::optional<int> index);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const Resource & other) const noexcept;
    [[nodiscard]] bool operator!=(const Resource & other) const noexcept;

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<Guid> guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<Guid> noteGuid READ noteGuid WRITE setNoteGuid)
    Q_PROPERTY(std::optional<Data> data READ data WRITE setData)
    Q_PROPERTY(std::optional<QString> mime READ mime WRITE setMime)
    Q_PROPERTY(std::optional<qint16> width READ width WRITE setWidth)
    Q_PROPERTY(std::optional<qint16> height READ height WRITE setHeight)
    Q_PROPERTY(std::optional<qint16> duration READ duration WRITE setDuration)
    Q_PROPERTY(std::optional<bool> active READ active WRITE setActive)
    Q_PROPERTY(std::optional<Data> recognition READ recognition WRITE setRecognition)
    Q_PROPERTY(std::optional<ResourceAttributes> attributes READ attributes WRITE setAttributes)
    Q_PROPERTY(std::optional<qint32> updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(std::optional<Data> alternateData READ alternateData WRITE setAlternateData)
    Q_PROPERTY(QString noteLocalId READ noteLocalId WRITE setNoteLocalId)
    Q_PROPERTY(std::optional<int> indexInNote READ indexInNote WRITE setIndexInNote)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::Resource)

#endif // QEVERCLOUD_GENERATED_RESOURCE_H
