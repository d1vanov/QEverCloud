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

#ifndef QEVERCLOUD_GENERATED_LINKEDNOTEBOOK
#define QEVERCLOUD_GENERATED_LINKEDNOTEBOOK

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QHash>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

/**
 * A link in a user's account that refers them to a public or
 * individual shared notebook in another user's account.
 *
 * */
class QEVERCLOUD_EXPORT LinkedNotebook: public Printable
{
    Q_GADGET
public:
    LinkedNotebook();
    LinkedNotebook(const LinkedNotebook & other);
    LinkedNotebook(LinkedNotebook && other) noexcept;
    ~LinkedNotebook() noexcept override;

    LinkedNotebook & operator=(const LinkedNotebook & other);
    LinkedNotebook & operator=(LinkedNotebook && other) noexcept;

    /**
     * @brief locallyModified flag can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocallyModified() const noexcept;
    void setLocallyModified(bool isLocallyModified = true);

    /**
     * @brief localOnly flag can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocalOnly() const noexcept;
    void setLocalOnly(bool isLocalOnly = true);

    /**
     * @brief locallyFavorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * a property between different clients
     */
    [[nodiscard]] bool isLocallyFavorited() const noexcept;
    void setLocallyFavorited(bool isLocallyFavorited = true);

    /**
     * @brief localData property can be used to store any additional
     * data which might be needed to be set for the type object
     * by QEverCloud's client code
     */
    [[nodiscard]] const QHash<QString, QVariant> & localData() const noexcept;
    [[nodiscard]] QHash<QString, QVariant> & mutableLocalData();
    void setLocalData(QHash<QString, QVariant> localData);

    /**
     * The display name of the shared notebook. The link owner can change this.
     */
    [[nodiscard]] const std::optional<QString> & shareName() const noexcept;
    void setShareName(std::optional<QString> shareName);

    /**
     * The username of the user who owns the shared or public notebook.
     */
    [[nodiscard]] const std::optional<QString> & username() const noexcept;
    void setUsername(std::optional<QString> username);

    /**
     * The shard ID of the notebook if the notebook is not public.
     *
     * <dt>uri
     * The identifier of the public notebook.
     */
    [[nodiscard]] const std::optional<QString> & shardId() const noexcept;
    void setShardId(std::optional<QString> shardId);

    /**
     * The globally unique identifier (globalId) of the shared notebook that
     * corresponds to the share key, or the GUID of the Notebook that the linked notebook
     * refers to. This field must be filled in with the SharedNotebook.globalId or
     * Notebook.GUID value when creating new LinkedNotebooks. This field replaces the
     * deprecated "shareKey" field.
     */
    [[nodiscard]] const std::optional<QString> & sharedNotebookGlobalId() const noexcept;
    void setSharedNotebookGlobalId(std::optional<QString> sharedNotebookGlobalId);

    [[nodiscard]] const std::optional<QString> & uri() const noexcept;
    void setUri(std::optional<QString> uri);

    /**
     * The unique identifier of this linked notebook. Will be set whenever
     * a linked notebook is retrieved from the service, but may be null when a client
     * is creating a linked notebook.
     * Length: EDAM_GUID_LEN_MIN - EDAM_GUID_LEN_MAX
     * Regex: EDAM_GUID_REGEX
     */
    [[nodiscard]] const std::optional<Guid> & guid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableGuid();
    void setGuid(std::optional<Guid> guid);

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
     * This field will contain the full URL that clients should use to make
     * NoteStore requests to the server shard that contains that notebook's data.
     * I.e. this is the URL that should be used to create the Thrift HTTP client
     * transport to send messages to the NoteStore service for the account.
     */
    [[nodiscard]] const std::optional<QString> & noteStoreUrl() const noexcept;
    void setNoteStoreUrl(std::optional<QString> noteStoreUrl);

    /**
     * This field will contain the initial part of the URLs that should be used
     * to make requests to Evernote's thin client "web API", which provide
     * optimized operations for clients that aren't capable of manipulating
     * the full contents of accounts via the full Thrift data model. Clients
     * should concatenate the relative path for the various servlets onto the
     * end of this string to construct the full URL, as documented on our
     * developer web site.
     */
    [[nodiscard]] const std::optional<QString> & webApiUrlPrefix() const noexcept;
    void setWebApiUrlPrefix(std::optional<QString> webApiUrlPrefix);

    /**
     * If this is set, then the notebook is visually contained within a stack
     * of notebooks with this name. All notebooks in the same account with the
     * same 'stack' field are considered to be in the same stack.
     * Notebooks with no stack set are "top level" and not contained within a
     * stack. The link owner can change this and this field is for the benefit
     * of the link owner.
     */
    [[nodiscard]] const std::optional<QString> & stack() const noexcept;
    void setStack(std::optional<QString> stack);

    /**
     * If set, this will be the unique identifier for the business that owns
     * the notebook to which the linked notebook refers.
     */
    [[nodiscard]] const std::optional<qint32> & businessId() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableBusinessId();
    void setBusinessId(std::optional<qint32> businessId);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const LinkedNotebook & linkedNotebook);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const LinkedNotebook & linkedNotebook);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const LinkedNotebook & linkedNotebook);

    using LocalData = QHash<QString, QVariant>;

    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(LocalData localData READ localData WRITE setLocalData)
    Q_PROPERTY(std::optional<QString> shareName READ shareName WRITE setShareName)
    Q_PROPERTY(std::optional<QString> username READ username WRITE setUsername)
    Q_PROPERTY(std::optional<QString> shardId READ shardId WRITE setShardId)
    Q_PROPERTY(std::optional<QString> sharedNotebookGlobalId READ sharedNotebookGlobalId WRITE setSharedNotebookGlobalId)
    Q_PROPERTY(std::optional<QString> uri READ uri WRITE setUri)
    Q_PROPERTY(std::optional<Guid> guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<qint32> updateSequenceNum READ updateSequenceNum WRITE setUpdateSequenceNum)
    Q_PROPERTY(std::optional<QString> noteStoreUrl READ noteStoreUrl WRITE setNoteStoreUrl)
    Q_PROPERTY(std::optional<QString> webApiUrlPrefix READ webApiUrlPrefix WRITE setWebApiUrlPrefix)
    Q_PROPERTY(std::optional<QString> stack READ stack WRITE setStack)
    Q_PROPERTY(std::optional<qint32> businessId READ businessId WRITE setBusinessId)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const LinkedNotebook & lhs, const LinkedNotebook & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const LinkedNotebook & lhs, const LinkedNotebook & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_LINKEDNOTEBOOK
