#include <iostream>

#include "MyClass.h"

int main(int argc, char* argv[]) {
    auto myObj = new MyClass();
    std::cout << "Hello world " << myObj->doStuff() << std::endl;
    return 0;
}