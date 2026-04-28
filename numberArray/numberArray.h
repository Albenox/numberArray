// numberArray.h
// This file will contain the NumberArray class

// Checks to see if NUMBERARRAY_H has already been defined, and to define it if it has not been already, to ensure it is not defined multiple times
#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

class NumberArray {
private:
    // A default array size in case one is not defined
    static const int MAX_SIZE = 10;

    // Dynamic memory size for the array using a pointer for data
    int size;
    double* data;

public:
    // Constructor and Deconstructor
    NumberArray(int s = MAX_SIZE);
    ~NumberArray();

    void print() const;
};

#endif#