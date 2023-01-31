/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_TAGIMPL
#define QEVERCLOUD_GENERATED_TAGIMPL

#include <qevercloud/types/Tag.h>
#include <QHash>
#include <QSharedData>
#include <QVariant>

namespace qevercloud {

class Q_DECL_HIDDEN Tag::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl();
    Impl(const Tag::Impl & other) = default;
    Impl(Tag::Impl && other) noexcept = default;

    Tag::Impl & operator=(const Tag::Impl & other) = delete;
    Tag::Impl & operator=(Tag::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    QString m_localId;
    bool m_isLocallyModified = false;
    bool m_isLocalOnly = false;
    bool m_isLocallyFavorited = false;
    QHash<QString, QVariant> m_localData;
    std::optional<Guid> m_linkedNotebookGuid;
    QString m_parentTagLocalId;
    std::optional<Guid> m_guid;
    std::optional<QString> m_name;
    std::optional<Guid> m_parentGuid;
    std::optional<qint32> m_updateSequenceNum;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TAGIMPL