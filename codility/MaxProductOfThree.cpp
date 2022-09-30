#include <vector>
#include <algorithm>

/*
 * Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).
 */

int solution(std::vector<int> &A) {
    std::sort(A.begin(), A.end());
    return std::max(A[0] * A[1] * A[A.size() - 1],
                    std::max(A[A.size() - 1] * A[A.size() - 1 - 1] * A[A.size() - 1 - 2], INT32_MIN));
}

int main() {
    return 0;
}
