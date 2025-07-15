#include "three_tape_turing_machine.h"

bool Three_Tape_Turing_Machine::test_string(const std::string &input)
{
    write_numbers_on_other_tapes();
    go_back_all_tapes();
    verify_if_tapes_are_the_same_size();
}

void Three_Tape_Turing_Machine::prepare_tapes(const std::string &input)
{
    tape_1.prepare(input);
    tape_2.reset();
    tape_3.reset();
}

void Three_Tape_Turing_Machine::write_numbers_on_other_tapes()
{
}

void Three_Tape_Turing_Machine::go_back_all_tapes()
{
}

void Three_Tape_Turing_Machine::verify_if_tapes_are_the_same_size()
{
}
