#include "Dog.hpp"

Dog::Dog() : AAnimal(), brain(new Brain())
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(0)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea)
{
    if (this->brain)
        this->brain->setIdea(idx, idea);
}

std::string Dog::getIdea(int idx) const
{
    if (!this->brain)
        return "";
    return this->brain->getIdea(idx);
}
