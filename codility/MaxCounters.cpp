#include <iostream>
#include <vector>

std::vector<int> solution(int N, std::vector<int> &A) {
    int max_val = 0;
    int maxed_out = 0;
    std::vector<int> r(N, 0);
    for (auto &i: A) {
        if (i == N + 1) {
            maxed_out = max_val;
        }
        if (i >= 1 && i <= N) {
            if (r[i - 1] < maxed_out) {
                r[i - 1] = maxed_out + 1;
            } else {
                r[i - 1]++;
            }
            max_val = std::max(max_val, r[i - 1]);
        }
    }
    for (int & i : r) {
        if (i < maxed_out) {
            i = maxed_out;
        }
    }
    return r;
}

int main() {
    return 0;
}
