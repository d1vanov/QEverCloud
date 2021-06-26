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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTOR
#define QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTOR

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
 * A structure that describes a notebook or a user's relationship with
 * a notebook. NotebookDescriptor is expected to remain a lighter-weight
 * structure when compared to Notebook.
 * */
class QEVERCLOUD_EXPORT NotebookDescriptor: public Printable
{
    Q_GADGET
public:
    NotebookDescriptor();
    NotebookDescriptor(const NotebookDescriptor & other);
    NotebookDescriptor(NotebookDescriptor && other) noexcept;
    ~NotebookDescriptor() noexcept override;

    NotebookDescriptor & operator=(const NotebookDescriptor & other);
    NotebookDescriptor & operator=(NotebookDescriptor && other) noexcept;

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
     * The unique identifier of the notebook.
     */
    [[nodiscard]] const std::optional<Guid> & guid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableGuid();
    void setGuid(std::optional<Guid> guid);

    /**
     * A sequence of characters representing the name of the
     * notebook.
     */
    [[nodiscard]] const std::optional<QString> & notebookDisplayName() const noexcept;
    void setNotebookDisplayName(std::optional<QString> notebookDisplayName);

    /**
     * The User.name value of the notebook's "contact".
     */
    [[nodiscard]] const std::optional<QString> & contactName() const noexcept;
    void setContactName(std::optional<QString> contactName);

    /**
     * Whether a SharedNotebook record exists between the calling user and this
     * notebook.
     */
    [[nodiscard]] const std::optional<bool> & hasSharedNotebook() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableHasSharedNotebook();
    void setHasSharedNotebook(std::optional<bool> hasSharedNotebook);

    /**
     * The number of users who have joined this notebook.
     */
    [[nodiscard]] const std::optional<qint32> & joinedUserCount() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableJoinedUserCount();
    void setJoinedUserCount(std::optional<qint32> joinedUserCount);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const NotebookDescriptor & notebookDescriptor);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const NotebookDescriptor & notebookDescriptor);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const NotebookDescriptor & notebookDescriptor);

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(bool locallyModified READ isLocallyModified WRITE setLocallyModified)
    Q_PROPERTY(bool localOnly READ isLocalOnly WRITE setLocalOnly)
    Q_PROPERTY(bool favorited READ isLocallyFavorited WRITE setLocallyFavorited)
    Q_PROPERTY(std::optional<Guid> guid READ guid WRITE setGuid)
    Q_PROPERTY(std::optional<QString> notebookDisplayName READ notebookDisplayName WRITE setNotebookDisplayName)
    Q_PROPERTY(std::optional<QString> contactName READ contactName WRITE setContactName)
    Q_PROPERTY(std::optional<bool> hasSharedNotebook READ hasSharedNotebook WRITE setHasSharedNotebook)
    Q_PROPERTY(std::optional<qint32> joinedUserCount READ joinedUserCount WRITE setJoinedUserCount)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const NotebookDescriptor & lhs, const NotebookDescriptor & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const NotebookDescriptor & lhs, const NotebookDescriptor & rhs) noexcept;

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NotebookDescriptor)

#endif // QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTOR
