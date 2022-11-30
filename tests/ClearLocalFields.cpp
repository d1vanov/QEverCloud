/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include "ClearLocalFields.h"
#include "../src/Impl.h"
#include <qevercloud/utility/ToRange.h>

namespace qevercloud {

void clearLocalFields(AuthenticationResult & v)
{
    if (v.user()) {
        clearLocalFields(*v.mutableUser());
    }
}

void clearLocalFields(CreateOrUpdateNotebookSharesResult & v)
{
    if (v.matchingShares()) {
        for (auto & i: *v.mutableMatchingShares()) {
            clearLocalFields(i);
        }
    }
}

void clearLocalFields(LinkedNotebook & v)
{
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
}

void clearLocalFields(Note & v)
{
    v.setLocalId(QString{});
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
    v.setNotebookLocalId(QString{});
    v.setTagLocalIds(QStringList{});
    v.setThumbnailData(QByteArray{});
    if (v.resources()) {
        for (auto & i: *v.mutableResources()) {
            clearLocalFields(i);
        }
    }
    if (v.sharedNotes()) {
        for (auto & i: *v.mutableSharedNotes()) {
            clearLocalFields(i);
        }
    }
}

void clearLocalFields(Notebook & v)
{
    v.setLocalId(QString{});
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
    if (v.linkedNotebookGuid()) {
        v.setLinkedNotebookGuid(std::nullopt);
    }
    if (v.sharedNotebooks()) {
        for (auto & i: *v.mutableSharedNotebooks()) {
            clearLocalFields(i);
        }
    }
    if (v.contact()) {
        clearLocalFields(*v.mutableContact());
    }
}

void clearLocalFields(NotebookDescriptor & v)
{
    v.setLocalId(QString{});
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
}

void clearLocalFields(NoteEmailParameters & v)
{
    if (v.note()) {
        clearLocalFields(*v.mutableNote());
    }
}

void clearLocalFields(NoteList & v)
{
    for (auto & i: v.mutableNotes()) {
        clearLocalFields(i);
    }
}

void clearLocalFields(NoteMetadata & v)
{
    v.setLocalId(QString{});
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
}

void clearLocalFields(NotesMetadataList & v)
{
    for (auto & i: v.mutableNotes()) {
        clearLocalFields(i);
    }
}

void clearLocalFields(RelatedResult & v)
{
    if (v.notes()) {
        for (auto & i: *v.mutableNotes()) {
            clearLocalFields(i);
        }
    }
    if (v.notebooks()) {
        for (auto & i: *v.mutableNotebooks()) {
            clearLocalFields(i);
        }
    }
    if (v.tags()) {
        for (auto & i: *v.mutableTags()) {
            clearLocalFields(i);
        }
    }
    if (v.containingNotebooks()) {
        for (auto & i: *v.mutableContainingNotebooks()) {
            clearLocalFields(i);
        }
    }
}

void clearLocalFields(Resource & v)
{
    v.setLocalId(QString{});
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
    v.setNoteLocalId(QString{});
}

void clearLocalFields(SavedSearch & v)
{
    v.setLocalId(QString{});
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
}

void clearLocalFields(SharedNote & v)
{
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
    v.setNoteGuid(Guid{});
}

void clearLocalFields(SharedNotebook & v)
{
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
}

void clearLocalFields(SyncChunk & v)
{
    if (v.notes()) {
        for (auto & i: *v.mutableNotes()) {
            clearLocalFields(i);
        }
    }
    if (v.notebooks()) {
        for (auto & i: *v.mutableNotebooks()) {
            clearLocalFields(i);
        }
    }
    if (v.tags()) {
        for (auto & i: *v.mutableTags()) {
            clearLocalFields(i);
        }
    }
    if (v.searches()) {
        for (auto & i: *v.mutableSearches()) {
            clearLocalFields(i);
        }
    }
    if (v.resources()) {
        for (auto & i: *v.mutableResources()) {
            clearLocalFields(i);
        }
    }
    if (v.linkedNotebooks()) {
        for (auto & i: *v.mutableLinkedNotebooks()) {
            clearLocalFields(i);
        }
    }
}

void clearLocalFields(Tag & v)
{
    v.setLocalId(QString{});
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
    if (v.linkedNotebookGuid()) {
        v.setLinkedNotebookGuid(std::nullopt);
    }
    v.setParentTagLocalId(QString{});
}

void clearLocalFields(UpdateNoteIfUsnMatchesResult & v)
{
    if (v.note()) {
        clearLocalFields(*v.mutableNote());
    }
}

void clearLocalFields(User & v)
{
    v.setLocallyModified(false);
    v.setLocalOnly(false);
    v.setLocallyFavorited(false);
    v.setLocalData(QHash<QString, QVariant>{});
}

} // namespace qevercloud
