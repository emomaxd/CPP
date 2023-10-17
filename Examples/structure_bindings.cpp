#include <iostream>

struct Value{

    int x, y;
};


Value func(int n){
    return {n, n+1};
}


int main(){

    const auto& [x, y] = func(5);

    std::cout << x << "\n"; // 5
    std::cout << y;         // 6

    return 0;
}