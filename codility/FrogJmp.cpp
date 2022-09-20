#include <iostream>

/*
 * Count minimal number of jumps from position X to Y.
 */

int solution (int X, int Y, int D) {
    return ((Y - X) / D) * D - (Y - X) < 0 ? (Y - X) / D + 1 : (Y - X) / D;
}

int main() {
    return 0;
}
