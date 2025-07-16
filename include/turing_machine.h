#pragma once

#include <string>

struct Turing_Machine
{
    virtual bool test_string(const std::string &input) = 0;
    virtual std::string get_name() const = 0;

    size_t last_run_steps() const
    {
        return steps_counter;
    }

protected:
    size_t steps_counter = 0;
};