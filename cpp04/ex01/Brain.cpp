#include "Brain.hpp"


Brain::Brain()
{
    this->count = 0;
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        this->count = other.count;
        for (size_t i = 0; i < this->count; i++)
        {
            this->ideas[i] = other.getIdea(i);
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(std::string idea, int index)
{
    if (index >= 0 && index < 100)
    {
        this->count++;
        this->ideas[index] = idea;
    }
}

std::string Brain::getIdea(int index) const
{
   if (index >= 0 && index < 100)
    {
        return ideas[index];
    }
    std::cout << "Invalid idea index" << std::endl;
    return "";
}

Brain* Brain::getBrain()
{
    return (this);
}