/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2025 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <generated/Constants.h>
#include "../Impl.h"
#include <Helpers.h>

namespace qevercloud {

////////////////////////////////////////////////////////////////////////////////

// Limits.thrift

const qint32 EDAM_ATTRIBUTE_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_ATTRIBUTE_LEN_MAX = 4096;
// Limits.thrift

const QString EDAM_ATTRIBUTE_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Zl}\\p{Zp}]{1,4096}$");
// Limits.thrift

const qint32 EDAM_ATTRIBUTE_LIST_MAX = 100;
// Limits.thrift

const qint32 EDAM_ATTRIBUTE_MAP_MAX = 100;
// Limits.thrift

const qint32 EDAM_GUID_LEN_MIN = 36;
// Limits.thrift

const qint32 EDAM_GUID_LEN_MAX = 36;
// Limits.thrift

const QString EDAM_GUID_REGEX = QStringLiteral("^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$");
// Limits.thrift

const qint32 EDAM_EMAIL_LEN_MIN = 6;
// Limits.thrift

const qint32 EDAM_EMAIL_LEN_MAX = 255;
// Limits.thrift

const QString EDAM_EMAIL_LOCAL_REGEX = QStringLiteral("^[A-Za-z0-9!#$%&'*+/=?^_`{|}~-]+(\\.[A-Za-z0-9!#$%&'*+/=?^_`{|}~-]+)*$");
// Limits.thrift

const QString EDAM_EMAIL_DOMAIN_REGEX = QStringLiteral("^[A-Za-z0-9-]*[A-Za-z0-9](\\.[A-Za-z0-9-]*[A-Za-z0-9])*\\.([A-Za-z]{2,})$");
// Limits.thrift

const QString EDAM_EMAIL_REGEX = QStringLiteral("^[A-Za-z0-9!#$%&'*+/=?^_`{|}~-]+(\\.[A-Za-z0-9!#$%&'*+/=?^_`{|}~-]+)*@[A-Za-z0-9-]*[A-Za-z0-9](\\.[A-Za-z0-9-]*[A-Za-z0-9])*\\.([A-Za-z]{2,})$");
// Limits.thrift

const QString EDAM_VAT_REGEX = QStringLiteral("^(AT)?U[0-9]{8}$|^(BE)?0?[0-9]{9}$|^(BG)?[0-9]{9,10}$|^(CY)?[0-9]{8}L$|^(CZ)?[0-9]{8,10}$|^(DE)?[0-9]{9}$|^(DK)?[0-9]{8}$|^(EE)?[0-9]{9}$|^(EL|GR)?[0-9]{9}$|^(ES)?[0-9A-Z][0-9]{7}[0-9A-Z]$|^(FI)?[0-9]{8}$|^(FR)?[0-9A-Z]{2}[0-9]{9}$|^(GB)?([0-9]{9}([0-9]{3})?|[A-Z]{2}[0-9]{3})$|^(HU)?[0-9]{8}$|^(IE)?[0-9]{7}[A-Z]{1,2}$|^(IT)?[0-9]{11}$|^(LT)?([0-9]{9}|[0-9]{12})$|^(LU)?[0-9]{8}$|^(LV)?[0-9]{11}$|^(MT)?[0-9]{8}$|^(NL)?[0-9]{9}B[0-9]{2}$|^(PL)?[0-9]{10}$|^(PT)?[0-9]{9}$|^(RO)?[0-9]{2,10}$|^(SE)?[0-9]{12}$|^(SI)?[0-9]{8}$|^(SK)?[0-9]{10}$|^[0-9]{9}MVA$|^[0-9]{6}$|^CHE[0-9]{9}(TVA|MWST|IVA)$");
// Limits.thrift

const qint32 EDAM_TIMEZONE_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_TIMEZONE_LEN_MAX = 32;
// Limits.thrift

const QString EDAM_TIMEZONE_REGEX = QStringLiteral("^([A-Za-z_-]+(/[A-Za-z_-]+)*)|(GMT(-|\\+)[0-9]{1,2}(:[0-9]{2})?)$");
// Limits.thrift

const qint32 EDAM_MIME_LEN_MIN = 3;
// Limits.thrift

const qint32 EDAM_MIME_LEN_MAX = 255;
// Limits.thrift

const QString EDAM_MIME_REGEX = QStringLiteral("^[A-Za-z]+/[A-Za-z0-9._+-]+$");
// Limits.thrift

const QString EDAM_MIME_TYPE_GIF = QStringLiteral("image/gif");
// Limits.thrift

const QString EDAM_MIME_TYPE_JPEG = QStringLiteral("image/jpeg");
// Limits.thrift

const QString EDAM_MIME_TYPE_PNG = QStringLiteral("image/png");
// Limits.thrift

const QString EDAM_MIME_TYPE_TIFF = QStringLiteral("image/tiff");
// Limits.thrift

const QString EDAM_MIME_TYPE_BMP = QStringLiteral("image/bmp");
// Limits.thrift

const QString EDAM_MIME_TYPE_WAV = QStringLiteral("audio/wav");
// Limits.thrift

const QString EDAM_MIME_TYPE_MP3 = QStringLiteral("audio/mpeg");
// Limits.thrift

const QString EDAM_MIME_TYPE_AMR = QStringLiteral("audio/amr");
// Limits.thrift

const QString EDAM_MIME_TYPE_AAC = QStringLiteral("audio/aac");
// Limits.thrift

const QString EDAM_MIME_TYPE_M4A = QStringLiteral("audio/mp4");
// Limits.thrift

const QString EDAM_MIME_TYPE_MP4_VIDEO = QStringLiteral("video/mp4");
// Limits.thrift

const QString EDAM_MIME_TYPE_INK = QStringLiteral("application/vnd.evernote.ink");
// Limits.thrift

const QString EDAM_MIME_TYPE_PDF = QStringLiteral("application/pdf");
// Limits.thrift

const QString EDAM_MIME_TYPE_DEFAULT = QStringLiteral("application/octet-stream");
// Limits.thrift

const QSet<QString> EDAM_MIME_TYPES = QSet<QString>()
    << EDAM_MIME_TYPE_GIF
    << EDAM_MIME_TYPE_JPEG
    << EDAM_MIME_TYPE_PNG
    << EDAM_MIME_TYPE_WAV
    << EDAM_MIME_TYPE_MP3
    << EDAM_MIME_TYPE_AMR
    << EDAM_MIME_TYPE_INK
    << EDAM_MIME_TYPE_PDF
    << EDAM_MIME_TYPE_MP4_VIDEO
    << EDAM_MIME_TYPE_AAC
    << EDAM_MIME_TYPE_M4A
;
// Limits.thrift

const QSet<QString> EDAM_INDEXABLE_RESOURCE_MIME_TYPES = QSet<QString>()
    << QStringLiteral("application/msword")
    << QStringLiteral("application/mspowerpoint")
    << QStringLiteral("application/excel")
    << QStringLiteral("application/vnd.ms-word")
    << QStringLiteral("application/vnd.ms-powerpoint")
    << QStringLiteral("application/vnd.ms-excel")
    << QStringLiteral("application/vnd.openxmlformats-officedocument.wordprocessingml.document")
    << QStringLiteral("application/vnd.openxmlformats-officedocument.presentationml.presentation")
    << QStringLiteral("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet")
    << QStringLiteral("application/vnd.apple.pages")
    << QStringLiteral("application/vnd.apple.numbers")
    << QStringLiteral("application/vnd.apple.keynote")
    << QStringLiteral("application/x-iwork-pages-sffpages")
    << QStringLiteral("application/x-iwork-numbers-sffnumbers")
    << QStringLiteral("application/x-iwork-keynote-sffkey")
;
// Limits.thrift

const QSet<QString> EDAM_INDEXABLE_PLAINTEXT_MIME_TYPES = QSet<QString>()
    << QStringLiteral("application/x-sh")
    << QStringLiteral("application/x-bsh")
    << QStringLiteral("application/sql")
    << QStringLiteral("application/x-sql")
;
// Limits.thrift

const qint32 EDAM_SEARCH_QUERY_LEN_MIN = 0;
// Limits.thrift

const qint32 EDAM_SEARCH_QUERY_LEN_MAX = 1024;
// Limits.thrift

const QString EDAM_SEARCH_QUERY_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Zl}\\p{Zp}]{0,1024}$");
// Limits.thrift

const qint32 EDAM_HASH_LEN = 16;
// Limits.thrift

const qint32 EDAM_USER_USERNAME_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_USER_USERNAME_LEN_MAX = 64;
// Limits.thrift

const QString EDAM_USER_USERNAME_REGEX = QStringLiteral("^[a-z0-9]([a-z0-9_-]{0,62}[a-z0-9])?$");
// Limits.thrift

const qint32 EDAM_USER_NAME_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_USER_NAME_LEN_MAX = 255;
// Limits.thrift

const QString EDAM_USER_NAME_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Zl}\\p{Zp}]{1,255}$");
// Limits.thrift

const qint32 EDAM_TAG_NAME_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_TAG_NAME_LEN_MAX = 100;
// Limits.thrift

const QString EDAM_TAG_NAME_REGEX = QStringLiteral("^[^,\\p{Cc}\\p{Z}]([^,\\p{Cc}\\p{Zl}\\p{Zp}]{0,98}[^,\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_NOTE_TITLE_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_NOTE_TITLE_LEN_MAX = 255;
// Limits.thrift

const QString EDAM_NOTE_TITLE_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,253}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_NOTE_CONTENT_LEN_MIN = 0;
// Limits.thrift

const qint32 EDAM_NOTE_CONTENT_LEN_MAX = 5242880;
// Limits.thrift

const qint32 EDAM_APPLICATIONDATA_NAME_LEN_MIN = 3;
// Limits.thrift

const qint32 EDAM_APPLICATIONDATA_NAME_LEN_MAX = 32;
// Limits.thrift

const qint32 EDAM_APPLICATIONDATA_VALUE_LEN_MIN = 0;
// Limits.thrift

const qint32 EDAM_APPLICATIONDATA_VALUE_LEN_MAX = 4092;
// Limits.thrift

const qint32 EDAM_APPLICATIONDATA_ENTRY_LEN_MAX = 4095;
// Limits.thrift

const QString EDAM_APPLICATIONDATA_NAME_REGEX = QStringLiteral("^[A-Za-z0-9_.-]{3,32}$");
// Limits.thrift

const QString EDAM_APPLICATIONDATA_VALUE_REGEX = QStringLiteral("^[\\p{Space}[^\\p{Cc}]]{0,4092}$");
// Limits.thrift

const qint32 EDAM_NOTEBOOK_NAME_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_NOTEBOOK_NAME_LEN_MAX = 100;
// Limits.thrift

const QString EDAM_NOTEBOOK_NAME_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,98}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_NOTEBOOK_STACK_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_NOTEBOOK_STACK_LEN_MAX = 100;
// Limits.thrift

const QString EDAM_NOTEBOOK_STACK_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,98}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_WORKSPACE_NAME_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_WORKSPACE_NAME_LEN_MAX = 100;
// Limits.thrift

const qint32 EDAM_WORKSPACE_DESCRIPTION_LEN_MAX = 600;
// Limits.thrift

const QString EDAM_WORKSPACE_NAME_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,98}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_PUBLISHING_URI_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_PUBLISHING_URI_LEN_MAX = 255;
// Limits.thrift

const QString EDAM_PUBLISHING_URI_REGEX = QStringLiteral("^[a-zA-Z0-9.~_+-]{1,255}$");
// Limits.thrift

const QSet<QString> EDAM_PUBLISHING_URI_PROHIBITED = QSet<QString>()
    << QStringLiteral(".")
    << QStringLiteral("..")
;
// Limits.thrift

const qint32 EDAM_PUBLISHING_DESCRIPTION_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_PUBLISHING_DESCRIPTION_LEN_MAX = 200;
// Limits.thrift

const QString EDAM_PUBLISHING_DESCRIPTION_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,198}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_SAVED_SEARCH_NAME_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_SAVED_SEARCH_NAME_LEN_MAX = 100;
// Limits.thrift

const QString EDAM_SAVED_SEARCH_NAME_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,98}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_USER_PASSWORD_LEN_MIN = 6;
// Limits.thrift

const qint32 EDAM_USER_PASSWORD_LEN_MAX = 64;
// Limits.thrift

const QString EDAM_USER_PASSWORD_REGEX = QStringLiteral("^[A-Za-z0-9!#$%&'()*+,./:;<=>?@^_`{|}~\\[\\]\\\\-]{6,64}$");
// Limits.thrift

const qint32 EDAM_BUSINESS_URI_LEN_MAX = 32;
// Limits.thrift

const QString EDAM_BUSINESS_MARKETING_CODE_REGEX_PATTERN = QStringLiteral("[A-Za-z0-9-]{1,128}");
// Limits.thrift

const qint32 EDAM_NOTE_TAGS_MAX = 100;
// Limits.thrift

const qint32 EDAM_NOTE_RESOURCES_MAX = 1000;
// Limits.thrift

const qint32 EDAM_USER_TAGS_MAX = 100000;
// Limits.thrift

const qint32 EDAM_BUSINESS_TAGS_MAX = 100000;
// Limits.thrift

const qint32 EDAM_USER_SAVED_SEARCHES_MAX = 100;
// Limits.thrift

const qint32 EDAM_USER_NOTES_MAX = 100000;
// Limits.thrift

const qint32 EDAM_BUSINESS_NOTES_MAX = 500000;
// Limits.thrift

const qint32 EDAM_USER_NOTEBOOKS_MAX = 250;
// Limits.thrift

const qint32 EDAM_USER_WORKSPACES_MAX = 0;
// Limits.thrift

const qint32 EDAM_BUSINESS_NOTEBOOKS_MAX = 10000;
// Limits.thrift

const qint32 EDAM_BUSINESS_WORKSPACES_MAX = 1000;
// Limits.thrift

const qint32 EDAM_USER_RECENT_MAILED_ADDRESSES_MAX = 10;
// Limits.thrift

const qint32 EDAM_USER_MAIL_LIMIT_DAILY_FREE = 50;
// Limits.thrift

const qint32 EDAM_USER_MAIL_LIMIT_DAILY_PREMIUM = 200;
// Limits.thrift

const qint64 EDAM_USER_UPLOAD_LIMIT_FREE = 62914560;
// Limits.thrift

const qint64 EDAM_USER_UPLOAD_LIMIT_PREMIUM = 10737418240;
// Limits.thrift

const qint64 EDAM_USER_UPLOAD_LIMIT_BUSINESS_FIRST_MONTH = 53687091200;
// Limits.thrift

const qint64 EDAM_USER_UPLOAD_LIMIT_BUSINESS_NEXT_MONTH = 21474836480;
// Limits.thrift

const qint64 EDAM_USER_UPLOAD_LIMIT_PLUS = 1073741824;
// Limits.thrift

const qint64 EDAM_USER_UPLOAD_SURVEY_THRESHOLD = 5368709120;
// Limits.thrift

const qint64 EDAM_USER_UPLOAD_LIMIT_BUSINESS = 10737418240;
// Limits.thrift

const qint64 EDAM_USER_UPLOAD_LIMIT_BUSINESS_PER_USER = 2147483647;
// Limits.thrift

const qint32 EDAM_NOTE_SIZE_MAX_FREE = 26214400;
// Limits.thrift

const qint32 EDAM_NOTE_SIZE_MAX_PREMIUM = 209715200;
// Limits.thrift

const qint32 EDAM_RESOURCE_SIZE_MAX_FREE = 26214400;
// Limits.thrift

const qint32 EDAM_RESOURCE_SIZE_MAX_PREMIUM = 209715200;
// Limits.thrift

const qint32 EDAM_USER_LINKED_NOTEBOOK_MAX = 100;
// Limits.thrift

const qint32 EDAM_USER_LINKED_NOTEBOOK_MAX_PREMIUM = 500;
// Limits.thrift

const qint32 EDAM_NOTEBOOK_BUSINESS_SHARED_NOTEBOOK_MAX = 5000;
// Limits.thrift

const qint32 EDAM_NOTEBOOK_PERSONAL_SHARED_NOTEBOOK_MAX = 500;
// Limits.thrift

const qint32 EDAM_NOTE_BUSINESS_SHARED_NOTE_MAX = 1000;
// Limits.thrift

const qint32 EDAM_NOTE_PERSONAL_SHARED_NOTE_MAX = 100;
// Limits.thrift

const qint32 EDAM_NOTE_CONTENT_CLASS_LEN_MIN = 3;
// Limits.thrift

const qint32 EDAM_NOTE_CONTENT_CLASS_LEN_MAX = 32;
// Limits.thrift

const QString EDAM_NOTE_CONTENT_CLASS_REGEX = QStringLiteral("^[A-Za-z0-9_.-]{3,32}$");
// Limits.thrift

const QString EDAM_HELLO_APP_CONTENT_CLASS_PREFIX = QStringLiteral("evernote.hello.");
// Limits.thrift

const QString EDAM_FOOD_APP_CONTENT_CLASS_PREFIX = QStringLiteral("evernote.food.");
// Limits.thrift

const QString EDAM_CONTENT_CLASS_HELLO_ENCOUNTER = QStringLiteral("evernote.hello.encounter");
// Limits.thrift

const QString EDAM_CONTENT_CLASS_HELLO_PROFILE = QStringLiteral("evernote.hello.profile");
// Limits.thrift

const QString EDAM_CONTENT_CLASS_FOOD_MEAL = QStringLiteral("evernote.food.meal");
// Limits.thrift

const QString EDAM_CONTENT_CLASS_SKITCH_PREFIX = QStringLiteral("evernote.skitch");
// Limits.thrift

const QString EDAM_CONTENT_CLASS_SKITCH = QStringLiteral("evernote.skitch");
// Limits.thrift

const QString EDAM_CONTENT_CLASS_SKITCH_PDF = QStringLiteral("evernote.skitch.pdf");
// Limits.thrift

const QString EDAM_CONTENT_CLASS_PENULTIMATE_PREFIX = QStringLiteral("evernote.penultimate.");
// Limits.thrift

const QString EDAM_CONTENT_CLASS_PENULTIMATE_NOTEBOOK = QStringLiteral("evernote.penultimate.notebook");
// Limits.thrift

const QString EDAM_SOURCE_APPLICATION_POSTIT = QStringLiteral("postit");
// Limits.thrift

const QString EDAM_SOURCE_APPLICATION_MOLESKINE = QStringLiteral("moleskine");
// Limits.thrift

const QString EDAM_SOURCE_APPLICATION_EN_SCANSNAP = QStringLiteral("scanner.scansnap.evernote");
// Limits.thrift

const QString EDAM_SOURCE_APPLICATION_EWC = QStringLiteral("clipncite.web");
// Limits.thrift

const QString EDAM_SOURCE_APPLICATION_ANDROID_SHARE_EXTENSION = QStringLiteral("android.clipper.evernote");
// Limits.thrift

const QString EDAM_SOURCE_APPLICATION_IOS_SHARE_EXTENSION = QStringLiteral("ios.clipper.evernote");
// Limits.thrift

const QString EDAM_SOURCE_APPLICATION_WEB_CLIPPER = QStringLiteral("webclipper.evernote");
// Limits.thrift

const QString EDAM_SOURCE_OUTLOOK_CLIPPER = QStringLiteral("app.ms.outlook");
// Limits.thrift

const qint32 EDAM_NOTE_TITLE_QUALITY_UNTITLED = 0;
// Limits.thrift

const qint32 EDAM_NOTE_TITLE_QUALITY_LOW = 1;
// Limits.thrift

const qint32 EDAM_NOTE_TITLE_QUALITY_MEDIUM = 2;
// Limits.thrift

const qint32 EDAM_NOTE_TITLE_QUALITY_HIGH = 3;
// Limits.thrift

const qint32 EDAM_RELATED_PLAINTEXT_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_RELATED_PLAINTEXT_LEN_MAX = 131072;
// Limits.thrift

const qint32 EDAM_RELATED_MAX_NOTES = 25;
// Limits.thrift

const qint32 EDAM_RELATED_MAX_NOTEBOOKS = 1;
// Limits.thrift

const qint32 EDAM_RELATED_MAX_TAGS = 25;
// Limits.thrift

const qint32 EDAM_RELATED_MAX_EXPERTS = 10;
// Limits.thrift

const qint32 EDAM_RELATED_MAX_RELATED_CONTENT = 10;
// Limits.thrift

const qint32 EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_LEN_MAX = 200;
// Limits.thrift

const QString EDAM_BUSINESS_NOTEBOOK_DESCRIPTION_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,198}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_BUSINESS_PHONE_NUMBER_LEN_MAX = 20;
// Limits.thrift

const qint32 EDAM_PREFERENCE_NAME_LEN_MIN = 3;
// Limits.thrift

const qint32 EDAM_PREFERENCE_NAME_LEN_MAX = 32;
// Limits.thrift

const qint32 EDAM_PREFERENCE_VALUE_LEN_MIN = 1;
// Limits.thrift

const qint32 EDAM_PREFERENCE_VALUE_LEN_MAX = 1024;
// Limits.thrift

const qint32 EDAM_MAX_PREFERENCES = 100;
// Limits.thrift

const qint32 EDAM_MAX_VALUES_PER_PREFERENCE = 256;
// Limits.thrift

const qint32 EDAM_PREFERENCE_ONLY_ONE_VALUE_LEN_MAX = 16384;
// Limits.thrift

const QString EDAM_PREFERENCE_NAME_REGEX = QStringLiteral("^[A-Za-z0-9_.-]{3,32}$");
// Limits.thrift

const QString EDAM_PREFERENCE_VALUE_REGEX = QStringLiteral("^[^\\p{Cc}]{1,1024}$");
// Limits.thrift

const QString EDAM_PREFERENCE_ONLY_ONE_VALUE_REGEX = QStringLiteral("^[^\\p{Cc}]{1,16384}$");
// Limits.thrift

const QString EDAM_PREFERENCE_SHORTCUTS = QStringLiteral("evernote.shortcuts");
// Limits.thrift

const QString EDAM_PREFERENCE_BUSINESS_DEFAULT_NOTEBOOK = QStringLiteral("evernote.business.notebook");
// Limits.thrift

const QString EDAM_PREFERENCE_BUSINESS_QUICKNOTE = QStringLiteral("evernote.business.quicknote");
// Limits.thrift

const qint32 EDAM_PREFERENCE_SHORTCUTS_MAX_VALUES = 250;
// Limits.thrift

const qint32 EDAM_DEVICE_ID_LEN_MAX = 32;
// Limits.thrift

const QString EDAM_DEVICE_ID_REGEX = QStringLiteral("^[^\\p{Cc}]{1,32}$");
// Limits.thrift

const qint32 EDAM_DEVICE_DESCRIPTION_LEN_MAX = 64;
// Limits.thrift

const QString EDAM_DEVICE_DESCRIPTION_REGEX = QStringLiteral("^[^\\p{Cc}]{1,64}$");
// Limits.thrift

const qint32 EDAM_SEARCH_SUGGESTIONS_MAX = 10;
// Limits.thrift

const qint32 EDAM_SEARCH_SUGGESTIONS_PREFIX_LEN_MAX = 1024;
// Limits.thrift

const qint32 EDAM_SEARCH_SUGGESTIONS_PREFIX_LEN_MIN = 2;
// Limits.thrift

const qint32 EDAM_FIND_CONTACT_DEFAULT_MAX_RESULTS = 100;
// Limits.thrift

const qint32 EDAM_FIND_CONTACT_MAX_RESULTS = 256;
// Limits.thrift

const qint32 EDAM_NOTE_LOCK_VIEWERS_NOTES_MAX = 150;
// Limits.thrift

const qint32 EDAM_GET_ORDERS_MAX_RESULTS = 2000;
// Limits.thrift

const qint32 EDAM_MESSAGE_BODY_LEN_MAX = 2048;
// Limits.thrift

const QString EDAM_MESSAGE_BODY_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,2046}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_MESSAGE_RECIPIENTS_MAX = 50;
// Limits.thrift

const qint32 EDAM_MESSAGE_ATTACHMENTS_MAX = 100;
// Limits.thrift

const qint32 EDAM_MESSAGE_ATTACHMENT_TITLE_LEN_MAX = 255;
// Limits.thrift

const QString EDAM_MESSAGE_ATTACHMENT_TITLE_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([^\\p{Cc}\\p{Zl}\\p{Zp}]{0,253}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_MESSAGE_ATTACHMENT_SNIPPET_LEN_MAX = 2048;
// Limits.thrift

const QString EDAM_MESSAGE_ATTACHMENT_SNIPPET_REGEX = QStringLiteral("^[^\\p{Cc}\\p{Z}]([\\n[^\\p{Cc}\\p{Zl}\\p{Zp}]]{0,2046}[^\\p{Cc}\\p{Z}])?$");
// Limits.thrift

const qint32 EDAM_USER_PROFILE_PHOTO_MAX_BYTES = 716800;
// Limits.thrift

const qint32 EDAM_PROMOTION_ID_LEN_MAX = 32;
// Limits.thrift

const QString EDAM_PROMOTION_ID_REGEX = QStringLiteral("^[A-Za-z0-9_.-]{1,32}$");
// Limits.thrift

const qint16 EDAM_APP_RATING_MIN = 1;
// Limits.thrift

const qint16 EDAM_APP_RATING_MAX = 5;
// Limits.thrift

const qint32 EDAM_SNIPPETS_NOTES_MAX = 24;
// Limits.thrift

const qint32 EDAM_CONNECTED_IDENTITY_REQUEST_MAX = 100;
// Limits.thrift

const qint32 EDAM_OPEN_ID_ACCESS_TOKEN_MAX = 1000;
// Types.thrift

const QString CLASSIFICATION_RECIPE_USER_NON_RECIPE = QStringLiteral("000");
// Types.thrift

const QString CLASSIFICATION_RECIPE_USER_RECIPE = QStringLiteral("001");
// Types.thrift

const QString CLASSIFICATION_RECIPE_SERVICE_RECIPE = QStringLiteral("002");
// Types.thrift

const QString EDAM_NOTE_SOURCE_WEB_CLIP = QStringLiteral("web.clip");
// Types.thrift

const QString EDAM_NOTE_SOURCE_WEB_CLIP_SIMPLIFIED = QStringLiteral("Clearly");
// Types.thrift

const QString EDAM_NOTE_SOURCE_MAIL_CLIP = QStringLiteral("mail.clip");
// Types.thrift

const QString EDAM_NOTE_SOURCE_MAIL_SMTP_GATEWAY = QStringLiteral("mail.smtp");
// UserStore.thrift

const qint16 EDAM_VERSION_MAJOR = 1;
// UserStore.thrift

const qint16 EDAM_VERSION_MINOR = 28;

} // namespace qevercloud
