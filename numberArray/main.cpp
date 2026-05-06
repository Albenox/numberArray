// main.cpp
// This file will contain the main() function used to test the NumberArray class and its methods

#include "numberArray.h"
#include <iostream>
using namespace std;

void printSeperator();

int main() {
    // Objects created by the NumberArray class that then use the print() function to print the stored numbers
    NumberArray numbers1;
    numbers1.print();

    printSeperator();
    
    NumberArray numbers2(5);
    numbers2.print();

    cout << endl;

    // Testing setNumber() with valid indexes
    numbers2.setNumber(0, 10.5);
    numbers2.setNumber(2, 25.75);
    numbers2.setNumber(4, 99.9);

    // Printing the array again to confirm the values changed
    numbers2.print();

    cout << endl;

    // Testing getNumber() with valid indexes
    cout << "Number at index 0: " << numbers2.getNumber(0) << endl;
    cout << "Number at index 2: " << numbers2.getNumber(2) << endl;
    cout << "Number at index 4: " << numbers2.getNumber(4) << endl;

    cout << endl;

    // Testing invalid indexes to make sure the program does not crash
    numbers2.setNumber(-1, 50);
    numbers2.setNumber(5, 50);

    cout << endl;

    // Attempts to retrieve numbers from invalid index locations
    cout << "Invalid get test: " << numbers2.getNumber(-1) << endl;
    cout << "Invalid get test: " << numbers2.getNumber(5) << endl;

    cout << endl;

    // Testing the statistical functions with the current values inside numbers2
    cout << "Minimum value: " << numbers2.getMin() << endl;
    cout << "Maximum value: " << numbers2.getMax() << endl;
    cout << "Average value: " << numbers2.getAverage() << endl;

    printSeperator();

    // Testing random values inside a new NumberArray object
    NumberArray randomNumbers(10);

    randomNumbers.fillRandom(1.0, 100.0);

    cout << "Randomly filled array:" << endl;
    randomNumbers.print();

    cout << "Minimum random value: " << randomNumbers.getMin() << endl;
    cout << "Maximum random value: " << randomNumbers.getMax() << endl;
    cout << "Average random value: " << randomNumbers.getAverage() << endl;

    printSeperator();

    // Testing an edge case where the array only has one element
    NumberArray oneNumber(1);

    oneNumber.setNumber(0, -3.5);
    oneNumber.print();

    cout << "Minimum value: " << oneNumber.getMin() << endl;
    cout << "Maximum value: " << oneNumber.getMax() << endl;
    cout << "Average value: " << oneNumber.getAverage() << endl;

    printSeperator();
    
    // Testing destructor behavior inside a block scope
    {
        NumberArray temp(5);
        temp.print();
    }

    cout << "The temporary array above should have already called its destructor." << endl;

    printSeperator();

    // Copy constructor testing
    cout << "Copy Constructor Test:" << endl;

    NumberArray original(5);
    original.setNumber(0, 10);
    original.setNumber(1, 20);
    original.setNumber(2, 30);

    cout << "Original array before copy:" << endl;
    original.print();

    // This creates a new object by copying original
    NumberArray copiedArray(original);

    cout << "Copied array after copy constructor:" << endl;
    copiedArray.print();

    // Change original after copying to prove copiedArray has its own memory
    original.setNumber(0, 999);

    cout << "Original array after being changed:" << endl;
    original.print();

    cout << "Copied array should stay the same:" << endl;
    copiedArray.print();

    printSeperator();

    // Assignment operator testing
    cout << "Assignment Operator Test:" << endl;

    NumberArray sourceArray(5);
    sourceArray.setNumber(0, 11);
    sourceArray.setNumber(1, 22);
    sourceArray.setNumber(2, 33);

    NumberArray assignedArray(3);

    cout << "Source array before assignment:" << endl;
    sourceArray.print();

    cout << "Assigned array before assignment:" << endl;
    assignedArray.print();

    // This copies sourceArray into an already existing object
    assignedArray = sourceArray;

    cout << "Assigned array after assignment:" << endl;
    assignedArray.print();

    // Change sourceArray after assignment to prove assignedArray has its own memory
    sourceArray.setNumber(0, 888);

    cout << "Source array after being changed:" << endl;
    sourceArray.print();

    cout << "Assigned array should stay the same:" << endl;
    assignedArray.print();

    printSeperator();

    cout << "Self-Assignment Test:" << endl;

    assignedArray = assignedArray;

    cout << "Assigned array after assigning it to itself:" << endl;
    assignedArray.print();

    printSeperator();

    return 0;
}

// A simple cout print function to make it easier to read the cmd output
void printSeperator() {
    cout << "------------------------------------------" << endl;
}