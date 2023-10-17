#include <iostream>

void mightGoWrong() {
    bool error1 = false;
    bool error2 = true;

    if(error1){
        throw "Something went wrong.";
    }
    if(error2){
        throw std::string("Something else went wrong.");
    }
}

void usesMightGoWrong(){
    mightGoWrong();
}



int main() {

    try{
        usesMightGoWrong();
    }
    catch(int e){
        std::cout << "Error code : " << e << "\n";
    }
    catch(char const* e){
        std::cout << "Error message : " << e << "\n";
    }
    catch(std::string& e){
        std::cout << "String error message : " << e << "\n";
    }

    std::cout << "Still running\n";  
    return 0;
}