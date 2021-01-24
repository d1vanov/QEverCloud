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

#include <qevercloud/generated/types/NoteEmailParameters.h>

#include "impl/NoteEmailParametersImpl.h"

namespace qevercloud {

NoteEmailParameters::NoteEmailParameters() :
    d(new NoteEmailParameters::Impl)
 {}

NoteEmailParameters::NoteEmailParameters(const NoteEmailParameters & other) :
    d(other.d)
{}

NoteEmailParameters::NoteEmailParameters(NoteEmailParameters && other) noexcept :
    d(std::move(other.d))
{}

NoteEmailParameters::~NoteEmailParameters() noexcept {}

NoteEmailParameters & NoteEmailParameters::operator=(const NoteEmailParameters & other)
{
    if (this != &other) {
        d = other.d;
    }

    return *this;
}

NoteEmailParameters & NoteEmailParameters::operator=(NoteEmailParameters && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

const std::optional<QString> & NoteEmailParameters::guid() const noexcept
{
    return d->m_guid;
}

void NoteEmailParameters::setGuid(std::optional<QString> guid)
{
    d->m_guid = guid;
}

const std::optional<Note> & NoteEmailParameters::note() const noexcept
{
    return d->m_note;
}

std::optional<Note> & NoteEmailParameters::mutableNote()
{
    return d->m_note;
}

void NoteEmailParameters::setNote(std::optional<Note> note)
{
    d->m_note = note;
}

const std::optional<QStringList> & NoteEmailParameters::toAddresses() const noexcept
{
    return d->m_toAddresses;
}

std::optional<QStringList> & NoteEmailParameters::mutableToAddresses()
{
    return d->m_toAddresses;
}

void NoteEmailParameters::setToAddresses(std::optional<QStringList> toAddresses)
{
    d->m_toAddresses = toAddresses;
}

const std::optional<QStringList> & NoteEmailParameters::ccAddresses() const noexcept
{
    return d->m_ccAddresses;
}

std::optional<QStringList> & NoteEmailParameters::mutableCcAddresses()
{
    return d->m_ccAddresses;
}

void NoteEmailParameters::setCcAddresses(std::optional<QStringList> ccAddresses)
{
    d->m_ccAddresses = ccAddresses;
}

const std::optional<QString> & NoteEmailParameters::subject() const noexcept
{
    return d->m_subject;
}

void NoteEmailParameters::setSubject(std::optional<QString> subject)
{
    d->m_subject = subject;
}

const std::optional<QString> & NoteEmailParameters::message() const noexcept
{
    return d->m_message;
}

void NoteEmailParameters::setMessage(std::optional<QString> message)
{
    d->m_message = message;
}

void NoteEmailParameters::print(QTextStream & strm) const
{
    d->print(strm);
}

bool NoteEmailParameters::operator==(const NoteEmailParameters & other) const noexcept
{
    return *d == *other.d;
}

bool NoteEmailParameters::operator!=(const NoteEmailParameters & other) const noexcept
{
    return !(*this == other);
}

} // namespace qevercloud
