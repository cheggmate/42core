#include "ShrubberyCreationForm.hpp"

// Initialize with required grades: sign 145, exec 137 
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        (void)other; // Attributes are mostly const or handled by AForm
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    // Creates a file <target>_shrubbery in the working directory 
    std::string filename = this->_target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if (!outfile.is_open()) {
        std::cerr << "Error: Could not create file " << filename << std::endl;
        return;
    }

    // Writes ASCII trees inside it 
    outfile << "      /\\      " << std::endl;
    outfile << "     /\\*\\     " << std::endl;
    outfile << "    /\\O\\*\\    " << std::endl;
    outfile << "   /*/\\/\\/\\   " << std::endl;
    outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
    outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << std::endl;
    outfile << "      /\\      " << std::endl;
    outfile << "     /  \\     " << std::endl;
    outfile << "    /    \\    " << std::endl;
    outfile << "   /      \\   " << std::endl;
    outfile << "  /________\\  " << std::endl;
    outfile << "      ||      " << std::endl;

    outfile.close();
}
