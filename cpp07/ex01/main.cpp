#include <iostream>
#include <string>
#include "iter.hpp"

// Regular function to print an element
template <typename T>
void printElement(const T &element) {
    std::cout << element << " ";
}

// Function to increment an integer
void increment(int &element) {
    element += 1;
}

// Function to convert a string to uppercase
void toUpperCase(std::string &element) {
    for (size_t i = 0; i < element.size(); ++i) {
        element[i] = std::toupper(element[i]);
    }
}

int main() {
    // Test with integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArraySize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intArraySize, increment);
    std::cout << "Incremented int array: ";
    iter(intArray, intArraySize, printElement<int>);
    std::cout << std::endl;

    // Test with strings
    std::string strArray[] = {"hello", "world", "iter", "template"};
    size_t strArraySize = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "\nOriginal string array: ";
    iter(strArray, strArraySize, printElement<std::string>);
    std::cout << std::endl;

    iter(strArray, strArraySize, toUpperCase);
    std::cout << "Uppercase string array: ";
    iter(strArray, strArraySize, printElement<std::string>);
    std::cout << std::endl;

    // Test with floats
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f};
    size_t floatArraySize = sizeof(floatArray) / sizeof(floatArray[0]);

    std::cout << "\nOriginal float array: ";
    iter(floatArray, floatArraySize, printElement<float>);
    std::cout << std::endl;

    return 0;
}