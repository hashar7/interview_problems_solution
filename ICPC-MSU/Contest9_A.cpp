#include <bits/stdc++.h>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second
#define MAX_N 300010
#define INF 0x3f3f3f3f

using namespace std;
using ll = long long;
using ull = unsigned long long;

int op[MAX_N],dp[MAX_N],num;
vector<int> v[MAX_N];

void dfs(int p){
    if(p>1&&v[p].empty()){
        dp[p]=1,++num;
        return;
    }
    if(op[p]) {
        dp[p]=INF;
    } else {
        dp[p]=0;
    }
    for(int i=0;i<v[p].size();++i){
        dfs(v[p][i]);
        if(op[p]) {
            dp[p]=min(dp[p],dp[v[p][i]]);
        } else {
            dp[p]+=dp[v[p][i]];
        }
    }
}

inline void solve() {
    int n;
    cin >> n;
    for(int i=1;i<=n;++i) {
        cin >> op[i];
    }
    for(int i=2;i<=n;++i){
        int tmp;
        cin >> tmp;
        v[tmp].push_back(i);
    }
    dfs(1);
    cout << num + 1 - dp[1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
