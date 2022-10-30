#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

inline void solve() {
    int N, K;
    cin >> N >> K;
    ll a[N], b[K];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < K; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < K; i++) {
        ll *ub = upper_bound(a, a + N, b[i]) - 1;
        ll *lb = lower_bound(a, a + N, b[i]);
        if (lb == a - 1) {
            lb = a;
        } else if (ub == a + N) {
            ub = a + N - 1;
        } else if (lb == a + N) {
            lb = a + N - 1;
        } else if (ub == a - 1) {
            ub = a;
        }
        if (llabs(*lb - b[i]) <= llabs(*ub - b[i])) {
            if (llabs(*lb - b[i]) == llabs(*ub - b[i])) {
                cout << min(*lb, *ub) << endl;
            } else {
                cout << *lb << endl;
            }
        } else {
            cout << *ub << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
