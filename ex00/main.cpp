#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    
    const Animal* meta = new Animal();
    const Animal* j    = new Dog();
    const Animal* i    = new Cat();

    std::cout << meta->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();    
    j->makeSound();    
    meta->makeSound(); 


    delete meta;
    delete j;
    delete i;


    const WrongAnimal* wrongBase = new WrongAnimal();
    const WrongAnimal* wrongCatAsBase = new WrongCat();

    std::cout << wrongBase->getType() << std::endl;
    std::cout << wrongCatAsBase->getType() << std::endl;

    wrongBase->makeSound();      
    wrongCatAsBase->makeSound(); 

    delete wrongBase;
    delete wrongCatAsBase;

    return 0;
}
