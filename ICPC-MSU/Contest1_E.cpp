#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    ll a, b, na, nb, all_a, all_b;
    bool is_multigramm, is_first;
    all_a = 0; all_b = 0;
    for(ll i = 1; i <= s.size() / 2; i++) {
        i == 1 ? is_first = true : is_first = false;
        if(s.size() % i != 0) {
            continue;
        }
        a = 0; b = 0;
        for (ll j = 0; j < i; j++) {
            s[j] == 'a' ? a++ : b++;
        }
        is_multigramm = true;
        if (is_first) {
            all_a = a;
            all_b = b;
        } else {
            if (a == 0 && all_a != 0 || b == 0 && all_b != 0 || all_a % a != 0 || all_b % b != 0) {
                continue;
            }
        }
        for (ll j = i; j < s.size(); j++) {
            if (is_first) {
                s[j] == 'a' ? all_a++ : all_b++;
            }
            if (j % i == 0) {
                if (j == i) {
                    na = 0; nb = 0;
                } else {
                    if (na != a || nb != b) {
                        is_multigramm = false;
                        if (!is_first) {
                            break;
                        }
                    }
                    na = 0; nb = 0;
                }
            }
            s[j] == 'a' ? na++ : nb++;
        }
        if (na != a || nb != b) {
            is_multigramm = false;
        }
        if (is_multigramm) {
            cout << i << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
