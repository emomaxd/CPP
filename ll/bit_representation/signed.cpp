#include <bitset>
#include <cstdint>
#include <iostream>

int main() {

    std::int32_t val = -1;
    std::bitset<32> bits(val);

    std::int32_t result = 0;

    for (int i = 0; i < 32; ++i) {
        if (bits[i]) {
            result += 1 << i;

            if (i == 31)
                std::cout << "-2^" << i << " = " << (1 << i) << '\n';
            else
                std::cout << "2^" << i << " =  " << (1 << i) << '\n';
        }
    }

    std::cout << "Total sum: " << result << " = 0b" << std::bitset<32>(result) << '\n';

            return 0;
}
