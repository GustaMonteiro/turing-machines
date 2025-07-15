#pragma once

#include <string>

struct Turing_Machine
{
    virtual bool test_string(const std::string &input) = 0;
    virtual std::string get_name() const = 0;
};