cmake_minimum_required(VERSION 3.10.2)

project(QEverCloud VERSION 7.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/sanitizers")

include(QEverCloudDoxygen)

option(BUILD_DOCUMENTATION "Build documentation for QEverCloud" ON)
option(BUILD_QCH_DOCUMENTATION "Build documentation for QEverCloud in qch format" OFF)
option(BUILD_WITH_Q_NAMESPACE "Use Q_NAMESPACE and Q_ENUM_NS macros for introspection" ON)
option(BUILD_WITH_QT6 "Build with Qt6" OFF)

if(NOT BUILD_WITH_QT6)
  option(BUILD_WITH_OAUTH_SUPPORT "Build QEverCloud with OAuth support" ON)
  option(USE_QT5_WEBKIT "Use QtWebKit instead of QtWebEngine" OFF)
endif()

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
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

include(QEverCloudCompilerSettings)

if(USE_QT5_WEBKIT OR BUILD_WITH_QT6)
  set(QEVERCLOUD_USE_QT_WEB_ENGINE OFF)
else()
  set(QEVERCLOUD_USE_QT_WEB_ENGINE ON)
endif()

set(QEVERCLOUD_FIND_QT_ARGS REQUIRED)

if (BUILD_WITH_OAUTH_SUPPORT)
  set(QEVERCLOUD_HAS_OAUTH ON)
else()
  set(QEVERCLOUD_HAS_OAUTH OFF)
endif()

if(BUILD_WITH_QT6)
  set(QEVERCLOUD_QT_VERSION 6)
  set(_QEVERCLOUD_USE_QT6 ON)
else()
  set(QEVERCLOUD_QT_VERSION 5)
  set(_QEVERCLOUD_USE_QT6 OFF)
endif()

include(QEverCloudFindDependencies)

configure_file(cmake/modules/QEverCloudConfig.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-qt${QEVERCLOUD_QT_VERSION}Config.cmake @ONLY)

configure_file(cmake/modules/QEverCloudConfigVersion.cmake.in
  ${PROJECT_BINARY_DIR}/QEverCloud-qt${QEVERCLOUD_QT_VERSION}ConfigVersion.cmake @ONLY)

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
    include/qevercloud/DurableService.h
    include/qevercloud/EventLoopFinisher.h
    include/qevercloud/InkNoteImageDownloader.h
    include/qevercloud/NetworkProxy.h
    include/qevercloud/RequestContext.h
    include/qevercloud/RequestContextBuilder.h
    include/qevercloud/Thumbnail.h
    include/qevercloud/exceptions/EDAMSystemExceptionAuthExpired.h
    include/qevercloud/exceptions/EDAMSystemExceptionRateLimitReached.h
    include/qevercloud/exceptions/EverCloudException.h
    include/qevercloud/exceptions/EvernoteException.h
    include/qevercloud/exceptions/NetworkException.h
    include/qevercloud/exceptions/ThriftException.h
    include/qevercloud/utility/Log.h
    include/qevercloud/utility/Printable.h
    include/qevercloud/utility/ToRange.h)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND NON_GENERATED_HEADERS
    include/qevercloud/OAuth.h)
endif()

set(GENERATED_HEADERS
    include/qevercloud/Constants.h
    include/qevercloud/EDAMErrorCode.h
    include/qevercloud/Fwd.h
    include/qevercloud/exceptions/All.h
    include/qevercloud/exceptions/EDAMInvalidContactsException.h
    include/qevercloud/exceptions/EDAMNotFoundException.h
    include/qevercloud/exceptions/EDAMSystemException.h
    include/qevercloud/exceptions/EDAMUserException.h
    include/qevercloud/exceptions/Fwd.h
    include/qevercloud/exceptions/builders/All.h
    include/qevercloud/exceptions/builders/EDAMInvalidContactsExceptionBuilder.h
    include/qevercloud/exceptions/builders/EDAMNotFoundExceptionBuilder.h
    include/qevercloud/exceptions/builders/EDAMSystemExceptionBuilder.h
    include/qevercloud/exceptions/builders/EDAMUserExceptionBuilder.h
    include/qevercloud/exceptions/builders/Fwd.h
    include/qevercloud/serialization/json/Accounting.h
    include/qevercloud/serialization/json/AccountLimits.h
    include/qevercloud/serialization/json/AuthenticationResult.h
    include/qevercloud/serialization/json/BootstrapInfo.h
    include/qevercloud/serialization/json/BootstrapProfile.h
    include/qevercloud/serialization/json/BootstrapSettings.h
    include/qevercloud/serialization/json/BusinessInvitation.h
    include/qevercloud/serialization/json/BusinessNotebook.h
    include/qevercloud/serialization/json/BusinessUserAttributes.h
    include/qevercloud/serialization/json/BusinessUserInfo.h
    include/qevercloud/serialization/json/CanMoveToContainerRestrictions.h
    include/qevercloud/serialization/json/Contact.h
    include/qevercloud/serialization/json/CreateOrUpdateNotebookSharesResult.h
    include/qevercloud/serialization/json/Data.h
    include/qevercloud/serialization/json/EDAMInvalidContactsException.h
    include/qevercloud/serialization/json/EDAMNotFoundException.h
    include/qevercloud/serialization/json/EDAMSystemException.h
    include/qevercloud/serialization/json/EDAMUserException.h
    include/qevercloud/serialization/json/Identity.h
    include/qevercloud/serialization/json/InvitationShareRelationship.h
    include/qevercloud/serialization/json/LazyMap.h
    include/qevercloud/serialization/json/LinkedNotebook.h
    include/qevercloud/serialization/json/ManageNotebookSharesError.h
    include/qevercloud/serialization/json/ManageNotebookSharesParameters.h
    include/qevercloud/serialization/json/ManageNotebookSharesResult.h
    include/qevercloud/serialization/json/ManageNoteSharesError.h
    include/qevercloud/serialization/json/ManageNoteSharesParameters.h
    include/qevercloud/serialization/json/ManageNoteSharesResult.h
    include/qevercloud/serialization/json/MemberShareRelationship.h
    include/qevercloud/serialization/json/Note.h
    include/qevercloud/serialization/json/NoteAttributes.h
    include/qevercloud/serialization/json/Notebook.h
    include/qevercloud/serialization/json/NotebookDescriptor.h
    include/qevercloud/serialization/json/NotebookRecipientSettings.h
    include/qevercloud/serialization/json/NotebookRestrictions.h
    include/qevercloud/serialization/json/NotebookShareTemplate.h
    include/qevercloud/serialization/json/NoteCollectionCounts.h
    include/qevercloud/serialization/json/NoteEmailParameters.h
    include/qevercloud/serialization/json/NoteFilter.h
    include/qevercloud/serialization/json/NoteInvitationShareRelationship.h
    include/qevercloud/serialization/json/NoteLimits.h
    include/qevercloud/serialization/json/NoteList.h
    include/qevercloud/serialization/json/NoteMemberShareRelationship.h
    include/qevercloud/serialization/json/NoteMetadata.h
    include/qevercloud/serialization/json/NoteRestrictions.h
    include/qevercloud/serialization/json/NoteResultSpec.h
    include/qevercloud/serialization/json/NoteShareRelationshipRestrictions.h
    include/qevercloud/serialization/json/NoteShareRelationships.h
    include/qevercloud/serialization/json/NotesMetadataList.h
    include/qevercloud/serialization/json/NotesMetadataResultSpec.h
    include/qevercloud/serialization/json/NoteVersionId.h
    include/qevercloud/serialization/json/PublicUserInfo.h
    include/qevercloud/serialization/json/Publishing.h
    include/qevercloud/serialization/json/RelatedContent.h
    include/qevercloud/serialization/json/RelatedContentImage.h
    include/qevercloud/serialization/json/RelatedQuery.h
    include/qevercloud/serialization/json/RelatedResult.h
    include/qevercloud/serialization/json/RelatedResultSpec.h
    include/qevercloud/serialization/json/Resource.h
    include/qevercloud/serialization/json/ResourceAttributes.h
    include/qevercloud/serialization/json/SavedSearch.h
    include/qevercloud/serialization/json/SavedSearchScope.h
    include/qevercloud/serialization/json/SharedNote.h
    include/qevercloud/serialization/json/SharedNotebook.h
    include/qevercloud/serialization/json/SharedNotebookRecipientSettings.h
    include/qevercloud/serialization/json/SharedNoteTemplate.h
    include/qevercloud/serialization/json/ShareRelationshipRestrictions.h
    include/qevercloud/serialization/json/ShareRelationships.h
    include/qevercloud/serialization/json/SyncChunk.h
    include/qevercloud/serialization/json/SyncChunkFilter.h
    include/qevercloud/serialization/json/SyncState.h
    include/qevercloud/serialization/json/Tag.h
    include/qevercloud/serialization/json/UpdateNoteIfUsnMatchesResult.h
    include/qevercloud/serialization/json/User.h
    include/qevercloud/serialization/json/UserAttributes.h
    include/qevercloud/serialization/json/UserIdentity.h
    include/qevercloud/serialization/json/UserProfile.h
    include/qevercloud/serialization/json/UserUrls.h
    include/qevercloud/services/Fwd.h
    include/qevercloud/services/INoteStore.h
    include/qevercloud/services/IUserStore.h
    include/qevercloud/services/NoteStoreServer.h
    include/qevercloud/services/UserStoreServer.h
    include/qevercloud/types/Accounting.h
    include/qevercloud/types/AccountLimits.h
    include/qevercloud/types/All.h
    include/qevercloud/types/AuthenticationResult.h
    include/qevercloud/types/BootstrapInfo.h
    include/qevercloud/types/BootstrapProfile.h
    include/qevercloud/types/BootstrapSettings.h
    include/qevercloud/types/BusinessInvitation.h
    include/qevercloud/types/BusinessNotebook.h
    include/qevercloud/types/BusinessUserAttributes.h
    include/qevercloud/types/BusinessUserInfo.h
    include/qevercloud/types/CanMoveToContainerRestrictions.h
    include/qevercloud/types/Contact.h
    include/qevercloud/types/CreateOrUpdateNotebookSharesResult.h
    include/qevercloud/types/Data.h
    include/qevercloud/types/Fwd.h
    include/qevercloud/types/Identity.h
    include/qevercloud/types/InvitationShareRelationship.h
    include/qevercloud/types/LazyMap.h
    include/qevercloud/types/LinkedNotebook.h
    include/qevercloud/types/ManageNotebookSharesError.h
    include/qevercloud/types/ManageNotebookSharesParameters.h
    include/qevercloud/types/ManageNotebookSharesResult.h
    include/qevercloud/types/ManageNoteSharesError.h
    include/qevercloud/types/ManageNoteSharesParameters.h
    include/qevercloud/types/ManageNoteSharesResult.h
    include/qevercloud/types/MemberShareRelationship.h
    include/qevercloud/types/Metatypes.h
    include/qevercloud/types/Note.h
    include/qevercloud/types/NoteAttributes.h
    include/qevercloud/types/Notebook.h
    include/qevercloud/types/NotebookDescriptor.h
    include/qevercloud/types/NotebookRecipientSettings.h
    include/qevercloud/types/NotebookRestrictions.h
    include/qevercloud/types/NotebookShareTemplate.h
    include/qevercloud/types/NoteCollectionCounts.h
    include/qevercloud/types/NoteEmailParameters.h
    include/qevercloud/types/NoteFilter.h
    include/qevercloud/types/NoteInvitationShareRelationship.h
    include/qevercloud/types/NoteLimits.h
    include/qevercloud/types/NoteList.h
    include/qevercloud/types/NoteMemberShareRelationship.h
    include/qevercloud/types/NoteMetadata.h
    include/qevercloud/types/NoteRestrictions.h
    include/qevercloud/types/NoteResultSpec.h
    include/qevercloud/types/NoteShareRelationshipRestrictions.h
    include/qevercloud/types/NoteShareRelationships.h
    include/qevercloud/types/NotesMetadataList.h
    include/qevercloud/types/NotesMetadataResultSpec.h
    include/qevercloud/types/NoteVersionId.h
    include/qevercloud/types/PublicUserInfo.h
    include/qevercloud/types/Publishing.h
    include/qevercloud/types/RelatedContent.h
    include/qevercloud/types/RelatedContentImage.h
    include/qevercloud/types/RelatedQuery.h
    include/qevercloud/types/RelatedResult.h
    include/qevercloud/types/RelatedResultSpec.h
    include/qevercloud/types/Resource.h
    include/qevercloud/types/ResourceAttributes.h
    include/qevercloud/types/SavedSearch.h
    include/qevercloud/types/SavedSearchScope.h
    include/qevercloud/types/SharedNote.h
    include/qevercloud/types/SharedNotebook.h
    include/qevercloud/types/SharedNotebookRecipientSettings.h
    include/qevercloud/types/SharedNoteTemplate.h
    include/qevercloud/types/ShareRelationshipRestrictions.h
    include/qevercloud/types/ShareRelationships.h
    include/qevercloud/types/SyncChunk.h
    include/qevercloud/types/SyncChunkFilter.h
    include/qevercloud/types/SyncState.h
    include/qevercloud/types/Tag.h
    include/qevercloud/types/TypeAliases.h
    include/qevercloud/types/UpdateNoteIfUsnMatchesResult.h
    include/qevercloud/types/User.h
    include/qevercloud/types/UserAttributes.h
    include/qevercloud/types/UserIdentity.h
    include/qevercloud/types/UserProfile.h
    include/qevercloud/types/UserUrls.h
    include/qevercloud/types/builders/AccountingBuilder.h
    include/qevercloud/types/builders/AccountLimitsBuilder.h
    include/qevercloud/types/builders/All.h
    include/qevercloud/types/builders/AuthenticationResultBuilder.h
    include/qevercloud/types/builders/BootstrapInfoBuilder.h
    include/qevercloud/types/builders/BootstrapProfileBuilder.h
    include/qevercloud/types/builders/BootstrapSettingsBuilder.h
    include/qevercloud/types/builders/BusinessInvitationBuilder.h
    include/qevercloud/types/builders/BusinessNotebookBuilder.h
    include/qevercloud/types/builders/BusinessUserAttributesBuilder.h
    include/qevercloud/types/builders/BusinessUserInfoBuilder.h
    include/qevercloud/types/builders/CanMoveToContainerRestrictionsBuilder.h
    include/qevercloud/types/builders/ContactBuilder.h
    include/qevercloud/types/builders/CreateOrUpdateNotebookSharesResultBuilder.h
    include/qevercloud/types/builders/DataBuilder.h
    include/qevercloud/types/builders/Fwd.h
    include/qevercloud/types/builders/IdentityBuilder.h
    include/qevercloud/types/builders/InvitationShareRelationshipBuilder.h
    include/qevercloud/types/builders/LazyMapBuilder.h
    include/qevercloud/types/builders/LinkedNotebookBuilder.h
    include/qevercloud/types/builders/ManageNotebookSharesErrorBuilder.h
    include/qevercloud/types/builders/ManageNotebookSharesParametersBuilder.h
    include/qevercloud/types/builders/ManageNotebookSharesResultBuilder.h
    include/qevercloud/types/builders/ManageNoteSharesErrorBuilder.h
    include/qevercloud/types/builders/ManageNoteSharesParametersBuilder.h
    include/qevercloud/types/builders/ManageNoteSharesResultBuilder.h
    include/qevercloud/types/builders/MemberShareRelationshipBuilder.h
    include/qevercloud/types/builders/NoteAttributesBuilder.h
    include/qevercloud/types/builders/NotebookBuilder.h
    include/qevercloud/types/builders/NotebookDescriptorBuilder.h
    include/qevercloud/types/builders/NotebookRecipientSettingsBuilder.h
    include/qevercloud/types/builders/NotebookRestrictionsBuilder.h
    include/qevercloud/types/builders/NotebookShareTemplateBuilder.h
    include/qevercloud/types/builders/NoteBuilder.h
    include/qevercloud/types/builders/NoteCollectionCountsBuilder.h
    include/qevercloud/types/builders/NoteEmailParametersBuilder.h
    include/qevercloud/types/builders/NoteFilterBuilder.h
    include/qevercloud/types/builders/NoteInvitationShareRelationshipBuilder.h
    include/qevercloud/types/builders/NoteLimitsBuilder.h
    include/qevercloud/types/builders/NoteListBuilder.h
    include/qevercloud/types/builders/NoteMemberShareRelationshipBuilder.h
    include/qevercloud/types/builders/NoteMetadataBuilder.h
    include/qevercloud/types/builders/NoteRestrictionsBuilder.h
    include/qevercloud/types/builders/NoteResultSpecBuilder.h
    include/qevercloud/types/builders/NoteShareRelationshipRestrictionsBuilder.h
    include/qevercloud/types/builders/NoteShareRelationshipsBuilder.h
    include/qevercloud/types/builders/NotesMetadataListBuilder.h
    include/qevercloud/types/builders/NotesMetadataResultSpecBuilder.h
    include/qevercloud/types/builders/NoteVersionIdBuilder.h
    include/qevercloud/types/builders/PublicUserInfoBuilder.h
    include/qevercloud/types/builders/PublishingBuilder.h
    include/qevercloud/types/builders/RelatedContentBuilder.h
    include/qevercloud/types/builders/RelatedContentImageBuilder.h
    include/qevercloud/types/builders/RelatedQueryBuilder.h
    include/qevercloud/types/builders/RelatedResultBuilder.h
    include/qevercloud/types/builders/RelatedResultSpecBuilder.h
    include/qevercloud/types/builders/ResourceAttributesBuilder.h
    include/qevercloud/types/builders/ResourceBuilder.h
    include/qevercloud/types/builders/SavedSearchBuilder.h
    include/qevercloud/types/builders/SavedSearchScopeBuilder.h
    include/qevercloud/types/builders/SharedNotebookBuilder.h
    include/qevercloud/types/builders/SharedNotebookRecipientSettingsBuilder.h
    include/qevercloud/types/builders/SharedNoteBuilder.h
    include/qevercloud/types/builders/SharedNoteTemplateBuilder.h
    include/qevercloud/types/builders/ShareRelationshipRestrictionsBuilder.h
    include/qevercloud/types/builders/ShareRelationshipsBuilder.h
    include/qevercloud/types/builders/SyncChunkBuilder.h
    include/qevercloud/types/builders/SyncChunkFilterBuilder.h
    include/qevercloud/types/builders/SyncStateBuilder.h
    include/qevercloud/types/builders/TagBuilder.h
    include/qevercloud/types/builders/UpdateNoteIfUsnMatchesResultBuilder.h
    include/qevercloud/types/builders/UserAttributesBuilder.h
    include/qevercloud/types/builders/UserBuilder.h
    include/qevercloud/types/builders/UserIdentityBuilder.h
    include/qevercloud/types/builders/UserProfileBuilder.h
    include/qevercloud/types/builders/UserUrlsBuilder.h)

set(PRIVATE_HEADERS
    src/Future.h
    src/Http.h
    src/Impl.h
    src/NetworkCookieJar.h
    src/NetworkReplyFetcher.h
    src/QtFutureContinuations.h
    src/Thrift.h
    src/exceptions/builders/EDAMInvalidContactsExceptionBuilder.cpp
    src/exceptions/builders/EDAMNotFoundExceptionBuilder.cpp
    src/exceptions/builders/EDAMSystemExceptionBuilder.cpp
    src/exceptions/builders/EDAMUserExceptionBuilder.cpp
    src/exceptions/impl/EDAMInvalidContactsExceptionImpl.h
    src/exceptions/impl/EDAMNotFoundExceptionImpl.h
    src/exceptions/impl/EDAMSystemExceptionImpl.h
    src/exceptions/impl/EDAMUserExceptionImpl.h
    src/types/Types_io.h
    src/types/builders/AccountingBuilder.cpp
    src/types/builders/AccountLimitsBuilder.cpp
    src/types/builders/AuthenticationResultBuilder.cpp
    src/types/builders/BootstrapInfoBuilder.cpp
    src/types/builders/BootstrapProfileBuilder.cpp
    src/types/builders/BootstrapSettingsBuilder.cpp
    src/types/builders/BusinessInvitationBuilder.cpp
    src/types/builders/BusinessNotebookBuilder.cpp
    src/types/builders/BusinessUserAttributesBuilder.cpp
    src/types/builders/BusinessUserInfoBuilder.cpp
    src/types/builders/CanMoveToContainerRestrictionsBuilder.cpp
    src/types/builders/ContactBuilder.cpp
    src/types/builders/CreateOrUpdateNotebookSharesResultBuilder.cpp
    src/types/builders/DataBuilder.cpp
    src/types/builders/IdentityBuilder.cpp
    src/types/builders/InvitationShareRelationshipBuilder.cpp
    src/types/builders/LazyMapBuilder.cpp
    src/types/builders/LinkedNotebookBuilder.cpp
    src/types/builders/ManageNotebookSharesErrorBuilder.cpp
    src/types/builders/ManageNotebookSharesParametersBuilder.cpp
    src/types/builders/ManageNotebookSharesResultBuilder.cpp
    src/types/builders/ManageNoteSharesErrorBuilder.cpp
    src/types/builders/ManageNoteSharesParametersBuilder.cpp
    src/types/builders/ManageNoteSharesResultBuilder.cpp
    src/types/builders/MemberShareRelationshipBuilder.cpp
    src/types/builders/NoteAttributesBuilder.cpp
    src/types/builders/NotebookBuilder.cpp
    src/types/builders/NotebookDescriptorBuilder.cpp
    src/types/builders/NotebookRecipientSettingsBuilder.cpp
    src/types/builders/NotebookRestrictionsBuilder.cpp
    src/types/builders/NotebookShareTemplateBuilder.cpp
    src/types/builders/NoteBuilder.cpp
    src/types/builders/NoteCollectionCountsBuilder.cpp
    src/types/builders/NoteEmailParametersBuilder.cpp
    src/types/builders/NoteFilterBuilder.cpp
    src/types/builders/NoteInvitationShareRelationshipBuilder.cpp
    src/types/builders/NoteLimitsBuilder.cpp
    src/types/builders/NoteListBuilder.cpp
    src/types/builders/NoteMemberShareRelationshipBuilder.cpp
    src/types/builders/NoteMetadataBuilder.cpp
    src/types/builders/NoteRestrictionsBuilder.cpp
    src/types/builders/NoteResultSpecBuilder.cpp
    src/types/builders/NoteShareRelationshipRestrictionsBuilder.cpp
    src/types/builders/NoteShareRelationshipsBuilder.cpp
    src/types/builders/NotesMetadataListBuilder.cpp
    src/types/builders/NotesMetadataResultSpecBuilder.cpp
    src/types/builders/NoteVersionIdBuilder.cpp
    src/types/builders/PublicUserInfoBuilder.cpp
    src/types/builders/PublishingBuilder.cpp
    src/types/builders/RelatedContentBuilder.cpp
    src/types/builders/RelatedContentImageBuilder.cpp
    src/types/builders/RelatedQueryBuilder.cpp
    src/types/builders/RelatedResultBuilder.cpp
    src/types/builders/RelatedResultSpecBuilder.cpp
    src/types/builders/ResourceAttributesBuilder.cpp
    src/types/builders/ResourceBuilder.cpp
    src/types/builders/SavedSearchBuilder.cpp
    src/types/builders/SavedSearchScopeBuilder.cpp
    src/types/builders/SharedNotebookBuilder.cpp
    src/types/builders/SharedNotebookRecipientSettingsBuilder.cpp
    src/types/builders/SharedNoteBuilder.cpp
    src/types/builders/SharedNoteTemplateBuilder.cpp
    src/types/builders/ShareRelationshipRestrictionsBuilder.cpp
    src/types/builders/ShareRelationshipsBuilder.cpp
    src/types/builders/SyncChunkBuilder.cpp
    src/types/builders/SyncChunkFilterBuilder.cpp
    src/types/builders/SyncStateBuilder.cpp
    src/types/builders/TagBuilder.cpp
    src/types/builders/UpdateNoteIfUsnMatchesResultBuilder.cpp
    src/types/builders/UserAttributesBuilder.cpp
    src/types/builders/UserBuilder.cpp
    src/types/builders/UserIdentityBuilder.cpp
    src/types/builders/UserProfileBuilder.cpp
    src/types/builders/UserUrlsBuilder.cpp
    src/types/impl/AccountingImpl.h
    src/types/impl/AccountLimitsImpl.h
    src/types/impl/AuthenticationResultImpl.h
    src/types/impl/BootstrapInfoImpl.h
    src/types/impl/BootstrapProfileImpl.h
    src/types/impl/BootstrapSettingsImpl.h
    src/types/impl/BusinessInvitationImpl.h
    src/types/impl/BusinessNotebookImpl.h
    src/types/impl/BusinessUserAttributesImpl.h
    src/types/impl/BusinessUserInfoImpl.h
    src/types/impl/CanMoveToContainerRestrictionsImpl.h
    src/types/impl/ContactImpl.h
    src/types/impl/CreateOrUpdateNotebookSharesResultImpl.h
    src/types/impl/DataImpl.h
    src/types/impl/IdentityImpl.h
    src/types/impl/InvitationShareRelationshipImpl.h
    src/types/impl/LazyMapImpl.h
    src/types/impl/LinkedNotebookImpl.h
    src/types/impl/ManageNotebookSharesErrorImpl.h
    src/types/impl/ManageNotebookSharesParametersImpl.h
    src/types/impl/ManageNotebookSharesResultImpl.h
    src/types/impl/ManageNoteSharesErrorImpl.h
    src/types/impl/ManageNoteSharesParametersImpl.h
    src/types/impl/ManageNoteSharesResultImpl.h
    src/types/impl/MemberShareRelationshipImpl.h
    src/types/impl/NoteAttributesImpl.h
    src/types/impl/NotebookImpl.h
    src/types/impl/NotebookDescriptorImpl.h
    src/types/impl/NotebookRecipientSettingsImpl.h
    src/types/impl/NotebookRestrictionsImpl.h
    src/types/impl/NotebookShareTemplateImpl.h
    src/types/impl/NoteCollectionCountsImpl.h
    src/types/impl/NoteImpl.h
    src/types/impl/NoteEmailParametersImpl.h
    src/types/impl/NoteFilterImpl.h
    src/types/impl/NoteInvitationShareRelationshipImpl.h
    src/types/impl/NoteLimitsImpl.h
    src/types/impl/NoteListImpl.h
    src/types/impl/NoteMemberShareRelationshipImpl.h
    src/types/impl/NoteMetadataImpl.h
    src/types/impl/NoteRestrictionsImpl.h
    src/types/impl/NoteResultSpecImpl.h
    src/types/impl/NoteShareRelationshipRestrictionsImpl.h
    src/types/impl/NoteShareRelationshipsImpl.h
    src/types/impl/NotesMetadataListImpl.h
    src/types/impl/NotesMetadataResultSpecImpl.h
    src/types/impl/NoteVersionIdImpl.h
    src/types/impl/PublicUserInfoImpl.h
    src/types/impl/PublishingImpl.h
    src/types/impl/RelatedContentImpl.h
    src/types/impl/RelatedContentImageImpl.h
    src/types/impl/RelatedQueryImpl.h
    src/types/impl/RelatedResultImpl.h
    src/types/impl/RelatedResultSpecImpl.h
    src/types/impl/ResourceAttributesImpl.h
    src/types/impl/ResourceImpl.h
    src/types/impl/SavedSearchImpl.h
    src/types/impl/SavedSearchScopeImpl.h
    src/types/impl/SharedNotebookImpl.h
    src/types/impl/SharedNotebookRecipientSettingsImpl.h
    src/types/impl/SharedNoteImpl.h
    src/types/impl/SharedNoteTemplateImpl.h
    src/types/impl/ShareRelationshipRestrictionsImpl.h
    src/types/impl/ShareRelationshipsImpl.h
    src/types/impl/SyncChunkImpl.h
    src/types/impl/SyncChunkFilterImpl.h
    src/types/impl/SyncStateImpl.h
    src/types/impl/TagImpl.h
    src/types/impl/UpdateNoteIfUsnMatchesResultImpl.h
    src/types/impl/UserAttributesImpl.h
    src/types/impl/UserImpl.h
    src/types/impl/UserIdentityImpl.h
    src/types/impl/UserProfileImpl.h
    src/types/impl/UserUrlsImpl.h)

set(SOURCES
    src/DurableService.cpp
    src/EventLoopFinisher.cpp
    src/Http.cpp
    src/Impl.cpp
    src/InkNoteImageDownloader.cpp
    src/Log.cpp
    src/NetworkProxy.cpp
    src/NetworkReplyFetcher.cpp
    src/Printable.cpp
    src/RequestContext.cpp
    src/RequestContextBuilder.cpp
    src/Thumbnail.cpp
    src/VersionInfo.cpp
    src/Constants.cpp
    src/EDAMErrorCode.cpp
    src/exceptions/EDAMInvalidContactsException.cpp
    src/exceptions/EDAMNotFoundException.cpp
    src/exceptions/EDAMSystemException.cpp
    src/exceptions/EDAMSystemExceptionAuthExpired.cpp
    src/exceptions/EDAMSystemExceptionRateLimitReached.cpp
    src/exceptions/EDAMUserException.cpp
    src/exceptions/EverCloudException.cpp
    src/exceptions/EvernoteException.cpp
    src/exceptions/NetworkException.cpp
    src/exceptions/ThriftException.cpp
    src/exceptions/impl/EDAMInvalidContactsExceptionImpl.cpp
    src/exceptions/impl/EDAMNotFoundExceptionImpl.cpp
    src/exceptions/impl/EDAMSystemExceptionImpl.cpp
    src/exceptions/impl/EDAMUserExceptionImpl.cpp
    src/serialization/json/Accounting.cpp
    src/serialization/json/AccountLimits.cpp
    src/serialization/json/AuthenticationResult.cpp
    src/serialization/json/BootstrapInfo.cpp
    src/serialization/json/BootstrapProfile.cpp
    src/serialization/json/BootstrapSettings.cpp
    src/serialization/json/BusinessInvitation.cpp
    src/serialization/json/BusinessNotebook.cpp
    src/serialization/json/BusinessUserAttributes.cpp
    src/serialization/json/BusinessUserInfo.cpp
    src/serialization/json/CanMoveToContainerRestrictions.cpp
    src/serialization/json/Contact.cpp
    src/serialization/json/CreateOrUpdateNotebookSharesResult.cpp
    src/serialization/json/Data.cpp
    src/serialization/json/EDAMInvalidContactsException.cpp
    src/serialization/json/EDAMNotFoundException.cpp
    src/serialization/json/EDAMSystemException.cpp
    src/serialization/json/EDAMUserException.cpp
    src/serialization/json/Identity.cpp
    src/serialization/json/InvitationShareRelationship.cpp
    src/serialization/json/LazyMap.cpp
    src/serialization/json/LinkedNotebook.cpp
    src/serialization/json/ManageNotebookSharesError.cpp
    src/serialization/json/ManageNotebookSharesParameters.cpp
    src/serialization/json/ManageNotebookSharesResult.cpp
    src/serialization/json/ManageNoteSharesError.cpp
    src/serialization/json/ManageNoteSharesParameters.cpp
    src/serialization/json/ManageNoteSharesResult.cpp
    src/serialization/json/MemberShareRelationship.cpp
    src/serialization/json/Note.cpp
    src/serialization/json/NoteAttributes.cpp
    src/serialization/json/Notebook.cpp
    src/serialization/json/NotebookDescriptor.cpp
    src/serialization/json/NotebookRecipientSettings.cpp
    src/serialization/json/NotebookRestrictions.cpp
    src/serialization/json/NotebookShareTemplate.cpp
    src/serialization/json/NoteCollectionCounts.cpp
    src/serialization/json/NoteEmailParameters.cpp
    src/serialization/json/NoteFilter.cpp
    src/serialization/json/NoteInvitationShareRelationship.cpp
    src/serialization/json/NoteLimits.cpp
    src/serialization/json/NoteList.cpp
    src/serialization/json/NoteMemberShareRelationship.cpp
    src/serialization/json/NoteMetadata.cpp
    src/serialization/json/NoteRestrictions.cpp
    src/serialization/json/NoteResultSpec.cpp
    src/serialization/json/NoteShareRelationshipRestrictions.cpp
    src/serialization/json/NoteShareRelationships.cpp
    src/serialization/json/NotesMetadataList.cpp
    src/serialization/json/NotesMetadataResultSpec.cpp
    src/serialization/json/NoteVersionId.cpp
    src/serialization/json/PublicUserInfo.cpp
    src/serialization/json/Publishing.cpp
    src/serialization/json/RelatedContent.cpp
    src/serialization/json/RelatedContentImage.cpp
    src/serialization/json/RelatedQuery.cpp
    src/serialization/json/RelatedResult.cpp
    src/serialization/json/RelatedResultSpec.cpp
    src/serialization/json/Resource.cpp
    src/serialization/json/ResourceAttributes.cpp
    src/serialization/json/SavedSearch.cpp
    src/serialization/json/SavedSearchScope.cpp
    src/serialization/json/SharedNote.cpp
    src/serialization/json/SharedNotebook.cpp
    src/serialization/json/SharedNotebookRecipientSettings.cpp
    src/serialization/json/SharedNoteTemplate.cpp
    src/serialization/json/ShareRelationshipRestrictions.cpp
    src/serialization/json/ShareRelationships.cpp
    src/serialization/json/SyncChunk.cpp
    src/serialization/json/SyncChunkFilter.cpp
    src/serialization/json/SyncState.cpp
    src/serialization/json/Tag.cpp
    src/serialization/json/UpdateNoteIfUsnMatchesResult.cpp
    src/serialization/json/User.cpp
    src/serialization/json/UserAttributes.cpp
    src/serialization/json/UserIdentity.cpp
    src/serialization/json/UserProfile.cpp
    src/serialization/json/UserUrls.cpp
    src/services/NoteStore.cpp
    src/services/NoteStoreServer.cpp
    src/services/UserStore.cpp
    src/services/UserStoreServer.cpp
    src/types/Accounting.cpp
    src/types/AccountLimits.cpp
    src/types/AuthenticationResult.cpp
    src/types/BootstrapInfo.cpp
    src/types/BootstrapProfile.cpp
    src/types/BootstrapSettings.cpp
    src/types/BusinessInvitation.cpp
    src/types/BusinessNotebook.cpp
    src/types/BusinessUserAttributes.cpp
    src/types/BusinessUserInfo.cpp
    src/types/CanMoveToContainerRestrictions.cpp
    src/types/Contact.cpp
    src/types/CreateOrUpdateNotebookSharesResult.cpp
    src/types/Data.cpp
    src/types/Identity.cpp
    src/types/InvitationShareRelationship.cpp
    src/types/LazyMap.cpp
    src/types/LinkedNotebook.cpp
    src/types/ManageNotebookSharesError.cpp
    src/types/ManageNotebookSharesParameters.cpp
    src/types/ManageNotebookSharesResult.cpp
    src/types/ManageNoteSharesError.cpp
    src/types/ManageNoteSharesParameters.cpp
    src/types/ManageNoteSharesResult.cpp
    src/types/MemberShareRelationship.cpp
    src/types/Metatypes.cpp
    src/types/Note.cpp
    src/types/NoteAttributes.cpp
    src/types/Notebook.cpp
    src/types/NotebookDescriptor.cpp
    src/types/NotebookRecipientSettings.cpp
    src/types/NotebookRestrictions.cpp
    src/types/NotebookShareTemplate.cpp
    src/types/NoteCollectionCounts.cpp
    src/types/NoteEmailParameters.cpp
    src/types/NoteFilter.cpp
    src/types/NoteInvitationShareRelationship.cpp
    src/types/NoteLimits.cpp
    src/types/NoteList.cpp
    src/types/NoteMemberShareRelationship.cpp
    src/types/NoteMetadata.cpp
    src/types/NoteRestrictions.cpp
    src/types/NoteResultSpec.cpp
    src/types/NoteShareRelationshipRestrictions.cpp
    src/types/NoteShareRelationships.cpp
    src/types/NotesMetadataList.cpp
    src/types/NotesMetadataResultSpec.cpp
    src/types/NoteVersionId.cpp
    src/types/PublicUserInfo.cpp
    src/types/Publishing.cpp
    src/types/RelatedContent.cpp
    src/types/RelatedContentImage.cpp
    src/types/RelatedQuery.cpp
    src/types/RelatedResult.cpp
    src/types/RelatedResultSpec.cpp
    src/types/Resource.cpp
    src/types/ResourceAttributes.cpp
    src/types/SavedSearch.cpp
    src/types/SavedSearchScope.cpp
    src/types/SharedNote.cpp
    src/types/SharedNotebook.cpp
    src/types/SharedNotebookRecipientSettings.cpp
    src/types/SharedNoteTemplate.cpp
    src/types/ShareRelationshipRestrictions.cpp
    src/types/ShareRelationships.cpp
    src/types/SyncChunk.cpp
    src/types/SyncChunkFilter.cpp
    src/types/SyncState.cpp
    src/types/Tag.cpp
    src/types/Types_io.cpp
    src/types/UpdateNoteIfUsnMatchesResult.cpp
    src/types/User.cpp
    src/types/UserAttributes.cpp
    src/types/UserIdentity.cpp
    src/types/UserProfile.cpp
    src/types/UserUrls.cpp
    src/types/impl/AccountingImpl.cpp
    src/types/impl/AccountLimitsImpl.cpp
    src/types/impl/AuthenticationResultImpl.cpp
    src/types/impl/BootstrapInfoImpl.cpp
    src/types/impl/BootstrapProfileImpl.cpp
    src/types/impl/BootstrapSettingsImpl.cpp
    src/types/impl/BusinessInvitationImpl.cpp
    src/types/impl/BusinessNotebookImpl.cpp
    src/types/impl/BusinessUserAttributesImpl.cpp
    src/types/impl/BusinessUserInfoImpl.cpp
    src/types/impl/CanMoveToContainerRestrictionsImpl.cpp
    src/types/impl/ContactImpl.cpp
    src/types/impl/CreateOrUpdateNotebookSharesResultImpl.cpp
    src/types/impl/DataImpl.cpp
    src/types/impl/IdentityImpl.cpp
    src/types/impl/InvitationShareRelationshipImpl.cpp
    src/types/impl/LazyMapImpl.cpp
    src/types/impl/LinkedNotebookImpl.cpp
    src/types/impl/ManageNotebookSharesErrorImpl.cpp
    src/types/impl/ManageNotebookSharesParametersImpl.cpp
    src/types/impl/ManageNotebookSharesResultImpl.cpp
    src/types/impl/ManageNoteSharesErrorImpl.cpp
    src/types/impl/ManageNoteSharesParametersImpl.cpp
    src/types/impl/ManageNoteSharesResultImpl.cpp
    src/types/impl/MemberShareRelationshipImpl.cpp
    src/types/impl/NoteAttributesImpl.cpp
    src/types/impl/NotebookImpl.cpp
    src/types/impl/NotebookDescriptorImpl.cpp
    src/types/impl/NotebookRecipientSettingsImpl.cpp
    src/types/impl/NotebookRestrictionsImpl.cpp
    src/types/impl/NotebookShareTemplateImpl.cpp
    src/types/impl/NoteCollectionCountsImpl.cpp
    src/types/impl/NoteImpl.cpp
    src/types/impl/NoteEmailParametersImpl.cpp
    src/types/impl/NoteFilterImpl.cpp
    src/types/impl/NoteInvitationShareRelationshipImpl.cpp
    src/types/impl/NoteLimitsImpl.cpp
    src/types/impl/NoteListImpl.cpp
    src/types/impl/NoteMemberShareRelationshipImpl.cpp
    src/types/impl/NoteMetadataImpl.cpp
    src/types/impl/NoteRestrictionsImpl.cpp
    src/types/impl/NoteResultSpecImpl.cpp
    src/types/impl/NoteShareRelationshipRestrictionsImpl.cpp
    src/types/impl/NoteShareRelationshipsImpl.cpp
    src/types/impl/NotesMetadataListImpl.cpp
    src/types/impl/NotesMetadataResultSpecImpl.cpp
    src/types/impl/NoteVersionIdImpl.cpp
    src/types/impl/PublicUserInfoImpl.cpp
    src/types/impl/PublishingImpl.cpp
    src/types/impl/RelatedContentImpl.cpp
    src/types/impl/RelatedContentImageImpl.cpp
    src/types/impl/RelatedQueryImpl.cpp
    src/types/impl/RelatedResultImpl.cpp
    src/types/impl/RelatedResultSpecImpl.cpp
    src/types/impl/ResourceAttributesImpl.cpp
    src/types/impl/ResourceImpl.cpp
    src/types/impl/SavedSearchImpl.cpp
    src/types/impl/SavedSearchScopeImpl.cpp
    src/types/impl/SharedNotebookImpl.cpp
    src/types/impl/SharedNotebookRecipientSettingsImpl.cpp
    src/types/impl/SharedNoteImpl.cpp
    src/types/impl/SharedNoteTemplateImpl.cpp
    src/types/impl/ShareRelationshipRestrictionsImpl.cpp
    src/types/impl/ShareRelationshipsImpl.cpp
    src/types/impl/SyncChunkImpl.cpp
    src/types/impl/SyncChunkFilterImpl.cpp
    src/types/impl/SyncStateImpl.cpp
    src/types/impl/TagImpl.cpp
    src/types/impl/UpdateNoteIfUsnMatchesResultImpl.cpp
    src/types/impl/UserAttributesImpl.cpp
    src/types/impl/UserImpl.cpp
    src/types/impl/UserIdentityImpl.cpp
    src/types/impl/UserProfileImpl.cpp
    src/types/impl/UserUrlsImpl.cpp)

if(BUILD_WITH_OAUTH_SUPPORT)
  list(APPEND SOURCES
    src/OAuth.cpp)
endif()

if(QEVERCLOUD_USE_QT_WEB_ENGINE)
  list(APPEND SOURCES
    src/NetworkCookieJar.cpp)
endif()

if(NOT BUILD_WITH_QT6)
  list(APPEND PRIVATE_HEADERS
    src/Qt5Promise.h
    src/Qt5FutureHelpers.h)
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

set(LIBNAME "qt${QEVERCLOUD_QT_VERSION}qevercloud")
add_library(${LIBNAME} ${ALL_HEADERS_AND_SOURCES})

if(MSVC)
  set_target_properties(${LIBNAME} PROPERTIES PREFIX "lib")
endif()

add_library(QEverCloud::${LIBNAME} ALIAS ${LIBNAME})

include(GenerateExportHeader)

generate_export_header(
  ${LIBNAME}
  BASE_NAME QEverCloud
  EXPORT_MACRO_NAME QEVERCLOUD_EXPORT
  EXPORT_FILE_NAME qevercloud/Export.h
  STATIC_DEFINE BUILDING_QEVERCLOUD_STATIC_LIBRARY)

if(BUILD_SHARED_LIBS)
  message(STATUS "Building QEverCloud shared library")
  if(BUILD_WITH_QT6)
    target_compile_definitions(${LIBNAME} PRIVATE "-Dqt6qevercloud_EXPORTS")
  else()
    target_compile_definitions(${LIBNAME} PRIVATE "-Dqt5qevercloud_EXPORTS")
  endif()
else()
  message(STATUS "Building QEverCloud static library")
  target_compile_definitions(${LIBNAME} PRIVATE "-DBUILDING_QEVERCLOUD_STATIC_LIBRARY")
endif()

add_sanitizers(${LIBNAME})

set_target_properties(${LIBNAME} PROPERTIES
  VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}"
  SOVERSION ${PROJECT_VERSION_MAJOR}
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  MACOSX_RPATH ON)

if(BUILD_WITH_QT6)
  target_link_libraries(${LIBNAME}
    PUBLIC
    Qt6::Core
    PRIVATE
    Qt6::Gui
    Qt6::Network)
else()
  target_link_libraries(${LIBNAME}
    PUBLIC
    Qt5::Core
    PRIVATE
    Qt5::Network)
endif()

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
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${PROJECT_BINARY_DIR})

# Tests
if(BUILD_WITH_QT6)
  find_package(Qt6Test QUIET)
else()
  find_package(Qt5Test QUIET)
endif()

if((BUILD_WITH_QT6 AND Qt6Test_FOUND) OR (NOT BUILD_WITH_QT6 AND Qt5Test_FOUND))
  set(TEST_HEADERS
      tests/InkNoteImageDownloaderTester.h
      tests/SocketHelpers.h
      tests/TestDurableService.h
      tests/TestSerializationJson.h
      tests/TestTypeBuilders.h
      tests/ClearLocalFields.h
      tests/RandomDataGenerators.h
      tests/services/TestNoteStore.h
      tests/services/TestUserStore.h)

  set(TEST_SOURCES
      tests/InkNoteImageDownloaderTester.cpp
      tests/SocketHelpers.cpp
      tests/TestDurableService.cpp
      tests/TestSerializationJson.cpp
      tests/TestQEverCloud.cpp
      tests/TestTypeBuilders.cpp
      tests/ClearLocalFields.cpp
      tests/RandomDataGenerators.cpp
      tests/services/TestNoteStore.cpp
      tests/services/TestUserStore.cpp)

  set(TEST_RESOURCES
    tests/resources/stripes.qrc)

  if (BUILD_WITH_QT6)
    qt6_add_resources(test_${LIBNAME}_RESOURCES_RCC ${TEST_RESOURCES})
  else()
    qt5_add_resources(test_${LIBNAME}_RESOURCES_RCC ${TEST_RESOURCES})
  endif()

  add_executable(
    test_${LIBNAME}
    ${TEST_HEADERS}
    ${TEST_SOURCES}
    ${test_${LIBNAME}_RESOURCES_RCC})

  add_sanitizers(test_${LIBNAME})

  add_test(NAME test_${LIBNAME}
    COMMAND test_${LIBNAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

  set_target_properties(test_${LIBNAME} PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF)

  if(BUILD_WITH_QT6)
    target_link_libraries(test_${LIBNAME} ${LIBNAME} Qt6::Network Qt6::Test)
  else()
    target_link_libraries(test_${LIBNAME} ${LIBNAME} Qt5::Network Qt5::Test)
  endif()

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

install(FILES ${PROJECT_BINARY_DIR}/qevercloud/LibraryType.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qevercloud")
install(FILES ${PROJECT_BINARY_DIR}/qevercloud/VersionInfo.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qevercloud")
install(FILES ${PROJECT_BINARY_DIR}/qevercloud/Export.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/qevercloud")

if(BUILD_SHARED_LIBS)
  install(EXPORT QEverCloudExport NAMESPACE QEverCloud:: DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt${QEVERCLOUD_QT_VERSION})
  install(FILES ${PROJECT_SOURCE_DIR}/cmake/modules/QEverCloudFindDependencies.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt${QEVERCLOUD_QT_VERSION})
  install(FILES ${PROJECT_BINARY_DIR}/QEverCloud-qt${QEVERCLOUD_QT_VERSION}Config.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt${QEVERCLOUD_QT_VERSION})
  install(FILES ${PROJECT_BINARY_DIR}/QEverCloud-qt${QEVERCLOUD_QT_VERSION}ConfigVersion.cmake DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/QEverCloud-qt${QEVERCLOUD_QT_VERSION})
endif()
