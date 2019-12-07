QEverCloud
==========

**Unofficial Evernote Cloud API for Qt**

Travis CI (Linux, OS X): [![Build Status](https://travis-ci.org/d1vanov/QEverCloud.svg?branch=master)](https://travis-ci.org/d1vanov/QEverCloud)

AppVeyor CI (Windows): [![Build status](https://ci.appveyor.com/api/projects/status/75vtxm2o18u4atw0/branch/master?svg=true)](https://ci.appveyor.com/project/d1vanov/qevercloud/branch/master)

## What's this

This library presents the complete Evernote SDK for Qt.
All the functionality that is described on [Evernote site](http://dev.evernote.com/doc/)
is implemented and ready to use. In particular OAuth authentication is implemented.

Read doxygen generated [documentation](http://d1vanov.github.io/QEverCloud) for detailed info.

The documentation can also be generated in the form of a .qch file which you can register with
your copy of Qt Creator to have context-sensitive help. See below for more details.

## How to contribute

Please see the [contribution guide](CONTRIBUTING.md) for detailed info.

## Downloads

Prebuilt versions of the library can be downloaded from the following locations:

 * Stable version:
   * Windows binaries:
     * [MSVC 2017 32 bit Qt 5.13](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt513-VS2017_x86.zip)
     * [MSVC 2017 64 bit Qt 5.13](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt510-VS2017_x64.zip)
     * [MinGW 32 bit Qt 5.5](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt55-MinGW_x86.zip)
   * [Mac binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud_mac_x86_64.zip) (built with latest Qt from Homebrew)
   * [Linux binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud_linux_qt_5132_x86_64.zip) built on Ubuntu 16.04 with Qt 5.13
 * Unstable version:
   * Windows binaries:
     * [MSVC 2017 32 bit Qt 5.13](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt513-VS2017_x86.zip)
     * [MSVC 2017 64 bit Qt 5.13](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt513-VS2017_x64.zip)
     * [MinGW 32 bit Qt 5.5](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt55-MinGW_x86.zip)
   * [Mac binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud_mac_x86_64.zip) (built with latest Qt from Homebrew)
   * [Linux binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud_linux_qt_5132_x86_64.zip) built on Ubuntu 16.04 with Qt 5.13

## How to build

The project can be built and shipped either as a static library or a shared library. Dll export/import symbols necessary for Windows platform are supported.

Dependencies include the following Qt components:
 * Qt5: Qt5Core, Qt5Widgets, Qt5Network and, if the library is built with OAuth support, either:
   * Qt5WebKit and Qt5WebKitWidgets
   * Qt5WebEngine and Qt5WebEngineWidgets - for Qt < 5.6
   * Qt5WebEngineCore and Qt5WebEngineWidgets - for Qt >= 5.6

Since QEverCloud 3.0.2 it is possible to choose Qt5WebKit over Qt5WebEngine using CMake option `USE_QT5_WEBKIT`.

Since QEverCloud 4.0.0 it is possible to build the library without OAuth support and thus without QtWebKit or QtWebEngine dependencies, for this use CMake option `BUILD_WITH_OAUTH_SUPPORT=NO`.

Also, if Qt5's Qt5Test modules are found during the pre-build configuration, the unit tests are enabled and can be run with `make test` command.

The project uses CMake build system which can be used as simply as follows (on Unix platforms):
```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=<...> ../
make
make install
```

Please note that installing the library somewhere is mandatory because it puts the library's headers into the subfolder *qt5qevercloud*. The intended use of library's headers is something like this:
```
#include <qt5qevercloud/QEverCloud.h>
```

More CMake configurations options available:

*BUILD_DOCUMENTATION* - when *ON*, attempts to find Doxygen and in case of success adds *doc* target so the documentation can be built using `make doc` command after the `cmake ../` step. By default this option is on.

*BUILD_QCH_DOCUMENTATION* - when *ON*, passes instructions on to Doxygen to build the documentation in *qch* format. This option only has any meaning if *BUILD_DOCUMENTATION* option is on. By default this option is off.

*BUILD_SHARED* - when *ON*, CMake configures the build for the shared library. By default this option is on.

If *BUILD_SHARED* is *ON*, `make install` would install the CMake module necessary for applications using CMake's `find_package` command to find the installation of the library.

Since QEverCloud 4.1.0 it is possible to build the library with enabled sanitizers using additional CMake options:
 * `-DSANITIZE_ADDRESS=ON` to enable address sanitizer
 * `-DSANITIZE_MEMORY=ON` to enable memory sanitizer
 * `-DSANITIZE_THREAD=ON` to enable thread sanitizer
 * `-DSANITIZE_UNDEFINED=ON` to enable undefined behaviour sanitizer

### QtWebKit vs QWebEngine

The library uses Qt's web facilities for OAuth authentication. These can be based on either QtWebKit (for older versions of Qt5) or QWebEngine (for more recent versions of Qt5). With CMake build system the choice happens automatically during the pre-build configuration based on the used version of Qt. One can also choose to use QtWebKit even with newer versions of Qt via CMake option `USE_QT5_WEBKIT`.

### Compiler requirements

The library requires the compiler to support C++17 standard. CMake automatically checks whether the compiler is capable enough of building QEverCloud so if pre-build step was successful, the build should be successful as well.

## Include files for applications using the library

Two "cumulative" headers - *QEverCloud.h* or *QEverCloudOAuth.h* - include everything needed for the general and OAuth functionality correspondingly. More "fine-grained" headers are available within the same subfolder if needed.

## Related projects

* [NotePoster](https://github.com/d1vanov/QEverCloud-example-NotePoster) is an example app using QEverCloud library to post notes to Evernote.
* [QEverCloud packaging](https://github.com/d1vanov/QEverCloud-packaging) repository contains various files and scripts required for building QEverCloud packages for various platforms and distributions.
* [QEverCloudGenerator](https://github.com/d1vanov/QEverCloudGenerator) repository contains the parser of [Evernote Thrift IDL files](https://github.com/evernote/evernote-thrift) generating headers and sources for QEverCloud library.
* [libquentier](https://github.com/d1vanov/libquentier) is a library for creating of feature rich full sync Evernote clients built on top of QEverCloud
* [Quentier](https://github.com/d1vanov/quentier) is an open source desktop note taking app capable of working as Evernote client built on top of libquentier and QEverCloud
