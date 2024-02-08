#include <iostream>
#include <fstream>
#include "array_functions.h"  //For header file

void tryModifyValue(int arr[], int& size, int index, int newValue) {
    try {
        std::pair<int, int> result = modifyValue(arr, size, index, newValue);
        std::cout << "Old value: " << result.first << ", New value: " << result.second << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
}