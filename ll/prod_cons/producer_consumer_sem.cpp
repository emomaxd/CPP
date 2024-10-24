#include <iostream>
#include <thread>
#include <queue>
#include <semaphore.h>
#include <chrono>

std::queue<int> buffer;
const unsigned int maxBufferSize = 10;
sem_t empty;
sem_t full;
std::mutex mtx;

void producer() {
    for (int i = 0; i < 20; ++i) {
        sem_wait(&empty);
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(i);
            std::cout << "Produced: " << i << std::endl;
        }
        sem_post(&full);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer() {
    for (int i = 0; i < 20; ++i) {
        sem_wait(&full);
        {
            std::lock_guard<std::mutex> lock(mtx);
            int value = buffer.front();
            buffer.pop();
            std::cout << "Consumed: " << value << std::endl;
        }
        sem_post(&empty);
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    sem_init(&empty, 0, maxBufferSize);
    sem_init(&full, 0, 0);

    std::thread prod(producer);
    std::thread cons(consumer);
    
    prod.join();
    cons.join();

    sem_destroy(&empty);
    sem_destroy(&full);
    
    return 0;
}
