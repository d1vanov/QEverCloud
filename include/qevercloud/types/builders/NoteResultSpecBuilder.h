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

#ifndef QEVERCLOUD_GENERATED_NOTERESULTSPECBUILDER
#define QEVERCLOUD_GENERATED_NOTERESULTSPECBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/NoteResultSpec.h>
#include <qevercloud/types/TypeAliases.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteResultSpecBuilder
{
public:
    NoteResultSpecBuilder();

    NoteResultSpecBuilder(NoteResultSpecBuilder && other) noexcept;

    ~NoteResultSpecBuilder() noexcept;

    NoteResultSpecBuilder & operator=(NoteResultSpecBuilder && other) noexcept;

    NoteResultSpecBuilder & setIncludeContent(std::optional<bool> includeContent);
    NoteResultSpecBuilder & setIncludeResourcesData(std::optional<bool> includeResourcesData);
    NoteResultSpecBuilder & setIncludeResourcesRecognition(std::optional<bool> includeResourcesRecognition);
    NoteResultSpecBuilder & setIncludeResourcesAlternateData(std::optional<bool> includeResourcesAlternateData);
    NoteResultSpecBuilder & setIncludeSharedNotes(std::optional<bool> includeSharedNotes);
    NoteResultSpecBuilder & setIncludeNoteAppDataValues(std::optional<bool> includeNoteAppDataValues);
    NoteResultSpecBuilder & setIncludeResourceAppDataValues(std::optional<bool> includeResourceAppDataValues);
    NoteResultSpecBuilder & setIncludeAccountLimits(std::optional<bool> includeAccountLimits);

    [[nodiscard]] NoteResultSpec build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTERESULTSPECBUILDER
