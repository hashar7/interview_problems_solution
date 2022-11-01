#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve() {
    ll n, k, l, r;
    ull min_, s, ad, sb;
    cin >> n >> k;
    ll a[n];
    ll a_ini[n];
    unordered_map<ll, ull> um;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a_ini[i] = a[i];
    }
    sort(a, a + n);
    l = 0;
    r = k;
    min_ = UINT64_MAX;
    s = 0;
    ad = 0;
    sb = 0;
    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            for (ll j = l; j <= k; j++) {
                if (j <= i) {
                    ad++;
                    s += a[i] - a[j];
                } else {
                    sb++;
                    s += a[j] - a[i];
                }
            }
            min_ = s;
            um.insert({a[i], s});
        } else {
            s = s + (a[i - 1] - a[i]) * (sb - ad);
            min_ = s;
            ad++;
            sb--;
            while (true) {
                if (l + 1 > i + 1 || r + 1 > n - 1) {
                    break;
                }
                s -= (a[i] - a[l++]);
                s += (a[++r] - a[i]);
                ad--;
                sb++;
                if (s > min_) {
                    s = min_;
                    ad++;
                    sb--;
                    l--;
                    r--;
                    break;
                } else {
                    min_ = s;
                }
            }
            um.insert({a[i], min_});
        }
    }
    for (ll i = 0; i < n; i++) {
        cout << um[a_ini[i]] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
