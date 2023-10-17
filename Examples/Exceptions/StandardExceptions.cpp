#include <iostream>

class CanGoWrong {
    public:
    CanGoWrong() {
        char* pMemory = new char[9999999999999];
        delete[] pMemory;
    }
};


int main(){
    try{
        CanGoWrong wrong;
    }
    catch(std::bad_alloc& e){
        std::cout << "Caught exception : " << e.what() << "\n";
    }

    std::cout << "Still running\n";

    return 0;
}