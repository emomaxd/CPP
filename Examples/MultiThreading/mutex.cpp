#include <iostream>
#include <thread>
#include <mutex>
#include <vector>



int main(){
    std::mutex m;
    auto f = [&m](int n) {
        m.lock();
        std::cout << n << "\n";
        m.unlock();
    };

    std::vector<std::jthread> v;
    for(int i = 0; i < 3; i += 1)
        v.emplace_back(f, i);
    return 0;
}