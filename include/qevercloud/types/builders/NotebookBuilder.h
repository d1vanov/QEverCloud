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

#ifndef QEVERCLOUD_GENERATED_NOTEBOOKBUILDER
#define QEVERCLOUD_GENERATED_NOTEBOOKBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/BusinessNotebook.h>
#include <qevercloud/types/Notebook.h>
#include <qevercloud/types/NotebookRecipientSettings.h>
#include <qevercloud/types/NotebookRestrictions.h>
#include <qevercloud/types/Publishing.h>
#include <qevercloud/types/SharedNotebook.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/types/User.h>
#include <QHash>
#include <QList>
#include <QSharedDataPointer>
#include <QVariant>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NotebookBuilder
{
public:
    NotebookBuilder();

    NotebookBuilder(NotebookBuilder && other) noexcept;

    ~NotebookBuilder() noexcept;

    NotebookBuilder & operator=(NotebookBuilder && other) noexcept;

    NotebookBuilder & setLocalId(QString localId);
    NotebookBuilder & setLocallyModified(bool isLocallyModified);
    NotebookBuilder & setLocalOnly(bool isLocalOnly);
    NotebookBuilder & setLocallyFavorited(bool isLocallyFavorited);
    NotebookBuilder & setLocalData(QHash<QString, QVariant> localData);
    NotebookBuilder & setLinkedNotebookGuid(std::optional<Guid> linkedNotebookGuid);
    NotebookBuilder & setGuid(std::optional<Guid> guid);
    NotebookBuilder & setName(std::optional<QString> name);
    NotebookBuilder & setUpdateSequenceNum(std::optional<qint32> updateSequenceNum);
    NotebookBuilder & setDefaultNotebook(std::optional<bool> defaultNotebook);
    NotebookBuilder & setServiceCreated(std::optional<Timestamp> serviceCreated);
    NotebookBuilder & setServiceUpdated(std::optional<Timestamp> serviceUpdated);
    NotebookBuilder & setPublishing(std::optional<Publishing> publishing);
    NotebookBuilder & setPublished(std::optional<bool> published);
    NotebookBuilder & setStack(std::optional<QString> stack);
    NotebookBuilder & setSharedNotebookIds(std::optional<QList<qint64>> sharedNotebookIds);
    NotebookBuilder & setSharedNotebooks(std::optional<QList<SharedNotebook>> sharedNotebooks);
    NotebookBuilder & setBusinessNotebook(std::optional<BusinessNotebook> businessNotebook);
    NotebookBuilder & setContact(std::optional<User> contact);
    NotebookBuilder & setRestrictions(std::optional<NotebookRestrictions> restrictions);
    NotebookBuilder & setRecipientSettings(std::optional<NotebookRecipientSettings> recipientSettings);

    [[nodiscard]] Notebook build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEBOOKBUILDER
