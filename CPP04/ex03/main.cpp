#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    std::cout << "--- SUBJECT TESTS ---" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    std::cout << "\n--- INVENTORY FULL & UNKNOWN MATERIA TESTS ---" << std::endl;
    // Attempting to learn more than 4 materias
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    AMateria* extra = new Ice();
    src->learnMateria(extra); // Should not be learned [cite: 267]
    delete extra; // Clean up manually as src didn't take ownership

    // Creating unknown materia
    AMateria* unknown = src->createMateria("fire");
    if (unknown == NULL)
        std::cout << "Successfully handled unknown materia type 'fire'" << std::endl;

    // Filling inventory
    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    
    // Attempting to equip 5th materia 
    AMateria* fifth = src->createMateria("ice");
    me->equip(fifth); 
    delete fifth; // Must delete manually as it wasn't equipped [cite: 245]

    std::cout << "\n--- UNEQUIP & DEEP COPY TESTS ---" << std::endl;
    // Test unequip without leaking 
    AMateria* floor = NULL;
    // Note: You must save the pointer before unequipping to delete it later
    // In a real implementation, you'd likely use an array or linked list for "grounded" items
    // This is a simple manual check for slot 0
    // floor = ((Character*)me)->getMateria(0); // If you added a getter for testing
    // me->unequip(0);
    // delete floor;

    // Deep Copy Test [cite: 253, 254]
    Character* original = new Character("Original");
    original->equip(src->createMateria("ice"));
    
    Character* copy = new Character(*original);
    std::cout << "Copy name: " << copy->getName() << std::endl;
    
    delete original;
    std::cout << "Using copy after deleting original (Deep Copy Check):" << std::endl;
    copy->use(0, *bob);

    std::cout << "\n--- CLEANUP ---" << std::endl;
    delete bob;
    delete me;
    delete src;
    delete copy;

    return 0;
}