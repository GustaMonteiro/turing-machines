#pragma once

#include <vector>
#include <string>

class Tape
{
public:
    void prepare(const std::string &input);
    void go_left();
    void go_right();
    void write(char chr);
    void reset();
    char current() const;

private:
    std::vector<char> tape;
    size_t cursor = 0;
};