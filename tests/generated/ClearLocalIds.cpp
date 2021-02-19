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

#include "ClearLocalIds.h"
#include "../../src/Impl.h"
#include <qevercloud/utility/ToRange.h>

namespace qevercloud {

void clearLocalIds(Note & v)
{
    v.setLocalId(QString{});
    if (v.resources()) {
        for (auto & i: *v.mutableResources()) {
            clearLocalIds(i);
        }
    }
}

void clearLocalIds(Notebook & v)
{
    v.setLocalId(QString{});
}

void clearLocalIds(NotebookDescriptor & v)
{
    v.setLocalId(QString{});
}

void clearLocalIds(NoteEmailParameters & v)
{
    if (v.note()) {
        clearLocalIds(*v.mutableNote());
    }
}

void clearLocalIds(NoteList & v)
{
    for (auto & i: v.mutableNotes()) {
        clearLocalIds(i);
    }
}

void clearLocalIds(NoteMetadata & v)
{
    v.setLocalId(QString{});
}

void clearLocalIds(NotesMetadataList & v)
{
    for (auto & i: v.mutableNotes()) {
        clearLocalIds(i);
    }
}

void clearLocalIds(RelatedResult & v)
{
    if (v.notes()) {
        for (auto & i: *v.mutableNotes()) {
            clearLocalIds(i);
        }
    }
    if (v.notebooks()) {
        for (auto & i: *v.mutableNotebooks()) {
            clearLocalIds(i);
        }
    }
    if (v.tags()) {
        for (auto & i: *v.mutableTags()) {
            clearLocalIds(i);
        }
    }
    if (v.containingNotebooks()) {
        for (auto & i: *v.mutableContainingNotebooks()) {
            clearLocalIds(i);
        }
    }
}

void clearLocalIds(Resource & v)
{
    v.setLocalId(QString{});
}

void clearLocalIds(SavedSearch & v)
{
    v.setLocalId(QString{});
}

void clearLocalIds(SyncChunk & v)
{
    if (v.notes()) {
        for (auto & i: *v.mutableNotes()) {
            clearLocalIds(i);
        }
    }
    if (v.notebooks()) {
        for (auto & i: *v.mutableNotebooks()) {
            clearLocalIds(i);
        }
    }
    if (v.tags()) {
        for (auto & i: *v.mutableTags()) {
            clearLocalIds(i);
        }
    }
    if (v.searches()) {
        for (auto & i: *v.mutableSearches()) {
            clearLocalIds(i);
        }
    }
    if (v.resources()) {
        for (auto & i: *v.mutableResources()) {
            clearLocalIds(i);
        }
    }
}

void clearLocalIds(Tag & v)
{
    v.setLocalId(QString{});
}

void clearLocalIds(UpdateNoteIfUsnMatchesResult & v)
{
    if (v.note()) {
        clearLocalIds(*v.mutableNote());
    }
}

} // namespace qevercloud
