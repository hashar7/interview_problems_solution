#include <bits/stdc++.h>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second

using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void solve() {
    int n, i, j, q;
    cin >> n;
    auto a = new vector<int>(n + 1);
    auto ans = new vector<ll>(n + 1);
    auto flag = new vector<bool>(n + 1);
    auto d = new vector<vector<int>>(n + 1, vector<int>(n + 1));
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> (*d)[i][j];
        }
    }
    for (i = 1; i <= n; i++) {
        cin >> (*a)[i];
    }
    for (q = n; q >= 1; q--) {
        (*flag)[(*a)[q]] = true;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (i == j) {
                    continue;
                }
                (*d)[i][j] = min((*d)[i][j], (*d)[i][(*a)[q]] + (*d)[(*a)[q]][j]);
                if ((*flag)[i] && (*flag)[j]) {
                    (*ans)[q] += (*d)[i][j];
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        cout << (*ans)[i] << " ";
    }
    cout << endl;
    delete a;
    delete ans;
    delete flag;
    delete d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
