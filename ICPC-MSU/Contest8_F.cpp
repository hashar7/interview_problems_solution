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
    int n, k;
    cin >> n >> k;
    ll tmp_sum = 0;
    ll mod = 1000000007;
    unordered_map<int, unordered_set<int>> vw;
    unordered_map<int, ll> res;
    for (int i = 1; i <= n; i++) {
        unordered_set<int> tmp;
        for (int j = 1; j <= i; j++) {
            if (!(i % j)) {
                tmp.insert(j);
            }
        }
        vw.insert({i, tmp});
        res.insert({1, 1});
    }

    while (k--) {
        for (int i = n; i >= 1; i--) {
            tmp_sum = 0;
            for (auto s: vw[i]) {
                tmp_sum = (tmp_sum + res[s]) % mod;
            }
            res[i] = tmp_sum;
        }
    }

    tmp_sum = 0;
    for (auto i: res) {
        tmp_sum = (tmp_sum + i.second) % mod;
    }

    cout << tmp_sum << endl;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
