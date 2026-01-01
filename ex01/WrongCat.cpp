#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    type = "WrongCat";
    std::cout << "[WrongCat] default constructor\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
    std::cout << "[WrongCat] copy constructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "[WrongCat] copy assignment\n";
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "[WrongCat] destructor\n";
}

void WrongCat::makeSound() const {
    std::cout << "Wrong meow?\n";
}
