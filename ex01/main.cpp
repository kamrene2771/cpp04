#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

static void polymorphism_basic_test() {
    std::cout << "\n=== Polymorphism basic test ===\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << "\n";
    std::cout << i->getType() << "\n";

    i->makeSound();
    j->makeSound();

    delete j;
    delete i;
}

static void wrong_polymorphism_test() {
    std::cout << "\n=== Wrong polymorphism test ===\n";
    const WrongAnimal* w = new WrongCat();
    std::cout << w->getType() << "\n";
    w->makeSound(); // will call WrongAnimal::makeSound because it's NOT virtual
    delete w;
}

static void array_delete_test() {
    std::cout << "\n=== Array delete-as-Animal test ===\n";
    const int N = 10;
    Animal* animals[N];

    for (int i = 0; i < N; ++i) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < N; ++i) {
        delete animals[i]; // must call derived destructors correctly
    }
}

static void deep_copy_test() {
    std::cout << "\n=== Deep copy test ===\n";

    Dog a;
    a.setIdea(0, "I want a bone");
    Dog b(a); // copy constructor (deep copy)

    a.setIdea(0, "I changed my mind");

    std::cout << "Dog a idea[0]: " << a.getIdea(0) << "\n";
    std::cout << "Dog b idea[0]: " << b.getIdea(0) << "\n";

    Cat c;
    c.setIdea(1, "I want tuna");

    Cat d;
    d = c; // assignment (deep copy)
    c.setIdea(1, "Actually, nap time");

    std::cout << "Cat c idea[1]: " << c.getIdea(1) << "\n";
    std::cout << "Cat d idea[1]: " << d.getIdea(1) << "\n";
}

int main() {
    polymorphism_basic_test();
    wrong_polymorphism_test();
    array_delete_test();
    deep_copy_test();

    std::cout << "\n(Use valgrind/leaks checker to confirm no leaks.)\n";
    return 0;
}
