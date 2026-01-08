/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#pragma once

#include "Qt5Promise.h"

#include <QFuture>

#include <type_traits>

// Backports of some helpers for QFuture continuations from Qt6 to Qt5
namespace QtFuture {

// Inherit option from Qt6 is not supported in Qt5
enum class Launch
{
    Sync,
    Async,
};

} // namespace QtFuture

namespace QtPrivate {

template <typename...>
struct ArgsType;

template <typename Arg, typename... Args>
struct ArgsType<Arg, Args...>
{
    using First = Arg;
    using PromiseType = void;
    using IsPromise = std::false_type;
    static const bool HasExtraArgs = (sizeof...(Args) > 0);

    template <class Class, class Callable>
    static const bool CanInvokeWithArgs =
        std::is_invocable_v<Callable, Class, Arg, Args...>;
};

template <typename Arg, typename... Args>
struct ArgsType<QPromise<Arg> &, Args...>
{
    using First = QPromise<Arg> &;
    using PromiseType = Arg;
    using IsPromise = std::true_type;
    static const bool HasExtraArgs = (sizeof...(Args) > 0);

    template <class Class, class Callable>
    static const bool CanInvokeWithArgs =
        std::is_invocable_v<Callable, Class, QPromise<Arg> &, Args...>;
};

template <>
struct ArgsType<>
{
    using First = void;
    using PromiseType = void;
    using IsPromise = std::false_type;
    static const bool HasExtraArgs = false;
    using AllArgs = void;

    template <class Class, class Callable>
    static const bool CanInvokeWithArgs = std::is_invocable_v<Callable, Class>;
};

template <typename F>
struct ArgResolver : ArgResolver<decltype(&std::decay_t<F>::operator())>
{};

template <typename F>
struct ArgResolver<std::reference_wrapper<F>> :
    ArgResolver<decltype(&std::decay_t<F>::operator())>
{};

template <typename R, typename... Args>
struct ArgResolver<R(Args...)> : public ArgsType<Args...>
{};

template <typename R, typename... Args>
struct ArgResolver<R (*)(Args...)> : public ArgsType<Args...>
{};

template <typename R, typename... Args>
struct ArgResolver<R (*&)(Args...)> : public ArgsType<Args...>
{};

template <typename R, typename... Args>
struct ArgResolver<R (*const)(Args...)> : public ArgsType<Args...>
{};

template <typename R, typename... Args>
struct ArgResolver<R (&)(Args...)> : public ArgsType<Args...>
{};

template <typename Class, typename R, typename... Args>
struct ArgResolver<R (Class::*)(Args...)> : public ArgsType<Args...>
{};

template <typename Class, typename R, typename... Args>
struct ArgResolver<R (Class::*)(Args...) noexcept> : public ArgsType<Args...>
{};

template <typename Class, typename R, typename... Args>
struct ArgResolver<R (Class::*)(Args...) const> : public ArgsType<Args...>
{};

template <typename Class, typename R, typename... Args>
struct ArgResolver<R (Class::*)(Args...) const noexcept> :
    public ArgsType<Args...>
{};

template <typename Class, typename R, typename... Args>
struct ArgResolver<R (Class::*const)(Args...) const> : public ArgsType<Args...>
{};

template <typename Class, typename R, typename... Args>
struct ArgResolver<R (Class::*const)(Args...) const noexcept> :
    public ArgsType<Args...>
{};

} // namespace QtPrivate

namespace qevercloud::detail {

template <typename F, typename Arg, typename Enable = void>
struct ResultTypeHelper
{};

// The callable takes an argument of type Arg
template <typename F, typename Arg>
struct ResultTypeHelper<
    F, Arg,
    typename std::enable_if_t<
        !std::is_invocable_v<std::decay_t<F>, QFuture<Arg>>>>
{
    using ResultType = std::invoke_result_t<std::decay_t<F>, std::decay_t<Arg>>;
};

// The callable takes an argument of type QFuture<Arg>
template <class F, class Arg>
struct ResultTypeHelper<
    F, Arg,
    typename std::enable_if_t<
        std::is_invocable_v<std::decay_t<F>, QFuture<Arg>>>>
{
    using ResultType = std::invoke_result_t<std::decay_t<F>, QFuture<Arg>>;
};

// The callable takes an argument of type QFuture<void>
template <class F>
struct ResultTypeHelper<
    F, void,
    typename std::enable_if_t<
        std::is_invocable_v<std::decay_t<F>, QFuture<void>>>>
{
    using ResultType = std::invoke_result_t<std::decay_t<F>, QFuture<void>>;
};

// The callable doesn't take argument
template <class F>
struct ResultTypeHelper<
    F, void,
    typename std::enable_if_t<
        !std::is_invocable_v<std::decay_t<F>, QFuture<void>>>>
{
    using ResultType = std::invoke_result_t<std::decay_t<F>>;
};

} // namespace qevercloud::detail
