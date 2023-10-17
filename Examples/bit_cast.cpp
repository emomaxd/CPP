#include <iostream>
#include <bit>


// C++ 20 FEATURE

int main() {
    float f = 3.14f;
    int i = std::bit_cast<int>(f);

    std::cout << "Float value: " << f << std::endl; // 3.14
    std::cout << "Int value: " << i << std::endl;   // 1078523331

    return 0;
}