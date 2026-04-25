#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // 1. Create a Data object with some values
    Data* myData = new Data;
    myData->s_id = 42;
    myData->s_name = "Gemini Test";
    myData->s_value = 3.14f;

    std::cout << "--- Original Data ---" << std::endl;
    std::cout << "Address: " << myData << std::endl;
    std::cout << "ID:      " << myData->s_id << std::endl;
    std::cout << "Name:    " << myData->s_name << std::endl;
    std::cout << "Value:   " << myData->s_value << std::endl;
    std::cout << "----------------------" << std::endl;

    // 2. Serialize the pointer into a uintptr_t
    uintptr_t raw = Serializer::serialize(myData);
    
    std::cout << "\n--- Serialization ---" << std::endl;
    std::cout << "Raw uintptr_t: " << raw << " (Hex: 0x" << std::hex << raw << std::dec << ")" << std::endl;

    // 3. Deserialize the integer back into a Data pointer
    Data* result = Serializer::deserialize(raw);

    std::cout << "\n--- Deserialization ---" << std::endl;
    std::cout << "Address: " << result << std::endl;
    std::cout << "ID:      " << result->s_id << std::endl;
    std::cout << "Name:    " << result->s_name << std::endl;
    std::cout << "Value:   " << result->s_value << std::endl;
    std::cout << "------------------------" << std::endl;

    // 4. Verification
    std::cout << "\n--- Verification ---" << std::endl;
    if (result == myData) {
        std::cout << "SUCCESS: The pointers are identical!" << std::endl;
    } else {
        std::cout << "FAILURE: The pointers differ!" << std::endl;
    }

    delete myData;
    return 0;
}
