#include <iostream>
#include <vector>

int solution(std::vector<int> &A) {
    int zero_count = 0;
    int cars_passed = 0;
    for (auto &i: A) {
        if (i == 0) {
            zero_count++;
        } else {
            cars_passed += zero_count;
            if (cars_passed > 1000000000) {
                return -1;
            }
        }
    }
    return cars_passed;
}

int main() {
    return 0;
}
