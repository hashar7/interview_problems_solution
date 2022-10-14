#include "bits/stdc++.h"

using namespace std;
using ll = long long;

inline void split(const string &txt, vector<string> &strs, char ch)
{
    size_t pos = txt.find( ch );
    size_t initialPos = 0;
    strs.clear();
    while(pos != string::npos) {
        strs.push_back( txt.substr( initialPos, pos - initialPos ) );
        initialPos = pos + 1;
        pos = txt.find( ch, initialPos );
    }
    strs.push_back(txt.substr(initialPos, min( pos, txt.size()) - initialPos + 1));
}

inline void perform_ops(char &op, stack<ll> &nums) {
    ll a, b;
    a = nums.top();
    nums.pop();
    b = nums.top();
    nums.pop();
    switch (op) {
        case '+':
            nums.push(a + b);
            break;
        case '-':
            nums.push(b - a);
            break;
        case '*':
            nums.push(a * b);
            break;
        case '/':
            nums.push(b / a);
            break;
        default:
            break;
    }
}

inline void solve() {
    string s;
    vector<string> split;
    stack<ll> nums;
    stack<char> ops;
    getline(cin, s);
    ::split(s, split, ' ');
    for (auto & i : split) {
        if (isdigit(i[0])) {
            nums.push(stoi(i));
        } else {
            perform_ops(i[0], nums);
        }
    }
    cout << nums.top() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    solve();
    return 0;
}
