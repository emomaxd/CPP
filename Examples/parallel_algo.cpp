#include <execution>
#include <numeric>
#include <vector>


int main(){
    std::vector<int> v(1 << 30);

    // Need to link with libtbb -> -ltbb
    // in linux sudo apt-get install libtbb
    // in windows i have no clue

    // in the example i ve seen
    // serial version took   -> 11 seconds
    // parallel version took -> 5 seconds
    auto r = std::reduce(std::execution::par_unseq, v.begin(), v.end(), 0);

    return r;
}