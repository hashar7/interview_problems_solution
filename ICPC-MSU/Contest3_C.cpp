#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void print_array(pair<int, int> *arr, int n) {
    cout << "{" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x = " << (arr + i)->first << "; y = " << (arr + i)->second << endl;
    }
    cout << "}" << endl;
}

bool compare_new_asc(const pair<ll, ll> & p1, const pair<ll, ll> & p2) {
    return p1.first < p2.first;
}

inline void solve() {
    int n, d, x, y;
    int res = INT32_MAX;
    multiset<int> lengths;
    cin >> n >> d;                          // x <-- first
    auto *arr = new pair<int, int>[n];      // y <-- second
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        *(arr + i) = make_pair(x, y);
    }
    sort(arr, arr + n, & compare_new_asc);
    int l = 0, r = 0;
    lengths.insert(arr->second);
    while (r < n) {
        if (*lengths.rbegin() - *lengths.begin() < d) {
            lengths.insert((arr + ++r)->second);
        } else {
            res = min(res, (arr + r)->first - (arr + l)->first);
            lengths.erase(lengths.find((arr + l++)->second));
        }
    }
    cout << ((res == INT32_MAX) ? -1 : res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
