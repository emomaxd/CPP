#include <iostream>

int main(){

    //stack memory
    int as=5;

    int bs[5];

    //heap memory
    int* a=new int;
    *a=5;

    int *b=new int[5];

    delete a;
    delete[] b;






    return 0;
}