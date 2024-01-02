cmake_minimum_required(VERSION 3.16.3)

project(QEverCloud VERSION 7.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/QEverCloud/cmake/modules")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/QEverCloud/cmake/modules/sanitizers")

include(QEverCloudDoxygen)

option(BUILD_DOCUMENTATION "Build documentation for QEverCloud" ON)
option(BUILD_QCH_DOCUMENTATION "Build documentation for QEverCloud in qch format" OFF)
option(BUILD_WITH_OAUTH_SUPPORT "Build QEverCloud with OAuth support" ON)
option(BUILD_WITH_Q_NAMESPACE "Use Q_NAMESPACE and Q_ENUM_NS macros for introspection" ON)

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

include(QEverCloudCompilerSettings)

if(NOT CMAKE_FIND_PACKAGE_NAME)
  set(CMAKE_FIND_PACKAGE_NAME "Qt5")
endif()

set(${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY OFF)
set(${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED ON)
include(QEverCloudFindDependencies)

configure_file(QEverCloud/cmake/modules/QEverCloudConfig.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}Config.cmake @ONLY)

configure_file(QEverCloud/cmake/modules/QEverCloudConfigVersion.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}ConfigVersion.cmake @ONLY)

find_package(Sanitizers)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR "ON")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()
add_subdirectory(QEverCloud)
add_custom_target(check COMMAND "${CMAKE_CTEST_COMMAND}" "--verbose")
