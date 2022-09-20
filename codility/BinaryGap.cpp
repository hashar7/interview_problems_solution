#include <iostream>

/*
 * Find longest sequence of zeros in binary representation of an integer.
 */

int BinaryGap(int n) {
    bool is_one = false;
    int gap = 0;
    int max_gap = 0;
    while (n != 0) {
        if (n % 2 == 1) {
            if (!is_one) {
                is_one = true;
            }
            max_gap = std::max(max_gap, gap);
            gap = 0;
        } else {
            if (is_one) {
                gap++;
            }
        }
        n >>= 1;
    }
    return max_gap;
}

int main() {
    return 0;
}
