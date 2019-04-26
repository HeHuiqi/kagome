/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef KAGOME_INMEM_KEY_REPOSITORY_HPP
#define KAGOME_INMEM_KEY_REPOSITORY_HPP

#include <unordered_map>

#include "libp2p/crypto/key.hpp"
#include "libp2p/peer/key_repository.hpp"

namespace libp2p::peer {

  class InmemKeyRepository : public KeyRepository {
   public:
    ~InmemKeyRepository() override = default;

    void clear(const PeerId &p) override;

    outcome::result<PubVecPtr> getPublicKeys(const PeerId &p) override;

    void addPublicKey(const PeerId &p, const crypto::PublicKey &pub) override;

    outcome::result<KeyPairVecPtr> getKeyPairs(const PeerId &p) override;

    void addKeyPair(const PeerId &p, const KeyPair &kp) override;

   private:
    std::unordered_map<PeerId, PubVecPtr> pub_;
    std::unordered_map<PeerId, KeyPairVecPtr> kp_;
  };

}  // namespace libp2p::peer

#endif  //KAGOME_INMEM_KEY_REPOSITORY_HPP