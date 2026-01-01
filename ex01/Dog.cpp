#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal(), brain(new Brain()) {
    type = "Dog";
    std::cout << "[Dog] default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Dog] copy constructor\n";
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] copy assignment\n";
    if (this != &other) {
        Animal::operator=(other);

        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "[Dog] destructor\n";
    delete brain;
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}

void Dog::setIdea(int idx, const std::string& idea) {
    brain->setIdea(idx, idea);
}

const std::string& Dog::getIdea(int idx) const {
    return brain->getIdea(idx);
}
