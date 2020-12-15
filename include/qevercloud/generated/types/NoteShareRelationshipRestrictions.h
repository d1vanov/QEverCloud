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

#ifndef QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONS_H
#define QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONS_H

#include <qevercloud/Export.h>

#include <qevercloud/EverCloudException.h>
#include <qevercloud/generated/EDAMErrorCode.h>
#include <qevercloud/generated/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <optional>

namespace qevercloud {

/**
 * This structure is used by the service to communicate to clients, via
 * getNoteShareRelationships, which privilege levels are assignable to the
 * target of a note share relationship.
 *
 * */
class QEVERCLOUD_EXPORT NoteShareRelationshipRestrictions: public Printable
{
    Q_GADGET
public:
    NoteShareRelationshipRestrictions();
    NoteShareRelationshipRestrictions(const NoteShareRelationshipRestrictions & other);
    NoteShareRelationshipRestrictions(NoteShareRelationshipRestrictions && other) noexcept;
    ~NoteShareRelationshipRestrictions() noexcept override;

    NoteShareRelationshipRestrictions & operator=(const NoteShareRelationshipRestrictions & other);
    NoteShareRelationshipRestrictions & operator=(NoteShareRelationshipRestrictions && other) noexcept;

    /**
    This value is true if the user is not allowed to set the privilege
     level to SharedNotePrivilegeLevel.READ_NOTE.
    */
    [[nodiscard]] const std::optional<bool> & noSetReadNote() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetReadNote();
    void setNoSetReadNote(std::optional<bool> noSetReadNote);

    /**
    This value is true if the user is not allowed to set the privilege
     level to SharedNotePrivilegeLevel.MODIFY_NOTE.
    */
    [[nodiscard]] const std::optional<bool> & noSetModifyNote() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetModifyNote();
    void setNoSetModifyNote(std::optional<bool> noSetModifyNote);

    /**
    This value is true if the user is not allowed to set the
     privilege level to SharedNotePrivilegeLevel.FULL_ACCESS.
    */
    [[nodiscard]] const std::optional<bool> & noSetFullAccess() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableNoSetFullAccess();
    void setNoSetFullAccess(std::optional<bool> noSetFullAccess);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const NoteShareRelationshipRestrictions & other) const noexcept;
    [[nodiscard]] bool operator!=(const NoteShareRelationshipRestrictions & other) const noexcept;

    Q_PROPERTY(std::optional<bool> noSetReadNote READ noSetReadNote WRITE setNoSetReadNote)
    Q_PROPERTY(std::optional<bool> noSetModifyNote READ noSetModifyNote WRITE setNoSetModifyNote)
    Q_PROPERTY(std::optional<bool> noSetFullAccess READ noSetFullAccess WRITE setNoSetFullAccess)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::NoteShareRelationshipRestrictions)

#endif // QEVERCLOUD_GENERATED_NOTESHARERELATIONSHIPRESTRICTIONS_H