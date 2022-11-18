#include "bits/stdc++.h"
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
 
using namespace std;
using ull = unsigned long long;
 
void solve() {
    ull n, k;
    vector<ull> l;
    vector<ull> r;
 
    cin >> n >> k;
 
    for (ull i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            l.push_back(i);
            if (i * i != n) {
                r.push_back(n / i);
            }
        }
    }
    reverse(all(r));

    if (k > sz(l) + sz(r)) {
        cout << -1 << endl;
        return;
    }
 
    if (k <= sz(l)) {
        cout << l[k - 1] << endl;
    } else {
        cout << r[k - sz(l) - 1];
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
