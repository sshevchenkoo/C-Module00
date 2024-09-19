#include "ScavTrap.hpp"


int main()
{
    ClapTrap ct1("CT1");

    ct1.attack("Target1");
    ct1.takeDamage(3);
    ct1.beRepaired(5);
  
    std::cout << std::endl;
    
    ScavTrap scav("Scavy");
    scav.attack("target1");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    scav.attack("target2");
    scav.takeDamage(80);
    scav.attack("target3");
    scav.beRepaired(50);
    scav.takeDamage(100);
    scav.attack("target4");

    return (0);
}
