if(BUILD_WITH_OAUTH_SUPPORT)
  if(QEVERCLOUD_USE_QT_WEB_ENGINE)
    find_package(Qt5 5.9.5 COMPONENTS Core Widgets Network WebEngineCore WebEngineWidgets ${QEVERCLOUD_FIND_QT_ARGS})
  else()
    find_package(Qt5 5.9.5 COMPONENTS Core Widgets Network WebKit WebKitWidgets ${QEVERCLOUD_FIND_QT_ARGS})
  endif()
else()
  find_package(Qt5 5.9.5 COMPONENTS Core Network ${QEVERCLOUD_FIND_QT_ARGS})
endif()