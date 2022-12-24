#include <bits/stdc++.h>

#define endl '\n'
#define watch(x) cout << (#x) << " is " << (x) << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define x first
#define y second
#define MAX_N 10001
#define MODS_NUM 4

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef int (*Operations) (int a);

struct Ops {
    Operations operations[4] = {
            add,
            subtract,
            shift_l,
            shift_r
    };
private:
    static int add(int n) {
        if (n / 1000 != 9) {
            return n + 1000;
        }
        return n;
    }
    static int subtract(int n) {
        if (n % 10 != 1) {
            return n - 1;
        }
        return n;
    }
    static int shift_l(int n) {
        return (n % 1000) * 10 + n / 1000;
    }
    static int shift_r(int n) {
        return (n % 10) * 1000 + n / 10;
    }
}ops;

inline void solve() {
    int a, b, f, c, i;
    cin >> a >> b;
    auto used = new vector<int>(MAX_N, 0);
    auto p = new vector<int>(MAX_N, -1);
    deque<int> dq;
    deque<int> res;
    dq.push_front(a);
    (*used)[a] = 1;
    while (!dq.empty()) {
        c = dq.front();
        dq.pop_front();
        if (c == b) {
            break;
        }
        for (i = 0; i < MODS_NUM; i++) {
            f = ops.operations[i](c);
            if (!(*used)[f]) {
                (*used)[f] = 1;
                (*p)[f] = c;
                dq.push_back(f);
            }
        }
    }
    while (b != -1) {
        res.push_back(b);
        b = (*p)[b];
    }
    for (auto j = res.rbegin(); j != res.rend(); j++) {
        cout << *j << endl;
    }
    delete used;
    delete p;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
