#include <iostream>
#include <vector>

/*
 * Find the missing element in a given permutation.
 */

int solution (std::vector<int> &A) {
    unsigned long long sum = 0;
    unsigned long long true_sum = (A.size() + 1) * (A.size() + 2) / 2;
    for (auto &i: A) {
        sum += i;
    }
    return (int) true_sum - sum;
}

int main() {
    return 0;
}
