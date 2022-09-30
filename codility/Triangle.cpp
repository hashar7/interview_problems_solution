#include <vector>
#include <algorithm>

/*
 * Determine whether a triangle can be built from a given set of edges.
 */

int solution(std::vector<int> &A) {
    if (A.size() < 3) {
        return 0;
    }
    std::sort(A.begin(), A.end());
    for (int i = 0; static_cast<unsigned>(i) < A.size() - 2; i++) {
        if (A[i] > 0 && A[i] > A[i + 2] - A[i + 1]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    return 0;
}
