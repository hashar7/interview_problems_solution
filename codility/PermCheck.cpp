#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
 * Check whether array A is a permutation.
 */

int solution (std::vector<int> &A) {
    if (A.size() == 1) {
        return A[0] == 1;
    }
    if (A.size() == 2) {
        return (A[0] == 1 && A[1] == 2) || (A[0] == 2 && A[1] == 1);
    }
    std::sort(A.data(), A.data() + A.size());
    if ((unsigned) A.back() != A.size()) {
        return 0;
    }
    for (unsigned i = 1; i < A.size(); i++) {
        if (A[i] - A[i - 1] != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    return 0;
}
