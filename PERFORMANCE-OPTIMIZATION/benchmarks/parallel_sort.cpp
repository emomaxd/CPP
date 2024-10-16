#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <random>
#include <vector>

auto get_time() { return std::chrono::high_resolution_clock::now(); }

int main() {
  const int N = 1 << 20;

  std::vector<int> v(N);

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(0, 255);

  std::generate(begin(v), end(v), [&]() { return dist(rng); });

  auto start = get_time();
  std::sort(std::execution::par, begin(v), end(v));
  auto finish = get_time();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
  std::cout << "Elapsed time = " << duration.count() << " ms\n";

  return 0;
}
