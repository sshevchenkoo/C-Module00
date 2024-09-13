#include "HumanB.hpp"

HumanB::HumanB(std::string nameb) : gun(NULL), name(nameb)
{
}

void    HumanB::setWeapon(Weapon &newgun)
{
    this->gun = &newgun;
}

void    HumanB::attack()
{
    std::cout << this->name << " attacks with their " << gun->getType() << std::endl;
}
