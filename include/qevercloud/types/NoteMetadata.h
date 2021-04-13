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

#ifndef QEVERCLOUD_GENERATED_NOTEMETADATA
#define QEVERCLOUD_GENERATED_NOTEMETADATA

#include <qevercloud/Export.h>

#include "NoteAttributes.h"
#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QHash>
#include <QList>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

/**
 * This structure is used in the set of results returned by the
 * findNotesMetadata function.  It represents the high-level information about
 * a single Note, without some of the larger deep structure.  This allows
 * for the information about a list of Notes to be returned relatively quickly
 * with less marshalling and data transfer to remote clients.
 * Most fields in this structure are identical to the corresponding field in
 * the Note structure, with the exception of:
 *
 * */
class QEVERCLOUD_EXPORT NoteMetadata: public Printable
{
    Q_GADGET
public:
    NoteMetadata();
    NoteMetadata(const NoteMetadata & other);
    NoteMetadata(NoteMetadata && other) noexcept;
    ~NoteMetadata() noexcept override;

    NoteMetadata & operator=(const NoteMetadata & other);
    NoteMetadata & operator=(NoteMetadata && other) noexcept;

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

    [[nodiscard]] const Guid & guid() const noexcept;
    [[nodiscard]] Guid & mutableGuid();
    void setGuid(Guid guid);

    [[nodiscard]] const std::optional<QString> & title() const noexcept;
    void setTitle(std::optional<QString> title);

    [[nodiscard]] const std::optional<qint32> & contentLength() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableContentLength();
    void setContentLength(std::optional<qint32> contentLength);

    [[nodiscard]] const std::optional<Timestamp> & created() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableCreated();
    void setCreated(std::optional<Timestamp> created);

    [[nodiscard]] const std::optional<Timestamp> & updated() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableUpdated();
    void setUpdated(std::optional<Timestamp> updated);

    [[nodiscard]] const std::optional<Timestamp> & deleted() const noexcept;
    [[nodiscard]] std::optional<Timestamp> & mutableDeleted();
    void setDeleted(std::optional<Timestamp> deleted);

    [[nodiscard]] const std::optional<qint32> & updateSequenceNum() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableUpdateSequenceNum();
    void setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);

    [[nodiscard]] const std::optional<QString> & notebookGuid() const noexcept;
    void setNotebookGuid(std::optional<QString> notebookGuid);

    [[nodiscard]] const std::optional<QList<Guid>> & tagGuids() const noexcept;
    [[nodiscard]] std::optional<QList<Guid>> & mutableTagGuids();
    void setTagGuids(std::optional<QList<Guid>> tagGuids);

    [[nodiscard]] const std::optional<NoteAttributes> & attributes() const noexcept;
    [[nodiscard]] std::optional<NoteAttributes> & mutableAttributes();
    void setAttributes(std::optional<NoteAttributes> attributes);

    /**
     * If set, then this will contain the MIME type of the largest Resource
     * (in bytes) within the Note. This may be useful, for example, to choose
     * an appropriate icon or thumbnail to represent the Note.
     */
    [[nodiscard]] const std::optional<QString> & largestResourceMime() const noexcept;
    void setLargestResourceMime(std::optional<QString> largestResourceMime);

    /**
     * If set, this will contain the size of the largest Resource file, in
     * bytes, within the Note. This may be useful, for example, to decide whether
     * to ask the server for a thumbnail to represent the Note.
     */
    [[nodiscard]] const std::optional<qint32> & largestResourceSize() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableLargestResourceSize();
    void setLargestResourceSize(std::optional<qint32> largestResourceSize);

    void print(QTextStream & strm) const override;

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(Guid guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<QString> title READ title WRITE setTitle)
    Q_PROPERTY(std::optional<qint32> contentLength READ contentLength WRITE setContentLength)
    Q_PROPERTY(std::optional<Timestamp> created READ created WRITE setCreated)
    Q_PROPERTY(std::optional<Timestamp> updated READ updated WRITE setUpdated)
    Q_PROPERTY(std::optional<Timestamp> deleted READ deleted WRITE setDeleted)
    Q_PROPERTY(std::optional<qint32> updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(std::optional<QString> notebookGuid READ notebookGuid WRITE setNotebookGuid)
    Q_PROPERTY(std::optional<QList<Guid>> tagGuids READ tagGuids WRITE setTagGuids)
    Q_PROPERTY(std::optional<NoteAttributes> attributes READ attributes WRITE setAttributes)
    Q_PROPERTY(std::optional<QString> largestResourceMime READ largestResourceMime WRITE setLargestResourceMime)
    Q_PROPERTY(std::optional<qint32> largestResourceSize READ largestResourceSize WRITE setLargestResourceSize)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const NoteMetadata & lhs, const NoteMetadata & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const NoteMetadata & lhs, const NoteMetadata & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteMetadata)

#endif // QEVERCLOUD_GENERATED_NOTEMETADATA
