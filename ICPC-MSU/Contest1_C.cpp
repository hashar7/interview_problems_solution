#include "bits/stdc++.h"

using namespace std;
using ll = long long;

class FreqCounter {
private:
    ll current_letter;
    ll letters_passed;
    bool reversed;
    bool is_initialized = false;
    string cmd;
    char x{};
    vector<ll> freq;
    ll q{}, n{};
public:
    FreqCounter(): current_letter(0),
    letters_passed(0), reversed(false),
    freq(vector<ll>(26, 0)) {}

    void solution() {
        cin >> q;
        for (ll i = 0; i < q; i++) {
            cin >> cmd;
            if (cmd == "cnt") {
                exec_cnt();
            } else {
                exec_rev();
            }
        }
    }

    void exec_cnt() {
        cin >> n >> x;
        if (letters_passed != n) {
            upd_cl();
        }
        cout << freq[x - 'a'] << endl;
    }

    void exec_rev() {
        cin >> n;
        if (letters_passed != n) {
            upd_cl();
        }
        reversed = !reversed;
    }

    void upd_cl() {
        if (!is_initialized) {
            if (reversed) {
                current_letter = 25;
            }
            if (n - letters_passed >= 26) {
                ll step = (n - letters_passed) / 26;
                for (auto &elem: freq) {
                    elem+= step;
                }
            }
            letters_passed += 26 * ((n - letters_passed) / 26);
            freq[current_letter]++;
            letters_passed++;
            for(;letters_passed < n; letters_passed++) {
                current_letter = reversed ? current_letter - 1 : current_letter + 1;
                current_letter = current_letter < 0 ? 25 : current_letter > 25 ? 0 : current_letter;
                freq[current_letter]++;
            }
            is_initialized = true;
        } else {
            if (n - letters_passed >= 26) {
                ll step = (n - letters_passed) / 26;
                for (auto &elem: freq) {
                    elem+= step;
                }
            }
            letters_passed += 26 * ((n - letters_passed) / 26);
            for(;letters_passed < n; letters_passed++) {
                current_letter = reversed ? current_letter - 1 : current_letter + 1;
                current_letter = current_letter < 0 ? 25 : current_letter > 25 ? 0 : current_letter;
                freq[current_letter]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);
    auto fq = FreqCounter();
    fq.solution();
    return 0;
}
