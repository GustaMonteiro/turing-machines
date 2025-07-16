#include "routines.h"

#include <format>
#include <iostream>
#include <string>
#include <vector>

#include "one_tape_turing_machine.h"
#include "three_tape_turing_machine.h"


std::vector<std::pair<std::string, bool> > tests = {
    {"", true},
    {"012", true},
    {"001122", true},
    {"000111222", true},
    {"0122", false},
    {"0112", false},
    {"0012", false},
    {"01122", false},
    {"00122", false},
    {"00112", false},
    {"0011222", false},
    {"0011122", false},
    {"0001122", false},
    {"00111222", false},
    {"00011222", false},
    {"00011122", false},
    {"011222", false},
    {"011122", false},
    {"001222", false},
    {"001112", false},
    {"000112", false},
    {"000122", false},
    {"001112222", false},
    {"001111222", false},
    {"000112222", false},
    {"000111122", false},
    {"000011122", false},
    {"000011222", false},
    {"122", false},
    {"112", false},
    {"12", false},
    {"1122", false},
    {"11222", false},
    {"11122", false},
    {"111222", false},
    {"1222", false},
    {"1112", false},
    {"1112222", false},
    {"1111222", false},
    {"112222", false},
    {"111122", false},
    {"022", false},
    {"02", false},
    {"002", false},
    {"0022", false},
    {"00222", false},
    {"00022", false},
    {"000222", false},
    {"0222", false},
    {"0002", false},
    {"002222", false},
    {"0002222", false},
    {"000022", false},
    {"0000222", false},
    {"01", false},
    {"011", false},
    {"001", false},
    {"0011", false},
    {"00111", false},
    {"00011", false},
    {"000111", false},
    {"0111", false},
    {"0001", false},
    {"001111", false},
    {"0001111", false},
    {"0000111", false},
    {"000011", false},
    {"2", false},
    {"22", false},
    {"222", false},
    {"2222", false},
    {"1", false},
    {"11", false},
    {"111", false},
    {"1111", false},
    {"0", false},
    {"00", false},
    {"000", false},
    {"0000", false},
};

void execute_all_tests()
{
    One_Tape_Turing_Machine one_tape;
    Three_Tape_Turing_Machine three_tape;

    std::vector<Turing_Machine *> machines{&one_tape, &three_tape};

    for (auto &machine: machines)
    {
        std::cout << "====================================================\n";
        std::cout << machine->get_name() << '\n';
        std::cout << "====================================================\n\n";

        for (auto [input, expected]: tests)
        {
            std::cout << std::format("Testing input '{}'\n", input);

            bool result = machine->test_string(input);

            if (result != expected)
                std::cout << "[DIFFERENT] ";

            std::cout << std::format("Input: '{}', expected: {}, got: {}, steps: {}\n\n", input, expected, result, machine->last_run_steps());
        }
    }
}

void execute_machines_with_input(const std::string &input_string)
{
    One_Tape_Turing_Machine one_tape;
    Three_Tape_Turing_Machine three_tape;

    std::vector<Turing_Machine *> machines{&one_tape, &three_tape};

    for (auto &machine: machines)
    {
        std::cout << "====================================================\n";
        std::cout << machine->get_name() << '\n';
        std::cout << "====================================================\n\n";

        bool result = machine->test_string(input_string);
        std::cout << "Result: " << (result ? "ACCEPT" : "REJECT") << '\n';
        std::cout << std::format("Number of steps: {}\n\n", machine->last_run_steps());
    }
}
