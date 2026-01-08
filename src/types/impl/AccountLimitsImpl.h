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

#ifndef QEVERCLOUD_GENERATED_ACCOUNTLIMITSIMPL
#define QEVERCLOUD_GENERATED_ACCOUNTLIMITSIMPL

#include <qevercloud/types/AccountLimits.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN AccountLimits::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const AccountLimits::Impl & other) = default;
    Impl(AccountLimits::Impl && other) noexcept = default;

    AccountLimits::Impl & operator=(const AccountLimits::Impl & other) = delete;
    AccountLimits::Impl & operator=(AccountLimits::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<qint32> m_userMailLimitDaily;
    std::optional<qint64> m_noteSizeMax;
    std::optional<qint64> m_resourceSizeMax;
    std::optional<qint32> m_userLinkedNotebookMax;
    std::optional<qint64> m_uploadLimit;
    std::optional<qint32> m_userNoteCountMax;
    std::optional<qint32> m_userNotebookCountMax;
    std::optional<qint32> m_userTagCountMax;
    std::optional<qint32> m_noteTagCountMax;
    std::optional<qint32> m_userSavedSearchesMax;
    std::optional<qint32> m_noteResourceCountMax;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_ACCOUNTLIMITSIMPL
