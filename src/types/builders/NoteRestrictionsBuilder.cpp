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

#include <qevercloud/types/builders/NoteRestrictionsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteRestrictionsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<bool> m_noUpdateTitle;
    std::optional<bool> m_noUpdateContent;
    std::optional<bool> m_noEmail;
    std::optional<bool> m_noShare;
    std::optional<bool> m_noSharePublicly;
};

NoteRestrictionsBuilder::NoteRestrictionsBuilder() :
    d(new NoteRestrictionsBuilder::Impl)
{}

NoteRestrictionsBuilder::NoteRestrictionsBuilder(NoteRestrictionsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteRestrictionsBuilder::~NoteRestrictionsBuilder() noexcept = default;

NoteRestrictionsBuilder & NoteRestrictionsBuilder::operator=(NoteRestrictionsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteRestrictionsBuilder & NoteRestrictionsBuilder::setNoUpdateTitle(std::optional<bool> noUpdateTitle)
{
    d->m_noUpdateTitle = std::move(noUpdateTitle);
    return *this;
}

NoteRestrictionsBuilder & NoteRestrictionsBuilder::setNoUpdateContent(std::optional<bool> noUpdateContent)
{
    d->m_noUpdateContent = std::move(noUpdateContent);
    return *this;
}

NoteRestrictionsBuilder & NoteRestrictionsBuilder::setNoEmail(std::optional<bool> noEmail)
{
    d->m_noEmail = std::move(noEmail);
    return *this;
}

NoteRestrictionsBuilder & NoteRestrictionsBuilder::setNoShare(std::optional<bool> noShare)
{
    d->m_noShare = std::move(noShare);
    return *this;
}

NoteRestrictionsBuilder & NoteRestrictionsBuilder::setNoSharePublicly(std::optional<bool> noSharePublicly)
{
    d->m_noSharePublicly = std::move(noSharePublicly);
    return *this;
}

NoteRestrictions NoteRestrictionsBuilder::build()
{
    NoteRestrictions result;

    result.setNoUpdateTitle(std::move(d->m_noUpdateTitle));
    result.setNoUpdateContent(std::move(d->m_noUpdateContent));
    result.setNoEmail(std::move(d->m_noEmail));
    result.setNoShare(std::move(d->m_noShare));
    result.setNoSharePublicly(std::move(d->m_noSharePublicly));

    d->m_noUpdateTitle = {};
    d->m_noUpdateContent = {};
    d->m_noEmail = {};
    d->m_noShare = {};
    d->m_noSharePublicly = {};

    return result;
}

} // namespace qevercloud
