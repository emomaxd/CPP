#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <chrono>

class Washroom {
private:
    std::mutex mtx;
    sem_t boysSem;
    sem_t girlsSem;
    int boysIn = 0;
    int girlsIn = 0;

public:
    Washroom() {
        sem_init(&boysSem, 0, 1);
        sem_init(&girlsSem, 0, 1);
    }

    ~Washroom() {
        sem_destroy(&boysSem);
        sem_destroy(&girlsSem);
    }

    void useBoysWashroom() {
        sem_wait(&boysSem);
        {
            std::lock_guard<std::mutex> lock(mtx);
            while (girlsIn > 0) { 
                sem_post(&boysSem); 
                std::this_thread::yield();
                sem_wait(&boysSem); }
            boysIn++;
            std::cout << "Boys are using the washroom. Current boys: " << boysIn << std::endl;
        }
        sem_post(&boysSem); for other boys

        washroom
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        {
            std::lock_guard<std::mutex> lock(mtx);
            boysIn--;
            std::cout << "A boy left the washroom. Current boys: " << boysIn << std::endl;
        }
    }

    void useGirlsWashroom() {
        sem_wait(&girlsSem); to enter
        {
            std::lock_guard<std::mutex> lock(mtx);
            while (boysIn > 0) { are in
                sem_post(&girlsSem); 
                std::this_thread::yield();
                sem_wait(&girlsSem); }
            girlsIn++;
            std::cout << "Girls are using the washroom. Current girls: " << girlsIn << std::endl;
        }
        sem_post(&girlsSem);

        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        {
            std::lock_guard<std::mutex> lock(mtx);
            girlsIn--;
            std::cout << "A girl left the washroom. Current girls: " << girlsIn << std::endl;
        }
    }
};

void boy(Washroom& washroom) {
    washroom.useBoysWashroom();
}

void girl(Washroom& washroom) {
    washroom.useGirlsWashroom();
}

int main() {
    Washroom washroom;
    
    std::thread boys[5];
    std::thread girls[5];

    for (int i = 0; i < 5; ++i) {
        boys[i] = std::thread(boy, std::ref(washroom));
        girls[i] = std::thread(girl, std::ref(washroom));
    }

    for (int i = 0; i < 5; ++i) {
        boys[i].join();
        girls[i].join();
    }

    return 0;
}
