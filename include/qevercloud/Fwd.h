/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#ifndef QEVERCLOUD_GENERATED_FWD
#define QEVERCLOUD_GENERATED_FWD

#include "exceptions/Fwd.h"
#include "services/Fwd.h"
#include "types/Fwd.h"

#include <memory>

namespace qevercloud {

class IInkNoteImageDownloader;
using IInkNoteImageDownloaderPtr = std::shared_ptr<IInkNoteImageDownloader>;

class IRequestContext;
using IRequestContextPtr = std::shared_ptr<IRequestContext>;

struct IRetryPolicy;
using IRetryPolicyPtr = std::shared_ptr<IRetryPolicy>;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_FWD
