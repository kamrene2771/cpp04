#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    
    const Animal* not_defined = new Animal();
    const Animal* dog    = new Dog();
    const Animal* cat    = new Cat();

    std::cout << not_defined->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    not_defined->makeSound(); 
    dog->makeSound();    
    cat->makeSound();    


    delete not_defined;
    delete dog;
    delete cat;

    std::cout << "----------------------------------------------------------" << std::endl;

    WrongAnimal* wrongbase = new WrongAnimal();
    WrongAnimal* wrongcat = new WrongCat();

    std::cout << wrongbase->getType() << std::endl;
    std::cout << wrongcat->getType() << std::endl;

    wrongbase->makeSound();      
    wrongcat->makeSound(); 

    delete wrongbase;
    delete wrongcat;

    return 0;
}
