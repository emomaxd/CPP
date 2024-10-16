#include <iostream>
#include <thread>

thread_local int thread_local_var = 0;

void increment() {
    for (int i = 0; i < 10000000; ++i) {
        ++thread_local_var;
        std::cout << "Thread " << std::this_thread::get_id() << " - Value: " << thread_local_var << std::endl;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.detach();
    t2.detach();

    while (true);
}
