/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2021 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_TYPEALIASES_H
#define QEVERCLOUD_GENERATED_TYPEALIASES_H

#include <qevercloud/Export.h>

#include <QString>
#include <QtGlobal>

namespace qevercloud {

/**
 * A monotonically incrementing number on each shard that identifies a cross shard
 * cache invalidation event.
 */
using InvalidationSequenceNumber = qint64;

/**
 * A type alias for the primary identifiers for Identity objects.
 */
using IdentityID = qint64;

/**
 * Every Evernote account is assigned a unique numeric identifier which
 * will not change for the life of the account.  This is independent of
 * the (string-based) "username" which is known by the user for login
 * purposes.  The user should have no reason to know their UserID.
 */
using UserID = qint32;

/**
 * Most data elements within a user's account (e.g. notebooks, notes, tags,
 * resources, etc.) are internally referred to using a globally unique
 * identifier that is written in a standard string format.  For example:
 *
 *    "8743428c-ef91-4d05-9e7c-4a2e856e813a"
 *
 * The internal components of the GUID are not given any particular meaning:
 * only the entire string is relevant as a unique identifier.
 */
using Guid = QString;

/**
 * An Evernote Timestamp is the date and time of an event in UTC time.
 * This is expressed as a specific number of milliseconds since the
 * standard base "epoch" of:
 *
 *    January 1, 1970, 00:00:00 GMT
 *
 * NOTE:  the time is expressed at the resolution of milliseconds, but
 * the value is only precise to the level of seconds.   This means that
 * the last three (decimal) digits of the timestamp will be '000'.
 *
 * The Thrift IDL specification does not include a native date/time type,
 * so this value is used instead.
 *
 * The service will accept timestamp values (e.g. for Note created and update
 * times) between 1000-01-01 and 9999-12-31
 */
using Timestamp = qint64;

/**
 * A sequence number for the MessageStore subsystem.
 */
using MessageEventID = qint64;

/**
 * A type alias for the primary identifiers for MessageThread objects.
 */
using MessageThreadID = qint64;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_TYPEALIASES_H
