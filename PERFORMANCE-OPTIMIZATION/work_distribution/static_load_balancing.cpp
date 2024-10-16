#include <iostream>
#include <thread>
#include <vector>

const int NUM_THREADS = 4;
const int N = 1000000;

void work(int start, int end, int thread_id) {
    for (int i = start; i < end; ++i) {
    }
    std::cout << "Thread " << thread_id << " completed.\n";
}

int main() {
    std::vector<std::thread> threads;
    int chunk_size = N / NUM_THREADS;

    for (int t = 0; t < NUM_THREADS; ++t) {
        int start = t * chunk_size;
        int end = (t == NUM_THREADS - 1) ? N : start + chunk_size;
        threads.push_back(std::thread(work, start, end, t));
    }

    for (auto& th : threads) {
        th.join();
    }

    std::cout << "All threads completed.\n";
    return 0;
}
