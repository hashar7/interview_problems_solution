#include <bits/stdc++.h>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second
#define INF 100000007

using namespace std;
using ll = long long;
using ull = unsigned long long;

inline int dijkstra(int **cost, int *dist, int *parent, int n) {
    memset(dist, 0, sizeof(int) * (n + 1));
    memset(parent, -1, sizeof(int) * (n + 1));
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    parent[1] = -1;
    priority_queue<pair<int, int>,
            vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        pair<int, int> front = pq.top(); pq.pop();
        int distance = front.x, node = front.y;
        if (distance > dist[node]) {
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (dist[node] + cost[node][i] < dist[i]) {
                dist[i] = dist[node] + cost[node][i];
                parent[i] = node;
                pq.push({dist[i], i});
            }
        }
    }
    return dist[n];
}

inline void solve() {
    int n, m, a, b, l;
    int original_dist, cur_node, n1, n2, res;
    int *dist, *parent;
    int **cost;
    vector<int> nodes_on_path;
    cin >> n >> m;
    cost = new int *[n + 1];
    dist = new int [n + 1];
    parent = new int [n + 1];
    for (int i = 0; i < n + 1; i++) {
        cost[i] = new int[n + 1];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cost[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> l;
        cost[a][b] = cost[b][a] = l;
    }
    original_dist = dijkstra(cost, dist, parent, n);
    cur_node = n;
    while (cur_node != -1) {
        nodes_on_path.push_back(cur_node);
        cur_node = parent[cur_node];
    }
    res = -1;
    while (nodes_on_path.size() > 1) {
        n1 = nodes_on_path.back();
        nodes_on_path.pop_back();
        n2 = nodes_on_path.back();
        cost[n1][n2] = 2 * cost[n1][n2];
        cost[n2][n1] = 2 * cost[n2][n1];
        res = max(res, dijkstra(cost, dist, parent, n) - original_dist);
        cost[n1][n2] = cost[n2][n1] = cost[n1][n2] / 2;
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
