/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_EVERNOTE_EXCEPTION_H
#define QEVERCLOUD_EVERNOTE_EXCEPTION_H

#include <qevercloud/Export.h>
#include <qevercloud/exceptions/EverCloudException.h>

#include <QObject>
#include <QString>

#include <exception>
#include <memory>

namespace qevercloud {

/**
 * All exception sent by Evernote servers (as opposed to other error conditions,
 * for example http errors) are descendants of this class.
 */
class QEVERCLOUD_EXPORT EvernoteException: public EverCloudException
{
public:
    explicit EvernoteException();
    explicit EvernoteException(QString error);
    explicit EvernoteException(const std::string & error);
    explicit EvernoteException(const char * error);

    [[nodiscard]] EverCloudExceptionDataPtr exceptionData() const override;
};

/**
 * Asynchronous API conterpart of EvernoteException. See EverCloudExceptionData
 * for more details.
 */
class QEVERCLOUD_EXPORT EvernoteExceptionData: public EverCloudExceptionData
{
    Q_OBJECT
    Q_DISABLE_COPY(EvernoteExceptionData)
public:
    explicit EvernoteExceptionData(QString error);
    void throwException() const override;
};


} // namespace qevercloud

#endif // QEVERCLOUD_EVERNOTE_EXCEPTION_H
