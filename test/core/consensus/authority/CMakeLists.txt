#
# Copyright Soramitsu Co., Ltd. All Rights Reserved.
# SPDX-License-Identifier: Apache-2.0
#

addtest(authority_manager_test
    authority_manager_test.cpp
    )
target_link_libraries(authority_manager_test
    authority_manager
    scale
    blob
    dummy_error
    )
