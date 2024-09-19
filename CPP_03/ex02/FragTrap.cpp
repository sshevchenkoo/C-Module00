#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap " << "Dafault" 
                << " created with 100 HP, 100 Energy Points, and 30 Attack Damage!"
                << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttackDamage = 30;
    std::cout << "FragTrap " << this->Name 
                << " created with 100 HP, 100 Energy Points, and 30 Attack Damage!"
                << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap&    FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap assignment operator called" << std::endl;
    return (*this);
}

FragTrap::~FragTrap() 
{
    std::cout << "FragTrap " << this->Name 
                << " is destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->HitPoints == 0 || this->EnergyPoints == 0)
    {
        std::cout << "FragTrap " << this->Name
                    << " cannot attack due to lack of energy or hit points!"
                    << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->Name << " attacks "
                << target << ", causing " << this->AttackDamage
                << " points of damage!" << std::endl;
    this->EnergyPoints -= 1;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->Name<< " requests a positive high five!" << std::endl;
}
