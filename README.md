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

See [contribution guide](CONTRIBUTING.md) for detailed info.

## Downloads

Prebuilt versions of the library can be downloaded from the following locations:

 * Stable version:
   * Windows binaries:
     * [MSVC 2017 32 bit Qt 5.13](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt513-VS2017_x86.zip)
     * [MSVC 2017 64 bit Qt 5.13](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt513-VS2017_x64.zip)
     * [MinGW 32 bit Qt 5.5](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud-windows-qt55-MinGW_x86.zip)
   * [Mac binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud_mac_x86_64.zip) (built with latest Qt from Homebrew)
   * [Linux binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-master/qevercloud_linux_qt_513_x86_64.zip) built on Ubuntu 16.04 with Qt 5.13
 * Unstable version:
   * Windows binaries:
     * [MSVC 2017 32 bit Qt 5.13](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt513-VS2017_x86.zip)
     * [MSVC 2017 64 bit Qt 5.13](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt513-VS2017_x64.zip)
     * [MinGW 32 bit Qt 5.5](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud-windows-qt55-MinGW_x86.zip)
   * [Mac binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud_mac_x86_64.zip) (built with latest Qt from Homebrew)
   * [Linux binary](https://github.com/d1vanov/QEverCloud/releases/download/continuous-development/qevercloud_linux_qt_513_x86_64.zip) built on Ubuntu 16.04 with Qt 5.13

## How to build

QEverCloud uses CMake build system which can be used as simply as follows (on Unix platforms):
```
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=<...> ../
make
make install
```

The library can be built and shipped either as a static library or a shared library. Dll export/import symbols necessary for Windows platform are supported.

QEverCloud requires the compiler to support certain elements of C++17 standard. CMake automatically checks whether the compiler is capable enough of building QEverCloud so if the pre-build configuration step was successful, the build step should be successful as well. Known capable compilers are g++ 5.4 or later and Visual Studio 2017 or later.

QEverCloud depends on the following Qt components:
 * Qt5Core
 * Qt5Widgets
 * Qt5Network

If the library is built with OAuth support, more dependencies are required:
 * Qt5WebKit and Qt5WebKitWidgets for Qt < 5.6
 * Qt5WebEngineCore and Qt5WebEngineWidgets - for Qt >= 5.6

By default CMake prefers QtWebEngine over QtWebKit if both are available for Qt >= 5.6 but it is possible to choose Qt5WebKit over Qt5WebEngine using CMake option `USE_QT5_WEBKIT`.

It is possible to build the library without OAuth support and thus eliminate the dependency on QtWebKit or QtWebEngine using CMake option `BUILD_WITH_OAUTH_SUPPORT=NO`.

If Qt5's Qt5Test module is found during the pre-build configuration step, the unit tests are enabled and can be run with `make test` and more verbose `make check` commands.

The minimal Qt version required to build the library is Qt 5.5.

Other available CMake configurations options:

*BUILD_DOCUMENTATION* - when *ON*, attempts to find Doxygen and in case of success adds *doc* target so the documentation can be built using `make doc` command after the pre-build configuration step. By default this option is on.

*BUILD_QCH_DOCUMENTATION* - when *ON*, passes instructions on to Doxygen to build the documentation in *qch* format. This option only has any meaning if *BUILD_DOCUMENTATION* option is on. By default this option is off.

*BUILD_SHARED* - when *ON*, CMake configures the build for the shared library. By default this option is on.

*BUILD_WITH_Q_NAMESPACE* - when *ON*, `Q_NAMESPACE` and `Q_ENUM_NS` macros are used to add introspection capabilities to enumerations within `qevercloud` namespace. Qt >= 5.8 is required to enable this option. By default this option is enabled.

If *BUILD_SHARED* is *ON*, `make install` installs CMake module necessary for applications using CMake's `find_package` command to find the installation of QEverCloud.

It is possible to build the library with enabled sanitizers using additional CMake options:
 * `-DSANITIZE_ADDRESS=ON` to enable address sanitizer
 * `-DSANITIZE_MEMORY=ON` to enable memory sanitizer
 * `-DSANITIZE_THREAD=ON` to enable thread sanitizer
 * `-DSANITIZE_UNDEFINED=ON` to enable undefined behaviour sanitizer

## Include files for applications using the library

Two "cumulative" headers - *QEverCloud.h* or *QEverCloudOAuth.h* - include everything needed for the general and OAuth functionality correspondingly. More "fine-grained" headers can also be used if needed.

## Related projects

* [QEverCloudGenerator](https://github.com/d1vanov/QEverCloudGenerator) repository hosts code generating parser of [Evernote Thrift IDL files](https://github.com/evernote/evernote-thrift). This parser is used to autogenerate a portion of QEverCloud's headers and sources.
* [libquentier](https://github.com/d1vanov/libquentier) is a library for creating feature rich full sync Evernote clients built on top of QEverCloud
* [Quentier](https://github.com/d1vanov/quentier) is an open source desktop note taking app capable of working as Evernote client built on top of libquentier and QEverCloud
