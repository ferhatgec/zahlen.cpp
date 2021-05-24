//
// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef ZAHLEN_CPP_ZAHLEN_HELPERS_HPP
#define ZAHLEN_CPP_ZAHLEN_HELPERS_HPP

#include "zahlen.hpp"

namespace {
    template<typename... Args>
    void print(Args... args) noexcept {
        ((std::cout << args), ...);
    }

    template<typename... Args>
    void println(Args... args) noexcept {
        ((std::cout << args), ...) << '\n';
    }
}

#endif // ZAHLEN_CPP_ZAHLEN_HELPERS_HPP
