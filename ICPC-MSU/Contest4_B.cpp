#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

inline void solve() {
    int n, m;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    pair<ll, ll> lr[m];
    for (int i = 0; i < m; i++) {
        cin >> lr->first >> lr->second;
        if (lr->first > a[n - 1] || lr->second < a[0]) {
            cout << "0" << endl;
        } else {
            ll *lb = lower_bound(a, a + n, lr->first);
            ll *ub = upper_bound(a, a + n, lr->second) - 1;

            if (*lb > *ub) {
                cout << "0" << endl;
            } else {
                cout << *ub - * lb << endl;
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

