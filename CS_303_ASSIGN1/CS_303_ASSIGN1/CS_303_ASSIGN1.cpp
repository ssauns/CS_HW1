// CS_303_ASSIGN1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream> //For input file
#include "array_functions.h"  //For header file


const int MAX_SIZE = 100; //maximum size of array

// Function to find the integer in the array
int findInteger(int arr[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {       
			return i;
		}
	}
	return -1;
}

// Function to modify value of integer
std::pair<int, int> modifyValue(int arr[], int size, int index, int newValue) {
	if (index < 0 || index >= size) {
		std::cerr << "Index out of range" << std::endl;
		return { -1, -1 };
	}
	int oldValue = arr[index];
	arr[index] = newValue;
	return { oldValue, newValue };
}
// Function to add new integer to end of array
void addInteger(int arr[], int& size, int newValue) {
	if (size >= MAX_SIZE) {
		std::cerr << "Array is full" << std::endl;
		return;
	}
	arr[size] = newValue;
	size++;
}
// Function to replace value with a zero
void replaceWithZero(int arr[], int size, int index) {
	if (index < 0 || index >= size) {
		std::cerr << "Index out of range" << std::endl;
		return;
	}
	arr[index] = 0;
}

int main() {
	std::ifstream inputFile("A1input.txt");  //opens file
	if (!inputFile) {
		std::cerr << " Error opening file";
		exit(1); // terminates with error
	}

	const int MAX_SIZE = 100;
	int myArray[MAX_SIZE];
	int i = 0;

	while (inputFile >> myArray[i] && i < MAX_SIZE) {
		i++;
	}

	inputFile.close();    //close file

	//Using Function to find the integer in the array
	int target = 27; // Random number to find in array
	int index = findInteger(myArray, i, target);
	if (index != -1) {
		std::cout << "Integer found at index " << index << std::endl;
	}
	else {
		std::cout << "Integer not found in the array" << std::endl;
	}
	
	//Using Function to modify integer in the array
	index = 5;    //random index to modify
	int newValue = 40; // new value 
	std::pair<int, int> result = modifyValue(myArray, i, index, newValue);
	if (result.first != -1) {
		std::cout << "Old value: " << result.first << ", New value: " << result.second << std::endl;
	}
	
	// Using the add Integer function
	newValue = 30; 
	addInteger(myArray, i, newValue);
	if (i < MAX_SIZE) {
		std::cout << "New value added to the end of the array: " << myArray[i - 1] << std::endl;
	}

	//Using the replacement function with a zero
	index = 70; 
	replaceWithZero(myArray, i, index);
	if (index < i) {
		std::cout << "Value at index " << index << " replaced with 0" << std::endl;
	}
	return 0;
}




 
	



