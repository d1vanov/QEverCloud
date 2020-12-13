cmake_minimum_required(VERSION 3.10.2)

project(QEverCloud VERSION 7.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/sanitizers")

include(QEverCloudDoxygen)

option(BUILD_DOCUMENTATION "Build documentation for QEverCloud" ON)
option(BUILD_QCH_DOCUMENTATION "Build documentation for QEverCloud in qch format" OFF)
option(BUILD_WITH_OAUTH_SUPPORT "Build QEverCloud with OAuth support" ON)
option(BUILD_WITH_Q_NAMESPACE "Use Q_NAMESPACE and Q_ENUM_NS macros for introspection" ON)
option(USE_QT5_WEBKIT "Use QtWebKit instead of QtWebEngine" OFF)

if(BUILD_DOCUMENTATION)
  set(DOXY_INPUT                  "${PROJECT_SOURCE_DIR}/QEverCloud/include/qevercloud ${PROJECT_SOURCE_DIR}/README.md")
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

configure_file(cmake/modules/QEverCloudConfig.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-qt5Config.cmake @ONLY)

configure_file(cmake/modules/QEverCloudConfigVersion.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-qt5ConfigVersion.cmake @ONLY)

find_package(Sanitizers)

enable_testing()

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(PUBLIC_HEADERS
    include/qevercloud/QEverCloud.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND PUBLIC_HEADERS
    include/qevercloud/QEverCloudOAuth.h)
endif()

set(NON_GENERATED_HEADERS
    include/qevercloud/AsyncResult.h
    include/qevercloud/DurableService.h
    include/qevercloud/EventLoopFinisher.h
    include/qevercloud/EverCloudException.h
    include/qevercloud/Export.h
    include/qevercloud/Exceptions.h
    include/qevercloud/Globals.h
    include/qevercloud/InkNoteImageDownloader.h
    include/qevercloud/Log.h
    include/qevercloud/Printable.h
    include/qevercloud/RequestContext.h
    include/qevercloud/Thumbnail.h
    include/qevercloud/utility/ToRange.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND NON_GENERATED_HEADERS
    include/qevercloud/OAuth.h)
endif()

set(GENERATED_HEADERS
    include/qevercloud/generated/Constants.h
    include/qevercloud/generated/Services.h
    include/qevercloud/generated/Servers.h
    include/qevercloud/generated/Types.h
    include/qevercloud/generated/EDAMErrorCode.h
    include/qevercloud/generated/exceptions/EDAMInvalidContactsException.h
    include/qevercloud/generated/exceptions/EDAMNotFoundException.h
    include/qevercloud/generated/exceptions/EDAMSystemException.h
    include/qevercloud/generated/exceptions/EDAMUserException.h
    include/qevercloud/generated/types/Accounting.h
    include/qevercloud/generated/types/AccountLimits.h
    include/qevercloud/generated/types/AuthenticationResult.h
    include/qevercloud/generated/types/BootstrapInfo.h
    include/qevercloud/generated/types/BootstrapProfile.h
    include/qevercloud/generated/types/BootstrapSettings.h
    include/qevercloud/generated/types/BusinessInvitation.h
    include/qevercloud/generated/types/BusinessNotebook.h
    include/qevercloud/generated/types/BusinessUserAttributes.h
    include/qevercloud/generated/types/BusinessUserInfo.h
    include/qevercloud/generated/types/CanMoveToContainerRestrictions.h
    include/qevercloud/generated/types/Contact.h
    include/qevercloud/generated/types/CreateOrUpdateNotebookSharesResult.h
    include/qevercloud/generated/types/Data.h
    include/qevercloud/generated/types/Identity.h
    include/qevercloud/generated/types/InvitationShareRelationship.h
    include/qevercloud/generated/types/LazyMap.h
    include/qevercloud/generated/types/LinkedNotebook.h
    include/qevercloud/generated/types/ManageNotebookSharesError.h
    include/qevercloud/generated/types/ManageNotebookSharesParameters.h
    include/qevercloud/generated/types/ManageNotebookSharesResult.h
    include/qevercloud/generated/types/ManageNoteSharesError.h
    include/qevercloud/generated/types/ManageNoteSharesParameters.h
    include/qevercloud/generated/types/ManageNoteSharesResult.h
    include/qevercloud/generated/types/MemberShareRelationship.h
    include/qevercloud/generated/types/Note.h
    include/qevercloud/generated/types/NoteAttributes.h
    include/qevercloud/generated/types/Notebook.h
    include/qevercloud/generated/types/NotebookDescriptor.h
    include/qevercloud/generated/types/NotebookRecipientSettings.h
    include/qevercloud/generated/types/NotebookRestrictions.h
    include/qevercloud/generated/types/NotebookShareTemplate.h
    include/qevercloud/generated/types/NoteCollectionCounts.h
    include/qevercloud/generated/types/NoteEmailParameters.h
    include/qevercloud/generated/types/NoteFilter.h
    include/qevercloud/generated/types/NoteInvitationShareRelationship.h
    include/qevercloud/generated/types/NoteLimits.h
    include/qevercloud/generated/types/NoteList.h
    include/qevercloud/generated/types/NoteMemberShareRelationship.h
    include/qevercloud/generated/types/NoteMetadata.h
    include/qevercloud/generated/types/NoteRestrictions.h
    include/qevercloud/generated/types/NoteResultSpec.h
    include/qevercloud/generated/types/NoteShareRelationshipRestrictions.h
    include/qevercloud/generated/types/NoteShareRelationships.h
    include/qevercloud/generated/types/NotesMetadataList.h
    include/qevercloud/generated/types/NotesMetadataResultSpec.h
    include/qevercloud/generated/types/NoteVersionId.h
    include/qevercloud/generated/types/PublicUserInfo.h
    include/qevercloud/generated/types/Publishing.h
    include/qevercloud/generated/types/RelatedContent.h
    include/qevercloud/generated/types/RelatedContentImage.h
    include/qevercloud/generated/types/RelatedQuery.h
    include/qevercloud/generated/types/RelatedResult.h
    include/qevercloud/generated/types/RelatedResultSpec.h
    include/qevercloud/generated/types/Resource.h
    include/qevercloud/generated/types/ResourceAttributes.h
    include/qevercloud/generated/types/SavedSearch.h
    include/qevercloud/generated/types/SavedSearchScope.h
    include/qevercloud/generated/types/SharedNote.h
    include/qevercloud/generated/types/SharedNotebook.h
    include/qevercloud/generated/types/SharedNotebookRecipientSettings.h
    include/qevercloud/generated/types/SharedNoteTemplate.h
    include/qevercloud/generated/types/ShareRelationshipRestrictions.h
    include/qevercloud/generated/types/ShareRelationships.h
    include/qevercloud/generated/types/SyncChunk.h
    include/qevercloud/generated/types/SyncChunkFilter.h
    include/qevercloud/generated/types/SyncState.h
    include/qevercloud/generated/types/Tag.h
    include/qevercloud/generated/types/TypeAliases.h
    include/qevercloud/generated/types/UpdateNoteIfUsnMatchesResult.h
    include/qevercloud/generated/types/User.h
    include/qevercloud/generated/types/UserAttributes.h
    include/qevercloud/generated/types/UserIdentity.h
    include/qevercloud/generated/types/UserProfile.h
    include/qevercloud/generated/types/UserUrls.h)

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

configure_file(include/qevercloud/LibraryType.h.in
  ${PROJECT_BINARY_DIR}/qevercloud/LibraryType.h @ONLY)

configure_file(include/qevercloud/VersionInfo.h.in
  ${PROJECT_BINARY_DIR}/qevercloud/VersionInfo.h @ONLY)

list(APPEND ALL_HEADERS_AND_SOURCES ${PROJECT_BINARY_DIR}/qevercloud/LibraryType.h)
list(APPEND ALL_HEADERS_AND_SOURCES ${PROJECT_BINARY_DIR}/qevercloud/VersionInfo.h)

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

target_include_directories(${LIBNAME}
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR})

# Tests
find_package(Qt5Test QUIET)
if(Qt5Test_FOUND)
  set(TEST_HEADERS
      tests/SocketHelpers.h
      tests/TestDurableService.h
      tests/generated/RandomDataGenerators.h
      tests/generated/TestNoteStore.h
      tests/generated/TestUserStore.h)

  set(TEST_SOURCES
      tests/SocketHelpers.cpp
      tests/TestDurableService.cpp
      tests/TestQEverCloud.cpp
      tests/generated/RandomDataGenerators.cpp
      tests/generated/TestNoteStore.cpp
      tests/generated/TestUserStore.cpp)

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
    ${CMAKE_CURRENT_SOURCE_DIR}/include
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

install(DIRECTORY include/qevercloud/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/qevercloud
  FILES_MATCHING
  PATTERN *.h
  PATTERN *.in EXCLUDE)

install(FILES ${PROJECT_BINARY_DIR}/LibraryType.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qevercloud")
install(FILES ${PROJECT_BINARY_DIR}/VersionInfo.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qevercloud")

if(BUILD_SHARED_LIBS)
  install(EXPORT QEverCloudExport DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${PROJECT_SOURCE_DIR}/cmake/modules/QEverCloudFindDependencies.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${PROJECT_BINARY_DIR}/QEverCloud-qt5Config.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
  install(FILES ${PROJECT_BINARY_DIR}/QEverCloud-qt5ConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt5)
endif()
