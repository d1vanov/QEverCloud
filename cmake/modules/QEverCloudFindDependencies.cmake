if(_QEVERCLOUD_USE_QT6)
  if(NOT DEFINED OpenGL_GL_PREFERENCE AND NOT CACHE{OpenGL_GL_PREFERENCE} AND NOT ENV{OpenGL_GL_PREFERENCE})
    set(OpenGL_GL_PREFERENCE GLVND)
  endif()

  if(BUILD_WITH_OAUTH_SUPPORT AND NOT QEVERCLOUD_USE_SYSTEM_BROWSER)
    if(BUILD_TRANSLATIONS)
      find_package(Qt6 6.4.0 COMPONENTS Core Gui LinguistTools Network WebEngineCore WebEngineWidgets ${QEVERCLOUD_FIND_QT_ARGS})
    else()
      find_package(Qt6 6.4.0 COMPONENTS Core Gui Network WebEngineCore WebEngineWidgets ${QEVERCLOUD_FIND_QT_ARGS})
    endif()
  else()
    if(BUILD_TRANSLATIONS)
      find_package(Qt6 6.0.0 COMPONENTS Core Gui LinguistTools Network ${QEVERCLOUD_FIND_QT_ARGS})
    else()
      find_package(Qt6 6.0.0 COMPONENTS Core Gui LinguistTools Network ${QEVERCLOUD_FIND_QT_ARGS})
    endif()
  endif()
else()
  if(BUILD_WITH_OAUTH_SUPPORT AND NOT QEVERCLOUD_USE_SYSTEM_BROWSER)
    if(USE_QT5_WEBKIT)
      if(BUILD_TRANSLATIONS)
        find_package(Qt5 5.10.0 COMPONENTS Core LinguistTools Network WebKit WebKitWidgets Widgets ${QEVERCLOUD_FIND_QT_ARGS})
      else()
        find_package(Qt5 5.10.0 COMPONENTS Core Network WebKit WebKitWidgets Widgets ${QEVERCLOUD_FIND_QT_ARGS})
      endif()
    else()
      if(BUILD_TRANSLATIONS)
        find_package(Qt5 5.10.0 COMPONENTS Core LinguistTools Network WebEngineCore WebEngineWidgets Widgets ${QEVERCLOUD_FIND_QT_ARGS})
      else()
        find_package(Qt5 5.10.0 COMPONENTS Core Network WebEngineCore WebEngineWidgets Widgets ${QEVERCLOUD_FIND_QT_ARGS})
      endif()
    endif()
  else()
    if(BUILD_TRANSLATIONS)
      find_package(Qt5 5.10.0 COMPONENTS Core LinguistTools Network ${QEVERCLOUD_FIND_QT_ARGS})
    else()
      find_package(Qt5 5.10.0 COMPONENTS Core Network ${QEVERCLOUD_FIND_QT_ARGS})
    endif()
  endif()
endif()
