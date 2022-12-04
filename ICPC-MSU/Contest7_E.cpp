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

inline int do_work(vector<int> &a, vector<int> &b) {
    if (!sz(b)) {
        return 0;
    }
    sort(all(a));
    sort(all(b));
    auto it = a.begin();
    int cnt = 0;
    auto sz_b = sz(b);
    vector<int> last(sz_b);
    vector<bool> box_pos(sz_b);
    for (int i = 0; i < sz_b; i++) {
        while (it != a.end() && *it < b[i]) {
            cnt++; ++it;
        }
        if (it != a.end() && *it == b[i]) {
            cnt++; ++it;
            box_pos[i] = true;
        }
        last[i] = b[i] - cnt;
    }

    vector<int> box_aft(sz_b + 1);
    for (int i = sz_b - 1; i >= 0; i--) {
        box_aft[i] = box_aft[i + 1] + box_pos[i];
    }
    int res = 0;
    for (int i = 0; i < sz_b; i++) {
        res = max(res, i + 1 - int(upper_bound(all(b), last[i]) - b.begin()) + box_aft[i + 1]);
    }
    return res;
}

inline void solve() {
    int t, n, m, a, b;
    vector<int> a1, a2, b1, b2;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        a1.clear();
        a2.clear();
        b1.clear();
        b2.clear();
        for (int i = 0; i < n; i++) {
            cin >> a;
            a < 0 ? a1.push_back(abs(a)) : a2.push_back(a);
        }
        for (int i = 0; i < m; i++) {
            cin >> b;
            b < 0 ? b1.push_back(abs(b)) : b2.push_back(b);
        }
        cout << do_work(a1, b1) + do_work(a2, b2) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();

    return 0;
}
