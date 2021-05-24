//
// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//
#ifndef ZAHLEN_CPP_ZAHLEN_HPP
#define ZAHLEN_CPP_ZAHLEN_HPP

#include <iostream>
#include <string>
#include <vector>

class Zahlen {
public:
    std::vector<std::string> files;

    bool new_buffer = false;
public:
    Zahlen() = default;
    ~Zahlen()= default;

    bool is_exit           (std::string const input) noexcept;
    bool is_force_quit     (std::string const input) noexcept;
    bool is_clear          (std::string const input) noexcept;
    bool is_ls             (std::string const input) noexcept;
    bool is_previous       (std::string const input) noexcept;

    void exec              (std::string const input) noexcept;

    std::string read_file  (std::string const input) noexcept;
    void display_prompt    ()                        noexcept;
    void init_directories  ()                        noexcept;
    void process_input     (std::string const input) noexcept;
    std::string const input()                        noexcept;
};

#endif // ZAHLEN_CPP_ZAHLEN_HPP