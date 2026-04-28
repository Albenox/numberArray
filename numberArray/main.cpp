// main.cpp
// This file will contain the main() function used to test the NumberArray class and its methods

#include "NumberArray.h"
using namespace std;

int main() {
    NumberArray numbers1;
    numbers1.print();

    NumberArray numbers2(5);
    numbers2.print();

    return 0;
}