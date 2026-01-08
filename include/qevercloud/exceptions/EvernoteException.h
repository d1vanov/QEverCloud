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

    void raise() const override;

    [[nodiscard]] EvernoteException * clone() const override;
};

} // namespace qevercloud

#endif // QEVERCLOUD_EVERNOTE_EXCEPTION_H
