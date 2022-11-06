#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve_v2() {
    unsigned N;
    multiset<ull> res;
    ull p;
    cin >> N;
    list<ull> lst;
    unordered_multimap<ull, list<ull>::iterator> umap;
    list<ull>::iterator it;
    unordered_multimap<ull, list<ull>::iterator>::iterator val;
    for (unsigned i = 0; i < N; i++) {
        cin >> p;
        lst.push_back(p);
        it = lst.end();
        umap.insert({p, --it});
    }
    lst.sort(greater<>());
    while (!lst.empty()) {
        it = lst.begin();
        val = umap.find(*it / 4 * 3);
        res.insert(val->first);
        lst.erase(val->second);
        lst.erase(it);
        umap.erase(val);
        umap.erase(umap.find(*it));
    }
    for (auto e: res) {
        cout << e << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve_v2();
    return 0;
}
