#include <iostream>
#include <vector>

void PrintValue(int value){
    std::cout<<"Value : "<<value<<std::endl;
}
void ForEach(const std::vector<int>& values,void(*f)(int)){
    for(int value : values)
        f(value);
}

int main(){

    std::vector<int> values={1,5,4,2,3};
    ForEach(values,PrintValue);
    ForEach(values,
            [](int value){
                std::cout<<"Lambda f values : "<<value<<std::endl;
            });


    return 0;
}