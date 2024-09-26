#include "AMateria.hpp"

Character::Character() : name("Default")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
    std::cout << "Character default created." << std::endl;
}

Character::Character(std::string const& name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = nullptr;
    std::cout << "Character " << name << " created." << std::endl;
}

Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = nullptr;
    }
    std::cout << "Character " << name << " copied." << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this == &other) 
        return *this;

    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = nullptr;
    }

    name = other.name;
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = nullptr;
    }
    std::cout << "Character " << name << " assigned." << std::endl;
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
    std::cout << "Character " << name << " destroyed." << std::endl;
}

std::string const& Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            std::cout << "Equipped " << m->getType() << " to "
                        << name << " in slot " << i << "." 
                        << std::endl;
            return ;
        }
    }
    std::cout << "No empty slots to equip " << m->getType()
                 << " for " << name << "." << std::endl;
}

void    Character::unequip(int idx)
{
    if (idx >= 4 || idx < 0 || !inventory[idx])
        return ;
    inventory[idx] = nullptr;
    std::cout << "Unequipped materia from slot " 
                << idx << " for " << name << "." 
                << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 4 || idx < 0 || !inventory[idx])
        return ;

    inventory[idx]->use(target);
    std::cout << name << " used materia from slot " 
                << idx << " on " << target.getName() 
                << "." << std::endl;
}
