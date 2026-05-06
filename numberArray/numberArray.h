// numberArray.h
// This file will contain the NumberArray template class

#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>
#include <random>
using namespace std;

template <typename T>
class NumberArray {
private:
    // A default array size in case one is not defined
    static const int MAX_SIZE = 10;

    // Variables that set arrays to have IDs, so they can be identified during printing
    static int arrayCount;
    int arrayID;

    // Dynamic memory size for the array using a pointer for data
    int size;
    T* data;

public:
    // Constructor and Destructor, which holds the code that runs once an object is created and once it is destroyed
    NumberArray(int s = MAX_SIZE);
    ~NumberArray();

    // Copy constructor that creates a deep copy of another NumberArray object
    NumberArray(const NumberArray<T>& other);

    // Assignment operator overload that allows one existing NumberArray object to be assigned to another
    NumberArray<T>& operator=(const NumberArray<T>& other);

    // Mutator function that will set/change a number in the array if the index is valid
    void setNumber(int index, T value);

    // Accessor function that will return a number from the array if the index is valid
    T getNumber(int index) const;

    // Mutator function that fills the array with random numbers between a minimum and maximum value
    void fillRandom(T minValue, T maxValue);

    // Accessor function that returns the smallest number in the array
    T getMin() const;

    // Accessor function that returns the largest number in the array
    T getMax() const;

    // Accessor function that returns the average of all numbers in the array
    double getAverage() const;

    void print() const;
};

// Sets the counter of arrays to 0, which is used to give arrays IDs as they are made
template <typename T>
int NumberArray<T>::arrayCount = 0;

// Constructor
template <typename T>
NumberArray<T>::NumberArray(int s) {
    size = s;

    // Increases the array count by 1, and gives the object an ID equal to the count
    arrayCount++;
    arrayID = arrayCount;

    // Dynamic array size
    data = new T[size];

    // Populates the array with values of 0
    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

// Destructor that deletes the array data from the memory to avoid memory leaks
template <typename T>
NumberArray<T>::~NumberArray() {
    delete[] data;

    cout << "Destructor called. Memory released." << endl;
}

// Mutator function that sets a value inside the array only if the index is valid
template <typename T>
void NumberArray<T>::setNumber(int index, T value) {
    if (index >= 0 && index < size) {
        data[index] = value;
        cout << "Index location " << index << " valid, and has been assigned " << value << "." << endl;
    }
    else {
        cout << "Invalid index location called at " << index << ", input " << value << " cannot be assigned." << endl;
    }
}

// Accessor function that returns a value from the array only if the index is valid
template <typename T>
T NumberArray<T>::getNumber(int index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    else {
        cout << "Failed to get number due to invalid index." << endl;
        return 0;
    }
}

// Accessor function that returns the smallest number in the array
template <typename T>
T NumberArray<T>::getMin() const {
    T min = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] < min) {
            min = data[i];
        }
    }

    return min;
}

// Accessor function that returns the largest number in the array
template <typename T>
T NumberArray<T>::getMax() const {
    T max = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    return max;
}

// Accessor function that returns the average of all numbers in the array
template <typename T>
double NumberArray<T>::getAverage() const {
    double total = 0.0;

    for (int i = 0; i < size; i++) {
        total += data[i];
    }

    return total / size;
}

// A void function to print all of the array contents
template <typename T>
void NumberArray<T>::print() const {
    cout << "Number Array " << arrayID << ": ";

    for (int i = 0; i < size; i++) {
        cout << data[i];

        if (i < size - 1) {
            cout << ", ";
        }
    }

    cout << endl;
}

#endif