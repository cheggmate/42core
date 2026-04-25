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
    src->learnMateria(extra); // Should not be learned 
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
    delete fifth; // Must delete manually as it wasn't equipped 

    std::cout << "\n--- UNEQUIP & DEEP COPY TESTS ---" << std::endl;
    std::cout << "\n--- SAFE UNEQUIP TEST ---" << std::endl;
    // Create and equip a Materia
    AMateria* m1 = src->createMateria("ice");
    me->equip(m1);

    // To avoid a leak, we keep the pointer 'm1' before calling unequip
    me->unequip(0); // This sets the slot to NULL but does NOT delete m1 

    // Now we manually delete the "fallen" Materia to avoid memory leaks 
    if (m1) {
        std::cout << "Manually cleaning up the unequipped " << m1->getType() << std::endl;
        delete m1;
    }

    // Deep Copy Test 
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