#include "bits/stdc++.h"

using namespace std;
using ll = long long;

void print_array(const unsigned *arr, unsigned N) {
    cout << "[ ";
    for (int i = 0; i < N; i++) {
        cout << *(arr + i) << " ";
    }
    cout << "]" << endl;
}

inline void solve() {
    unsigned N;
    unsigned res = 0;
    cin >> N;
    auto *arr = new unsigned[N];
    for (int i = 0; i < N; i++) {
        cin >> *(arr + i);
    }
    sort(arr, arr + N);
    unsigned maximum = *(arr + N - 1);
    unsigned l = 0, r = N - 1;
    while (maximum != 0) {
        if (r - l >= maximum) {
            for (unsigned i = l; i <= r; i++) {
                *(arr + i) -= 1;
                if (*(arr + i) != 0 && (i > 0 && *(arr + i - 1) == 0)) {
                    l = i;
                }
            }
            maximum = *(arr + r);
        } else {
            if (r > 0) {
                *(arr + r--) = 0;
                maximum = *(arr + r);
            } else {
                maximum = 0;
            }
        }
        res += 1;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
