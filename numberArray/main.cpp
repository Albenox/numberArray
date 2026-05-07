// main.cpp
// This file will contain the main() function used to test the NumberArray template class and its methods

#include "numberArray.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Function prototype for a simple separator line used to improve cmd readability
void printSeperator();

int main() {

    // --------------------------------------------------
    // Testing the NumberArray template class with int
    // --------------------------------------------------

    cout << "Testing NumberArray<int>" << endl;

    // Creates an integer array object with a size of 5
    NumberArray<int> intNumbers(5);

    // Assigns values into the integer array using valid indexes
    intNumbers.setNumber(0, 10);
    intNumbers.setNumber(1, 20);
    intNumbers.setNumber(2, 30);
    intNumbers.setNumber(3, 40);
    intNumbers.setNumber(4, 50);

    // Prints all values currently stored inside the integer array
    intNumbers.print();

    cout << endl;

    // Retrieves and prints values from several valid indexes
    cout << "Number at index 0: " << intNumbers.getNumber(0) << endl;
    cout << "Number at index 2: " << intNumbers.getNumber(2) << endl;
    cout << "Number at index 4: " << intNumbers.getNumber(4) << endl;

    cout << endl;

    // Tests the statistical functions for the integer array
    cout << "Minimum int value: " << intNumbers.getMin() << endl;
    cout << "Maximum int value: " << intNumbers.getMax() << endl;
    cout << "Average int value: " << intNumbers.getAverage() << endl;

    printSeperator();

    // --------------------------------------------------
    // Testing the NumberArray template class with double
    // --------------------------------------------------

    cout << "Testing NumberArray<double>" << endl;

    // Creates a decimal array object with a size of 5
    NumberArray<double> doubleNumbers(5);

    // Assigns decimal values into the array
    doubleNumbers.setNumber(0, 10.5);
    doubleNumbers.setNumber(1, 20.75);
    doubleNumbers.setNumber(2, 30.25);
    doubleNumbers.setNumber(3, 40.5);
    doubleNumbers.setNumber(4, 50.75);

    // Prints all decimal values currently stored inside the array
    doubleNumbers.print();

    cout << endl;

    // Retrieves and prints decimal values from several valid indexes
    cout << "Number at index 0: " << doubleNumbers.getNumber(0) << endl;
    cout << "Number at index 2: " << doubleNumbers.getNumber(2) << endl;
    cout << "Number at index 4: " << doubleNumbers.getNumber(4) << endl;

    cout << endl;

    // Tests the statistical functions for the decimal array
    cout << "Minimum double value: " << doubleNumbers.getMin() << endl;
    cout << "Maximum double value: " << doubleNumbers.getMax() << endl;
    cout << "Average double value: " << doubleNumbers.getAverage() << endl;

    printSeperator();

    // --------------------------------------------------
    // Testing exception handling for invalid indexes
    // --------------------------------------------------

    cout << "Exception Handling Test" << endl;

    // Tries to store a value at an invalid negative index
    try {
        intNumbers.setNumber(-1, 999);
    }
    catch (const out_of_range& e) {
        cout << "Caught exception from setNumber(): " << e.what() << endl;
    }

    // Tries to get a value from an invalid index past the end of the array
    try {
        cout << intNumbers.getNumber(5) << endl;
    }
    catch (const out_of_range& e) {
        cout << "Caught exception from getNumber(): " << e.what() << endl;
    }

    // This line proves the program keeps running after catching exceptions
    cout << "Program continued after exception tests." << endl;

    printSeperator();

    // --------------------------------------------------
    // Testing randomly generated integer values
    // --------------------------------------------------

    cout << "Testing random integer values" << endl;

    // Creates an integer array that will be filled with random values
    NumberArray<int> randomInts(5);

    // Fills the array with random integers between 1 and 100
    randomInts.fillRandom(1, 100);

    // Prints the randomly generated values
    randomInts.print();

    cout << endl;

    // Tests statistical calculations on the random integer array
    cout << "Minimum random int value: " << randomInts.getMin() << endl;
    cout << "Maximum random int value: " << randomInts.getMax() << endl;
    cout << "Average random int value: " << randomInts.getAverage() << endl;

    printSeperator();

    // --------------------------------------------------
    // Testing randomly generated double values
    // --------------------------------------------------

    cout << "Testing random double values" << endl;

    // Creates a decimal array that will be filled with random values
    NumberArray<double> randomDoubles(5);

    // Fills the array with random decimal values between 1.0 and 100.0
    randomDoubles.fillRandom(1.0, 100.0);

    // Prints the randomly generated decimal values
    randomDoubles.print();

    cout << endl;

    // Tests statistical calculations on the random decimal array
    cout << "Minimum random double value: " << randomDoubles.getMin() << endl;
    cout << "Maximum random double value: " << randomDoubles.getMax() << endl;
    cout << "Average random double value: " << randomDoubles.getAverage() << endl;

    printSeperator();

    // --------------------------------------------------
    // Testing the copy constructor
    // --------------------------------------------------

    cout << "Copy Constructor Test with NumberArray<int>" << endl;

    // Creates a new object by copying the intNumbers object
    NumberArray<int> copiedInts(intNumbers);

    cout << "Original int array:" << endl;
    intNumbers.print();

    cout << "Copied int array:" << endl;
    copiedInts.print();

    cout << endl;

    // Changes the original array after copying to confirm deep copying
    intNumbers.setNumber(0, 999);

    cout << "Original int array after being changed:" << endl;
    intNumbers.print();

    // If deep copying worked correctly, copiedInts should not change
    cout << "Copied int array should stay the same:" << endl;
    copiedInts.print();

    printSeperator();

    // --------------------------------------------------
    // Testing the assignment operator
    // --------------------------------------------------

    cout << "Assignment Operator Test with NumberArray<double>" << endl;

    // Creates another decimal array object with a different size
    NumberArray<double> assignedDoubles(3);

    cout << "Original double array before assignment:" << endl;
    doubleNumbers.print();

    cout << "Assigned double array before assignment:" << endl;
    assignedDoubles.print();

    // Assigns one existing object to another existing object
    assignedDoubles = doubleNumbers;

    cout << "Assigned double array after assignment:" << endl;
    assignedDoubles.print();

    cout << endl;

    // Changes the original object after assignment
    doubleNumbers.setNumber(0, 888.88);

    cout << "Original double array after being changed:" << endl;
    doubleNumbers.print();

    // If deep copying worked correctly, assignedDoubles should not change
    cout << "Assigned double array should stay the same:" << endl;
    assignedDoubles.print();

    printSeperator();

    // --------------------------------------------------
    // Testing self-assignment protection
    // --------------------------------------------------

    cout << "Self-Assignment Test" << endl;

    // Assigns the object to itself to verify the program handles it safely
    assignedDoubles = assignedDoubles;

    cout << "Assigned double array after assigning it to itself:" << endl;
    assignedDoubles.print();

    printSeperator();

    // --------------------------------------------------
    // Testing destructor execution inside a block scope
    // --------------------------------------------------

    cout << "Destructor Block Scope Test" << endl;

    // Creates a temporary object inside a block scope
    {
        NumberArray<int> temp(3);

        temp.setNumber(0, 1);
        temp.setNumber(1, 2);
        temp.setNumber(2, 3);

        temp.print();
    }

    // Once the block ends, the destructor should automatically run
    cout << "The temporary array above should have already called its destructor." << endl;

    printSeperator();

    return 0;
}

// A simple cout print function to make it easier to read the cmd output
void printSeperator() {
    cout << "------------------------------------------" << endl;
}