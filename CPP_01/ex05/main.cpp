#include "Harl.hpp"

int main()
{
    Harl    test;
    std::string level;

    std::cout << "Write level: ";
    std::cin >> level;

    test.complain(level);
    return (0);
}
