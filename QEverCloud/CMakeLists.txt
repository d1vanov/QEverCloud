cmake_minimum_required(VERSION 2.8.11)

include(QEverCloudCMakePolicies)
SET_POLICIES()

set(QEVERCLOUD_BINARY_DIR ${PROJECT_BINARY_DIR})

set(PUBLIC_HEADERS
    headers/QEverCloud.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND PUBLIC_HEADERS
    headers/QEverCloudOAuth.h)
endif()

set(NON_GENERATED_HEADERS
    headers/AsyncResult.h
    headers/EventLoopFinisher.h
    headers/EverCloudException.h
    headers/Export.h
    headers/Exceptions.h
    headers/Globals.h
    headers/Helpers.h
    headers/InkNoteImageDownloader.h
    headers/Optional.h
    headers/RequestContext.h
    headers/Thumbnail.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND NON_GENERATED_HEADERS
    headers/OAuth.h)
endif()

set(GENERATED_HEADERS
    headers/generated/Constants.h
    headers/generated/Services.h
    headers/generated/Types.h
    headers/generated/EDAMErrorCode.h)

set(PRIVATE_HEADERS
    src/Http.h
    src/Impl.h
    src/Thrift.h
    src/generated/Types_io.h)

set(SOURCES
    src/AsyncResult.cpp
    src/EventLoopFinisher.cpp
    src/EverCloudException.cpp
    src/Exceptions.cpp
    src/Globals.cpp
    src/Http.cpp
    src/InkNoteImageDownloader.cpp
    src/RequestContext.cpp
    src/ServicesNonGenerated.cpp
    src/Thumbnail.cpp
    src/generated/Constants.cpp
    src/generated/EDAMErrorCode.cpp
    src/generated/Services.cpp
    src/generated/Types.cpp)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND SOURCES
    src/OAuth.cpp)
endif()

set(ALL_HEADERS_AND_SOURCES ${PUBLIC_HEADERS})
list(APPEND ALL_HEADERS_AND_SOURCES ${NON_GENERATED_HEADERS})
list(APPEND ALL_HEADERS_AND_SOURCES ${GENERATED_HEADERS})
list(APPEND ALL_HEADERS_AND_SOURCES ${PRIVATE_HEADERS})
list(APPEND ALL_HEADERS_AND_SOURCES ${SOURCES})

if(BUILD_WITH_OAUTH_SUPPORT)
  set(QEVERCLOUD_HAS_OAUTH "#define QEVERCLOUD_HAS_OAUTH 1")
else()
  set(QEVERCLOUD_HAS_OAUTH "#define QEVERCLOUD_HAS_OAUTH 0")
endif()

if(QEVERCLOUD_USE_QT_WEB_ENGINE)
  set(QEVERCLOUD_USES_QT_WEB_ENGINE "#define QEVERCLOUD_USE_QT_WEB_ENGINE 1")
else()
  set(QEVERCLOUD_USES_QT_WEB_ENGINE "#define QEVERCLOUD_USE_QT_WEB_ENGINE 0")
endif()

configure_file(headers/VersionInfo.h.in
  ${PROJECT_BINARY_DIR}/VersionInfo.h @ONLY)
list(APPEND ALL_HEADERS_AND_SOURCES ${PROJECT_BINARY_DIR}/VersionInfo.h)
include_directories(${PROJECT_BINARY_DIR})

set(LIBNAME "${QEVERCLOUD_LIBNAME_PREFIX}${QEVERCLOUD_QT_VERSION}qevercloud${QEVERCLOUD_LIBNAME_SUFFIX}")

if(BUILD_SHARED)
  add_definitions("-DQEVERCLOUD_SHARED_LIBRARY")
  add_library(${LIBNAME} SHARED ${ALL_HEADERS_AND_SOURCES})
else()
  add_definitions("-DQEVERCLOUD_STATIC_LIBRARY")
  add_library(${LIBNAME} STATIC ${ALL_HEADERS_AND_SOURCES})
endif()

add_sanitizers(${LIBNAME})

set_target_properties(${LIBNAME} PROPERTIES
  VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
  SOVERSION ${PROJECT_VERSION_MAJOR}
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  MACOSX_RPATH 1
  INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")

target_link_libraries(${LIBNAME} ${QT_LIBRARIES})

if(BUILD_WITH_QT4)
  # NOTE: working around what seems to be a CMake bug
  target_link_libraries(${LIBNAME} Qt4::QtWebKit)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_definitions("-DQT_NO_CAST_FROM_ASCII -DQT_NO_CAST_TO_ASCII -DQT_NO_CAST_FROM_BYTEARRAY -DQT_NO_NARROWING_CONVERSIONS_IN_CONNECT")

# Tests
if(BUILD_WITH_QT4)
  find_package(QT4 COMPONENTS QTCORE QTTEST QUIET)
else()
  find_package(Qt5Test QUIET)
endif()

if((NOT BUILD_WITH_QT4 AND Qt5Test_FOUND) OR (BUILD_WITH_QT4 AND Qt4_FOUND))
  set(TEST_SOURCES
      src/tests/TestQEverCloud.cpp)
  add_executable(test_${PROJECT_NAME} ${TEST_SOURCES})
  add_sanitizers(test_${PROJECT_NAME})
  add_test(test_${PROJECT_NAME} test_${PROJECT_NAME})
  if(BUILD_WITH_QT4)
    target_link_libraries(test_${PROJECT_NAME} ${LIBNAME} Qt4::QtCore Qt4::QtGui Qt4::QtNetwork Qt4::QtWebKit Qt4::QtTest)
  else()
    target_link_libraries(test_${PROJECT_NAME} ${LIBNAME} ${QT_LIBRARIES} Qt5::Test)
  endif()
else()
  message(STATUS "Haven't found Qt components required for building and running the unit tests")
endif()

# install shared library
install(TARGETS ${LIBNAME}
  EXPORT QEverCloud-${QEVERCLOUD_QT_VERSION}LibraryDepends
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(DEV_HEADERS_FOLDER_NAME ${QEVERCLOUD_QT_VERSION}qevercloud)
if(MAJOR_VERSION_DEV_HEADERS_FOLDER_NAME_SUFFIX)
  string(CONCAT DEV_HEADERS_FOLDER_NAME ${DEV_HEADERS_FOLDER_NAME} ${PROJECT_VERSION_MAJOR})
endif()

# install public headers
foreach(ITEM ${PUBLIC_HEADERS})
  install(FILES ${ITEM} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${DEV_HEADERS_FOLDER_NAME})
endforeach()

foreach(ITEM ${NON_GENERATED_HEADERS})
  install(FILES ${ITEM} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${DEV_HEADERS_FOLDER_NAME})
endforeach()

foreach(ITEM ${GENERATED_HEADERS})
  install(FILES ${ITEM} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${DEV_HEADERS_FOLDER_NAME}/generated)
endforeach()

# install VersionInfo.h header
install(FILES ${PROJECT_BINARY_DIR}/VersionInfo.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${DEV_HEADERS_FOLDER_NAME})

# install cmake module
if(BUILD_SHARED)
  install(EXPORT QEverCloud-${QEVERCLOUD_QT_VERSION}LibraryDepends DESTINATION ${INSTALL_CMAKE_DIR})
  install(FILES ${PROJECT_SOURCE_DIR}/QEverCloud/cmake/modules/QEverCloudFindPackageWrapperMacro.cmake DESTINATION ${INSTALL_CMAKE_DIR})
  install(FILES ${QEVERCLOUD_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}FindQtDependencies.cmake DESTINATION ${INSTALL_CMAKE_DIR})
  install(FILES ${QEVERCLOUD_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}Config.cmake DESTINATION ${INSTALL_CMAKE_DIR})
  install(FILES ${QEVERCLOUD_BINARY_DIR}/QEverCloud-${QEVERCLOUD_QT_VERSION}ConfigVersion.cmake DESTINATION ${INSTALL_CMAKE_DIR})
endif()
