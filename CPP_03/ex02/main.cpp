#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << std::endl;

    FragTrap frag("Fragy");
    frag.attack("target1");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();
    frag.attack("target2");
    frag.takeDamage(80);
    frag.attack("target3");
    frag.beRepaired(50);

    return (0);
}
