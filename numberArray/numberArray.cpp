// numberArray.cpp
// This file will contain the logic for the methods used in the NumberArray class

#include "NumberArray.h"
#include <iostream>
using namespace std;

NumberArray::NumberArray(int s) {
    size = s;

    data = new double[size];

    // Populates the array
    for (int i = 0; i < size; i++) {
        data[i] = 0.0;
    }
}

NumberArray::~NumberArray() {
    delete[] data;

    cout << "Destructor called. Memory released." << endl;
}

void NumberArray::print() const {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}