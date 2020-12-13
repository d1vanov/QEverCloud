cmake_minimum_required(VERSION 3.10.2)

project(QEverCloud VERSION 7.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/QEverCloud/cmake/modules")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/QEverCloud/cmake/modules/sanitizers")

include(QEverCloudDoxygen)

option(BUILD_DOCUMENTATION "Build documentation for QEverCloud" ON)
option(BUILD_QCH_DOCUMENTATION "Build documentation for QEverCloud in qch format" OFF)
option(BUILD_WITH_OAUTH_SUPPORT "Build QEverCloud with OAuth support" ON)
option(BUILD_WITH_Q_NAMESPACE "Use Q_NAMESPACE and Q_ENUM_NS macros for introspection" ON)
option(USE_QT5_WEBKIT "Use QtWebKit instead of QtWebEngine" OFF)

if(BUILD_DOCUMENTATION)
  set(DOXY_INPUT                  "${PROJECT_SOURCE_DIR}/QEverCloud/headers ${PROJECT_SOURCE_DIR}/README.md")
  set(DOXY_USE_MDFILE_AS_MAINPAGE "${PROJECT_SOURCE_DIR}/README.md")
  set(DOXY_RECURSIVE              "YES")
  set(DOXY_PROJECT_NAME           "${PROJECT_NAME}")
  set(DOXY_PROJECT_NUMBER         "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
  set(DOXY_PROJECT_BRIEF          "\"Unofficial Evernote Cloud API for Qt\"")
  set(DOXY_OUTPUT_DIRECTORY       "${PROJECT_BINARY_DIR}/doc")
  set(DOXY_WARN_IF_UNDOCUMENTED   "NO")
  set(DOXY_EXTRACT_ALL            "YES")

  if(BUILD_QCH_DOCUMENTATION)
    set(DOXY_GENERATE_QHP "YES")
  else()
    set(DOXY_GENERATE_QHP "NO")
  endif()
  ADD_DOCUMENTATION(doc Doxyfile)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(QEverCloudCompilerSettings)

if(USE_QT5_WEBKIT)
  set(QEVERCLOUD_USE_QT_WEB_ENGINE OFF)
else()
  set(QEVERCLOUD_USE_QT_WEB_ENGINE ON)
endif()

set(QEVERCLOUD_FIND_QT_ARGS REQUIRED)

include(QEverCloudFindDependencies)

configure_file(QEverCloud/cmake/modules/QEverCloudConfig.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-qt5Config.cmake @ONLY)

configure_file(QEverCloud/cmake/modules/QEverCloudConfigVersion.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-qt5ConfigVersion.cmake @ONLY)

find_package(Sanitizers)

enable_testing()
add_subdirectory(QEverCloud)
