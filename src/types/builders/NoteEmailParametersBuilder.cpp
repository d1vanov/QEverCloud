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

#include <qevercloud/types/builders/NoteEmailParametersBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteEmailParametersBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_guid;
    std::optional<Note> m_note;
    std::optional<QStringList> m_toAddresses;
    std::optional<QStringList> m_ccAddresses;
    std::optional<QString> m_subject;
    std::optional<QString> m_message;
};

NoteEmailParametersBuilder::NoteEmailParametersBuilder() :
    d(new NoteEmailParametersBuilder::Impl)
{}

NoteEmailParametersBuilder::NoteEmailParametersBuilder(NoteEmailParametersBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteEmailParametersBuilder::~NoteEmailParametersBuilder() noexcept = default;

NoteEmailParametersBuilder & NoteEmailParametersBuilder::operator=(NoteEmailParametersBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteEmailParametersBuilder & NoteEmailParametersBuilder::setGuid(std::optional<QString> guid)
{
    d->m_guid = std::move(guid);
    return *this;
}

NoteEmailParametersBuilder & NoteEmailParametersBuilder::setNote(std::optional<Note> note)
{
    d->m_note = std::move(note);
    return *this;
}

NoteEmailParametersBuilder & NoteEmailParametersBuilder::setToAddresses(std::optional<QStringList> toAddresses)
{
    d->m_toAddresses = std::move(toAddresses);
    return *this;
}

NoteEmailParametersBuilder & NoteEmailParametersBuilder::setCcAddresses(std::optional<QStringList> ccAddresses)
{
    d->m_ccAddresses = std::move(ccAddresses);
    return *this;
}

NoteEmailParametersBuilder & NoteEmailParametersBuilder::setSubject(std::optional<QString> subject)
{
    d->m_subject = std::move(subject);
    return *this;
}

NoteEmailParametersBuilder & NoteEmailParametersBuilder::setMessage(std::optional<QString> message)
{
    d->m_message = std::move(message);
    return *this;
}

NoteEmailParameters NoteEmailParametersBuilder::build()
{
    NoteEmailParameters result;

    result.setGuid(std::move(d->m_guid));
    result.setNote(std::move(d->m_note));
    result.setToAddresses(std::move(d->m_toAddresses));
    result.setCcAddresses(std::move(d->m_ccAddresses));
    result.setSubject(std::move(d->m_subject));
    result.setMessage(std::move(d->m_message));

    d->m_guid = {};
    d->m_note = {};
    d->m_toAddresses = {};
    d->m_ccAddresses = {};
    d->m_subject = {};
    d->m_message = {};

    return result;
}

} // namespace qevercloud
