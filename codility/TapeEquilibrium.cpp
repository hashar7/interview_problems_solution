#include <iostream>
#include <vector>

/*
 * Minimize the value |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.
 */

int solution (std::vector<int> &A) {
    int ls = A[0];
    int rs = 0;
    for (unsigned i = 1; i < A.size(); i++) {
        rs += A[i];
    }
    int min_diff = std::abs(rs - ls);
    for (unsigned i = 1; i < A.size() - 1; i++) {
        ls += A[i];
        rs -= A[i];
        min_diff = std::min(min_diff, std::abs(rs - ls));
    }
    return min_diff;
}

int main() {
    return 0;
}
