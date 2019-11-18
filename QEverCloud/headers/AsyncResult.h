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
#include <QUuid>

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
                 [ns](QVariant result, QSharedPointer<EverCloudExceptionData> error)
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

    AsyncResult(QString url, QByteArray postData,
                qint64 timeoutMsec, QUuid requestId,
                ReadFunctionType readFunction = AsyncResult::asIs,
                bool autoDelete = true, QObject * parent = nullptr);

    AsyncResult(QNetworkRequest request, QByteArray postData,
                qint64 timeoutMsec, QUuid requestId,
                ReadFunctionType readFunction = AsyncResult::asIs,
                bool autoDelete = true, QObject * parent = nullptr);

    /**
     * Constructor accepting already prepared value and/or exception,
     * for use in tests
     */
    AsyncResult(QVariant result, QSharedPointer<EverCloudExceptionData> error,
                QUuid requestId, bool autoDelete = true,
                QObject * parent = nullptr);

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
     */
    void finished(QVariant result, QSharedPointer<EverCloudExceptionData> error);

private:
    friend class DurableService;

private:
    AsyncResultPrivate * const d_ptr;
    Q_DECLARE_PRIVATE(AsyncResult)
};

} // namespace qevercloud

#endif // QEVERCLOUD_ASYNC_RESULT_H
