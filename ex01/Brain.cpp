#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "[Brain] default constructor\n";
}

Brain::Brain(const Brain& other) {
    std::cout << "[Brain] copy constructor\n";
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "[Brain] copy assignment\n";
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "[Brain] destructor\n";
}

void Brain::setIdea(int idx, const std::string& idea) {
    if (idx < 0 || idx >= 100)
        return;
    ideas[idx] = idea;
}

const std::string& Brain::getIdea(int idx) const {
    static const std::string empty = "";
    if (idx < 0 || idx >= 100)
        return empty;
    return ideas[idx];
}
