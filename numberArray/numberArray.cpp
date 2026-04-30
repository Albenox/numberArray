// numberArray.cpp
// This file will contain the logic for the methods used in the NumberArray class

#include "numberArray.h"
#include <iostream>
#include <random>
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

// Copy constructor that performs a deep copy of another NumberArray object
NumberArray::NumberArray(const NumberArray& other) {
    // Copies the size from the object being copied
    size = other.size;

    // Gives this copied object its own new array ID
    arrayCount++;
    arrayID = arrayCount;

    // Allocates new memory for this object's own array
    data = new double[size];

    // Copies each value from the other object's array into this object's array
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }

    cout << "Copy constructor called. Number Array " << arrayID << " was created as a copy." << endl;
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

// Mutator function that fills the array with random decimal numbers between a minimum and maximum value
void NumberArray::fillRandom(double minValue, double maxValue) {
    // Generates a random number between the minimum and maximum entered limits which returns better results than just rand()
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> distr(minValue, maxValue);

    for (int i = 0; i < size; i++) {
        data[i] = distr(gen);
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

// Accessor function that returns the smallest number in the array
double NumberArray::getMin() const {
    double min = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }

    return min;
}

// Accessor function that returns the largest number in the array
double NumberArray::getMax() const {
    double max = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    return max;
}

// Accessor function that returns the average of all numbers in the array
double NumberArray::getAverage() const {
    double total = 0.0;

    for (int i = 0; i < size; i++) {
        total += data[i];
    }

    return total / size;
}

// A void function to print all of the array contents
void NumberArray::print() const {
    cout << "Number Array " << arrayID << ": ";

    for (int i = 0; i < size; i++) {
        cout << data[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}