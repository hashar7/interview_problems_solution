#include <iostream>
#include <vector>
#include <algorithm>

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
    ll n, c;
    bool on_taxi = false;
    bool was_on_taxi = false;
    ll time_taxi_pos;
    ll sum_b_i;
    cin >> n >> c;
    time_taxi_pos = c;
    sum_b_i = 0;
    vector<ll> a(n), b(n), res(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 2; i <= n; i++) {
        if (on_taxi) {
            if (a[i - 1] < b[i - 1]) {
                res[i] = res[i - 1] + a[i - 1];
                time_taxi_pos = res[i - 1];
                sum_b_i = b[i - 1];
                on_taxi = false;
            } else {
                res[i] = res[i - 1] + b[i - 1];
            }
        } else {
            sum_b_i += b[i - 1];
            if (a[i - 1] < c + b[i - 1] && res[i - 1] + a[i - 1] < time_taxi_pos + sum_b_i) {
                res[i] = res[i - 1] + a[i - 1];
                if (res[i - 1] + c + b[i - 1] < time_taxi_pos + sum_b_i) {
                    time_taxi_pos = res[i - 1] + c;
                    sum_b_i = b[i - 1];
                }
            } else {
                res[i] = min(res[i - 1] + c + b[i - 1], time_taxi_pos + sum_b_i);
                on_taxi = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
