// numberArray.cpp
// This file will contain the logic for the methods used in the NumberArray class

#include "NumberArray.h"
#include <iostream>
using namespace std;

// Sets the counter of arrays to 0, which is used to give arrays IDs as they are made
int NumberArray::arrayCount = 0;

// Constructor
NumberArray::NumberArray(int s) {
    size = s;

    // Increases the array count by 1, and gives the object an ID equal to the count
    arrayCount++;
    arrayID = arrayCount;

    // Dynamic array size
    data = new double[size];

    // Populates the array with values of 0.0
    for (int i = 0; i < size; i++) {
        data[i] = 0.0;
    }
}

// Destructor that deletes the array data from the memory to avoid memory leaks
NumberArray::~NumberArray() {
    delete[] data;

    cout << "Destructor called. Memory released." << endl;
}

// Mutator function that sets a value inside the array only if the index is valid
void NumberArray::setNumber(int index, double value) {
    if (index >= 0 && index < size) {
        data[index] = value;
        cout << "Index location " << index << " valid, and has been assigned " << value << "." << endl;
    }
    else {
        cout << "Invalid index location called at " << index << ", input " << value << " cannot be assigned." << endl;
    }
}

// Accessor function that returns a value from the array only if the index is valid
double NumberArray::getNumber(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    else {
        cout << "Failed to get number due to invalid index." << endl;
        return 0.0;
    }
}

// A void function to print all of the array contents
void NumberArray::print() const {
    cout << "Number Array " << arrayCount << ": ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}