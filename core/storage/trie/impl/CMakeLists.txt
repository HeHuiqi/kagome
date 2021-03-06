# Copyright Soramitsu Co., Ltd. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0

add_library(trie_storage_backend
    trie_storage_backend_impl.cpp
    trie_storage_backend_batch.cpp
    )
target_link_libraries(trie_storage_backend
    buffer
    )
kagome_install(trie_storage_backend)

add_library(topper_trie_batch
    topper_trie_batch_impl.cpp
    )
target_link_libraries(topper_trie_batch
    buffer
    )
kagome_install(topper_trie_batch)

add_library(persistent_trie_batch
    persistent_trie_batch_impl.cpp
    )
target_link_libraries(persistent_trie_batch
    buffer
    trie_error
    polkadot_trie_cursor
    topper_trie_batch
    )
kagome_install(persistent_trie_batch)

add_library(ephemeral_trie_batch
    ephemeral_trie_batch_impl.cpp
    )
target_link_libraries(ephemeral_trie_batch
    buffer
    polkadot_trie_cursor
    topper_trie_batch
    )
kagome_install(ephemeral_trie_batch)

add_library(trie_storage
    trie_storage_impl.cpp
    )
target_link_libraries(trie_storage
    ephemeral_trie_batch
    persistent_trie_batch
    logger
    )
kagome_install(trie_storage)
