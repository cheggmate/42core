#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "========== CONSTITUTION CHAINING ==========" << std::endl;
    // Should show ClapTrap constructed, then FragTrap [cite: 180]
    FragTrap frag("Fraggy");

    std::cout << "\n========== ATTRIBUTE TESTING ==========" << std::endl;
    // FragTrap has 30 Attack Damage [cite: 185]
    frag.attack("a training dummy"); 
    frag.takeDamage(50);
    frag.beRepaired(20);

    std::cout << "\n========== UNIQUE ABILITY ==========" << std::endl;
    // FragTrap's special high-five request [cite: 187]
    frag.highFivesGuys();

    std::cout << "\n========== ENERGY CAPACITY TEST ==========" << std::endl;
    // FragTrap has 100 energy[cite: 184]. 
    // It should be able to attack far more than ScavTrap.
    for (int i = 0; i < 5; i++) {
        frag.attack("the target");
    }

    std::cout << "\n========== DESTRUCTION CHAINING ==========" << std::endl;
    // Should show FragTrap destroyed, then ClapTrap [cite: 180]
    return 0;
}