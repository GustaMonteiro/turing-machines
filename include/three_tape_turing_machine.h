#pragma once

#include <vector>

#include "turing_machine.h"
#include "tape.h"

class Three_Tape_Turing_Machine : public Turing_Machine
{
public:
    bool test_string(const std::string &input);
    std::string get_name() const;

private:
    void prepare_tapes(const std::string &input);

    void write_numbers_on_other_tapes();
    void go_back_all_tapes();
    void verify_if_tapes_are_the_same_size();

private:
    Tape tape_1, tape_2, tape_3;
};