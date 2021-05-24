//
// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef ZAHLEN_CPP_ZAHLEN_BUFFER_HPP
#define ZAHLEN_CPP_ZAHLEN_BUFFER_HPP

#include <csignal>
#include "zahlen_helpers.hpp"
#include "zahlen.hpp"

namespace buffer {
    static void refresh() noexcept {
        print("\x1b[2J");
    }

    static void clear() noexcept {
        refresh(); print("\x1b[H");
    }
}

#endif // ZAHLEN_CPP_ZAHLEN_BUFFER_HPP
