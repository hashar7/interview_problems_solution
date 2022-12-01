#include <iostream>
#include <vector>
#include <algorithm>

#define watch(x) cout << "\n" << (#x) << " is " << (x) << endl
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second

using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void solve() {
    int t, n;
    ll e;
    cin >> t;
    vector<ll> a;
    for (int i = 0; i < t; i++) {
        cin >> n;
        a.clear();
        for (int j = 0; j < n; j++) {
            cin >> e;
            a.push_back(e);
        }
        if (a[n - 2] > a[n - 1]) {
            cout << "-1" << endl;
            continue;
        }
        if (is_sorted(all(a))) {
            cout << "0" << endl;
            continue;
        }
        if (a[n - 1] >= 0) {
            cout << n - 2 << endl;
            for (int j = 0; j < n - 2; j++) {
                cout << j + 1 << " " << n - 1 << " " << n << endl;
            }
            continue;
        }
        cout << "-1" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
