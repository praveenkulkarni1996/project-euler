#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <unordered_map>
using namespace std;

inline unsigned int penta(int x) {
    return (x * (3 * x - 1)) >> 1;
}

inline bool checkpenta(int x) {
    double t = (sqrt(24 * x + 1) + 1) / 6;
    return(t == int(t));
}

int solve() {
    set<int> pset;
    unordered_map<int, int> dset;
    for(int i = 1; ; ++i) {
        int x = penta(i);
        if(dset.count(x) == 1)
            return dset[x];
        for(int y : pset) {
            int diff = x - y;
            if(pset.count(diff) == 1) dset[x + y] = diff;
        }
        pset.insert(x);
    }
    return -1;
}

int main() {
    printf("%d\n", solve());
}
