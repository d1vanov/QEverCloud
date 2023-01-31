/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include <qevercloud/utility/Printable.h>

#include <QIODevice>

#include <ostream>

namespace qevercloud {

QString Printable::toString() const
{
    QString str;
    QTextStream strm(&str, QIODevice::WriteOnly);
    strm << *this;
    return str;
}

QTextStream & operator<<(QTextStream & strm, const Printable & printable)
{
    printable.print(strm);
    return strm;
}

QDebug & operator<<(QDebug & dbg, const Printable & printable)
{
    QString str;
    QTextStream strm(&str);
    printable.print(strm);

    dbg << str;
    return dbg;
}

std::ostream & operator<<(std::ostream & strm, const Printable & printable)
{
    QString str;
    QTextStream textStrm(&str);
    printable.print(textStrm);

    strm << str.toStdString();
    return strm;
}

} // namespace qevercloud