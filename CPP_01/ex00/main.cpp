#include "Zombie.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Enter Zombie Name" << std::endl;
        return 1;
    }
    Zombie  *zombieheap;

    randomChump(argv[1]);
    zombieheap = newZombie(argv[1]);
    zombieheap->announce();
    delete(zombieheap);
    return (0);
}
