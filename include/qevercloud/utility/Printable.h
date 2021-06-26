/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_PRINTABLE_H
#define QEVERCLOUD_PRINTABLE_H

#include <qevercloud/Export.h>

#include <QDebug>
#include <QTextStream>

#include <iosfwd>

namespace qevercloud {

class QEVERCLOUD_EXPORT Printable
{
public:
    Printable() = default;
    virtual ~Printable() noexcept = default;

    virtual void print(QTextStream & strm) const = 0;

    virtual QString toString() const;

    friend QEVERCLOUD_EXPORT QTextStream & operator <<(
        QTextStream & strm, const Printable & printable);

    friend QEVERCLOUD_EXPORT QDebug & operator <<(
        QDebug & dbg, const Printable & printable);

    friend QEVERCLOUD_EXPORT std::ostream & operator<<(
        std::ostream & strm, const Printable & printable);
};

} // namespace qevercloud

#endif // QEVERCLOUD_PRINTABLE_H
