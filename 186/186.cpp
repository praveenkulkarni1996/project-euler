#include <iostream>
using namespace std;

const int nmax = 1e6;
const int smax = 24e6;

int s[smax];
int par[nmax];
int rnk[nmax];

inline int find_set(const int x) {
    return (x == par[x]) ? x : par[x] = find_set(par[x]);
}
inline int rank_set(const int x) {
    return rnk[find_set(x)];
}

inline void unite(int x, int y) {
    x = find_set(x);
    y = find_set(y);
    if(x != y) {
        par[y] = x;
        rnk[x] += rnk[y];
    }
}

inline void build() {
    for(int j = 1; j <= smax; ++j) {
        long long x = j;
        if(j <= 55) s[j - 1] = (100003 - 200003*x + 300007*x*x*x) % nmax;
        else        s[j - 1] = (s[j - 25] + s[j - 56]) % nmax;
    }
}

inline void solver() {
    for(int i = 0; i < nmax; ++i) par[i] = i, rnk[i] = 1;
    int answer = 0;
    for(int i = 0; i + 1 < smax; i += 2) {
        int x = s[i], y = s[i + 1];
        if(x == y) continue;
        else answer++;
        if(find_set(x) != find_set(y)) {
            unite(x, y);
            if(rank_set(524287) >= 0.99 * nmax) {
                printf("answer = %d\n", answer);
                return;
            }
        }
    }
    return;
}
int main() {
    clock_t start = clock();
    build();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );
}
