#include "HumanA.hpp"

HumanA::HumanA(std::string namea, Weapon &initgun) : gun(initgun) , name(namea)
{
}

void    HumanA::attack()
{
    std::cout << this->name << " attacks with their " << gun.getType() << std::endl;
}
