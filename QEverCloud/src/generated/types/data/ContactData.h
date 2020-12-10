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

#ifndef QEVERCLOUD_GENERATED_CONTACTDATA_H
#define QEVERCLOUD_GENERATED_CONTACTDATA_H

#include <generated/types/Contact.h>
#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN Contact::ContactData final:
    public QSharedData,
    public Printable
{
public:
    ContactData() = default;
    ContactData(const ContactData & other) = default;
    ContactData(ContactData && other) noexcept = default;

    ContactData & operator=(const ContactData & other) = delete;
    ContactData & operator=(ContactData && other) = delete;

    ~ContactData() noexcept override = default;

    [[nodiscard]] bool operator==(const ContactData & other) const noexcept;
    [[nodiscard]] bool operator!=(const ContactData & other) const noexcept;

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

#endif // QEVERCLOUD_GENERATED_CONTACTDATA_H
