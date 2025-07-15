#pragma once

#include <vector>

#include "turing_machine.h"

class One_Tape_Turing_Machine : public Turing_Machine
{
public:
    bool test_string(const std::string &input);

private:
    void prepare_tape(const std::string &input);
    void searching_loop();
    void search_for_one();
    void search_for_two();
    void look_for_remaining_numbers();
    inline char current() const;

    void mark_x();
    void mark_y();
    void mark_z();
    void go_left();
    void go_right();
    void go_back();

private:
    std::vector<char> tape;
    size_t cursor = 0;
};