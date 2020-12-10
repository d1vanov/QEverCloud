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

#ifndef QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECDATA_H
#define QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECDATA_H

#include <generated/types/NotesMetadataResultSpec.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotesMetadataResultSpec::NotesMetadataResultSpecData final:
    public QSharedData,
    public Printable
{
public:
    NotesMetadataResultSpecData() = default;
    NotesMetadataResultSpecData(const NotesMetadataResultSpecData & other) = default;
    NotesMetadataResultSpecData(NotesMetadataResultSpecData && other) noexcept = default;

    NotesMetadataResultSpecData & operator=(const NotesMetadataResultSpecData & other) = delete;
    NotesMetadataResultSpecData & operator=(NotesMetadataResultSpecData && other) = delete;

    ~NotesMetadataResultSpecData() noexcept override = default;

    [[nodiscard]] bool operator==(const NotesMetadataResultSpecData & other) const noexcept;
    [[nodiscard]] bool operator!=(const NotesMetadataResultSpecData & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_includeTitle;
    std::optional<bool> m_includeContentLength;
    std::optional<bool> m_includeCreated;
    std::optional<bool> m_includeUpdated;
    std::optional<bool> m_includeDeleted;
    std::optional<bool> m_includeUpdateSequenceNum;
    std::optional<bool> m_includeNotebookGuid;
    std::optional<bool> m_includeTagGuids;
    std::optional<bool> m_includeAttributes;
    std::optional<bool> m_includeLargestResourceMime;
    std::optional<bool> m_includeLargestResourceSize;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECDATA_H
