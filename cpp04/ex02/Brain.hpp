#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();
        void setIdea(std::string idea, int index);
        std::string getIdea(int index) const;
        Brain* getBrain();

    private:
        std::string ideas[100];
        size_t      count;
};
#endif