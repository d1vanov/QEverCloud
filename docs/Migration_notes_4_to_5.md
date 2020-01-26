# Migration notes from QEverCloud 4 to 5

Release 5 of QEverCloud added several major new features which required to introduce API breaks. This document lists the changes made and suggests ways to adapt your code using QEverCloud to these changes.

## Minimal required versions of compiler, Qt and CMake

In release 5 QEverCloud bumped the minimal required versions of compiler, Qt and CMake. Minimal supported versions are as follows:
 * g++: 5.4
 * Visual Studio: 2017
 * Qt: 5.5
 * CMake: 3.5.1

If your build infrastructure is older than that, unfortunately you won't be able to build QEverCloud 5 before you upgrade your infrastructure.

If you use any other compiler than g++ or Visual Studio, the requirement is that it should support C++14 features used by QEverCloud. CMake automatically checks the presence of support for most of required features during the pre-build configuration phase.

## Removed functionality

### Removed CMake options

Some CMake options existing in QEverCloud before version 5 were removed. These options include the following:
 * `MAJOR_VERSION_LIB_NAME_SUFFIX`
 * `MAJOR_VERSION_DEV_HEADERS_FOLDER_NAME_SUFFIX`
 * `BUILD_WITH_QT4`

### Removed global functions

Two functions were removed from QEverCloud 5 which used to control the request timeout: they were improperly called `connectionTimeout` and `setConnectionTimeout`. In QEverCloud 5 in order to specify request timeouts one should use `IRequestContext` interface (see below for more details).

## Changes in API

### Changes in names of headers

Since QEverCloud 5 all header and source files have consistent naming: now they all start from uppercase letters i.e. `globals.h` has become `Globals.h`. Before QEverCloud 5 the naming of header and source files was inconsistent for legacy reasons - some file names started from uppercase letters, some from lowercase ones. It was preserved for backward compatibility but as QEverCloud 5 breaks this compatibility in numerous ways, it was considered a good opportunity to clean up the headers naming as well.

Most probably it shouldn't be a problem for your code as the recommendation has always been to include `QEverCloud.h` global header (or `QEverCloudOAuth.h` for OAuth functionality) instead of particular other headers. If your code did use other headers, just adjust their names in inclusion directives.

### Use of std::shared_ptr instead of QSharedPointer throughout the library

In release 5 of QEverCloud all `QSharedPointers` were replaced with `std::shared_ptrs`. Smart pointers from the C++ standard library offer more convenience and flexibility than Qt's ones which were introduced back in times of C++98 when there was no choice to use the standard library's smart pointers as they didn't exist.

One place within the library where the replacement took place is `AsyncResult::finished` signal. `QSharedPointer<EverCloudExceptionData>` was replaced with typedef `EverCloudExceptionDataPtr` which actually is `std::shared_ptr<EverCloudExceptionData>`. Note that Qt metatype is registered for the typedef rather than the `std::shared_ptr` so in your code you should use the typedef as well to ensure Qt doesn't have any troubles queuing the pointer in signal-slot connections.

Note that due to this change your code needs to call `initializeQEverCloud` function before QEverCloud functionality is used (see below).

### Changes in AsyncResult class

The constructors of `AsyncResult` class now accept one more argument: `IRequextContextPtr`. See the section on request context within this document for details on what it is. Also, one more constructor was added to `AsyncResult` class which handles the case of pre-existing value and/or exception.

It's very unlikely that your code uses `AsyncResult` constructors directly, instead it most probably receives pointers to `AsyncResult` objects created by QEverCloud's services methods. So it's unlikely that changes in `AsyncResult` constructors would affect your code in any way.

What would affect your code though is the change in `AsyncResult::finished` signature: in addition to value and exception data it also passes the request context pointer. In your code you'd need to add the additional parameter to the slot connected to `AsyncResult::finished` signal. You might just do it and leave the new parameter unused but you can actually use request context for e.g. matching request id to the guid of a downloaded note, for example. If your code downloads many notes asynchronously and concurrently, your slot connected to `AsyncResult::finished` might be invoked several times for different notes. Now you can conveniently map each such invokation to a particular note.

### Changes in Optional template class

In QEverCloud 5 `Optional` template class implementation was changed: `operator==` and `operator!=` accepting another `Optional` were added to it. Unfortunately, it has lead to some complications: you can no longer do comparisons involving implicit type conversions between `Optional` and value of compatible yet different type, like this:
```
Optional<int> a = 42;
double b = 1.0;
bool res = (a == b);
```
Instead you need to cast the right hand side expression to proper type:
```
Optional<int> a = 42;
double b = 1.0;
bool res = (a == static_cast<int>(b));
```

### Changes in Thumbnail class

Since QEverCloud 5 method `Thumbnail::createPostRequest` returns `std::pair<QNetworkRequest, QByteArray>` instead of `QPair<QNetworkRequest, QByteArray>`. There are [plans to deprecate/remove](https://bugreports.qt.io/browse/QTBUG-80309) `QPair` in favour of `std::pair`.

`Thumbnail::ImageType` used to be a so called "C++98-style scoped enum" i.e. struct `ImageType` wrapping enum `type` so that enum items could be referenced with `ImageType::` prefix. Now this enum is a proper C++11 scoped enum so the prefix is still there but there's no need to refer to the type as `ImageType::type`, `ImageType` is sufficient now.

### Changes in EDAMErrorCode header

`EDAMErrorCode.h` header contains numerous enumerations related to error codes. Before QEverCloud 5 they used to be "C++98-style scoped enums" i.e. structs wrapping enum called `type`. Now they are proper `enum classes`. For client code it means that all references to enumerations containing `::type` suffix need to be freed from it. I.e. all occurrences of `EDAMErrorCode::type` need to be changes to `EDAMErrorCode`, same for other enumerations.

### Changes in service classes

Before QEverCloud 5 there were two classes which methods were used to communicate with Evernote: `NoteStore` and `UserStore`. Now these classes are converted to abstract interfaces: `INoteStore` and `IUserStore`. The actual instances of services should now be created with functions `newNoteStore` and `newUserStore`. These functions accept service url, request context, parent `QObject` and retry policy. The request context parameter has important meaning here:
 * it would be used as default request context if none is provided in particular method calls of the service (only request id would be different)
 * the authentication token from this request context would be used in method calls for which no request context was provided
 * if this request context has zero max request retry count, the automatic retries of requests would be disabled

Methods of both interfaces now accept optional `IRequestContextPtr` where before QEverCloud 5 they used to accept `authenticationToken` parameter. If no request context is provided, the default one is used - either the one provided to `newNoteStore`/`newUserStore` or the one created with `newRequestContext` with all the default parameters.

The constructor of `UserStore` class in previous QEverCloud versions used to accept `host` string which was the address of Evernote service. Now `newUserStore` accepts a user store url which is essentially `"https://" + host + "/edam/user"`

## New functionality

### Printability

Since QEverCloud 5 all types and enumerations from Evernote API as well as exception classes are printable. Printability means that enumeration values and objects of Evernote types and exceptions classes can be printed to `QTextStream` and `QDebug`. Additionally, objects of Evernote types and exceptions classes can be conveniently converted to string using `toString` method.

Printability for classes was implemented as inheritance from `Printable` base class which contains one pure virtual method:
```
virtual void print(QTextStream & strm) const = 0;
```
`Printable` uses this method to implement printing to `QTextStream` and `QDebug` using stream operators and the conversion to string.

Printability of enumerations and objects was required to implement QEverCloud's logging facility (see below).

### IRequestContext interface

`IRequestContext` interface carries several values related to the request which define the way in which the request is handled by QEverCloud. In particular, values within request context include the following:
 * `requestId` is the autogenerated unique identifier of the request which allows to tell one request from another in e.g. logs
 * `authenticationToken` is Evernote authentication token - either user's own one or the one for a particular linked notebook for requests related to it. Before QEverCloud 5 it used to be a separate parameter in service calls but now it is a part of request context.
 * `requestTimeout` in milliseconds
 * `increaseRequestTimeoutExponentially` is a boolean flag telling whether the timeout should be increased when the request is automatically retried
 * `maxRequestTimeout` is an upper boundary for automatically increased timeout on retries
 * `maxRequestRetryCount` is the maximum number of attempts to retry the request

### IDurableService and IRetryPolicy interfaces

`IDurableService` interface encapsulates the logic of retrying the request if some *retriable* error has occurred during the attempt to execute it. A good example of a retriable error is a transient network failure. QEverCloud might have sent a http request to Evernote service but network has suddenly failed, the request was not delivered to Evernote service which thus has never sent the response back to QEverCloud. With retries the request is automatically sent again in the hope that it would succeed this time but it happens only for errors which are actually retriable. The logic of deciding whether some particular error is retriable is encapsulated within `IRetryPolicy` interface. QEverCloud offers two convenience functions for dealing with `IRetryPolicy`:
 * `newRetryPolicy` creates the retry policy used by QEverCloud by default - only transient network errors are retried.
 * `nullRetryPolicy` creates the retry policy which considers any error not retriable. In QEverCloud this policy is used for testing.

In order to create the actual durable service instance, call `newDurableService`. In this function you can optionally pass the pointer to `IRetryPolicy` (the default one is used if you don't specify it) and the pointer to the "global" request context for this service.

You don't have to use `IDurableService` or `IRetryPolicy` directly, they are already used by QEverClouds internals under the hood. But if you want to reuse QEverCloud's retry functionality for arbitrary code of yours, you can actually do so.

### NetworkException

New exception class was introduced in QEverCloud 5: `NetworkException`. It encapsulates any network errors that might occur during the communication between QEverCloud and Evernote service. Some of these errors might be transient and thus retriable (see the section about `IDurableService` and `IRetryPolicy` above). The type of error is an element from `QNetworkReply::NetworkError` enumeration.

### New global function: initializeQEverCloud

The migration from `QSharedPointer` to `std::shared_ptr` required to explicitly specify some Qt metatypes using this smart pointer. For this a special function was introduced, `initializeQEverCloud` which is declared in `Globals.h` header. It is meant to be called once before other QEverCloud functionality is used. There is no harm in calling it multiple times if it happens by occasion.

### Logging facility

QEverCloud 5 added a flexible logging facility which client code can use as desired. The logging facility consists of `LogLevel` enumeration and `ILogger` interface located in new `Log.h` header. `LogLevel` enumeration has the following log levels:

 * `Trace`
 * `Debug`
 * `Info`
 * `Warn`
 * `Error`

The default log level is `Info` which means that QEverCloud's logger would log events with `Info`, `Warn` and `Error` level.

The `ILogger` interface contains methods which would be called by QEverCloud when it uses the logger internally. The fact that `ILogger` is an interface and not a particular class means that the client code can implement this interface and thus integrate QEverCloud's logger into its own logging facility, whatever that it. The instance of a particular QEverCloud logger is a singleton which can be set using `setLogger` function and retrieved using `logger` function. For convenience QEverCloud provides two auxiliary functions:

 * `nullLogger`: this function creates an instance of logger which does nothing. It is a logger used by QEverCloud by default i.e. by default QEverCloud doesn't write the logs it collects anywhere
 * `newStdErrLogger`: this function creates an instance of logger which writes logs to stderr.

### New servers classes

QEverCloud 5 added new classes in `Servers.h` header which can be used to implement a simplistic version of Evernote service of your own. `NoteStoreServer` and `UserStoreServer` classes are `QObject` subclasses which are capable of the following:
 * take serialized thrift request data as `QByteArray` in `onRequest` slot
 * parse the request and emit one of particular signals indicating what request needs to be served. For example, for note creation request `NoteStoreServer::createNoteRequest` signal would be emitted.
 * take external response on request into a particular slot. For example, for note creation request `NoteStoreServer::onCreateNoteRequestReady` slot should be invoked.
 * encode response data into a thrift format and emit a particular signal indicating that the response is ready to be delivered. For example, for note creation request `NoteStoreServer::createNoteRequestReady` signal would be emitted.

 In QEverCloud these classes are used in unit tests which ensure that code talking to Evernote service works as it should.

### New convenience functions toRange for iterating over Qt's associative containers

In QEverCloud 5 a new header file was added, `Helpers.h` which contains various auxiliary stuff which doesn't quite fit in other places. In particular, this new header contains two convenience functions `toRange` which allow one to use modern C++'s range based loops for iteration over Qt's associative containers.

Modern C++'s range based loops have certain requirements for container's iterators: one should be able to dereference the iterator and work with whatever value that yields. Iterators of Qt containers such as `QHash` and `QMap` don't comply with this requirement: their iterators are not dereferenced at all, they contain methods `key()` and `value()` which return key and value respectively. Helper functions `toRange` create lightweight wrappers around Qt's containers and their iterators providing range based for loop compliant wrapper iterators. No data copying from the container takes place so it is truly lightweight.

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

### New optional timeout parameter in EvernoteOAuthWebView::authenticate method

The optional timeout parameter was added to `EvernoteOAuthWebView::authenticate` method. The timeout is not for the whole OAuth procedure but for communication with Evernote service over the network. If Evernote doesn't answer to QEverCloud's request for the duration of a timeout, OAuth fails. That's how OAuth has worked before too but previously this timeout duration could not be specified by the client code. Now it can be specified. By default the timeout of 30 seconds is used.

### New localData field in structs corresponding to Evernote types

Since QEverCloud 5 structs corresponding to Evernote types have a new field of type `EverCloudLocalData` called `localData`. This field encapsulates several data members which don't take part in synchronization with Evernote (thus "local" in the name) but which are useful for applications using QEverCloud to implement rich Evernote client apps. `EverCloudLocalData` struct contains the following fields:
 * `id` string which by default is generated as a `QUuid` but can be substituted with any string value
 * `dirty`, `local` and `favorited` boolean flags
 * `dict` which is a collection of arbitrary data in the form of `QVariant`s indexed by strings

### Elements of Evernote types registered in Qt's meta object system with Q_PROPERTY and Q_GADGET macros

Some introspection capabilities were added to QEverCloud 5 structs corresponding to Evernote types: they now have [Q_GADGET](https://doc.qt.io/qt-5/qobject.html#Q_GADGET) macro and each of their attributes is registered as a [Q_PROPERTY](https://doc.qt.io/qt-5/qobject.html#Q_PROPERTY).


