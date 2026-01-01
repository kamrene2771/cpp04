#include "Cat.hpp"

Cat::Cat() : AAnimal(), brain(new Brain())
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(0)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int idx, const std::string& idea)
{
    if (this->brain)
        this->brain->setIdea(idx, idea);
}

std::string Cat::getIdea(int idx) const
{
    if (!this->brain)
        return "";
    return this->brain->getIdea(idx);
}
