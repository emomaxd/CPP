#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::queue<int> buffer;
const unsigned int maxBufferSize = 10;
std::mutex mtx;
std::condition_variable cv;

void producer() {
    for (int i = 0; i < 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < maxBufferSize; });

        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_all();
        lock.unlock();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer() {
    for (int i = 0; i < 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); });
        
        int value = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << value << std::endl;
        cv.notify_all();
        lock.unlock();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);
    
    prod.join();
    cons.join();
    
    return 0;
}
