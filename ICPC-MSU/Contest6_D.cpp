#include "bits/stdc++.h"

using namespace std;
using ll = long long;

ll bp(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

inline void solve() {
    ll t, a, b, p, x;
    cin >> t;
    while (t--) {
        cin >> a >> b >> p;
        a %= p;
        b %= p;
        if (a < 0) {
            a += p;
        }
        b = -b;
        if (b < 0) {
            b += p;
        }
        // now solving ax = b (mod p)
        // x = b / a = b * a ^ (p - 2)
        x = b * bp(a, p - 2, p);
        x %= p;
        if (x < 0) {
            x += p;
        }
        if ((a * x) % p != b % p ) {
            cout << "-1\n";
            continue;
        }
        if (a % p == 0 && b % p == 0) {
            cout << "Any\n";
            continue;
        }
        cout << x << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
