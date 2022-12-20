#include <bits/stdc++.h>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second

using namespace std;
using ll = long long;
using ull = unsigned long long;

static int num_used = 0;

inline void solve() {
    int n, m, xi, yi, v, num_of_vertices, num_edges, res = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>{});
    vector<bool> used(n, false);
    unordered_set<int> u;
    vector<int> num_of_edges(n, 0);
    for (int i = 0; i < n; i++) {
        u.insert(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> xi >> yi;
        graph[xi - 1].push_back(yi - 1);
        graph[yi - 1].push_back(xi - 1);
        num_of_edges[xi - 1]++;
        num_of_edges[yi - 1]++;
    }
    while (num_used < n) {
        num_of_vertices = 0;
        num_edges = 0;
        v = *u.begin();
        vector<int> stack;
        stack.push_back(v);
        num_of_vertices++;
        num_edges += num_of_edges[v];
        while (!stack.empty()) {
            v = *stack.rbegin();
            stack.pop_back();
            if (u.find(v) == u.end()) {
                continue;
            }
            u.erase(v);
            num_used++;
            for (auto it = graph[v].rbegin(); it != graph[v].rend(); it++) {
                if (u.find(*it) != u.end()) {
                    stack.push_back(*it);
                    num_of_vertices++;
                    num_edges += num_of_edges[*it];
                }
            }
        }
        if (2 * (num_of_vertices - 1) == num_edges) {
            res++;
        }
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
