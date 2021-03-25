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

#ifndef QEVERCLOUD_GENERATED_CONTACTIMPL
#define QEVERCLOUD_GENERATED_CONTACTIMPL

#include <qevercloud/types/Contact.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Contact::Impl final:
    public QSharedData,
    public Printable
{
public:
    Impl() = default;
    Impl(const Contact::Impl & other) = default;
    Impl(Contact::Impl && other) noexcept = default;

    Contact::Impl & operator=(const Contact::Impl & other) = delete;
    Contact::Impl & operator=(Contact::Impl && other) = delete;

    ~Impl() noexcept override = default;

    void print(QTextStream & strm) const override;

    std::optional<QString> m_name;
    std::optional<QString> m_id;
    std::optional<ContactType> m_type;
    std::optional<QString> m_photoUrl;
    std::optional<Timestamp> m_photoLastUpdated;
    std::optional<QByteArray> m_messagingPermit;
    std::optional<Timestamp> m_messagingPermitExpires;
};

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_CONTACTIMPL
