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

#ifndef QEVERCLOUD_GENERATED_TAG_H
#define QEVERCLOUD_GENERATED_TAG_H

#include <qevercloud/Export.h>

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
 * A tag within a user's account is a unique name which may be organized
 * a simple hierarchy.
 **/
class QEVERCLOUD_EXPORT Tag: public Printable
{
    Q_GADGET
public:
    Tag();
    Tag(const Tag & other);
    Tag(Tag && other) noexcept;
    ~Tag() noexcept override;

    Tag & operator=(const Tag & other);
    Tag & operator=(Tag && other) noexcept;

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
     * The unique identifier of this tag. Will be set by the service,
     * so may be omitted by the client when creating the Tag.
     * Length: EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
     * Regex: EDAM_GUID_REGEX
     */
    [[nodiscard]] const std::optional<Guid> & guid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableGuid();
    void setGuid(std::optional<Guid> guid);

    /**
     * A sequence of characters representing the tag's identifier.
     * Case is preserved, but is ignored for comparisons.
     * This means that an account may only have one tag with a given name, via
     * case-insensitive comparison, so an account may not have both "food" and
     * "Food" tags.
     * May not contain a comma (','), and may not begin or end with a space.
     * Length: EDAM_TAG_NAME_LEN_MIN - EDAM_TAG_NAME_LEN_MAX
     * Regex: EDAM_TAG_NAME_REGEX
     */
    [[nodiscard]] const std::optional<QString> & name() const noexcept;
    void setName(std::optional<QString> name);

    /**
     * If this is set, then this is the GUID of the tag that
     * holds this tag within the tag organizational hierarchy. If this is
     * not set, then the tag has no parent and it is a "top level" tag.
     * Cycles are not allowed (e.g. a->parent->parent == a) and will be
     * rejected by the service.
     * Length: EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
     * Regex: EDAM_GUID_REGEX
     */
    [[nodiscard]] const std::optional<Guid> & parentGuid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableParentGuid();
    void setParentGuid(std::optional<Guid> parentGuid);

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
     * Methods below correspond to fields which are NOT set by QEverCloud itself.
     * They exist for convenience of client code and are intended to be called
     * and used by QEverCloud's client code if/when appropriate
     */

    /**
     * Guid of linked notebook which this tag comes from. If
     * this tag belongs to user's own content i.e. doesn't
     * come from any linked notebook, this field would be empty
     */
    [[nodiscard]] const std::optional<QString> & linkedNotebookGuid() const;

    /**
     * Set guid of linked notebook to which this tag belongs
     * or empty string if this tag belongs to user's own content
     */
    void setLinkedNotebookGuid(std::optional<QString> guid);

    /**
     * Local id of a tag which is this tag's parent
     */
[[nodiscard]] QString parentTagLocalId() const;

    /**
     * Set local id of a parent tag to this tag
 */
void setParentTagLocalId(QString parentTagLocalId);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const Tag & other) const noexcept;
    [[nodiscard]] bool operator!=(const Tag & other) const noexcept;

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<Guid> guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<QString> name READ name WRITE setName)
    Q_PROPERTY(std::optional<Guid> parentGuid READ parentGuid WRITE setParentGuid)
    Q_PROPERTY(std::optional<qint32> updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(std::optional<QString> linkedNotebookGuid READ linkedNotebookGuid WRITE setLinkedNotebookGuid)
    Q_PROPERTY(QString parentTagLocalId READ parentTagLocalId WRITE setParentTagLocalId)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::Tag)

#endif // QEVERCLOUD_GENERATED_TAG_H
