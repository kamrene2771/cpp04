#include "Character.hpp"

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; ++i)
        _inv[i] = 0;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < 4; ++i)
        _inv[i] = 0;
    copyFrom(other);
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        clearInventory();
        _name = other._name;
        copyFrom(other);
    }
    return *this;
}

Character::~Character()
{
    clearInventory();
}

void Character::clearInventory()
{
    for (int i = 0; i < 4; ++i)
    {
        delete _inv[i];
        _inv[i] = 0;
    }
}

void Character::copyFrom(const Character& other)
{
    for (int i = 0; i < 4; ++i)
    {
        if (other._inv[i])
            _inv[i] = other._inv[i]->clone();
        else
            _inv[i] = 0;
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i)
    {
        if (_inv[i] == 0)
        {
            _inv[i] = m;
            return;
        }
    }
    // inventory full -> nothing happens
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return;
    if (_inv[idx] == 0)
        return;

    // MUST NOT delete the Materia (ownership goes back to caller)
    _inv[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (_inv[idx] == 0)
        return;

    _inv[idx]->use(target);
}
