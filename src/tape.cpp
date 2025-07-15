#include "tape.h"
#include "definitions.h"

void Tape::prepare(const std::string &input)
{
    reset();
    tape.insert(tape.begin(), input.begin(), input.end());
    tape.resize(input.size() + NUMBER_OF_BLANKS_AFTER, BLANK);
}

void Tape::go_left()
{
    if (!cursor)
        return;

    cursor--;
}

void Tape::go_right()
{
    if (cursor >= tape.size())
        return;

    cursor++;
}

void Tape::write(char chr)
{
    tape[cursor] = chr;
}

void Tape::reset()
{
    cursor = 0;
    tape.clear();
}

char Tape::current() const
{
    return tape[cursor];
}