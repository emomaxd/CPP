#include <iostream>
#include "C:\Users\merke\Desktop\VsCode\CPP\DataStructes-Algorithms\LinkedList\include\LinkedList.hpp"

int main(void){

LinkedList<int> x;

x.Add(31);
x.Add(123131);
x.Add(989);
std::cout<<"List : "<<std::endl;
x.Print();
x.removeLast();
std::cout<<"RemoveLAST"<<std::endl;
x.Print();

return 0;
}