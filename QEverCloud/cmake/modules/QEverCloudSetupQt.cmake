if(NOT USE_QT5)
  find_package(Qt4 COMPONENTS QTCORE OPTIONAL QUIET)
  if(NOT QT_QTCORE_LIBRARY)
    message(STATUS "Qt4's core was not found, trying to find Qt5's libraries")
    set(USE_QT5 1)
  else()
    message(STATUS "Found Qt4 installation, version ${QT_VERSION_MAJOR}.${QT_VERSION_MINOR}.${QT_VERSION_PATCH}")
  endif()
endif()

if(USE_QT5)
  find_package(Qt5Core REQUIRED)
  message(STATUS "Found Qt5 installation, version ${Qt5Core_VERSION}")
  find_package(Qt5Network REQUIRED)
  find_package(Qt5Widgets REQUIRED)

  find_package(Qt5WebEngine QUIET)
  if(NOT Qt5WebEngine)
    message(STATUS "Haven't found Qt5WebEngine module, trying to find Qt5WebKit instead")
    find_package(Qt5WebKit REQUIRED)
    find_package(Qt5WebKitWidgets REQUIRED)
  else()
    if(NOT Qt5WebEngine_VERSION VERSION_LESS "5.6.0")
      find_package(Qt5WebEngineCore REQUIRED)
    endif()
    find_package(Qt5WebEngineWidgets REQUIRED)
    set(USE_QT_WEB_ENGINE TRUE)
    add_definitions(-DUSE_QT_WEB_ENGINE)
  endif()

  set(QT_INCLUDES "${Qt5Core_INCLUDE_DIRS} ${Qt5Network_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS} ${Qt5Test_INCLUDE_DIRS}")
  set(QT_LIBRARIES "${Qt5Core_LIBRARIES} ${Qt5Network_LIBRARIES} ${Qt5Widgets_LIBRARIES} ${Qt5Test_LIBRARIES}")
  set(QT_DEFINITIONS "${Qt5Core_DEFINITIONS} ${Qt5Network_DEFINITIONS} ${Qt5Widgets_DEFINITIONS} ${Qt5Test_DEFINITIONS}")
else()
  find_package(Qt4 COMPONENTS QTCORE QTGUI QTNETWORK QTWEBKIT QTTEST REQUIRED)
  include(${QT_USE_FILE})
  # Workaround CMake > 3.0.2 bug with Qt4 libraries
  list(FIND QT_LIBRARIES "${QT_QTGUI_LIBRARY}" HasGui)
  if(HasGui EQUAL -1)
    list(APPEND QT_LIBRARIES ${QT_QTGUI_LIBRARY})
  endif()
endif()

include_directories(SYSTEM "${QT_INCLUDES} ${SYSTEM}")
add_definitions(${QT_DEFINITIONS})

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR "ON")