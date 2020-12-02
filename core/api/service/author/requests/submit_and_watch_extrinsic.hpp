/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef KAGOME_SUBMIT_AND_WATCH_EXTRINSIC_HPP
#define KAGOME_SUBMIT_AND_WATCH_EXTRINSIC_HPP

#include <jsonrpc-lean/request.h>

#include "api/service/author/author_api.hpp"
#include "primitives/extrinsic.hpp"

namespace kagome::api::author::request {

  class SubmitAndWatchExtrinsic final {
   public:
    explicit SubmitAndWatchExtrinsic(std::shared_ptr<AuthorApi> api)
        : api_(std::move(api)){};

    outcome::result<void> init(const jsonrpc::Request::Parameters &params);

    outcome::result<primitives::SubscriptionId> execute();

   private:
    std::shared_ptr<AuthorApi> api_;
    primitives::Extrinsic extrinsic_;
  };

}  // namespace kagome::api::author::request

#endif  // KAGOME_SUBMIT_AND_WATCH_EXTRINSIC_HPP