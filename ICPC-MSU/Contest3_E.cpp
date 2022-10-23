#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void print_array(pair<ll, ll> *arr, int n) {
    cout << "{" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a = " << (arr + i)->first << "; b = " << (arr + i)->second << endl;
    }
    cout << "}" << endl;
}

ll func(pair<ll, ll> *arr, int n) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += (arr + i)->first * i + (arr + i)->second * (n - i - 1);
    }
    return res;
}

bool compare_new_asc(const pair<ll, ll> & p1, const pair<ll, ll> & p2) {
    return p1.first - p1.second > p2.first - p2.second;
}

inline void solve() {
    int n, a, b;
    cin >> n;
    auto *arr = new pair<ll, ll>[n];
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        *(arr + i) = make_pair(a, b);
    }
    sort(arr, arr + n, &compare_new_asc);
    cout << func(arr, n) << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
