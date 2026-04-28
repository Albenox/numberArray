// main.cpp
// This file will contain the main() function used to test the NumberArray class and its methods

#include "NumberArray.h"
#include <iostream>
using namespace std;

void printSeperator();

int main() {
    // Objects created by the NumberArray class that then use the print() function to print the stored numbers
    NumberArray numbers1;
    numbers1.print();

    NumberArray numbers2(5);
    numbers2.print();

    printSeperator();

    // Testing setNumber() with valid indexes
    numbers2.setNumber(0, 10.5);
    numbers2.setNumber(2, 25.75);
    numbers2.setNumber(4, 99.9);

    // Printing the array again to confirm the values changed
    numbers2.print();

    printSeperator();

    // Testing getNumber() with valid indexes
    cout << "Number at index 0: " << numbers2.getNumber(0) << endl;
    cout << "Number at index 2: " << numbers2.getNumber(2) << endl;
    cout << "Number at index 4: " << numbers2.getNumber(4) << endl;

    printSeperator();

    // Testing invalid indexes to make sure the program does not crash
    numbers2.setNumber(-1, 50);
    numbers2.setNumber(5, 50);

    printSeperator();

    // Attempts to retrieve numbers from invalid index locations
    cout << "Invalid get test: " << numbers2.getNumber(-1) << endl;
    cout << "Invalid get test: " << numbers2.getNumber(5) << endl;

    printSeperator();

    // Testing the statistical functions with the current values inside numbers2
    cout << "Minimum value: " << numbers2.getMin() << endl;
    cout << "Maximum value: " << numbers2.getMax() << endl;
    cout << "Average value: " << numbers2.getAverage() << endl;

    return 0;
}

// A simple cout print function to make it easier to read the cmd output
void printSeperator() {
    cout << "------------------------------------------" << endl;
}