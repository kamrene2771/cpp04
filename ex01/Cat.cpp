#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain()) {
    type = "Cat";
    std::cout << "[Cat] default constructor\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) {
    std::cout << "[Cat] copy constructor\n";
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] copy assignment\n";
    if (this != &other) {
        Animal::operator=(other);

        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] destructor\n";
    delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}

void Cat::setIdea(int idx, const std::string& idea) {
    brain->setIdea(idx, idea);
}

const std::string& Cat::getIdea(int idx) const {
    return brain->getIdea(idx);
}
