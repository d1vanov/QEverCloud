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
