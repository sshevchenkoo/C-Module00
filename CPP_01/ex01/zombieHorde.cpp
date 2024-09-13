#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zombieHorde;
    int i = 0;

    zombieHorde = new Zombie[N];
    while (i < N)
    {
        zombieHorde[i].setName(name);
        i++;
    }
    return (zombieHorde);
}
