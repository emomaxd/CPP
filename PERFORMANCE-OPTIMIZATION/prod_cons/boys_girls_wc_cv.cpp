#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

class Washroom {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int boysIn = 0;
    int girlsIn = 0;

public:
    void useBoysWashroom() {
        std::unique_lock<std::mutex> lock(mtx);
        while (girlsIn > 0) {
            cv.wait(lock);
        }
        boysIn++;
        std::cout << "Boys are using the washroom. Current boys: " << boysIn << std::endl;
        lock.unlock();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        lock.lock();
        boysIn--;
        std::cout << "A boy left the washroom. Current boys: " << boysIn << std::endl;
        cv.notify_all();
    }

    void useGirlsWashroom() {
        std::unique_lock<std::mutex> lock(mtx);
        while (boysIn > 0) {
            cv.wait(lock);
        }
        girlsIn++;
        std::cout << "Girls are using the washroom. Current girls: " << girlsIn << std::endl;
        lock.unlock();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        lock.lock();
        girlsIn--;
        std::cout << "A girl left the washroom. Current girls: " << girlsIn << std::endl;
        cv.notify_all();
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
