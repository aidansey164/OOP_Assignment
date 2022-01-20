#include <iostream>
#include "myuint.cpp"

int main() {
    myuint<1024> a(5);
    std::cout << a.getNumber() << std::endl;
    std::cout << a.convert_to<int>() << std::endl;

    myuint<1024> b(10);
    std::cout << b.getNumber() << std::endl;
    std::cout << b.convert_to<int>() << std::endl;

    std::cout << ((a * b) / 10).convert_to<int>() << std::endl;
    return 0;

}


