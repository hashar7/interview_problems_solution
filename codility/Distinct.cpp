#include <vector>
#include <set>

/*
 * Compute number of distinct values in an array.
 */

int solution(std::vector<int> &A) {
    std::set<int> elems;
    for (auto i: A) {
        elems.insert(i);
    }
    return static_cast<int> (elems.size());
}

int main() {
    return 0;
}
