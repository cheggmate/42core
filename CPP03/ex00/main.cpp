#include "ClapTrap.hpp"

int main() {
    std::cout << "--- Initializing Tests ---" << std::endl;
    // Test construction and name initialization 
    ClapTrap clap("CLP-42");
    ClapTrap anonymous("CL-TP");

    std::cout << "\n--- Action Tests ---" << std::endl;
    // Test attack (Costs 1 energy) 
    clap.attack("Target-Dummy");

    // Test taking damage
    clap.takeDamage(5);

    // Test repairing (Costs 1 energy, regains HP) 
    clap.beRepaired(3);

    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    // ClapTrap starts with 10 Energy 
    // We already used 2 (attack + repair). Using the remaining 8.
    for (int i = 0; i < 9; ++i) {
        std::cout << "[" << i + 1 << "] ";
        clap.attack("the air");
    }

    std::cout << "\n--- Death Test ---" << std::endl;
    // Test behavior when Hit Points reach 0 
    anonymous.takeDamage(10);
    anonymous.attack("anything"); // Should fail: no HP left
    anonymous.beRepaired(5);      // Should fail: no HP left

    std::cout << "\n--- Destruction Phase ---" << std::endl;
    // Destructor messages will print as objects go out of scope 
    return 0;
}
