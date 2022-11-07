#include "bits/stdc++.h"

#define sz(x) (int)(x).size()

using namespace std;
using ull = unsigned long long;

void print_vec(vector<ull> &v) {
    cout << "[ ";
    for (auto e: v) {
        cout << e << " ";
    }
    cout << "]" << endl;
}

void solve() {
    int q, x;
    ull y, tmp = 0, lst;
    cin >> q >> x;
    vector<ull> freq(x);
    while (q--) {
        cin >> y;
        ++freq[y % x];
        lst = tmp;
        while(freq[lst % x]) {
            --freq[lst % x];
            ++lst;
        }
        cout << lst << endl;
        tmp = lst;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
