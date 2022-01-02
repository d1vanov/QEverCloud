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

#include <qevercloud/types/builders/BusinessNotebookBuilder.h>

#include <QSharedData>

namespace qevercloud {

class Q_DECL_HIDDEN BusinessNotebookBuilder::Impl final:
    public QSharedData
{
public:
    std::optional<QString> m_notebookDescription;
    std::optional<SharedNotebookPrivilegeLevel> m_privilege;
    std::optional<bool> m_recommended;
};

BusinessNotebookBuilder::BusinessNotebookBuilder() :
    d(new BusinessNotebookBuilder::Impl)
{}

BusinessNotebookBuilder::BusinessNotebookBuilder(BusinessNotebookBuilder && other) noexcept :
    d{std::move(other.d)}
{}

BusinessNotebookBuilder::~BusinessNotebookBuilder() noexcept = default;

BusinessNotebookBuilder & BusinessNotebookBuilder::operator=(BusinessNotebookBuilder && other) noexcept
{
    if (this != &other) {
        d = std::move(other.d);
    }

    return *this;
}

BusinessNotebookBuilder & BusinessNotebookBuilder::setNotebookDescription(std::optional<QString> notebookDescription)
{
    d->m_notebookDescription = std::move(notebookDescription);
    return *this;
}

BusinessNotebookBuilder & BusinessNotebookBuilder::setPrivilege(std::optional<SharedNotebookPrivilegeLevel> privilege)
{
    d->m_privilege = std::move(privilege);
    return *this;
}

BusinessNotebookBuilder & BusinessNotebookBuilder::setRecommended(std::optional<bool> recommended)
{
    d->m_recommended = std::move(recommended);
    return *this;
}

BusinessNotebook BusinessNotebookBuilder::build()
{
    BusinessNotebook result;

    result.setNotebookDescription(std::move(d->m_notebookDescription));
    result.setPrivilege(std::move(d->m_privilege));
    result.setRecommended(std::move(d->m_recommended));

    d->m_notebookDescription = {};
    d->m_privilege = {};
    d->m_recommended = {};

    return result;
}

} // namespace qevercloud
