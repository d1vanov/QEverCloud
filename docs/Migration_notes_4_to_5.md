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

## Removed CMake options

Some CMake options existing in QEverCloud before version 5 were removed. These options include the following:
 * `MAJOR_VERSION_LIB_NAME_SUFFIX`
 * `MAJOR_VERSION_DEV_HEADERS_FOLDER_NAME_SUFFIX`
 * `BUILD_WITH_QT4`

## Changes in AsyncResult class

The constructors of `AsyncResult` class now accept one more argument: `IRequextContextPtr`. See the section on request context within this document for details on what it is. Also, one more constructor was added to `AsyncResult` class which handles the case of pre-existing value and/or exception.

It's very unlikely that your code uses `AsyncResult` constructors directly, instead it most probably receives pointers to `AsyncResult` objects created by QEverCloud's services methods. So it's unlikely that changes in `AsyncResult` constructors would affect your code in any way.

What would affect your code though is the change in `AsyncResult::finished` signature: in addition to value and exception data it also passes the request context pointer. In your code you'd need to add the additional parameter to the slot connected to `AsyncResult::finished` signal. You might just do it and leave the new parameter unused but you can actually use request context for e.g. matching request id from it to the guid of a downloaded note, for example. If your code downloads many notes asynchronously and concurrently, your slot connected to `AsyncResult::finished` might be invoked several times for different notes. Now you can conveniently map each such invokation to a particular note.
