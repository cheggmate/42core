#include "ScavTrap.hpp"

int main() {
    std::cout << "========== CONSTITUTION CHAINING ==========" << std::endl;
    // This should show ClapTrap being built first, then ScavTrap 
    ScavTrap scav("Scavvy");

    std::cout << "\n========== ATTRIBUTE TESTING ==========" << std::endl;
    scav.attack("a training dummy"); // Should use ScavTrap's 20 damage 
    scav.takeDamage(30);
    scav.beRepaired(20);

    std::cout << "\n========== UNIQUE ABILITY ==========" << std::endl;
    scav.guardGate(); // Specific ScavTrap function 

    std::cout << "\n========== ENERGY DEPLETION ==========" << std::endl;
    // ScavTrap has 50 energy 
    for (int i = 0; i < 51; i++) {
        scav.attack("target");
    }

    std::cout << "\n========== DESTRUCTION CHAINING ==========" << std::endl;
    // This should show ScavTrap destroyed first, then ClapTrap 
    return 0;
}
