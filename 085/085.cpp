#include <iostream>
#include <cstdio>
using namespace std;

const long long N = 2000000;
const long long LIM = 1414;
long long abso = 0;
long long best = N;

inline long long nc2 (int n) {
    return 1LL * n * (n - 1) / 2;
}

inline int findmin(int x) {
    int lo = 1, hi = 20000;
    long long pre = nc2(x);
    while(lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if(pre * nc2(mid) <= N) lo = mid;
        else hi = mid - 1;
    }
    return lo; 
}

inline int findmax(int x) {
    int lo = 1, hi = 20000;
    long long pre = nc2(x);
    while(lo < hi) {
        int mid = (lo + hi) / 2;
        if(pre * nc2(mid) >= N) hi = mid;
        else lo = mid + 1;
    }
    return lo; 
}

int main() {
    long long area = 0;
    for(int i = 2; i < LIM; ++i) {
        int low = findmin(i);
        abso = N - 1LL * nc2(low) * nc2(i);
        if(abso < best) {
            area = 1LL * (i - 1) * (low - 1);
            best = abso;
        }
        int high = findmax(i);
        abso = 1LL * nc2(high) * nc2(i) - N;
        if(abso < best) {
            area = 1LL * (i - 1) * (high - 1);
            best = abso;
        }
    }
    printf("%lld\n", area);
}
