#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type)
: _type(type), _xp(0)
{
}

AMateria::AMateria(const AMateria& other)
: _type(other._type), _xp(other._xp)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
    {
        // Copying the type doesn't make sense on assignment (keep current _type)
        this->_xp = other._xp;
    }
    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

unsigned int AMateria::getXP() const
{
    return this->_xp;
}

void AMateria::use(ICharacter& /*target*/)
{
    this->_xp += 10;
}
