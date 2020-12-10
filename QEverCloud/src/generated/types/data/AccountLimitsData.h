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

#ifndef QEVERCLOUD_GENERATED_ACCOUNTLIMITSDATA_H
#define QEVERCLOUD_GENERATED_ACCOUNTLIMITSDATA_H

#include <generated/types/AccountLimits.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN AccountLimits::AccountLimitsData final:
    public QSharedData,
    public Printable
{
public:
    AccountLimitsData() = default;
    AccountLimitsData(const AccountLimitsData & other) = default;
    AccountLimitsData(AccountLimitsData && other) noexcept = default;

    AccountLimitsData & operator=(const AccountLimitsData & other) = delete;
    AccountLimitsData & operator=(AccountLimitsData && other) = delete;

    ~AccountLimitsData() noexcept override = default;

    [[nodiscard]] bool operator==(const AccountLimitsData & other) const noexcept;
    [[nodiscard]] bool operator!=(const AccountLimitsData & other) const noexcept;

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

#endif // QEVERCLOUD_GENERATED_ACCOUNTLIMITSDATA_H
