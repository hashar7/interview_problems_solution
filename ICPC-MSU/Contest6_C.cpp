#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;

void sieve_of_eratosthenes(int n, unordered_set<int> &s) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p]) {
            s.insert(p);
        }
}

void solve() {
    int n;
    unordered_set<int> s;
    cin >> n;
    sieve_of_eratosthenes(n + 1, s);
    vector<int> res(n + 2);

    if (n == 1) {
        cout << "1" << endl;
        cout << "1" << endl;
        return;
    }
    if (n == 2) {
        cout << "1" << endl;
        cout << "1 1" << endl;
        return;
    }

    cout << 2 << endl;

    for (int i = 2; i <= n + 1; i++) {
        if (s.find(i) != s.end()) {
            cout << "1 ";
        } else {
            cout << "2 ";
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
