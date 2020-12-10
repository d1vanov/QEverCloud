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

#ifndef QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSDATA_H
#define QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSDATA_H

#include <generated/types/NoteEmailParameters.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteEmailParameters::NoteEmailParametersData final:
    public QSharedData,
    public Printable
{
public:
    NoteEmailParametersData() = default;
    NoteEmailParametersData(const NoteEmailParametersData & other) = default;
    NoteEmailParametersData(NoteEmailParametersData && other) noexcept = default;

    NoteEmailParametersData & operator=(const NoteEmailParametersData & other) = delete;
    NoteEmailParametersData & operator=(NoteEmailParametersData && other) = delete;

    ~NoteEmailParametersData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteEmailParametersData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteEmailParametersData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_guid;
    std::optional<Note> m_note;
    std::optional<QStringList> m_toAddresses;
    std::optional<QStringList> m_ccAddresses;
    std::optional<QString> m_subject;
    std::optional<QString> m_message;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTEEMAILPARAMETERSDATA_H
