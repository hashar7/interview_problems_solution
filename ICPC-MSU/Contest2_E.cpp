#include "bits/stdc++.h"

using namespace std;
using ll = long long;

inline void print_deque(deque<ll> &deque) {
    cout << "[";
    for (long long & i : deque) {
        cout << i << " ";
    }
    cout << "]" << endl;
}

inline void solve() {
    ll n, q, elem, max_elem = INT64_MIN, idx = 1, m;
    deque<ll> deque;
    map<ll, pair<ll, ll>> map;
    cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> elem;
        if (elem > max_elem) {
            max_elem = elem;
        }
        deque.push_back(elem);
    }
    while (deque.front() != max_elem) {
        ll a, b;
        a = deque[0];
        b = deque[1];
        map[idx++] = {a, b};
        deque.pop_front();
        deque.pop_front();
        if (a > b) {
            deque.push_front(a);
            deque.push_back(b);
        } else {
            deque.push_front(b);
            deque.push_back(a);
        }
    }
    map[idx] = {deque[0], deque[1]};

    for (ll i = 0; i < q; i++) {
        cin >> m;
        if (m <= idx) {
            cout << map[m].first << " " << map[m].second << endl;
        } else {
            ll point = (m + 1 - (idx + 1)) % (n - 1) + 1;
            cout << max_elem << " " << deque[point] << endl;
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
