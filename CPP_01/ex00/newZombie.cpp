#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie* zombieheap;

    zombieheap = new Zombie(name);
    return (zombieheap);
}
