#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap " << "Default"
                << " created with 100 HP, 50 Energy Points, and 20 Attack Damage!"
                << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttackDamage = 20;
    std::cout << "ScavTrap " << this->Name 
                << " created with 100 HP, 50 Energy Points, and 20 Attack Damage!"
                << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap&    ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap() 
{
    std::cout << "ScavTrap " << this->Name 
                << " is destroyed!" << std::endl;
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << this->Name 
                << " is now in Gatekeeper mode!" 
                << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->HitPoints == 0 || this->EnergyPoints == 0)
    {
        std::cout << "ScavTrap " << this->Name
                    << " cannot attack due to lack of energy or hit points!"
                    << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->Name << " attacks "
                << target << ", causing " << this->AttackDamage
                << " points of damage!" << std::endl;
    this->EnergyPoints -= 1;
}
