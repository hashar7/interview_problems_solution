#include "bits/stdc++.h"
 
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool desc_cmp(ll p1, ll p2) {
    return p1 > p2;
}
 
void solve() {
    ll n, m;
    cin >> n >> m;
    ll a[n], b[m];
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (ll i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + m, desc_cmp);
    ull res = 0;
    for (ll i = 0; i < min(n, m) && a[i] < b[i]; i++) {
        res += (b[i] - a[i]);
    }
    cout << res << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
