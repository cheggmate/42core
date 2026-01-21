#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "========== 1. THE DIAMOND CONSTRUCTION ==========" << std::endl;
    // Look closely at the output order: 
    // ClapTrap should ONLY be called ONCE.
    DiamondTrap diamond("D-MON");

    std::cout << "\n========== 2. IDENTITY CHECK ==========" << std::endl;
    // Should show the DiamondTrap name and the ClapTrap name with suffix
    diamond.whoAmI();

    std::cout << "\n========== 3. HYBRID ATTRIBUTES ==========" << std::endl;
    // Damage should be 30 (from FragTrap)
    // attack() logic should be from ScavTrap
    diamond.attack("an unsuspecting target");
    
    // HP should be 100 (from FragTrap)
    diamond.takeDamage(90);
    
    // Energy should be 50 (from ScavTrap)
    diamond.beRepaired(10);

    std::cout << "\n========== 4. INHERITED ABILITIES ==========" << std::endl;
    diamond.guardGate();      // Inherited from ScavTrap
    diamond.highFivesGuys();  // Inherited from FragTrap

    std::cout << "\n========== 5. DESTRUCTION CHAINING ==========" << std::endl;
    // Should destroy in reverse order: Diamond -> Frag -> Scav -> Clap
    return 0;
}