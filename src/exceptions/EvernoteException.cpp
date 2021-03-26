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

EverCloudExceptionDataPtr EvernoteException::exceptionData() const
{
    return std::make_shared<EverCloudExceptionData>(QString::fromUtf8(what()));
}

EvernoteExceptionData::EvernoteExceptionData(QString error) :
    EverCloudExceptionData(error)
{}

void EvernoteExceptionData::throwException() const
{
    throw EvernoteException(errorMessage);
}

} // namespace qevercloud
