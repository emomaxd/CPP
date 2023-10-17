#include <iostream>

void goesWrong() {
    bool error1Detected = false;
    bool error2Detected = true;

    if(error1Detected) {
        throw std::bad_alloc();
    }

    if(error2Detected) {
        throw std::exception();
    }

}


int main(){

    try{
        goesWrong();
    }
    catch(std::exception& e) {
        std::cout << "Catching exception : " << e.what() << "\n";
    }
    catch(std::bad_alloc& e) {
        std::cout << "Catching exception : " << e.what() << "\n";
    }

    

    return 0;
}