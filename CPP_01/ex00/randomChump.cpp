#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie zombiestack(name);
    zombiestack.announce();
}
