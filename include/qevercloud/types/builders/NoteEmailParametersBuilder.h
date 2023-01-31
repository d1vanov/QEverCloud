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

#ifndef QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSBUILDER
#define QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSBUILDER

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/Note.h>
#include <qevercloud/types/NoteEmailParameters.h>
#include <qevercloud/types/TypeAliases.h>
#include <QList>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

class QEVERCLOUD_EXPORT NoteEmailParametersBuilder
{
public:
    NoteEmailParametersBuilder();

    NoteEmailParametersBuilder(NoteEmailParametersBuilder && other) noexcept;

    ~NoteEmailParametersBuilder() noexcept;

    NoteEmailParametersBuilder & operator=(NoteEmailParametersBuilder && other) noexcept;

    NoteEmailParametersBuilder & setGuid(std::optional<QString> guid);
    NoteEmailParametersBuilder & setNote(std::optional<Note> note);
    NoteEmailParametersBuilder & setToAddresses(std::optional<QStringList> toAddresses);
    NoteEmailParametersBuilder & setCcAddresses(std::optional<QStringList> ccAddresses);
    NoteEmailParametersBuilder & setSubject(std::optional<QString> subject);
    NoteEmailParametersBuilder & setMessage(std::optional<QString> message);

    [[nodiscard]] NoteEmailParameters build();

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};
} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSBUILDER
