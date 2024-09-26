#include "IMateriaSource.hpp"


MateriaSource::MateriaSource() : count(0)
{
    for (int i = 0; i < 4; i++)
        materias[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other) : count(other.count)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.materias[i])
            materias[i] = other.materias[i]->clone();
        else
            materias[i] = nullptr;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        count = other.count;
        for (int i = 0; i < 4; i++)
        {
            if (materias[i])
                delete materias[i];
            if (other.materias[i])
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = nullptr;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (materias[i])
            delete materias[i];
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (count < 4 && m)
    {
        materias[count++] = m;
        std::cout << "Materia learned: " << m->getType() << std::endl;
    }
    else
        std::cout << "Cannot learn more materias!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < count; i++)
    {
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    }
    std::cout << "Materia not found: " << type << std::endl;
    return nullptr;
}
