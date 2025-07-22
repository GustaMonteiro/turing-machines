#include "three_tape_turing_machine.h"

#include "definitions.h"


/*
1) Write the input to tape 1.
2) If the first element is blank, ACCEPT.
3) Otherwise, while the current element on tape 1 is 0:
    4) Write 0 on tape 2 and move to the right.
    5) Write blank on tape 1 and move to the right.
6) If the current element is not a 1, REJECT.
7) Otherwise, while the current element on tape 1 is 1:
    8) Write 1 on tape 3 and move to the right.
    9) Write blank on tape 1 and move to the right.
10) If the current element is not a 2, REJECT.
11) Move tape 2 to the left.
12) Move tape 3 to the left.
13) While not stopping:
    14) If the current element on tape 1 is 2, on tape 2 is 0, and on tape 3 is 1:
        15) Write Z on tape 1 and move right.
        16) Write X on tape 2 and move left.
        17) Write Y on tape 3 and move left.
        18) Return to step 14.
    19) Otherwise, if the current element on tape 1 is blank, on tape 2 is X, and on tape 3 is Y, ACCEPT; otherwise, REJECT.
*/
bool Three_Tape_Turing_Machine::test_string(const std::string &input)
{
    try
    {
        prepare_tapes(input);
        write_numbers_on_other_tapes();
        go_back_all_tapes();
        verify_if_tapes_are_the_same_size();
    }
    catch (bool result)
    {
        return result;
    }

    return REJECT;
}

std::string Three_Tape_Turing_Machine::get_name() const
{
    return "Three Tape Turing Machine";
}

void Three_Tape_Turing_Machine::prepare_tapes(const std::string &input)
{
    steps_counter = 0;
    tape_1.prepare(input);
    tape_2.prepare(std::string(input.size(), BLANK));
    tape_3.prepare(std::string(input.size(), BLANK));
}

void Three_Tape_Turing_Machine::write_numbers_on_other_tapes()
{
    if (tape_1.current() == BLANK)
        throw ACCEPT;

    write_zeroes_on_tape_2();
    write_ones_on_tape_3();
}

void Three_Tape_Turing_Machine::write_zeroes_on_tape_2()
{
    while (tape_1.current() == ZERO)
    {
        tape_2.write(ZERO);
        tape_2.go_right();

        tape_1.write(BLANK);
        tape_1.go_right();

        steps_counter+=4;
    }

    if(tape_1.current() != ONE)
        throw REJECT;
}

void Three_Tape_Turing_Machine::write_ones_on_tape_3()
{
    while (tape_1.current() == ONE)
    {
        tape_3.write(ONE);
        tape_3.go_right();

        tape_1.write(BLANK);
        tape_1.go_right();

        steps_counter+=4;
    }

    if (tape_1.current() != TWO)
        throw REJECT;
}

void Three_Tape_Turing_Machine::go_back_all_tapes()
{
    tape_2.go_left();
    tape_3.go_left();

    steps_counter+=2;
}

void Three_Tape_Turing_Machine::verify_if_tapes_are_the_same_size()
{
    while (true)
    {
        if (tape_1.current() == TWO && tape_2.current() == ZERO && tape_3.current() == ONE)
        {
            tape_1.write(Z);
            tape_1.go_right();
            tape_2.write(X);
            tape_2.go_left();
            tape_3.write(Y);
            tape_3.go_left();

            steps_counter+=6;
        }
        else if (tape_1.current() == BLANK && tape_2.current() == X && tape_3.current() == Y)
            throw ACCEPT;
        else
            throw REJECT;
    }
}
