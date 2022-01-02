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

#ifndef QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSIMPL
#define QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSIMPL

#include <qevercloud/types/NoteEmailParameters.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteEmailParameters::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteEmailParameters::Impl & other) = default;
    Impl(NoteEmailParameters::Impl && other) noexcept = default;

    NoteEmailParameters::Impl & operator=(const NoteEmailParameters::Impl & other) = delete;
    NoteEmailParameters::Impl & operator=(NoteEmailParameters::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_guid;
    std::optional<Note> m_note;
    std::optional<QStringList> m_toAddresses;
    std::optional<QStringList> m_ccAddresses;
    std::optional<QString> m_subject;
    std::optional<QString> m_message;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSIMPL
