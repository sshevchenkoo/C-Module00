#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string namea, Weapon &initgun);
        void   attack();
    private:
        Weapon  &gun;
        std::string name;
};


#endif
