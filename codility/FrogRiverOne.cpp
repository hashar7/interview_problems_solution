#include <iostream>
#include <vector>
#include <map>

/*
 * Find the earliest time when a frog can jump to the other side of a river.
 */

int solution (int X, std::vector<int> &A) {
    std::map<int, bool> m;
    auto it = A.begin();
    int count = 0;
    while (m.size() < (unsigned) X && it != A.end()) {
        m.insert({*it, true});
        ++it;
        count++;
    }
    return m.size() == (unsigned) X ? --count : -1;
}

int main() {
    return 0;
}
