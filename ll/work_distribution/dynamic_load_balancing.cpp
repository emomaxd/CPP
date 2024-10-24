#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>

const int N = 1000000;
const int NUM_THREADS = 4;

std::atomic<int> next_task(0);
std::mutex output_mutex;

void dynamic_work(int thread_id) {
    while (true) {
        int task_index = next_task.fetch_add(1);
        if (task_index >= N) break;

        std::lock_guard<std::mutex> lock(output_mutex);
        std::cout << "Thread " << thread_id << " processing task " << task_index << "\n";
    }

    std::lock_guard<std::mutex> lock(output_mutex);
    std::cout << "Thread " << thread_id << " completed.\n";
}

int main() {
    std::vector<std::thread> threads;

    for (int t = 0; t < NUM_THREADS; ++t) {
        threads.push_back(std::thread(dynamic_work, t));
    }

    for (auto& th : threads) {
        th.join();
    }

    std::cout << "All threads completed.\n";
    return 0;
}
