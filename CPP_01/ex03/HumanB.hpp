#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string nameb);
        void   attack();
        void    setWeapon(Weapon &newgun);
    private:
        Weapon  *gun;
        std::string name;
};


#endif
