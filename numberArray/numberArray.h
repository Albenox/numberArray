// numberArray.h
// This file will contain the NumberArray class

// Checks to see if NUMBERARRAY_H has already been defined, and to define it if it has not been already, to ensure it is not defined multiple times
#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

class NumberArray {
private:
    // A default array size in case one is not defined
    static const int MAX_SIZE = 10;

    // Variables that set arrays to have IDs, so they can be identified during printing
    static int arrayCount;
    int arrayID;

    // Dynamic memory size for the array using a pointer for data
    int size;
    double* data;

public:
    // Constructor and Destructor, which holds the code that runs once an object is created and once it is destroyed 
    NumberArray(int s = MAX_SIZE);
    ~NumberArray();

    // Copy constructor that creates a deep copy of another NumberArray object
    NumberArray(const NumberArray& other);
    
    // Assignment operator overload that allows one existing NumberArray object to be assigned to another
    NumberArray& operator=(const NumberArray& other);

    // Mutator function that will set/change a number in the array if the index is valid
    void setNumber(int index, double value);

    // Accessor function that will return a number from the array if the index is valid
    double getNumber(int index) const;

    // Mutator function that fills the array with random decimal numbers between a minimum and maximum value
    void fillRandom(double minValue, double maxValue);

    // Accessor function that returns the smallest number in the array
    double getMin() const;

    // Accessor function that returns the largest number in the array
    double getMax() const;

    // Accessor function that returns the average of all numbers in the array
    double getAverage() const;

    void print() const;
};

#endif