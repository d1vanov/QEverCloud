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

#ifndef QEVERCLOUD_GENERATED_TAGDATA_H
#define QEVERCLOUD_GENERATED_TAGDATA_H

#include <generated/types/Tag.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Tag::TagData final:
    public QSharedData,
    public Printable
{
public:
    TagData() = default;
    TagData(const TagData & other) = default;
    TagData(TagData && other) noexcept = default;

    TagData & operator=(const TagData & other) = delete;
    TagData & operator=(TagData && other) = delete;

    ~TagData() noexcept override = default;

    [[nodiscard]] bool operator==(const TagData & other) const noexcept;
    [[nodiscard]] bool operator!=(const TagData & other) const noexcept;

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

#endif // QEVERCLOUD_GENERATED_TAGDATA_H
