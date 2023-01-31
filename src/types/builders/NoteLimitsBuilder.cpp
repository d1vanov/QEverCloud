/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <qevercloud/types/builders/NoteLimitsBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN NoteLimitsBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<qint32> m_noteResourceCountMax;
    std::optional<qint64> m_uploadLimit;
    std::optional<qint64> m_resourceSizeMax;
    std::optional<qint64> m_noteSizeMax;
    std::optional<qint64> m_uploaded;
};

NoteLimitsBuilder::NoteLimitsBuilder() :
    d(new NoteLimitsBuilder::Impl)
{}

NoteLimitsBuilder::NoteLimitsBuilder(NoteLimitsBuilder && other) noexcept :
    d{std::move(other.d)}
{}

NoteLimitsBuilder::~NoteLimitsBuilder() noexcept = default;

NoteLimitsBuilder & NoteLimitsBuilder::operator=(NoteLimitsBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

NoteLimitsBuilder & NoteLimitsBuilder::setNoteResourceCountMax(std::optional<qint32> noteResourceCountMax)
{
    d->m_noteResourceCountMax = std::move(noteResourceCountMax);
    return *this;
}

NoteLimitsBuilder & NoteLimitsBuilder::setUploadLimit(std::optional<qint64> uploadLimit)
{
    d->m_uploadLimit = std::move(uploadLimit);
    return *this;
}

NoteLimitsBuilder & NoteLimitsBuilder::setResourceSizeMax(std::optional<qint64> resourceSizeMax)
{
    d->m_resourceSizeMax = std::move(resourceSizeMax);
    return *this;
}

NoteLimitsBuilder & NoteLimitsBuilder::setNoteSizeMax(std::optional<qint64> noteSizeMax)
{
    d->m_noteSizeMax = std::move(noteSizeMax);
    return *this;
}

NoteLimitsBuilder & NoteLimitsBuilder::setUploaded(std::optional<qint64> uploaded)
{
    d->m_uploaded = std::move(uploaded);
    return *this;
}

NoteLimits NoteLimitsBuilder::build()
{
    NoteLimits result;

    result.setNoteResourceCountMax(std::move(d->m_noteResourceCountMax));
    result.setUploadLimit(std::move(d->m_uploadLimit));
    result.setResourceSizeMax(std::move(d->m_resourceSizeMax));
    result.setNoteSizeMax(std::move(d->m_noteSizeMax));
    result.setUploaded(std::move(d->m_uploaded));

    d->m_noteResourceCountMax = {};
    d->m_uploadLimit = {};
    d->m_resourceSizeMax = {};
    d->m_noteSizeMax = {};
    d->m_uploaded = {};

    return result;
}

} // namespace qevercloud
