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

#ifndef QEVERCLOUD_GENERATED_PUBLISHING
#define QEVERCLOUD_GENERATED_PUBLISHING

#include <qevercloud/Export.h>

#include <qevercloud/EDAMErrorCode.h>
#include <qevercloud/exceptions/EverCloudException.h>
#include <qevercloud/types/TypeAliases.h>
#include <qevercloud/utility/Printable.h>
#include <QSharedDataPointer>
#include <optional>

namespace qevercloud {

/**
 * If a Notebook has been opened to the public, the Notebook will have a
 * reference to one of these structures, which gives the location and optional
 * description of the externally-visible public Notebook.
 * */
class QEVERCLOUD_EXPORT Publishing: public Printable
{
    Q_GADGET
public:
    Publishing();
    Publishing(const Publishing & other);
    Publishing(Publishing && other) noexcept;
    ~Publishing() noexcept override;

    Publishing & operator=(const Publishing & other);
    Publishing & operator=(Publishing && other) noexcept;

    /**
     * If this field is present, then the notebook is published for
     * mass consumption on the Internet under the provided URI, which is
     * relative to a defined base publishing URI defined by the service.
     * This field can only be modified via the web service GUI ... publishing
     * cannot be modified via an offline client.
     * Length: EDAM_PUBLISHING_URI_LEN_MIN - EDAM_PUBLISHING_URI_LEN_MAX
     * Regex: EDAM_PUBLISHING_URI_REGEX
     */
    [[nodiscard]] const std::optional<QString> & uri() const noexcept;
    void setUri(std::optional<QString> uri);

    /**
     * When the notes are publicly displayed, they will be sorted
     * based on the requested criteria.
     */
    [[nodiscard]] const std::optional<NoteSortOrder> & order() const noexcept;
    [[nodiscard]] std::optional<NoteSortOrder> & mutableOrder();
    void setOrder(std::optional<NoteSortOrder> order);

    /**
     * If this is set to true, then the public notes will be
     * displayed in ascending order (e.g. from oldest to newest). Otherwise,
     * the notes will be displayed in descending order (e.g. newest to oldest).
     */
    [[nodiscard]] const std::optional<bool> & ascending() const noexcept;
    [[nodiscard]] std::optional<bool> & mutableAscending();
    void setAscending(std::optional<bool> ascending);

    /**
     * This field may be used to provide a short
     * description of the notebook, which may be displayed when (e.g.) the
     * notebook is shown in a public view. Can't begin or end with a space.
     * Length: EDAM_PUBLISHING_DESCRIPTION_LEN_MIN -
     * EDAM_PUBLISHING_DESCRIPTION_LEN_MAX
     * Regex: EDAM_PUBLISHING_DESCRIPTION_REGEX
     */
    [[nodiscard]] const std::optional<QString> & publicDescription() const noexcept;
    void setPublicDescription(std::optional<QString> publicDescription);

    void print(QTextStream & strm) const override;

    friend QEVERCLOUD_EXPORT QTextStream & operator<<(
        QTextStream & strm, const Publishing & publishing);

    friend QEVERCLOUD_EXPORT QDebug & operator<<(
        QDebug & dbg, const Publishing & publishing);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const Publishing & publishing);

    Q_PROPERTY(std::optional<QString> uri READ uri WRITE setUri)
    Q_PROPERTY(std::optional<NoteSortOrder> order READ order WRITE setOrder)
    Q_PROPERTY(std::optional<bool> ascending READ ascending WRITE setAscending)
    Q_PROPERTY(std::optional<QString> publicDescription READ publicDescription WRITE setPublicDescription)

private:
    class Impl;
    QSharedDataPointer<Impl> d;
};

[[nodiscard]] QEVERCLOUD_EXPORT bool operator==(const Publishing & lhs, const Publishing & rhs) noexcept;
[[nodiscard]] QEVERCLOUD_EXPORT bool operator!=(const Publishing & lhs, const Publishing & rhs) noexcept;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_PUBLISHING