#include "bits/stdc++.h"

#define endl '\n'

using namespace std;
using ll = long long;

inline ll mult(ll a, ll b, ll mod) {
    ll result = 0;
    while (b) {
        if (b & 1)
            result = (result + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return result;
}

inline ll f(ll x, ll c, ll mod) {
    return (mult(x, x, mod) + c) % mod;
}

inline ll rho(ll n, ll x0=2, ll c=1) {
    ll x = x0;
    ll y = x0;
    ll g = 1;
    while (g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        g = gcd(llabs(x - y), n);
    }
    return g;
}

inline void solve() {
    int n;
    ll a, b, r, tmp;
    cin >> n;
    cin >> a >> b;
    r = a * b;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        r = gcd(r, a * b);
    }
    if (r == 1) {
        cout << "-1\n";
        return;
    }
    if (r % 2 == 0) {
        cout << 2 << endl;
        return;
    }
    cout << rho(r) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
