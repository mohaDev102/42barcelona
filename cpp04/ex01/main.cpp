#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
        size_t size = 4;
        Animal  *animals[size];

        std::cout << "-----------------------------------" << std::endl;

        Dog first_dog;
        first_dog.getBrain()->setIdea("Great idea", 0);

        Dog second_dog(first_dog);
        second_dog.getBrain()->setIdea("Second great idea", 0);
        second_dog.getBrain()->setIdea("Second wrong idea", 1);
        second_dog.getBrain()->setIdea("Second good idea", 2);

        std::cout << first_dog.getBrain()->getIdea(0) << std::endl;
        std::cout << first_dog.getBrain()->getIdea(1) << std::endl;
        std::cout << first_dog.getBrain()->getIdea(2) << std::endl;

        std::cout << second_dog.getBrain()->getIdea(0) << std::endl;
        std::cout << second_dog.getBrain()->getIdea(1) << std::endl;
        std::cout << second_dog.getBrain()->getIdea(2) << std::endl;

        std::cout << "-----------------------------------" << std::endl;

        
        for (size_t i = 0; i < size / 2; i++) {
            animals[i] = new Dog();
        }

        for (size_t i = size / 2; i < size; i++) {
            animals[i] = new Cat();
        }

        for (size_t i = 0; i < size; i++) {
            animals[i]->makeSound();
        }

        std::cout << "-----------------------------------" << std::endl;

        for (size_t i = 0; i < size; i++) {
            delete animals[i];
        }

        std::cout << "-----------------------------------" << std::endl;
}