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

#ifndef QEVERCLOUD_GENERATED_NOTERESULTSPEC_H
#define QEVERCLOUD_GENERATED_NOTERESULTSPEC_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "TypeAliases.h"
#include <optional>

namespace qevercloud {

/**
 * This structure is provided to the getNoteWithResultSpec function to specify the subset of
 * fields that should be included in the Note that is returned. This allows clients to request
 * the minimum set of information that they require when retrieving a note, reducing the size
 * of the response and improving the response time.
 *
 * If one of the fields in this spec is not set, then it will be treated as 'false' by the service,
 * so that the default behavior is to include none of the fields below in the Note.
 *
 * */
class QEVERCLOUD_EXPORT NoteResultSpec: public Printable
{
    Q_GADGET
public:
    NoteResultSpec();
    NoteResultSpec(const NoteResultSpec & other);
    NoteResultSpec(NoteResultSpec && other) noexcept;
    ~NoteResultSpec() noexcept override;

    NoteResultSpec & operator=(const NoteResultSpec & other);
    NoteResultSpec & operator=(NoteResultSpec && other) noexcept;

    /**
    If true, the Note.content field will be populated with the note's ENML contents.
    */
    [[nodiscard]] const std::optional<bool> & includeContent() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeContent();
    void setIncludeContent(std::optional<bool> includeContent);

    /**
    If true, any Resource elements will include the binary contents of their 'data' field's
         body.
    */
    [[nodiscard]] const std::optional<bool> & includeResourcesData() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeResourcesData();
    void setIncludeResourcesData(std::optional<bool> includeResourcesData);

    /**
    If true, any Resource elements will include the binary contents of their 'recognition'
         field's body if recognition data is available.
    */
    [[nodiscard]] const std::optional<bool> & includeResourcesRecognition() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeResourcesRecognition();
    void setIncludeResourcesRecognition(std::optional<bool> includeResourcesRecognition);

    /**
    If true, any Resource elements will include the binary contents of their 'alternateData'
         field's body, if an alternate form is available.
    */
    [[nodiscard]] const std::optional<bool> & includeResourcesAlternateData() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeResourcesAlternateData();
    void setIncludeResourcesAlternateData(std::optional<bool> includeResourcesAlternateData);

    /**
    If true, the Note.sharedNotes field will be populated with the note's shares.
    */
    [[nodiscard]] const std::optional<bool> & includeSharedNotes() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeSharedNotes();
    void setIncludeSharedNotes(std::optional<bool> includeSharedNotes);

    /**
    If true, the Note.attributes.applicationData.fullMap field will be populated.
    */
    [[nodiscard]] const std::optional<bool> & includeNoteAppDataValues() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeNoteAppDataValues();
    void setIncludeNoteAppDataValues(std::optional<bool> includeNoteAppDataValues);

    /**
    If true, the Note.resource.attributes.applicationData.fullMap field will be populated.
    */
    [[nodiscard]] const std::optional<bool> & includeResourceAppDataValues() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeResourceAppDataValues();
    void setIncludeResourceAppDataValues(std::optional<bool> includeResourceAppDataValues);

    /**
    If true, the Note.limits field will be populated with the note owner's account limits.
    */
    [[nodiscard]] const std::optional<bool> & includeAccountLimits() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableIncludeAccountLimits();
    void setIncludeAccountLimits(std::optional<bool> includeAccountLimits);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NoteResultSpec & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteResultSpec & other) const noexcept;

    Q_PROPERTY(std::optional<bool> includeContent READ includeContent WRITE setIncludeContent)
    Q_PROPERTY(std::optional<bool> includeResourcesData READ includeResourcesData WRITE setIncludeResourcesData)
    Q_PROPERTY(std::optional<bool> includeResourcesRecognition READ includeResourcesRecognition WRITE setIncludeResourcesRecognition)
    Q_PROPERTY(std::optional<bool> includeResourcesAlternateData READ includeResourcesAlternateData WRITE setIncludeResourcesAlternateData)
    Q_PROPERTY(std::optional<bool> includeSharedNotes READ includeSharedNotes WRITE setIncludeSharedNotes)
    Q_PROPERTY(std::optional<bool> includeNoteAppDataValues READ includeNoteAppDataValues WRITE setIncludeNoteAppDataValues)
    Q_PROPERTY(std::optional<bool> includeResourceAppDataValues READ includeResourceAppDataValues WRITE setIncludeResourceAppDataValues)
    Q_PROPERTY(std::optional<bool> includeAccountLimits READ includeAccountLimits WRITE setIncludeAccountLimits)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteResultSpec)

#endif // QEVERCLOUD_GENERATED_NOTERESULTSPEC_H
