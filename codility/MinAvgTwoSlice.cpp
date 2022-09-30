#include <iostream>
#include <vector>

/*
 * Find the minimal average of any slice containing at least two elements.
 */

int solution (std::vector<int> &A) {
    int pos = 0;
    auto min_avg = static_cast<double>(INT32_MAX);
    double sum_avg;
    for (int i = 0 ; static_cast<unsigned>(i) < A.size() - 2; i++) {
        sum_avg = static_cast<double>(A[i] + A[i + 1]) / 2;
        if (sum_avg < min_avg) {
            pos = i;
            min_avg = sum_avg;
        }
        sum_avg = static_cast<double>(A[i] + A[i  + 1] + A[i + 2]) / 3;
        if (sum_avg < min_avg) {
            pos = i;
            min_avg = sum_avg;
        }
    }
    if (static_cast<double>(A[A.size() - 2] + A[A.size() - 1]) / 2 < min_avg) {
        pos = static_cast<int>(A.size()) - 2;
    }
    return pos;
}

int main() {
    return 0;
}
