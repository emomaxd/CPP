#include <atomic>
#include <thread>
#include <iostream>


int main(){

    std::atomic<int> counter = 0;
    auto work = [&counter](){
        for(int i = 0; i < 10000; i += 1)
            counter += 1;
    };

    std::thread t1(work), t2(work);
    t1.join();
    t2.join();

    std::cout << counter;
    return 0;
}