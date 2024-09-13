#include "Zombie.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Enter Zombie " << std::endl;
        return 1;
    }
    int N;
    int i;

    i = 0;
    N = std::stoi(argv[1]);
    Zombie *horde;
    horde = zombieHorde(N, argv[2]);
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}
