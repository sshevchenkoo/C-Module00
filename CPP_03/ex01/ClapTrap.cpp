#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap default constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap " << Name << " constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called for " << other.Name << std::endl;
    this->Name = other.Name;
    this->HitPoints = other.HitPoints;
    this->EnergyPoints = other.EnergyPoints;
    this->AttackDamage = other.AttackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        std::cout << "Assignment operator called for " << other.Name << std::endl;
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " destructor" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->HitPoints == 0 || this->EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << this->Name
                    << " cannot attack due to lack of energy or hit points!"
                    << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->Name << " attacks "
                << target << ", causing " << this->AttackDamage
                << " points of damage!" << std::endl;
    this->EnergyPoints -= 1;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->HitPoints == 0)
    {
        std::cout << "ClapTrap " << this->Name 
                    << " is already destroyed!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->Name << " takes "
                << amount << " points of damage!" << std::endl;
    if (amount >= this->HitPoints)
    {
        this->HitPoints = 0;
    }
    else
        this->HitPoints -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->HitPoints == 0 || this->EnergyPoints == 0)
    {
        std::cout << "ClapTrap " << this->Name
                    << " cannot be repaired due to lack of energy or being destroyed!"
                    << std::endl;
        return ;
    }
    std::cout << "ClapTrap "<< this->Name << " is repaired, restoring "
                << amount << "hit points!" << std::endl;
    this->HitPoints += amount;
    this->EnergyPoints -= 1;
}
