#include "bits/stdc++.h"

using namespace std;
using ull = unsigned long long;

inline void solve() {
   ull n, elem, n_sq, x, l = 0;
   unordered_map<ull, int> freq;
   cin >> n;
   n_sq = n * n;
   ull a[n_sq];

   for (ull i = 0; i < n_sq; i++) {
       cin >> a[i];
       if (freq.find(a[i]) != freq.end()) {
           freq[a[i]]++;
       } else {
           freq.insert({a[i], 1});
       }
   }
   sort(a, a + n_sq, greater<>());
   ull res[n];

   for (ull i = 0; i < n_sq; i++) {
       if (freq[a[i]] > 0) {
           res[l] = a[i];
           freq[res[l]]--;
           l++;
           for (ull j = 0; j < l; j++) {
               if (i != j) {
                   freq[gcd(a[i], res[j])] -= 2;
               }
           }
       }
   }

   for (ull i = 0; i < n - 1; i++) {
       cout << res[i] << " ";
   }
   cout << res[n - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
