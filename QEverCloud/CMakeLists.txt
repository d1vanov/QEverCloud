cmake_minimum_required(VERSION 3.10.2)

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
    headers/generated/exceptions/EDAMInvalidContactsException.h
    headers/generated/exceptions/EDAMNotFoundException.h
    headers/generated/exceptions/EDAMSystemException.h
    headers/generated/exceptions/EDAMUserException.h
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
    src/generated/exceptions/impl/EDAMInvalidContactsExceptionImpl.h
    src/generated/exceptions/impl/EDAMNotFoundExceptionImpl.h
    src/generated/exceptions/impl/EDAMSystemExceptionImpl.h
    src/generated/exceptions/impl/EDAMUserExceptionImpl.h
    src/generated/types/impl/AccountingImpl.h
    src/generated/types/impl/AccountLimitsImpl.h
    src/generated/types/impl/AuthenticationResultImpl.h
    src/generated/types/impl/BootstrapInfoImpl.h
    src/generated/types/impl/BootstrapProfileImpl.h
    src/generated/types/impl/BootstrapSettingsImpl.h
    src/generated/types/impl/BusinessInvitationImpl.h
    src/generated/types/impl/BusinessNotebookImpl.h
    src/generated/types/impl/BusinessUserAttributesImpl.h
    src/generated/types/impl/BusinessUserInfoImpl.h
    src/generated/types/impl/CanMoveToContainerRestrictionsImpl.h
    src/generated/types/impl/ContactImpl.h
    src/generated/types/impl/CreateOrUpdateNotebookSharesResultImpl.h
    src/generated/types/impl/DataImpl.h
    src/generated/types/impl/IdentityImpl.h
    src/generated/types/impl/InvitationShareRelationshipImpl.h
    src/generated/types/impl/LazyMapImpl.h
    src/generated/types/impl/LinkedNotebookImpl.h
    src/generated/types/impl/ManageNotebookSharesErrorImpl.h
    src/generated/types/impl/ManageNotebookSharesParametersImpl.h
    src/generated/types/impl/ManageNotebookSharesResultImpl.h
    src/generated/types/impl/ManageNoteSharesErrorImpl.h
    src/generated/types/impl/ManageNoteSharesParametersImpl.h
    src/generated/types/impl/ManageNoteSharesResultImpl.h
    src/generated/types/impl/MemberShareRelationshipImpl.h
    src/generated/types/impl/NoteAttributesImpl.h
    src/generated/types/impl/NotebookImpl.h
    src/generated/types/impl/NotebookDescriptorImpl.h
    src/generated/types/impl/NotebookRecipientSettingsImpl.h
    src/generated/types/impl/NotebookRestrictionsImpl.h
    src/generated/types/impl/NotebookShareTemplateImpl.h
    src/generated/types/impl/NoteCollectionCountsImpl.h
    src/generated/types/impl/NoteImpl.h
    src/generated/types/impl/NoteEmailParametersImpl.h
    src/generated/types/impl/NoteFilterImpl.h
    src/generated/types/impl/NoteInvitationShareRelationshipImpl.h
    src/generated/types/impl/NoteLimitsImpl.h
    src/generated/types/impl/NoteListImpl.h
    src/generated/types/impl/NoteMemberShareRelationshipImpl.h
    src/generated/types/impl/NoteMetadataImpl.h
    src/generated/types/impl/NoteRestrictionsImpl.h
    src/generated/types/impl/NoteResultSpecImpl.h
    src/generated/types/impl/NoteShareRelationshipRestrictionsImpl.h
    src/generated/types/impl/NoteShareRelationshipsImpl.h
    src/generated/types/impl/NotesMetadataListImpl.h
    src/generated/types/impl/NotesMetadataResultSpecImpl.h
    src/generated/types/impl/NoteVersionIdImpl.h
    src/generated/types/impl/PublicUserInfoImpl.h
    src/generated/types/impl/PublishingImpl.h
    src/generated/types/impl/RelatedContentImpl.h
    src/generated/types/impl/RelatedContentImageImpl.h
    src/generated/types/impl/RelatedQueryImpl.h
    src/generated/types/impl/RelatedResultImpl.h
    src/generated/types/impl/RelatedResultSpecImpl.h
    src/generated/types/impl/ResourceAttributesImpl.h
    src/generated/types/impl/ResourceImpl.h
    src/generated/types/impl/SavedSearchImpl.h
    src/generated/types/impl/SavedSearchScopeImpl.h
    src/generated/types/impl/SharedNotebookImpl.h
    src/generated/types/impl/SharedNotebookRecipientSettingsImpl.h
    src/generated/types/impl/SharedNoteImpl.h
    src/generated/types/impl/SharedNoteTemplateImpl.h
    src/generated/types/impl/ShareRelationshipRestrictionsImpl.h
    src/generated/types/impl/ShareRelationshipsImpl.h
    src/generated/types/impl/SyncChunkImpl.h
    src/generated/types/impl/SyncChunkFilterImpl.h
    src/generated/types/impl/SyncStateImpl.h
    src/generated/types/impl/TagImpl.h
    src/generated/types/impl/UpdateNoteIfUsnMatchesResultImpl.h
    src/generated/types/impl/UserAttributesImpl.h
    src/generated/types/impl/UserImpl.h
    src/generated/types/impl/UserIdentityImpl.h
    src/generated/types/impl/UserProfileImpl.h
    src/generated/types/impl/UserUrlsImpl.h)

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
    src/generated/exceptions/EDAMInvalidContactsException.cpp
    src/generated/exceptions/EDAMNotFoundException.cpp
    src/generated/exceptions/EDAMSystemException.cpp
    src/generated/exceptions/EDAMUserException.cpp
    src/generated/exceptions/impl/EDAMInvalidContactsExceptionImpl.cpp
    src/generated/exceptions/impl/EDAMNotFoundExceptionImpl.cpp
    src/generated/exceptions/impl/EDAMSystemExceptionImpl.cpp
    src/generated/exceptions/impl/EDAMUserExceptionImpl.cpp
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
    src/generated/types/impl/AccountingImpl.cpp
    src/generated/types/impl/AccountLimitsImpl.cpp
    src/generated/types/impl/AuthenticationResultImpl.cpp
    src/generated/types/impl/BootstrapInfoImpl.cpp
    src/generated/types/impl/BootstrapProfileImpl.cpp
    src/generated/types/impl/BootstrapSettingsImpl.cpp
    src/generated/types/impl/BusinessInvitationImpl.cpp
    src/generated/types/impl/BusinessNotebookImpl.cpp
    src/generated/types/impl/BusinessUserAttributesImpl.cpp
    src/generated/types/impl/BusinessUserInfoImpl.cpp
    src/generated/types/impl/CanMoveToContainerRestrictionsImpl.cpp
    src/generated/types/impl/ContactImpl.cpp
    src/generated/types/impl/CreateOrUpdateNotebookSharesResultImpl.cpp
    src/generated/types/impl/DataImpl.cpp
    src/generated/types/impl/IdentityImpl.cpp
    src/generated/types/impl/InvitationShareRelationshipImpl.cpp
    src/generated/types/impl/LazyMapImpl.cpp
    src/generated/types/impl/LinkedNotebookImpl.cpp
    src/generated/types/impl/ManageNotebookSharesErrorImpl.cpp
    src/generated/types/impl/ManageNotebookSharesParametersImpl.cpp
    src/generated/types/impl/ManageNotebookSharesResultImpl.cpp
    src/generated/types/impl/ManageNoteSharesErrorImpl.cpp
    src/generated/types/impl/ManageNoteSharesParametersImpl.cpp
    src/generated/types/impl/ManageNoteSharesResultImpl.cpp
    src/generated/types/impl/MemberShareRelationshipImpl.cpp
    src/generated/types/impl/NoteAttributesImpl.cpp
    src/generated/types/impl/NotebookImpl.cpp
    src/generated/types/impl/NotebookDescriptorImpl.cpp
    src/generated/types/impl/NotebookRecipientSettingsImpl.cpp
    src/generated/types/impl/NotebookRestrictionsImpl.cpp
    src/generated/types/impl/NotebookShareTemplateImpl.cpp
    src/generated/types/impl/NoteCollectionCountsImpl.cpp
    src/generated/types/impl/NoteImpl.cpp
    src/generated/types/impl/NoteEmailParametersImpl.cpp
    src/generated/types/impl/NoteFilterImpl.cpp
    src/generated/types/impl/NoteInvitationShareRelationshipImpl.cpp
    src/generated/types/impl/NoteLimitsImpl.cpp
    src/generated/types/impl/NoteListImpl.cpp
    src/generated/types/impl/NoteMemberShareRelationshipImpl.cpp
    src/generated/types/impl/NoteMetadataImpl.cpp
    src/generated/types/impl/NoteRestrictionsImpl.cpp
    src/generated/types/impl/NoteResultSpecImpl.cpp
    src/generated/types/impl/NoteShareRelationshipRestrictionsImpl.cpp
    src/generated/types/impl/NoteShareRelationshipsImpl.cpp
    src/generated/types/impl/NotesMetadataListImpl.cpp
    src/generated/types/impl/NotesMetadataResultSpecImpl.cpp
    src/generated/types/impl/NoteVersionIdImpl.cpp
    src/generated/types/impl/PublicUserInfoImpl.cpp
    src/generated/types/impl/PublishingImpl.cpp
    src/generated/types/impl/RelatedContentImpl.cpp
    src/generated/types/impl/RelatedContentImageImpl.cpp
    src/generated/types/impl/RelatedQueryImpl.cpp
    src/generated/types/impl/RelatedResultImpl.cpp
    src/generated/types/impl/RelatedResultSpecImpl.cpp
    src/generated/types/impl/ResourceAttributesImpl.cpp
    src/generated/types/impl/ResourceImpl.cpp
    src/generated/types/impl/SavedSearchImpl.cpp
    src/generated/types/impl/SavedSearchScopeImpl.cpp
    src/generated/types/impl/SharedNotebookImpl.cpp
    src/generated/types/impl/SharedNotebookRecipientSettingsImpl.cpp
    src/generated/types/impl/SharedNoteImpl.cpp
    src/generated/types/impl/SharedNoteTemplateImpl.cpp
    src/generated/types/impl/ShareRelationshipRestrictionsImpl.cpp
    src/generated/types/impl/ShareRelationshipsImpl.cpp
    src/generated/types/impl/SyncChunkImpl.cpp
    src/generated/types/impl/SyncChunkFilterImpl.cpp
    src/generated/types/impl/SyncStateImpl.cpp
    src/generated/types/impl/TagImpl.cpp
    src/generated/types/impl/UpdateNoteIfUsnMatchesResultImpl.cpp
    src/generated/types/impl/UserAttributesImpl.cpp
    src/generated/types/impl/UserImpl.cpp
    src/generated/types/impl/UserIdentityImpl.cpp
    src/generated/types/impl/UserProfileImpl.cpp
    src/generated/types/impl/UserUrlsImpl.cpp)

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
  MACOSX_RPATH ON)

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
  add_test(NAME test_${LIBNAME}
    COMMAND test_${LIBNAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

  set_target_properties(test_${LIBNAME} PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF)

  target_link_libraries(test_${LIBNAME} ${LIBNAME} Qt5::Network Qt5::Test)

  target_include_directories(test_${LIBNAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
    ${PROJECT_BINARY_DIR})

  add_custom_target(check COMMAND "${CMAKE_CTEST_COMMAND}" "--verbose")
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
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/qt5qevercloud
  FILES_MATCHING
  PATTERN *.h
  PATTERN *.in EXCLUDE)

install(FILES ${PROJECT_BINARY_DIR}/LibraryType.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qt5qevercloud")
install(FILES ${PROJECT_BINARY_DIR}/VersionInfo.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qt5qevercloud")

if(BUILD_SHARED_LIBS)
  install(EXPORT QEverCloudExport DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${PROJECT_SOURCE_DIR}/QEverCloud/cmake/modules/QEverCloudFindDependencies.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${PROJECT_BINARY_DIR}/QEverCloud-qt5Config.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${PROJECT_BINARY_DIR}/QEverCloud-qt5ConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
endif()
