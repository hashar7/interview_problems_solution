#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A) {
    int res = 1;
    std::sort(A.data(), A.data() + A.size());
    for (int i = 0; i < (int) A.size(); i++) {
        if (A[i] == res) {
            res++;
        }
    }
    return res;
}

int main() {
    return 0;
}
