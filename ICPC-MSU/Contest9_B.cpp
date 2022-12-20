#include <bits/stdc++.h>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second
#define MAX_N 100010

using namespace std;
using ll = long long;
using ull = unsigned long long;

int  color[MAX_N];
int degree[MAX_N];

struct Edge{
    int u,v;
} edge[MAX_N];

inline void solve() {
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> edge[i].u >> edge[i].v;
    }
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (color[edge[i].u] != color[edge[i].v]) {
            cnt++;
            degree[edge[i].u]++;
            degree[edge[i].v]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] == cnt) {
            cout << "YES" << endl << i << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
