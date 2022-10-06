#include "bits/stdc++.h"

using namespace std;

void solve() {
    short n, m;
    cin >> n >> m;
    char **c = new char *[n];
    map<string, int> freq;
    using pair_type = decltype(freq)::value_type;
    for (short i = 0; i < n; i++) {
        c[i] = new char[m];
    }
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) { continue; }
                    if (i + dx + dx < n && i + dx + dx >= 0 && j + dy + dy < m && j + dy + dy >= 0) {
                        if (c[i + dx][j + dy] == c[i + dx + dx][j + dy + dy] && c[i + dx][j + dy] != c[i][j]
                            && c[i][j] != 'M' && c[i + dx][j + dy] != 'O') {
                            string s = string() + c[i][j] + c[i + dx][j + dy];
                            if (freq.find(s) == freq.end()) {
                                freq.insert(make_pair(s, 1));
                            } else {
                                freq.find(s)->second++;
                            }
                        }
                    }
                }
            }
        }
    }
    if (freq.empty()) {
        cout << 0;
        return;
    }
    auto pr = max_element(
            begin(freq), end(freq),
            [](const pair_type &p1, const pair_type &p2) {
                return p1.second < p2.second;
            }
    );
    cout << pr->second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
