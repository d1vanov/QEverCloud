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

#ifndef QEVERCLOUD_GENERATED_NOTERESULTSPECIMPL
#define QEVERCLOUD_GENERATED_NOTERESULTSPECIMPL

#include <qevercloud/types/NoteResultSpec.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteResultSpec::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteResultSpec::Impl & other) = default;
    Impl(NoteResultSpec::Impl && other) noexcept = default;

    NoteResultSpec::Impl & operator=(const NoteResultSpec::Impl & other) = delete;
    NoteResultSpec::Impl & operator=(NoteResultSpec::Impl && other) = delete;

    ~Impl() noexcept override = default;

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

#endif // QEVERCLOUD_GENERATED_NOTERESULTSPECIMPL
