#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void update_node_value(ll *x, const ll k) {
    ll var;
    if (*x % k <= 1) {
        var = (*x - (*x % k)) / k;
        if (var != 0) {
            *x = (*x - (*x % k)) / k;
        }
    } else {
        var = (*x + k - (*x % k)) / k;
        if (var != 0) {
            *x = (*x + k - (*x % k)) / k;
        }
    }
}

void pass() {}

void solve() {
    ll n, k, q, a, b, dist;
    cin >> n >> k >> q;
    for (ll i = 0; i < q; i++) {
        cin >> a >> b;
        if (k == 1) {
            cout << llabs(a - b) << endl;
            continue;
        }
        dist = 0;
        a > b ? swap(a, b) : pass();
        while (a != b) {
            a < b ? update_node_value(&b, k) : update_node_value(&a, k);
            dist++;
        }
        cout << dist << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
