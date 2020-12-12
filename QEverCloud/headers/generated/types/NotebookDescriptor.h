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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTOR_H
#define QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTOR_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "TypeAliases.h"
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
    [[nodiscard]] QString localId() const;
    void setLocalId(QString id);

    /**
     * @brief parentLocalId can be used as a local unique identifier
     * of the data item being a parent to this data item.
     *
     * For example, a note is a parent to a resource, a notebook
     * is a parent to a note. So note's localId is a parentLocalId for a
     * resource, notebook's localId is a parentLocalId for a note,
     * tag's localId is a parentLocalId to a child tag.
     *
     * By default the parentLocalId property is empty
     */
    [[nodiscard]] QString parentLocalId() const;
    void setParentLocalId(QString id);

    /**
     * @brief locallyModified flag can be used to keep track which
     * objects have been modified locally and thus need to be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocallyModified() const;
    void setLocallyModified(bool modified = true);

    /**
     * @brief localOnly flag can be used to keep track which
     * data items are meant to be local only and thus never be synchronized
     * with Evernote service
     */
    [[nodiscard]] bool isLocalOnly() const;
    void setLocalOnly(bool localOnly = true);

    /**
     * @brief locallyFavorited property can be used to keep track which
     * data items were favorited in the client. Unfortunately,
     * Evernote has never provided a way to synchronize such
     * a property between different clients
     */
    [[nodiscard]] bool isLocallyFavorited() const;
    void setLocallyFavorited(bool favorited = true);

    /**
    The unique identifier of the notebook.
    */
    [[nodiscard]] const std::optional<Guid> & guid() const noexcept;
    [[nodiscard]] std::optional<Guid> & mutableGuid();
    void setGuid(std::optional<Guid> guid);

    /**
    A sequence of characters representing the name of the
       notebook.
    */
    [[nodiscard]] const std::optional<QString> & notebookDisplayName() const noexcept;
    void setNotebookDisplayName(std::optional<QString> notebookDisplayName);

    /**
    The User.name value of the notebook's "contact".
    */
    [[nodiscard]] const std::optional<QString> & contactName() const noexcept;
    void setContactName(std::optional<QString> contactName);

    /**
    Whether a SharedNotebook record exists between the calling user and this
       notebook.
    */
    [[nodiscard]] const std::optional<bool> & hasSharedNotebook() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableHasSharedNotebook();
    void setHasSharedNotebook(std::optional<bool> hasSharedNotebook);

    /**
    The number of users who have joined this notebook.
    */
    [[nodiscard]] const std::optional<qint32> & joinedUserCount() const noexcept;
    [[nodiscard]] std::optional<qint32> & mutableJoinedUserCount();
    void setJoinedUserCount(std::optional<qint32> joinedUserCount);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NotebookDescriptor & other) const noexcept;
    [[nodiscard]] bool operator!=(const NotebookDescriptor & other) const noexcept;

    Q_PROPERTY(QString localId READ localId WRITE setLocalId)
    Q_PROPERTY(QString parentLocalId READ parentLocalId WRITE setParentLocalId)
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

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NotebookDescriptor)

#endif // QEVERCLOUD_GENERATED_NOTEBOOKDESCRIPTOR_H
