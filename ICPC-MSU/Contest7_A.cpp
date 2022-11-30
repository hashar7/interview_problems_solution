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

inline ll query(const vector<ll> &p, ll l, ll r) {
    if (l == 0) {
        return p[r];
    }
    return p[r] - p[l - 1];
}

inline void solve() {
    ll t, n, m, a, b, pos, res, count, idx, s;
    vector<pair<ll ,ll>> p;
    vector<ll> pref_sum;
    cin >> t;
    for (int i = 0; i < t; i++) {
        res = numeric_limits<ll>::min();
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            cin >> a >> b;
            p.emplace_back(a, b);
        }
        sort(all(p));
        pref_sum = vector<ll>(m);
        pref_sum[0] = p[0].x;
        for (int j = 1; j < m; j++) {
            pref_sum[j] = pref_sum[j - 1] + p[j].x;
        }
        for (int where_b = 0; where_b < m; where_b++) {
            pos = lower_bound(all(p),
                              pair<ll, ll>(p[where_b].second, 0)) - p.begin();
            if (pos == sz(p)) {
                res = max(res, p[where_b].x + (n - 1) * p[where_b].y);
                continue;
            }
            count = sz(p) - pos;
            if (count >= n) {
                s = query(pref_sum, sz(p) - n, sz(p) - 1);
                res = max(res, s);
                continue;
            }
            if (pos <= where_b) {
                s = query(pref_sum, pos, sz(p) - 1) + (n - count) * p[where_b].y;
                res = max(res, s);
                continue;
            } else {
                s = query(pref_sum, pos, sz(p) - 1) + p[where_b].x + (n - count - 1) * p[where_b].y;
                res = max(res, s);
            }
        }
        cout << res << endl;
        p.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
