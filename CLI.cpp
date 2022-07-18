#include <iostream>

int main(int argc, char **argv)
{
    std::string arg = argv[1], arg_value;
    if (arg == "echo")
    {
        for (int i = 2; i < argc; ++i)
        {
            arg_value = argv[i];
            std::cout << arg_value << " ";
        }
    }
    else if (arg == "+" && argc == 4)
    {
        std::cout << "addition = " << std::stoi(argv[2]) + std::stoi(argv[3]);
    }
    else if (arg == "-" && argc == 4)
    {
        std::cout << "subtraction = " << std::stoi(argv[2]) - std::stoi(argv[3]);
    }

    return 0;
}
