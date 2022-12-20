#include <bits/stdc++.h>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second
#define MAX_N 200010

using namespace std;
using ll = long long;
using ull = unsigned long long;

int dp[MAX_N];
int anc[MAX_N][18];
vector<int> adj[MAX_N];

void build_table(int u = 0, int p = -1) {
    anc[u][0] = p;
    for(int i = 1;i < 18; i++) {
        anc[u][i] = anc[u][i - 1] != -1 ? anc[anc[u][i - 1]][i - 1] : -1;
    }
    for(int v: adj[u]) {
        if(v ^ p) {
            dp[v] = dp[u] + 1;
            build_table(v, u);
        }
    }
}

int lca(int u, int v) {
    if(dp[u]< dp[v]) {
        swap(u, v);
    }
    for(int i = 17; i >= 0; i--) {
        if (dp[u] - (1 << i) >= dp[v]) {
            u = anc[u][i];
        }
    }
    if(u == v) {
        return u;
    }
    for(int i = 17;i >= 0; i--) {
        if (anc[u][i] ^ anc[v][i]) {
            u = anc[u][i], v = anc[v][i];
        }
    }
    return anc[u][0];
}

inline void solve() {
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build_table();
    while(m--) {
        int k;
        cin >> k;
        vector<int> query(k);
        for(int i=0;i<k;i++) {
            cin >> query[i], query[i]--;
        }
        sort(query.begin(), query.end(), [](const int &i, const int &j) {
            return dp[i] < dp[j];
        });
        bool ok = true;
        for(int i = 0;i < k - 1 && ok; ++i) {
            ok = dp[query[i]] <= dp[lca(query[i], query[k - 1])] + 1;
        }
        cout << (ok ? "YES" : "NO") << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
