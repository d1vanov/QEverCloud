/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include <qevercloud/exceptions/EvernoteException.h>

namespace qevercloud {

EvernoteException::EvernoteException() :
    EverCloudException()
{}

EvernoteException::EvernoteException(QString error) :
    EverCloudException(error)
{}

EvernoteException::EvernoteException(const std::string & error) :
    EverCloudException(error)
{}

EvernoteException::EvernoteException(const char * error) :
    EverCloudException(error)
{}

void EvernoteException::raise() const
{
    throw *this;
}

EvernoteException * EvernoteException::clone() const
{
    return new EvernoteException(QString::fromUtf8(what()));
}

} // namespace qevercloud
