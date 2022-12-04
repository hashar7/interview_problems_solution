#include <bits/stdc++.h>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second

using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "8" << endl;
        return;
    }
    ll sum = 0;
    ll mod = 1000000000;
    vector<ll> v(10, 1);
    vector<ll> temp(10);
    v[0] = 0;
    v[5] = 0;
    v[8] = 0;
    for (ll i = 1; i < n; i++) {
        temp[0] = (v[4] + v[6]) % mod;
        temp[1] = (v[6] + v[8]) % mod;
        temp[2] = (v[7] + v[9]) % mod;
        temp[3] = (v[4] + v[8]) % mod;
        temp[4] = (v[0] + v[3] + v[9]) % mod;
        temp[6] = (v[0] + v[1] + v[7]) % mod;
        temp[7] = (v[2] + v[6]) % mod;
        temp[8] = (v[1] + v[3]) % mod;
        temp[9] = (v[2] + v[4]) % mod;
        copy(all(temp), v.begin());
    }
    for (auto e: v) {
        sum = (sum + e) % mod;
    }
    cout << sum << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
