// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#include <filesystem>
#include <string>
#include <fstream>
#include "../include/zahlen.hpp"
#include "../include/zahlen_helpers.hpp"
#include "../include/zahlen_buffer.hpp"

bool Zahlen::is_exit(std::string const input) noexcept {
    return (input == "q") ? true : false;
}

bool Zahlen::is_force_quit(std::string const input) noexcept {
    return (input == "q!"
        || input  == "!q") ? true : false;
}

bool Zahlen::is_clear(std::string const input) noexcept {
    return (input == "clear") ? true : false;
}

bool Zahlen::is_ls(std::string const input) noexcept {
    return (input == "ls"
        || input  == "list"
        || input  == "dir") ? true : false;
}

bool Zahlen::is_previous(std::string const input) noexcept {
    return (input == "prev"
        || input  == "previous"
        || input  == "..") ? true : false;
}

void Zahlen::exec(std::string const input) noexcept {
    this->new_buffer = true; if(!std::system(input.c_str())) {}
}

std::string Zahlen::read_file(std::string const input) noexcept {
    std::ifstream read(input); std::string data;
    for(std::string temporary; std::getline(read, temporary);
        data.append(temporary + "\n")); return data;
}

void Zahlen::display_prompt() noexcept {
    buffer::clear();
    println("\x1b[1;95m", std::filesystem::current_path().string(), "\x1b[0m");
}

void Zahlen::init_directories() noexcept {
    for(unsigned i = 0;
        const auto& directory : std::filesystem::directory_iterator(std::filesystem::current_path())) {
            print("\x1b[0;93m[\x1b[1;96m", i, "\x1b[0;93m]\x1b[0m : ");

            if(directory.is_directory()) { print("\x1b[1;97m"); } else { print("\x1b[1;92m"); }

            println(directory.path().filename().string());
            this->files.push_back(directory.path().filename().string()); ++i;
    }
}

std::string const Zahlen::input() noexcept {
    print("\x1b[0;97m>> \x1b[0m");

    for(std::string temporary; std::getline(std::cin, temporary);) {
        return temporary;
    }
}

void Zahlen::process_input(std::string const input) noexcept {
    if(this->is_exit(input))  {
        if(this->new_buffer) {
            new_buffer = false; return;
        } std::exit(0); }
    if(this->is_force_quit(input)) { std::exit(0); }
    if(this->is_clear(input)) { return; }
    if(this->is_ls(input)) { new_buffer = false; return; }
    if(this->is_previous(input)) { std::filesystem::current_path(".."); return; }
    if(!std::isdigit(input.front())){ this->exec(input); return; }

    unsigned i = std::stoi(input); this->new_buffer = false;

    //if(std::isdigit(i)) {
        if(i <= this->files.size()) {
            std::string directory = this->files.at(i);
            auto what = std::filesystem::path(directory);
            if(std::filesystem::is_directory(std::filesystem::status(what))) {
                std::filesystem::current_path(what);
                this->files.clear(); return;
            }

            if(std::filesystem::is_regular_file(std::filesystem::status(what))) {
                buffer::clear(); this->new_buffer = true;
                println(this->read_file(directory));
            }
        }
   // }
}

int main(int argc, char** argv) noexcept {
    Zahlen init;

    std::string input;

    do {
        if(!init.new_buffer) {
            init.display_prompt  ();
            init.init_directories();
        }

        init.process_input   (init.input());
    } while(input != "q");

    buffer::clear();
}