#include "Zombie.hpp"

void    Zombie::setName(std::string zombiename)
{
    this->name = zombiename;
}

void    Zombie::announce()
{
    std::cout << this->name << std::endl;
}
