#include <iostream>
#include <thread>

void print(std::string str){
    std::cout<<str<<"\n";
}

int main(){

    std::thread t1(print,"TEST");
    t1.join();


    return 0;
}