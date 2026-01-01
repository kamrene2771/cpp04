#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] default constructor\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] copy constructor\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] copy assignment\n";
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] destructor\n";
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "* generic animal sound *\n";
}
