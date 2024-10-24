#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

auto get_time() { return std::chrono::high_resolution_clock::now(); }

int main() {
  constexpr int N = 1 << 20;

  std::vector<int> v1(N);
  std::vector<int> v2(N);

  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(0, 255);

  std::generate(begin(v1), end(v1), [&]() { return dist(rng); });
  std::generate(begin(v2), end(v2), [&]() { return dist(rng); });

  auto start = get_time();
  std::sort(begin(v1), end(v1));
  std::sort(begin(v2), end(v2));
  auto finish = get_time();

  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(finish - start);
  std::cout << "Elapsed time = " << duration.count() << " ms\n";

  return 0;
}
