#include "three_tape_turing_machine.h"

#include "definitions.h"

bool Three_Tape_Turing_Machine::test_string(const std::string &input)
{
    prepare_tapes(input);
    write_numbers_on_other_tapes();
    go_back_all_tapes();
    return verify_if_tapes_are_the_same_size();
}

void Three_Tape_Turing_Machine::prepare_tapes(const std::string &input)
{
    tape_1.prepare(input);
    tape_2.prepare(std::string(input.size(), BLANK));
    tape_3.prepare(std::string(input.size(), BLANK));
}

void Three_Tape_Turing_Machine::write_numbers_on_other_tapes()
{
    while (tape_1.current() != BLANK)
    {
        if(tape_1.current() == ZERO)
            tape_1.go_right();
        else if (tape_1.current() == ONE)
        {
            tape_2.write(ONE);
            tape_2.go_right();

            tape_1.write(BLANK);
            tape_1.go_right();
        }
        else if (tape_1.current() == TWO)
        {
            tape_3.write(TWO);
            tape_3.go_right();

            tape_1.write(BLANK);
            tape_1.go_right();
        }
    }
}

void Three_Tape_Turing_Machine::go_back_all_tapes()
{
    while (tape_1.current() != ZERO)
        tape_1.go_left();

    while (tape_2.current() != ONE)
        tape_2.go_left();

    while (tape_3.current() != TWO)
        tape_3.go_left();
}

bool Three_Tape_Turing_Machine::verify_if_tapes_are_the_same_size()
{
    while (true)
    {
        if (tape_1.current() == ZERO && tape_2.current() == ONE && tape_3.current() == TWO)
        {
            tape_1.write(X);
            tape_1.go_left();
            tape_2.write(Y);
            tape_2.go_left();
            tape_3.write(Z);
            tape_3.go_left();
        }
        else if (tape_1.current() == X && tape_2.current() == Y && tape_3.current() == Z)
            return ACCEPT;
        else
            return REJECT;
    }

    return REJECT;
}
