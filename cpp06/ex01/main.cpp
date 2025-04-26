
#include "Serializer.hpp"

int main()
{
    Data data;
    data.id = 42;
    data.name = "Test Data";

    // Serialize the Data object
    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    // Deserialize the uintptr_t back to a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Verify that the deserialized pointer matches the original pointer
    if (deserializedData == &data)
    {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Data ID: " << deserializedData->id << std::endl;
        std::cout << "Data Name: " << deserializedData->name << std::endl;
    }
    else
    {
        std::cout << "Deserialization failed!" << std::endl;
    }

    return 0;
}