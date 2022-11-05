#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;
using ll = long long;

void solve() {
    int n, k, cnt, p = 2, max_;
    cin >> n >> k;
    list<int> lst;
    list<int> maxes;
    int a[n];
    int answ[n];
    fill(answ, answ + 1, 0);
    list<int>::iterator iter, l, r;
    unordered_map<int, list<int>::iterator> maxes_map, lst_map;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lst.push_back(a[i]);
        maxes.push_back(i + 1);
        iter = maxes.end();
        maxes_map.insert({i + 1, --iter});
        iter = lst.end();
        lst_map.insert({a[i], --iter});
    }

    while (!lst.empty()) {
        max_ = *maxes.rbegin();
        p = p == 2 ? 1 : 2;
        l = lst_map.find(max_)->second;
        r = l;
        iter = lst.end();
        iter--;
        cnt = k;
        if (l == lst.begin()) {
            maxes.erase(maxes_map.find(*l)->second);
            maxes_map.erase(*l);
            lst_map.erase(*l);
            answ[*l - 1] = p;
            lst.erase(l++);
            while (l != lst.end() && cnt-- > 0) {
                maxes.erase(maxes_map.find(*l)->second);
                maxes_map.erase(*l);
                lst_map.erase(*l);
                answ[*l - 1] = p;
                lst.erase(l++);
            }
        } else if (r == iter) {
            maxes.erase(maxes_map.find(*r)->second);
            maxes_map.erase(*r);
            lst_map.erase(*r);
            answ[*r - 1] = p;
            lst.erase(r--);
            while (r != lst.begin() && cnt-- > 0) {
                maxes.erase(maxes_map.find(*r)->second);
                maxes_map.erase(*r);
                lst_map.erase(*r);
                answ[*r - 1] = p;
                lst.erase(r--);
            }
            if (r == lst.begin() && cnt > 0) {
                maxes.erase(maxes_map.find(*r)->second);
                maxes_map.erase(*r);
                lst_map.erase(*r);
                answ[*r - 1] = p;
                lst.erase(r++);
            }
        } else {
            maxes.erase(maxes_map.find(*l)->second);
            maxes_map.erase(*l);
            lst_map.erase(*l);
            r++;
            answ[*l - 1] = p;
            lst.erase(l--);
            while (l != lst.begin() && cnt-- > 0) {
                maxes.erase(maxes_map.find(*l)->second);
                maxes_map.erase(*l);
                lst_map.erase(*l);
                answ[*l - 1] = p;
                lst.erase(l--);
            }
            if (l == lst.begin() && cnt > 0) {
                maxes.erase(maxes_map.find(*l)->second);
                maxes_map.erase(*l);
                lst_map.erase(*l);
                answ[*l - 1] = p;
                lst.erase(l);
            }
            cnt = k;
            while (r != lst.end() && cnt-- > 0) {
                maxes.erase(maxes_map.find(*r)->second);
                maxes_map.erase(*r);
                lst_map.erase(*r);
                answ[*r - 1] = p;
                lst.erase(r++);
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        cout << answ[a[i] - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}

/*
5 5
1 2 3 4 5
RTE
 */
