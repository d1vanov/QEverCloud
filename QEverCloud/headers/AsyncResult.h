/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#ifndef QEVERCLOUD_ASYNC_RESULT_H
#define QEVERCLOUD_ASYNC_RESULT_H

#include "EverCloudException.h"
#include "Export.h"
#include "Helpers.h"

#include <QNetworkRequest>
#include <QObject>

namespace qevercloud {

QT_FORWARD_DECLARE_CLASS(AsyncResultPrivate)
QT_FORWARD_DECLARE_CLASS(DurableService)

/**
 * @brief Returned by asynchonous versions of functions.
 *
 * Wait for AsyncResult::finished signal.
 *
 * Intended usage is something like this:
 *
 * @code
NoteStore* ns;
Note note;
...
QObject::connect(ns->createNoteAsync(note), &AsyncResult::finished,
                 [ns](QVariant result, EverCloudExceptionDataPtr error)
                 {
                     if (error) {
                         // do something in case of an error
                     }
                     else {
                         Note note = result.value<Note>();
                         // process returned result
                     }
                 });
 @endcode
 */
class QEVERCLOUD_EXPORT AsyncResult: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(AsyncResult)
public:
    static QVariant asIs(QByteArray replyData);

    typedef QVariant (*ReadFunctionType)(QByteArray replyData);

    AsyncResult(QString url, QByteArray postData, qint64 timeoutMsec,
                ReadFunctionType readFunction = AsyncResult::asIs,
                bool autoDelete = true, QObject * parent = nullptr);

    AsyncResult(QNetworkRequest request, QByteArray postData, qint64 timeoutMsec,
                ReadFunctionType readFunction = AsyncResult::asIs,
                bool autoDelete = true, QObject * parent = nullptr);

    /**
     * Constructor accepting already prepared value and/or exception,
     * for use in tests
     */
    AsyncResult(QVariant result, EverCloudExceptionDataPtr error,
                bool autoDelete = true, QObject * parent = nullptr);

    ~AsyncResult();

    /**
     * @brief Wait for asyncronous operation to complete.
     * @param timeout
     * Maximum time to wait in milliseconds. Forever if < 0.
     * @return true if finished successfully, false in case of the timeout
     */
    bool waitForFinished(int timeout = -1);

Q_SIGNALS:
    /**
     * @brief Emitted upon asyncronous call completition.
     * @param result
     * @param error
     * error != nullptr in case of an error. See EverCloudExceptionData
     * for more details.
     *
     * AsyncResult deletes itself after emitting this signal (if autoDelete
     * parameter passed to its constructor was set to true). You don't have to
     * manage it's lifetime explicitly.
     *
     * NOTE: in order to use this signal with queued connections (either via
     * explicit specification of Qt::QueuedConnection connection type or just
     * via connecting signals and slots of objects living in different threads),
     * you must make this call before creating any such connection:
     *
     * @code
     * qRegisterMetaType<EverCloudExceptionDataPtr>("EverCloudExceptionDataPtr");
     * @endcode
     */
    void finished(QVariant result, EverCloudExceptionDataPtr error);

private:
    friend class DurableService;

private:
    AsyncResultPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(AsyncResult)
};

} // namespace qevercloud

#endif // QEVERCLOUD_ASYNC_RESULT_H
