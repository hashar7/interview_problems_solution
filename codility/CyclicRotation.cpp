#include <iostream>
#include <vector>

/*
 * Rotate an array to the right by a given number of steps.
 */

void shift_once(std::vector<int> &A) {
    int last_elem = A.back();
    for (auto i = A.size() - 1; i > 0; i--) {
        A[i] = A[i - 1];
    }
    A[0] = last_elem;
}

std::vector<int> solution(std::vector<int> &A, int K) {
    if (A.empty()) {
        return A;
    }
    long long offset = K % A.size();
    for (auto i = 0; i < offset; i++) {
        shift_once(A);
    }
    return A;
}

int main() {
    return 0;
}
