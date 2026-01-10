#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
    IMateriaSource* src = new MateriaSource();
    AMateria* iceTemplate = new Ice();
    AMateria* cureTemplate = new Cure();
    src->learnMateria(iceTemplate);
    src->learnMateria(cureTemplate);
    delete iceTemplate;
    delete cureTemplate;

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    AMateria* tmp1;
    tmp1 = src->createMateria("ice");
    ICharacter* bob = new Character("bob");

    bob->equip(tmp1);

    me->use(0, *bob);
    me->use(1, *bob);
    bob->use(0, *me);

    std::cout << tmp1->getXP() << std::endl;


    delete bob;
    delete me;
    delete src;
    return 0;
}
