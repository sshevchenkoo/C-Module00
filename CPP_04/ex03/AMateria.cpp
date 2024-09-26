#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
    std::cout << "AMateria constructor call" << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
    std::cout << "AMateria copy constructor call" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria constructor whith type call" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor call" << std::endl;
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Ussing default materia on " << target.getName() << std::endl;
}
