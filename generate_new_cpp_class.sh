#!/bin/bash

CLASS_NAME=$1

if [ -z "$CLASS_NAME" ]; then
    echo "Usage: ./generate_new_cpp_class.sh <ClassName>"
    exit 1
fi

UPPER_NAME=$(echo $CLASS_NAME | tr '[:lower:]' '[:upper:]')

# --- Generate HPP ---
cat <<EOF > ${CLASS_NAME}.hpp
#ifndef ${UPPER_NAME}_HPP
# define ${UPPER_NAME}_HPP

# include <iostream>

class ${CLASS_NAME} {
public:
    ${CLASS_NAME}();                             // Default Constructor
    ${CLASS_NAME}(const ${CLASS_NAME}& other);    // Copy Constructor
    ${CLASS_NAME}& operator=(const ${CLASS_NAME}& other); // Assignment Operator
    ~${CLASS_NAME}();                            // Destructor

private:
};

#endif
EOF

# --- Generate CPP ---
cat <<EOF > ${CLASS_NAME}.cpp
#include "${CLASS_NAME}.hpp"

${CLASS_NAME}::${CLASS_NAME}() {
    std::cout << "${CLASS_NAME} default constructor called" << std::endl;
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) {
    std::cout << "${CLASS_NAME} copy constructor called" << std::endl;
    *this = other;
}

${CLASS_NAME}& ${CLASS_NAME}::operator=(const ${CLASS_NAME}& other) {
    std::cout << "${CLASS_NAME} assignment operator called" << std::endl;
    if (this != &other) {
        // Copy members here
    }
    return *this;
}

${CLASS_NAME}::~${CLASS_NAME}() {
    std::cout << "${CLASS_NAME} destructor called" << std::endl;
}
EOF

echo "Generated ${CLASS_NAME}.hpp and ${CLASS_NAME}.cpp"