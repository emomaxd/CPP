#include "../include/LinkedList.hpp"
#include <iostream>
int main(void){
    LinkedList<int> x;
    x.Add(31);
    x.Add(69);
    x.Add(13);
    x.Add(31231);
    x.Add(53252352);
    std::cout<<"List : "<<std::endl;
    x.Print();

    x.removeFront();
    std::cout<<"FRONT"<<std::endl;
    x.Print();

    x.removeLast();
    std::cout<<"LAST"<<std::endl;
    x.Print();

    x.Remove(1);
    std::cout<<"REMOVE(1)"<<std::endl;
    x.Print();

    x.Remove(0);
    std::cout<<"REMOVE(0)"<<std::endl;
    x.Print();
    
    x.Remove(0);
    std::cout<<"REMOVE(0)"<<std::endl;
    x.Print();

    return 0;
}