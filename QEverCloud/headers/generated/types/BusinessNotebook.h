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

#ifndef QEVERCLOUD_GENERATED_BUSINESSNOTEBOOK_H
#define QEVERCLOUD_GENERATED_BUSINESSNOTEBOOK_H

#include "../../Export.h"

#include "../../EverCloudException.h"
#include "../../Printable.h"
#include "../EDAMErrorCode.h"
#include "TypeAliases.h"
#include <optional>

namespace qevercloud {

/**
 * If a Notebook contained in an Evernote Business account has been published
 * the to business library, the Notebook will have a reference to one of these
 * structures, which specifies how the Notebook will be represented in the
 * library.
 *
 * */
class QEVERCLOUD_EXPORT BusinessNotebook: public Printable
{
    Q_GADGET
public:
    BusinessNotebook();
    BusinessNotebook(const BusinessNotebook & other);
    BusinessNotebook(BusinessNotebook && other) noexcept;
    ~BusinessNotebook() noexcept override;

    BusinessNotebook & operator=(const BusinessNotebook & other);
    BusinessNotebook & operator=(BusinessNotebook && other) noexcept;

    /**
    A short description of the notebook's content that will be displayed
           in the business library user interface. The description may not begin
           or end with whitespace.
       <br/>
       Length: EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_LEN_MIN -
               EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_LEN_MAX
       <br/>
       Regex:  EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_REGEX
    */
    [[nodiscard]] const std::optional<QString> & notebookDescription() const noexcept;
    void setNotebookDescription(std::optional<QString> notebookDescription);

    /**
    The privileges that will be granted to users who join the notebook through
           the business library.
    */
    [[nodiscard]] const std::optional<SharedNotebookPrivilegeLevel> & privilege() const noexcept;
    [[nodiscard]] std::optional<SharedNotebookPrivilegeLevel> & mutablePrivilege();
    void setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege);

    /**
    Whether the notebook should be "recommended" when displayed in the business
           library user interface.
    */
    [[nodiscard]] const std::optional<bool> & recommended() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableRecommended();
    void setRecommended(std::optional<bool> recommended);

    void print(QTextStream & strm) const override;

    [[nodiscard]] bool operator==(const BusinessNotebook & other) const noexcept;
    [[nodiscard]] bool operator!=(const BusinessNotebook & other) const noexcept;

    Q_PROPERTY(std::optional<QString> notebookDescription READ notebookDescription WRITE setNotebookDescription)
    Q_PROPERTY(std::optional<SharedNotebookPrivilegeLevel> privilege READ privilege WRITE setPrivilege)
    Q_PROPERTY(std::optional<bool> recommended READ recommended WRITE setRecommended)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

} // namespace qevercloud

Q_DECLARE_METATYPE(qevercloud::BusinessNotebook)

#endif // QEVERCLOUD_GENERATED_BUSINESSNOTEBOOK_H
