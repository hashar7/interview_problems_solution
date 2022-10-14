#include "bits/stdc++.h"
using namespace std;
using ll = long long;

inline void solve() {
    int n;
    int elem;
    cin >> n;
    stack<int> A;
    stack<int> B;
    vector<int> tmp(n);
    vector<string> res;
    bool was_popped = false;
    for (int i = 0; i < n; i++) {
        cin >> elem;
        tmp[i] = elem;
    }
    for(auto i = tmp.rbegin(); i != tmp.rend(); i++) {
        A.push(*i);
    }

    while (!A.empty()) {
        if (B.empty()) {
            B.push(A.top());
            A.pop();
            res.emplace_back("push");
        } else {
            if (B.top() >= A.top()) {
                B.push(A.top());
                A.pop();
                res.emplace_back("push");
            } else {
                if (!was_popped) {
                    elem = B.top();
                    B.pop();
                    was_popped = true;
                } else {
                    if (B.top() < elem) {
                        cout << "impossible" << endl;
                        return;
                    }
                    elem = B.top();
                    B.pop();
                }
                res.emplace_back("pop");
            }
        }
    }

    while (!B.empty()) {
        if (!was_popped) {
            elem = B.top();
            B.pop();
            was_popped = true;
        } else {
            if (B.top() < elem) {
                cout << "impossible" << endl;
                return;
            }
            elem = B.top();
            B.pop();
        }
        res.emplace_back("pop");
    }

    for (auto &i: res) {
        cout << i << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
