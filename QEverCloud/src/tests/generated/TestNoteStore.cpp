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
#include <generated/Servers.h>

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
    void GetSyncStateRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetFilteredSyncChunkRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetLinkedNotebookSyncStateRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetLinkedNotebookSyncChunkRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListNotebooksRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListAccessibleBusinessNotebooksRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetDefaultNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void CreateNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ExpungeNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListTagsRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListTagsByNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetTagRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void CreateTagRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateTagRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UntagAllRequestReady(
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
            // TODO: emit finished
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ExpungeTagRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListSearchesRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetSearchRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void CreateSearchRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateSearchRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ExpungeSearchRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void FindNoteOffsetRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void FindNotesMetadataRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void FindNoteCountsRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNoteWithResultSpecRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNoteRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNoteApplicationDataRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNoteApplicationDataEntryRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void SetNoteApplicationDataEntryRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UnsetNoteApplicationDataEntryRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNoteContentRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNoteSearchTextRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceSearchTextRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNoteTagNamesRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void CreateNoteRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateNoteRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void DeleteNoteRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ExpungeNoteRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void CopyNoteRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListNoteVersionsRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNoteVersionRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceApplicationDataRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceApplicationDataEntryRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void SetResourceApplicationDataEntryRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UnsetResourceApplicationDataEntryRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateResourceRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceDataRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceByHashRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceRecognitionRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceAlternateDataRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetResourceAttributesRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetPublicNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ShareNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void CreateOrUpdateNotebookSharesRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateSharedNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void SetNotebookRecipientSettingsRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListSharedNotebooksRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void CreateLinkedNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateLinkedNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ListLinkedNotebooksRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ExpungeLinkedNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void AuthenticateToSharedNotebookRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetSharedNotebookByAuthRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void EmailNoteRequestReady(
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
            // TODO: emit finished
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ShareNoteRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void StopSharingNoteRequestReady(
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
            // TODO: emit finished
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void AuthenticateToSharedNoteRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void FindRelatedRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void UpdateNoteIfUsnMatchesRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void ManageNotebookSharesRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
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
    void GetNotebookSharesRequestReady(
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
            // TODO: emit finished
            Q_UNUSED(v)
        }
        catch(const EverCloudException & e)
        {
            // TODO: emit error
            Q_UNUSED(e)
        }
    }

private:
    Executor m_executor;
};

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetSyncState()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetFilteredSyncChunk()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetLinkedNotebookSyncState()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetLinkedNotebookSyncChunk()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListNotebooks()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListAccessibleBusinessNotebooks()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetDefaultNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListTags()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListTagsByNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetTag()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateTag()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateTag()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUntagAll()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeTag()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListSearches()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetSearch()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateSearch()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateSearch()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeSearch()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteFindNoteOffset()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteFindNotesMetadata()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteFindNoteCounts()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteWithResultSpec()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteApplicationData()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteApplicationDataEntry()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteSetNoteApplicationDataEntry()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUnsetNoteApplicationDataEntry()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteContent()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteSearchText()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceSearchText()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteTagNames()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteDeleteNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCopyNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListNoteVersions()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNoteVersion()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResource()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceApplicationData()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceApplicationDataEntry()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteSetResourceApplicationDataEntry()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUnsetResourceApplicationDataEntry()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateResource()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceData()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceByHash()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceRecognition()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceAlternateData()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetResourceAttributes()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetPublicNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteShareNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateOrUpdateNotebookShares()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateSharedNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteSetNotebookRecipientSettings()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListSharedNotebooks()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteCreateLinkedNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateLinkedNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteListLinkedNotebooks()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteExpungeLinkedNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteAuthenticateToSharedNotebook()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetSharedNotebookByAuth()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteEmailNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteShareNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteStopSharingNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteAuthenticateToSharedNote()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteFindRelated()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteUpdateNoteIfUsnMatches()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteManageNotebookShares()
{
    // TODO: implement
}

////////////////////////////////////////////////////////////////////////////////

void NoteStoreTester::shouldExecuteGetNotebookShares()
{
    // TODO: implement
}

} // namespace qevercloud

#include <TestNoteStore.moc>
