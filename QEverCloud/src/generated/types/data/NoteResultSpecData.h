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

#ifndef QEVERCLOUD_GENERATED_NOTERESULTSPECDATA_H
#define QEVERCLOUD_GENERATED_NOTERESULTSPECDATA_H

#include <generated/types/NoteResultSpec.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteResultSpec::NoteResultSpecData final:
    public QSharedData,
    public Printable
{
public:
    NoteResultSpecData() = default;
    NoteResultSpecData(const NoteResultSpecData & other) = default;
    NoteResultSpecData(NoteResultSpecData && other) noexcept = default;

    NoteResultSpecData & operator=(const NoteResultSpecData & other) = delete;
    NoteResultSpecData & operator=(NoteResultSpecData && other) = delete;

    ~NoteResultSpecData() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteResultSpecData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteResultSpecData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_includeContent;
    std::optional<bool> m_includeResourcesData;
    std::optional<bool> m_includeResourcesRecognition;
    std::optional<bool> m_includeResourcesAlternateData;
    std::optional<bool> m_includeSharedNotes;
    std::optional<bool> m_includeNoteAppDataValues;
    std::optional<bool> m_includeResourceAppDataValues;
    std::optional<bool> m_includeAccountLimits;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTERESULTSPECDATA_H
