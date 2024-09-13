#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>
# include <iomanip>

class   Weapon
{
    public:
        Weapon(const std::string& initType);
        const std::string& getType() const;
        void    setType(std::string newtype);
    private:
        std::string type;
};

#endif
