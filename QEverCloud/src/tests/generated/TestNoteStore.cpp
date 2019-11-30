/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "TestNoteStore.h"
#include "../../Impl.h"
#include "../SocketHelpers.h"
#include "RandomDataGenerators.h"
#include <generated/Servers.h>
#include <generated/Services.h>
#include <QTcpServer>
#include <QtTest/QtTest>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

NoteStoreTester::NoteStoreTester(QObject * parent) :
    QObject(parent)
{}

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetSyncStateTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        SyncState(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetSyncStateTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getSyncStateRequestReady(
        SyncState value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetSyncStateRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT getSyncStateRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getSyncStateRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetFilteredSyncChunkTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        SyncChunk(
            qint32,
            qint32,
            const SyncChunkFilter &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetFilteredSyncChunkTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getFilteredSyncChunkRequestReady(
        SyncChunk value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetFilteredSyncChunkRequestReceived(
        qint32 afterUSN,
        qint32 maxEntries,
        SyncChunkFilter filter,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                afterUSN,
                maxEntries,
                filter,
                ctx);

            Q_EMIT getFilteredSyncChunkRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getFilteredSyncChunkRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetLinkedNotebookSyncStateTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        SyncState(
            const LinkedNotebook &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetLinkedNotebookSyncStateTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getLinkedNotebookSyncStateRequestReady(
        SyncState value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetLinkedNotebookSyncStateRequestReceived(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                linkedNotebook,
                ctx);

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetLinkedNotebookSyncChunkTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        SyncChunk(
            const LinkedNotebook &,
            qint32,
            qint32,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetLinkedNotebookSyncChunkTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getLinkedNotebookSyncChunkRequestReady(
        SyncChunk value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetLinkedNotebookSyncChunkRequestReceived(
        LinkedNotebook linkedNotebook,
        qint32 afterUSN,
        qint32 maxEntries,
        bool fullSyncOnly,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                linkedNotebook,
                afterUSN,
                maxEntries,
                fullSyncOnly,
                ctx);

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreListNotebooksTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<Notebook>(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreListNotebooksTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listNotebooksRequestReady(
        QList<Notebook> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListNotebooksRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT listNotebooksRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listNotebooksRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreListAccessibleBusinessNotebooksTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<Notebook>(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreListAccessibleBusinessNotebooksTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listAccessibleBusinessNotebooksRequestReady(
        QList<Notebook> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListAccessibleBusinessNotebooksRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT listAccessibleBusinessNotebooksRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listAccessibleBusinessNotebooksRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Notebook(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNotebookRequestReady(
        Notebook value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNotebookRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetDefaultNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Notebook(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetDefaultNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getDefaultNotebookRequestReady(
        Notebook value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetDefaultNotebookRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT getDefaultNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getDefaultNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreCreateNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Notebook(
            const Notebook &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreCreateNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void createNotebookRequestReady(
        Notebook value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCreateNotebookRequestReceived(
        Notebook notebook,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                notebook,
                ctx);

            Q_EMIT createNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT createNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUpdateNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            const Notebook &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUpdateNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateNotebookRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateNotebookRequestReceived(
        Notebook notebook,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                notebook,
                ctx);

            Q_EMIT updateNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreExpungeNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreExpungeNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void expungeNotebookRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onExpungeNotebookRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT expungeNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT expungeNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreListTagsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<Tag>(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreListTagsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listTagsRequestReady(
        QList<Tag> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListTagsRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT listTagsRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listTagsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreListTagsByNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<Tag>(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreListTagsByNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listTagsByNotebookRequestReady(
        QList<Tag> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListTagsByNotebookRequestReceived(
        Guid notebookGuid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                notebookGuid,
                ctx);

            Q_EMIT listTagsByNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listTagsByNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetTagTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Tag(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetTagTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getTagRequestReady(
        Tag value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetTagRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getTagRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getTagRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreCreateTagTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Tag(
            const Tag &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreCreateTagTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void createTagRequestReady(
        Tag value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCreateTagRequestReceived(
        Tag tag,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                tag,
                ctx);

            Q_EMIT createTagRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT createTagRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUpdateTagTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            const Tag &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUpdateTagTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateTagRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateTagRequestReceived(
        Tag tag,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                tag,
                ctx);

            Q_EMIT updateTagRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateTagRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUntagAllTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUntagAllTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void untagAllRequestReady(
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUntagAllRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                guid,
                ctx);

            Q_EMIT untagAllRequestReady(
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT untagAllRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreExpungeTagTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreExpungeTagTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void expungeTagRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onExpungeTagRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT expungeTagRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT expungeTagRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreListSearchesTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<SavedSearch>(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreListSearchesTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listSearchesRequestReady(
        QList<SavedSearch> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListSearchesRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT listSearchesRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listSearchesRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetSearchTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        SavedSearch(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetSearchTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getSearchRequestReady(
        SavedSearch value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetSearchRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getSearchRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getSearchRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreCreateSearchTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        SavedSearch(
            const SavedSearch &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreCreateSearchTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void createSearchRequestReady(
        SavedSearch value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCreateSearchRequestReceived(
        SavedSearch search,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                search,
                ctx);

            Q_EMIT createSearchRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT createSearchRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUpdateSearchTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            const SavedSearch &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUpdateSearchTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateSearchRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateSearchRequestReceived(
        SavedSearch search,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                search,
                ctx);

            Q_EMIT updateSearchRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateSearchRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreExpungeSearchTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreExpungeSearchTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void expungeSearchRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onExpungeSearchRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT expungeSearchRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT expungeSearchRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreFindNoteOffsetTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            const NoteFilter &,
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreFindNoteOffsetTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void findNoteOffsetRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onFindNoteOffsetRequestReceived(
        NoteFilter filter,
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                filter,
                guid,
                ctx);

            Q_EMIT findNoteOffsetRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT findNoteOffsetRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreFindNotesMetadataTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        NotesMetadataList(
            const NoteFilter &,
            qint32,
            qint32,
            const NotesMetadataResultSpec &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreFindNotesMetadataTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void findNotesMetadataRequestReady(
        NotesMetadataList value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onFindNotesMetadataRequestReceived(
        NoteFilter filter,
        qint32 offset,
        qint32 maxNotes,
        NotesMetadataResultSpec resultSpec,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                filter,
                offset,
                maxNotes,
                resultSpec,
                ctx);

            Q_EMIT findNotesMetadataRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT findNotesMetadataRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreFindNoteCountsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        NoteCollectionCounts(
            const NoteFilter &,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreFindNoteCountsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void findNoteCountsRequestReady(
        NoteCollectionCounts value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onFindNoteCountsRequestReceived(
        NoteFilter filter,
        bool withTrash,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                filter,
                withTrash,
                ctx);

            Q_EMIT findNoteCountsRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT findNoteCountsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNoteWithResultSpecTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Note(
            Guid,
            const NoteResultSpec &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNoteWithResultSpecTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNoteWithResultSpecRequestReady(
        Note value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNoteWithResultSpecRequestReceived(
        Guid guid,
        NoteResultSpec resultSpec,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                resultSpec,
                ctx);

            Q_EMIT getNoteWithResultSpecRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNoteWithResultSpecRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Note(
            Guid,
            bool,
            bool,
            bool,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNoteRequestReady(
        Note value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNoteRequestReceived(
        Guid guid,
        bool withContent,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                withContent,
                withResourcesData,
                withResourcesRecognition,
                withResourcesAlternateData,
                ctx);

            Q_EMIT getNoteRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNoteRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNoteApplicationDataTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        LazyMap(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNoteApplicationDataTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNoteApplicationDataRequestReady(
        LazyMap value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNoteApplicationDataRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getNoteApplicationDataRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNoteApplicationDataRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNoteApplicationDataEntryTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QString(
            Guid,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNoteApplicationDataEntryTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNoteApplicationDataEntryRequestReady(
        QString value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNoteApplicationDataEntryRequestReceived(
        Guid guid,
        QString key,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                key,
                ctx);

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNoteApplicationDataEntryRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreSetNoteApplicationDataEntryTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            QString,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreSetNoteApplicationDataEntryTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void setNoteApplicationDataEntryRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onSetNoteApplicationDataEntryRequestReceived(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                key,
                value,
                ctx);

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT setNoteApplicationDataEntryRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUnsetNoteApplicationDataEntryTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUnsetNoteApplicationDataEntryTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void unsetNoteApplicationDataEntryRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUnsetNoteApplicationDataEntryRequestReceived(
        Guid guid,
        QString key,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                key,
                ctx);

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNoteContentTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QString(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNoteContentTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNoteContentRequestReady(
        QString value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNoteContentRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getNoteContentRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNoteContentRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNoteSearchTextTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QString(
            Guid,
            bool,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNoteSearchTextTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNoteSearchTextRequestReady(
        QString value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNoteSearchTextRequestReceived(
        Guid guid,
        bool noteOnly,
        bool tokenizeForIndexing,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                noteOnly,
                tokenizeForIndexing,
                ctx);

            Q_EMIT getNoteSearchTextRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNoteSearchTextRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceSearchTextTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QString(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceSearchTextTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceSearchTextRequestReady(
        QString value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceSearchTextRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getResourceSearchTextRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceSearchTextRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNoteTagNamesTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QStringList(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNoteTagNamesTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNoteTagNamesRequestReady(
        QStringList value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNoteTagNamesRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getNoteTagNamesRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNoteTagNamesRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreCreateNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Note(
            const Note &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreCreateNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void createNoteRequestReady(
        Note value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCreateNoteRequestReceived(
        Note note,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                note,
                ctx);

            Q_EMIT createNoteRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT createNoteRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUpdateNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Note(
            const Note &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUpdateNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateNoteRequestReady(
        Note value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateNoteRequestReceived(
        Note note,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                note,
                ctx);

            Q_EMIT updateNoteRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateNoteRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreDeleteNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreDeleteNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void deleteNoteRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onDeleteNoteRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT deleteNoteRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT deleteNoteRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreExpungeNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreExpungeNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void expungeNoteRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onExpungeNoteRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT expungeNoteRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT expungeNoteRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreCopyNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Note(
            Guid,
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreCopyNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void copyNoteRequestReady(
        Note value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCopyNoteRequestReceived(
        Guid noteGuid,
        Guid toNotebookGuid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                noteGuid,
                toNotebookGuid,
                ctx);

            Q_EMIT copyNoteRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT copyNoteRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreListNoteVersionsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<NoteVersionId>(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreListNoteVersionsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listNoteVersionsRequestReady(
        QList<NoteVersionId> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListNoteVersionsRequestReceived(
        Guid noteGuid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                noteGuid,
                ctx);

            Q_EMIT listNoteVersionsRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listNoteVersionsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNoteVersionTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Note(
            Guid,
            qint32,
            bool,
            bool,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNoteVersionTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNoteVersionRequestReady(
        Note value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNoteVersionRequestReceived(
        Guid noteGuid,
        qint32 updateSequenceNum,
        bool withResourcesData,
        bool withResourcesRecognition,
        bool withResourcesAlternateData,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                noteGuid,
                updateSequenceNum,
                withResourcesData,
                withResourcesRecognition,
                withResourcesAlternateData,
                ctx);

            Q_EMIT getNoteVersionRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNoteVersionRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Resource(
            Guid,
            bool,
            bool,
            bool,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceRequestReady(
        Resource value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceRequestReceived(
        Guid guid,
        bool withData,
        bool withRecognition,
        bool withAttributes,
        bool withAlternateData,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                withData,
                withRecognition,
                withAttributes,
                withAlternateData,
                ctx);

            Q_EMIT getResourceRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceApplicationDataTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        LazyMap(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceApplicationDataTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceApplicationDataRequestReady(
        LazyMap value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceApplicationDataRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getResourceApplicationDataRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceApplicationDataRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceApplicationDataEntryTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QString(
            Guid,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceApplicationDataEntryTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceApplicationDataEntryRequestReady(
        QString value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceApplicationDataEntryRequestReceived(
        Guid guid,
        QString key,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                key,
                ctx);

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceApplicationDataEntryRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreSetResourceApplicationDataEntryTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            QString,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreSetResourceApplicationDataEntryTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void setResourceApplicationDataEntryRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onSetResourceApplicationDataEntryRequestReceived(
        Guid guid,
        QString key,
        QString value,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                key,
                value,
                ctx);

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT setResourceApplicationDataEntryRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUnsetResourceApplicationDataEntryTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUnsetResourceApplicationDataEntryTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void unsetResourceApplicationDataEntryRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUnsetResourceApplicationDataEntryRequestReceived(
        Guid guid,
        QString key,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                key,
                ctx);

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUpdateResourceTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            const Resource &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUpdateResourceTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateResourceRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateResourceRequestReceived(
        Resource resource,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                resource,
                ctx);

            Q_EMIT updateResourceRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateResourceRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceDataTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QByteArray(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceDataTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceDataRequestReady(
        QByteArray value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceDataRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getResourceDataRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceDataRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceByHashTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Resource(
            Guid,
            QByteArray,
            bool,
            bool,
            bool,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceByHashTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceByHashRequestReady(
        Resource value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceByHashRequestReceived(
        Guid noteGuid,
        QByteArray contentHash,
        bool withData,
        bool withRecognition,
        bool withAlternateData,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                noteGuid,
                contentHash,
                withData,
                withRecognition,
                withAlternateData,
                ctx);

            Q_EMIT getResourceByHashRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceByHashRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceRecognitionTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QByteArray(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceRecognitionTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceRecognitionRequestReady(
        QByteArray value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceRecognitionRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getResourceRecognitionRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceRecognitionRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceAlternateDataTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QByteArray(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceAlternateDataTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceAlternateDataRequestReady(
        QByteArray value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceAlternateDataRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getResourceAlternateDataRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceAlternateDataRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetResourceAttributesTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        ResourceAttributes(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetResourceAttributesTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getResourceAttributesRequestReady(
        ResourceAttributes value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetResourceAttributesRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT getResourceAttributesRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getResourceAttributesRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetPublicNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Notebook(
            UserID,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetPublicNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getPublicNotebookRequestReady(
        Notebook value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetPublicNotebookRequestReceived(
        UserID userId,
        QString publicUri,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                userId,
                publicUri,
                ctx);

            Q_EMIT getPublicNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getPublicNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreShareNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        SharedNotebook(
            const SharedNotebook &,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreShareNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void shareNotebookRequestReady(
        SharedNotebook value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onShareNotebookRequestReceived(
        SharedNotebook sharedNotebook,
        QString message,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                sharedNotebook,
                message,
                ctx);

            Q_EMIT shareNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT shareNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreCreateOrUpdateNotebookSharesTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        CreateOrUpdateNotebookSharesResult(
            const NotebookShareTemplate &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreCreateOrUpdateNotebookSharesTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void createOrUpdateNotebookSharesRequestReady(
        CreateOrUpdateNotebookSharesResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCreateOrUpdateNotebookSharesRequestReceived(
        NotebookShareTemplate shareTemplate,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                shareTemplate,
                ctx);

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUpdateSharedNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            const SharedNotebook &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUpdateSharedNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateSharedNotebookRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateSharedNotebookRequestReceived(
        SharedNotebook sharedNotebook,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                sharedNotebook,
                ctx);

            Q_EMIT updateSharedNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateSharedNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreSetNotebookRecipientSettingsTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        Notebook(
            QString,
            const NotebookRecipientSettings &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreSetNotebookRecipientSettingsTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void setNotebookRecipientSettingsRequestReady(
        Notebook value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onSetNotebookRecipientSettingsRequestReceived(
        QString notebookGuid,
        NotebookRecipientSettings recipientSettings,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                notebookGuid,
                recipientSettings,
                ctx);

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT setNotebookRecipientSettingsRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreListSharedNotebooksTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<SharedNotebook>(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreListSharedNotebooksTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listSharedNotebooksRequestReady(
        QList<SharedNotebook> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListSharedNotebooksRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT listSharedNotebooksRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listSharedNotebooksRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreCreateLinkedNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        LinkedNotebook(
            const LinkedNotebook &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreCreateLinkedNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void createLinkedNotebookRequestReady(
        LinkedNotebook value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onCreateLinkedNotebookRequestReceived(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                linkedNotebook,
                ctx);

            Q_EMIT createLinkedNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT createLinkedNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUpdateLinkedNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            const LinkedNotebook &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUpdateLinkedNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateLinkedNotebookRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateLinkedNotebookRequestReceived(
        LinkedNotebook linkedNotebook,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                linkedNotebook,
                ctx);

            Q_EMIT updateLinkedNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateLinkedNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreListLinkedNotebooksTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QList<LinkedNotebook>(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreListLinkedNotebooksTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void listLinkedNotebooksRequestReady(
        QList<LinkedNotebook> value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onListLinkedNotebooksRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT listLinkedNotebooksRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT listLinkedNotebooksRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreExpungeLinkedNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        qint32(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreExpungeLinkedNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void expungeLinkedNotebookRequestReady(
        qint32 value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onExpungeLinkedNotebookRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT expungeLinkedNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT expungeLinkedNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreAuthenticateToSharedNotebookTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AuthenticationResult(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreAuthenticateToSharedNotebookTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void authenticateToSharedNotebookRequestReady(
        AuthenticationResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onAuthenticateToSharedNotebookRequestReceived(
        QString shareKeyOrGlobalId,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                shareKeyOrGlobalId,
                ctx);

            Q_EMIT authenticateToSharedNotebookRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT authenticateToSharedNotebookRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetSharedNotebookByAuthTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        SharedNotebook(
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetSharedNotebookByAuthTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getSharedNotebookByAuthRequestReady(
        SharedNotebook value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetSharedNotebookByAuthRequestReceived(
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                ctx);

            Q_EMIT getSharedNotebookByAuthRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getSharedNotebookByAuthRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreEmailNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            const NoteEmailParameters &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreEmailNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void emailNoteRequestReady(
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onEmailNoteRequestReceived(
        NoteEmailParameters parameters,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                parameters,
                ctx);

            Q_EMIT emailNoteRequestReady(
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT emailNoteRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreShareNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        QString(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreShareNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void shareNoteRequestReady(
        QString value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onShareNoteRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                ctx);

            Q_EMIT shareNoteRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT shareNoteRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreStopSharingNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        void(
            Guid,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreStopSharingNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void stopSharingNoteRequestReady(
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onStopSharingNoteRequestReceived(
        Guid guid,
        IRequestContextPtr ctx)
    {
        try
        {
            m_executor(
                guid,
                ctx);

            Q_EMIT stopSharingNoteRequestReady(
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT stopSharingNoteRequestReady(
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreAuthenticateToSharedNoteTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        AuthenticationResult(
            QString,
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreAuthenticateToSharedNoteTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void authenticateToSharedNoteRequestReady(
        AuthenticationResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onAuthenticateToSharedNoteRequestReceived(
        QString guid,
        QString noteKey,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                guid,
                noteKey,
                ctx);

            Q_EMIT authenticateToSharedNoteRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT authenticateToSharedNoteRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreFindRelatedTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        RelatedResult(
            const RelatedQuery &,
            const RelatedResultSpec &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreFindRelatedTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void findRelatedRequestReady(
        RelatedResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onFindRelatedRequestReceived(
        RelatedQuery query,
        RelatedResultSpec resultSpec,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                query,
                resultSpec,
                ctx);

            Q_EMIT findRelatedRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT findRelatedRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreUpdateNoteIfUsnMatchesTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        UpdateNoteIfUsnMatchesResult(
            const Note &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreUpdateNoteIfUsnMatchesTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void updateNoteIfUsnMatchesRequestReady(
        UpdateNoteIfUsnMatchesResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onUpdateNoteIfUsnMatchesRequestReceived(
        Note note,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                note,
                ctx);

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreManageNotebookSharesTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        ManageNotebookSharesResult(
            const ManageNotebookSharesParameters &,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreManageNotebookSharesTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void manageNotebookSharesRequestReady(
        ManageNotebookSharesResult value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onManageNotebookSharesRequestReceived(
        ManageNotebookSharesParameters parameters,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                parameters,
                ctx);

            Q_EMIT manageNotebookSharesRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT manageNotebookSharesRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

class NoteStoreGetNotebookSharesTesterHelper: public QObject
{
    Q_OBJECT
public:
    using Executor = std::function<
        ShareRelationships(
            QString,
            IRequestContextPtr ctx)>;

public:
    explicit NoteStoreGetNotebookSharesTesterHelper(
            Executor executor,
            QObject * parent = nullptr) :
        QObject(parent),
        m_executor(std::move(executor))
    {}

Q_SIGNALS:
    void getNotebookSharesRequestReady(
        ShareRelationships value,
        QSharedPointer<EverCloudExceptionData> exceptionData);

public Q_SLOTS:
    void onGetNotebookSharesRequestReceived(
        QString notebookGuid,
        IRequestContextPtr ctx)
    {
        try
        {
            auto v = m_executor(
                notebookGuid,
                ctx);

            Q_EMIT getNotebookSharesRequestReady(
                v,
                QSharedPointer<EverCloudExceptionData>());
        }
        catch(const EverCloudException & e)
        {
            Q_EMIT getNotebookSharesRequestReady(
                {},
                e.exceptionData());
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetSyncState()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    SyncState response = generateRandomSyncState();

    NoteStoreGetSyncStateTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> SyncState
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSyncStateRequest,
        &helper,
        &NoteStoreGetSyncStateTesterHelper::onGetSyncStateRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSyncStateTesterHelper::getSyncStateRequestReady,
        &server,
        &NoteStoreServer::onGetSyncStateRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSyncStateRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    SyncState res = noteStore->getSyncState(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetSyncState()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_MANY;
    userException.parameter = generateRandomString();

    NoteStoreGetSyncStateTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> SyncState
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSyncStateRequest,
        &helper,
        &NoteStoreGetSyncStateTesterHelper::onGetSyncStateRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSyncStateTesterHelper::getSyncStateRequestReady,
        &server,
        &NoteStoreServer::onGetSyncStateRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSyncStateRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncState res = noteStore->getSyncState(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetSyncState()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INTERNAL_ERROR;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetSyncStateTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> SyncState
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSyncStateRequest,
        &helper,
        &NoteStoreGetSyncStateTesterHelper::onGetSyncStateRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSyncStateTesterHelper::getSyncStateRequestReady,
        &server,
        &NoteStoreServer::onGetSyncStateRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSyncStateRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncState res = noteStore->getSyncState(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetFilteredSyncChunk()
{
    qint32 afterUSN = generateRandomInt32();
    qint32 maxEntries = generateRandomInt32();
    SyncChunkFilter filter = generateRandomSyncChunkFilter();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    SyncChunk response = generateRandomSyncChunk();

    NoteStoreGetFilteredSyncChunkTesterHelper helper(
        [&] (qint32 afterUSNParam,
             qint32 maxEntriesParam,
             const SyncChunkFilter & filterParam,
             IRequestContextPtr ctxParam) -> SyncChunk
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(afterUSN == afterUSNParam);
            Q_ASSERT(maxEntries == maxEntriesParam);
            Q_ASSERT(filter == filterParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getFilteredSyncChunkRequest,
        &helper,
        &NoteStoreGetFilteredSyncChunkTesterHelper::onGetFilteredSyncChunkRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetFilteredSyncChunkTesterHelper::getFilteredSyncChunkRequestReady,
        &server,
        &NoteStoreServer::onGetFilteredSyncChunkRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getFilteredSyncChunkRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    SyncChunk res = noteStore->getFilteredSyncChunk(
        afterUSN,
        maxEntries,
        filter,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetFilteredSyncChunk()
{
    qint32 afterUSN = generateRandomInt32();
    qint32 maxEntries = generateRandomInt32();
    SyncChunkFilter filter = generateRandomSyncChunkFilter();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreGetFilteredSyncChunkTesterHelper helper(
        [&] (qint32 afterUSNParam,
             qint32 maxEntriesParam,
             const SyncChunkFilter & filterParam,
             IRequestContextPtr ctxParam) -> SyncChunk
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(afterUSN == afterUSNParam);
            Q_ASSERT(maxEntries == maxEntriesParam);
            Q_ASSERT(filter == filterParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getFilteredSyncChunkRequest,
        &helper,
        &NoteStoreGetFilteredSyncChunkTesterHelper::onGetFilteredSyncChunkRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetFilteredSyncChunkTesterHelper::getFilteredSyncChunkRequestReady,
        &server,
        &NoteStoreServer::onGetFilteredSyncChunkRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getFilteredSyncChunkRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncChunk res = noteStore->getFilteredSyncChunk(
            afterUSN,
            maxEntries,
            filter,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetFilteredSyncChunk()
{
    qint32 afterUSN = generateRandomInt32();
    qint32 maxEntries = generateRandomInt32();
    SyncChunkFilter filter = generateRandomSyncChunkFilter();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::USER_ALREADY_ASSOCIATED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetFilteredSyncChunkTesterHelper helper(
        [&] (qint32 afterUSNParam,
             qint32 maxEntriesParam,
             const SyncChunkFilter & filterParam,
             IRequestContextPtr ctxParam) -> SyncChunk
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(afterUSN == afterUSNParam);
            Q_ASSERT(maxEntries == maxEntriesParam);
            Q_ASSERT(filter == filterParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getFilteredSyncChunkRequest,
        &helper,
        &NoteStoreGetFilteredSyncChunkTesterHelper::onGetFilteredSyncChunkRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetFilteredSyncChunkTesterHelper::getFilteredSyncChunkRequestReady,
        &server,
        &NoteStoreServer::onGetFilteredSyncChunkRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getFilteredSyncChunkRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncChunk res = noteStore->getFilteredSyncChunk(
            afterUSN,
            maxEntries,
            filter,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetLinkedNotebookSyncState()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    SyncState response = generateRandomSyncState();

    NoteStoreGetLinkedNotebookSyncStateTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> SyncState
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncStateRequest,
        &helper,
        &NoteStoreGetLinkedNotebookSyncStateTesterHelper::onGetLinkedNotebookSyncStateRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetLinkedNotebookSyncStateTesterHelper::getLinkedNotebookSyncStateRequestReady,
        &server,
        &NoteStoreServer::onGetLinkedNotebookSyncStateRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncStateRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    SyncState res = noteStore->getLinkedNotebookSyncState(
        linkedNotebook,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetLinkedNotebookSyncState()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INTERNAL_ERROR;
    userException.parameter = generateRandomString();

    NoteStoreGetLinkedNotebookSyncStateTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> SyncState
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncStateRequest,
        &helper,
        &NoteStoreGetLinkedNotebookSyncStateTesterHelper::onGetLinkedNotebookSyncStateRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetLinkedNotebookSyncStateTesterHelper::getLinkedNotebookSyncStateRequestReady,
        &server,
        &NoteStoreServer::onGetLinkedNotebookSyncStateRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncStateRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncState res = noteStore->getLinkedNotebookSyncState(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetLinkedNotebookSyncState()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LEN_TOO_LONG;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetLinkedNotebookSyncStateTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> SyncState
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncStateRequest,
        &helper,
        &NoteStoreGetLinkedNotebookSyncStateTesterHelper::onGetLinkedNotebookSyncStateRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetLinkedNotebookSyncStateTesterHelper::getLinkedNotebookSyncStateRequestReady,
        &server,
        &NoteStoreServer::onGetLinkedNotebookSyncStateRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncStateRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncState res = noteStore->getLinkedNotebookSyncState(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetLinkedNotebookSyncState()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetLinkedNotebookSyncStateTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> SyncState
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncStateRequest,
        &helper,
        &NoteStoreGetLinkedNotebookSyncStateTesterHelper::onGetLinkedNotebookSyncStateRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetLinkedNotebookSyncStateTesterHelper::getLinkedNotebookSyncStateRequestReady,
        &server,
        &NoteStoreServer::onGetLinkedNotebookSyncStateRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncStateRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncState res = noteStore->getLinkedNotebookSyncState(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetLinkedNotebookSyncChunk()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    qint32 afterUSN = generateRandomInt32();
    qint32 maxEntries = generateRandomInt32();
    bool fullSyncOnly = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    SyncChunk response = generateRandomSyncChunk();

    NoteStoreGetLinkedNotebookSyncChunkTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             qint32 afterUSNParam,
             qint32 maxEntriesParam,
             bool fullSyncOnlyParam,
             IRequestContextPtr ctxParam) -> SyncChunk
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            Q_ASSERT(afterUSN == afterUSNParam);
            Q_ASSERT(maxEntries == maxEntriesParam);
            Q_ASSERT(fullSyncOnly == fullSyncOnlyParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncChunkRequest,
        &helper,
        &NoteStoreGetLinkedNotebookSyncChunkTesterHelper::onGetLinkedNotebookSyncChunkRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetLinkedNotebookSyncChunkTesterHelper::getLinkedNotebookSyncChunkRequestReady,
        &server,
        &NoteStoreServer::onGetLinkedNotebookSyncChunkRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncChunkRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    SyncChunk res = noteStore->getLinkedNotebookSyncChunk(
        linkedNotebook,
        afterUSN,
        maxEntries,
        fullSyncOnly,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetLinkedNotebookSyncChunk()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    qint32 afterUSN = generateRandomInt32();
    qint32 maxEntries = generateRandomInt32();
    bool fullSyncOnly = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::BAD_DATA_FORMAT;
    userException.parameter = generateRandomString();

    NoteStoreGetLinkedNotebookSyncChunkTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             qint32 afterUSNParam,
             qint32 maxEntriesParam,
             bool fullSyncOnlyParam,
             IRequestContextPtr ctxParam) -> SyncChunk
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            Q_ASSERT(afterUSN == afterUSNParam);
            Q_ASSERT(maxEntries == maxEntriesParam);
            Q_ASSERT(fullSyncOnly == fullSyncOnlyParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncChunkRequest,
        &helper,
        &NoteStoreGetLinkedNotebookSyncChunkTesterHelper::onGetLinkedNotebookSyncChunkRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetLinkedNotebookSyncChunkTesterHelper::getLinkedNotebookSyncChunkRequestReady,
        &server,
        &NoteStoreServer::onGetLinkedNotebookSyncChunkRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncChunkRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncChunk res = noteStore->getLinkedNotebookSyncChunk(
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetLinkedNotebookSyncChunk()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    qint32 afterUSN = generateRandomInt32();
    qint32 maxEntries = generateRandomInt32();
    bool fullSyncOnly = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::AUTH_EXPIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetLinkedNotebookSyncChunkTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             qint32 afterUSNParam,
             qint32 maxEntriesParam,
             bool fullSyncOnlyParam,
             IRequestContextPtr ctxParam) -> SyncChunk
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            Q_ASSERT(afterUSN == afterUSNParam);
            Q_ASSERT(maxEntries == maxEntriesParam);
            Q_ASSERT(fullSyncOnly == fullSyncOnlyParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncChunkRequest,
        &helper,
        &NoteStoreGetLinkedNotebookSyncChunkTesterHelper::onGetLinkedNotebookSyncChunkRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetLinkedNotebookSyncChunkTesterHelper::getLinkedNotebookSyncChunkRequestReady,
        &server,
        &NoteStoreServer::onGetLinkedNotebookSyncChunkRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncChunkRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncChunk res = noteStore->getLinkedNotebookSyncChunk(
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetLinkedNotebookSyncChunk()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    qint32 afterUSN = generateRandomInt32();
    qint32 maxEntries = generateRandomInt32();
    bool fullSyncOnly = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetLinkedNotebookSyncChunkTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             qint32 afterUSNParam,
             qint32 maxEntriesParam,
             bool fullSyncOnlyParam,
             IRequestContextPtr ctxParam) -> SyncChunk
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            Q_ASSERT(afterUSN == afterUSNParam);
            Q_ASSERT(maxEntries == maxEntriesParam);
            Q_ASSERT(fullSyncOnly == fullSyncOnlyParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncChunkRequest,
        &helper,
        &NoteStoreGetLinkedNotebookSyncChunkTesterHelper::onGetLinkedNotebookSyncChunkRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetLinkedNotebookSyncChunkTesterHelper::getLinkedNotebookSyncChunkRequestReady,
        &server,
        &NoteStoreServer::onGetLinkedNotebookSyncChunkRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getLinkedNotebookSyncChunkRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SyncChunk res = noteStore->getLinkedNotebookSyncChunk(
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<Notebook> response;
    response << generateRandomNotebook();
    response << generateRandomNotebook();
    response << generateRandomNotebook();

    NoteStoreListNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Notebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listNotebooksRequest,
        &helper,
        &NoteStoreListNotebooksTesterHelper::onListNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListNotebooksTesterHelper::listNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QList<Notebook> res = noteStore->listNotebooks(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInListNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::BAD_DATA_FORMAT;
    userException.parameter = generateRandomString();

    NoteStoreListNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Notebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listNotebooksRequest,
        &helper,
        &NoteStoreListNotebooksTesterHelper::onListNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListNotebooksTesterHelper::listNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Notebook> res = noteStore->listNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInListNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreListNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Notebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listNotebooksRequest,
        &helper,
        &NoteStoreListNotebooksTesterHelper::onListNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListNotebooksTesterHelper::listNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Notebook> res = noteStore->listNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListAccessibleBusinessNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<Notebook> response;
    response << generateRandomNotebook();
    response << generateRandomNotebook();
    response << generateRandomNotebook();

    NoteStoreListAccessibleBusinessNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Notebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listAccessibleBusinessNotebooksRequest,
        &helper,
        &NoteStoreListAccessibleBusinessNotebooksTesterHelper::onListAccessibleBusinessNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListAccessibleBusinessNotebooksTesterHelper::listAccessibleBusinessNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListAccessibleBusinessNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listAccessibleBusinessNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QList<Notebook> res = noteStore->listAccessibleBusinessNotebooks(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInListAccessibleBusinessNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_AUTH;
    userException.parameter = generateRandomString();

    NoteStoreListAccessibleBusinessNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Notebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listAccessibleBusinessNotebooksRequest,
        &helper,
        &NoteStoreListAccessibleBusinessNotebooksTesterHelper::onListAccessibleBusinessNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListAccessibleBusinessNotebooksTesterHelper::listAccessibleBusinessNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListAccessibleBusinessNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listAccessibleBusinessNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Notebook> res = noteStore->listAccessibleBusinessNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInListAccessibleBusinessNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreListAccessibleBusinessNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Notebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listAccessibleBusinessNotebooksRequest,
        &helper,
        &NoteStoreListAccessibleBusinessNotebooksTesterHelper::onListAccessibleBusinessNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListAccessibleBusinessNotebooksTesterHelper::listAccessibleBusinessNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListAccessibleBusinessNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listAccessibleBusinessNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Notebook> res = noteStore->listAccessibleBusinessNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Notebook response = generateRandomNotebook();

    NoteStoreGetNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookRequest,
        &helper,
        &NoteStoreGetNotebookTesterHelper::onGetNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNotebookTesterHelper::getNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Notebook res = noteStore->getNotebook(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_NOT_ASSOCIATED;
    userException.parameter = generateRandomString();

    NoteStoreGetNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookRequest,
        &helper,
        &NoteStoreGetNotebookTesterHelper::onGetNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNotebookTesterHelper::getNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->getNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::ACCOUNT_CLEAR;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookRequest,
        &helper,
        &NoteStoreGetNotebookTesterHelper::onGetNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNotebookTesterHelper::getNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->getNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookRequest,
        &helper,
        &NoteStoreGetNotebookTesterHelper::onGetNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNotebookTesterHelper::getNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->getNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetDefaultNotebook()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Notebook response = generateRandomNotebook();

    NoteStoreGetDefaultNotebookTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getDefaultNotebookRequest,
        &helper,
        &NoteStoreGetDefaultNotebookTesterHelper::onGetDefaultNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetDefaultNotebookTesterHelper::getDefaultNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetDefaultNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getDefaultNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Notebook res = noteStore->getDefaultNotebook(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetDefaultNotebook()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LEN_TOO_LONG;
    userException.parameter = generateRandomString();

    NoteStoreGetDefaultNotebookTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getDefaultNotebookRequest,
        &helper,
        &NoteStoreGetDefaultNotebookTesterHelper::onGetDefaultNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetDefaultNotebookTesterHelper::getDefaultNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetDefaultNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getDefaultNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->getDefaultNotebook(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetDefaultNotebook()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::ENML_VALIDATION;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetDefaultNotebookTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getDefaultNotebookRequest,
        &helper,
        &NoteStoreGetDefaultNotebookTesterHelper::onGetDefaultNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetDefaultNotebookTesterHelper::getDefaultNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetDefaultNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getDefaultNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->getDefaultNotebook(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateNotebook()
{
    Notebook notebook = generateRandomNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Notebook response = generateRandomNotebook();

    NoteStoreCreateNotebookTesterHelper helper(
        [&] (const Notebook & notebookParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebook == notebookParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createNotebookRequest,
        &helper,
        &NoteStoreCreateNotebookTesterHelper::onCreateNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateNotebookTesterHelper::createNotebookRequestReady,
        &server,
        &NoteStoreServer::onCreateNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Notebook res = noteStore->createNotebook(
        notebook,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInCreateNotebook()
{
    Notebook notebook = generateRandomNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_ALREADY_ASSOCIATED;
    userException.parameter = generateRandomString();

    NoteStoreCreateNotebookTesterHelper helper(
        [&] (const Notebook & notebookParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebook == notebookParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createNotebookRequest,
        &helper,
        &NoteStoreCreateNotebookTesterHelper::onCreateNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateNotebookTesterHelper::createNotebookRequestReady,
        &server,
        &NoteStoreServer::onCreateNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->createNotebook(
            notebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInCreateNotebook()
{
    Notebook notebook = generateRandomNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::SHARD_UNAVAILABLE;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreCreateNotebookTesterHelper helper(
        [&] (const Notebook & notebookParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebook == notebookParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createNotebookRequest,
        &helper,
        &NoteStoreCreateNotebookTesterHelper::onCreateNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateNotebookTesterHelper::createNotebookRequestReady,
        &server,
        &NoteStoreServer::onCreateNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->createNotebook(
            notebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInCreateNotebook()
{
    Notebook notebook = generateRandomNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreCreateNotebookTesterHelper helper(
        [&] (const Notebook & notebookParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebook == notebookParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createNotebookRequest,
        &helper,
        &NoteStoreCreateNotebookTesterHelper::onCreateNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateNotebookTesterHelper::createNotebookRequestReady,
        &server,
        &NoteStoreServer::onCreateNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->createNotebook(
            notebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateNotebook()
{
    Notebook notebook = generateRandomNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreUpdateNotebookTesterHelper helper(
        [&] (const Notebook & notebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebook == notebookParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNotebookRequest,
        &helper,
        &NoteStoreUpdateNotebookTesterHelper::onUpdateNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNotebookTesterHelper::updateNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->updateNotebook(
        notebook,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUpdateNotebook()
{
    Notebook notebook = generateRandomNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_MANY;
    userException.parameter = generateRandomString();

    NoteStoreUpdateNotebookTesterHelper helper(
        [&] (const Notebook & notebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebook == notebookParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNotebookRequest,
        &helper,
        &NoteStoreUpdateNotebookTesterHelper::onUpdateNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNotebookTesterHelper::updateNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateNotebook(
            notebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUpdateNotebook()
{
    Notebook notebook = generateRandomNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INVALID_AUTH;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUpdateNotebookTesterHelper helper(
        [&] (const Notebook & notebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebook == notebookParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNotebookRequest,
        &helper,
        &NoteStoreUpdateNotebookTesterHelper::onUpdateNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNotebookTesterHelper::updateNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateNotebook(
            notebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateNotebook()
{
    Notebook notebook = generateRandomNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUpdateNotebookTesterHelper helper(
        [&] (const Notebook & notebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebook == notebookParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNotebookRequest,
        &helper,
        &NoteStoreUpdateNotebookTesterHelper::onUpdateNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNotebookTesterHelper::updateNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateNotebook(
            notebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreExpungeNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeNotebookRequest,
        &helper,
        &NoteStoreExpungeNotebookTesterHelper::onExpungeNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeNotebookTesterHelper::expungeNotebookRequestReady,
        &server,
        &NoteStoreServer::onExpungeNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->expungeNotebook(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInExpungeNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreExpungeNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeNotebookRequest,
        &helper,
        &NoteStoreExpungeNotebookTesterHelper::onExpungeNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeNotebookTesterHelper::expungeNotebookRequestReady,
        &server,
        &NoteStoreServer::onExpungeNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInExpungeNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreExpungeNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeNotebookRequest,
        &helper,
        &NoteStoreExpungeNotebookTesterHelper::onExpungeNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeNotebookTesterHelper::expungeNotebookRequestReady,
        &server,
        &NoteStoreServer::onExpungeNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInExpungeNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreExpungeNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeNotebookRequest,
        &helper,
        &NoteStoreExpungeNotebookTesterHelper::onExpungeNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeNotebookTesterHelper::expungeNotebookRequestReady,
        &server,
        &NoteStoreServer::onExpungeNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListTags()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<Tag> response;
    response << generateRandomTag();
    response << generateRandomTag();
    response << generateRandomTag();

    NoteStoreListTagsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Tag>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listTagsRequest,
        &helper,
        &NoteStoreListTagsTesterHelper::onListTagsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListTagsTesterHelper::listTagsRequestReady,
        &server,
        &NoteStoreServer::onListTagsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listTagsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QList<Tag> res = noteStore->listTags(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInListTags()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreListTagsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Tag>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listTagsRequest,
        &helper,
        &NoteStoreListTagsTesterHelper::onListTagsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListTagsTesterHelper::listTagsRequestReady,
        &server,
        &NoteStoreServer::onListTagsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listTagsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Tag> res = noteStore->listTags(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInListTags()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::OPENID_ALREADY_TAKEN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreListTagsTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<Tag>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listTagsRequest,
        &helper,
        &NoteStoreListTagsTesterHelper::onListTagsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListTagsTesterHelper::listTagsRequestReady,
        &server,
        &NoteStoreServer::onListTagsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listTagsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Tag> res = noteStore->listTags(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListTagsByNotebook()
{
    Guid notebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<Tag> response;
    response << generateRandomTag();
    response << generateRandomTag();
    response << generateRandomTag();

    NoteStoreListTagsByNotebookTesterHelper helper(
        [&] (const Guid & notebookGuidParam,
             IRequestContextPtr ctxParam) -> QList<Tag>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listTagsByNotebookRequest,
        &helper,
        &NoteStoreListTagsByNotebookTesterHelper::onListTagsByNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListTagsByNotebookTesterHelper::listTagsByNotebookRequestReady,
        &server,
        &NoteStoreServer::onListTagsByNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listTagsByNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QList<Tag> res = noteStore->listTagsByNotebook(
        notebookGuid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInListTagsByNotebook()
{
    Guid notebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INTERNAL_ERROR;
    userException.parameter = generateRandomString();

    NoteStoreListTagsByNotebookTesterHelper helper(
        [&] (const Guid & notebookGuidParam,
             IRequestContextPtr ctxParam) -> QList<Tag>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listTagsByNotebookRequest,
        &helper,
        &NoteStoreListTagsByNotebookTesterHelper::onListTagsByNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListTagsByNotebookTesterHelper::listTagsByNotebookRequestReady,
        &server,
        &NoteStoreServer::onListTagsByNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listTagsByNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Tag> res = noteStore->listTagsByNotebook(
            notebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInListTagsByNotebook()
{
    Guid notebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TAKEN_DOWN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreListTagsByNotebookTesterHelper helper(
        [&] (const Guid & notebookGuidParam,
             IRequestContextPtr ctxParam) -> QList<Tag>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listTagsByNotebookRequest,
        &helper,
        &NoteStoreListTagsByNotebookTesterHelper::onListTagsByNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListTagsByNotebookTesterHelper::listTagsByNotebookRequestReady,
        &server,
        &NoteStoreServer::onListTagsByNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listTagsByNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Tag> res = noteStore->listTagsByNotebook(
            notebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInListTagsByNotebook()
{
    Guid notebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreListTagsByNotebookTesterHelper helper(
        [&] (const Guid & notebookGuidParam,
             IRequestContextPtr ctxParam) -> QList<Tag>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listTagsByNotebookRequest,
        &helper,
        &NoteStoreListTagsByNotebookTesterHelper::onListTagsByNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListTagsByNotebookTesterHelper::listTagsByNotebookRequestReady,
        &server,
        &NoteStoreServer::onListTagsByNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listTagsByNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<Tag> res = noteStore->listTagsByNotebook(
            notebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetTag()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Tag response = generateRandomTag();

    NoteStoreGetTagTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> Tag
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getTagRequest,
        &helper,
        &NoteStoreGetTagTesterHelper::onGetTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetTagTesterHelper::getTagRequestReady,
        &server,
        &NoteStoreServer::onGetTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Tag res = noteStore->getTag(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetTag()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LEN_TOO_SHORT;
    userException.parameter = generateRandomString();

    NoteStoreGetTagTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> Tag
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getTagRequest,
        &helper,
        &NoteStoreGetTagTesterHelper::onGetTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetTagTesterHelper::getTagRequestReady,
        &server,
        &NoteStoreServer::onGetTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Tag res = noteStore->getTag(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetTag()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::AUTH_EXPIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetTagTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> Tag
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getTagRequest,
        &helper,
        &NoteStoreGetTagTesterHelper::onGetTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetTagTesterHelper::getTagRequestReady,
        &server,
        &NoteStoreServer::onGetTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Tag res = noteStore->getTag(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetTag()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetTagTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> Tag
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getTagRequest,
        &helper,
        &NoteStoreGetTagTesterHelper::onGetTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetTagTesterHelper::getTagRequestReady,
        &server,
        &NoteStoreServer::onGetTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Tag res = noteStore->getTag(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateTag()
{
    Tag tag = generateRandomTag();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Tag response = generateRandomTag();

    NoteStoreCreateTagTesterHelper helper(
        [&] (const Tag & tagParam,
             IRequestContextPtr ctxParam) -> Tag
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(tag == tagParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createTagRequest,
        &helper,
        &NoteStoreCreateTagTesterHelper::onCreateTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateTagTesterHelper::createTagRequestReady,
        &server,
        &NoteStoreServer::onCreateTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Tag res = noteStore->createTag(
        tag,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInCreateTag()
{
    Tag tag = generateRandomTag();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreCreateTagTesterHelper helper(
        [&] (const Tag & tagParam,
             IRequestContextPtr ctxParam) -> Tag
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(tag == tagParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createTagRequest,
        &helper,
        &NoteStoreCreateTagTesterHelper::onCreateTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateTagTesterHelper::createTagRequestReady,
        &server,
        &NoteStoreServer::onCreateTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Tag res = noteStore->createTag(
            tag,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInCreateTag()
{
    Tag tag = generateRandomTag();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::RATE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreCreateTagTesterHelper helper(
        [&] (const Tag & tagParam,
             IRequestContextPtr ctxParam) -> Tag
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(tag == tagParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createTagRequest,
        &helper,
        &NoteStoreCreateTagTesterHelper::onCreateTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateTagTesterHelper::createTagRequestReady,
        &server,
        &NoteStoreServer::onCreateTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Tag res = noteStore->createTag(
            tag,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInCreateTag()
{
    Tag tag = generateRandomTag();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreCreateTagTesterHelper helper(
        [&] (const Tag & tagParam,
             IRequestContextPtr ctxParam) -> Tag
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(tag == tagParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createTagRequest,
        &helper,
        &NoteStoreCreateTagTesterHelper::onCreateTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateTagTesterHelper::createTagRequestReady,
        &server,
        &NoteStoreServer::onCreateTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Tag res = noteStore->createTag(
            tag,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateTag()
{
    Tag tag = generateRandomTag();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreUpdateTagTesterHelper helper(
        [&] (const Tag & tagParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(tag == tagParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateTagRequest,
        &helper,
        &NoteStoreUpdateTagTesterHelper::onUpdateTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateTagTesterHelper::updateTagRequestReady,
        &server,
        &NoteStoreServer::onUpdateTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->updateTag(
        tag,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUpdateTag()
{
    Tag tag = generateRandomTag();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    userException.parameter = generateRandomString();

    NoteStoreUpdateTagTesterHelper helper(
        [&] (const Tag & tagParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(tag == tagParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateTagRequest,
        &helper,
        &NoteStoreUpdateTagTesterHelper::onUpdateTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateTagTesterHelper::updateTagRequestReady,
        &server,
        &NoteStoreServer::onUpdateTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateTag(
            tag,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUpdateTag()
{
    Tag tag = generateRandomTag();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::QUOTA_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUpdateTagTesterHelper helper(
        [&] (const Tag & tagParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(tag == tagParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateTagRequest,
        &helper,
        &NoteStoreUpdateTagTesterHelper::onUpdateTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateTagTesterHelper::updateTagRequestReady,
        &server,
        &NoteStoreServer::onUpdateTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateTag(
            tag,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateTag()
{
    Tag tag = generateRandomTag();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUpdateTagTesterHelper helper(
        [&] (const Tag & tagParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(tag == tagParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateTagRequest,
        &helper,
        &NoteStoreUpdateTagTesterHelper::onUpdateTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateTagTesterHelper::updateTagRequestReady,
        &server,
        &NoteStoreServer::onUpdateTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateTag(
            tag,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUntagAll()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    NoteStoreUntagAllTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::untagAllRequest,
        &helper,
        &NoteStoreUntagAllTesterHelper::onUntagAllRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUntagAllTesterHelper::untagAllRequestReady,
        &server,
        &NoteStoreServer::onUntagAllRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::untagAllRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    noteStore->untagAll(
        guid,
        ctx);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUntagAll()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    userException.parameter = generateRandomString();

    NoteStoreUntagAllTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::untagAllRequest,
        &helper,
        &NoteStoreUntagAllTesterHelper::onUntagAllRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUntagAllTesterHelper::untagAllRequestReady,
        &server,
        &NoteStoreServer::onUntagAllRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::untagAllRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->untagAll(
            guid,
            ctx);
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUntagAll()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::USER_ALREADY_ASSOCIATED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUntagAllTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::untagAllRequest,
        &helper,
        &NoteStoreUntagAllTesterHelper::onUntagAllRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUntagAllTesterHelper::untagAllRequestReady,
        &server,
        &NoteStoreServer::onUntagAllRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::untagAllRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->untagAll(
            guid,
            ctx);
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUntagAll()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUntagAllTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::untagAllRequest,
        &helper,
        &NoteStoreUntagAllTesterHelper::onUntagAllRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUntagAllTesterHelper::untagAllRequestReady,
        &server,
        &NoteStoreServer::onUntagAllRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::untagAllRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->untagAll(
            guid,
            ctx);
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeTag()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreExpungeTagTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeTagRequest,
        &helper,
        &NoteStoreExpungeTagTesterHelper::onExpungeTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeTagTesterHelper::expungeTagRequestReady,
        &server,
        &NoteStoreServer::onExpungeTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->expungeTag(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInExpungeTag()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_MANY;
    userException.parameter = generateRandomString();

    NoteStoreExpungeTagTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeTagRequest,
        &helper,
        &NoteStoreExpungeTagTesterHelper::onExpungeTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeTagTesterHelper::expungeTagRequestReady,
        &server,
        &NoteStoreServer::onExpungeTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeTag(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInExpungeTag()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DATA_CONFLICT;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreExpungeTagTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeTagRequest,
        &helper,
        &NoteStoreExpungeTagTesterHelper::onExpungeTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeTagTesterHelper::expungeTagRequestReady,
        &server,
        &NoteStoreServer::onExpungeTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeTag(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInExpungeTag()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreExpungeTagTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeTagRequest,
        &helper,
        &NoteStoreExpungeTagTesterHelper::onExpungeTagRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeTagTesterHelper::expungeTagRequestReady,
        &server,
        &NoteStoreServer::onExpungeTagRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeTagRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeTag(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListSearches()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<SavedSearch> response;
    response << generateRandomSavedSearch();
    response << generateRandomSavedSearch();
    response << generateRandomSavedSearch();

    NoteStoreListSearchesTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<SavedSearch>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listSearchesRequest,
        &helper,
        &NoteStoreListSearchesTesterHelper::onListSearchesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListSearchesTesterHelper::listSearchesRequestReady,
        &server,
        &NoteStoreServer::onListSearchesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listSearchesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QList<SavedSearch> res = noteStore->listSearches(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInListSearches()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ENML_VALIDATION;
    userException.parameter = generateRandomString();

    NoteStoreListSearchesTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<SavedSearch>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listSearchesRequest,
        &helper,
        &NoteStoreListSearchesTesterHelper::onListSearchesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListSearchesTesterHelper::listSearchesRequestReady,
        &server,
        &NoteStoreServer::onListSearchesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listSearchesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<SavedSearch> res = noteStore->listSearches(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInListSearches()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreListSearchesTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<SavedSearch>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listSearchesRequest,
        &helper,
        &NoteStoreListSearchesTesterHelper::onListSearchesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListSearchesTesterHelper::listSearchesRequestReady,
        &server,
        &NoteStoreServer::onListSearchesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listSearchesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<SavedSearch> res = noteStore->listSearches(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetSearch()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    SavedSearch response = generateRandomSavedSearch();

    NoteStoreGetSearchTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> SavedSearch
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSearchRequest,
        &helper,
        &NoteStoreGetSearchTesterHelper::onGetSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSearchTesterHelper::getSearchRequestReady,
        &server,
        &NoteStoreServer::onGetSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    SavedSearch res = noteStore->getSearch(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetSearch()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TAKEN_DOWN;
    userException.parameter = generateRandomString();

    NoteStoreGetSearchTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> SavedSearch
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSearchRequest,
        &helper,
        &NoteStoreGetSearchTesterHelper::onGetSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSearchTesterHelper::getSearchRequestReady,
        &server,
        &NoteStoreServer::onGetSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SavedSearch res = noteStore->getSearch(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetSearch()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::USER_NOT_ASSOCIATED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetSearchTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> SavedSearch
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSearchRequest,
        &helper,
        &NoteStoreGetSearchTesterHelper::onGetSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSearchTesterHelper::getSearchRequestReady,
        &server,
        &NoteStoreServer::onGetSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SavedSearch res = noteStore->getSearch(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetSearch()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetSearchTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> SavedSearch
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSearchRequest,
        &helper,
        &NoteStoreGetSearchTesterHelper::onGetSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSearchTesterHelper::getSearchRequestReady,
        &server,
        &NoteStoreServer::onGetSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SavedSearch res = noteStore->getSearch(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateSearch()
{
    SavedSearch search = generateRandomSavedSearch();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    SavedSearch response = generateRandomSavedSearch();

    NoteStoreCreateSearchTesterHelper helper(
        [&] (const SavedSearch & searchParam,
             IRequestContextPtr ctxParam) -> SavedSearch
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(search == searchParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createSearchRequest,
        &helper,
        &NoteStoreCreateSearchTesterHelper::onCreateSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateSearchTesterHelper::createSearchRequestReady,
        &server,
        &NoteStoreServer::onCreateSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    SavedSearch res = noteStore->createSearch(
        search,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInCreateSearch()
{
    SavedSearch search = generateRandomSavedSearch();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_AUTH;
    userException.parameter = generateRandomString();

    NoteStoreCreateSearchTesterHelper helper(
        [&] (const SavedSearch & searchParam,
             IRequestContextPtr ctxParam) -> SavedSearch
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(search == searchParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createSearchRequest,
        &helper,
        &NoteStoreCreateSearchTesterHelper::onCreateSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateSearchTesterHelper::createSearchRequestReady,
        &server,
        &NoteStoreServer::onCreateSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SavedSearch res = noteStore->createSearch(
            search,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInCreateSearch()
{
    SavedSearch search = generateRandomSavedSearch();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::AUTH_EXPIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreCreateSearchTesterHelper helper(
        [&] (const SavedSearch & searchParam,
             IRequestContextPtr ctxParam) -> SavedSearch
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(search == searchParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createSearchRequest,
        &helper,
        &NoteStoreCreateSearchTesterHelper::onCreateSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateSearchTesterHelper::createSearchRequestReady,
        &server,
        &NoteStoreServer::onCreateSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SavedSearch res = noteStore->createSearch(
            search,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateSearch()
{
    SavedSearch search = generateRandomSavedSearch();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreUpdateSearchTesterHelper helper(
        [&] (const SavedSearch & searchParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(search == searchParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateSearchRequest,
        &helper,
        &NoteStoreUpdateSearchTesterHelper::onUpdateSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateSearchTesterHelper::updateSearchRequestReady,
        &server,
        &NoteStoreServer::onUpdateSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->updateSearch(
        search,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUpdateSearch()
{
    SavedSearch search = generateRandomSavedSearch();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::BAD_DATA_FORMAT;
    userException.parameter = generateRandomString();

    NoteStoreUpdateSearchTesterHelper helper(
        [&] (const SavedSearch & searchParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(search == searchParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateSearchRequest,
        &helper,
        &NoteStoreUpdateSearchTesterHelper::onUpdateSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateSearchTesterHelper::updateSearchRequestReady,
        &server,
        &NoteStoreServer::onUpdateSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateSearch(
            search,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUpdateSearch()
{
    SavedSearch search = generateRandomSavedSearch();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUpdateSearchTesterHelper helper(
        [&] (const SavedSearch & searchParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(search == searchParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateSearchRequest,
        &helper,
        &NoteStoreUpdateSearchTesterHelper::onUpdateSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateSearchTesterHelper::updateSearchRequestReady,
        &server,
        &NoteStoreServer::onUpdateSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateSearch(
            search,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateSearch()
{
    SavedSearch search = generateRandomSavedSearch();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUpdateSearchTesterHelper helper(
        [&] (const SavedSearch & searchParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(search == searchParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateSearchRequest,
        &helper,
        &NoteStoreUpdateSearchTesterHelper::onUpdateSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateSearchTesterHelper::updateSearchRequestReady,
        &server,
        &NoteStoreServer::onUpdateSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateSearch(
            search,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeSearch()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreExpungeSearchTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeSearchRequest,
        &helper,
        &NoteStoreExpungeSearchTesterHelper::onExpungeSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeSearchTesterHelper::expungeSearchRequestReady,
        &server,
        &NoteStoreServer::onExpungeSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->expungeSearch(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInExpungeSearch()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_AUTH;
    userException.parameter = generateRandomString();

    NoteStoreExpungeSearchTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeSearchRequest,
        &helper,
        &NoteStoreExpungeSearchTesterHelper::onExpungeSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeSearchTesterHelper::expungeSearchRequestReady,
        &server,
        &NoteStoreServer::onExpungeSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeSearch(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInExpungeSearch()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TOO_MANY;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreExpungeSearchTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeSearchRequest,
        &helper,
        &NoteStoreExpungeSearchTesterHelper::onExpungeSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeSearchTesterHelper::expungeSearchRequestReady,
        &server,
        &NoteStoreServer::onExpungeSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeSearch(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInExpungeSearch()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreExpungeSearchTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeSearchRequest,
        &helper,
        &NoteStoreExpungeSearchTesterHelper::onExpungeSearchRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeSearchTesterHelper::expungeSearchRequestReady,
        &server,
        &NoteStoreServer::onExpungeSearchRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeSearchRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeSearch(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteFindNoteOffset()
{
    NoteFilter filter = generateRandomNoteFilter();
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreFindNoteOffsetTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNoteOffsetRequest,
        &helper,
        &NoteStoreFindNoteOffsetTesterHelper::onFindNoteOffsetRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNoteOffsetTesterHelper::findNoteOffsetRequestReady,
        &server,
        &NoteStoreServer::onFindNoteOffsetRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNoteOffsetRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->findNoteOffset(
        filter,
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInFindNoteOffset()
{
    NoteFilter filter = generateRandomNoteFilter();
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LEN_TOO_LONG;
    userException.parameter = generateRandomString();

    NoteStoreFindNoteOffsetTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNoteOffsetRequest,
        &helper,
        &NoteStoreFindNoteOffsetTesterHelper::onFindNoteOffsetRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNoteOffsetTesterHelper::findNoteOffsetRequestReady,
        &server,
        &NoteStoreServer::onFindNoteOffsetRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNoteOffsetRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->findNoteOffset(
            filter,
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInFindNoteOffset()
{
    NoteFilter filter = generateRandomNoteFilter();
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreFindNoteOffsetTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNoteOffsetRequest,
        &helper,
        &NoteStoreFindNoteOffsetTesterHelper::onFindNoteOffsetRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNoteOffsetTesterHelper::findNoteOffsetRequestReady,
        &server,
        &NoteStoreServer::onFindNoteOffsetRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNoteOffsetRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->findNoteOffset(
            filter,
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInFindNoteOffset()
{
    NoteFilter filter = generateRandomNoteFilter();
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreFindNoteOffsetTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNoteOffsetRequest,
        &helper,
        &NoteStoreFindNoteOffsetTesterHelper::onFindNoteOffsetRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNoteOffsetTesterHelper::findNoteOffsetRequestReady,
        &server,
        &NoteStoreServer::onFindNoteOffsetRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNoteOffsetRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->findNoteOffset(
            filter,
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteFindNotesMetadata()
{
    NoteFilter filter = generateRandomNoteFilter();
    qint32 offset = generateRandomInt32();
    qint32 maxNotes = generateRandomInt32();
    NotesMetadataResultSpec resultSpec = generateRandomNotesMetadataResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    NotesMetadataList response = generateRandomNotesMetadataList();

    NoteStoreFindNotesMetadataTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             qint32 offsetParam,
             qint32 maxNotesParam,
             const NotesMetadataResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> NotesMetadataList
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(offset == offsetParam);
            Q_ASSERT(maxNotes == maxNotesParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNotesMetadataRequest,
        &helper,
        &NoteStoreFindNotesMetadataTesterHelper::onFindNotesMetadataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNotesMetadataTesterHelper::findNotesMetadataRequestReady,
        &server,
        &NoteStoreServer::onFindNotesMetadataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNotesMetadataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    NotesMetadataList res = noteStore->findNotesMetadata(
        filter,
        offset,
        maxNotes,
        resultSpec,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInFindNotesMetadata()
{
    NoteFilter filter = generateRandomNoteFilter();
    qint32 offset = generateRandomInt32();
    qint32 maxNotes = generateRandomInt32();
    NotesMetadataResultSpec resultSpec = generateRandomNotesMetadataResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ACCOUNT_CLEAR;
    userException.parameter = generateRandomString();

    NoteStoreFindNotesMetadataTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             qint32 offsetParam,
             qint32 maxNotesParam,
             const NotesMetadataResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> NotesMetadataList
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(offset == offsetParam);
            Q_ASSERT(maxNotes == maxNotesParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNotesMetadataRequest,
        &helper,
        &NoteStoreFindNotesMetadataTesterHelper::onFindNotesMetadataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNotesMetadataTesterHelper::findNotesMetadataRequestReady,
        &server,
        &NoteStoreServer::onFindNotesMetadataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNotesMetadataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        NotesMetadataList res = noteStore->findNotesMetadata(
            filter,
            offset,
            maxNotes,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInFindNotesMetadata()
{
    NoteFilter filter = generateRandomNoteFilter();
    qint32 offset = generateRandomInt32();
    qint32 maxNotes = generateRandomInt32();
    NotesMetadataResultSpec resultSpec = generateRandomNotesMetadataResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LEN_TOO_SHORT;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreFindNotesMetadataTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             qint32 offsetParam,
             qint32 maxNotesParam,
             const NotesMetadataResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> NotesMetadataList
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(offset == offsetParam);
            Q_ASSERT(maxNotes == maxNotesParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNotesMetadataRequest,
        &helper,
        &NoteStoreFindNotesMetadataTesterHelper::onFindNotesMetadataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNotesMetadataTesterHelper::findNotesMetadataRequestReady,
        &server,
        &NoteStoreServer::onFindNotesMetadataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNotesMetadataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        NotesMetadataList res = noteStore->findNotesMetadata(
            filter,
            offset,
            maxNotes,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInFindNotesMetadata()
{
    NoteFilter filter = generateRandomNoteFilter();
    qint32 offset = generateRandomInt32();
    qint32 maxNotes = generateRandomInt32();
    NotesMetadataResultSpec resultSpec = generateRandomNotesMetadataResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreFindNotesMetadataTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             qint32 offsetParam,
             qint32 maxNotesParam,
             const NotesMetadataResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> NotesMetadataList
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(offset == offsetParam);
            Q_ASSERT(maxNotes == maxNotesParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNotesMetadataRequest,
        &helper,
        &NoteStoreFindNotesMetadataTesterHelper::onFindNotesMetadataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNotesMetadataTesterHelper::findNotesMetadataRequestReady,
        &server,
        &NoteStoreServer::onFindNotesMetadataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNotesMetadataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        NotesMetadataList res = noteStore->findNotesMetadata(
            filter,
            offset,
            maxNotes,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteFindNoteCounts()
{
    NoteFilter filter = generateRandomNoteFilter();
    bool withTrash = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    NoteCollectionCounts response = generateRandomNoteCollectionCounts();

    NoteStoreFindNoteCountsTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             bool withTrashParam,
             IRequestContextPtr ctxParam) -> NoteCollectionCounts
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(withTrash == withTrashParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNoteCountsRequest,
        &helper,
        &NoteStoreFindNoteCountsTesterHelper::onFindNoteCountsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNoteCountsTesterHelper::findNoteCountsRequestReady,
        &server,
        &NoteStoreServer::onFindNoteCountsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNoteCountsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    NoteCollectionCounts res = noteStore->findNoteCounts(
        filter,
        withTrash,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInFindNoteCounts()
{
    NoteFilter filter = generateRandomNoteFilter();
    bool withTrash = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_NOT_REGISTERED;
    userException.parameter = generateRandomString();

    NoteStoreFindNoteCountsTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             bool withTrashParam,
             IRequestContextPtr ctxParam) -> NoteCollectionCounts
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(withTrash == withTrashParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNoteCountsRequest,
        &helper,
        &NoteStoreFindNoteCountsTesterHelper::onFindNoteCountsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNoteCountsTesterHelper::findNoteCountsRequestReady,
        &server,
        &NoteStoreServer::onFindNoteCountsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNoteCountsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        NoteCollectionCounts res = noteStore->findNoteCounts(
            filter,
            withTrash,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInFindNoteCounts()
{
    NoteFilter filter = generateRandomNoteFilter();
    bool withTrash = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TOO_FEW;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreFindNoteCountsTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             bool withTrashParam,
             IRequestContextPtr ctxParam) -> NoteCollectionCounts
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(withTrash == withTrashParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNoteCountsRequest,
        &helper,
        &NoteStoreFindNoteCountsTesterHelper::onFindNoteCountsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNoteCountsTesterHelper::findNoteCountsRequestReady,
        &server,
        &NoteStoreServer::onFindNoteCountsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNoteCountsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        NoteCollectionCounts res = noteStore->findNoteCounts(
            filter,
            withTrash,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInFindNoteCounts()
{
    NoteFilter filter = generateRandomNoteFilter();
    bool withTrash = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreFindNoteCountsTesterHelper helper(
        [&] (const NoteFilter & filterParam,
             bool withTrashParam,
             IRequestContextPtr ctxParam) -> NoteCollectionCounts
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(filter == filterParam);
            Q_ASSERT(withTrash == withTrashParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findNoteCountsRequest,
        &helper,
        &NoteStoreFindNoteCountsTesterHelper::onFindNoteCountsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindNoteCountsTesterHelper::findNoteCountsRequestReady,
        &server,
        &NoteStoreServer::onFindNoteCountsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findNoteCountsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        NoteCollectionCounts res = noteStore->findNoteCounts(
            filter,
            withTrash,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteWithResultSpec()
{
    Guid guid = generateRandomString();
    NoteResultSpec resultSpec = generateRandomNoteResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Note response = generateRandomNote();

    NoteStoreGetNoteWithResultSpecTesterHelper helper(
        [&] (const Guid & guidParam,
             const NoteResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteWithResultSpecRequest,
        &helper,
        &NoteStoreGetNoteWithResultSpecTesterHelper::onGetNoteWithResultSpecRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteWithResultSpecTesterHelper::getNoteWithResultSpecRequestReady,
        &server,
        &NoteStoreServer::onGetNoteWithResultSpecRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteWithResultSpecRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Note res = noteStore->getNoteWithResultSpec(
        guid,
        resultSpec,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNoteWithResultSpec()
{
    Guid guid = generateRandomString();
    NoteResultSpec resultSpec = generateRandomNoteResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    userException.parameter = generateRandomString();

    NoteStoreGetNoteWithResultSpecTesterHelper helper(
        [&] (const Guid & guidParam,
             const NoteResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteWithResultSpecRequest,
        &helper,
        &NoteStoreGetNoteWithResultSpecTesterHelper::onGetNoteWithResultSpecRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteWithResultSpecTesterHelper::getNoteWithResultSpecRequestReady,
        &server,
        &NoteStoreServer::onGetNoteWithResultSpecRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteWithResultSpecRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNoteWithResultSpec(
            guid,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNoteWithResultSpec()
{
    Guid guid = generateRandomString();
    NoteResultSpec resultSpec = generateRandomNoteResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INVALID_AUTH;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNoteWithResultSpecTesterHelper helper(
        [&] (const Guid & guidParam,
             const NoteResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteWithResultSpecRequest,
        &helper,
        &NoteStoreGetNoteWithResultSpecTesterHelper::onGetNoteWithResultSpecRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteWithResultSpecTesterHelper::getNoteWithResultSpecRequestReady,
        &server,
        &NoteStoreServer::onGetNoteWithResultSpecRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteWithResultSpecRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNoteWithResultSpec(
            guid,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNoteWithResultSpec()
{
    Guid guid = generateRandomString();
    NoteResultSpec resultSpec = generateRandomNoteResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNoteWithResultSpecTesterHelper helper(
        [&] (const Guid & guidParam,
             const NoteResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteWithResultSpecRequest,
        &helper,
        &NoteStoreGetNoteWithResultSpecTesterHelper::onGetNoteWithResultSpecRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteWithResultSpecTesterHelper::getNoteWithResultSpecRequestReady,
        &server,
        &NoteStoreServer::onGetNoteWithResultSpecRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteWithResultSpecRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNoteWithResultSpec(
            guid,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNote()
{
    Guid guid = generateRandomString();
    bool withContent = generateRandomBool();
    bool withResourcesData = generateRandomBool();
    bool withResourcesRecognition = generateRandomBool();
    bool withResourcesAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Note response = generateRandomNote();

    NoteStoreGetNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             bool withContentParam,
             bool withResourcesDataParam,
             bool withResourcesRecognitionParam,
             bool withResourcesAlternateDataParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(withContent == withContentParam);
            Q_ASSERT(withResourcesData == withResourcesDataParam);
            Q_ASSERT(withResourcesRecognition == withResourcesRecognitionParam);
            Q_ASSERT(withResourcesAlternateData == withResourcesAlternateDataParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteRequest,
        &helper,
        &NoteStoreGetNoteTesterHelper::onGetNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteTesterHelper::getNoteRequestReady,
        &server,
        &NoteStoreServer::onGetNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Note res = noteStore->getNote(
        guid,
        withContent,
        withResourcesData,
        withResourcesRecognition,
        withResourcesAlternateData,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNote()
{
    Guid guid = generateRandomString();
    bool withContent = generateRandomBool();
    bool withResourcesData = generateRandomBool();
    bool withResourcesRecognition = generateRandomBool();
    bool withResourcesAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_AUTH;
    userException.parameter = generateRandomString();

    NoteStoreGetNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             bool withContentParam,
             bool withResourcesDataParam,
             bool withResourcesRecognitionParam,
             bool withResourcesAlternateDataParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(withContent == withContentParam);
            Q_ASSERT(withResourcesData == withResourcesDataParam);
            Q_ASSERT(withResourcesRecognition == withResourcesRecognitionParam);
            Q_ASSERT(withResourcesAlternateData == withResourcesAlternateDataParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteRequest,
        &helper,
        &NoteStoreGetNoteTesterHelper::onGetNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteTesterHelper::getNoteRequestReady,
        &server,
        &NoteStoreServer::onGetNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNote(
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNote()
{
    Guid guid = generateRandomString();
    bool withContent = generateRandomBool();
    bool withResourcesData = generateRandomBool();
    bool withResourcesRecognition = generateRandomBool();
    bool withResourcesAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             bool withContentParam,
             bool withResourcesDataParam,
             bool withResourcesRecognitionParam,
             bool withResourcesAlternateDataParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(withContent == withContentParam);
            Q_ASSERT(withResourcesData == withResourcesDataParam);
            Q_ASSERT(withResourcesRecognition == withResourcesRecognitionParam);
            Q_ASSERT(withResourcesAlternateData == withResourcesAlternateDataParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteRequest,
        &helper,
        &NoteStoreGetNoteTesterHelper::onGetNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteTesterHelper::getNoteRequestReady,
        &server,
        &NoteStoreServer::onGetNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNote(
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNote()
{
    Guid guid = generateRandomString();
    bool withContent = generateRandomBool();
    bool withResourcesData = generateRandomBool();
    bool withResourcesRecognition = generateRandomBool();
    bool withResourcesAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             bool withContentParam,
             bool withResourcesDataParam,
             bool withResourcesRecognitionParam,
             bool withResourcesAlternateDataParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(withContent == withContentParam);
            Q_ASSERT(withResourcesData == withResourcesDataParam);
            Q_ASSERT(withResourcesRecognition == withResourcesRecognitionParam);
            Q_ASSERT(withResourcesAlternateData == withResourcesAlternateDataParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteRequest,
        &helper,
        &NoteStoreGetNoteTesterHelper::onGetNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteTesterHelper::getNoteRequestReady,
        &server,
        &NoteStoreServer::onGetNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNote(
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteApplicationData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    LazyMap response = generateRandomLazyMap();

    NoteStoreGetNoteApplicationDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> LazyMap
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataRequest,
        &helper,
        &NoteStoreGetNoteApplicationDataTesterHelper::onGetNoteApplicationDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteApplicationDataTesterHelper::getNoteApplicationDataRequestReady,
        &server,
        &NoteStoreServer::onGetNoteApplicationDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    LazyMap res = noteStore->getNoteApplicationData(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNoteApplicationData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_NOT_REGISTERED;
    userException.parameter = generateRandomString();

    NoteStoreGetNoteApplicationDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> LazyMap
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataRequest,
        &helper,
        &NoteStoreGetNoteApplicationDataTesterHelper::onGetNoteApplicationDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteApplicationDataTesterHelper::getNoteApplicationDataRequestReady,
        &server,
        &NoteStoreServer::onGetNoteApplicationDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LazyMap res = noteStore->getNoteApplicationData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNoteApplicationData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNoteApplicationDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> LazyMap
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataRequest,
        &helper,
        &NoteStoreGetNoteApplicationDataTesterHelper::onGetNoteApplicationDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteApplicationDataTesterHelper::getNoteApplicationDataRequestReady,
        &server,
        &NoteStoreServer::onGetNoteApplicationDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LazyMap res = noteStore->getNoteApplicationData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNoteApplicationData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNoteApplicationDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> LazyMap
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataRequest,
        &helper,
        &NoteStoreGetNoteApplicationDataTesterHelper::onGetNoteApplicationDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteApplicationDataTesterHelper::getNoteApplicationDataRequestReady,
        &server,
        &NoteStoreServer::onGetNoteApplicationDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LazyMap res = noteStore->getNoteApplicationData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QString response = generateRandomString();

    NoteStoreGetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreGetNoteApplicationDataEntryTesterHelper::onGetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteApplicationDataEntryTesterHelper::getNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onGetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QString res = noteStore->getNoteApplicationDataEntry(
        guid,
        key,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_NOT_REGISTERED;
    userException.parameter = generateRandomString();

    NoteStoreGetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreGetNoteApplicationDataEntryTesterHelper::onGetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteApplicationDataEntryTesterHelper::getNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onGetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreGetNoteApplicationDataEntryTesterHelper::onGetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteApplicationDataEntryTesterHelper::getNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onGetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreGetNoteApplicationDataEntryTesterHelper::onGetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteApplicationDataEntryTesterHelper::getNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onGetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteSetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    QString value = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreSetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             const QString & valueParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            Q_ASSERT(value == valueParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreSetNoteApplicationDataEntryTesterHelper::onSetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetNoteApplicationDataEntryTesterHelper::setNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onSetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->setNoteApplicationDataEntry(
        guid,
        key,
        value,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInSetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    QString value = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::QUOTA_REACHED;
    userException.parameter = generateRandomString();

    NoteStoreSetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             const QString & valueParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            Q_ASSERT(value == valueParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreSetNoteApplicationDataEntryTesterHelper::onSetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetNoteApplicationDataEntryTesterHelper::setNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onSetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->setNoteApplicationDataEntry(
            guid,
            key,
            value,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInSetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    QString value = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TAKEN_DOWN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreSetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             const QString & valueParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            Q_ASSERT(value == valueParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreSetNoteApplicationDataEntryTesterHelper::onSetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetNoteApplicationDataEntryTesterHelper::setNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onSetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->setNoteApplicationDataEntry(
            guid,
            key,
            value,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInSetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    QString value = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreSetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             const QString & valueParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            Q_ASSERT(value == valueParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreSetNoteApplicationDataEntryTesterHelper::onSetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetNoteApplicationDataEntryTesterHelper::setNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onSetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->setNoteApplicationDataEntry(
            guid,
            key,
            value,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUnsetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreUnsetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::unsetNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreUnsetNoteApplicationDataEntryTesterHelper::onUnsetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUnsetNoteApplicationDataEntryTesterHelper::unsetNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onUnsetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::unsetNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->unsetNoteApplicationDataEntry(
        guid,
        key,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUnsetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::QUOTA_REACHED;
    userException.parameter = generateRandomString();

    NoteStoreUnsetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::unsetNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreUnsetNoteApplicationDataEntryTesterHelper::onUnsetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUnsetNoteApplicationDataEntryTesterHelper::unsetNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onUnsetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::unsetNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->unsetNoteApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUnsetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::UNKNOWN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUnsetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::unsetNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreUnsetNoteApplicationDataEntryTesterHelper::onUnsetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUnsetNoteApplicationDataEntryTesterHelper::unsetNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onUnsetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::unsetNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->unsetNoteApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUnsetNoteApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUnsetNoteApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::unsetNoteApplicationDataEntryRequest,
        &helper,
        &NoteStoreUnsetNoteApplicationDataEntryTesterHelper::onUnsetNoteApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUnsetNoteApplicationDataEntryTesterHelper::unsetNoteApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onUnsetNoteApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::unsetNoteApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->unsetNoteApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteContent()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QString response = generateRandomString();

    NoteStoreGetNoteContentTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteContentRequest,
        &helper,
        &NoteStoreGetNoteContentTesterHelper::onGetNoteContentRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteContentTesterHelper::getNoteContentRequestReady,
        &server,
        &NoteStoreServer::onGetNoteContentRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteContentRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QString res = noteStore->getNoteContent(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNoteContent()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_FEW;
    userException.parameter = generateRandomString();

    NoteStoreGetNoteContentTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteContentRequest,
        &helper,
        &NoteStoreGetNoteContentTesterHelper::onGetNoteContentRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteContentTesterHelper::getNoteContentRequestReady,
        &server,
        &NoteStoreServer::onGetNoteContentRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteContentRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteContent(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNoteContent()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNoteContentTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteContentRequest,
        &helper,
        &NoteStoreGetNoteContentTesterHelper::onGetNoteContentRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteContentTesterHelper::getNoteContentRequestReady,
        &server,
        &NoteStoreServer::onGetNoteContentRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteContentRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteContent(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNoteContent()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNoteContentTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteContentRequest,
        &helper,
        &NoteStoreGetNoteContentTesterHelper::onGetNoteContentRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteContentTesterHelper::getNoteContentRequestReady,
        &server,
        &NoteStoreServer::onGetNoteContentRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteContentRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteContent(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteSearchText()
{
    Guid guid = generateRandomString();
    bool noteOnly = generateRandomBool();
    bool tokenizeForIndexing = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QString response = generateRandomString();

    NoteStoreGetNoteSearchTextTesterHelper helper(
        [&] (const Guid & guidParam,
             bool noteOnlyParam,
             bool tokenizeForIndexingParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(noteOnly == noteOnlyParam);
            Q_ASSERT(tokenizeForIndexing == tokenizeForIndexingParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteSearchTextRequest,
        &helper,
        &NoteStoreGetNoteSearchTextTesterHelper::onGetNoteSearchTextRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteSearchTextTesterHelper::getNoteSearchTextRequestReady,
        &server,
        &NoteStoreServer::onGetNoteSearchTextRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteSearchTextRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QString res = noteStore->getNoteSearchText(
        guid,
        noteOnly,
        tokenizeForIndexing,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNoteSearchText()
{
    Guid guid = generateRandomString();
    bool noteOnly = generateRandomBool();
    bool tokenizeForIndexing = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    userException.parameter = generateRandomString();

    NoteStoreGetNoteSearchTextTesterHelper helper(
        [&] (const Guid & guidParam,
             bool noteOnlyParam,
             bool tokenizeForIndexingParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(noteOnly == noteOnlyParam);
            Q_ASSERT(tokenizeForIndexing == tokenizeForIndexingParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteSearchTextRequest,
        &helper,
        &NoteStoreGetNoteSearchTextTesterHelper::onGetNoteSearchTextRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteSearchTextTesterHelper::getNoteSearchTextRequestReady,
        &server,
        &NoteStoreServer::onGetNoteSearchTextRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteSearchTextRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteSearchText(
            guid,
            noteOnly,
            tokenizeForIndexing,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNoteSearchText()
{
    Guid guid = generateRandomString();
    bool noteOnly = generateRandomBool();
    bool tokenizeForIndexing = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::AUTH_EXPIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNoteSearchTextTesterHelper helper(
        [&] (const Guid & guidParam,
             bool noteOnlyParam,
             bool tokenizeForIndexingParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(noteOnly == noteOnlyParam);
            Q_ASSERT(tokenizeForIndexing == tokenizeForIndexingParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteSearchTextRequest,
        &helper,
        &NoteStoreGetNoteSearchTextTesterHelper::onGetNoteSearchTextRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteSearchTextTesterHelper::getNoteSearchTextRequestReady,
        &server,
        &NoteStoreServer::onGetNoteSearchTextRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteSearchTextRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteSearchText(
            guid,
            noteOnly,
            tokenizeForIndexing,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNoteSearchText()
{
    Guid guid = generateRandomString();
    bool noteOnly = generateRandomBool();
    bool tokenizeForIndexing = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNoteSearchTextTesterHelper helper(
        [&] (const Guid & guidParam,
             bool noteOnlyParam,
             bool tokenizeForIndexingParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(noteOnly == noteOnlyParam);
            Q_ASSERT(tokenizeForIndexing == tokenizeForIndexingParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteSearchTextRequest,
        &helper,
        &NoteStoreGetNoteSearchTextTesterHelper::onGetNoteSearchTextRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteSearchTextTesterHelper::getNoteSearchTextRequestReady,
        &server,
        &NoteStoreServer::onGetNoteSearchTextRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteSearchTextRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getNoteSearchText(
            guid,
            noteOnly,
            tokenizeForIndexing,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceSearchText()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QString response = generateRandomString();

    NoteStoreGetResourceSearchTextTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceSearchTextRequest,
        &helper,
        &NoteStoreGetResourceSearchTextTesterHelper::onGetResourceSearchTextRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceSearchTextTesterHelper::getResourceSearchTextRequestReady,
        &server,
        &NoteStoreServer::onGetResourceSearchTextRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceSearchTextRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QString res = noteStore->getResourceSearchText(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResourceSearchText()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ENML_VALIDATION;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceSearchTextTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceSearchTextRequest,
        &helper,
        &NoteStoreGetResourceSearchTextTesterHelper::onGetResourceSearchTextRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceSearchTextTesterHelper::getResourceSearchTextRequestReady,
        &server,
        &NoteStoreServer::onGetResourceSearchTextRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceSearchTextRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getResourceSearchText(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResourceSearchText()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::USER_NOT_ASSOCIATED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceSearchTextTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceSearchTextRequest,
        &helper,
        &NoteStoreGetResourceSearchTextTesterHelper::onGetResourceSearchTextRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceSearchTextTesterHelper::getResourceSearchTextRequestReady,
        &server,
        &NoteStoreServer::onGetResourceSearchTextRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceSearchTextRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getResourceSearchText(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResourceSearchText()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceSearchTextTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceSearchTextRequest,
        &helper,
        &NoteStoreGetResourceSearchTextTesterHelper::onGetResourceSearchTextRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceSearchTextTesterHelper::getResourceSearchTextRequestReady,
        &server,
        &NoteStoreServer::onGetResourceSearchTextRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceSearchTextRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getResourceSearchText(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteTagNames()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QStringList response;
    response << generateRandomString();
    response << generateRandomString();
    response << generateRandomString();

    NoteStoreGetNoteTagNamesTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QStringList
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteTagNamesRequest,
        &helper,
        &NoteStoreGetNoteTagNamesTesterHelper::onGetNoteTagNamesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteTagNamesTesterHelper::getNoteTagNamesRequestReady,
        &server,
        &NoteStoreServer::onGetNoteTagNamesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteTagNamesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QStringList res = noteStore->getNoteTagNames(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNoteTagNames()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreGetNoteTagNamesTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QStringList
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteTagNamesRequest,
        &helper,
        &NoteStoreGetNoteTagNamesTesterHelper::onGetNoteTagNamesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteTagNamesTesterHelper::getNoteTagNamesRequestReady,
        &server,
        &NoteStoreServer::onGetNoteTagNamesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteTagNamesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QStringList res = noteStore->getNoteTagNames(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNoteTagNames()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNoteTagNamesTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QStringList
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteTagNamesRequest,
        &helper,
        &NoteStoreGetNoteTagNamesTesterHelper::onGetNoteTagNamesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteTagNamesTesterHelper::getNoteTagNamesRequestReady,
        &server,
        &NoteStoreServer::onGetNoteTagNamesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteTagNamesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QStringList res = noteStore->getNoteTagNames(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNoteTagNames()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNoteTagNamesTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QStringList
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteTagNamesRequest,
        &helper,
        &NoteStoreGetNoteTagNamesTesterHelper::onGetNoteTagNamesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteTagNamesTesterHelper::getNoteTagNamesRequestReady,
        &server,
        &NoteStoreServer::onGetNoteTagNamesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteTagNamesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QStringList res = noteStore->getNoteTagNames(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateNote()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Note response = generateRandomNote();

    NoteStoreCreateNoteTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createNoteRequest,
        &helper,
        &NoteStoreCreateNoteTesterHelper::onCreateNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateNoteTesterHelper::createNoteRequestReady,
        &server,
        &NoteStoreServer::onCreateNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Note res = noteStore->createNote(
        note,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInCreateNote()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreCreateNoteTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createNoteRequest,
        &helper,
        &NoteStoreCreateNoteTesterHelper::onCreateNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateNoteTesterHelper::createNoteRequestReady,
        &server,
        &NoteStoreServer::onCreateNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->createNote(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInCreateNote()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreCreateNoteTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createNoteRequest,
        &helper,
        &NoteStoreCreateNoteTesterHelper::onCreateNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateNoteTesterHelper::createNoteRequestReady,
        &server,
        &NoteStoreServer::onCreateNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->createNote(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInCreateNote()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreCreateNoteTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createNoteRequest,
        &helper,
        &NoteStoreCreateNoteTesterHelper::onCreateNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateNoteTesterHelper::createNoteRequestReady,
        &server,
        &NoteStoreServer::onCreateNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->createNote(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateNote()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Note response = generateRandomNote();

    NoteStoreUpdateNoteTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteRequest,
        &helper,
        &NoteStoreUpdateNoteTesterHelper::onUpdateNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNoteTesterHelper::updateNoteRequestReady,
        &server,
        &NoteStoreServer::onUpdateNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Note res = noteStore->updateNote(
        note,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUpdateNote()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    userException.parameter = generateRandomString();

    NoteStoreUpdateNoteTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteRequest,
        &helper,
        &NoteStoreUpdateNoteTesterHelper::onUpdateNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNoteTesterHelper::updateNoteRequestReady,
        &server,
        &NoteStoreServer::onUpdateNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->updateNote(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUpdateNote()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::USER_NOT_ASSOCIATED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUpdateNoteTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteRequest,
        &helper,
        &NoteStoreUpdateNoteTesterHelper::onUpdateNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNoteTesterHelper::updateNoteRequestReady,
        &server,
        &NoteStoreServer::onUpdateNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->updateNote(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateNote()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUpdateNoteTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteRequest,
        &helper,
        &NoteStoreUpdateNoteTesterHelper::onUpdateNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNoteTesterHelper::updateNoteRequestReady,
        &server,
        &NoteStoreServer::onUpdateNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->updateNote(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteDeleteNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreDeleteNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::deleteNoteRequest,
        &helper,
        &NoteStoreDeleteNoteTesterHelper::onDeleteNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreDeleteNoteTesterHelper::deleteNoteRequestReady,
        &server,
        &NoteStoreServer::onDeleteNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::deleteNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->deleteNote(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInDeleteNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreDeleteNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::deleteNoteRequest,
        &helper,
        &NoteStoreDeleteNoteTesterHelper::onDeleteNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreDeleteNoteTesterHelper::deleteNoteRequestReady,
        &server,
        &NoteStoreServer::onDeleteNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::deleteNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->deleteNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInDeleteNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LEN_TOO_LONG;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreDeleteNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::deleteNoteRequest,
        &helper,
        &NoteStoreDeleteNoteTesterHelper::onDeleteNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreDeleteNoteTesterHelper::deleteNoteRequestReady,
        &server,
        &NoteStoreServer::onDeleteNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::deleteNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->deleteNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInDeleteNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreDeleteNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::deleteNoteRequest,
        &helper,
        &NoteStoreDeleteNoteTesterHelper::onDeleteNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreDeleteNoteTesterHelper::deleteNoteRequestReady,
        &server,
        &NoteStoreServer::onDeleteNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::deleteNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->deleteNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreExpungeNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeNoteRequest,
        &helper,
        &NoteStoreExpungeNoteTesterHelper::onExpungeNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeNoteTesterHelper::expungeNoteRequestReady,
        &server,
        &NoteStoreServer::onExpungeNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->expungeNote(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInExpungeNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::SHARD_UNAVAILABLE;
    userException.parameter = generateRandomString();

    NoteStoreExpungeNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeNoteRequest,
        &helper,
        &NoteStoreExpungeNoteTesterHelper::onExpungeNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeNoteTesterHelper::expungeNoteRequestReady,
        &server,
        &NoteStoreServer::onExpungeNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInExpungeNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreExpungeNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeNoteRequest,
        &helper,
        &NoteStoreExpungeNoteTesterHelper::onExpungeNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeNoteTesterHelper::expungeNoteRequestReady,
        &server,
        &NoteStoreServer::onExpungeNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInExpungeNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreExpungeNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeNoteRequest,
        &helper,
        &NoteStoreExpungeNoteTesterHelper::onExpungeNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeNoteTesterHelper::expungeNoteRequestReady,
        &server,
        &NoteStoreServer::onExpungeNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCopyNote()
{
    Guid noteGuid = generateRandomString();
    Guid toNotebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Note response = generateRandomNote();

    NoteStoreCopyNoteTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             const Guid & toNotebookGuidParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(toNotebookGuid == toNotebookGuidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::copyNoteRequest,
        &helper,
        &NoteStoreCopyNoteTesterHelper::onCopyNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCopyNoteTesterHelper::copyNoteRequestReady,
        &server,
        &NoteStoreServer::onCopyNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::copyNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Note res = noteStore->copyNote(
        noteGuid,
        toNotebookGuid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInCopyNote()
{
    Guid noteGuid = generateRandomString();
    Guid toNotebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ACCOUNT_CLEAR;
    userException.parameter = generateRandomString();

    NoteStoreCopyNoteTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             const Guid & toNotebookGuidParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(toNotebookGuid == toNotebookGuidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::copyNoteRequest,
        &helper,
        &NoteStoreCopyNoteTesterHelper::onCopyNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCopyNoteTesterHelper::copyNoteRequestReady,
        &server,
        &NoteStoreServer::onCopyNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::copyNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->copyNote(
            noteGuid,
            toNotebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInCopyNote()
{
    Guid noteGuid = generateRandomString();
    Guid toNotebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::BUSINESS_SECURITY_LOGIN_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreCopyNoteTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             const Guid & toNotebookGuidParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(toNotebookGuid == toNotebookGuidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::copyNoteRequest,
        &helper,
        &NoteStoreCopyNoteTesterHelper::onCopyNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCopyNoteTesterHelper::copyNoteRequestReady,
        &server,
        &NoteStoreServer::onCopyNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::copyNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->copyNote(
            noteGuid,
            toNotebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInCopyNote()
{
    Guid noteGuid = generateRandomString();
    Guid toNotebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreCopyNoteTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             const Guid & toNotebookGuidParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(toNotebookGuid == toNotebookGuidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::copyNoteRequest,
        &helper,
        &NoteStoreCopyNoteTesterHelper::onCopyNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCopyNoteTesterHelper::copyNoteRequestReady,
        &server,
        &NoteStoreServer::onCopyNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::copyNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->copyNote(
            noteGuid,
            toNotebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListNoteVersions()
{
    Guid noteGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<NoteVersionId> response;
    response << generateRandomNoteVersionId();
    response << generateRandomNoteVersionId();
    response << generateRandomNoteVersionId();

    NoteStoreListNoteVersionsTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             IRequestContextPtr ctxParam) -> QList<NoteVersionId>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listNoteVersionsRequest,
        &helper,
        &NoteStoreListNoteVersionsTesterHelper::onListNoteVersionsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListNoteVersionsTesterHelper::listNoteVersionsRequestReady,
        &server,
        &NoteStoreServer::onListNoteVersionsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listNoteVersionsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QList<NoteVersionId> res = noteStore->listNoteVersions(
        noteGuid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInListNoteVersions()
{
    Guid noteGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    userException.parameter = generateRandomString();

    NoteStoreListNoteVersionsTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             IRequestContextPtr ctxParam) -> QList<NoteVersionId>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listNoteVersionsRequest,
        &helper,
        &NoteStoreListNoteVersionsTesterHelper::onListNoteVersionsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListNoteVersionsTesterHelper::listNoteVersionsRequestReady,
        &server,
        &NoteStoreServer::onListNoteVersionsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listNoteVersionsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<NoteVersionId> res = noteStore->listNoteVersions(
            noteGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInListNoteVersions()
{
    Guid noteGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::ACCOUNT_CLEAR;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreListNoteVersionsTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             IRequestContextPtr ctxParam) -> QList<NoteVersionId>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listNoteVersionsRequest,
        &helper,
        &NoteStoreListNoteVersionsTesterHelper::onListNoteVersionsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListNoteVersionsTesterHelper::listNoteVersionsRequestReady,
        &server,
        &NoteStoreServer::onListNoteVersionsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listNoteVersionsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<NoteVersionId> res = noteStore->listNoteVersions(
            noteGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInListNoteVersions()
{
    Guid noteGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreListNoteVersionsTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             IRequestContextPtr ctxParam) -> QList<NoteVersionId>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listNoteVersionsRequest,
        &helper,
        &NoteStoreListNoteVersionsTesterHelper::onListNoteVersionsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListNoteVersionsTesterHelper::listNoteVersionsRequestReady,
        &server,
        &NoteStoreServer::onListNoteVersionsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listNoteVersionsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<NoteVersionId> res = noteStore->listNoteVersions(
            noteGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteVersion()
{
    Guid noteGuid = generateRandomString();
    qint32 updateSequenceNum = generateRandomInt32();
    bool withResourcesData = generateRandomBool();
    bool withResourcesRecognition = generateRandomBool();
    bool withResourcesAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Note response = generateRandomNote();

    NoteStoreGetNoteVersionTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             qint32 updateSequenceNumParam,
             bool withResourcesDataParam,
             bool withResourcesRecognitionParam,
             bool withResourcesAlternateDataParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(updateSequenceNum == updateSequenceNumParam);
            Q_ASSERT(withResourcesData == withResourcesDataParam);
            Q_ASSERT(withResourcesRecognition == withResourcesRecognitionParam);
            Q_ASSERT(withResourcesAlternateData == withResourcesAlternateDataParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteVersionRequest,
        &helper,
        &NoteStoreGetNoteVersionTesterHelper::onGetNoteVersionRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteVersionTesterHelper::getNoteVersionRequestReady,
        &server,
        &NoteStoreServer::onGetNoteVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteVersionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Note res = noteStore->getNoteVersion(
        noteGuid,
        updateSequenceNum,
        withResourcesData,
        withResourcesRecognition,
        withResourcesAlternateData,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNoteVersion()
{
    Guid noteGuid = generateRandomString();
    qint32 updateSequenceNum = generateRandomInt32();
    bool withResourcesData = generateRandomBool();
    bool withResourcesRecognition = generateRandomBool();
    bool withResourcesAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreGetNoteVersionTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             qint32 updateSequenceNumParam,
             bool withResourcesDataParam,
             bool withResourcesRecognitionParam,
             bool withResourcesAlternateDataParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(updateSequenceNum == updateSequenceNumParam);
            Q_ASSERT(withResourcesData == withResourcesDataParam);
            Q_ASSERT(withResourcesRecognition == withResourcesRecognitionParam);
            Q_ASSERT(withResourcesAlternateData == withResourcesAlternateDataParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteVersionRequest,
        &helper,
        &NoteStoreGetNoteVersionTesterHelper::onGetNoteVersionRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteVersionTesterHelper::getNoteVersionRequestReady,
        &server,
        &NoteStoreServer::onGetNoteVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteVersionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNoteVersion(
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNoteVersion()
{
    Guid noteGuid = generateRandomString();
    qint32 updateSequenceNum = generateRandomInt32();
    bool withResourcesData = generateRandomBool();
    bool withResourcesRecognition = generateRandomBool();
    bool withResourcesAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::AUTH_EXPIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNoteVersionTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             qint32 updateSequenceNumParam,
             bool withResourcesDataParam,
             bool withResourcesRecognitionParam,
             bool withResourcesAlternateDataParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(updateSequenceNum == updateSequenceNumParam);
            Q_ASSERT(withResourcesData == withResourcesDataParam);
            Q_ASSERT(withResourcesRecognition == withResourcesRecognitionParam);
            Q_ASSERT(withResourcesAlternateData == withResourcesAlternateDataParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteVersionRequest,
        &helper,
        &NoteStoreGetNoteVersionTesterHelper::onGetNoteVersionRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteVersionTesterHelper::getNoteVersionRequestReady,
        &server,
        &NoteStoreServer::onGetNoteVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteVersionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNoteVersion(
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNoteVersion()
{
    Guid noteGuid = generateRandomString();
    qint32 updateSequenceNum = generateRandomInt32();
    bool withResourcesData = generateRandomBool();
    bool withResourcesRecognition = generateRandomBool();
    bool withResourcesAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNoteVersionTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             qint32 updateSequenceNumParam,
             bool withResourcesDataParam,
             bool withResourcesRecognitionParam,
             bool withResourcesAlternateDataParam,
             IRequestContextPtr ctxParam) -> Note
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(updateSequenceNum == updateSequenceNumParam);
            Q_ASSERT(withResourcesData == withResourcesDataParam);
            Q_ASSERT(withResourcesRecognition == withResourcesRecognitionParam);
            Q_ASSERT(withResourcesAlternateData == withResourcesAlternateDataParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNoteVersionRequest,
        &helper,
        &NoteStoreGetNoteVersionTesterHelper::onGetNoteVersionRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNoteVersionTesterHelper::getNoteVersionRequestReady,
        &server,
        &NoteStoreServer::onGetNoteVersionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNoteVersionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Note res = noteStore->getNoteVersion(
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResource()
{
    Guid guid = generateRandomString();
    bool withData = generateRandomBool();
    bool withRecognition = generateRandomBool();
    bool withAttributes = generateRandomBool();
    bool withAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Resource response = generateRandomResource();

    NoteStoreGetResourceTesterHelper helper(
        [&] (const Guid & guidParam,
             bool withDataParam,
             bool withRecognitionParam,
             bool withAttributesParam,
             bool withAlternateDataParam,
             IRequestContextPtr ctxParam) -> Resource
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(withData == withDataParam);
            Q_ASSERT(withRecognition == withRecognitionParam);
            Q_ASSERT(withAttributes == withAttributesParam);
            Q_ASSERT(withAlternateData == withAlternateDataParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRequest,
        &helper,
        &NoteStoreGetResourceTesterHelper::onGetResourceRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceTesterHelper::getResourceRequestReady,
        &server,
        &NoteStoreServer::onGetResourceRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Resource res = noteStore->getResource(
        guid,
        withData,
        withRecognition,
        withAttributes,
        withAlternateData,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResource()
{
    Guid guid = generateRandomString();
    bool withData = generateRandomBool();
    bool withRecognition = generateRandomBool();
    bool withAttributes = generateRandomBool();
    bool withAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceTesterHelper helper(
        [&] (const Guid & guidParam,
             bool withDataParam,
             bool withRecognitionParam,
             bool withAttributesParam,
             bool withAlternateDataParam,
             IRequestContextPtr ctxParam) -> Resource
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(withData == withDataParam);
            Q_ASSERT(withRecognition == withRecognitionParam);
            Q_ASSERT(withAttributes == withAttributesParam);
            Q_ASSERT(withAlternateData == withAlternateDataParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRequest,
        &helper,
        &NoteStoreGetResourceTesterHelper::onGetResourceRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceTesterHelper::getResourceRequestReady,
        &server,
        &NoteStoreServer::onGetResourceRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Resource res = noteStore->getResource(
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResource()
{
    Guid guid = generateRandomString();
    bool withData = generateRandomBool();
    bool withRecognition = generateRandomBool();
    bool withAttributes = generateRandomBool();
    bool withAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::USER_NOT_ASSOCIATED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceTesterHelper helper(
        [&] (const Guid & guidParam,
             bool withDataParam,
             bool withRecognitionParam,
             bool withAttributesParam,
             bool withAlternateDataParam,
             IRequestContextPtr ctxParam) -> Resource
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(withData == withDataParam);
            Q_ASSERT(withRecognition == withRecognitionParam);
            Q_ASSERT(withAttributes == withAttributesParam);
            Q_ASSERT(withAlternateData == withAlternateDataParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRequest,
        &helper,
        &NoteStoreGetResourceTesterHelper::onGetResourceRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceTesterHelper::getResourceRequestReady,
        &server,
        &NoteStoreServer::onGetResourceRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Resource res = noteStore->getResource(
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResource()
{
    Guid guid = generateRandomString();
    bool withData = generateRandomBool();
    bool withRecognition = generateRandomBool();
    bool withAttributes = generateRandomBool();
    bool withAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceTesterHelper helper(
        [&] (const Guid & guidParam,
             bool withDataParam,
             bool withRecognitionParam,
             bool withAttributesParam,
             bool withAlternateDataParam,
             IRequestContextPtr ctxParam) -> Resource
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(withData == withDataParam);
            Q_ASSERT(withRecognition == withRecognitionParam);
            Q_ASSERT(withAttributes == withAttributesParam);
            Q_ASSERT(withAlternateData == withAlternateDataParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRequest,
        &helper,
        &NoteStoreGetResourceTesterHelper::onGetResourceRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceTesterHelper::getResourceRequestReady,
        &server,
        &NoteStoreServer::onGetResourceRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Resource res = noteStore->getResource(
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceApplicationData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    LazyMap response = generateRandomLazyMap();

    NoteStoreGetResourceApplicationDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> LazyMap
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataRequest,
        &helper,
        &NoteStoreGetResourceApplicationDataTesterHelper::onGetResourceApplicationDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceApplicationDataTesterHelper::getResourceApplicationDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceApplicationDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    LazyMap res = noteStore->getResourceApplicationData(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResourceApplicationData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LEN_TOO_SHORT;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceApplicationDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> LazyMap
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataRequest,
        &helper,
        &NoteStoreGetResourceApplicationDataTesterHelper::onGetResourceApplicationDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceApplicationDataTesterHelper::getResourceApplicationDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceApplicationDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LazyMap res = noteStore->getResourceApplicationData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResourceApplicationData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceApplicationDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> LazyMap
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataRequest,
        &helper,
        &NoteStoreGetResourceApplicationDataTesterHelper::onGetResourceApplicationDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceApplicationDataTesterHelper::getResourceApplicationDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceApplicationDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LazyMap res = noteStore->getResourceApplicationData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResourceApplicationData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceApplicationDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> LazyMap
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataRequest,
        &helper,
        &NoteStoreGetResourceApplicationDataTesterHelper::onGetResourceApplicationDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceApplicationDataTesterHelper::getResourceApplicationDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceApplicationDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LazyMap res = noteStore->getResourceApplicationData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QString response = generateRandomString();

    NoteStoreGetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreGetResourceApplicationDataEntryTesterHelper::onGetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceApplicationDataEntryTesterHelper::getResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onGetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QString res = noteStore->getResourceApplicationDataEntry(
        guid,
        key,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::SHARD_UNAVAILABLE;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreGetResourceApplicationDataEntryTesterHelper::onGetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceApplicationDataEntryTesterHelper::getResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onGetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getResourceApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::RATE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreGetResourceApplicationDataEntryTesterHelper::onGetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceApplicationDataEntryTesterHelper::getResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onGetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getResourceApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreGetResourceApplicationDataEntryTesterHelper::onGetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceApplicationDataEntryTesterHelper::getResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onGetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->getResourceApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteSetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    QString value = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreSetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             const QString & valueParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            Q_ASSERT(value == valueParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreSetResourceApplicationDataEntryTesterHelper::onSetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetResourceApplicationDataEntryTesterHelper::setResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onSetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->setResourceApplicationDataEntry(
        guid,
        key,
        value,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInSetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    QString value = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNKNOWN;
    userException.parameter = generateRandomString();

    NoteStoreSetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             const QString & valueParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            Q_ASSERT(value == valueParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreSetResourceApplicationDataEntryTesterHelper::onSetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetResourceApplicationDataEntryTesterHelper::setResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onSetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->setResourceApplicationDataEntry(
            guid,
            key,
            value,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInSetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    QString value = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreSetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             const QString & valueParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            Q_ASSERT(value == valueParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreSetResourceApplicationDataEntryTesterHelper::onSetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetResourceApplicationDataEntryTesterHelper::setResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onSetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->setResourceApplicationDataEntry(
            guid,
            key,
            value,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInSetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    QString value = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreSetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             const QString & valueParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            Q_ASSERT(value == valueParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreSetResourceApplicationDataEntryTesterHelper::onSetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetResourceApplicationDataEntryTesterHelper::setResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onSetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->setResourceApplicationDataEntry(
            guid,
            key,
            value,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUnsetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreUnsetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::unsetResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreUnsetResourceApplicationDataEntryTesterHelper::onUnsetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUnsetResourceApplicationDataEntryTesterHelper::unsetResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onUnsetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::unsetResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->unsetResourceApplicationDataEntry(
        guid,
        key,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUnsetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INTERNAL_ERROR;
    userException.parameter = generateRandomString();

    NoteStoreUnsetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::unsetResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreUnsetResourceApplicationDataEntryTesterHelper::onUnsetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUnsetResourceApplicationDataEntryTesterHelper::unsetResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onUnsetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::unsetResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->unsetResourceApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUnsetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TOO_FEW;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUnsetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::unsetResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreUnsetResourceApplicationDataEntryTesterHelper::onUnsetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUnsetResourceApplicationDataEntryTesterHelper::unsetResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onUnsetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::unsetResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->unsetResourceApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUnsetResourceApplicationDataEntry()
{
    Guid guid = generateRandomString();
    QString key = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUnsetResourceApplicationDataEntryTesterHelper helper(
        [&] (const Guid & guidParam,
             const QString & keyParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(key == keyParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::unsetResourceApplicationDataEntryRequest,
        &helper,
        &NoteStoreUnsetResourceApplicationDataEntryTesterHelper::onUnsetResourceApplicationDataEntryRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUnsetResourceApplicationDataEntryTesterHelper::unsetResourceApplicationDataEntryRequestReady,
        &server,
        &NoteStoreServer::onUnsetResourceApplicationDataEntryRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::unsetResourceApplicationDataEntryRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->unsetResourceApplicationDataEntry(
            guid,
            key,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateResource()
{
    Resource resource = generateRandomResource();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreUpdateResourceTesterHelper helper(
        [&] (const Resource & resourceParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(resource == resourceParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateResourceRequest,
        &helper,
        &NoteStoreUpdateResourceTesterHelper::onUpdateResourceRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateResourceTesterHelper::updateResourceRequestReady,
        &server,
        &NoteStoreServer::onUpdateResourceRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateResourceRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->updateResource(
        resource,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUpdateResource()
{
    Resource resource = generateRandomResource();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_NOT_REGISTERED;
    userException.parameter = generateRandomString();

    NoteStoreUpdateResourceTesterHelper helper(
        [&] (const Resource & resourceParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(resource == resourceParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateResourceRequest,
        &helper,
        &NoteStoreUpdateResourceTesterHelper::onUpdateResourceRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateResourceTesterHelper::updateResourceRequestReady,
        &server,
        &NoteStoreServer::onUpdateResourceRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateResourceRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateResource(
            resource,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUpdateResource()
{
    Resource resource = generateRandomResource();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DATA_CONFLICT;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUpdateResourceTesterHelper helper(
        [&] (const Resource & resourceParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(resource == resourceParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateResourceRequest,
        &helper,
        &NoteStoreUpdateResourceTesterHelper::onUpdateResourceRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateResourceTesterHelper::updateResourceRequestReady,
        &server,
        &NoteStoreServer::onUpdateResourceRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateResourceRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateResource(
            resource,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateResource()
{
    Resource resource = generateRandomResource();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUpdateResourceTesterHelper helper(
        [&] (const Resource & resourceParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(resource == resourceParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateResourceRequest,
        &helper,
        &NoteStoreUpdateResourceTesterHelper::onUpdateResourceRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateResourceTesterHelper::updateResourceRequestReady,
        &server,
        &NoteStoreServer::onUpdateResourceRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateResourceRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateResource(
            resource,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QByteArray response = generateRandomString().toUtf8();

    NoteStoreGetResourceDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceDataRequest,
        &helper,
        &NoteStoreGetResourceDataTesterHelper::onGetResourceDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceDataTesterHelper::getResourceDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QByteArray res = noteStore->getResourceData(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResourceData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceDataRequest,
        &helper,
        &NoteStoreGetResourceDataTesterHelper::onGetResourceDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceDataTesterHelper::getResourceDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResourceData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::RATE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceDataRequest,
        &helper,
        &NoteStoreGetResourceDataTesterHelper::onGetResourceDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceDataTesterHelper::getResourceDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResourceData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceDataRequest,
        &helper,
        &NoteStoreGetResourceDataTesterHelper::onGetResourceDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceDataTesterHelper::getResourceDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceByHash()
{
    Guid noteGuid = generateRandomString();
    QByteArray contentHash = generateRandomString().toUtf8();
    bool withData = generateRandomBool();
    bool withRecognition = generateRandomBool();
    bool withAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Resource response = generateRandomResource();

    NoteStoreGetResourceByHashTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             QByteArray contentHashParam,
             bool withDataParam,
             bool withRecognitionParam,
             bool withAlternateDataParam,
             IRequestContextPtr ctxParam) -> Resource
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(contentHash == contentHashParam);
            Q_ASSERT(withData == withDataParam);
            Q_ASSERT(withRecognition == withRecognitionParam);
            Q_ASSERT(withAlternateData == withAlternateDataParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceByHashRequest,
        &helper,
        &NoteStoreGetResourceByHashTesterHelper::onGetResourceByHashRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceByHashTesterHelper::getResourceByHashRequestReady,
        &server,
        &NoteStoreServer::onGetResourceByHashRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceByHashRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Resource res = noteStore->getResourceByHash(
        noteGuid,
        contentHash,
        withData,
        withRecognition,
        withAlternateData,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResourceByHash()
{
    Guid noteGuid = generateRandomString();
    QByteArray contentHash = generateRandomString().toUtf8();
    bool withData = generateRandomBool();
    bool withRecognition = generateRandomBool();
    bool withAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceByHashTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             QByteArray contentHashParam,
             bool withDataParam,
             bool withRecognitionParam,
             bool withAlternateDataParam,
             IRequestContextPtr ctxParam) -> Resource
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(contentHash == contentHashParam);
            Q_ASSERT(withData == withDataParam);
            Q_ASSERT(withRecognition == withRecognitionParam);
            Q_ASSERT(withAlternateData == withAlternateDataParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceByHashRequest,
        &helper,
        &NoteStoreGetResourceByHashTesterHelper::onGetResourceByHashRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceByHashTesterHelper::getResourceByHashRequestReady,
        &server,
        &NoteStoreServer::onGetResourceByHashRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceByHashRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Resource res = noteStore->getResourceByHash(
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResourceByHash()
{
    Guid noteGuid = generateRandomString();
    QByteArray contentHash = generateRandomString().toUtf8();
    bool withData = generateRandomBool();
    bool withRecognition = generateRandomBool();
    bool withAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::ENML_VALIDATION;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceByHashTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             QByteArray contentHashParam,
             bool withDataParam,
             bool withRecognitionParam,
             bool withAlternateDataParam,
             IRequestContextPtr ctxParam) -> Resource
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(contentHash == contentHashParam);
            Q_ASSERT(withData == withDataParam);
            Q_ASSERT(withRecognition == withRecognitionParam);
            Q_ASSERT(withAlternateData == withAlternateDataParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceByHashRequest,
        &helper,
        &NoteStoreGetResourceByHashTesterHelper::onGetResourceByHashRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceByHashTesterHelper::getResourceByHashRequestReady,
        &server,
        &NoteStoreServer::onGetResourceByHashRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceByHashRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Resource res = noteStore->getResourceByHash(
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResourceByHash()
{
    Guid noteGuid = generateRandomString();
    QByteArray contentHash = generateRandomString().toUtf8();
    bool withData = generateRandomBool();
    bool withRecognition = generateRandomBool();
    bool withAlternateData = generateRandomBool();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceByHashTesterHelper helper(
        [&] (const Guid & noteGuidParam,
             QByteArray contentHashParam,
             bool withDataParam,
             bool withRecognitionParam,
             bool withAlternateDataParam,
             IRequestContextPtr ctxParam) -> Resource
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(noteGuid == noteGuidParam);
            Q_ASSERT(contentHash == contentHashParam);
            Q_ASSERT(withData == withDataParam);
            Q_ASSERT(withRecognition == withRecognitionParam);
            Q_ASSERT(withAlternateData == withAlternateDataParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceByHashRequest,
        &helper,
        &NoteStoreGetResourceByHashTesterHelper::onGetResourceByHashRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceByHashTesterHelper::getResourceByHashRequestReady,
        &server,
        &NoteStoreServer::onGetResourceByHashRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceByHashRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Resource res = noteStore->getResourceByHash(
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceRecognition()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QByteArray response = generateRandomString().toUtf8();

    NoteStoreGetResourceRecognitionTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRecognitionRequest,
        &helper,
        &NoteStoreGetResourceRecognitionTesterHelper::onGetResourceRecognitionRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceRecognitionTesterHelper::getResourceRecognitionRequestReady,
        &server,
        &NoteStoreServer::onGetResourceRecognitionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRecognitionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QByteArray res = noteStore->getResourceRecognition(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResourceRecognition()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::DATA_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceRecognitionTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRecognitionRequest,
        &helper,
        &NoteStoreGetResourceRecognitionTesterHelper::onGetResourceRecognitionRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceRecognitionTesterHelper::getResourceRecognitionRequestReady,
        &server,
        &NoteStoreServer::onGetResourceRecognitionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRecognitionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceRecognition(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResourceRecognition()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceRecognitionTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRecognitionRequest,
        &helper,
        &NoteStoreGetResourceRecognitionTesterHelper::onGetResourceRecognitionRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceRecognitionTesterHelper::getResourceRecognitionRequestReady,
        &server,
        &NoteStoreServer::onGetResourceRecognitionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRecognitionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceRecognition(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResourceRecognition()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceRecognitionTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRecognitionRequest,
        &helper,
        &NoteStoreGetResourceRecognitionTesterHelper::onGetResourceRecognitionRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceRecognitionTesterHelper::getResourceRecognitionRequestReady,
        &server,
        &NoteStoreServer::onGetResourceRecognitionRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceRecognitionRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceRecognition(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceAlternateData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QByteArray response = generateRandomString().toUtf8();

    NoteStoreGetResourceAlternateDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAlternateDataRequest,
        &helper,
        &NoteStoreGetResourceAlternateDataTesterHelper::onGetResourceAlternateDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceAlternateDataTesterHelper::getResourceAlternateDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceAlternateDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAlternateDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QByteArray res = noteStore->getResourceAlternateData(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResourceAlternateData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceAlternateDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAlternateDataRequest,
        &helper,
        &NoteStoreGetResourceAlternateDataTesterHelper::onGetResourceAlternateDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceAlternateDataTesterHelper::getResourceAlternateDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceAlternateDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAlternateDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceAlternateData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResourceAlternateData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::OPENID_ALREADY_TAKEN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceAlternateDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAlternateDataRequest,
        &helper,
        &NoteStoreGetResourceAlternateDataTesterHelper::onGetResourceAlternateDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceAlternateDataTesterHelper::getResourceAlternateDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceAlternateDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAlternateDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceAlternateData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResourceAlternateData()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceAlternateDataTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QByteArray
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAlternateDataRequest,
        &helper,
        &NoteStoreGetResourceAlternateDataTesterHelper::onGetResourceAlternateDataRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceAlternateDataTesterHelper::getResourceAlternateDataRequestReady,
        &server,
        &NoteStoreServer::onGetResourceAlternateDataRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAlternateDataRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QByteArray res = noteStore->getResourceAlternateData(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceAttributes()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    ResourceAttributes response = generateRandomResourceAttributes();

    NoteStoreGetResourceAttributesTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> ResourceAttributes
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAttributesRequest,
        &helper,
        &NoteStoreGetResourceAttributesTesterHelper::onGetResourceAttributesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceAttributesTesterHelper::getResourceAttributesRequestReady,
        &server,
        &NoteStoreServer::onGetResourceAttributesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAttributesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    ResourceAttributes res = noteStore->getResourceAttributes(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetResourceAttributes()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_MANY;
    userException.parameter = generateRandomString();

    NoteStoreGetResourceAttributesTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> ResourceAttributes
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAttributesRequest,
        &helper,
        &NoteStoreGetResourceAttributesTesterHelper::onGetResourceAttributesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceAttributesTesterHelper::getResourceAttributesRequestReady,
        &server,
        &NoteStoreServer::onGetResourceAttributesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAttributesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ResourceAttributes res = noteStore->getResourceAttributes(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetResourceAttributes()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetResourceAttributesTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> ResourceAttributes
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAttributesRequest,
        &helper,
        &NoteStoreGetResourceAttributesTesterHelper::onGetResourceAttributesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceAttributesTesterHelper::getResourceAttributesRequestReady,
        &server,
        &NoteStoreServer::onGetResourceAttributesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAttributesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ResourceAttributes res = noteStore->getResourceAttributes(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetResourceAttributes()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetResourceAttributesTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> ResourceAttributes
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAttributesRequest,
        &helper,
        &NoteStoreGetResourceAttributesTesterHelper::onGetResourceAttributesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetResourceAttributesTesterHelper::getResourceAttributesRequestReady,
        &server,
        &NoteStoreServer::onGetResourceAttributesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getResourceAttributesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ResourceAttributes res = noteStore->getResourceAttributes(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetPublicNotebook()
{
    UserID userId = generateRandomInt32();
    QString publicUri = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    Notebook response = generateRandomNotebook();

    NoteStoreGetPublicNotebookTesterHelper helper(
        [&] (const UserID & userIdParam,
             const QString & publicUriParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(userId == userIdParam);
            Q_ASSERT(publicUri == publicUriParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getPublicNotebookRequest,
        &helper,
        &NoteStoreGetPublicNotebookTesterHelper::onGetPublicNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetPublicNotebookTesterHelper::getPublicNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetPublicNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getPublicNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Notebook res = noteStore->getPublicNotebook(
        userId,
        publicUri,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetPublicNotebook()
{
    UserID userId = generateRandomInt32();
    QString publicUri = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::QUOTA_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetPublicNotebookTesterHelper helper(
        [&] (const UserID & userIdParam,
             const QString & publicUriParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(userId == userIdParam);
            Q_ASSERT(publicUri == publicUriParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getPublicNotebookRequest,
        &helper,
        &NoteStoreGetPublicNotebookTesterHelper::onGetPublicNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetPublicNotebookTesterHelper::getPublicNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetPublicNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getPublicNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->getPublicNotebook(
            userId,
            publicUri,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetPublicNotebook()
{
    UserID userId = generateRandomInt32();
    QString publicUri = generateRandomString();
    IRequestContextPtr ctx = newRequestContext();

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetPublicNotebookTesterHelper helper(
        [&] (const UserID & userIdParam,
             const QString & publicUriParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(userId == userIdParam);
            Q_ASSERT(publicUri == publicUriParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getPublicNotebookRequest,
        &helper,
        &NoteStoreGetPublicNotebookTesterHelper::onGetPublicNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetPublicNotebookTesterHelper::getPublicNotebookRequestReady,
        &server,
        &NoteStoreServer::onGetPublicNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getPublicNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->getPublicNotebook(
            userId,
            publicUri,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteShareNotebook()
{
    SharedNotebook sharedNotebook = generateRandomSharedNotebook();
    QString message = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    SharedNotebook response = generateRandomSharedNotebook();

    NoteStoreShareNotebookTesterHelper helper(
        [&] (const SharedNotebook & sharedNotebookParam,
             const QString & messageParam,
             IRequestContextPtr ctxParam) -> SharedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(sharedNotebook == sharedNotebookParam);
            Q_ASSERT(message == messageParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::shareNotebookRequest,
        &helper,
        &NoteStoreShareNotebookTesterHelper::onShareNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreShareNotebookTesterHelper::shareNotebookRequestReady,
        &server,
        &NoteStoreServer::onShareNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::shareNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    SharedNotebook res = noteStore->shareNotebook(
        sharedNotebook,
        message,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInShareNotebook()
{
    SharedNotebook sharedNotebook = generateRandomSharedNotebook();
    QString message = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED;
    userException.parameter = generateRandomString();

    NoteStoreShareNotebookTesterHelper helper(
        [&] (const SharedNotebook & sharedNotebookParam,
             const QString & messageParam,
             IRequestContextPtr ctxParam) -> SharedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(sharedNotebook == sharedNotebookParam);
            Q_ASSERT(message == messageParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::shareNotebookRequest,
        &helper,
        &NoteStoreShareNotebookTesterHelper::onShareNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreShareNotebookTesterHelper::shareNotebookRequestReady,
        &server,
        &NoteStoreServer::onShareNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::shareNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SharedNotebook res = noteStore->shareNotebook(
            sharedNotebook,
            message,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInShareNotebook()
{
    SharedNotebook sharedNotebook = generateRandomSharedNotebook();
    QString message = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreShareNotebookTesterHelper helper(
        [&] (const SharedNotebook & sharedNotebookParam,
             const QString & messageParam,
             IRequestContextPtr ctxParam) -> SharedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(sharedNotebook == sharedNotebookParam);
            Q_ASSERT(message == messageParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::shareNotebookRequest,
        &helper,
        &NoteStoreShareNotebookTesterHelper::onShareNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreShareNotebookTesterHelper::shareNotebookRequestReady,
        &server,
        &NoteStoreServer::onShareNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::shareNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SharedNotebook res = noteStore->shareNotebook(
            sharedNotebook,
            message,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInShareNotebook()
{
    SharedNotebook sharedNotebook = generateRandomSharedNotebook();
    QString message = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INVALID_AUTH;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreShareNotebookTesterHelper helper(
        [&] (const SharedNotebook & sharedNotebookParam,
             const QString & messageParam,
             IRequestContextPtr ctxParam) -> SharedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(sharedNotebook == sharedNotebookParam);
            Q_ASSERT(message == messageParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::shareNotebookRequest,
        &helper,
        &NoteStoreShareNotebookTesterHelper::onShareNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreShareNotebookTesterHelper::shareNotebookRequestReady,
        &server,
        &NoteStoreServer::onShareNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::shareNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SharedNotebook res = noteStore->shareNotebook(
            sharedNotebook,
            message,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateOrUpdateNotebookShares()
{
    NotebookShareTemplate shareTemplate = generateRandomNotebookShareTemplate();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    CreateOrUpdateNotebookSharesResult response = generateRandomCreateOrUpdateNotebookSharesResult();

    NoteStoreCreateOrUpdateNotebookSharesTesterHelper helper(
        [&] (const NotebookShareTemplate & shareTemplateParam,
             IRequestContextPtr ctxParam) -> CreateOrUpdateNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(shareTemplate == shareTemplateParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequest,
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::onCreateOrUpdateNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::createOrUpdateNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    CreateOrUpdateNotebookSharesResult res = noteStore->createOrUpdateNotebookShares(
        shareTemplate,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInCreateOrUpdateNotebookShares()
{
    NotebookShareTemplate shareTemplate = generateRandomNotebookShareTemplate();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNSUPPORTED_OPERATION;
    userException.parameter = generateRandomString();

    NoteStoreCreateOrUpdateNotebookSharesTesterHelper helper(
        [&] (const NotebookShareTemplate & shareTemplateParam,
             IRequestContextPtr ctxParam) -> CreateOrUpdateNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(shareTemplate == shareTemplateParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequest,
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::onCreateOrUpdateNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::createOrUpdateNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        CreateOrUpdateNotebookSharesResult res = noteStore->createOrUpdateNotebookShares(
            shareTemplate,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInCreateOrUpdateNotebookShares()
{
    NotebookShareTemplate shareTemplate = generateRandomNotebookShareTemplate();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreCreateOrUpdateNotebookSharesTesterHelper helper(
        [&] (const NotebookShareTemplate & shareTemplateParam,
             IRequestContextPtr ctxParam) -> CreateOrUpdateNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(shareTemplate == shareTemplateParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequest,
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::onCreateOrUpdateNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::createOrUpdateNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        CreateOrUpdateNotebookSharesResult res = noteStore->createOrUpdateNotebookShares(
            shareTemplate,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInCreateOrUpdateNotebookShares()
{
    NotebookShareTemplate shareTemplate = generateRandomNotebookShareTemplate();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreCreateOrUpdateNotebookSharesTesterHelper helper(
        [&] (const NotebookShareTemplate & shareTemplateParam,
             IRequestContextPtr ctxParam) -> CreateOrUpdateNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(shareTemplate == shareTemplateParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequest,
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::onCreateOrUpdateNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::createOrUpdateNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        CreateOrUpdateNotebookSharesResult res = noteStore->createOrUpdateNotebookShares(
            shareTemplate,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMInvalidContactsExceptionInCreateOrUpdateNotebookShares()
{
    NotebookShareTemplate shareTemplate = generateRandomNotebookShareTemplate();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto invalidContactsException = EDAMInvalidContactsException();
    invalidContactsException.contacts << generateRandomContact();
    invalidContactsException.contacts << generateRandomContact();
    invalidContactsException.contacts << generateRandomContact();
    invalidContactsException.parameter = generateRandomString();
    invalidContactsException.reasons = QList<EDAMInvalidContactReason>();
    invalidContactsException.reasons.ref() << EDAMInvalidContactReason::BAD_ADDRESS;
    invalidContactsException.reasons.ref() << EDAMInvalidContactReason::NO_CONNECTION;
    invalidContactsException.reasons.ref() << EDAMInvalidContactReason::NO_CONNECTION;

    NoteStoreCreateOrUpdateNotebookSharesTesterHelper helper(
        [&] (const NotebookShareTemplate & shareTemplateParam,
             IRequestContextPtr ctxParam) -> CreateOrUpdateNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(shareTemplate == shareTemplateParam);
            throw invalidContactsException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequest,
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::onCreateOrUpdateNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateOrUpdateNotebookSharesTesterHelper::createOrUpdateNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createOrUpdateNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        CreateOrUpdateNotebookSharesResult res = noteStore->createOrUpdateNotebookShares(
            shareTemplate,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMInvalidContactsException & e)
    {
        caughtException = true;
        QVERIFY(e == invalidContactsException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateSharedNotebook()
{
    SharedNotebook sharedNotebook = generateRandomSharedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreUpdateSharedNotebookTesterHelper helper(
        [&] (const SharedNotebook & sharedNotebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(sharedNotebook == sharedNotebookParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateSharedNotebookRequest,
        &helper,
        &NoteStoreUpdateSharedNotebookTesterHelper::onUpdateSharedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateSharedNotebookTesterHelper::updateSharedNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateSharedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateSharedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->updateSharedNotebook(
        sharedNotebook,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUpdateSharedNotebook()
{
    SharedNotebook sharedNotebook = generateRandomSharedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_MANY;
    userException.parameter = generateRandomString();

    NoteStoreUpdateSharedNotebookTesterHelper helper(
        [&] (const SharedNotebook & sharedNotebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(sharedNotebook == sharedNotebookParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateSharedNotebookRequest,
        &helper,
        &NoteStoreUpdateSharedNotebookTesterHelper::onUpdateSharedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateSharedNotebookTesterHelper::updateSharedNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateSharedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateSharedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateSharedNotebook(
            sharedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateSharedNotebook()
{
    SharedNotebook sharedNotebook = generateRandomSharedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUpdateSharedNotebookTesterHelper helper(
        [&] (const SharedNotebook & sharedNotebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(sharedNotebook == sharedNotebookParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateSharedNotebookRequest,
        &helper,
        &NoteStoreUpdateSharedNotebookTesterHelper::onUpdateSharedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateSharedNotebookTesterHelper::updateSharedNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateSharedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateSharedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateSharedNotebook(
            sharedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUpdateSharedNotebook()
{
    SharedNotebook sharedNotebook = generateRandomSharedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::BAD_DATA_FORMAT;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUpdateSharedNotebookTesterHelper helper(
        [&] (const SharedNotebook & sharedNotebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(sharedNotebook == sharedNotebookParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateSharedNotebookRequest,
        &helper,
        &NoteStoreUpdateSharedNotebookTesterHelper::onUpdateSharedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateSharedNotebookTesterHelper::updateSharedNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateSharedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateSharedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateSharedNotebook(
            sharedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteSetNotebookRecipientSettings()
{
    QString notebookGuid = generateRandomString();
    NotebookRecipientSettings recipientSettings = generateRandomNotebookRecipientSettings();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    Notebook response = generateRandomNotebook();

    NoteStoreSetNotebookRecipientSettingsTesterHelper helper(
        [&] (const QString & notebookGuidParam,
             const NotebookRecipientSettings & recipientSettingsParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            Q_ASSERT(recipientSettings == recipientSettingsParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setNotebookRecipientSettingsRequest,
        &helper,
        &NoteStoreSetNotebookRecipientSettingsTesterHelper::onSetNotebookRecipientSettingsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetNotebookRecipientSettingsTesterHelper::setNotebookRecipientSettingsRequestReady,
        &server,
        &NoteStoreServer::onSetNotebookRecipientSettingsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setNotebookRecipientSettingsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    Notebook res = noteStore->setNotebookRecipientSettings(
        notebookGuid,
        recipientSettings,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInSetNotebookRecipientSettings()
{
    QString notebookGuid = generateRandomString();
    NotebookRecipientSettings recipientSettings = generateRandomNotebookRecipientSettings();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_ALREADY_ASSOCIATED;
    userException.parameter = generateRandomString();

    NoteStoreSetNotebookRecipientSettingsTesterHelper helper(
        [&] (const QString & notebookGuidParam,
             const NotebookRecipientSettings & recipientSettingsParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            Q_ASSERT(recipientSettings == recipientSettingsParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setNotebookRecipientSettingsRequest,
        &helper,
        &NoteStoreSetNotebookRecipientSettingsTesterHelper::onSetNotebookRecipientSettingsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetNotebookRecipientSettingsTesterHelper::setNotebookRecipientSettingsRequestReady,
        &server,
        &NoteStoreServer::onSetNotebookRecipientSettingsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setNotebookRecipientSettingsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->setNotebookRecipientSettings(
            notebookGuid,
            recipientSettings,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInSetNotebookRecipientSettings()
{
    QString notebookGuid = generateRandomString();
    NotebookRecipientSettings recipientSettings = generateRandomNotebookRecipientSettings();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreSetNotebookRecipientSettingsTesterHelper helper(
        [&] (const QString & notebookGuidParam,
             const NotebookRecipientSettings & recipientSettingsParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            Q_ASSERT(recipientSettings == recipientSettingsParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setNotebookRecipientSettingsRequest,
        &helper,
        &NoteStoreSetNotebookRecipientSettingsTesterHelper::onSetNotebookRecipientSettingsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetNotebookRecipientSettingsTesterHelper::setNotebookRecipientSettingsRequestReady,
        &server,
        &NoteStoreServer::onSetNotebookRecipientSettingsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setNotebookRecipientSettingsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->setNotebookRecipientSettings(
            notebookGuid,
            recipientSettings,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInSetNotebookRecipientSettings()
{
    QString notebookGuid = generateRandomString();
    NotebookRecipientSettings recipientSettings = generateRandomNotebookRecipientSettings();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::SHARD_UNAVAILABLE;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreSetNotebookRecipientSettingsTesterHelper helper(
        [&] (const QString & notebookGuidParam,
             const NotebookRecipientSettings & recipientSettingsParam,
             IRequestContextPtr ctxParam) -> Notebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            Q_ASSERT(recipientSettings == recipientSettingsParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::setNotebookRecipientSettingsRequest,
        &helper,
        &NoteStoreSetNotebookRecipientSettingsTesterHelper::onSetNotebookRecipientSettingsRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreSetNotebookRecipientSettingsTesterHelper::setNotebookRecipientSettingsRequestReady,
        &server,
        &NoteStoreServer::onSetNotebookRecipientSettingsRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::setNotebookRecipientSettingsRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        Notebook res = noteStore->setNotebookRecipientSettings(
            notebookGuid,
            recipientSettings,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListSharedNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<SharedNotebook> response;
    response << generateRandomSharedNotebook();
    response << generateRandomSharedNotebook();
    response << generateRandomSharedNotebook();

    NoteStoreListSharedNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<SharedNotebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listSharedNotebooksRequest,
        &helper,
        &NoteStoreListSharedNotebooksTesterHelper::onListSharedNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListSharedNotebooksTesterHelper::listSharedNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListSharedNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listSharedNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QList<SharedNotebook> res = noteStore->listSharedNotebooks(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInListSharedNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::UNKNOWN;
    userException.parameter = generateRandomString();

    NoteStoreListSharedNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<SharedNotebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listSharedNotebooksRequest,
        &helper,
        &NoteStoreListSharedNotebooksTesterHelper::onListSharedNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListSharedNotebooksTesterHelper::listSharedNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListSharedNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listSharedNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<SharedNotebook> res = noteStore->listSharedNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInListSharedNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreListSharedNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<SharedNotebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listSharedNotebooksRequest,
        &helper,
        &NoteStoreListSharedNotebooksTesterHelper::onListSharedNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListSharedNotebooksTesterHelper::listSharedNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListSharedNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listSharedNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<SharedNotebook> res = noteStore->listSharedNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInListSharedNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreListSharedNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<SharedNotebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listSharedNotebooksRequest,
        &helper,
        &NoteStoreListSharedNotebooksTesterHelper::onListSharedNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListSharedNotebooksTesterHelper::listSharedNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListSharedNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listSharedNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<SharedNotebook> res = noteStore->listSharedNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateLinkedNotebook()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    LinkedNotebook response = generateRandomLinkedNotebook();

    NoteStoreCreateLinkedNotebookTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> LinkedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createLinkedNotebookRequest,
        &helper,
        &NoteStoreCreateLinkedNotebookTesterHelper::onCreateLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateLinkedNotebookTesterHelper::createLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onCreateLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    LinkedNotebook res = noteStore->createLinkedNotebook(
        linkedNotebook,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInCreateLinkedNotebook()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    userException.parameter = generateRandomString();

    NoteStoreCreateLinkedNotebookTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> LinkedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createLinkedNotebookRequest,
        &helper,
        &NoteStoreCreateLinkedNotebookTesterHelper::onCreateLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateLinkedNotebookTesterHelper::createLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onCreateLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LinkedNotebook res = noteStore->createLinkedNotebook(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInCreateLinkedNotebook()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreCreateLinkedNotebookTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> LinkedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createLinkedNotebookRequest,
        &helper,
        &NoteStoreCreateLinkedNotebookTesterHelper::onCreateLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateLinkedNotebookTesterHelper::createLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onCreateLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LinkedNotebook res = noteStore->createLinkedNotebook(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInCreateLinkedNotebook()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::UNKNOWN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreCreateLinkedNotebookTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> LinkedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::createLinkedNotebookRequest,
        &helper,
        &NoteStoreCreateLinkedNotebookTesterHelper::onCreateLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreCreateLinkedNotebookTesterHelper::createLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onCreateLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::createLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        LinkedNotebook res = noteStore->createLinkedNotebook(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateLinkedNotebook()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreUpdateLinkedNotebookTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateLinkedNotebookRequest,
        &helper,
        &NoteStoreUpdateLinkedNotebookTesterHelper::onUpdateLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateLinkedNotebookTesterHelper::updateLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->updateLinkedNotebook(
        linkedNotebook,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUpdateLinkedNotebook()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    userException.parameter = generateRandomString();

    NoteStoreUpdateLinkedNotebookTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateLinkedNotebookRequest,
        &helper,
        &NoteStoreUpdateLinkedNotebookTesterHelper::onUpdateLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateLinkedNotebookTesterHelper::updateLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateLinkedNotebook(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateLinkedNotebook()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUpdateLinkedNotebookTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateLinkedNotebookRequest,
        &helper,
        &NoteStoreUpdateLinkedNotebookTesterHelper::onUpdateLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateLinkedNotebookTesterHelper::updateLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateLinkedNotebook(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUpdateLinkedNotebook()
{
    LinkedNotebook linkedNotebook = generateRandomLinkedNotebook();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TAKEN_DOWN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUpdateLinkedNotebookTesterHelper helper(
        [&] (const LinkedNotebook & linkedNotebookParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(linkedNotebook == linkedNotebookParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateLinkedNotebookRequest,
        &helper,
        &NoteStoreUpdateLinkedNotebookTesterHelper::onUpdateLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateLinkedNotebookTesterHelper::updateLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onUpdateLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->updateLinkedNotebook(
            linkedNotebook,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListLinkedNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QList<LinkedNotebook> response;
    response << generateRandomLinkedNotebook();
    response << generateRandomLinkedNotebook();
    response << generateRandomLinkedNotebook();

    NoteStoreListLinkedNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<LinkedNotebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listLinkedNotebooksRequest,
        &helper,
        &NoteStoreListLinkedNotebooksTesterHelper::onListLinkedNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListLinkedNotebooksTesterHelper::listLinkedNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListLinkedNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listLinkedNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QList<LinkedNotebook> res = noteStore->listLinkedNotebooks(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInListLinkedNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ACCOUNT_CLEAR;
    userException.parameter = generateRandomString();

    NoteStoreListLinkedNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<LinkedNotebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listLinkedNotebooksRequest,
        &helper,
        &NoteStoreListLinkedNotebooksTesterHelper::onListLinkedNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListLinkedNotebooksTesterHelper::listLinkedNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListLinkedNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listLinkedNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<LinkedNotebook> res = noteStore->listLinkedNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInListLinkedNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreListLinkedNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<LinkedNotebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listLinkedNotebooksRequest,
        &helper,
        &NoteStoreListLinkedNotebooksTesterHelper::onListLinkedNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListLinkedNotebooksTesterHelper::listLinkedNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListLinkedNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listLinkedNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<LinkedNotebook> res = noteStore->listLinkedNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInListLinkedNotebooks()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreListLinkedNotebooksTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> QList<LinkedNotebook>
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::listLinkedNotebooksRequest,
        &helper,
        &NoteStoreListLinkedNotebooksTesterHelper::onListLinkedNotebooksRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreListLinkedNotebooksTesterHelper::listLinkedNotebooksRequestReady,
        &server,
        &NoteStoreServer::onListLinkedNotebooksRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::listLinkedNotebooksRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QList<LinkedNotebook> res = noteStore->listLinkedNotebooks(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeLinkedNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    qint32 response = generateRandomInt32();

    NoteStoreExpungeLinkedNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeLinkedNotebookRequest,
        &helper,
        &NoteStoreExpungeLinkedNotebookTesterHelper::onExpungeLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeLinkedNotebookTesterHelper::expungeLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onExpungeLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    qint32 res = noteStore->expungeLinkedNotebook(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInExpungeLinkedNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ENML_VALIDATION;
    userException.parameter = generateRandomString();

    NoteStoreExpungeLinkedNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeLinkedNotebookRequest,
        &helper,
        &NoteStoreExpungeLinkedNotebookTesterHelper::onExpungeLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeLinkedNotebookTesterHelper::expungeLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onExpungeLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeLinkedNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInExpungeLinkedNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreExpungeLinkedNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeLinkedNotebookRequest,
        &helper,
        &NoteStoreExpungeLinkedNotebookTesterHelper::onExpungeLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeLinkedNotebookTesterHelper::expungeLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onExpungeLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeLinkedNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInExpungeLinkedNotebook()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreExpungeLinkedNotebookTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> qint32
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::expungeLinkedNotebookRequest,
        &helper,
        &NoteStoreExpungeLinkedNotebookTesterHelper::onExpungeLinkedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreExpungeLinkedNotebookTesterHelper::expungeLinkedNotebookRequestReady,
        &server,
        &NoteStoreServer::onExpungeLinkedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::expungeLinkedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        qint32 res = noteStore->expungeLinkedNotebook(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteAuthenticateToSharedNotebook()
{
    QString shareKeyOrGlobalId = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    AuthenticationResult response = generateRandomAuthenticationResult();

    NoteStoreAuthenticateToSharedNotebookTesterHelper helper(
        [&] (const QString & shareKeyOrGlobalIdParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(shareKeyOrGlobalId == shareKeyOrGlobalIdParam);
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNotebookRequest,
        &helper,
        &NoteStoreAuthenticateToSharedNotebookTesterHelper::onAuthenticateToSharedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreAuthenticateToSharedNotebookTesterHelper::authenticateToSharedNotebookRequestReady,
        &server,
        &NoteStoreServer::onAuthenticateToSharedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    AuthenticationResult res = noteStore->authenticateToSharedNotebook(
        shareKeyOrGlobalId,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInAuthenticateToSharedNotebook()
{
    QString shareKeyOrGlobalId = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    userException.parameter = generateRandomString();

    NoteStoreAuthenticateToSharedNotebookTesterHelper helper(
        [&] (const QString & shareKeyOrGlobalIdParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(shareKeyOrGlobalId == shareKeyOrGlobalIdParam);
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNotebookRequest,
        &helper,
        &NoteStoreAuthenticateToSharedNotebookTesterHelper::onAuthenticateToSharedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreAuthenticateToSharedNotebookTesterHelper::authenticateToSharedNotebookRequestReady,
        &server,
        &NoteStoreServer::onAuthenticateToSharedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = noteStore->authenticateToSharedNotebook(
            shareKeyOrGlobalId,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInAuthenticateToSharedNotebook()
{
    QString shareKeyOrGlobalId = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreAuthenticateToSharedNotebookTesterHelper helper(
        [&] (const QString & shareKeyOrGlobalIdParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(shareKeyOrGlobalId == shareKeyOrGlobalIdParam);
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNotebookRequest,
        &helper,
        &NoteStoreAuthenticateToSharedNotebookTesterHelper::onAuthenticateToSharedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreAuthenticateToSharedNotebookTesterHelper::authenticateToSharedNotebookRequestReady,
        &server,
        &NoteStoreServer::onAuthenticateToSharedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = noteStore->authenticateToSharedNotebook(
            shareKeyOrGlobalId,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInAuthenticateToSharedNotebook()
{
    QString shareKeyOrGlobalId = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::TOO_FEW;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreAuthenticateToSharedNotebookTesterHelper helper(
        [&] (const QString & shareKeyOrGlobalIdParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(shareKeyOrGlobalId == shareKeyOrGlobalIdParam);
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNotebookRequest,
        &helper,
        &NoteStoreAuthenticateToSharedNotebookTesterHelper::onAuthenticateToSharedNotebookRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreAuthenticateToSharedNotebookTesterHelper::authenticateToSharedNotebookRequestReady,
        &server,
        &NoteStoreServer::onAuthenticateToSharedNotebookRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNotebookRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = noteStore->authenticateToSharedNotebook(
            shareKeyOrGlobalId,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetSharedNotebookByAuth()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    SharedNotebook response = generateRandomSharedNotebook();

    NoteStoreGetSharedNotebookByAuthTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> SharedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSharedNotebookByAuthRequest,
        &helper,
        &NoteStoreGetSharedNotebookByAuthTesterHelper::onGetSharedNotebookByAuthRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSharedNotebookByAuthTesterHelper::getSharedNotebookByAuthRequestReady,
        &server,
        &NoteStoreServer::onGetSharedNotebookByAuthRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSharedNotebookByAuthRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    SharedNotebook res = noteStore->getSharedNotebookByAuth(
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetSharedNotebookByAuth()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::TOO_MANY;
    userException.parameter = generateRandomString();

    NoteStoreGetSharedNotebookByAuthTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> SharedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSharedNotebookByAuthRequest,
        &helper,
        &NoteStoreGetSharedNotebookByAuthTesterHelper::onGetSharedNotebookByAuthRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSharedNotebookByAuthTesterHelper::getSharedNotebookByAuthRequestReady,
        &server,
        &NoteStoreServer::onGetSharedNotebookByAuthRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSharedNotebookByAuthRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SharedNotebook res = noteStore->getSharedNotebookByAuth(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetSharedNotebookByAuth()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetSharedNotebookByAuthTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> SharedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSharedNotebookByAuthRequest,
        &helper,
        &NoteStoreGetSharedNotebookByAuthTesterHelper::onGetSharedNotebookByAuthRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSharedNotebookByAuthTesterHelper::getSharedNotebookByAuthRequestReady,
        &server,
        &NoteStoreServer::onGetSharedNotebookByAuthRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSharedNotebookByAuthRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SharedNotebook res = noteStore->getSharedNotebookByAuth(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetSharedNotebookByAuth()
{
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DATA_CONFLICT;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetSharedNotebookByAuthTesterHelper helper(
        [&] (IRequestContextPtr ctxParam) -> SharedNotebook
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getSharedNotebookByAuthRequest,
        &helper,
        &NoteStoreGetSharedNotebookByAuthTesterHelper::onGetSharedNotebookByAuthRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetSharedNotebookByAuthTesterHelper::getSharedNotebookByAuthRequestReady,
        &server,
        &NoteStoreServer::onGetSharedNotebookByAuthRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getSharedNotebookByAuthRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        SharedNotebook res = noteStore->getSharedNotebookByAuth(
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteEmailNote()
{
    NoteEmailParameters parameters = generateRandomNoteEmailParameters();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    NoteStoreEmailNoteTesterHelper helper(
        [&] (const NoteEmailParameters & parametersParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(parameters == parametersParam);
            return;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::emailNoteRequest,
        &helper,
        &NoteStoreEmailNoteTesterHelper::onEmailNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreEmailNoteTesterHelper::emailNoteRequestReady,
        &server,
        &NoteStoreServer::onEmailNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::emailNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    noteStore->emailNote(
        parameters,
        ctx);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInEmailNote()
{
    NoteEmailParameters parameters = generateRandomNoteEmailParameters();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::INVALID_AUTH;
    userException.parameter = generateRandomString();

    NoteStoreEmailNoteTesterHelper helper(
        [&] (const NoteEmailParameters & parametersParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(parameters == parametersParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::emailNoteRequest,
        &helper,
        &NoteStoreEmailNoteTesterHelper::onEmailNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreEmailNoteTesterHelper::emailNoteRequestReady,
        &server,
        &NoteStoreServer::onEmailNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::emailNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->emailNote(
            parameters,
            ctx);
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInEmailNote()
{
    NoteEmailParameters parameters = generateRandomNoteEmailParameters();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreEmailNoteTesterHelper helper(
        [&] (const NoteEmailParameters & parametersParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(parameters == parametersParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::emailNoteRequest,
        &helper,
        &NoteStoreEmailNoteTesterHelper::onEmailNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreEmailNoteTesterHelper::emailNoteRequestReady,
        &server,
        &NoteStoreServer::onEmailNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::emailNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->emailNote(
            parameters,
            ctx);
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInEmailNote()
{
    NoteEmailParameters parameters = generateRandomNoteEmailParameters();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INTERNAL_ERROR;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreEmailNoteTesterHelper helper(
        [&] (const NoteEmailParameters & parametersParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(parameters == parametersParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::emailNoteRequest,
        &helper,
        &NoteStoreEmailNoteTesterHelper::onEmailNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreEmailNoteTesterHelper::emailNoteRequestReady,
        &server,
        &NoteStoreServer::onEmailNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::emailNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->emailNote(
            parameters,
            ctx);
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteShareNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    QString response = generateRandomString();

    NoteStoreShareNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::shareNoteRequest,
        &helper,
        &NoteStoreShareNoteTesterHelper::onShareNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreShareNoteTesterHelper::shareNoteRequestReady,
        &server,
        &NoteStoreServer::onShareNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::shareNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    QString res = noteStore->shareNote(
        guid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInShareNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    userException.parameter = generateRandomString();

    NoteStoreShareNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::shareNoteRequest,
        &helper,
        &NoteStoreShareNoteTesterHelper::onShareNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreShareNoteTesterHelper::shareNoteRequestReady,
        &server,
        &NoteStoreServer::onShareNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::shareNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->shareNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInShareNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreShareNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::shareNoteRequest,
        &helper,
        &NoteStoreShareNoteTesterHelper::onShareNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreShareNoteTesterHelper::shareNoteRequestReady,
        &server,
        &NoteStoreServer::onShareNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::shareNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->shareNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInShareNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::QUOTA_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreShareNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> QString
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::shareNoteRequest,
        &helper,
        &NoteStoreShareNoteTesterHelper::onShareNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreShareNoteTesterHelper::shareNoteRequestReady,
        &server,
        &NoteStoreServer::onShareNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::shareNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        QString res = noteStore->shareNote(
            guid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteStopSharingNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    NoteStoreStopSharingNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            return;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::stopSharingNoteRequest,
        &helper,
        &NoteStoreStopSharingNoteTesterHelper::onStopSharingNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreStopSharingNoteTesterHelper::stopSharingNoteRequestReady,
        &server,
        &NoteStoreServer::onStopSharingNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::stopSharingNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    noteStore->stopSharingNote(
        guid,
        ctx);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInStopSharingNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::AUTH_EXPIRED;
    userException.parameter = generateRandomString();

    NoteStoreStopSharingNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::stopSharingNoteRequest,
        &helper,
        &NoteStoreStopSharingNoteTesterHelper::onStopSharingNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreStopSharingNoteTesterHelper::stopSharingNoteRequestReady,
        &server,
        &NoteStoreServer::onStopSharingNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::stopSharingNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->stopSharingNote(
            guid,
            ctx);
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInStopSharingNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreStopSharingNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::stopSharingNoteRequest,
        &helper,
        &NoteStoreStopSharingNoteTesterHelper::onStopSharingNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreStopSharingNoteTesterHelper::stopSharingNoteRequestReady,
        &server,
        &NoteStoreServer::onStopSharingNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::stopSharingNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->stopSharingNote(
            guid,
            ctx);
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInStopSharingNote()
{
    Guid guid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DATA_CONFLICT;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreStopSharingNoteTesterHelper helper(
        [&] (const Guid & guidParam,
             IRequestContextPtr ctxParam) -> void
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(guid == guidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::stopSharingNoteRequest,
        &helper,
        &NoteStoreStopSharingNoteTesterHelper::onStopSharingNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreStopSharingNoteTesterHelper::stopSharingNoteRequestReady,
        &server,
        &NoteStoreServer::onStopSharingNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::stopSharingNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        noteStore->stopSharingNote(
            guid,
            ctx);
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteAuthenticateToSharedNote()
{
    QString guid = generateRandomString();
    QString noteKey = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    AuthenticationResult response = generateRandomAuthenticationResult();

    NoteStoreAuthenticateToSharedNoteTesterHelper helper(
        [&] (const QString & guidParam,
             const QString & noteKeyParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(noteKey == noteKeyParam);
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNoteRequest,
        &helper,
        &NoteStoreAuthenticateToSharedNoteTesterHelper::onAuthenticateToSharedNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreAuthenticateToSharedNoteTesterHelper::authenticateToSharedNoteRequestReady,
        &server,
        &NoteStoreServer::onAuthenticateToSharedNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    AuthenticationResult res = noteStore->authenticateToSharedNote(
        guid,
        noteKey,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInAuthenticateToSharedNote()
{
    QString guid = generateRandomString();
    QString noteKey = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::LIMIT_REACHED;
    userException.parameter = generateRandomString();

    NoteStoreAuthenticateToSharedNoteTesterHelper helper(
        [&] (const QString & guidParam,
             const QString & noteKeyParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(noteKey == noteKeyParam);
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNoteRequest,
        &helper,
        &NoteStoreAuthenticateToSharedNoteTesterHelper::onAuthenticateToSharedNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreAuthenticateToSharedNoteTesterHelper::authenticateToSharedNoteRequestReady,
        &server,
        &NoteStoreServer::onAuthenticateToSharedNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = noteStore->authenticateToSharedNote(
            guid,
            noteKey,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInAuthenticateToSharedNote()
{
    QString guid = generateRandomString();
    QString noteKey = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreAuthenticateToSharedNoteTesterHelper helper(
        [&] (const QString & guidParam,
             const QString & noteKeyParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(noteKey == noteKeyParam);
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNoteRequest,
        &helper,
        &NoteStoreAuthenticateToSharedNoteTesterHelper::onAuthenticateToSharedNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreAuthenticateToSharedNoteTesterHelper::authenticateToSharedNoteRequestReady,
        &server,
        &NoteStoreServer::onAuthenticateToSharedNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = noteStore->authenticateToSharedNote(
            guid,
            noteKey,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInAuthenticateToSharedNote()
{
    QString guid = generateRandomString();
    QString noteKey = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::SSO_AUTHENTICATION_REQUIRED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreAuthenticateToSharedNoteTesterHelper helper(
        [&] (const QString & guidParam,
             const QString & noteKeyParam,
             IRequestContextPtr ctxParam) -> AuthenticationResult
        {
            Q_ASSERT(guid == guidParam);
            Q_ASSERT(noteKey == noteKeyParam);
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNoteRequest,
        &helper,
        &NoteStoreAuthenticateToSharedNoteTesterHelper::onAuthenticateToSharedNoteRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreAuthenticateToSharedNoteTesterHelper::authenticateToSharedNoteRequestReady,
        &server,
        &NoteStoreServer::onAuthenticateToSharedNoteRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::authenticateToSharedNoteRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        AuthenticationResult res = noteStore->authenticateToSharedNote(
            guid,
            noteKey,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteFindRelated()
{
    RelatedQuery query = generateRandomRelatedQuery();
    RelatedResultSpec resultSpec = generateRandomRelatedResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    RelatedResult response = generateRandomRelatedResult();

    NoteStoreFindRelatedTesterHelper helper(
        [&] (const RelatedQuery & queryParam,
             const RelatedResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> RelatedResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(query == queryParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findRelatedRequest,
        &helper,
        &NoteStoreFindRelatedTesterHelper::onFindRelatedRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindRelatedTesterHelper::findRelatedRequestReady,
        &server,
        &NoteStoreServer::onFindRelatedRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findRelatedRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    RelatedResult res = noteStore->findRelated(
        query,
        resultSpec,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInFindRelated()
{
    RelatedQuery query = generateRandomRelatedQuery();
    RelatedResultSpec resultSpec = generateRandomRelatedResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::USER_ALREADY_ASSOCIATED;
    userException.parameter = generateRandomString();

    NoteStoreFindRelatedTesterHelper helper(
        [&] (const RelatedQuery & queryParam,
             const RelatedResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> RelatedResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(query == queryParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findRelatedRequest,
        &helper,
        &NoteStoreFindRelatedTesterHelper::onFindRelatedRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindRelatedTesterHelper::findRelatedRequestReady,
        &server,
        &NoteStoreServer::onFindRelatedRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findRelatedRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        RelatedResult res = noteStore->findRelated(
            query,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInFindRelated()
{
    RelatedQuery query = generateRandomRelatedQuery();
    RelatedResultSpec resultSpec = generateRandomRelatedResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::DEVICE_LIMIT_REACHED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreFindRelatedTesterHelper helper(
        [&] (const RelatedQuery & queryParam,
             const RelatedResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> RelatedResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(query == queryParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findRelatedRequest,
        &helper,
        &NoteStoreFindRelatedTesterHelper::onFindRelatedRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindRelatedTesterHelper::findRelatedRequestReady,
        &server,
        &NoteStoreServer::onFindRelatedRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findRelatedRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        RelatedResult res = noteStore->findRelated(
            query,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInFindRelated()
{
    RelatedQuery query = generateRandomRelatedQuery();
    RelatedResultSpec resultSpec = generateRandomRelatedResultSpec();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreFindRelatedTesterHelper helper(
        [&] (const RelatedQuery & queryParam,
             const RelatedResultSpec & resultSpecParam,
             IRequestContextPtr ctxParam) -> RelatedResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(query == queryParam);
            Q_ASSERT(resultSpec == resultSpecParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::findRelatedRequest,
        &helper,
        &NoteStoreFindRelatedTesterHelper::onFindRelatedRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreFindRelatedTesterHelper::findRelatedRequestReady,
        &server,
        &NoteStoreServer::onFindRelatedRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::findRelatedRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        RelatedResult res = noteStore->findRelated(
            query,
            resultSpec,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateNoteIfUsnMatches()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    UpdateNoteIfUsnMatchesResult response = generateRandomUpdateNoteIfUsnMatchesResult();

    NoteStoreUpdateNoteIfUsnMatchesTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> UpdateNoteIfUsnMatchesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteIfUsnMatchesRequest,
        &helper,
        &NoteStoreUpdateNoteIfUsnMatchesTesterHelper::onUpdateNoteIfUsnMatchesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNoteIfUsnMatchesTesterHelper::updateNoteIfUsnMatchesRequestReady,
        &server,
        &NoteStoreServer::onUpdateNoteIfUsnMatchesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteIfUsnMatchesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    UpdateNoteIfUsnMatchesResult res = noteStore->updateNoteIfUsnMatches(
        note,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInUpdateNoteIfUsnMatches()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::QUOTA_REACHED;
    userException.parameter = generateRandomString();

    NoteStoreUpdateNoteIfUsnMatchesTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> UpdateNoteIfUsnMatchesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteIfUsnMatchesRequest,
        &helper,
        &NoteStoreUpdateNoteIfUsnMatchesTesterHelper::onUpdateNoteIfUsnMatchesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNoteIfUsnMatchesTesterHelper::updateNoteIfUsnMatchesRequestReady,
        &server,
        &NoteStoreServer::onUpdateNoteIfUsnMatchesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteIfUsnMatchesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        UpdateNoteIfUsnMatchesResult res = noteStore->updateNoteIfUsnMatches(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInUpdateNoteIfUsnMatches()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreUpdateNoteIfUsnMatchesTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> UpdateNoteIfUsnMatchesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteIfUsnMatchesRequest,
        &helper,
        &NoteStoreUpdateNoteIfUsnMatchesTesterHelper::onUpdateNoteIfUsnMatchesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNoteIfUsnMatchesTesterHelper::updateNoteIfUsnMatchesRequestReady,
        &server,
        &NoteStoreServer::onUpdateNoteIfUsnMatchesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteIfUsnMatchesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        UpdateNoteIfUsnMatchesResult res = noteStore->updateNoteIfUsnMatches(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInUpdateNoteIfUsnMatches()
{
    Note note = generateRandomNote();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::USER_NOT_REGISTERED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreUpdateNoteIfUsnMatchesTesterHelper helper(
        [&] (const Note & noteParam,
             IRequestContextPtr ctxParam) -> UpdateNoteIfUsnMatchesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(note == noteParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteIfUsnMatchesRequest,
        &helper,
        &NoteStoreUpdateNoteIfUsnMatchesTesterHelper::onUpdateNoteIfUsnMatchesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreUpdateNoteIfUsnMatchesTesterHelper::updateNoteIfUsnMatchesRequestReady,
        &server,
        &NoteStoreServer::onUpdateNoteIfUsnMatchesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::updateNoteIfUsnMatchesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        UpdateNoteIfUsnMatchesResult res = noteStore->updateNoteIfUsnMatches(
            note,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteManageNotebookShares()
{
    ManageNotebookSharesParameters parameters = generateRandomManageNotebookSharesParameters();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    ManageNotebookSharesResult response = generateRandomManageNotebookSharesResult();

    NoteStoreManageNotebookSharesTesterHelper helper(
        [&] (const ManageNotebookSharesParameters & parametersParam,
             IRequestContextPtr ctxParam) -> ManageNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(parameters == parametersParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::manageNotebookSharesRequest,
        &helper,
        &NoteStoreManageNotebookSharesTesterHelper::onManageNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreManageNotebookSharesTesterHelper::manageNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onManageNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::manageNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    ManageNotebookSharesResult res = noteStore->manageNotebookShares(
        parameters,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInManageNotebookShares()
{
    ManageNotebookSharesParameters parameters = generateRandomManageNotebookSharesParameters();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::OPENID_ALREADY_TAKEN;
    userException.parameter = generateRandomString();

    NoteStoreManageNotebookSharesTesterHelper helper(
        [&] (const ManageNotebookSharesParameters & parametersParam,
             IRequestContextPtr ctxParam) -> ManageNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(parameters == parametersParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::manageNotebookSharesRequest,
        &helper,
        &NoteStoreManageNotebookSharesTesterHelper::onManageNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreManageNotebookSharesTesterHelper::manageNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onManageNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::manageNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ManageNotebookSharesResult res = noteStore->manageNotebookShares(
            parameters,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInManageNotebookShares()
{
    ManageNotebookSharesParameters parameters = generateRandomManageNotebookSharesParameters();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreManageNotebookSharesTesterHelper helper(
        [&] (const ManageNotebookSharesParameters & parametersParam,
             IRequestContextPtr ctxParam) -> ManageNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(parameters == parametersParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::manageNotebookSharesRequest,
        &helper,
        &NoteStoreManageNotebookSharesTesterHelper::onManageNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreManageNotebookSharesTesterHelper::manageNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onManageNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::manageNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ManageNotebookSharesResult res = noteStore->manageNotebookShares(
            parameters,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInManageNotebookShares()
{
    ManageNotebookSharesParameters parameters = generateRandomManageNotebookSharesParameters();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::INVALID_OPENID_TOKEN;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreManageNotebookSharesTesterHelper helper(
        [&] (const ManageNotebookSharesParameters & parametersParam,
             IRequestContextPtr ctxParam) -> ManageNotebookSharesResult
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(parameters == parametersParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::manageNotebookSharesRequest,
        &helper,
        &NoteStoreManageNotebookSharesTesterHelper::onManageNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreManageNotebookSharesTesterHelper::manageNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onManageNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::manageNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ManageNotebookSharesResult res = noteStore->manageNotebookShares(
            parameters,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNotebookShares()
{
    QString notebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    ShareRelationships response = generateRandomShareRelationships();

    NoteStoreGetNotebookSharesTesterHelper helper(
        [&] (const QString & notebookGuidParam,
             IRequestContextPtr ctxParam) -> ShareRelationships
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            return response;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookSharesRequest,
        &helper,
        &NoteStoreGetNotebookSharesTesterHelper::onGetNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNotebookSharesTesterHelper::getNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onGetNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    ShareRelationships res = noteStore->getNotebookShares(
        notebookGuid,
        ctx);
    QVERIFY(res == response);
}

void NoteStoreTester::shouldDeliverEDAMUserExceptionInGetNotebookShares()
{
    QString notebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto userException = EDAMUserException();
    userException.errorCode = EDAMErrorCode::ACCOUNT_CLEAR;
    userException.parameter = generateRandomString();

    NoteStoreGetNotebookSharesTesterHelper helper(
        [&] (const QString & notebookGuidParam,
             IRequestContextPtr ctxParam) -> ShareRelationships
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            throw userException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookSharesRequest,
        &helper,
        &NoteStoreGetNotebookSharesTesterHelper::onGetNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNotebookSharesTesterHelper::getNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onGetNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ShareRelationships res = noteStore->getNotebookShares(
            notebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMUserException & e)
    {
        caughtException = true;
        QVERIFY(e == userException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMNotFoundExceptionInGetNotebookShares()
{
    QString notebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto notFoundException = EDAMNotFoundException();
    notFoundException.identifier = generateRandomString();
    notFoundException.key = generateRandomString();

    NoteStoreGetNotebookSharesTesterHelper helper(
        [&] (const QString & notebookGuidParam,
             IRequestContextPtr ctxParam) -> ShareRelationships
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            throw notFoundException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookSharesRequest,
        &helper,
        &NoteStoreGetNotebookSharesTesterHelper::onGetNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNotebookSharesTesterHelper::getNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onGetNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ShareRelationships res = noteStore->getNotebookShares(
            notebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMNotFoundException & e)
    {
        caughtException = true;
        QVERIFY(e == notFoundException);
    }

    QVERIFY(caughtException);
}

void NoteStoreTester::shouldDeliverEDAMSystemExceptionInGetNotebookShares()
{
    QString notebookGuid = generateRandomString();
    IRequestContextPtr ctx = newRequestContext(
        QStringLiteral("authenticationToken"));

    auto systemException = EDAMSystemException();
    systemException.errorCode = EDAMErrorCode::PERMISSION_DENIED;
    systemException.message = generateRandomString();
    systemException.rateLimitDuration = generateRandomInt32();

    NoteStoreGetNotebookSharesTesterHelper helper(
        [&] (const QString & notebookGuidParam,
             IRequestContextPtr ctxParam) -> ShareRelationships
        {
            Q_ASSERT(ctx->authenticationToken() == ctxParam->authenticationToken());
            Q_ASSERT(notebookGuid == notebookGuidParam);
            throw systemException;
        });

    NoteStoreServer server;
    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookSharesRequest,
        &helper,
        &NoteStoreGetNotebookSharesTesterHelper::onGetNotebookSharesRequestReceived);
    QObject::connect(
        &helper,
        &NoteStoreGetNotebookSharesTesterHelper::getNotebookSharesRequestReady,
        &server,
        &NoteStoreServer::onGetNotebookSharesRequestReady);

    QTcpServer tcpServer;
    QVERIFY(tcpServer.listen(QHostAddress::LocalHost));
    quint16 port = tcpServer.serverPort();

    QTcpSocket * pSocket = nullptr;
    QObject::connect(
        &tcpServer,
        &QTcpServer::newConnection,
        [&] {
            pSocket = tcpServer.nextPendingConnection();
            Q_ASSERT(pSocket);
            QObject::connect(
                pSocket,
                &QAbstractSocket::disconnected,
                pSocket,
                &QAbstractSocket::deleteLater);
            if (!pSocket->waitForConnected()) {
                QFAIL("Failed to establish connection");
            }

            QByteArray requestData = readThriftRequestFromSocket(*pSocket);
            server.onRequest(requestData);
        });

    QObject::connect(
        &server,
        &NoteStoreServer::getNotebookSharesRequestReady,
        [&] (QByteArray responseData)
        {
            QByteArray buffer;
            buffer.append("HTTP/1.1 200 OK\r\n");
            buffer.append("Content-Length: ");
            buffer.append(QString::number(responseData.size()).toUtf8());
            buffer.append("\r\n");
            buffer.append("Content-Type: application/x-thrift\r\n\r\n");
            buffer.append(responseData);

            if (!writeBufferToSocket(buffer, *pSocket)) {
                QFAIL("Failed to write response to socket");
            }
        });

    auto noteStore = newNoteStore(
        QStringLiteral("http://127.0.0.1:") + QString::number(port));
    bool caughtException = false;
    try
    {
        ShareRelationships res = noteStore->getNotebookShares(
            notebookGuid,
            ctx);
        Q_UNUSED(res)
    }
    catch(const EDAMSystemException & e)
    {
        caughtException = true;
        QVERIFY(e == systemException);
    }

    QVERIFY(caughtException);
}

} // namespace qevercloud

#include <TestNoteStore.moc>
