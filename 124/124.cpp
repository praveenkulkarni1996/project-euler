//  used logarithms to compare the big numbers
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
#include <cmath>
using namespace std;

const int n = 1e5 + 1;
int factor[n];
long double rad[n];
pair<long double, int> a[n];

inline void sieve() {
    for(int i = 0; i < n; ++i) factor[i] = i;
    for(int i = 2; i * i < n; ++i) {
        if(factor[i] == i) {
            for(int j = i * i; j < n; j += i) {
                if(factor[j] > i) {
                    factor[j] = i;
                }
            }
        }
    }
    rad[0] = rad[1] = 0;
    for(int i = 2; i < n; ++i) {
        int x = factor[i] , y = factor[i / x];
        rad[i] = (x == y) ? rad[i / x] : rad[i / x] + log2l(x);
    }
    for(int i = 0; i < n; ++i) a[i] = make_pair(rad[i], i);    
    sort(a, a + n);
}

inline void solve () {
    sieve();
    printf("%d\n", a[10000].second);
}

int main() {
    clock_t start = clock();
    solve();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
