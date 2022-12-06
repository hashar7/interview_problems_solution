#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<int> c(m + 1);
    vector<int> mc(m + 1);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 1; i < m+1; i++) {
        cin >> c[i];
    }
    mc[m] = c[m];
    sort(all(x));
    for (int i = m-1; i >= 0; i--) {
        mc[i] = min(mc[i + 1], c[i]);
    }
    dp[0] = mc[1];
    for (int i = 1; i < n; i++) {
        dp[i] = mc[x[i]-x[0]+ 1];
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j] + mc[x[i] - x[j + 1] + 1]);
        }
    }
    cout << dp[n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
