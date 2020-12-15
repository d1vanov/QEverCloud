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

#ifndef QEVERCLOUD_GENERATED_TAGIMPL_H
#define QEVERCLOUD_GENERATED_TAGIMPL_H

#include <qevercloud/generated/types/Tag.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Tag::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const Tag::Impl & other) = default;
    Impl(Tag::Impl && other) noexcept = default;

    Tag::Impl & operator=(const Tag::Impl & other) = delete;
    Tag::Impl & operator=(Tag::Impl && other) = delete;

    ~Impl() noexcept override = default;

    [[nodiscard]] bool operator==(const Tag::Impl & other) const noexcept;
    [[nodiscard]] bool operator!=(const Tag::Impl & other) const noexcept;

    void print(QTextStream & strm) const override;

    QString m_localId;
    QString m_parentLocalId;
    bool m_locallyModified = false;
    bool m_localOnly = false;
    bool m_locallyFavorited = false;

    std::optional<Guid> m_guid;
    std::optional<QString> m_name;
    std::optional<Guid> m_parentGuid;
    std::optional<qint32> m_updateSequenceNum;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TAGIMPL_H