cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PUBLIC_HEADERS
    headers/QEverCloud.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND PUBLIC_HEADERS
    headers/QEverCloudOAuth.h)
endif()

set(NON_GENERATED_HEADERS
    headers/AsyncResult.h
    headers/DurableService.h
    headers/EventLoopFinisher.h
    headers/EverCloudException.h
    headers/Export.h
    headers/Exceptions.h
    headers/Globals.h
    headers/Helpers.h
    headers/InkNoteImageDownloader.h
    headers/Log.h
    headers/Printable.h
    headers/RequestContext.h
    headers/Thumbnail.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND NON_GENERATED_HEADERS
    headers/OAuth.h)
endif()

set(GENERATED_HEADERS
    headers/generated/Constants.h
    headers/generated/Services.h
    headers/generated/Servers.h
    headers/generated/Types.h
    headers/generated/EDAMErrorCode.h
    headers/generated/types/Accounting.h
    headers/generated/types/AccountLimits.h
    headers/generated/types/AuthenticationResult.h
    headers/generated/types/BootstrapInfo.h
    headers/generated/types/BootstrapProfile.h
    headers/generated/types/BootstrapSettings.h
    headers/generated/types/BusinessInvitation.h
    headers/generated/types/BusinessNotebook.h
    headers/generated/types/BusinessUserAttributes.h
    headers/generated/types/BusinessUserInfo.h
    headers/generated/types/CanMoveToContainerRestrictions.h
    headers/generated/types/Contact.h
    headers/generated/types/CreateOrUpdateNotebookSharesResult.h
    headers/generated/types/Data.h
    headers/generated/types/Identity.h
    headers/generated/types/InvitationShareRelationship.h
    headers/generated/types/LazyMap.h
    headers/generated/types/LinkedNotebook.h
    headers/generated/types/ManageNotebookSharesError.h
    headers/generated/types/ManageNotebookSharesParameters.h
    headers/generated/types/ManageNotebookSharesResult.h
    headers/generated/types/ManageNoteSharesError.h
    headers/generated/types/ManageNoteSharesParameters.h
    headers/generated/types/ManageNoteSharesResult.h
    headers/generated/types/MemberShareRelationship.h
    headers/generated/types/Note.h
    headers/generated/types/NoteAttributes.h
    headers/generated/types/Notebook.h
    headers/generated/types/NotebookDescriptor.h
    headers/generated/types/NotebookRecipientSettings.h
    headers/generated/types/NotebookRestrictions.h
    headers/generated/types/NotebookShareTemplate.h
    headers/generated/types/NoteCollectionCounts.h
    headers/generated/types/NoteEmailParameters.h
    headers/generated/types/NoteFilter.h
    headers/generated/types/NoteInvitationShareRelationship.h
    headers/generated/types/NoteLimits.h
    headers/generated/types/NoteList.h
    headers/generated/types/NoteMemberShareRelationship.h
    headers/generated/types/NoteMetadata.h
    headers/generated/types/NoteRestrictions.h
    headers/generated/types/NoteResultSpec.h
    headers/generated/types/NoteShareRelationshipRestrictions.h
    headers/generated/types/NoteShareRelationships.h
    headers/generated/types/NotesMetadataList.h
    headers/generated/types/NotesMetadataResultSpec.h
    headers/generated/types/NoteVersionId.h
    headers/generated/types/PublicUserInfo.h
    headers/generated/types/Publishing.h
    headers/generated/types/RelatedContent.h
    headers/generated/types/RelatedContentImage.h
    headers/generated/types/RelatedQuery.h
    headers/generated/types/RelatedResult.h
    headers/generated/types/RelatedResultSpec.h
    headers/generated/types/Resource.h
    headers/generated/types/ResourceAttributes.h
    headers/generated/types/SavedSearch.h
    headers/generated/types/SavedSearchScope.h
    headers/generated/types/SharedNote.h
    headers/generated/types/SharedNotebook.h
    headers/generated/types/SharedNotebookRecipientSettings.h
    headers/generated/types/SharedNoteTemplate.h
    headers/generated/types/ShareRelationshipRestrictions.h
    headers/generated/types/ShareRelationships.h
    headers/generated/types/SyncChunk.h
    headers/generated/types/SyncChunkFilter.h
    headers/generated/types/SyncState.h
    headers/generated/types/Tag.h
    headers/generated/types/TypeAliases.h
    headers/generated/types/UpdateNoteIfUsnMatchesResult.h
    headers/generated/types/User.h
    headers/generated/types/UserAttributes.h
    headers/generated/types/UserIdentity.h
    headers/generated/types/UserProfile.h
    headers/generated/types/UserUrls.h)

set(PRIVATE_HEADERS
    src/AsyncResult_p.h
    src/Http.h
    src/Impl.h
    src/NetworkCookieJar.h
    src/Thrift.h
    src/generated/Types_io.h
    src/generated/types/data/AccountingData.h
    src/generated/types/data/AccountLimitsData.h
    src/generated/types/data/AuthenticationResultData.h
    src/generated/types/data/BootstrapInfoData.h
    src/generated/types/data/BootstrapProfileData.h
    src/generated/types/data/BootstrapSettingsData.h
    src/generated/types/data/BusinessInvitationData.h
    src/generated/types/data/BusinessNotebookData.h
    src/generated/types/data/BusinessUserAttributesData.h
    src/generated/types/data/BusinessUserInfoData.h
    src/generated/types/data/CanMoveToContainerRestrictionsData.h
    src/generated/types/data/ContactData.h
    src/generated/types/data/CreateOrUpdateNotebookSharesResultData.h
    src/generated/types/data/DataData.h
    src/generated/types/data/IdentityData.h
    src/generated/types/data/InvitationShareRelationshipData.h
    src/generated/types/data/LazyMapData.h
    src/generated/types/data/LinkedNotebookData.h
    src/generated/types/data/ManageNotebookSharesErrorData.h
    src/generated/types/data/ManageNotebookSharesParametersData.h
    src/generated/types/data/ManageNotebookSharesResultData.h
    src/generated/types/data/ManageNoteSharesErrorData.h
    src/generated/types/data/ManageNoteSharesParametersData.h
    src/generated/types/data/ManageNoteSharesResultData.h
    src/generated/types/data/MemberShareRelationshipData.h
    src/generated/types/data/NoteAttributesData.h
    src/generated/types/data/NotebookData.h
    src/generated/types/data/NotebookDescriptorData.h
    src/generated/types/data/NotebookRecipientSettingsData.h
    src/generated/types/data/NotebookRestrictionsData.h
    src/generated/types/data/NotebookShareTemplateData.h
    src/generated/types/data/NoteCollectionCountsData.h
    src/generated/types/data/NoteData.h
    src/generated/types/data/NoteEmailParametersData.h
    src/generated/types/data/NoteFilterData.h
    src/generated/types/data/NoteInvitationShareRelationshipData.h
    src/generated/types/data/NoteLimitsData.h
    src/generated/types/data/NoteListData.h
    src/generated/types/data/NoteMemberShareRelationshipData.h
    src/generated/types/data/NoteMetadataData.h
    src/generated/types/data/NoteRestrictionsData.h
    src/generated/types/data/NoteResultSpecData.h
    src/generated/types/data/NoteShareRelationshipRestrictionsData.h
    src/generated/types/data/NoteShareRelationshipsData.h
    src/generated/types/data/NotesMetadataListData.h
    src/generated/types/data/NotesMetadataResultSpecData.h
    src/generated/types/data/NoteVersionIdData.h
    src/generated/types/data/PublicUserInfoData.h
    src/generated/types/data/PublishingData.h
    src/generated/types/data/RelatedContentData.h
    src/generated/types/data/RelatedContentImageData.h
    src/generated/types/data/RelatedQueryData.h
    src/generated/types/data/RelatedResultData.h
    src/generated/types/data/RelatedResultSpecData.h
    src/generated/types/data/ResourceAttributesData.h
    src/generated/types/data/ResourceData.h
    src/generated/types/data/SavedSearchData.h
    src/generated/types/data/SavedSearchScopeData.h
    src/generated/types/data/SharedNotebookData.h
    src/generated/types/data/SharedNotebookRecipientSettingsData.h
    src/generated/types/data/SharedNoteData.h
    src/generated/types/data/SharedNoteTemplateData.h
    src/generated/types/data/ShareRelationshipRestrictionsData.h
    src/generated/types/data/ShareRelationshipsData.h
    src/generated/types/data/SyncChunkData.h
    src/generated/types/data/SyncChunkFilterData.h
    src/generated/types/data/SyncStateData.h
    src/generated/types/data/TagData.h
    src/generated/types/data/UpdateNoteIfUsnMatchesResultData.h
    src/generated/types/data/UserAttributesData.h
    src/generated/types/data/UserData.h
    src/generated/types/data/UserIdentityData.h
    src/generated/types/data/UserProfileData.h
    src/generated/types/data/UserUrlsData.h)

set(SOURCES
    src/AsyncResult.cpp
    src/AsyncResult_p.cpp
    src/DurableService.cpp
    src/EventLoopFinisher.cpp
    src/EverCloudException.cpp
    src/Exceptions.cpp
    src/Globals.cpp
    src/Http.cpp
    src/InkNoteImageDownloader.cpp
    src/Log.cpp
    src/Printable.cpp
    src/RequestContext.cpp
    src/Thumbnail.cpp
    src/VersionInfo.cpp
    src/generated/Constants.cpp
    src/generated/EDAMErrorCode.cpp
    src/generated/Services.cpp
    src/generated/Servers.cpp
    src/generated/Types.cpp
    src/generated/types/Accounting.cpp
    src/generated/types/AccountLimits.cpp
    src/generated/types/AuthenticationResult.cpp
    src/generated/types/BootstrapInfo.cpp
    src/generated/types/BootstrapProfile.cpp
    src/generated/types/BootstrapSettings.cpp
    src/generated/types/BusinessInvitation.cpp
    src/generated/types/BusinessNotebook.cpp
    src/generated/types/BusinessUserAttributes.cpp
    src/generated/types/BusinessUserInfo.cpp
    src/generated/types/CanMoveToContainerRestrictions.cpp
    src/generated/types/Contact.cpp
    src/generated/types/CreateOrUpdateNotebookSharesResult.cpp
    src/generated/types/Data.cpp
    src/generated/types/Identity.cpp
    src/generated/types/InvitationShareRelationship.cpp
    src/generated/types/LazyMap.cpp
    src/generated/types/LinkedNotebook.cpp
    src/generated/types/ManageNotebookSharesError.cpp
    src/generated/types/ManageNotebookSharesParameters.cpp
    src/generated/types/ManageNotebookSharesResult.cpp
    src/generated/types/ManageNoteSharesError.cpp
    src/generated/types/ManageNoteSharesParameters.cpp
    src/generated/types/ManageNoteSharesResult.cpp
    src/generated/types/MemberShareRelationship.cpp
    src/generated/types/Note.cpp
    src/generated/types/NoteAttributes.cpp
    src/generated/types/Notebook.cpp
    src/generated/types/NotebookDescriptor.cpp
    src/generated/types/NotebookRecipientSettings.cpp
    src/generated/types/NotebookRestrictions.cpp
    src/generated/types/NotebookShareTemplate.cpp
    src/generated/types/NoteCollectionCounts.cpp
    src/generated/types/NoteEmailParameters.cpp
    src/generated/types/NoteFilter.cpp
    src/generated/types/NoteInvitationShareRelationship.cpp
    src/generated/types/NoteLimits.cpp
    src/generated/types/NoteList.cpp
    src/generated/types/NoteMemberShareRelationship.cpp
    src/generated/types/NoteMetadata.cpp
    src/generated/types/NoteRestrictions.cpp
    src/generated/types/NoteResultSpec.cpp
    src/generated/types/NoteShareRelationshipRestrictions.cpp
    src/generated/types/NoteShareRelationships.cpp
    src/generated/types/NotesMetadataList.cpp
    src/generated/types/NotesMetadataResultSpec.cpp
    src/generated/types/NoteVersionId.cpp
    src/generated/types/PublicUserInfo.cpp
    src/generated/types/Publishing.cpp
    src/generated/types/RelatedContent.cpp
    src/generated/types/RelatedContentImage.cpp
    src/generated/types/RelatedQuery.cpp
    src/generated/types/RelatedResult.cpp
    src/generated/types/RelatedResultSpec.cpp
    src/generated/types/Resource.cpp
    src/generated/types/ResourceAttributes.cpp
    src/generated/types/SavedSearch.cpp
    src/generated/types/SavedSearchScope.cpp
    src/generated/types/SharedNote.cpp
    src/generated/types/SharedNotebook.cpp
    src/generated/types/SharedNotebookRecipientSettings.cpp
    src/generated/types/SharedNoteTemplate.cpp
    src/generated/types/ShareRelationshipRestrictions.cpp
    src/generated/types/ShareRelationships.cpp
    src/generated/types/SyncChunk.cpp
    src/generated/types/SyncChunkFilter.cpp
    src/generated/types/SyncState.cpp
    src/generated/types/Tag.cpp
    src/generated/types/UpdateNoteIfUsnMatchesResult.cpp
    src/generated/types/User.cpp
    src/generated/types/UserAttributes.cpp
    src/generated/types/UserIdentity.cpp
    src/generated/types/UserProfile.cpp
    src/generated/types/UserUrls.cpp
    src/generated/types/data/AccountingData.cpp
    src/generated/types/data/AccountLimitsData.cpp
    src/generated/types/data/AuthenticationResultData.cpp
    src/generated/types/data/BootstrapInfoData.cpp
    src/generated/types/data/BootstrapProfileData.cpp
    src/generated/types/data/BootstrapSettingsData.cpp
    src/generated/types/data/BusinessInvitationData.cpp
    src/generated/types/data/BusinessNotebookData.cpp
    src/generated/types/data/BusinessUserAttributesData.cpp
    src/generated/types/data/BusinessUserInfoData.cpp
    src/generated/types/data/CanMoveToContainerRestrictionsData.cpp
    src/generated/types/data/ContactData.cpp
    src/generated/types/data/CreateOrUpdateNotebookSharesResultData.cpp
    src/generated/types/data/DataData.cpp
    src/generated/types/data/IdentityData.cpp
    src/generated/types/data/InvitationShareRelationshipData.cpp
    src/generated/types/data/LazyMapData.cpp
    src/generated/types/data/LinkedNotebookData.cpp
    src/generated/types/data/ManageNotebookSharesErrorData.cpp
    src/generated/types/data/ManageNotebookSharesParametersData.cpp
    src/generated/types/data/ManageNotebookSharesResultData.cpp
    src/generated/types/data/ManageNoteSharesErrorData.cpp
    src/generated/types/data/ManageNoteSharesParametersData.cpp
    src/generated/types/data/ManageNoteSharesResultData.cpp
    src/generated/types/data/MemberShareRelationshipData.cpp
    src/generated/types/data/NoteAttributesData.cpp
    src/generated/types/data/NotebookData.cpp
    src/generated/types/data/NotebookDescriptorData.cpp
    src/generated/types/data/NotebookRecipientSettingsData.cpp
    src/generated/types/data/NotebookRestrictionsData.cpp
    src/generated/types/data/NotebookShareTemplateData.cpp
    src/generated/types/data/NoteCollectionCountsData.cpp
    src/generated/types/data/NoteData.cpp
    src/generated/types/data/NoteEmailParametersData.cpp
    src/generated/types/data/NoteFilterData.cpp
    src/generated/types/data/NoteInvitationShareRelationshipData.cpp
    src/generated/types/data/NoteLimitsData.cpp
    src/generated/types/data/NoteListData.cpp
    src/generated/types/data/NoteMemberShareRelationshipData.cpp
    src/generated/types/data/NoteMetadataData.cpp
    src/generated/types/data/NoteRestrictionsData.cpp
    src/generated/types/data/NoteResultSpecData.cpp
    src/generated/types/data/NoteShareRelationshipRestrictionsData.cpp
    src/generated/types/data/NoteShareRelationshipsData.cpp
    src/generated/types/data/NotesMetadataListData.cpp
    src/generated/types/data/NotesMetadataResultSpecData.cpp
    src/generated/types/data/NoteVersionIdData.cpp
    src/generated/types/data/PublicUserInfoData.cpp
    src/generated/types/data/PublishingData.cpp
    src/generated/types/data/RelatedContentData.cpp
    src/generated/types/data/RelatedContentImageData.cpp
    src/generated/types/data/RelatedQueryData.cpp
    src/generated/types/data/RelatedResultData.cpp
    src/generated/types/data/RelatedResultSpecData.cpp
    src/generated/types/data/ResourceAttributesData.cpp
    src/generated/types/data/ResourceData.cpp
    src/generated/types/data/SavedSearchData.cpp
    src/generated/types/data/SavedSearchScopeData.cpp
    src/generated/types/data/SharedNotebookData.cpp
    src/generated/types/data/SharedNotebookRecipientSettingsData.cpp
    src/generated/types/data/SharedNoteData.cpp
    src/generated/types/data/SharedNoteTemplateData.cpp
    src/generated/types/data/ShareRelationshipRestrictionsData.cpp
    src/generated/types/data/ShareRelationshipsData.cpp
    src/generated/types/data/SyncChunkData.cpp
    src/generated/types/data/SyncChunkFilterData.cpp
    src/generated/types/data/SyncStateData.cpp
    src/generated/types/data/TagData.cpp
    src/generated/types/data/UpdateNoteIfUsnMatchesResultData.cpp
    src/generated/types/data/UserAttributesData.cpp
    src/generated/types/data/UserData.cpp
    src/generated/types/data/UserIdentityData.cpp
    src/generated/types/data/UserProfileData.cpp
    src/generated/types/data/UserUrlsData.cpp)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND SOURCES
    src/OAuth.cpp)
endif()

if(QEVERCLOUD_USE_QT_WEB_ENGINE)
  list(APPEND SOURCES
    src/NetworkCookieJar.cpp)
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

if(BUILD_WITH_Q_NAMESPACE)
  set(QEVERCLOUD_USES_Q_NAMESPACE "#define QEVERCLOUD_USES_Q_NAMESPACE 1")
else()
  set(QEVERCLOUD_USES_Q_NAMESPACE "#define QEVERCLOUD_USES_Q_NAMESPACE 0")
endif()

if(BUILD_SHARED_LIBS)
  set(QEVERCLOUD_IS_SHARED_LIBRARY "#define QEVERCLOUD_SHARED_LIBRARY 1")
else()
  set(QEVERCLOUD_IS_SHARED_LIBRARY "#define QEVERCLOUD_SHARED_LIBRARY 0")
endif()

set(QEVERCLOUD_VERSION_MAJOR_DEFINE "#define QEVERCLOUD_VERSION_MAJOR ${PROJECT_VERSION_MAJOR}")
set(QEVERCLOUD_VERSION_MINOR_DEFINE "#define QEVERCLOUD_VERSION_MINOR ${PROJECT_VERSION_MINOR}")
set(QEVERCLOUD_VERSION_PATCH_DEFINE "#define QEVERCLOUD_VERSION_PATCH ${PROJECT_VERSION_PATCH}")

if(NOT QEVERCLOUD_BUILD_INFO)
  find_package(Git)
  if(GIT_FOUND)
    message(STATUS "Git found: ${GIT_EXECUTABLE}")

    # Get git branch
    execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --abbrev-ref HEAD
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
      OUTPUT_VARIABLE QEVERCLOUD_GIT_BRANCH
      RESULT_VARIABLE QEVERCLOUD_GIT_BRANCH_RETURN_CODE
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(NOT "${QEVERCLOUD_GIT_BRANCH_RETURN_CODE}" STREQUAL "0")
      message(AUTHOR_WARNING "Failed to determine the current git branch, return code ${QEVERCLOUD_GIT_BRANCH_RETURN_CODE}")
      set(QEVERCLOUD_GIT_BRANCH "unknown branch")
    else()
      if(${QEVERCLOUD_GIT_BRANCH} STREQUAL "HEAD")
        # Can happen if running on detached HEAD, can happen in CI jobs; workaround: try to get the current branch from environment variables
        set(APPVEYOR_REPO_BRANCH "$ENV{APPVEYOR_REPO_BRANCH}")
        set(TRAVIS_BRANCH "$ENV{TRAVIS_BRANCH}")
        if(NOT "${APPVEYOR_REPO_BRANCH}" STREQUAL "")
          set(QEVERCLOUD_GIT_BRANCH "${APPVEYOR_REPO_BRANCH}")
        elseif(NOT "${TRAVIS_BRANCH}" STREQUAL "")
          set(QEVERCLOUD_GIT_BRANCH "${TRAVIS_BRANCH}")
        endif()
      endif()
      message(STATUS "Git branch: ${QEVERCLOUD_GIT_BRANCH}")
    endif()

    # Get last commit short hash
    execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
      OUTPUT_VARIABLE QEVERCLOUD_GIT_REVISION
      RESULT_VARIABLE QEVERCLOUD_GIT_REVISION_RETURN_CODE
      OUTPUT_STRIP_TRAILING_WHITESPACE)
    if(NOT "${QEVERCLOUD_GIT_REVISION_RETURN_CODE}" STREQUAL "0")
      message(AUTHOR_WARNING "Failed to determine the current git revision")
      set(QEVERCLOUD_GIT_REVISION "unknown revision")
    else()
      message(STATUS "Last commit short hash: ${QEVERCLOUD_GIT_REVISION}")
    endif()

    # Check for uncommitted changes
    execute_process(COMMAND ${GIT_EXECUTABLE} diff-index --quiet HEAD --
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
      RESULT_VARIABLE QEVERCLOUD_GIT_DIRTY_STATE)
    if(NOT "${QEVERCLOUD_GIT_DIRTY_STATE}" STREQUAL "0")
      set(QEVERCLOUD_GIT_REVISION "${QEVERCLOUD_GIT_REVISION}, with uncommitted changes")
    endif()

    set(QEVERCLOUD_BUILD_INFO "#define QEVERCLOUD_BUILD_INFO \"${QEVERCLOUD_GIT_BRANCH}, ${QEVERCLOUD_GIT_REVISION}\"")
  else()
    set(QEVERCLOUD_BUILD_INFO "#define QEVERCLOUD_BUILD_INFO \"unknown\"")
  endif()
else()
  set(QEVERCLOUD_BUILD_INFO "#define QEVERCLOUD_BUILD_INFO \"${QEVERCLOUD_BUILD_INFO}\"")
endif()

configure_file(headers/LibraryType.h.in
  ${PROJECT_BINARY_DIR}/LibraryType.h @ONLY)

configure_file(headers/VersionInfo.h.in
  ${PROJECT_BINARY_DIR}/VersionInfo.h @ONLY)

list(APPEND ALL_HEADERS_AND_SOURCES ${PROJECT_BINARY_DIR}/LibraryType.h)
list(APPEND ALL_HEADERS_AND_SOURCES ${PROJECT_BINARY_DIR}/VersionInfo.h)

if(MSVC)
  set(LIBNAME "libqt5qevercloud")
else()
  set(LIBNAME "qt5qevercloud")
endif()

add_library(${LIBNAME} ${ALL_HEADERS_AND_SOURCES})

if(BUILD_SHARED_LIBS)
  message(STATUS "Building QEverCloud shared library")
  target_compile_definitions(${LIBNAME} PRIVATE "-DBUILDING_QEVERCLOUD_SHARED_LIBRARY")
else()
  message(STATUS "Building QEverCloud static library")
endif()

add_sanitizers(${LIBNAME})

set_target_properties(${LIBNAME} PROPERTIES
  VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
  SOVERSION ${PROJECT_VERSION_MAJOR}
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  MACOSX_RPATH 1)

target_compile_features(${LIBNAME} INTERFACE
  cxx_auto_type
  cxx_defaulted_functions
  cxx_defaulted_move_initializers
  cxx_deleted_functions
  cxx_noexcept
  cxx_nullptr
  cxx_override
  cxx_right_angle_brackets
  cxx_rvalue_references
  cxx_strong_enums)

target_compile_features(${LIBNAME} PRIVATE
  cxx_final
  cxx_lambdas
  cxx_range_for)

target_link_libraries(${LIBNAME}
  PUBLIC
  Qt5::Core
  PRIVATE
  Qt5::Network)

if(BUILD_WITH_OAUTH_SUPPORT)
  if(USE_QT5_WEBKIT)
    target_link_libraries(${LIBNAME} PUBLIC Qt5::Widgets PRIVATE Qt5::WebKit Qt5::WebKitWidgets)
  else()
    target_link_libraries(${LIBNAME} PUBLIC Qt5::Widgets PRIVATE Qt5::WebEngineCore Qt5::WebEngineWidgets)
  endif()
endif()

target_compile_definitions(${LIBNAME} PRIVATE
  "-DQT_NO_CAST_FROM_ASCII"
  "-DQT_NO_CAST_TO_ASCII"
  "-DQT_NO_CAST_FROM_BYTEARRAY"
  "-DQT_NO_NARROWING_CONVERSIONS_IN_CONNECT")

target_include_directories(${LIBNAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/headers
  ${PROJECT_BINARY_DIR})

# Tests
find_package(Qt5Test QUIET)
if(Qt5Test_FOUND)
  set(TEST_HEADERS
      src/tests/SocketHelpers.h
      src/tests/TestDurableService.h
      src/tests/generated/RandomDataGenerators.h
      src/tests/generated/TestNoteStore.h
      src/tests/generated/TestUserStore.h)
  set(TEST_SOURCES
      src/tests/SocketHelpers.cpp
      src/tests/TestDurableService.cpp
      src/tests/TestQEverCloud.cpp
      src/tests/generated/RandomDataGenerators.cpp
      src/tests/generated/TestNoteStore.cpp
      src/tests/generated/TestUserStore.cpp)

  add_executable(test_${LIBNAME} ${TEST_HEADERS} ${TEST_SOURCES})
  add_sanitizers(test_${LIBNAME})
  add_test(test_${LIBNAME} test_${PROJECT_NAME})

  set_target_properties(test_${LIBNAME} PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF)

  target_link_libraries(test_${LIBNAME} ${LIBNAME} Qt5::Network Qt5::Test)

  target_include_directories(test_${LIBNAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
    ${PROJECT_BINARY_DIR})
else()
  message(STATUS "Could not find Qt5::Test, won't build tests")
endif()

if(APPLE)
  set(BASE_INSTALL_POINT @loader_path)
else()
  set(BASE_INSTALL_POINT $ORIGIN)
endif()

include(GNUInstallDirs)

file(RELATIVE_PATH BASE_INSTALL_POINT_SUBDIR
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})

set(CMAKE_INSTALL_RPATH ${BASE_INSTALL_POINT} ${BASE_INSTALL_POINT}/${BASE_INSTALL_POINT_SUBDIR})

# install shared library
install(TARGETS ${LIBNAME}
  EXPORT QEverCloudExport
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(DIRECTORY headers/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  FILES_MATCHING
  PATTERN *.in
  EXCLUDE)

# install VersionInfo.h header
install(FILES ${PROJECT_BINARY_DIR}/VersionInfo.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qt5qevercloud")

# install cmake module
if(BUILD_SHARED_LIBS)
  install(EXPORT QEverCloudExport DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${PROJECT_SOURCE_DIR}/QEverCloud/cmake/modules/QEverCloudFindDependencies.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${QEVERCLOUD_BINARY_DIR}/QEverCloud-qt5Config.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${QEVERCLOUD_BINARY_DIR}/QEverCloud-qt5ConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
endif()
