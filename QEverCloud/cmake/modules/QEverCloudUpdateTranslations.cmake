macro(update_translation SOURCES TRANSLATIONS)
  # First generate the fake .pro file for lupdate utility
  set(fake_pro_file "${PROJECT_BINARY_DIR}/fake_pro_file.pro")

  # generate .pro file for lupdate utility
  file(WRITE "${fake_pro_file}"
    "#\n"
    "# This file was autogenerated by update_translation macro\n"
    "# All changes will be lost\n"
    "#\n")

  # INCLUDEPATH section
  file(APPEND "${fake_pro_file}"
    "\n"
    "INCLUDEPATH += ${PROJECT_SOURCE_DIR}/QEverCloud/headers\n")

  # SOURCES section
  file(APPEND "${fake_pro_file}"
    "\n"
    "SOURCES =\\\n")

  foreach(source_file ${SOURCES})
    file(APPEND "${fake_pro_file}" "  ${PROJECT_SOURCE_DIR}/QEverCloud/${source_file}\\\n")
  endforeach()

  # TRANSLATIONS section
  file(APPEND "${fake_pro_file}"
    "\n"
    "TRANSLATIONS =\\\n")

  foreach(translation_file ${TRANSLATIONS})
    file(APPEND "${fake_pro_file}" "  ${PROJECT_SOURCE_DIR}/${translation_file}\\\n")
  endforeach()

  file(APPEND "${fake_pro_file}"
    "\n")

  set(LUPDATE ${Qt5_LUPDATE_EXECUTABLE})
  set(LRELEASE ${Qt5_LRELEASE_EXECUTABLE})

  add_custom_target(lupdate COMMAND ${LUPDATE} -verbose -noobsolete \"${fake_pro_file}\" DEPENDS ${fake_pro_file})

  add_custom_target(lrelease)
  file(MAKE_DIRECTORY "${PROJECT_BINARY_DIR}/QEverCloud/translations")
  foreach(translation_file ${TRANSLATIONS})
    string(FIND ${translation_file} "." DOT_POS)
    string(SUBSTRING ${translation_file} 0 ${DOT_POS} QM_FILE_NAME)
    # NOTE: "translations/" is already included into QM_FILE_NAME
    set(QM_FILE "${PROJECT_BINARY_DIR}/${QM_FILE_NAME}.qm")
    list(APPEND ${PROJECT_NAME}_QM_FILES ${QM_FILE})
    add_custom_command(COMMAND ${LRELEASE} ${PROJECT_SOURCE_DIR}/${translation_file} -qm \"${QM_FILE}\" TARGET lrelease POST_BUILD)
  endforeach()
endmacro()
