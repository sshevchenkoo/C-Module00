#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Zombie
{
    public:
        void    setName(std::string zombiename);
        void    announce(void);
    private:
        std::string    name;
};

Zombie* zombieHorde( int N, std::string name );

#endif
