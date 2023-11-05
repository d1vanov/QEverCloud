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

#include <qevercloud/services/NoteStoreServer.h>
#include "../Impl.h"
#include "../Thrift.h"
#include "../Types_io.h"
#include <qevercloud/RequestContextBuilder.h>
#include <qevercloud/exceptions/builders/EDAMSystemExceptionBuilder.h>
#include <qevercloud/utility/Log.h>
#include <utility>

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSyncStateParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getSyncState_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetFilteredSyncChunkParams(
    ThriftBinaryBufferReader & reader,
    qint32 & afterUSN,
    qint32 & maxEntries,
    SyncChunkFilter & filter,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getFilteredSyncChunk_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                afterUSN = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                maxEntries = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SyncChunkFilter v;
                readSyncChunkFilter(reader, v);
                filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetLinkedNotebookSyncStateParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getLinkedNotebookSyncState_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                linkedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetLinkedNotebookSyncChunkParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    qint32 & afterUSN,
    qint32 & maxEntries,
    bool & fullSyncOnly,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getLinkedNotebookSyncChunk_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                linkedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                afterUSN = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                maxEntries = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                fullSyncOnly = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListNotebooksParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listNotebooks_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListAccessibleBusinessNotebooksParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listAccessibleBusinessNotebooks_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetDefaultNotebookParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getDefaultNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateNotebookParams(
    ThriftBinaryBufferReader & reader,
    Notebook & notebook,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Notebook v;
                readNotebook(reader, v);
                notebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNotebookParams(
    ThriftBinaryBufferReader & reader,
    Notebook & notebook,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Notebook v;
                readNotebook(reader, v);
                notebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListTagsParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listTags_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListTagsByNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & notebookGuid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listTagsByNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetTagParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getTag_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateTagParams(
    ThriftBinaryBufferReader & reader,
    Tag & tag,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createTag_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Tag v;
                readTag(reader, v);
                tag = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateTagParams(
    ThriftBinaryBufferReader & reader,
    Tag & tag,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateTag_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Tag v;
                readTag(reader, v);
                tag = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUntagAllParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_untagAll_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeTagParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeTag_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListSearchesParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listSearches_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSearchParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getSearch_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateSearchParams(
    ThriftBinaryBufferReader & reader,
    SavedSearch & search,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createSearch_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SavedSearch v;
                readSavedSearch(reader, v);
                search = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateSearchParams(
    ThriftBinaryBufferReader & reader,
    SavedSearch & search,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateSearch_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SavedSearch v;
                readSavedSearch(reader, v);
                search = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeSearchParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeSearch_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNoteOffsetParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_findNoteOffset_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(reader, v);
                filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNotesMetadataParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    qint32 & offset,
    qint32 & maxNotes,
    NotesMetadataResultSpec & resultSpec,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_findNotesMetadata_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(reader, v);
                filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                offset = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                maxNotes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotesMetadataResultSpec v;
                readNotesMetadataResultSpec(reader, v);
                resultSpec = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNoteCountsParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    bool & withTrash,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_findNoteCounts_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteFilter v;
                readNoteFilter(reader, v);
                filter = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withTrash = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteWithResultSpecParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    NoteResultSpec & resultSpec,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteWithResultSpec_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteResultSpec v;
                readNoteResultSpec(reader, v);
                resultSpec = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & withContent,
    bool & withResourcesData,
    bool & withResourcesRecognition,
    bool & withResourcesAlternateData,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withContent = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteApplicationDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteApplicationData_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QString & value,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_setNoteApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                value = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUnsetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_unsetNoteApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteContentParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteContent_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteSearchTextParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & noteOnly,
    bool & tokenizeForIndexing,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteSearchText_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                noteOnly = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                tokenizeForIndexing = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceSearchTextParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceSearchText_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteTagNamesParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteTagNames_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateNoteParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                note = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNoteParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                note = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreDeleteNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_deleteNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCopyNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    Guid & toNotebookGuid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_copyNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                toNotebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListNoteVersionsParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listNoteVersions_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteVersionParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    qint32 & updateSequenceNum,
    bool & withResourcesData,
    bool & withResourcesRecognition,
    bool & withResourcesAlternateData,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNoteVersion_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                qint32 v;
                reader.readI32(v);
                updateSequenceNum = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withResourcesAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & withData,
    bool & withRecognition,
    bool & withAttributes,
    bool & withAlternateData,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResource_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withAttributes = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceApplicationDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceApplicationData_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QString & value,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_setResourceApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                value = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUnsetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_unsetResourceApplicationDataEntry_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                key = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateResourceParams(
    ThriftBinaryBufferReader & reader,
    Resource & resource,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateResource_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Resource v;
                readResource(reader, v);
                resource = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceData_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceByHashParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    QByteArray & contentHash,
    bool & withData,
    bool & withRecognition,
    bool & withAlternateData,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceByHash_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                noteGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QByteArray v;
                reader.readBinary(v);
                contentHash = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 4)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withRecognition = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                withAlternateData = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceRecognitionParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceRecognition_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceAlternateDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceAlternateData_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceAttributesParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getResourceAttributes_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetPublicNotebookParams(
    ThriftBinaryBufferReader & reader,
    UserID & userId,
    QString & publicUri,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname =
        QStringLiteral("NoteStore_getPublicNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_I32) {
                UserID v;
                reader.readI32(v);
                userId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                publicUri = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreShareNotebookParams(
    ThriftBinaryBufferReader & reader,
    SharedNotebook & sharedNotebook,
    QString & message,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_shareNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SharedNotebook v;
                readSharedNotebook(reader, v);
                sharedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                message = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateOrUpdateNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    NotebookShareTemplate & shareTemplate,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createOrUpdateNotebookShares_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookShareTemplate v;
                readNotebookShareTemplate(reader, v);
                shareTemplate = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateSharedNotebookParams(
    ThriftBinaryBufferReader & reader,
    SharedNotebook & sharedNotebook,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateSharedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                SharedNotebook v;
                readSharedNotebook(reader, v);
                sharedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetNotebookRecipientSettingsParams(
    ThriftBinaryBufferReader & reader,
    QString & notebookGuid,
    NotebookRecipientSettings & recipientSettings,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_setNotebookRecipientSettings_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NotebookRecipientSettings v;
                readNotebookRecipientSettings(reader, v);
                recipientSettings = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListSharedNotebooksParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listSharedNotebooks_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_createLinkedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                linkedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateLinkedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                LinkedNotebook v;
                readLinkedNotebook(reader, v);
                linkedNotebook = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListLinkedNotebooksParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_listLinkedNotebooks_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_expungeLinkedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreAuthenticateToSharedNotebookParams(
    ThriftBinaryBufferReader & reader,
    QString & shareKeyOrGlobalId,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_authenticateToSharedNotebook_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                shareKeyOrGlobalId = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSharedNotebookByAuthParams(
    ThriftBinaryBufferReader & reader,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getSharedNotebookByAuth_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreEmailNoteParams(
    ThriftBinaryBufferReader & reader,
    NoteEmailParameters & parameters,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_emailNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                NoteEmailParameters v;
                readNoteEmailParameters(reader, v);
                parameters = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreShareNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_shareNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreStopSharingNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_stopSharingNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                Guid v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreAuthenticateToSharedNoteParams(
    ThriftBinaryBufferReader & reader,
    QString & guid,
    QString & noteKey,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_authenticateToSharedNote_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                guid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                noteKey = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindRelatedParams(
    ThriftBinaryBufferReader & reader,
    RelatedQuery & query,
    RelatedResultSpec & resultSpec,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_findRelated_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                RelatedQuery v;
                readRelatedQuery(reader, v);
                query = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                RelatedResultSpec v;
                readRelatedResultSpec(reader, v);
                resultSpec = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNoteIfUsnMatchesParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_updateNoteIfUsnMatches_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                Note v;
                readNote(reader, v);
                note = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreManageNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesParameters & parameters,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_manageNotebookShares_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRUCT) {
                ManageNotebookSharesParameters v;
                readManageNotebookSharesParameters(reader, v);
                parameters = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    QString & notebookGuid,
    QUuid requestId,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname =
        QStringLiteral("NoteStore_getNotebookShares_pargs");

    reader.readStructBegin(fname);
    while(true)
    {
        reader.readFieldBegin(fname, fieldType, fieldId);
        if (fieldType == ThriftFieldType::T_STOP) {
            break;
        }

        if (fieldId == 1)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                authenticationToken = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                notebookGuid = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else
        {
            reader.skip(fieldType);
        }

        reader.readFieldEnd();
    }

    reader.readStructEnd();
    reader.readMessageEnd();

    ctx = RequestContextBuilder{}
        .setAuthenticationToken(std::move(authenticationToken))
        .setRequestId(requestId)
        .build();
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

NoteStoreServer::NoteStoreServer(QObject * parent) :
    QObject(parent)
{}

void NoteStoreServer::onRequest(QByteArray data, QUuid requestId)
{
    ThriftBinaryBufferReader reader(data);
    qint32 rseqid = 0;
    QString fname;
    ThriftMessageType mtype;
    reader.readMessageBegin(fname, mtype, rseqid);

    if (mtype != ThriftMessageType::T_CALL) {
        reader.skip(ThriftFieldType::T_STRUCT);
        reader.readMessageEnd();
        throw ThriftException(ThriftException::Type::INVALID_MESSAGE_TYPE);
    }

    if (fname == QStringLiteral("getSyncState"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreGetSyncStateParams(
            reader,
            requestId,
            ctx);

        Q_EMIT getSyncStateRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getFilteredSyncChunk"))
    {
        qint32 afterUSN = 0;
        qint32 maxEntries = 0;
        SyncChunkFilter filter;
        IRequestContextPtr ctx;

        parseNoteStoreGetFilteredSyncChunkParams(
            reader,
            afterUSN,
            maxEntries,
            filter,
            requestId,
            ctx);

        Q_EMIT getFilteredSyncChunkRequest(
            afterUSN,
            maxEntries,
            filter,
            ctx);
    }
    else if (fname == QStringLiteral("getLinkedNotebookSyncState"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;

        parseNoteStoreGetLinkedNotebookSyncStateParams(
            reader,
            linkedNotebook,
            requestId,
            ctx);

        Q_EMIT getLinkedNotebookSyncStateRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("getLinkedNotebookSyncChunk"))
    {
        LinkedNotebook linkedNotebook;
        qint32 afterUSN = 0;
        qint32 maxEntries = 0;
        bool fullSyncOnly = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetLinkedNotebookSyncChunkParams(
            reader,
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            requestId,
            ctx);

        Q_EMIT getLinkedNotebookSyncChunkRequest(
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
            ctx);
    }
    else if (fname == QStringLiteral("listNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListNotebooksParams(
            reader,
            requestId,
            ctx);

        Q_EMIT listNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listAccessibleBusinessNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListAccessibleBusinessNotebooksParams(
            reader,
            requestId,
            ctx);

        Q_EMIT listAccessibleBusinessNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNotebookParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getDefaultNotebook"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreGetDefaultNotebookParams(
            reader,
            requestId,
            ctx);

        Q_EMIT getDefaultNotebookRequest(
            ctx);
    }
    else if (fname == QStringLiteral("createNotebook"))
    {
        Notebook notebook;
        IRequestContextPtr ctx;

        parseNoteStoreCreateNotebookParams(
            reader,
            notebook,
            requestId,
            ctx);

        Q_EMIT createNotebookRequest(
            notebook,
            ctx);
    }
    else if (fname == QStringLiteral("updateNotebook"))
    {
        Notebook notebook;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateNotebookParams(
            reader,
            notebook,
            requestId,
            ctx);

        Q_EMIT updateNotebookRequest(
            notebook,
            ctx);
    }
    else if (fname == QStringLiteral("expungeNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeNotebookParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT expungeNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("listTags"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListTagsParams(
            reader,
            requestId,
            ctx);

        Q_EMIT listTagsRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listTagsByNotebook"))
    {
        Guid notebookGuid;
        IRequestContextPtr ctx;

        parseNoteStoreListTagsByNotebookParams(
            reader,
            notebookGuid,
            requestId,
            ctx);

        Q_EMIT listTagsByNotebookRequest(
            notebookGuid,
            ctx);
    }
    else if (fname == QStringLiteral("getTag"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetTagParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getTagRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createTag"))
    {
        Tag tag;
        IRequestContextPtr ctx;

        parseNoteStoreCreateTagParams(
            reader,
            tag,
            requestId,
            ctx);

        Q_EMIT createTagRequest(
            tag,
            ctx);
    }
    else if (fname == QStringLiteral("updateTag"))
    {
        Tag tag;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateTagParams(
            reader,
            tag,
            requestId,
            ctx);

        Q_EMIT updateTagRequest(
            tag,
            ctx);
    }
    else if (fname == QStringLiteral("untagAll"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreUntagAllParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT untagAllRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("expungeTag"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeTagParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT expungeTagRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("listSearches"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListSearchesParams(
            reader,
            requestId,
            ctx);

        Q_EMIT listSearchesRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getSearch"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetSearchParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getSearchRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createSearch"))
    {
        SavedSearch search;
        IRequestContextPtr ctx;

        parseNoteStoreCreateSearchParams(
            reader,
            search,
            requestId,
            ctx);

        Q_EMIT createSearchRequest(
            search,
            ctx);
    }
    else if (fname == QStringLiteral("updateSearch"))
    {
        SavedSearch search;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateSearchParams(
            reader,
            search,
            requestId,
            ctx);

        Q_EMIT updateSearchRequest(
            search,
            ctx);
    }
    else if (fname == QStringLiteral("expungeSearch"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeSearchParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT expungeSearchRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("findNoteOffset"))
    {
        NoteFilter filter;
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreFindNoteOffsetParams(
            reader,
            filter,
            guid,
            requestId,
            ctx);

        Q_EMIT findNoteOffsetRequest(
            filter,
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("findNotesMetadata"))
    {
        NoteFilter filter;
        qint32 offset = 0;
        qint32 maxNotes = 0;
        NotesMetadataResultSpec resultSpec;
        IRequestContextPtr ctx;

        parseNoteStoreFindNotesMetadataParams(
            reader,
            filter,
            offset,
            maxNotes,
            resultSpec,
            requestId,
            ctx);

        Q_EMIT findNotesMetadataRequest(
            filter,
            offset,
            maxNotes,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("findNoteCounts"))
    {
        NoteFilter filter;
        bool withTrash = false;
        IRequestContextPtr ctx;

        parseNoteStoreFindNoteCountsParams(
            reader,
            filter,
            withTrash,
            requestId,
            ctx);

        Q_EMIT findNoteCountsRequest(
            filter,
            withTrash,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteWithResultSpec"))
    {
        Guid guid;
        NoteResultSpec resultSpec;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteWithResultSpecParams(
            reader,
            guid,
            resultSpec,
            requestId,
            ctx);

        Q_EMIT getNoteWithResultSpecRequest(
            guid,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("getNote"))
    {
        Guid guid;
        bool withContent = false;
        bool withResourcesData = false;
        bool withResourcesRecognition = false;
        bool withResourcesAlternateData = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteParams(
            reader,
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            requestId,
            ctx);

        Q_EMIT getNoteRequest(
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteApplicationData"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteApplicationDataParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getNoteApplicationDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteApplicationDataEntryParams(
            reader,
            guid,
            key,
            requestId,
            ctx);

        Q_EMIT getNoteApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("setNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        QString value;
        IRequestContextPtr ctx;

        parseNoteStoreSetNoteApplicationDataEntryParams(
            reader,
            guid,
            key,
            value,
            requestId,
            ctx);

        Q_EMIT setNoteApplicationDataEntryRequest(
            guid,
            key,
            value,
            ctx);
    }
    else if (fname == QStringLiteral("unsetNoteApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;

        parseNoteStoreUnsetNoteApplicationDataEntryParams(
            reader,
            guid,
            key,
            requestId,
            ctx);

        Q_EMIT unsetNoteApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteContent"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteContentParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getNoteContentRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteSearchText"))
    {
        Guid guid;
        bool noteOnly = false;
        bool tokenizeForIndexing = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteSearchTextParams(
            reader,
            guid,
            noteOnly,
            tokenizeForIndexing,
            requestId,
            ctx);

        Q_EMIT getNoteSearchTextRequest(
            guid,
            noteOnly,
            tokenizeForIndexing,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceSearchText"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceSearchTextParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getResourceSearchTextRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteTagNames"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteTagNamesParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getNoteTagNamesRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("createNote"))
    {
        Note note;
        IRequestContextPtr ctx;

        parseNoteStoreCreateNoteParams(
            reader,
            note,
            requestId,
            ctx);

        Q_EMIT createNoteRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("updateNote"))
    {
        Note note;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateNoteParams(
            reader,
            note,
            requestId,
            ctx);

        Q_EMIT updateNoteRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("deleteNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreDeleteNoteParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT deleteNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("expungeNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeNoteParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT expungeNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("copyNote"))
    {
        Guid noteGuid;
        Guid toNotebookGuid;
        IRequestContextPtr ctx;

        parseNoteStoreCopyNoteParams(
            reader,
            noteGuid,
            toNotebookGuid,
            requestId,
            ctx);

        Q_EMIT copyNoteRequest(
            noteGuid,
            toNotebookGuid,
            ctx);
    }
    else if (fname == QStringLiteral("listNoteVersions"))
    {
        Guid noteGuid;
        IRequestContextPtr ctx;

        parseNoteStoreListNoteVersionsParams(
            reader,
            noteGuid,
            requestId,
            ctx);

        Q_EMIT listNoteVersionsRequest(
            noteGuid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteVersion"))
    {
        Guid noteGuid;
        qint32 updateSequenceNum = 0;
        bool withResourcesData = false;
        bool withResourcesRecognition = false;
        bool withResourcesAlternateData = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteVersionParams(
            reader,
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            requestId,
            ctx);

        Q_EMIT getNoteVersionRequest(
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResource"))
    {
        Guid guid;
        bool withData = false;
        bool withRecognition = false;
        bool withAttributes = false;
        bool withAlternateData = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceParams(
            reader,
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            requestId,
            ctx);

        Q_EMIT getResourceRequest(
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceApplicationData"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceApplicationDataParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getResourceApplicationDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceApplicationDataEntryParams(
            reader,
            guid,
            key,
            requestId,
            ctx);

        Q_EMIT getResourceApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("setResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        QString value;
        IRequestContextPtr ctx;

        parseNoteStoreSetResourceApplicationDataEntryParams(
            reader,
            guid,
            key,
            value,
            requestId,
            ctx);

        Q_EMIT setResourceApplicationDataEntryRequest(
            guid,
            key,
            value,
            ctx);
    }
    else if (fname == QStringLiteral("unsetResourceApplicationDataEntry"))
    {
        Guid guid;
        QString key;
        IRequestContextPtr ctx;

        parseNoteStoreUnsetResourceApplicationDataEntryParams(
            reader,
            guid,
            key,
            requestId,
            ctx);

        Q_EMIT unsetResourceApplicationDataEntryRequest(
            guid,
            key,
            ctx);
    }
    else if (fname == QStringLiteral("updateResource"))
    {
        Resource resource;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateResourceParams(
            reader,
            resource,
            requestId,
            ctx);

        Q_EMIT updateResourceRequest(
            resource,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceData"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceDataParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getResourceDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceByHash"))
    {
        Guid noteGuid;
        QByteArray contentHash;
        bool withData = false;
        bool withRecognition = false;
        bool withAlternateData = false;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceByHashParams(
            reader,
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            requestId,
            ctx);

        Q_EMIT getResourceByHashRequest(
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceRecognition"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceRecognitionParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getResourceRecognitionRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceAlternateData"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceAlternateDataParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getResourceAlternateDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceAttributes"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceAttributesParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT getResourceAttributesRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getPublicNotebook"))
    {
        UserID userId;
        QString publicUri;
        IRequestContextPtr ctx;

        parseNoteStoreGetPublicNotebookParams(
            reader,
            userId,
            publicUri,
            requestId,
            ctx);

        Q_EMIT getPublicNotebookRequest(
            userId,
            publicUri,
            ctx);
    }
    else if (fname == QStringLiteral("shareNotebook"))
    {
        SharedNotebook sharedNotebook;
        QString message;
        IRequestContextPtr ctx;

        parseNoteStoreShareNotebookParams(
            reader,
            sharedNotebook,
            message,
            requestId,
            ctx);

        Q_EMIT shareNotebookRequest(
            sharedNotebook,
            message,
            ctx);
    }
    else if (fname == QStringLiteral("createOrUpdateNotebookShares"))
    {
        NotebookShareTemplate shareTemplate;
        IRequestContextPtr ctx;

        parseNoteStoreCreateOrUpdateNotebookSharesParams(
            reader,
            shareTemplate,
            requestId,
            ctx);

        Q_EMIT createOrUpdateNotebookSharesRequest(
            shareTemplate,
            ctx);
    }
    else if (fname == QStringLiteral("updateSharedNotebook"))
    {
        SharedNotebook sharedNotebook;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateSharedNotebookParams(
            reader,
            sharedNotebook,
            requestId,
            ctx);

        Q_EMIT updateSharedNotebookRequest(
            sharedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("setNotebookRecipientSettings"))
    {
        QString notebookGuid;
        NotebookRecipientSettings recipientSettings;
        IRequestContextPtr ctx;

        parseNoteStoreSetNotebookRecipientSettingsParams(
            reader,
            notebookGuid,
            recipientSettings,
            requestId,
            ctx);

        Q_EMIT setNotebookRecipientSettingsRequest(
            notebookGuid,
            recipientSettings,
            ctx);
    }
    else if (fname == QStringLiteral("listSharedNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListSharedNotebooksParams(
            reader,
            requestId,
            ctx);

        Q_EMIT listSharedNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("createLinkedNotebook"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;

        parseNoteStoreCreateLinkedNotebookParams(
            reader,
            linkedNotebook,
            requestId,
            ctx);

        Q_EMIT createLinkedNotebookRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("updateLinkedNotebook"))
    {
        LinkedNotebook linkedNotebook;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateLinkedNotebookParams(
            reader,
            linkedNotebook,
            requestId,
            ctx);

        Q_EMIT updateLinkedNotebookRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("listLinkedNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListLinkedNotebooksParams(
            reader,
            requestId,
            ctx);

        Q_EMIT listLinkedNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("expungeLinkedNotebook"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreExpungeLinkedNotebookParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT expungeLinkedNotebookRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToSharedNotebook"))
    {
        QString shareKeyOrGlobalId;
        IRequestContextPtr ctx;

        parseNoteStoreAuthenticateToSharedNotebookParams(
            reader,
            shareKeyOrGlobalId,
            requestId,
            ctx);

        Q_EMIT authenticateToSharedNotebookRequest(
            shareKeyOrGlobalId,
            ctx);
    }
    else if (fname == QStringLiteral("getSharedNotebookByAuth"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreGetSharedNotebookByAuthParams(
            reader,
            requestId,
            ctx);

        Q_EMIT getSharedNotebookByAuthRequest(
            ctx);
    }
    else if (fname == QStringLiteral("emailNote"))
    {
        NoteEmailParameters parameters;
        IRequestContextPtr ctx;

        parseNoteStoreEmailNoteParams(
            reader,
            parameters,
            requestId,
            ctx);

        Q_EMIT emailNoteRequest(
            parameters,
            ctx);
    }
    else if (fname == QStringLiteral("shareNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreShareNoteParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT shareNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("stopSharingNote"))
    {
        Guid guid;
        IRequestContextPtr ctx;

        parseNoteStoreStopSharingNoteParams(
            reader,
            guid,
            requestId,
            ctx);

        Q_EMIT stopSharingNoteRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToSharedNote"))
    {
        QString guid;
        QString noteKey;
        IRequestContextPtr ctx;

        parseNoteStoreAuthenticateToSharedNoteParams(
            reader,
            guid,
            noteKey,
            requestId,
            ctx);

        Q_EMIT authenticateToSharedNoteRequest(
            guid,
            noteKey,
            ctx);
    }
    else if (fname == QStringLiteral("findRelated"))
    {
        RelatedQuery query;
        RelatedResultSpec resultSpec;
        IRequestContextPtr ctx;

        parseNoteStoreFindRelatedParams(
            reader,
            query,
            resultSpec,
            requestId,
            ctx);

        Q_EMIT findRelatedRequest(
            query,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("updateNoteIfUsnMatches"))
    {
        Note note;
        IRequestContextPtr ctx;

        parseNoteStoreUpdateNoteIfUsnMatchesParams(
            reader,
            note,
            requestId,
            ctx);

        Q_EMIT updateNoteIfUsnMatchesRequest(
            note,
            ctx);
    }
    else if (fname == QStringLiteral("manageNotebookShares"))
    {
        ManageNotebookSharesParameters parameters;
        IRequestContextPtr ctx;

        parseNoteStoreManageNotebookSharesParams(
            reader,
            parameters,
            requestId,
            ctx);

        Q_EMIT manageNotebookSharesRequest(
            parameters,
            ctx);
    }
    else if (fname == QStringLiteral("getNotebookShares"))
    {
        QString notebookGuid;
        IRequestContextPtr ctx;

        parseNoteStoreGetNotebookSharesParams(
            reader,
            notebookGuid,
            requestId,
            ctx);

        Q_EMIT getNotebookSharesRequest(
            notebookGuid,
            ctx);
    }
}

void NoteStoreServer::onGetSyncStateRequestReady(
    SyncState value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getSyncState"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getSyncStateRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getSyncState"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getSyncState"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSyncStateRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSyncStateRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getSyncStateRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getSyncState"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSyncState(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getSyncStateRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetFilteredSyncChunkRequestReady(
    SyncChunk value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getFilteredSyncChunk"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getFilteredSyncChunkRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getFilteredSyncChunk"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getFilteredSyncChunk"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getFilteredSyncChunkRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getFilteredSyncChunkRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getFilteredSyncChunkRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getFilteredSyncChunk"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSyncChunk(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getFilteredSyncChunkRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetLinkedNotebookSyncStateRequestReady(
    SyncState value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getLinkedNotebookSyncState"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getLinkedNotebookSyncState"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getLinkedNotebookSyncState"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncStateRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getLinkedNotebookSyncStateRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getLinkedNotebookSyncState"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSyncState(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getLinkedNotebookSyncStateRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetLinkedNotebookSyncChunkRequestReady(
    SyncChunk value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getLinkedNotebookSyncChunk"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getLinkedNotebookSyncChunk"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getLinkedNotebookSyncChunk"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getLinkedNotebookSyncChunkRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getLinkedNotebookSyncChunkRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getLinkedNotebookSyncChunk"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSyncChunk(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getLinkedNotebookSyncChunkRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onListNotebooksRequestReady(
    QList<Notebook> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listNotebooks"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listNotebooks"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listNotebooks"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listNotebooksRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listNotebooks"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: std::as_const(value)) {
        writeNotebook(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listNotebooksRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onListAccessibleBusinessNotebooksRequestReady(
    QList<Notebook> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listAccessibleBusinessNotebooks"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listAccessibleBusinessNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listAccessibleBusinessNotebooks"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listAccessibleBusinessNotebooks"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listAccessibleBusinessNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listAccessibleBusinessNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listAccessibleBusinessNotebooksRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listAccessibleBusinessNotebooks"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: std::as_const(value)) {
        writeNotebook(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listAccessibleBusinessNotebooksRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNotebookRequestReady(
    Notebook value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetDefaultNotebookRequestReady(
    Notebook value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getDefaultNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getDefaultNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getDefaultNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getDefaultNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getDefaultNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getDefaultNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getDefaultNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getDefaultNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getDefaultNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onCreateNotebookRequestReady(
    Notebook value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT createNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("createNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUpdateNotebookRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onExpungeNotebookRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT expungeNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onListTagsRequestReady(
    QList<Tag> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listTags"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listTagsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listTags"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listTags"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listTagsRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listTags"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: std::as_const(value)) {
        writeTag(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listTagsRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onListTagsByNotebookRequestReady(
    QList<Tag> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listTagsByNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listTagsByNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listTagsByNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listTagsByNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsByNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsByNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listTagsByNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listTagsByNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listTagsByNotebook"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: std::as_const(value)) {
        writeTag(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listTagsByNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetTagRequestReady(
    Tag value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getTag"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getTag"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getTag"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getTagRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getTag"),
        ThriftFieldType::T_STRUCT,
        0);
    writeTag(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getTagRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onCreateTagRequestReady(
    Tag value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createTag"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createTag"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createTag"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT createTagRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("createTag"),
        ThriftFieldType::T_STRUCT,
        0);
    writeTag(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createTagRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUpdateTagRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateTag"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateTag"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateTag"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateTagRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateTag"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateTagRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUntagAllRequestReady(
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("untagAll"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT untagAllRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("untagAll"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("untagAll"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT untagAllRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT untagAllRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT untagAllRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT untagAllRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("untagAll"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT untagAllRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onExpungeTagRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeTag"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeTag"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeTag"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeTagRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT expungeTagRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeTag"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeTagRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onListSearchesRequestReady(
    QList<SavedSearch> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listSearches"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listSearchesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listSearches"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listSearches"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSearchesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSearchesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listSearchesRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listSearches"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: std::as_const(value)) {
        writeSavedSearch(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listSearchesRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetSearchRequestReady(
    SavedSearch value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getSearch"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getSearch"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getSearch"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getSearchRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getSearch"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSavedSearch(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getSearchRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onCreateSearchRequestReady(
    SavedSearch value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createSearch"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createSearch"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createSearch"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT createSearchRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("createSearch"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSavedSearch(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createSearchRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUpdateSearchRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateSearch"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateSearch"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateSearch"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateSearchRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateSearch"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateSearchRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onExpungeSearchRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeSearch"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeSearch"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeSearch"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeSearchRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT expungeSearchRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeSearch"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeSearchRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onFindNoteOffsetRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("findNoteOffset"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT findNoteOffsetRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("findNoteOffset"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("findNoteOffset"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteOffsetRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteOffsetRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteOffsetRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT findNoteOffsetRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("findNoteOffset"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT findNoteOffsetRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onFindNotesMetadataRequestReady(
    NotesMetadataList value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("findNotesMetadata"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT findNotesMetadataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("findNotesMetadata"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("findNotesMetadata"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNotesMetadataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNotesMetadataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNotesMetadataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT findNotesMetadataRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("findNotesMetadata"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotesMetadataList(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT findNotesMetadataRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onFindNoteCountsRequestReady(
    NoteCollectionCounts value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("findNoteCounts"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT findNoteCountsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("findNoteCounts"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("findNoteCounts"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteCountsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteCountsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findNoteCountsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT findNoteCountsRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("findNoteCounts"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNoteCollectionCounts(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT findNoteCountsRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNoteWithResultSpecRequestReady(
    Note value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteWithResultSpec"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteWithResultSpecRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteWithResultSpec"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteWithResultSpec"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteWithResultSpecRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteWithResultSpecRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteWithResultSpecRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNoteWithResultSpecRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteWithResultSpec"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteWithResultSpecRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNoteRequestReady(
    Note value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNoteApplicationDataRequestReady(
    LazyMap value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteApplicationData"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteApplicationData"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteApplicationData"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNoteApplicationDataRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteApplicationData"),
        ThriftFieldType::T_STRUCT,
        0);
    writeLazyMap(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteApplicationDataRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNoteApplicationDataEntryRequestReady(
    QString value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteApplicationDataEntry"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNoteApplicationDataEntryRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteApplicationDataEntry"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteApplicationDataEntryRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onSetNoteApplicationDataEntryRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("setNoteApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("setNoteApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("setNoteApplicationDataEntry"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT setNoteApplicationDataEntryRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("setNoteApplicationDataEntry"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT setNoteApplicationDataEntryRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUnsetNoteApplicationDataEntryRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("unsetNoteApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("unsetNoteApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("unsetNoteApplicationDataEntry"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetNoteApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT unsetNoteApplicationDataEntryRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("unsetNoteApplicationDataEntry"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT unsetNoteApplicationDataEntryRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNoteContentRequestReady(
    QString value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteContent"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteContentRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteContent"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteContent"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteContentRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteContentRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteContentRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNoteContentRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteContent"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteContentRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNoteSearchTextRequestReady(
    QString value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteSearchText"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteSearchTextRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteSearchText"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteSearchText"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteSearchTextRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteSearchTextRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteSearchTextRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNoteSearchTextRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteSearchText"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteSearchTextRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceSearchTextRequestReady(
    QString value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceSearchText"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceSearchTextRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceSearchText"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceSearchText"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceSearchTextRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceSearchTextRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceSearchTextRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceSearchTextRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceSearchText"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceSearchTextRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNoteTagNamesRequestReady(
    QStringList value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteTagNames"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteTagNamesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteTagNames"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteTagNames"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteTagNamesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteTagNamesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteTagNamesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNoteTagNamesRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteTagNames"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRING, value.size());
    for(const auto & v: std::as_const(value)) {
        writer.writeString(v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteTagNamesRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onCreateNoteRequestReady(
    Note value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT createNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("createNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUpdateNoteRequestReady(
    Note value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onDeleteNoteRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("deleteNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT deleteNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("deleteNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("deleteNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT deleteNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT deleteNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT deleteNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT deleteNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("deleteNote"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT deleteNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onExpungeNoteRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT expungeNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeNote"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onCopyNoteRequestReady(
    Note value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("copyNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT copyNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("copyNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("copyNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT copyNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT copyNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT copyNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT copyNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("copyNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT copyNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onListNoteVersionsRequestReady(
    QList<NoteVersionId> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listNoteVersions"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listNoteVersionsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listNoteVersions"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listNoteVersions"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNoteVersionsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNoteVersionsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listNoteVersionsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listNoteVersionsRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listNoteVersions"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: std::as_const(value)) {
        writeNoteVersionId(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listNoteVersionsRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNoteVersionRequestReady(
    Note value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNoteVersion"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNoteVersionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNoteVersion"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNoteVersion"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteVersionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteVersionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNoteVersionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNoteVersionRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNoteVersion"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNote(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNoteVersionRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceRequestReady(
    Resource value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResource"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResource"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResource"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResource"),
        ThriftFieldType::T_STRUCT,
        0);
    writeResource(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceApplicationDataRequestReady(
    LazyMap value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceApplicationData"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceApplicationData"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceApplicationData"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceApplicationDataRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceApplicationData"),
        ThriftFieldType::T_STRUCT,
        0);
    writeLazyMap(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceApplicationDataRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceApplicationDataEntryRequestReady(
    QString value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceApplicationDataEntry"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceApplicationDataEntryRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceApplicationDataEntry"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceApplicationDataEntryRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onSetResourceApplicationDataEntryRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("setResourceApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("setResourceApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("setResourceApplicationDataEntry"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT setResourceApplicationDataEntryRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("setResourceApplicationDataEntry"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT setResourceApplicationDataEntryRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUnsetResourceApplicationDataEntryRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("unsetResourceApplicationDataEntry"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("unsetResourceApplicationDataEntry"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("unsetResourceApplicationDataEntry"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT unsetResourceApplicationDataEntryRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT unsetResourceApplicationDataEntryRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("unsetResourceApplicationDataEntry"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT unsetResourceApplicationDataEntryRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUpdateResourceRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateResource"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateResourceRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateResource"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateResource"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateResourceRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateResourceRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateResourceRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateResourceRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateResource"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateResourceRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceDataRequestReady(
    QByteArray value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceData"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceData"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceData"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceDataRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceData"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeBinary(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceDataRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceByHashRequestReady(
    Resource value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceByHash"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceByHashRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceByHash"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceByHash"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceByHashRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceByHashRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceByHashRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceByHashRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceByHash"),
        ThriftFieldType::T_STRUCT,
        0);
    writeResource(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceByHashRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceRecognitionRequestReady(
    QByteArray value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceRecognition"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceRecognitionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceRecognition"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceRecognition"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRecognitionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRecognitionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceRecognitionRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceRecognitionRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceRecognition"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeBinary(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceRecognitionRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceAlternateDataRequestReady(
    QByteArray value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceAlternateData"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceAlternateDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceAlternateData"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceAlternateData"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAlternateDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAlternateDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAlternateDataRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceAlternateDataRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceAlternateData"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeBinary(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceAlternateDataRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetResourceAttributesRequestReady(
    ResourceAttributes value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getResourceAttributes"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getResourceAttributesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getResourceAttributes"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getResourceAttributes"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAttributesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAttributesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getResourceAttributesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getResourceAttributesRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getResourceAttributes"),
        ThriftFieldType::T_STRUCT,
        0);
    writeResourceAttributes(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getResourceAttributesRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetPublicNotebookRequestReady(
    Notebook value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getPublicNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getPublicNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getPublicNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getPublicNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getPublicNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            1);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getPublicNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getPublicNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getPublicNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onShareNotebookRequestReady(
    SharedNotebook value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("shareNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT shareNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("shareNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("shareNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT shareNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("shareNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSharedNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT shareNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady(
    CreateOrUpdateNotebookSharesResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createOrUpdateNotebookShares"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createOrUpdateNotebookShares"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createOrUpdateNotebookShares"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMInvalidContactsException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMInvalidContactsException"),
                ThriftFieldType::T_STRUCT,
                4);

            writeEDAMInvalidContactsException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createOrUpdateNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT createOrUpdateNotebookSharesRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("createOrUpdateNotebookShares"),
        ThriftFieldType::T_STRUCT,
        0);
    writeCreateOrUpdateNotebookSharesResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createOrUpdateNotebookSharesRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUpdateSharedNotebookRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateSharedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateSharedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateSharedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateSharedNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSharedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSharedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateSharedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateSharedNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateSharedNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateSharedNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onSetNotebookRecipientSettingsRequestReady(
    Notebook value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("setNotebookRecipientSettings"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("setNotebookRecipientSettings"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("setNotebookRecipientSettings"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT setNotebookRecipientSettingsRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT setNotebookRecipientSettingsRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("setNotebookRecipientSettings"),
        ThriftFieldType::T_STRUCT,
        0);
    writeNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT setNotebookRecipientSettingsRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onListSharedNotebooksRequestReady(
    QList<SharedNotebook> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listSharedNotebooks"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listSharedNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listSharedNotebooks"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listSharedNotebooks"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSharedNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSharedNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listSharedNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listSharedNotebooksRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listSharedNotebooks"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: std::as_const(value)) {
        writeSharedNotebook(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listSharedNotebooksRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onCreateLinkedNotebookRequestReady(
    LinkedNotebook value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("createLinkedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT createLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("createLinkedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("createLinkedNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT createLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT createLinkedNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("createLinkedNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeLinkedNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT createLinkedNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUpdateLinkedNotebookRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateLinkedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateLinkedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateLinkedNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateLinkedNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateLinkedNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateLinkedNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onListLinkedNotebooksRequestReady(
    QList<LinkedNotebook> value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("listLinkedNotebooks"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT listLinkedNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("listLinkedNotebooks"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("listLinkedNotebooks"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listLinkedNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listLinkedNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT listLinkedNotebooksRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT listLinkedNotebooksRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("listLinkedNotebooks"),
        ThriftFieldType::T_LIST,
        0);
    writer.writeListBegin(ThriftFieldType::T_STRUCT, value.size());
    for(const auto & v: std::as_const(value)) {
        writeLinkedNotebook(writer, v);
    }
    writer.writeListEnd();
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT listLinkedNotebooksRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onExpungeLinkedNotebookRequestReady(
    qint32 value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("expungeLinkedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT expungeLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("expungeLinkedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("expungeLinkedNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT expungeLinkedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT expungeLinkedNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("expungeLinkedNotebook"),
        ThriftFieldType::T_I32,
        0);
    writer.writeI32(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT expungeLinkedNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onAuthenticateToSharedNotebookRequestReady(
    AuthenticationResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("authenticateToSharedNotebook"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("authenticateToSharedNotebook"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("authenticateToSharedNotebook"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNotebookRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT authenticateToSharedNotebookRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("authenticateToSharedNotebook"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT authenticateToSharedNotebookRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetSharedNotebookByAuthRequestReady(
    SharedNotebook value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getSharedNotebookByAuth"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getSharedNotebookByAuthRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getSharedNotebookByAuth"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getSharedNotebookByAuth"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSharedNotebookByAuthRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSharedNotebookByAuthRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getSharedNotebookByAuthRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getSharedNotebookByAuthRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getSharedNotebookByAuth"),
        ThriftFieldType::T_STRUCT,
        0);
    writeSharedNotebook(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getSharedNotebookByAuthRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onEmailNoteRequestReady(
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("emailNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT emailNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("emailNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("emailNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT emailNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT emailNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT emailNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT emailNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("emailNote"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT emailNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onShareNoteRequestReady(
    QString value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("shareNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT shareNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("shareNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("shareNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT shareNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT shareNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("shareNote"),
        ThriftFieldType::T_STRING,
        0);
    writer.writeString(value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT shareNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onStopSharingNoteRequestReady(
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("stopSharingNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT stopSharingNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("stopSharingNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("stopSharingNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT stopSharingNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT stopSharingNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT stopSharingNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT stopSharingNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("stopSharingNote"),
        ThriftFieldType::T_VOID,
        0);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT stopSharingNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onAuthenticateToSharedNoteRequestReady(
    AuthenticationResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("authenticateToSharedNote"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("authenticateToSharedNote"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("authenticateToSharedNote"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT authenticateToSharedNoteRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT authenticateToSharedNoteRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("authenticateToSharedNote"),
        ThriftFieldType::T_STRUCT,
        0);
    writeAuthenticationResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT authenticateToSharedNoteRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onFindRelatedRequestReady(
    RelatedResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("findRelated"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT findRelatedRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("findRelated"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("findRelated"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findRelatedRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findRelatedRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT findRelatedRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            2);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT findRelatedRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("findRelated"),
        ThriftFieldType::T_STRUCT,
        0);
    writeRelatedResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT findRelatedRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onUpdateNoteIfUsnMatchesRequestReady(
    UpdateNoteIfUsnMatchesResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("updateNoteIfUsnMatches"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("updateNoteIfUsnMatches"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("updateNoteIfUsnMatches"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT updateNoteIfUsnMatchesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT updateNoteIfUsnMatchesRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("updateNoteIfUsnMatches"),
        ThriftFieldType::T_STRUCT,
        0);
    writeUpdateNoteIfUsnMatchesResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT updateNoteIfUsnMatchesRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onManageNotebookSharesRequestReady(
    ManageNotebookSharesResult value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("manageNotebookShares"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT manageNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("manageNotebookShares"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("manageNotebookShares"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT manageNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT manageNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT manageNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT manageNotebookSharesRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("manageNotebookShares"),
        ThriftFieldType::T_STRUCT,
        0);
    writeManageNotebookSharesResult(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT manageNotebookSharesRequestReady(
        writer.buffer(), requestId);
}

void NoteStoreServer::onGetNotebookSharesRequestReady(
    ShareRelationships value,
    std::exception_ptr e,
    QUuid requestId)
{
    ThriftBinaryBufferWriter writer;
    qint32 cseqid = 0;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const ThriftException & exception)
        {
            writer.writeMessageBegin(
                QStringLiteral("getNotebookShares"),
                ThriftMessageType::T_EXCEPTION,
                cseqid);
            writeThriftException(writer, exception);
            writer.writeMessageEnd();

            Q_EMIT getNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(...)
        {
            // Will be handled below
        }
    }

    writer.writeMessageBegin(
        QStringLiteral("getNotebookShares"),
        ThriftMessageType::T_REPLY,
        cseqid);

    writer.writeStructBegin(
        QStringLiteral("getNotebookShares"));

    bool caughtUnidentifiedException = false;
    std::optional<QString> unidentifiedExceptionMessage;

    if (e)
    {
        try
        {
            std::rethrow_exception(e);
        }
        catch(const EDAMUserException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMUserException"),
                ThriftFieldType::T_STRUCT,
                1);

            writeEDAMUserException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMNotFoundException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMNotFoundException"),
                ThriftFieldType::T_STRUCT,
                2);

            writeEDAMNotFoundException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const EDAMSystemException & e)
        {
            writer.writeFieldBegin(
                QStringLiteral("EDAMSystemException"),
                ThriftFieldType::T_STRUCT,
                3);

            writeEDAMSystemException(writer, e);
            writer.writeFieldEnd();

            // Finalize message and return immediately
            writer.writeStructEnd();
            writer.writeMessageEnd();

            Q_EMIT getNotebookSharesRequestReady(
                writer.buffer(), requestId);
            return;
        }
        catch(const std::exception & e)
        {
            QEC_ERROR("server", "Unknown exception: " << e.what());
            caughtUnidentifiedException = true;
            unidentifiedExceptionMessage = QString::fromUtf8(e.what());
        }
        catch(...)
        {
            QEC_ERROR("server", "Unknown exception");
            caughtUnidentifiedException = true;
        }
    }

    if (caughtUnidentifiedException) {
        writer.writeFieldBegin(
            QStringLiteral("EDAMSystemException"),
            ThriftFieldType::T_STRUCT,
            3);

        writeEDAMSystemException(
            writer,
            EDAMSystemExceptionBuilder{}
                .setErrorCode(EDAMErrorCode::INTERNAL_ERROR)
                .setMessage(std::move(unidentifiedExceptionMessage))
                .build());
        writer.writeFieldEnd();

        // Finalize message and return immediately
        writer.writeStructEnd();
        writer.writeMessageEnd();

        Q_EMIT getNotebookSharesRequestReady(
            writer.buffer(), requestId);
        return;
    }

    writer.writeFieldBegin(
        QStringLiteral("getNotebookShares"),
        ThriftFieldType::T_STRUCT,
        0);
    writeShareRelationships(writer, value);
    writer.writeFieldEnd();

    writer.writeFieldBegin(QString(), ThriftFieldType::T_STOP, 0);
    writer.writeFieldEnd();

    writer.writeStructEnd();
    writer.writeMessageEnd();

    Q_EMIT getNotebookSharesRequestReady(
        writer.buffer(), requestId);
}

} // namespace qevercloud
