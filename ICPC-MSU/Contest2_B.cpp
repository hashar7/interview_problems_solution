#include "bits/stdc++.h"
using namespace std;
using ll = long long;

inline void solve() {
    int q;
    stack<int> s;
    string cmd;
    int max_elem;
    int elem;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> elem;
            if (s.empty()) {
                s.push(elem);
                max_elem = elem;
            } else {
                if (elem > max_elem) {
                    s.push(2 * elem - max_elem);
                    max_elem = elem;
                } else {
                    s.push(elem);
                }
            }
        } else {
            if (cmd == "pop") {
                if (!s.empty()) {
                    elem = s.top();
                    if (elem > max_elem) {
                        max_elem = 2 * max_elem - elem;
                    }
                    s.pop();
                }
            } else {
                if (cmd == "max") {
                    cout << max_elem << endl;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
