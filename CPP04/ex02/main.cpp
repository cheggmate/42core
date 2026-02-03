#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== Basic polymorphism test =====" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    delete j; // should call Dog destructor, then Brain, then Animal
    delete i; // should call Cat destructor, then Brain, then Animal

    std::cout << "\n===== Array of Animals test =====" << std::endl;

    const int size = 10;
    AAnimal* animals[size];

    for (int k = 0; k < size; k++)
    {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    std::cout << "\n===== Deleting animals =====" << std::endl;
    for (int k = 0; k < size; k++)
        delete animals[k]; // must call correct destructors

    std::cout << "\n===== Deep copy test =====" << std::endl;

    Dog original;
    original.getBrain()->ideas[0] = "Chase the cat";

    Dog copy(original); // copy constructor
    copy.getBrain()->ideas[0] = "Eat food";

    std::cout << "Original idea: "
              << original.getBrain()->ideas[0] << std::endl;
    std::cout << "Copy idea: "
              << copy.getBrain()->ideas[0] << std::endl;

    std::cout << "\n===== Assignment operator test =====" << std::endl;

    Dog assigned;
    assigned = original;
    assigned.getBrain()->ideas[0] = "Sleep";

    std::cout << "Original idea after assignment: "
              << original.getBrain()->ideas[0] << std::endl;
    std::cout << "Assigned idea: "
              << assigned.getBrain()->ideas[0] << std::endl;

    std::cout << "\n===== End of program =====" << std::endl;
    return 0;
}
