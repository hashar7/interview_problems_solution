#include <bits/stdc++.h>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second
#define INF 100000007
#define MAX_C 1001

using namespace std;
using ll = long long;
using ull = unsigned long long;

inline bool is_valid_coord(int X, int Y) {
    return X >= 0 && X <= MAX_C && Y >= 0 && Y <= MAX_C;
}

inline void solve() {
    pair<int, int> p;
    queue<pair<int, int>> zero_away, one_away;
    int **A = new int *[MAX_C + 1];
    int **D = new int *[MAX_C + 1];
    int n;
    for (int i = 0; i < MAX_C + 1; i++) {
        A[i] = new int [MAX_C + 1];
        D[i] = new int [MAX_C + 1];
        memset(A[i], 0, MAX_C + 1);
        memset(D[i], 0, MAX_C + 1);
    }
    cin >> n >> p.x >> p.y;
    D[p.x][p.y] = 1;
    zero_away.push(p);
    for (int i = 0; i < n; i++) {
        cin >> p.x >> p.y;
        A[p.x][p.y] = 1;
    }
    while (!zero_away.empty() || !one_away.empty()) {
        if (zero_away.empty()) {
            while (!one_away.empty()) {
                zero_away.push(one_away.front());
                one_away.pop();
            }
        }
        p = zero_away.front();
        zero_away.pop();
        if (is_valid_coord(p.x - 1, p.y) &&
            (D[p.x - 1][p.y] == 0 || D[p.x][p.y] + A[p.x - 1][p.y] < D[p.x - 1][p.y])) {
            D[p.x - 1][p.y] = D[p.x][p.y] + A[p.x - 1][p.y];
            A[p.x - 1][p.y] == 0 ? zero_away.push({p.x - 1, p.y}) : one_away.push({p.x - 1, p.y});
        }
        if (is_valid_coord(p.x + 1, p.y) &&
            (D[p.x + 1][p.y] == 0 || D[p.x][p.y] + A[p.x + 1][p.y] < D[p.x + 1][p.y])) {
            D[p.x + 1][p.y] = D[p.x][p.y] + A[p.x + 1][p.y];
            A[p.x + 1][p.y] == 0 ? zero_away.push({p.x + 1, p.y}) : one_away.push({p.x + 1, p.y});
        }
        if (is_valid_coord(p.x, p. y - 1) &&
            (D[p.x][p.y - 1] == 0 || D[p.x][p.y] + A[p.x][p.y - 1] < D[p.x][p.y - 1])) {
            D[p.x][p.y - 1] = D[p.x][p.y] + A[p.x][p.y - 1];
            A[p.x][p.y - 1] == 0 ? zero_away.push({p.x, p.y - 1}) : one_away.push({p.x, p.y - 1});
        }
        if (is_valid_coord(p.x, p. y + 1) &&
            (D[p.x][p.y + 1] == 0 || D[p.x][p.y] + A[p.x][p.y + 1] < D[p.x][p.y + 1])) {
            D[p.x][p.y + 1] = D[p.x][p.y] + A[p.x][p.y + 1];
            A[p.x][p.y + 1] == 0 ? zero_away.push({p.x, p.y + 1}) : one_away.push({p.x, p.y + 1});
        }
    }
    cout << D[0][0] - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
