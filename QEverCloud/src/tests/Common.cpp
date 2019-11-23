/**
 * Copyright (c) 2019 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 */

#include "Common.h"

#include <QCryptographicHash>
#include <QDateTime>
#include <QEventLoop>
#include <QObject>

#include <algorithm>
#include <cstdlib>
#include <limits>

namespace qevercloud {
namespace tests {

namespace {

////////////////////////////////////////////////////////////////////////////////

static const QString randomStringAvailableCharacters = QStringLiteral(
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

template <typename T>
T generateRandomIntType()
{
    return static_cast<T>(rand() % std::numeric_limits<T>::max());
}

} // namespace

////////////////////////////////////////////////////////////////////////////////

class ThriftRequestExtractor: public QObject
{
    Q_OBJECT
public:
    explicit ThriftRequestExtractor(QTcpSocket & socket, QObject * parent = nullptr) :
        QObject(parent)
    {
        QObject::connect(
            &socket,
            &QIODevice::readyRead,
            this,
            &ThriftRequestExtractor::onSocketReadyRead,
            Qt::QueuedConnection);
    }

    bool status() const { return m_status; }

    const QByteArray & data() { return m_data; }

Q_SIGNALS:
    void finished();
    void failed();

private Q_SLOTS:
    void onSocketReadyRead()
    {
        QTcpSocket * pSocket = qobject_cast<QTcpSocket*>(sender());
        Q_ASSERT(pSocket);

        m_data.append(pSocket->read(pSocket->bytesAvailable()));
        tryParseData();
    }

private:
    void tryParseData()
    {
        // Data read from socket should be a http request with headers and body

        // First parse headers, find Content-Length one to figure out the size
        // of request body
        int contentLengthIndex = m_data.indexOf("Content-Length:");
        if (contentLengthIndex < 0) {
            // No Content-Length header, probably not all data has arrived yet
            return;
        }

        int contentLengthLineEndIndex = m_data.indexOf("\r\n", contentLengthIndex);
        if (contentLengthLineEndIndex < 0) {
            // No line end after Content-Length header, probably not all data
            // has arrived yet
            return;
        }

        int contentLengthLen = contentLengthLineEndIndex - contentLengthIndex - 15;
        QString contentLengthStr =
            QString::fromUtf8(m_data.mid(contentLengthIndex + 15, contentLengthLen));

        bool conversionResult = false;
        int contentLength = contentLengthStr.toInt(&conversionResult);
        if (Q_UNLIKELY(!conversionResult)) {
            m_status = false;
            Q_EMIT failed();
            return;
        }

        // Now see whether whole body data is present
        int headersEndIndex = m_data.indexOf("\r\n\r\n", contentLengthLineEndIndex);
        if (headersEndIndex < 0) {
            // No empty line after http headers, probably not all data has
            // arrived yet
            return;
        }

        QByteArray body = m_data;
        body.remove(0, headersEndIndex + 4);
        if (body.size() < contentLength) {
            // Not all data has arrived yet
            return;
        }

        m_data = body;
        m_status = true;
        Q_EMIT finished();
    }

private:
    bool            m_status = false;
    QByteArray      m_data;
};

////////////////////////////////////////////////////////////////////////////////

QByteArray readThriftRequestFromSocket(QTcpSocket & socket)
{
    if (!socket.waitForConnected()) {
        return QByteArray();
    }

    QEventLoop loop;
    ThriftRequestExtractor extractor(socket);

    QObject::connect(
        &extractor,
        &ThriftRequestExtractor::finished,
        &loop,
        &QEventLoop::quit);

    QObject::connect(
        &extractor,
        &ThriftRequestExtractor::failed,
        &loop,
        &QEventLoop::quit);

    loop.exec();

    if (!extractor.status()) {
        return QByteArray();
    }

    return extractor.data();
}

bool writeBufferToSocket(const QByteArray & data, QTcpSocket & socket)
{
    int remaining = data.size();
    const char * pData = data.constData();
    while(socket.isOpen() && remaining>0)
    {
        // If the output buffer has become large, then wait until it has been sent.
        if (socket.bytesToWrite() > 16384)
        {
            socket.waitForBytesWritten(-1);
        }

        qint64 written = socket.write(pData, remaining);
        if (written < 0) {
            return false;
        }

        pData += written;
        remaining -= written;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////

QString generateRandomString(int len)
{
    if (len <= 0) {
        return {};
    }

    QString res;
    res.reserve(len);
    for(int i = 0; i < len; ++i) {
        int index = rand() % randomStringAvailableCharacters.length();
        res.append(randomStringAvailableCharacters.at(index));
    }

    return res;
}

qint8 generateRandomInt8()
{
    return generateRandomIntType<qint8>();
}

qint16 generateRandomInt16()
{
    return generateRandomIntType<qint16>();
}

qint32 generateRandomInt32()
{
    return generateRandomIntType<qint32>();
}

qint64 generateRandomInt64()
{
    return generateRandomIntType<qint64>();
}

quint8 generateRandomUint8()
{
    return generateRandomIntType<quint8>();
}

quint16 generateRandomUint16()
{
    return generateRandomIntType<quint16>();
}

quint32 generateRandomUint32()
{
    return generateRandomIntType<quint32>();
}

quint64 generateRandomUint64()
{
    return generateRandomIntType<quint64>();
}

double generateRandomDouble()
{
    double minval = std::numeric_limits<double>::min();
    double maxval = std::numeric_limits<double>::max();
    double f = (double)rand() / RAND_MAX;
    return minval + f * (maxval - minval);
}

////////////////////////////////////////////////////////////////////////////////

QByteArray extractBodyFromHttpRequest(QByteArray requestData)
{
    int index = requestData.indexOf("\r\n\r\n");
    if (index < 0) {
        return {};
    }

    requestData.remove(0, index + 4);
    return requestData;
}

////////////////////////////////////////////////////////////////////////////////

SyncState generateSyncState()
{
    SyncState state;
    state.currentTime = QDateTime::currentMSecsSinceEpoch();
    state.fullSyncBefore = state.currentTime + 100000;
    state.updateCount = 10;
    state.uploaded = 20000;
    state.userLastUpdated = state.currentTime - 20;
    state.userMaxMessageEventId = 50000;

    return state;
}

SyncChunkFilter generateSyncChunkFilter()
{
    SyncChunkFilter filter;
    filter.includeNotes = true;
    filter.includeNoteResources = false;
    filter.includeNoteAttributes = true;
    filter.includeNotebooks = false;
    filter.includeTags = true;
    filter.includeSearches = false;
    filter.includeResources = true;
    filter.includeLinkedNotebooks = false;
    filter.includeExpunged = true;
    filter.includeNoteApplicationDataFullMap = false;
    filter.includeResourceApplicationDataFullMap = true;
    filter.includeNoteResourceApplicationDataFullMap = false;
    filter.includeSharedNotes = true;
    filter.omitSharedNotebooks = false;
    filter.requireNoteContentClass = true;
    filter.notebookGuids = QSet<QString>() << QStringLiteral("guid1")
        << QStringLiteral("guid2") << QStringLiteral("guid3");

    return filter;
}

NoteFilter generateNoteFilter()
{
    NoteFilter filter;
    filter.order = 5;
    filter.ascending = false;
    filter.words = QStringLiteral("words");
    filter.notebookGuid = QStringLiteral("notebookGuid");
    filter.tagGuids = QList<QString>() << QStringLiteral("tagGuid1")
        << QStringLiteral("tagGuid2") << QStringLiteral("tagGuid3");
    filter.timeZone = QStringLiteral("America/Los_Angeles");
    filter.inactive = false;
    filter.emphasized = QStringLiteral("emphasized");
    filter.includeAllReadableNotebooks = true;
    filter.includeAllReadableWorkspaces = false;
    filter.context = QStringLiteral("context");
    filter.rawWords = QStringLiteral("rawWords");
    filter.searchContextBytes = QStringLiteral("searchContextBytes").toUtf8();

    return filter;
}

NotesMetadataResultSpec generateNotesMetadataResultSpec()
{
    NotesMetadataResultSpec spec;
    spec.includeTitle = true;
    spec.includeContentLength = false;
    spec.includeCreated = true;
    spec.includeUpdated = false;
    spec.includeDeleted = true;
    spec.includeUpdateSequenceNum = false;
    spec.includeNotebookGuid = true;
    spec.includeTagGuids = false;
    spec.includeAttributes = true;
    spec.includeLargestResourceMime = false;
    spec.includeLargestResourceSize = true;

    return spec;
}

NoteCollectionCounts generateNoteCollectionCounts()
{
    NoteCollectionCounts counts;

    QMap<Guid, qint32> notebookCounts;
    notebookCounts[QStringLiteral("notebookGuid1")] = 2;
    notebookCounts[QStringLiteral("notebookGuid2")] = 3;
    notebookCounts[QStringLiteral("notebookGuid3")] = 4;
    counts.notebookCounts = notebookCounts;

    QMap<Guid, qint32> tagCounts;
    tagCounts[QStringLiteral("tagGuid1")] = 2;
    tagCounts[QStringLiteral("tagGuid2")] = 3;
    tagCounts[QStringLiteral("tagGuid3")] = 4;
    counts.tagCounts = tagCounts;

    counts.trashCount = 15;

    return counts;
}

NoteResultSpec generateNoteResultSpec()
{
    NoteResultSpec spec;
    spec.includeContent = true;
    spec.includeResourcesData = false;
    spec.includeResourcesRecognition = true;
    spec.includeResourcesAlternateData = false;
    spec.includeSharedNotes = true;
    spec.includeNoteAppDataValues = false;
    spec.includeResourceAppDataValues = true;
    spec.includeAccountLimits = false;

    return spec;
}

NoteVersionId generateNoteVersionId()
{
    NoteVersionId id;
    id.updateSequenceNum = 95;
    id.updated = QDateTime::currentMSecsSinceEpoch();
    id.saved = id.updated - 100;
    id.title = QStringLiteral("title");
    id.lastEditorId = 72;

    return id;
}

RelatedQuery generateRelatedQuery()
{
    RelatedQuery query;
    query.noteGuid = QStringLiteral("noteGuid");
    query.plainText = QStringLiteral("plainText");
    query.filter = generateNoteFilter();
    query.referenceUri = QStringLiteral("referenceUri");
    query.context = QStringLiteral("context");
    query.cacheKey = QStringLiteral("cacheKey");

    return query;
}

RelatedResultSpec generateRelatedResultSpec()
{
    RelatedResultSpec spec;
    spec.maxNotes = 30;
    spec.maxNotebooks = 10;
    spec.maxTags = 20;
    spec.writableNotebooksOnly = false;
    spec.includeContainingNotebooks = true;
    spec.includeDebugInfo = false;
    spec.maxExperts = 5;
    spec.maxRelatedContent = 3;
    spec.relatedContentTypes = QSet<RelatedContentType>()
        << RelatedContentType::NEWS_ARTICLE
        << RelatedContentType::PROFILE_ORGANIZATION
        << RelatedContentType::PROFILE_PERSON;

    return spec;
}

ShareRelationshipRestrictions generateShareRelationshipRestrictions()
{
    ShareRelationshipRestrictions r;
    r.noSetReadOnly = false;
    r.noSetReadPlusActivity = true;
    r.noSetModify = false;
    r.noSetFullAccess = true;

    return r;
}

MemberShareRelationship generateMemberShareRelationship()
{
    MemberShareRelationship r;
    r.displayName = QStringLiteral("displayName");
    r.recipientUserId = 5;
    r.bestPrivilege = ShareRelationshipPrivilegeLevel::FULL_ACCESS;
    r.individualPrivilege = ShareRelationshipPrivilegeLevel::READ_NOTEBOOK;
    r.restrictions = generateShareRelationshipRestrictions();
    r.sharerUserId = 10;

    return r;
}

NoteShareRelationshipRestrictions generateNoteShareRelationshipRestrictions()
{
    NoteShareRelationshipRestrictions r;
    r.noSetReadNote = false;
    r.noSetModifyNote = true;
    r.noSetFullAccess = false;

    return r;
}

NoteMemberShareRelationship generateNoteMemberShareRelationship()
{
    NoteMemberShareRelationship r;
    r.displayName = QStringLiteral("displayName");
    r.recipientUserId = 7;
    r.privilege = SharedNotePrivilegeLevel::READ_NOTE;
    r.restrictions = generateNoteShareRelationshipRestrictions();
    r.sharerUserId = 19;

    return r;
}

NoteInvitationShareRelationship generateNoteInvitationShareRelationship()
{
    NoteInvitationShareRelationship r;
    r.displayName = QStringLiteral("displayName");
    r.recipientIdentityId = 124;
    r.privilege = SharedNotePrivilegeLevel::FULL_ACCESS;
    r.sharerUserId = 231;

    return r;
}

NoteShareRelationships generateNoteShareRelationships()
{
    NoteShareRelationships r;
    r.invitations = QList<NoteInvitationShareRelationship>()
        << generateNoteInvitationShareRelationship();
    r.memberships = QList<NoteMemberShareRelationship>()
        << generateNoteMemberShareRelationship();
    r.invitationRestrictions = generateNoteShareRelationshipRestrictions();

    return r;
}

ManageNoteSharesParameters generateManageNoteSharesParameters()
{
    ManageNoteSharesParameters p;
    p.noteGuid = QStringLiteral("noteGuid");
    p.membershipsToUpdate = QList<NoteMemberShareRelationship>()
        << generateNoteMemberShareRelationship();
    p.invitationsToUpdate = QList<NoteInvitationShareRelationship>()
        << generateNoteInvitationShareRelationship();
    p.membershipsToUnshare = QList<UserID>() << 27 << 81 << 32;
    p.invitationsToUnshare = QList<IdentityID>() << 22 << 46 << 73;

    return p;
}

Data generateData()
{
    Data data;
    data.body = QString(QStringLiteral("data body ") + QString::number(rand() % 101)).toUtf8();
    data.size = data.body->size();
    data.bodyHash = QCryptographicHash::hash(data.body.ref(), QCryptographicHash::Md5);

    return data;
}

UserAttributes generateUserAttributes()
{
    UserAttributes a;
    a.defaultLocationName = QStringLiteral("defaultLocationName");
    a.defaultLatitude = 0.1;
    a.defaultLongitude = 0.2;
    a.preactivation = false;
    a.viewedPromotions = QStringList()
        << QStringLiteral("viewedPromotion1")
        << QStringLiteral("viewedPromotion2")
        << QStringLiteral("viewedPromotion3");
    a.incomingEmailAddress = QStringLiteral("incomingEmailAddress");
    a.recentMailedAddresses = QStringList()
        << QStringLiteral("recentMailedAddress1")
        << QStringLiteral("recentMailedAddress2")
        << QStringLiteral("recentMailedAddress3");
    a.comments = QStringLiteral("comments");
    a.dateAgreedToTermsOfService = QDateTime::currentMSecsSinceEpoch();
    a.maxReferrals = 11;
    a.referralCount = 9;
    a.refererCode = QStringLiteral("refererCode");
    a.sentEmailDate = QDateTime::currentMSecsSinceEpoch();
    a.sentEmailCount = 8;
    a.dailyEmailLimit = 22;
    a.emailOptOutDate = QDateTime::currentMSecsSinceEpoch();
    a.partnerEmailOptInDate = QDateTime::currentMSecsSinceEpoch();
    a.preferredLanguage = QStringLiteral("en");
    a.preferredCountry = QStringLiteral("US");
    a.clipFullPage = false;
    a.twitterUserName = QStringLiteral("twitterUserName");
    a.twitterId = QStringLiteral("twitterId");
    a.groupName = QStringLiteral("groupName");
    a.recognitionLanguage = QStringLiteral("ru");
    a.referralProof = QStringLiteral("referralProof");
    a.educationalDiscount = false;
    a.businessAddress = QStringLiteral("businessAddress");
    a.hideSponsorBilling = true;
    a.useEmailAutoFiling = false;
    a.reminderEmailConfig = ReminderEmailConfig::DO_NOT_SEND;
    a.passwordUpdated = QDateTime::currentMSecsSinceEpoch();
    a.salesforcePushEnabled = false;
    a.shouldLogClientEvent = true;
    a.optOutMachineLearning = false;

    return a;
}

BusinessUserAttributes generateBusinessUserAttributes()
{
    BusinessUserAttributes a;
    a.title = QStringLiteral("title");
    a.location = QStringLiteral("location");
    a.department = QStringLiteral("department");
    a.mobilePhone = QStringLiteral("mobilePhone");
    a.linkedInProfileUrl = QStringLiteral("linkedInProfileUrl");
    a.workPhone = QStringLiteral("workPhone");
    a.companyStartDate = QDateTime::currentMSecsSinceEpoch();

    return a;
}

Accounting generateAccounting()
{
    Accounting a;
    a.uploadLimitEnd = QDateTime::currentMSecsSinceEpoch() + 10000;
    a.uploadLimitNextMonth = 700;
    a.premiumServiceStatus = PremiumOrderStatus::PENDING;
    a.premiumOrderNumber = QStringLiteral("premiumOrderNumber");
    a.premiumCommerceService = QStringLiteral("premiumCommerceService");
    a.premiumServiceStart = QDateTime::currentMSecsSinceEpoch();
    a.premiumServiceSKU = QStringLiteral("premiumServiceSKU");
    a.lastSuccessfulCharge = QDateTime::currentMSecsSinceEpoch();
    a.lastFailedCharge = QDateTime::currentMSecsSinceEpoch();
    a.lastFailedChargeReason = QStringLiteral("lastFailedChargeReason");
    a.nextPaymentDue = QDateTime::currentMSecsSinceEpoch() + 200;
    a.premiumLockUntil = QDateTime::currentMSecsSinceEpoch() + 100;
    a.updated = QDateTime::currentMSecsSinceEpoch() + 50;
    a.premiumSubscriptionNumber = QStringLiteral("premiumSubscriptionNumber");
    a.lastRequestedCharge = QDateTime::currentMSecsSinceEpoch() - 50;
    a.currency = QStringLiteral("currency");
    a.unitPrice = 19;
    a.businessId = 21;
    a.businessName = QStringLiteral("businessName");
    a.businessRole = BusinessUserRole::NORMAL;
    a.unitDiscount = 14;
    a.nextChargeDate = QDateTime::currentMSecsSinceEpoch() + 400;
    a.availablePoints = 11;

    return a;
}

BusinessUserInfo generateBusinessUserInfo()
{
    BusinessUserInfo info;
    info.businessId = 13;
    info.businessName = QStringLiteral("businessName");
    info.role = BusinessUserRole::NORMAL;
    info.email = QStringLiteral("email");
    info.updated = QDateTime::currentMSecsSinceEpoch();

    return info;
}

AccountLimits generateAccountLimits()
{
    AccountLimits limits;
    limits.userMailLimitDaily = 9;
    limits.noteSizeMax = 300;
    limits.resourceSizeMax = 200;
    limits.userLinkedNotebookMax = 30;
    limits.uploadLimit = 500;
    limits.userNoteCountMax = 40;
    limits.userNotebookCountMax = 35;
    limits.userTagCountMax = 45;
    limits.noteTagCountMax = 20;
    limits.userSavedSearchesMax = 50;
    limits.noteResourceCountMax = 60;

    return limits;
}

User generateUser()
{
    User user;
    user.id = 19;
    user.username = QStringLiteral("username");
    user.email = QStringLiteral("email");
    user.name = QStringLiteral("name");
    user.timezone = QStringLiteral("America/Los_Angeles");
    user.privilege = PrivilegeLevel::MANAGER;
    user.serviceLevel = ServiceLevel::BASIC;
    user.created = QDateTime::currentMSecsSinceEpoch();
    user.updated = QDateTime::currentMSecsSinceEpoch();
    user.deleted = QDateTime::currentMSecsSinceEpoch();
    user.active = true;
    user.shardId = QStringLiteral("shardId");
    user.attributes = generateUserAttributes();
    user.accounting = generateAccounting();
    user.businessUserInfo = generateBusinessUserInfo();
    user.photoUrl = QStringLiteral("photoUrl");
    user.photoLastUpdated = QDateTime::currentMSecsSinceEpoch();
    user.accountLimits = generateAccountLimits();

    return user;
}

Contact generateContact()
{
    Contact contact;
    contact.name = QStringLiteral("name");
    contact.id = QStringLiteral("id");
    contact.type = ContactType::EVERNOTE;
    contact.photoUrl = QStringLiteral("photoUrl");
    contact.photoLastUpdated = QDateTime::currentMSecsSinceEpoch() - 20;
    contact.messagingPermit = QStringLiteral("messagingPermit").toUtf8();
    contact.messagingPermitExpires = QDateTime::currentMSecsSinceEpoch();

    return contact;
}

Identity generateIdentity()
{
    Identity identity;
    identity.id = 200;
    identity.contact = generateContact();
    identity.userId = 30;
    identity.deactivated = false;
    identity.sameBusiness = true;
    identity.blocked = false;
    identity.userConnected = true;
    identity.eventId = 341;

    return identity;
}

Tag generateTag()
{
    Tag tag;
    tag.guid = QStringLiteral("guid");
    tag.name = QStringLiteral("name");
    tag.parentGuid = QStringLiteral("parentGuid");
    tag.updateSequenceNum = 30;

    return tag;
}

LazyMap generateLazyMap()
{
    LazyMap lazyMap;

    QSet<QString> keysOnly;
    keysOnly << QStringLiteral("key1");
    keysOnly << QStringLiteral("key2");
    keysOnly << QStringLiteral("key3");
    lazyMap.keysOnly = keysOnly;

    QMap<QString, QString> fullMap;
    fullMap[QStringLiteral("key1")] = QStringLiteral("value1");
    fullMap[QStringLiteral("key2")] = QStringLiteral("value2");
    fullMap[QStringLiteral("key3")] = QStringLiteral("value3");
    lazyMap.fullMap = fullMap;

    return lazyMap;
}

ResourceAttributes generateResourceAttributes()
{
    ResourceAttributes a;
    a.sourceURL = QStringLiteral("sourceURL");
    a.timestamp = QDateTime::currentMSecsSinceEpoch();
    a.latitude = 0.1;
    a.longitude = 0.2;
    a.altitude = 0.3;
    a.cameraMake = QStringLiteral("cameraMake");
    a.clientWillIndex = false;
    a.recoType = QStringLiteral("recoType");
    a.fileName = QStringLiteral("fileName");
    a.attachment = false;
    a.applicationData = generateLazyMap();

    return a;
}

Resource generateResource()
{
    Resource r;
    r.guid = QStringLiteral("guid");
    r.noteGuid = QStringLiteral("noteGuid");
    r.data = generateData();
    r.mime = QStringLiteral("mime");
    r.width = 23;
    r.height = 19;
    r.duration = 13;
    r.active = true;
    r.recognition = generateData();
    r.attributes = generateResourceAttributes();
    r.updateSequenceNum = 31;
    r.alternateData = generateData();

    return r;
}

NoteAttributes generateNoteAttributes()
{
    NoteAttributes a;
    a.subjectDate = QDateTime::currentMSecsSinceEpoch();
    a.latitude = 0.1;
    a.longitude = 0.2;
    a.altitude = 0.3;
    a.author = QStringLiteral("author");
    a.source = QStringLiteral("source");
    a.sourceURL = QStringLiteral("sourceURL");
    a.sourceApplication = QStringLiteral("sourceApplication");
    a.shareDate = QDateTime::currentMSecsSinceEpoch() - 20;
    a.reminderOrder = 20;
    a.reminderDoneTime = QDateTime::currentMSecsSinceEpoch() - 300;
    a.reminderTime = QDateTime::currentMSecsSinceEpoch() - 100;
    a.placeName = QStringLiteral("placeName");
    a.contentClass = QStringLiteral("contentClass");
    a.applicationData = generateLazyMap();
    a.lastEditedBy = QStringLiteral("lastEditedBy");

    QMap<QString, QString> classifications;
    classifications[QStringLiteral("key1")] = QStringLiteral("value1");
    classifications[QStringLiteral("key2")] = QStringLiteral("value2");
    classifications[QStringLiteral("key3")] = QStringLiteral("value3");
    a.classifications = classifications;

    a.creatorId = 18;
    a.lastEditorId = 16;
    a.sharedWithBusiness = false;
    a.conflictSourceNoteGuid = QStringLiteral("conflictSourceNoteGuid");
    a.noteTitleQuality = 2;

    return a;
}

SharedNote generateSharedNote()
{
    SharedNote n;
    n.sharerUserID = 19;
    n.recipientIdentity = generateIdentity();
    n.privilege = SharedNotePrivilegeLevel::MODIFY_NOTE;
    n.serviceCreated = QDateTime::currentMSecsSinceEpoch() - 20;
    n.serviceUpdated = QDateTime::currentMSecsSinceEpoch() - 10;
    n.serviceAssigned = QDateTime::currentMSecsSinceEpoch();

    return n;
}

NoteRestrictions generateNoteRestrictions()
{
    NoteRestrictions r;
    r.noUpdateTitle = true;
    r.noUpdateContent = false;
    r.noEmail = true;
    r.noShare = false;
    r.noSharePublicly = true;

    return r;
}

NoteLimits generateNoteLimits()
{
    NoteLimits limits;
    limits.noteResourceCountMax = 10;
    limits.uploadLimit = 100;
    limits.resourceSizeMax = 20;
    limits.noteSizeMax = 40;
    limits.uploaded = 50;

    return limits;
}

Note generateNote()
{
    Note note;
    note.guid = QStringLiteral("guid");
    note.title = QStringLiteral("title");
    note.content = QStringLiteral("content");
    note.contentHash = QCryptographicHash::hash(
        note.content.ref().toUtf8(),
        QCryptographicHash::Md5);
    note.contentLength = note.content->size();
    note.created = QDateTime::currentMSecsSinceEpoch() - 20;
    note.updated = QDateTime::currentMSecsSinceEpoch() - 10;
    note.deleted = QDateTime::currentMSecsSinceEpoch();
    note.active = true;
    note.updateSequenceNum = 20;
    note.notebookGuid = QStringLiteral("notebookGuid");
    note.tagGuids = QList<Guid>()
        << QStringLiteral("tagGuid1")
        << QStringLiteral("tagGuid2")
        << QStringLiteral("tagGuid3");
    note.resources = QList<Resource>()
        << generateResource();
    note.attributes = generateNoteAttributes();
    note.tagNames = QStringList()
        << QStringLiteral("tagName1")
        << QStringLiteral("tagName2")
        << QStringLiteral("tagName3");
    note.sharedNotes = QList<SharedNote>()
        << generateSharedNote();
    note.restrictions = generateNoteRestrictions();
    note.limits = generateNoteLimits();

    return note;
}

Publishing generatePublishing()
{
    Publishing p;
    p.uri = QStringLiteral("uri");
    p.order = NoteSortOrder::UPDATED;
    p.ascending = true;
    p.publicDescription = QStringLiteral("publicDescription");

    return p;
}

BusinessNotebook generateBusinessNotebook()
{
    BusinessNotebook notebook;
    notebook.notebookDescription = QStringLiteral("notebookDescription");
    notebook.privilege = SharedNotebookPrivilegeLevel::READ_NOTEBOOK;
    notebook.recommended = true;

    return notebook;
}

SavedSearchScope generateSavedSearchScope()
{
    SavedSearchScope scope;
    scope.includeAccount = true;
    scope.includePersonalLinkedNotebooks = true;
    scope.includeBusinessLinkedNotebooks = false;

    return scope;
}

SavedSearch generateSavedSearch()
{
    SavedSearch search;
    search.guid = QStringLiteral("guid");
    search.name = QStringLiteral("name");
    search.query = QStringLiteral("query");
    search.format = QueryFormat::USER;
    search.updateSequenceNum = 13;
    search.scope = generateSavedSearchScope();

    return search;
}

SharedNotebookRecipientSettings generateSharedNotebookRecipientSettings()
{
    SharedNotebookRecipientSettings s;
    s.reminderNotifyEmail = true;
    s.reminderNotifyInApp = false;

    return s;
}

NotebookRecipientSettings generateNotebookRecipientSettings()
{
    NotebookRecipientSettings s;
    s.reminderNotifyEmail = true;
    s.reminderNotifyInApp = false;
    s.inMyList = true;
    s.stack = QStringLiteral("stack");
    s.recipientStatus = RecipientStatus::IN_MY_LIST;

    return s;
}

SharedNotebook generateSharedNotebook()
{
    SharedNotebook notebook;
    notebook.id = 201;
    notebook.userId = 102;
    notebook.notebookGuid = QStringLiteral("notebookGuid");
    notebook.email = QStringLiteral("email");
    notebook.recipientIdentityId = 172;
    notebook.notebookModifiable = true;
    notebook.serviceCreated = QDateTime::currentMSecsSinceEpoch() - 200;
    notebook.serviceUpdated = QDateTime::currentMSecsSinceEpoch() - 100;
    notebook.globalId = QStringLiteral("globalId");
    notebook.username = QStringLiteral("username");
    notebook.privilege = SharedNotebookPrivilegeLevel::FULL_ACCESS;
    notebook.recipientSettings = generateSharedNotebookRecipientSettings();
    notebook.sharerUserId = 314;
    notebook.recipientUsername = QStringLiteral("recipientUsername");
    notebook.recipientUserId = 635;
    notebook.serviceAssigned = QDateTime::currentMSecsSinceEpoch() - 50;

    return notebook;
}

CanMoveToContainerRestrictions generateCanMoveToContainerRestrictions()
{
    CanMoveToContainerRestrictions r;
    r.canMoveToContainer = CanMoveToContainerStatus::INSUFFICIENT_ENTITY_PRIVILEGE;

    return r;
}

NotebookRestrictions generateNotebookRestrictions()
{
    NotebookRestrictions r;
    r.noReadNotes = true;
    r.noCreateNotes = false;
    r.noUpdateNotes = false;
    r.noExpungeNotes = true;
    r.noShareNotes = false;
    r.noEmailNotes = true;
    r.noSendMessageToRecipients = false;
    r.noUpdateNotebook = true;
    r.noExpungeNotebook = false;
    r.noSetDefaultNotebook = true;
    r.noSetNotebookStack = false;
    r.noPublishToPublic = true;
    r.noPublishToBusinessLibrary = false;
    r.noCreateTags = true;
    r.noUpdateTags = false;
    r.noExpungeTags = true;
    r.noSetParentTag = true;
    r.noCreateSharedNotebooks = false;
    r.updateWhichSharedNotebookRestrictions =
        SharedNotebookInstanceRestrictions::ASSIGNED;
    r.expungeWhichSharedNotebookRestrictions =
        SharedNotebookInstanceRestrictions::NO_SHARED_NOTEBOOKS;
    r.noShareNotesWithBusiness = false;
    r.noRenameNotebook = true;
    r.noSetInMyList = false;
    r.noChangeContact = true;
    r.canMoveToContainerRestrictions = generateCanMoveToContainerRestrictions();
    r.noSetReminderNotifyEmail = true;
    r.noSetReminderNotifyInApp = false;
    r.noSetRecipientSettingsStack = true;
    r.noCanMoveNote = false;

    return r;
}

Notebook generateNotebook()
{
    Notebook notebook;
    notebook.guid = QStringLiteral("guid");
    notebook.name = QStringLiteral("name");
    notebook.updateSequenceNum = 31;
    notebook.defaultNotebook = false;
    notebook.serviceCreated = QDateTime::currentMSecsSinceEpoch() - 200;
    notebook.serviceUpdated = QDateTime::currentMSecsSinceEpoch() - 100;
    notebook.publishing = generatePublishing();
    notebook.published = true;
    notebook.stack = QStringLiteral("stack");
    notebook.sharedNotebookIds = QList<qint64>() << 45;
    notebook.sharedNotebooks = QList<SharedNotebook>()
        << generateSharedNotebook();
    notebook.businessNotebook = generateBusinessNotebook();
    notebook.contact = generateUser();
    notebook.restrictions = generateNotebookRestrictions();
    notebook.recipientSettings = generateNotebookRecipientSettings();

    return notebook;
}

LinkedNotebook generateLinkedNotebook()
{
    LinkedNotebook notebook;
    notebook.shareName = QStringLiteral("shareName");
    notebook.username = QStringLiteral("username");
    notebook.shardId = QStringLiteral("shardId");
    notebook.sharedNotebookGlobalId = QStringLiteral("sharedNotebookGlobalId");
    notebook.uri = QStringLiteral("uri");
    notebook.guid = QStringLiteral("guid");
    notebook.updateSequenceNum = 823;
    notebook.noteStoreUrl = QStringLiteral("noteStoreUrl");
    notebook.webApiUrlPrefix = QStringLiteral("webApiUrlPrefix");
    notebook.stack = QStringLiteral("stack");
    notebook.businessId = 71;

    return notebook;
}

NotebookDescriptor generateNotebookDescriptor()
{
    NotebookDescriptor d;
    d.guid = QStringLiteral("guid");
    d.notebookDisplayName = QStringLiteral("notebookDisplayName");
    d.contactName = QStringLiteral("contactName");
    d.hasSharedNotebook = false;
    d.joinedUserCount = 23;

    return d;
}

UserProfile generateUserProfile()
{
    UserProfile p;
    p.id = 23;
    p.name = QStringLiteral("name");
    p.email = QStringLiteral("email");
    p.username = QStringLiteral("username");
    p.attributes = generateBusinessUserAttributes();
    p.joined = QDateTime::currentMSecsSinceEpoch();
    p.photoLastUpdated = QDateTime::currentMSecsSinceEpoch() - 100;
    p.photoUrl = QStringLiteral("photoUrl");
    p.role = BusinessUserRole::NORMAL;
    p.status = BusinessUserStatus::ACTIVE;

    return p;
}

RelatedContentImage generateRelatedContentImage()
{
    RelatedContentImage i;
    i.url = QStringLiteral("url");
    i.width = 20;
    i.height = 30;
    i.pixelRatio = 0.2;
    i.fileSize = 315;

    return i;
}

RelatedContent generateRelatedContent()
{
    RelatedContent c;
    c.contentId = QStringLiteral("contentId");
    c.title = QStringLiteral("title");
    c.url = QStringLiteral("url");
    c.sourceId = QStringLiteral("sourceId");
    c.sourceUrl = QStringLiteral("sourceUrl");
    c.sourceFaviconUrl = QStringLiteral("sourceFaviconUrl");
    c.sourceName = QStringLiteral("sourceName");
    c.date = QDateTime::currentMSecsSinceEpoch();
    c.teaser = QStringLiteral("teaser");
    c.thumbnails = QList<RelatedContentImage>() << generateRelatedContentImage();
    c.contentType = RelatedContentType::NEWS_ARTICLE;
    c.accessType = RelatedContentAccess::DIRECT_LINK_ACCESS_OK;
    c.visibleUrl = QStringLiteral("visibleUrl");
    c.clipUrl = QStringLiteral("clipUrl");
    c.contact = generateContact();
    c.authors = QStringList()
        << QStringLiteral("author1")
        << QStringLiteral("author2")
        << QStringLiteral("author3");

    return c;
}

BusinessInvitation generateBusinessInvitation()
{
    BusinessInvitation i;
    i.businessId = 22;
    i.email = QStringLiteral("email");
    i.role = BusinessUserRole::NORMAL;
    i.status = BusinessInvitationStatus::APPROVED;
    i.requesterId = 13;
    i.fromWorkChat = false;
    i.created = QDateTime::currentMSecsSinceEpoch();
    i.mostRecentReminder = QDateTime::currentMSecsSinceEpoch();

    return i;
}

UserIdentity generateUserIdentity()
{
    UserIdentity i;
    i.type = UserIdentityType::EMAIL;
    i.stringIdentifier = QStringLiteral("stringIdentifier");
    i.longIdentifier = 346;

    return i;
}

PublicUserInfo generatePublicUserInfo()
{
    PublicUserInfo i;
    i.userId = 34;
    i.serviceLevel = ServiceLevel::BASIC;
    i.username = QStringLiteral("username");
    i.noteStoreUrl = QStringLiteral("noteStoreUrl");
    i.webApiUrlPrefix = QStringLiteral("webApiUrlPrefix");

    return i;
}

UserUrls generateUserUrls()
{
    UserUrls u;
    u.noteStoreUrl = QStringLiteral("noteStoreUrl");
    u.webApiUrlPrefix = QStringLiteral("webApiUrlPrefix");
    u.userStoreUrl = QStringLiteral("userStoreUrl");
    u.utilityUrl = QStringLiteral("utilityUrl");
    u.messageStoreUrl = QStringLiteral("messageStoreUrl");
    u.userWebSocketUrl = QStringLiteral("userWebSocketUrl");

    return u;
}

AuthenticationResult generateAuthenticationResult()
{
    AuthenticationResult r;
    r.currentTime = QDateTime::currentMSecsSinceEpoch();
    r.authenticationToken = QStringLiteral("authenticationToken");
    r.expiration = QDateTime::currentMSecsSinceEpoch();
    r.user = generateUser();
    r.publicUserInfo = generatePublicUserInfo();
    r.noteStoreUrl = QStringLiteral("noteStoreUrl");
    r.webApiUrlPrefix = QStringLiteral("webApiUrlPrefix");
    r.secondFactorRequired = false;
    r.secondFactorDeliveryHint = QStringLiteral("secondFactorDeliveryHint");
    r.urls = generateUserUrls();

    return r;
}

BootstrapSettings generateBootstrapSettings()
{
    BootstrapSettings s;
    s.serviceHost = QStringLiteral("serviceHost");
    s.marketingUrl = QStringLiteral("marketingUrl");
    s.supportUrl = QStringLiteral("supportUrl");
    s.accountEmailDomain = QStringLiteral("accountEmailDomain");
    s.enableFacebookSharing = false;
    s.enableGiftSubscriptions = true;
    s.enableSupportTickets = false;
    s.enableSharedNotebooks = true;
    s.enableSingleNoteSharing = false;
    s.enableSponsoredAccounts = true;
    s.enableTwitterSharing = false;
    s.enableLinkedInSharing = true;
    s.enablePublicNotebooks = false;
    s.enableGoogle = true;

    return s;
}

BootstrapProfile generateBootstrapProfile()
{
    BootstrapProfile p;
    p.name = QStringLiteral("name");
    p.settings = generateBootstrapSettings();

    return p;
}

BootstrapInfo generateBootstrapInfo()
{
    BootstrapInfo i;
    i.profiles = QList<BootstrapProfile>() << generateBootstrapProfile();

    return i;
}

SyncChunk generateSyncChunk()
{
    SyncChunk c;
    c.currentTime = QDateTime::currentMSecsSinceEpoch();
    c.chunkHighUSN = 32;
    c.updateCount = 17;
    c.notes = QList<Note>() << generateNote();
    c.notebooks = QList<Notebook>() << generateNotebook();
    c.tags = QList<Tag>() << generateTag();
    c.searches = QList<SavedSearch>() << generateSavedSearch();
    c.resources = QList<Resource>() << generateResource();
    c.expungedNotes = QList<Guid>() << QStringLiteral("expungedNoteGuid");
    c.expungedNotebooks = QList<Guid>() << QStringLiteral("expungedNotebookGuid");
    c.expungedTags = QList<Guid>() << QStringLiteral("expungedTagGuid");
    c.expungedSearches = QList<Guid>() << QStringLiteral("expungedSearcheGuid");
    c.linkedNotebooks = QList<LinkedNotebook>() << generateLinkedNotebook();
    c.expungedLinkedNotebooks = QList<Guid>()
        << QStringLiteral("expungedLinkedNotebookGuid");

    return c;
}

NoteList generateNoteList()
{
    NoteList l;
    l.startIndex = 2;
    l.totalNotes = 1;
    l.notes = QList<Note>() << generateNote();
    l.stoppedWords = QStringList()
        << QStringLiteral("stoppedWord1")
        << QStringLiteral("stoppedWord2")
        << QStringLiteral("stoppedWord3");
    l.searchedWords = QStringList()
        << QStringLiteral("seachedWord1")
        << QStringLiteral("seachedWord2")
        << QStringLiteral("seachedWord3");
    l.updateCount = 34;
    l.searchContextBytes = QStringLiteral("searchContextBytes").toUtf8();
    l.debugInfo = QStringLiteral("debugInfo");

    return l;
}

NoteMetadata generateNoteMetadata()
{
    NoteMetadata m;
    m.guid = QStringLiteral("guid");
    m.title = QStringLiteral("title");
    m.contentLength = 23;
    m.created = QDateTime::currentMSecsSinceEpoch() - 200;
    m.updated = QDateTime::currentMSecsSinceEpoch() - 100;
    m.deleted = QDateTime::currentMSecsSinceEpoch() - 50;
    m.updateSequenceNum = 345;
    m.notebookGuid = QStringLiteral("notebookGuid");
    m.tagGuids = QList<Guid>()
        << QStringLiteral("tagGuid1")
        << QStringLiteral("tagGuid2")
        << QStringLiteral("tagGuid3");
    m.attributes = generateNoteAttributes();
    m.largestResourceMime = QStringLiteral("largestResourceMime");
    m.largestResourceSize = 378;

    return m;
}

NotesMetadataList generateNotesMetadataList()
{
    NotesMetadataList l;
    l.startIndex = 2;
    l.totalNotes = 1;
    l.notes = QList<NoteMetadata>() << generateNoteMetadata();
    l.stoppedWords = QStringList()
        << QStringLiteral("stoppedWord1")
        << QStringLiteral("stoppedWord2")
        << QStringLiteral("stoppedWord3");
    l.searchedWords = QStringList()
        << QStringLiteral("seachedWord1")
        << QStringLiteral("seachedWord2")
        << QStringLiteral("seachedWord3");
    l.updateCount = 34;
    l.searchContextBytes = QStringLiteral("searchContextBytes").toUtf8();
    l.debugInfo = QStringLiteral("debugInfo");

    return l;
}

NoteEmailParameters generateNoteEmailParameters()
{
    NoteEmailParameters p;
    p.guid = QStringLiteral("guid");
    p.note = generateNote();
    p.toAddresses = QStringList()
        << QStringLiteral("address1")
        << QStringLiteral("address2")
        << QStringLiteral("address3");
    p.ccAddresses = QStringList()
        << QStringLiteral("ccAddress1")
        << QStringLiteral("ccAddress2")
        << QStringLiteral("ccAddress3");
    p.subject = QStringLiteral("subject");
    p.message = QStringLiteral("message");

    return p;
}

RelatedResult generateRelatedResult()
{
    RelatedResult r;
    r.notes = QList<Note>() << generateNote();
    r.notebooks = QList<Notebook>() << generateNotebook();
    r.tags = QList<Tag>() << generateTag();
    r.containingNotebooks = QList<NotebookDescriptor>()
        << generateNotebookDescriptor();
    r.debugInfo = QStringLiteral("debugInfo");
    r.experts = QList<UserProfile>() << generateUserProfile();
    r.relatedContent = QList<RelatedContent>() << generateRelatedContent();
    r.cacheKey = QStringLiteral("cacheKey");
    r.cacheExpires = 320;

    return r;
}

UpdateNoteIfUsnMatchesResult generateUpdateNoteIfUsnMatchesResult()
{
    UpdateNoteIfUsnMatchesResult r;
    r.note = generateNote();
    r.updated = true;

    return r;
}

InvitationShareRelationship generateInvitationShareRelationship()
{
    InvitationShareRelationship r;
    r.displayName = QStringLiteral("displayName");
    r.recipientUserIdentity = generateUserIdentity();
    r.privilege = ShareRelationshipPrivilegeLevel::FULL_ACCESS;
    r.sharerUserId = 341;

    return r;
}

ShareRelationships generateShareRelationships()
{
    ShareRelationships r;
    r.invitations = QList<InvitationShareRelationship>()
        << generateInvitationShareRelationship();
    r.memberships = QList<MemberShareRelationship>()
        << generateMemberShareRelationship();
    r.invitationRestrictions = generateShareRelationshipRestrictions();

    return r;
}

ManageNotebookSharesParameters generateManageNotebookSharesParameters()
{
    ManageNotebookSharesParameters p;
    p.notebookGuid = QStringLiteral("notebookGuid");
    p.inviteMessage = QStringLiteral("inviteMessage");
    p.membershipsToUpdate = QList<MemberShareRelationship>()
        << generateMemberShareRelationship();
    p.invitationsToCreateOrUpdate = QList<InvitationShareRelationship>()
        << generateInvitationShareRelationship();
    p.unshares = QList<UserIdentity>() << generateUserIdentity();

    return p;
}

ManageNotebookSharesError generateManageNotebookSharesError()
{
    ManageNotebookSharesError e;
    e.userIdentity = generateUserIdentity();

    e.userException = EDAMUserException();
    e.userException->errorCode = EDAMErrorCode::ACCOUNT_CLEAR;
    e.userException->parameter = QStringLiteral("userException");

    e.notFoundException = EDAMNotFoundException();
    e.notFoundException->identifier = QStringLiteral("identfier");
    e.notFoundException->key = QStringLiteral("key");

    return e;
}

ManageNotebookSharesResult generateManageNotebookSharesResult()
{
    ManageNotebookSharesResult r;
    r.errors = QList<ManageNotebookSharesError>()
        << generateManageNotebookSharesError();

    return r;
}

SharedNoteTemplate generateSharedNoteTemplate()
{
    SharedNoteTemplate t;
    t.noteGuid = QStringLiteral("noteGuid");
    t.recipientThreadId = 23;
    t.recipientContacts = QList<Contact>()
        << generateContact();
    t.privilege = SharedNotePrivilegeLevel::MODIFY_NOTE;

    return t;
}

NotebookShareTemplate generateNotebookShareTemplate()
{
    NotebookShareTemplate t;
    t.notebookGuid = QStringLiteral("notebookGuid");
    t.recipientThreadId = 23;
    t.recipientContacts = QList<Contact>()
        << generateContact();
    t.privilege = SharedNotebookPrivilegeLevel::GROUP;

    return t;
}

CreateOrUpdateNotebookSharesResult generateCreateOrUpdateNotebookSharesResult()
{
    CreateOrUpdateNotebookSharesResult r;
    r.updateSequenceNum = 34;
    r.matchingShares = QList<SharedNotebook>() << generateSharedNotebook();

    return r;
}

ManageNoteSharesError generateManageNoteSharesError()
{
    ManageNoteSharesError e;
    e.identityID = 54;
    e.userID = 34;

    e.userException = EDAMUserException();
    e.userException->errorCode = EDAMErrorCode::ACCOUNT_CLEAR;
    e.userException->parameter = QStringLiteral("userException");

    e.notFoundException = EDAMNotFoundException();
    e.notFoundException->identifier = QStringLiteral("identfier");
    e.notFoundException->key = QStringLiteral("key");

    return e;
}

ManageNoteSharesResult generateManageNoteSharesResult()
{
    ManageNoteSharesResult r;
    r.errors = QList<ManageNoteSharesError>()
        << generateManageNoteSharesError();

    return r;
}

} // namespace tests
} // namespace qevercloud

#include <Common.moc>
