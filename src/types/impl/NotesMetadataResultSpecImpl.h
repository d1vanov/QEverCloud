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

#ifndef QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECIMPL_H
#define QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECIMPL_H

#include <qevercloud/types/NotesMetadataResultSpec.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NotesMetadataResultSpec::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NotesMetadataResultSpec::Impl & other) = default;
    Impl(NotesMetadataResultSpec::Impl && other) noexcept = default;

    NotesMetadataResultSpec::Impl & operator=(const NotesMetadataResultSpec::Impl & other) = delete;
    NotesMetadataResultSpec::Impl & operator=(NotesMetadataResultSpec::Impl && other) = delete;

    ~Impl() noexcept override = default;

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

#endif // QEVERCLOUD_GENERATED_NOTESMETADATARESULTSPECIMPL_H
