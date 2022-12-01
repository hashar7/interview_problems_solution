#include <bits/stdc++.h>

#define watch(x) cout << (#x) << " is " << (x) << endl
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second

using namespace std;
using ll = long long;
using ull = unsigned long long;

inline void solve() {
    int n, res = 0;
    queue<int> v[40];
    vector<int> p;
    vector<pair<int, int>> w;
    cin >> n;
    string s,t;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            v[30].push(i + 1);
        } else {
            v[s[i] - 'a'].push(i + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if(t[i]=='?'){
            res++;
            p.push_back(i+1);
        } else {
            if (!v[t[i]-'a'].empty()) {
                res++;
                w.emplace_back(v[t[i]-'a'].front(),i+1);
                v[t[i]-'a'].pop();
            } else {
                if (!v[30].empty()) {
                    res++;
                    w.emplace_back(v[30].front(),i+1);
                    v[30].pop();
                }
            }
        }
    }
    for (int i = 0; i < sz(p); i++) {
        for (int j = 0; j < 35; j++) {
            if(v[j].empty()) {
                continue;
            }
            w.emplace_back(v[j].front(),p[i]);
            v[j].pop();
            break;
        }
    }
    cout << res << endl;
    for (int i = 0; i < sz(w); i++) {
        cout << w[i].x << ' ' << w[i].y << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
