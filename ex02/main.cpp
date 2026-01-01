#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

static void deepCopyTest()
{
    std::cout << "\n--- Deep copy test (Dog) ---" << std::endl;

    Dog a;
    a.setIdea(0, "I want a bone.");

    Dog b(a); // copy ctor
    a.setIdea(0, "I changed my mind.");

    std::cout << "a idea[0] = " << a.getIdea(0) << std::endl;
    std::cout << "b idea[0] = " << b.getIdea(0) << std::endl;

    std::cout << "\n--- Deep copy test (Cat) ---" << std::endl;

    Cat c;
    c.setIdea(0, "I will ignore you.");

    Cat d;
    d = c; // assignment
    c.setIdea(0, "Actually, feed me.");

    std::cout << "c idea[0] = " << c.getIdea(0) << std::endl;
    std::cout << "d idea[0] = " << d.getIdea(0) << std::endl;
}

int main()
{
    // AAnimal x; // ERROR: cannot instantiate abstract class

    std::cout << "--- Polymorphism test ---" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();

    delete j;
    delete i;

    std::cout << "\n--- Array test ---" << std::endl;
    AAnimal* animals[10];

    for (int k = 0; k < 5; ++k)
        animals[k] = new Dog();
    for (int k = 5; k < 10; ++k)
        animals[k] = new Cat();

    for (int k = 0; k < 10; ++k)
        delete animals[k];

    deepCopyTest();

    std::cout << "\n--- WrongAnimal test ---" << std::endl;
    const WrongAnimal* wa = new WrongCat();
    std::cout << wa->getType() << std::endl;
    wa->makeSound(); // will call WrongAnimal::makeSound because it's NOT virtual
    delete wa;

    return 0;
}
