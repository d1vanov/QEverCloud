# Migration notes from major version 4 to major version 5

Release 5 of QEverCloud added several major new features which required to introduce API breaks. This document lists the changes made and suggests ways to adapt your code using QEverCloud to these changes.

## Minimal required versions of compiler, Qt and CMake

In release 5 QEverCloud bumped the minimal required versions of compiler, Qt and CMake. Minimal supported versions are as follows:
 * g++: 5.4
 * Visual Studio: 2017
 * Qt: 5.5
 * CMake: 3.5.1

If your build infrastructure is older than than, unfortunately you want be able to build QEverCloud 5 before you upgrade your infrastructure.

If you use any other compiler than g++ or Visual Studio, the requirement is that it should support C++14 standard features used by QEverCloud. CMake automatically checks the presence of support for most of required features during the pre-build configuration phase.

## Removed functionality

### Removed CMake options

Some CMake options existing in QEverCloud before version 5 were removed. These options include the following:
 * `MAJOR_VERSION_LIB_NAME_SUFFIX`
 * `MAJOR_VERSION_DEV_HEADERS_FOLDER_NAME_SUFFIX`
 * `BUILD_WITH_QT4`

### Removed functions

Two functions were removed from QEverCloud 5 which used to control the request timeout: they were improperly called `connectionTimeout` and `setConnectionTimeout`. In QEverCloud 5 in order to specify request timeouts one should use `IRequestContext` interface (see below for more details).

## Changes in API

### Changes in names of headers

Since QEverCloud 5 all header and source files have consistent naming: now they all start from capital letters i.e. `globals.h` has become `Globals.h`. Before that naming of header and source files was inconsistent - some file names started from capital letters, some did not. It was preserved for backward compatibility but since QEverCloud 5 breaks this compatibility in numerous ways, it was considered a good opportunity to clean up the headers naming as well.

Most probably it shouldn't be a problem for your code as the recommendation has always been to include `QEverCloud.h` global header (or `QEverCloudOAuth.h` for OAuth functionality) instead of particular other headers.

### Use of std::shared_ptr instead of QSharedPointer throughout the library

In release 5 of QEverCloud all `QSharedPointers` were replaced with `std::shared_ptrs`. Smart pointers from the C++ standard library offer more convenience and flexibility than Qt's ones which were introduced back in times of C++98 when there was no choice to use standard library's smart pointers as there were none. 

One place within the library where the replacement took place is `AsyncResult::finished` signal. `QSharedPointer<EverCloudExceptionData>` was replaced with typedef `EverCloudExceptionDataPtr` which actually is `std::shared_ptr<EverCloudExceptionData>`. Note that Qt metatype is registered for the typedef rather than the shared_ptr so in your code you should use the typedef as well to ensure Qt doesn't have any troubles queuing the pointer in signal-slot connections.

### Changes in AsyncResult class

The constructors of `AsyncResult` class now accept one more argument: `IRequextContextPtr`. See the section on request context within this document for details on what it is. Also, one more constructor was added to `AsyncResult` class which handles the case of pre-existing value and/or exception.

It's very unlikely that your code uses `AsyncResult` constructors directly, instead it most probably receives pointers to `AsyncResult` objects created by QEverCloud's services methods. So it's unlikely that changes in `AsyncResult` constructors would affect your code in any way.

What would affect your code though is the change in `AsyncResult::finished` signature: in addition to value and exception data it also passes the request context pointer. In your code you'd need to add the additional parameter to the slot connected to `AsyncResult::finished` signal. You might just do it and leave the new parameter unused but you can actually use request context for e.g. matching request id to the guid of a downloaded note, for example. If your code downloads many notes asynchronously and concurrently, your slot connected to `AsyncResult::finished` might be invoked several times for different notes. Now you can conveniently map each such invokation to a particular note.

## New functionality

### New interfaces: IDurableService and IRetryPolicy

`IDurableService` interface encapsulates the logic of retrying the request if some *retriable* error has occurred during the attempt to execute it. A good example of a retriable error is a transient network failure. QEverCloud might have sent a http request to Evernote service but network has suddenly failed, the request was not delivered to Evernote service which thus has never sent the response back to QEverCloud. With retries the request is automatically sent again in the hope that it would succeed this time but it happens only for errors which are actually retriable. The logic of deciding whether some particular error is retriable is encapsulated within `IRetryPolicy` interface. QEverCloud offers two convenience functions for dealing with `IRetryPolicy`:
 * `newRetryPolicy` creates the retry policy used by QEverCloud by default - only transient network errors are retried.
 * `nullRetryPolicy` creates the retry policy which considers any error not retriable. In QEverCloud this policy is used for testing.

In order to create the actual durable service instance, call `newDurableService`. In this function you can optionally pass the pointer to `IRetryPolicy` (the default one is used if you don't specify it) and the pointer to the "global" request context for this service.

You don't have to use `IDurableService` or `IRetryPolicy` directly, they are already used by QEverClouds internals under the hood. But if you want to reuse QEverCloud's retry functionality for arbitrary code of yours, you can actually do so.

### New class: NetworkException

New exception class was introduced in QEverCloud 5: `NetworkException`. It encapsulates any network errors that might occur during the communication between QEverCloud and Evernote service. Some of these errors might be transient and thus retriable (see the section about `IDurableService` and `IRetryPolicy` above). The type of error is an element from `QNetworkReply::NetworkError` enumeration.

### New global function: initializeQEverCloud

The migration from `QSharedPointer` to `std::shared_ptr` required to explicitly specify corresponding Qt metatypes. For this a special function was introduced, `initializeQEverCloud` which is declared in `Globals.h` header. It is meant to be called once before other QEverCloud functionality is used. There is no harm in calling it multiple times if it happens by occasion.

### New convenience functions toRange for iterating over Qt's associative containers

In QEverCloud 5 a new header file was added, `Helpers.h` which contains various auxiliary stuff which doesn't quite fit in other places. In particular, this new header contains two convenience functions `toRange` which allow one to use modern C++'s range based loops for iteration over Qt's associative containers.

Modern C++'s range based loops have certain requirements for container's iterators: dereferencing the iterator should return a pair with key and value. Iterators of Qt containers such as `QHash` and `QMap` don't comply with this requirement: their iterators are not dereferenced at all, they contain methods `key()` and `value()` which return key and value respectively. Helper functions `toRange` create lightweight wrappers around Qt's containers and their iterators providing range based for loop compliant wrapper iterators. No data copying from the container takes place so it is truly lightweight.

There are two overloads of `toRange` function: one for iterating over the constant container and one for iterating over the non-const one.

In code such iteration looks like this:
```
QHash<QString, int> myHash;
<...> // fill myHash
for(const auto & it: toRange(myHash)) {
    const auto & key = it.key();
    const auto & value = it.value();
    <...> // do something with key and value
}
```
