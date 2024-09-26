#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
    int i = 0;
    while (i < 100)
    {
        this->ideas[i] = "My idea";
        i++;
    }
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    int i = 0;
    while(i < 100)
    {
        this->ideas[i] = other.ideas[i];
        i++;
    }
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &other)
    {
        int i = 0;
        while(i < 100)
        {
            this->ideas[i] = other.ideas[i];
            i++;
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
