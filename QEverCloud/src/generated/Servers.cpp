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

#include <generated/Servers.h>
#include "../Impl.h"
#include "../Thrift.h"
#include "Types_io.h"

namespace qevercloud {

namespace {

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSyncStateParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetFilteredSyncChunkParams(
    ThriftBinaryBufferReader & reader,
    qint32 & afterUSN,
    qint32 & maxEntries,
    SyncChunkFilter & filter,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetLinkedNotebookSyncStateParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetLinkedNotebookSyncChunkParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
    qint32 & afterUSN,
    qint32 & maxEntries,
    bool & fullSyncOnly,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListNotebooksParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListAccessibleBusinessNotebooksParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetDefaultNotebookParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateNotebookParams(
    ThriftBinaryBufferReader & reader,
    Notebook & notebook,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNotebookParams(
    ThriftBinaryBufferReader & reader,
    Notebook & notebook,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListTagsParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListTagsByNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & notebookGuid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetTagParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateTagParams(
    ThriftBinaryBufferReader & reader,
    Tag & tag,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateTagParams(
    ThriftBinaryBufferReader & reader,
    Tag & tag,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUntagAllParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeTagParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListSearchesParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSearchParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateSearchParams(
    ThriftBinaryBufferReader & reader,
    SavedSearch & search,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateSearchParams(
    ThriftBinaryBufferReader & reader,
    SavedSearch & search,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeSearchParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNoteOffsetParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNotesMetadataParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    qint32 & offset,
    qint32 & maxNotes,
    NotesMetadataResultSpec & resultSpec,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindNoteCountsParams(
    ThriftBinaryBufferReader & reader,
    NoteFilter & filter,
    bool & withTrash,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteWithResultSpecParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    NoteResultSpec & resultSpec,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & withContent,
    bool & withResourcesData,
    bool & withResourcesRecognition,
    bool & withResourcesAlternateData,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteApplicationDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QString & value,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUnsetNoteApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteContentParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteSearchTextParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & noteOnly,
    bool & tokenizeForIndexing,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceSearchTextParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteTagNamesParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateNoteParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNoteParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreDeleteNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCopyNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    Guid & toNotebookGuid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListNoteVersionsParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNoteVersionParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    qint32 & updateSequenceNum,
    bool & withResourcesData,
    bool & withResourcesRecognition,
    bool & withResourcesAlternateData,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    bool & withData,
    bool & withRecognition,
    bool & withAttributes,
    bool & withAlternateData,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceApplicationDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
    QString & value,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUnsetResourceApplicationDataEntryParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
    QString & key,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateResourceParams(
    ThriftBinaryBufferReader & reader,
    Resource & resource,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceByHashParams(
    ThriftBinaryBufferReader & reader,
    Guid & noteGuid,
    QByteArray & contentHash,
    bool & withData,
    bool & withRecognition,
    bool & withAlternateData,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceRecognitionParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceAlternateDataParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetResourceAttributesParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetPublicNotebookParams(
    ThriftBinaryBufferReader & reader,
    UserID & userId,
    QString & publicUri,
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

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreShareNotebookParams(
    ThriftBinaryBufferReader & reader,
    SharedNotebook & sharedNotebook,
    QString & message,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateOrUpdateNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    NotebookShareTemplate & shareTemplate,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateSharedNotebookParams(
    ThriftBinaryBufferReader & reader,
    SharedNotebook & sharedNotebook,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreSetNotebookRecipientSettingsParams(
    ThriftBinaryBufferReader & reader,
    QString & notebookGuid,
    NotebookRecipientSettings & recipientSettings,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListSharedNotebooksParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreCreateLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    LinkedNotebook & linkedNotebook,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreListLinkedNotebooksParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreExpungeLinkedNotebookParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreAuthenticateToSharedNotebookParams(
    ThriftBinaryBufferReader & reader,
    QString & shareKeyOrGlobalId,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetSharedNotebookByAuthParams(
    ThriftBinaryBufferReader & reader,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreEmailNoteParams(
    ThriftBinaryBufferReader & reader,
    NoteEmailParameters & parameters,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreShareNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreStopSharingNoteParams(
    ThriftBinaryBufferReader & reader,
    Guid & guid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreAuthenticateToSharedNoteParams(
    ThriftBinaryBufferReader & reader,
    QString & guid,
    QString & noteKey,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreFindRelatedParams(
    ThriftBinaryBufferReader & reader,
    RelatedQuery & query,
    RelatedResultSpec & resultSpec,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreUpdateNoteIfUsnMatchesParams(
    ThriftBinaryBufferReader & reader,
    Note & note,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreManageNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    ManageNotebookSharesParameters & parameters,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseNoteStoreGetNotebookSharesParams(
    ThriftBinaryBufferReader & reader,
    QString & notebookGuid,
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreCheckVersionParams(
    ThriftBinaryBufferReader & reader,
    QString & clientName,
    qint16 & edamVersionMajor,
    qint16 & edamVersionMinor,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname = 
        QStringLiteral("UserStore_checkVersion_pargs");

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
                clientName = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 2)
        {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                edamVersionMajor = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 3)
        {
            if (fieldType == ThriftFieldType::T_I16) {
                qint16 v;
                reader.readI16(v);
                edamVersionMinor = v;
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

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetBootstrapInfoParams(
    ThriftBinaryBufferReader & reader,
    QString & locale,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname = 
        QStringLiteral("UserStore_getBootstrapInfo_pargs");

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
                locale = v;
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

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreAuthenticateLongSessionParams(
    ThriftBinaryBufferReader & reader,
    QString & username,
    QString & password,
    QString & consumerKey,
    QString & consumerSecret,
    QString & deviceIdentifier,
    QString & deviceDescription,
    bool & supportsTwoFactor,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname = 
        QStringLiteral("UserStore_authenticateLongSession_pargs");

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
                username = v;
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
                password = v;
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
                consumerKey = v;
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
                consumerSecret = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 5)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceIdentifier = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 6)
        {
            if (fieldType == ThriftFieldType::T_STRING) {
                QString v;
                reader.readString(v);
                deviceDescription = v;
            }
            else {
                reader.skip(fieldType);
            }
        }
        else if (fieldId == 7)
        {
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                supportsTwoFactor = v;
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

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreCompleteTwoFactorAuthenticationParams(
    ThriftBinaryBufferReader & reader,
    QString & oneTimeCode,
    QString & deviceIdentifier,
    QString & deviceDescription,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_completeTwoFactorAuthentication_pargs");

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
                oneTimeCode = v;
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
                deviceIdentifier = v;
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
                deviceDescription = v;
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreRevokeLongSessionParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_revokeLongSession_pargs");

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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreAuthenticateToBusinessParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_authenticateToBusiness_pargs");

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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetUserParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_getUser_pargs");

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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetPublicUserInfoParams(
    ThriftBinaryBufferReader & reader,
    QString & username,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname = 
        QStringLiteral("UserStore_getPublicUserInfo_pargs");

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
                username = v;
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

    ctx = newRequestContext();
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetUserUrlsParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_getUserUrls_pargs");

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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreInviteToBusinessParams(
    ThriftBinaryBufferReader & reader,
    QString & emailAddress,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_inviteToBusiness_pargs");

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
                emailAddress = v;
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreRemoveFromBusinessParams(
    ThriftBinaryBufferReader & reader,
    QString & emailAddress,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_removeFromBusiness_pargs");

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
                emailAddress = v;
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreUpdateBusinessUserIdentifierParams(
    ThriftBinaryBufferReader & reader,
    QString & oldEmailAddress,
    QString & newEmailAddress,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_updateBusinessUserIdentifier_pargs");

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
                oldEmailAddress = v;
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
                newEmailAddress = v;
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreListBusinessUsersParams(
    ThriftBinaryBufferReader & reader,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_listBusinessUsers_pargs");

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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreListBusinessInvitationsParams(
    ThriftBinaryBufferReader & reader,
    bool & includeRequestedInvitations,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;
    QString authenticationToken;

    QString fname = 
        QStringLiteral("UserStore_listBusinessInvitations_pargs");

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
            if (fieldType == ThriftFieldType::T_BOOL) {
                bool v;
                reader.readBool(v);
                includeRequestedInvitations = v;
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

    ctx = newRequestContext(authenticationToken);
}

////////////////////////////////////////////////////////////////////////////////

void parseUserStoreGetAccountLimitsParams(
    ThriftBinaryBufferReader & reader,
    ServiceLevel & serviceLevel,
    IRequestContextPtr & ctx)
{
    ThriftFieldType fieldType;
    qint16 fieldId;

    QString fname = 
        QStringLiteral("UserStore_getAccountLimits_pargs");

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
                ServiceLevel v;
                readEnumServiceLevel(reader, v);
                serviceLevel = v;
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

    ctx = newRequestContext();
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

NoteStoreServer::NoteStoreServer(QObject * parent) :
    QObject(parent)
{}

void NoteStoreServer::onRequest(QByteArray data)
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
            ctx);

        Q_EMIT getSyncStateRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getFilteredSyncChunk"))
    {
        qint32 afterUSN;
        qint32 maxEntries;
        SyncChunkFilter filter;
        IRequestContextPtr ctx;

        parseNoteStoreGetFilteredSyncChunkParams(
            reader,
            afterUSN,
            maxEntries,
            filter,
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
            ctx);

        Q_EMIT getLinkedNotebookSyncStateRequest(
            linkedNotebook,
            ctx);
    }
    else if (fname == QStringLiteral("getLinkedNotebookSyncChunk"))
    {
        LinkedNotebook linkedNotebook;
        qint32 afterUSN;
        qint32 maxEntries;
        bool fullSyncOnly;
        IRequestContextPtr ctx;

        parseNoteStoreGetLinkedNotebookSyncChunkParams(
            reader,
            linkedNotebook,
            afterUSN,
            maxEntries,
            fullSyncOnly,
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
            ctx);

        Q_EMIT listNotebooksRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listAccessibleBusinessNotebooks"))
    {
        IRequestContextPtr ctx;

        parseNoteStoreListAccessibleBusinessNotebooksParams(
            reader,
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
            ctx);

        Q_EMIT findNoteOffsetRequest(
            filter,
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("findNotesMetadata"))
    {
        NoteFilter filter;
        qint32 offset;
        qint32 maxNotes;
        NotesMetadataResultSpec resultSpec;
        IRequestContextPtr ctx;

        parseNoteStoreFindNotesMetadataParams(
            reader,
            filter,
            offset,
            maxNotes,
            resultSpec,
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
        bool withTrash;
        IRequestContextPtr ctx;

        parseNoteStoreFindNoteCountsParams(
            reader,
            filter,
            withTrash,
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
            ctx);

        Q_EMIT getNoteWithResultSpecRequest(
            guid,
            resultSpec,
            ctx);
    }
    else if (fname == QStringLiteral("getNote"))
    {
        Guid guid;
        bool withContent;
        bool withResourcesData;
        bool withResourcesRecognition;
        bool withResourcesAlternateData;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteParams(
            reader,
            guid,
            withContent,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
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
            ctx);

        Q_EMIT getNoteContentRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteSearchText"))
    {
        Guid guid;
        bool noteOnly;
        bool tokenizeForIndexing;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteSearchTextParams(
            reader,
            guid,
            noteOnly,
            tokenizeForIndexing,
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
            ctx);

        Q_EMIT listNoteVersionsRequest(
            noteGuid,
            ctx);
    }
    else if (fname == QStringLiteral("getNoteVersion"))
    {
        Guid noteGuid;
        qint32 updateSequenceNum;
        bool withResourcesData;
        bool withResourcesRecognition;
        bool withResourcesAlternateData;
        IRequestContextPtr ctx;

        parseNoteStoreGetNoteVersionParams(
            reader,
            noteGuid,
            updateSequenceNum,
            withResourcesData,
            withResourcesRecognition,
            withResourcesAlternateData,
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
        bool withData;
        bool withRecognition;
        bool withAttributes;
        bool withAlternateData;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceParams(
            reader,
            guid,
            withData,
            withRecognition,
            withAttributes,
            withAlternateData,
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
            ctx);

        Q_EMIT getResourceDataRequest(
            guid,
            ctx);
    }
    else if (fname == QStringLiteral("getResourceByHash"))
    {
        Guid noteGuid;
        QByteArray contentHash;
        bool withData;
        bool withRecognition;
        bool withAlternateData;
        IRequestContextPtr ctx;

        parseNoteStoreGetResourceByHashParams(
            reader,
            noteGuid,
            contentHash,
            withData,
            withRecognition,
            withAlternateData,
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
            ctx);

        Q_EMIT getNotebookSharesRequest(
            notebookGuid,
            ctx);
    }
}

void NoteStoreServer::onGetSyncStateRequestReady(SyncState value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetFilteredSyncChunkRequestReady(SyncChunk value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetLinkedNotebookSyncStateRequestReady(SyncState value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetLinkedNotebookSyncChunkRequestReady(SyncChunk value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListNotebooksRequestReady(QList<Notebook> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListAccessibleBusinessNotebooksRequestReady(QList<Notebook> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNotebookRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetDefaultNotebookRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateNotebookRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onExpungeNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListTagsRequestReady(QList<Tag> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListTagsByNotebookRequestReady(QList<Tag> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetTagRequestReady(Tag value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateTagRequestReady(Tag value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateTagRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUntagAllRequestReady()
{
    // TODO: implement
}

void NoteStoreServer::onExpungeTagRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListSearchesRequestReady(QList<SavedSearch> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetSearchRequestReady(SavedSearch value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateSearchRequestReady(SavedSearch value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateSearchRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onExpungeSearchRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onFindNoteOffsetRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onFindNotesMetadataRequestReady(NotesMetadataList value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onFindNoteCountsRequestReady(NoteCollectionCounts value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteWithResultSpecRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteApplicationDataRequestReady(LazyMap value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteApplicationDataEntryRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onSetNoteApplicationDataEntryRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUnsetNoteApplicationDataEntryRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteContentRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteSearchTextRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceSearchTextRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteTagNamesRequestReady(QStringList value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateNoteRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateNoteRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onDeleteNoteRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onExpungeNoteRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCopyNoteRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListNoteVersionsRequestReady(QList<NoteVersionId> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNoteVersionRequestReady(Note value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceRequestReady(Resource value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceApplicationDataRequestReady(LazyMap value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceApplicationDataEntryRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onSetResourceApplicationDataEntryRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUnsetResourceApplicationDataEntryRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateResourceRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceDataRequestReady(QByteArray value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceByHashRequestReady(Resource value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceRecognitionRequestReady(QByteArray value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceAlternateDataRequestReady(QByteArray value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetResourceAttributesRequestReady(ResourceAttributes value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetPublicNotebookRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onShareNotebookRequestReady(SharedNotebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateOrUpdateNotebookSharesRequestReady(CreateOrUpdateNotebookSharesResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateSharedNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onSetNotebookRecipientSettingsRequestReady(Notebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListSharedNotebooksRequestReady(QList<SharedNotebook> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onCreateLinkedNotebookRequestReady(LinkedNotebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateLinkedNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onListLinkedNotebooksRequestReady(QList<LinkedNotebook> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onExpungeLinkedNotebookRequestReady(qint32 value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onAuthenticateToSharedNotebookRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetSharedNotebookByAuthRequestReady(SharedNotebook value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onEmailNoteRequestReady()
{
    // TODO: implement
}

void NoteStoreServer::onShareNoteRequestReady(QString value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onStopSharingNoteRequestReady()
{
    // TODO: implement
}

void NoteStoreServer::onAuthenticateToSharedNoteRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onFindRelatedRequestReady(RelatedResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onUpdateNoteIfUsnMatchesRequestReady(UpdateNoteIfUsnMatchesResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onManageNotebookSharesRequestReady(ManageNotebookSharesResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void NoteStoreServer::onGetNotebookSharesRequestReady(ShareRelationships value)
{
    // TODO: implement
    Q_UNUSED(value)
}

////////////////////////////////////////////////////////////////////////////////

UserStoreServer::UserStoreServer(QObject * parent) :
    QObject(parent)
{}

void UserStoreServer::onRequest(QByteArray data)
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

    if (fname == QStringLiteral("checkVersion"))
    {
        QString clientName;
        qint16 edamVersionMajor;
        qint16 edamVersionMinor;
        IRequestContextPtr ctx;

        parseUserStoreCheckVersionParams(
            reader,
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);

        Q_EMIT checkVersionRequest(
            clientName,
            edamVersionMajor,
            edamVersionMinor,
            ctx);
    }
    else if (fname == QStringLiteral("getBootstrapInfo"))
    {
        QString locale;
        IRequestContextPtr ctx;

        parseUserStoreGetBootstrapInfoParams(
            reader,
            locale,
            ctx);

        Q_EMIT getBootstrapInfoRequest(
            locale,
            ctx);
    }
    else if (fname == QStringLiteral("authenticateLongSession"))
    {
        QString username;
        QString password;
        QString consumerKey;
        QString consumerSecret;
        QString deviceIdentifier;
        QString deviceDescription;
        bool supportsTwoFactor;
        IRequestContextPtr ctx;

        parseUserStoreAuthenticateLongSessionParams(
            reader,
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);

        Q_EMIT authenticateLongSessionRequest(
            username,
            password,
            consumerKey,
            consumerSecret,
            deviceIdentifier,
            deviceDescription,
            supportsTwoFactor,
            ctx);
    }
    else if (fname == QStringLiteral("completeTwoFactorAuthentication"))
    {
        QString oneTimeCode;
        QString deviceIdentifier;
        QString deviceDescription;
        IRequestContextPtr ctx;

        parseUserStoreCompleteTwoFactorAuthenticationParams(
            reader,
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);

        Q_EMIT completeTwoFactorAuthenticationRequest(
            oneTimeCode,
            deviceIdentifier,
            deviceDescription,
            ctx);
    }
    else if (fname == QStringLiteral("revokeLongSession"))
    {
        IRequestContextPtr ctx;

        parseUserStoreRevokeLongSessionParams(
            reader,
            ctx);

        Q_EMIT revokeLongSessionRequest(
            ctx);
    }
    else if (fname == QStringLiteral("authenticateToBusiness"))
    {
        IRequestContextPtr ctx;

        parseUserStoreAuthenticateToBusinessParams(
            reader,
            ctx);

        Q_EMIT authenticateToBusinessRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getUser"))
    {
        IRequestContextPtr ctx;

        parseUserStoreGetUserParams(
            reader,
            ctx);

        Q_EMIT getUserRequest(
            ctx);
    }
    else if (fname == QStringLiteral("getPublicUserInfo"))
    {
        QString username;
        IRequestContextPtr ctx;

        parseUserStoreGetPublicUserInfoParams(
            reader,
            username,
            ctx);

        Q_EMIT getPublicUserInfoRequest(
            username,
            ctx);
    }
    else if (fname == QStringLiteral("getUserUrls"))
    {
        IRequestContextPtr ctx;

        parseUserStoreGetUserUrlsParams(
            reader,
            ctx);

        Q_EMIT getUserUrlsRequest(
            ctx);
    }
    else if (fname == QStringLiteral("inviteToBusiness"))
    {
        QString emailAddress;
        IRequestContextPtr ctx;

        parseUserStoreInviteToBusinessParams(
            reader,
            emailAddress,
            ctx);

        Q_EMIT inviteToBusinessRequest(
            emailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("removeFromBusiness"))
    {
        QString emailAddress;
        IRequestContextPtr ctx;

        parseUserStoreRemoveFromBusinessParams(
            reader,
            emailAddress,
            ctx);

        Q_EMIT removeFromBusinessRequest(
            emailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("updateBusinessUserIdentifier"))
    {
        QString oldEmailAddress;
        QString newEmailAddress;
        IRequestContextPtr ctx;

        parseUserStoreUpdateBusinessUserIdentifierParams(
            reader,
            oldEmailAddress,
            newEmailAddress,
            ctx);

        Q_EMIT updateBusinessUserIdentifierRequest(
            oldEmailAddress,
            newEmailAddress,
            ctx);
    }
    else if (fname == QStringLiteral("listBusinessUsers"))
    {
        IRequestContextPtr ctx;

        parseUserStoreListBusinessUsersParams(
            reader,
            ctx);

        Q_EMIT listBusinessUsersRequest(
            ctx);
    }
    else if (fname == QStringLiteral("listBusinessInvitations"))
    {
        bool includeRequestedInvitations;
        IRequestContextPtr ctx;

        parseUserStoreListBusinessInvitationsParams(
            reader,
            includeRequestedInvitations,
            ctx);

        Q_EMIT listBusinessInvitationsRequest(
            includeRequestedInvitations,
            ctx);
    }
    else if (fname == QStringLiteral("getAccountLimits"))
    {
        ServiceLevel serviceLevel;
        IRequestContextPtr ctx;

        parseUserStoreGetAccountLimitsParams(
            reader,
            serviceLevel,
            ctx);

        Q_EMIT getAccountLimitsRequest(
            serviceLevel,
            ctx);
    }
}

void UserStoreServer::onCheckVersionRequestReady(bool value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetBootstrapInfoRequestReady(BootstrapInfo value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onAuthenticateLongSessionRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onCompleteTwoFactorAuthenticationRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onRevokeLongSessionRequestReady()
{
    // TODO: implement
}

void UserStoreServer::onAuthenticateToBusinessRequestReady(AuthenticationResult value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetUserRequestReady(User value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetPublicUserInfoRequestReady(PublicUserInfo value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetUserUrlsRequestReady(UserUrls value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onInviteToBusinessRequestReady()
{
    // TODO: implement
}

void UserStoreServer::onRemoveFromBusinessRequestReady()
{
    // TODO: implement
}

void UserStoreServer::onUpdateBusinessUserIdentifierRequestReady()
{
    // TODO: implement
}

void UserStoreServer::onListBusinessUsersRequestReady(QList<UserProfile> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onListBusinessInvitationsRequestReady(QList<BusinessInvitation> value)
{
    // TODO: implement
    Q_UNUSED(value)
}

void UserStoreServer::onGetAccountLimitsRequestReady(AccountLimits value)
{
    // TODO: implement
    Q_UNUSED(value)
}

} // namespace qevercloud
