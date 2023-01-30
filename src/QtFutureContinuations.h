/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#pragma once

#include <QtGlobal>

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include <QException>
#include <QFutureWatcher>
#include "Qt5FutureHelpers.h"
#include "Qt5Promise.h"
#endif

#include <memory>
#include <type_traits>

namespace qevercloud {

// implementation for Qt6

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)

template <class T, class Function>
QFuture<typename QtPrivate::ResultTypeHelper<Function, T>::ResultType> then(
    QFuture<T> && future, Function && function)
{
    return future.then(std::forward<decltype(function)>(function));
}

template <class T, class Function>
std::enable_if_t<!QtPrivate::ArgResolver<Function>::HasExtraArgs, QFuture<T>>
    onFailed(QFuture<T> && future, Function && handler)
{
    return future.onFailed(std::forward<decltype(handler)>(handler));
}

#else // QT_VERSION

// implementation for Qt5

namespace detail {

class CompatException : public QException
{
public:
    CompatException(QString message) :
        m_message{std::move(message)}
    {}

    QException * clone() const override
    {
        return new CompatException(m_message);
    }

    void raise() const override
    {
        throw *this;
    }

private:
    QString m_message;
};

template <class T, class Function>
void processParentFuture(
    std::shared_ptr<
        QPromise<typename ResultTypeHelper<Function, T>::ResultType>>
        promise,
    QFuture<T> && future, Function && function)
{
    Q_ASSERT(promise);

    using ResultType = typename ResultTypeHelper<Function, T>::ResultType;

    promise->start();

    // If future contains exception, just forward it to the promise and
    // don't call the function at all
    try {
        future.waitForFinished();
    }
    catch (const QException & e) {
        promise->setException(e);
        promise->finish();
        return;
    }
    // NOTE: there cannot be other exception types in this context in Qt5
    // because exception store can only contain QExceptions

    // Try to run the handler, in case of success forward the result to promise
    // (unless it is void), catch possible exceptions and if caught put them
    // to the promise
    try {
        if constexpr (std::is_void_v<ResultType>) {
            if constexpr (std::is_void_v<T>) {
                function();
            }
            else {
                function(future.result());
            }
        }
        else {
            if constexpr (std::is_void_v<T>) {
                promise->addResult(function());
            }
            else {
                promise->addResult(function(future.result()));
            }
        }
    }
    catch (const QException & e) {
        promise->setException(e);
    }
    catch (const std::exception & e) {
        QString message = QString::fromUtf8(
            "Unknown std::exception in then future handler: {}").arg(
                QString::fromStdString(std::string{e.what()}));
        promise->setException(CompatException{std::move(message)});
    }
    catch (...) {
        promise->setException(CompatException{
            QStringLiteral("Unknown exception in then future handler")});
    }

    promise->finish();
}

} // namespace detail

template <class T, class Function>
QFuture<typename detail::ResultTypeHelper<Function, T>::ResultType> then(
    QFuture<T> && future, Function && function)
{
    using ResultType =
        typename detail::ResultTypeHelper<Function, T>::ResultType;

    auto promise = std::make_shared<QPromise<ResultType>>();
    auto result = promise->future();

    if (future.isFinished()) {
        detail::processParentFuture(
            std::move(promise), std::move(future),
            std::forward<decltype(function)>(function));
        return result;
    }

    auto watcher = std::make_unique<QFutureWatcher<T>>();
    auto * rawWatcher = watcher.get();
    QObject::connect(
        rawWatcher, &QFutureWatcher<T>::finished, rawWatcher,
        [rawWatcher, function = std::forward<decltype(function)>(function),
         promise = std::move(promise)]() mutable {
            detail::processParentFuture(
                std::move(promise), rawWatcher->future(),
                std::forward<decltype(function)>(function));
            rawWatcher->deleteLater();
        });

    QObject::connect(
        rawWatcher, &QFutureWatcher<T>::canceled, rawWatcher,
        [rawWatcher] { rawWatcher->deleteLater(); });

    watcher->setFuture(std::move(future));

    Q_UNUSED(watcher.release())
    return result;
}

namespace detail {

template <class T, class Function>
std::enable_if_t<!QtPrivate::ArgResolver<Function>::HasExtraArgs, void>
    processPossibleFutureException(
        std::shared_ptr<QPromise<T>> promise, QFuture<T> && future,
        Function && handler)
{
    Q_ASSERT(promise);

    using ArgType = typename QtPrivate::ArgResolver<Function>::First;
    using ResultType =
        typename ResultTypeHelper<Function, std::decay_t<ArgType>>::ResultType;
    static_assert(std::is_convertible_v<ResultType, T>);

    promise->start();

    try {
        try {
            future.waitForFinished();
        }
        catch (const ArgType & e) {
            try {
                if constexpr (std::is_void_v<ResultType>) {
                    handler(e);
                }
                else {
                    promise->addResult(handler(e));
                }
            }
            catch (const QException & e) {
                promise->setException(e);
            }
            catch (const std::exception & e) {
                QString message = QString::fromUtf8(
                    "Unknown std::exception in then future handler: {}").arg(
                        QString::fromStdString(std::string{e.what()}));
                promise->setException(CompatException{std::move(message)});
            }
            catch (...) {
                promise->setException(CompatException{
                    QStringLiteral("Unknown exception in then future handler")});
            }
        }
    }
    // Exception doesn't match with handler's argument type, propagate
    // the exception to be handled later.
    catch (const QException & e) {
        promise->setException(e);
    }
    catch (const std::exception & e) {
        QString message = QString::fromUtf8(
            "Unknown std::exception which did not match with onFailed future "
            "handler: {}").arg(QString::fromStdString(std::string{e.what()}));
        promise->setException(CompatException{std::move(message)});
    }
    catch (...) {
        promise->setException(CompatException{
            QStringLiteral(
                "Unknown exception which did not match with "
                "onFailed future handler")});
    }

    promise->finish();
}

} // namespace detail

// WARNING! "Chaining" of onFailed calls would only work properly with Qt5 if
// all involved exceptions subclass QException. It is due to the way exception
// storage is implemented in Qt5. In Qt6 is was made to store std::exception_ptr
// so there's no requirement to use QExceptions in Qt6.

template <class T, class Function>
std::enable_if_t<!QtPrivate::ArgResolver<Function>::HasExtraArgs, QFuture<T>>
    onFailed(QFuture<T> && future, Function && handler)
{
    auto promise = std::make_shared<QPromise<T>>();
    auto result = promise->future();

    if (future.isFinished()) {
        detail::processPossibleFutureException(
            std::move(promise), std::move(future),
            std::forward<decltype(handler)>(handler));
        return result;
    }

    auto watcher = std::make_unique<QFutureWatcher<T>>();
    watcher->setFuture(std::move(future));
    auto * rawWatcher = watcher.get();
    QObject::connect(
        rawWatcher, &QFutureWatcher<T>::finished, rawWatcher,
        [rawWatcher, promise = std::move(promise), future = std::move(future),
         handler = std::forward<decltype(handler)>(handler)]() mutable {
            rawWatcher->deleteLater();
            detail::processPossibleFutureException(
                std::move(promise), std::move(future),
                std::forward<decltype(handler)>(handler));
        });

    Q_UNUSED(watcher.release())
    return result;
}

#endif // QT_VERSION

// Convenience functions for both Qt versions

template <class T, class U, class Function>
void thenOrFailed(
    QFuture<T> && future, std::shared_ptr<QPromise<U>> promise,
    Function && function)
{
    auto thenFuture =
        then(std::move(future), std::forward<decltype(function)>(function));

    onFailed(std::move(thenFuture), [promise](const QException & e) {
        promise->setException(e);
        promise->finish();
    });
}

template <class T, class U>
void thenOrFailed(QFuture<T> && future, std::shared_ptr<QPromise<U>> promise)
{
    thenOrFailed(std::move(future), promise, [promise] { promise->finish(); });
}

} // namespace quentier::threading
