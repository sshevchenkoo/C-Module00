#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if(this != &other)
        this->type = other.type;
    return (*this);
}
Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

/*void    Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}*/

const std::string& Animal::getType() const
{
    return (this->type);
}
