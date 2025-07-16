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
