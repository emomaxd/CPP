#include <iostream>
#include <concepts>

void print(std::integral auto value){
    std::cout << "Printing integral value: " << value << "\n";
}


int main(){

    print(10.5); // will give compiler error
    return 0;
}