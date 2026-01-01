#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        _templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
        _templates[i] = 0;
    copyFrom(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        clearTemplates();
        copyFrom(other);
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    clearTemplates();
}

void MateriaSource::clearTemplates()
{
    for (int i = 0; i < 4; ++i)
    {
        delete _templates[i];
        _templates[i] = 0;
    }
}

void MateriaSource::copyFrom(const MateriaSource& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._templates[i])
            _templates[i] = other._templates[i]->clone();
        else
            _templates[i] = 0;
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] == 0)
        {
            _templates[i] = m->clone(); // store a copy (template)
            delete m;                   // avoid leaking the passed materia from example usage
            return;
        }
    }
    // full -> nothing happens, but we still delete to avoid leaking "new Ice()" passed in
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return 0;
}
