#include <iostream>
#include <omp.h>

int main() {
#pragma omp parallel
  {
#pragma omp critical
    {
      std::cout << "Printing from thread: " << omp_get_thread_num() << '\n';
    }
  }

  return 0;
}
