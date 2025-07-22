#include "one_tape_turing_machine.h"
#include "definitions.h"

#include <iostream>

/*
1) Write the input on the tape.
2) If the first element is blank, ACCEPT.
3) Otherwise, if the current element is 0:
    4) Mark with X and advance to the right until you find something other than 0 and Y.
    5) If the element found is different from 1, REJECT.
    6) Otherwise, mark with Y and advance to the right until you find something other than 1 and Z.
    7) If the element found is different from 2, REJECT.
    8) Otherwise, mark with Z and, while the current element is different from X, move to the left.
    9) Go right and return to step 3.
10) Otherwise, if the current element is different from Y, REJECT.
11) Otherwise, advance to the right until you find something other than Y and Z.
12) If the element found is blank, ACCEPT, otherwise, REJECT.
*/
bool One_Tape_Turing_Machine::test_string(const std::string &input)
{
    try
    {
        prepare_tape(input);
        searching_loop();
    }
    catch (bool result)
    {
        return result;
    }

    return REJECT;
}

std::string One_Tape_Turing_Machine::get_name() const
{
    return "One Tape Turing Machine";
}

void One_Tape_Turing_Machine::prepare_tape(const std::string &input)
{
    steps_counter = 0;
    tape.prepare(input);
}

void One_Tape_Turing_Machine::searching_loop()
{
    while (true)
    {
        if (current() == BLANK)
        {
            throw ACCEPT;
        }
        else if (current() == ZERO)
        {
            mark_x();
            go_right();
            search_for_one();
        }
        else if (current() == Y)
        {
            look_for_remaining_numbers();
        }
        else
        {
            throw REJECT;
        }
    }
}

void One_Tape_Turing_Machine::search_for_one()
{
    while (true)
    {
        if (current() == ONE)
        {
            mark_y();
            go_right();
            search_for_two();
            break;
        }
        else if (current() == ZERO || current() == Y)
        {
            go_right();
        }
        else
        {
            throw REJECT;
        }
    }
}

void One_Tape_Turing_Machine::search_for_two()
{
    while (true)
    {
        if (current() == TWO)
        {
            mark_z();
            go_back();
            break;
        }
        else if (current() == ONE || current() == Z)
        {
            go_right();
        }
        else
        {
            throw REJECT;
        }
    }
}

void One_Tape_Turing_Machine::look_for_remaining_numbers()
{
    while (true)
    {
        if (current() == Y || current() == Z)
        {
            go_right();
        }
        else if (current() == BLANK)
        {
            throw ACCEPT;
        }
        else
        {
            throw REJECT;
        }
    }
}

void One_Tape_Turing_Machine::go_back()
{
    while (current() != X)
        go_left();

    go_right();
}

char One_Tape_Turing_Machine::current() const
{
    return tape.current();
}

void One_Tape_Turing_Machine::mark_x()
{
    steps_counter++;
    tape.write(X);
}

void One_Tape_Turing_Machine::mark_y()
{
    steps_counter++;
    tape.write(Y);
}

void One_Tape_Turing_Machine::mark_z()
{
    steps_counter++;
    tape.write(Z);
}

void One_Tape_Turing_Machine::go_left()
{
    steps_counter++;
    tape.go_left();
}

void One_Tape_Turing_Machine::go_right()
{
    steps_counter++;
    tape.go_right();
}
