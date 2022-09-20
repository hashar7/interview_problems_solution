#include <iostream>
#include <vector>

/*
 * Find value that occurs in odd number of elements.
 */

int solution(std::vector<int> &A) {
    int answ = 0;
    for (int & i : A) {
        answ ^= i;
    }
    return answ;
}

int main() {
    return 0;
}
