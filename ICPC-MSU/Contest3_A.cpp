#include "bits/stdc++.h"

using namespace std;
using ll = long long;

inline void solve() {
   int T, n;
   unsigned minimum;
   cin >> T;
   for (int k = 0; k< T; k++) {
       cin >> n;
       auto *arr = new unsigned[n];
       minimum = UINT32_MAX;
       for (int i = 0; i < n; i++) {
           cin >> *(arr + i);
       }
       sort(arr, arr + n);
       for (int i = 1; i < n; i++) {
           minimum = min(minimum, (*(arr + i - 1) ^ *(arr + i)));
       }
       cout << minimum << endl;
       delete [] arr;
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
