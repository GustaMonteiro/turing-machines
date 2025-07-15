#include "one_tape_turing_machine.h"
#include "definitions.h"

#include <iostream>

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

void One_Tape_Turing_Machine::prepare_tape(const std::string &input)
{
    cursor = 0;
    tape.clear();
    tape.insert(tape.begin(), input.begin(), input.end());
    tape.resize(input.size() + NUMBER_OF_BLANKS_AFTER, BLANK);
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

inline char One_Tape_Turing_Machine::current() const
{
    return tape[cursor];
}

void One_Tape_Turing_Machine::mark_x()
{
    tape[cursor] = X;
}

void One_Tape_Turing_Machine::mark_y()
{
    tape[cursor] = Y;
}

void One_Tape_Turing_Machine::mark_z()
{
    tape[cursor] = Z;
}

void One_Tape_Turing_Machine::go_left()
{
    cursor--;
}

void One_Tape_Turing_Machine::go_right()
{
    cursor++;
}
