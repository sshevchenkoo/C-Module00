#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct1("CT1");

    ct1.attack("Target1");
    ct1.takeDamage(3);
    ct1.beRepaired(5);
  
    std::cout << std::endl;

    ClapTrap ct2(ct1);
    ct2.attack("Target2");
    ct2.takeDamage(4);
    ct2.beRepaired(2);

    std::cout << std::endl;

    ClapTrap ct3("CT3");
    ct3 = ct1;
    ct3.attack("Target3");
    ct3.takeDamage(5);
    ct3.beRepaired(1);

    std::cout << std::endl;

    ct1.attack("Target4");
    ct1.takeDamage(2);
    ct1.beRepaired(3);

    std::cout << std::endl;

    ClapTrap def;
    def.attack("Def");
    def.takeDamage(3);
    def.beRepaired(5);

    return (0);
}
