#include <iostream>

#include "routines.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage:\n";
        std::cerr << '\t' << argv[0] << " -t              # Run all tests for both Turing Machines\n";
        std::cerr << '\t' << argv[0] << " <input-string>  # Run both Turing Machines with the given input string\n";
        return EXIT_FAILURE;
    }
    else if (std::string(argv[1]) == "-t")
    {
        execute_all_tests();
        return EXIT_SUCCESS;
    }
    else
    {
        execute_machines_with_input(std::string(argv[1]));
        return EXIT_SUCCESS;
    }
}
