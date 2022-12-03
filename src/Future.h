/**
 * Copyright (c) 2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_FUTURE_H
#define QEVERCLOUD_FUTURE_H

#include <QFuture>
#include <QFutureWatcher>
#include <QVariant>

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QPromise>
#else
#include "Qt5Promise.h"
#endif

#include <memory>
#include <type_traits>

namespace qevercloud {

namespace detail {

template <class T>
void deleteFutureWatcherLater(QFutureWatcher<T> * watcher) noexcept
{
    watcher->deleteLater();
}

/**
 * Create QFutureWatcher which would be deleted through a call to deleteLater
 */
template <class T>
[[nodiscard]] std::shared_ptr<QFutureWatcher<T>> makeFutureWatcher()
{
    return std::shared_ptr<QFutureWatcher<T>>(
        new QFutureWatcher<T>, deleteFutureWatcherLater<T>);
}

} // namespace detail

template <class T>
[[nodiscard]] QFuture<T> convertFromVariantFuture(
    QFuture<QVariant> variantFuture)
{
    if (variantFuture.isFinished()) {
        QPromise<T> promise;
        auto future = promise.future();
        promise.start();
        try {
            variantFuture.waitForFinished();
        }
        catch (const QException & e) {
            promise.setException(e);
            promise.finish();
            return future;
        }

        if constexpr (!std::is_void_v<T>) {
            Q_ASSERT(variantFuture.resultCount() == 1);
            auto variantValue = variantFuture.result();
            Q_ASSERT(variantValue.canConvert<T>());
            promise.addResult(variantValue.value<T>());
        }

        promise.finish();
        return future;
    }

    QPromise<T> promise;
    auto future = promise.future();
    promise.start();

    auto watcher = detail::makeFutureWatcher<QVariant>();
    auto * rawWatcher = watcher.get();
    QObject::connect(
        rawWatcher, &QFutureWatcher<QVariant>::finished, rawWatcher,
        [watcher = std::move(watcher), promise = std::move(promise)]() mutable {
            auto future = watcher->future();
            try {
                future.waitForFinished();
            }
            catch (const QException & e) {
                promise.setException(e);
                promise.finish();
                return;
            }

            if constexpr (!std::is_void_v<T>) {
                Q_ASSERT(future.resultCount() == 1);
                auto variantValue = future.result();
                Q_ASSERT(variantValue.canConvert<T>());
                promise.addResult(variantValue.value<T>());
            }

            promise.finish();
        });

    rawWatcher->setFuture(std::move(variantFuture));
    return future;
}

template <class T>
[[nodiscard]] QFuture<QVariant> convertToVariantFuture(
    QFuture<T> valueFuture)
{
    if (valueFuture.isFinished()) {
        QPromise<QVariant> promise;
        auto future = promise.future();
        promise.start();
        try {
            valueFuture.waitForFinished();
        }
        catch (const QException & e) {
            promise.setException(e);
            promise.finish();
            return future;
        }

        if constexpr (!std::is_void_v<T>) {
            Q_ASSERT(valueFuture.resultCount() == 1);
            promise.addResult(QVariant::fromValue(valueFuture.result()));
        }
        else {
            promise.addResult(QVariant{});
        }

        promise.finish();
        return future;
    }

    QPromise<QVariant> promise;
    auto future = promise.future();
    promise.start();

    auto watcher = detail::makeFutureWatcher<T>();
    auto * rawWatcher = watcher.get();
    QObject::connect(
        rawWatcher, &QFutureWatcher<T>::finished, rawWatcher,
        [watcher = std::move(watcher), promise = std::move(promise)]() mutable {
            auto future = watcher->future();
            try {
                future.waitForFinished();
            }
            catch (const QException & e) {
                promise.setException(e);
                promise.finish();
                return;
            }

            if constexpr (!std::is_void_v<T>) {
                Q_ASSERT(future.resultCount() == 1);
                promise.addResult(QVariant::fromValue(future.result()));
            }
            else {
                promise.addResult(QVariant{});
            }

            promise.finish();
        });

    rawWatcher->setFuture(std::move(valueFuture));
    return future;
}

} // namespace qevercloud

#endif // QEVERCLOUD_FUTURE_H
