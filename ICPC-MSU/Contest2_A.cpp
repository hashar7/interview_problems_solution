#include "bits/stdc++.h"
using namespace std;
using ll = long long;

inline bool opening(char &c) {
    return c == '(' || c == '[' || c == '{';
}

inline bool is_match(char &a, char &b) {
    switch (a) {
        case '(':
            return b == ')';
        case '[':
            return b == ']';
        case '{':
            return b == '}';
        default:
            return false;
    }
}

inline void solve() {
    string s;
    unsigned idx = 0;
    stack<pair<unsigned, char>> stack;
    cin >> s;
    auto sz = s.size();
    unsigned arr[sz];
    memset(arr, 0, sizeof(arr));
    for (auto &c: s) {
        if (opening(c)) {
            stack.push({idx++, c});
        } else {
            if (stack.empty()) {
                cout << "-1" << endl;
                return;
            }
            auto top = stack.top();
            if (is_match(top.second, c)) {
                arr[top.first] = idx;
                arr[idx++] = top.first;
                stack.pop();
            } else {
                cout << "-1" << endl;
                return;
            }
        }
    }
    if (!stack.empty()) {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i < sz; i++) {
        if (i == sz - 1) {
            cout << arr[i] << endl;
            return;
        }
        cout << arr[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
