#include "Zombie.hpp"

Zombie::Zombie(std::string zombiename) : name(zombiename)
{
    std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std::endl;
}

void    Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
