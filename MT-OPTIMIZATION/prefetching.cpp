#include <iostream>
#include <vector>
#include <chrono>

void sum_with_prefetch(const std::vector<int>& data) {
    long long sum = 0;
    for (size_t i = 0; i < data.size(); i++) {
        if (i + 16 < data.size()) {
            __builtin_prefetch(&data[i + 16], 0, 1);
        }
        sum += data[i];
    }
    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    std::vector<int> data(1000000, 1);
    auto start = std::chrono::high_resolution_clock::now();
    sum_with_prefetch(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    return 0;
}
