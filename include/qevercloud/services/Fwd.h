/**
 * Original work: Copyright (c) 2014 Sergey Skoblikov
 * Modified work: Copyright (c) 2015-2022 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license:
 * https://opensource.org/licenses/MIT
 *
 * This file was generated from Evernote Thrift API
 */

#include <memory>

#ifndef QEVERCLOUD_GENERATED_SERVICES_FWD
#define QEVERCLOUD_GENERATED_SERVICES_FWD

namespace qevercloud {

class INoteStore;
using INoteStorePtr = std::shared_ptr<INoteStore>;

class IUserStore;
using IUserStorePtr = std::shared_ptr<IUserStore>;

class NoteStoreServer;
class UserStoreServer;

} // namespace qevercloud

#endif // QEVERCLOUD_GENERATED_SERVICES_FWD
