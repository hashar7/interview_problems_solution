#include <iostream>
#include <vector>
#include <string>

/*
 * Find the minimal nucleotide from a range of sequence DNA.
 */

std::vector<int> solution (std::string &S, std::vector<int> &P, std::vector<int> &Q) {
    std::vector<std::vector<int>> cumulative_gen(S.size(), std::vector<int>(4, 0));
    short a = 0;
    short c = 0;
    short g = 0;
    short t = 0;
    std::vector<int> res(P.size(), 0);
    for (unsigned i = 0; i < S.size(); i++) {
        switch (S[i]) {
            case 'A':
                a = 1;
                break;
            case 'C':
                c = 1;
                break;
            case 'G':
                g = 1;
                break;
            case 'T':
                t = 1;
                break;
        }
        cumulative_gen[i][0] = cumulative_gen[i != 0 ? i - 1 : 0][0] + static_cast<int>(a);
        cumulative_gen[i][1] = cumulative_gen[i != 0 ? i - 1 : 0][1] + static_cast<int>(c);
        cumulative_gen[i][2] = cumulative_gen[i != 0 ? i - 1 : 0][2] + static_cast<int>(g);
        cumulative_gen[i][3] = cumulative_gen[i != 0 ? i - 1 : 0][3] + static_cast<int>(t);
        a = 0;
        c = 0;
        g = 0;
        t = 0;
    }

    for (unsigned i = 0; i < P.size(); i++) {
        if (Q[i] - P[i] >= 1) {
            if (cumulative_gen[Q[i]][0] - cumulative_gen[P[i]][0] > 0 || S[P[i]] == 'A') {
                res[i] = 1;
            } else if (cumulative_gen[Q[i]][1] - cumulative_gen[P[i]][1] > 0 || S[P[i]] == 'C') {
                res[i] = 2;
            } else if (cumulative_gen[Q[i]][2] - cumulative_gen[P[i]][2] > 0 || S[P[i]] == 'G') {
                res[i] = 3;
            } else if (cumulative_gen[Q[i]][3] - cumulative_gen[P[i]][3] > 0 || S[P[i]] == 'T') {
                res[i] = 4;
            }
        } else {
            res[i] = S[P[i]] == 'A' ? 1 : S[P[i]] == 'C' ? 2 : S[P[i]] == 'G' ? 3 : S[P[i]] == 'T' ? 4 : 0;
        }
    }
    return res;
}

int main() {
    return 0;
}
