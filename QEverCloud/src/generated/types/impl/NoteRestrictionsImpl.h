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

#ifndef QEVERCLOUD_GENERATED_NOTERESTRICTIONSIMPL_H
#define QEVERCLOUD_GENERATED_NOTERESTRICTIONSIMPL_H

#include <generated/types/NoteRestrictions.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteRestrictions::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const NoteRestrictions::Impl & other) = default;
    Impl(NoteRestrictions::Impl && other) noexcept = default;

    NoteRestrictions::Impl & operator=(const NoteRestrictions::Impl & other) = delete;
    NoteRestrictions::Impl & operator=(NoteRestrictions::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const NoteRestrictions::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteRestrictions::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    std::optional<bool> m_noUpdateTitle;
    std::optional<bool> m_noUpdateContent;
    std::optional<bool> m_noEmail;
    std::optional<bool> m_noShare;
    std::optional<bool> m_noSharePublicly;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_NOTERESTRICTIONSIMPL_H
