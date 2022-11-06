#include "bits/stdc++.h"

#define sz(x) (int)(x).size()

using namespace std;
using ull = unsigned long long;

void solve() {
    ull n, m, x, y;
    cin >> n >> m;
    set<ull> xs, ys;
    while (m--) {
        cin >> x >> y;
        xs.insert(x);
        ys.insert(y);
        if (m > 0) {
            cout << (n - sz(xs)) * (n - sz(ys)) << " ";
        } else {
            cout << (n - sz(xs)) * (n - sz(ys));
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
