#include "Weapon.hpp"

Weapon::Weapon(const std::string& initType) : type(initType)
{
}

const std::string& Weapon::getType() const
{
    return (this->type);
}
void    Weapon::setType(std::string newtype)
{
    this->type = newtype;
}
