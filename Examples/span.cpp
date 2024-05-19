#include <iostream>
#include <span>
#include <vector>

// C++ 20 -> -std=c++20

void print_subvector(std::span<int> span){
    for(auto val : span)
        std::cout << val << " ";
    std::cout << "\n";
}

int main(){

    std::vector<int> vector = {1, 2, 3, 4, 5};
    print_subvector(std::span(vector.begin(), 2));
    return 0;
}