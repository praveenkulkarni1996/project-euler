#include <cstdio>
using namespace std;

const int n = (int)1e7 + 1;
int factor[n];
inline void sieve() {
    for(int i = 0; i < n; ++i) factor[i] = i;
    for(int i = 2; i * i < n; ++i) 
        if(factor[i] == i) 
            for(int j = i * i; j < n; j += i)
                if (i < factor[j]) 
                    factor[j] = i;
}

inline int countfactor(int x) {
    if(x == 1) return 1;
    int curr = 1;
    unsigned char counter = 1;
    int ans = 1;
    while(x != 1) {
        if(factor[x] == curr) counter++;
        else counter = 1;
        if(factor[x] != factor[x / factor[x]]) 
            ans *= ++counter, counter = 1;
        curr = factor[x];
        x /= factor[x];
    }
    return ans;
}

int main() {
    sieve();
    int count = 0;
    int prevcount, currcount = countfactor(2);
    for(int i = 3; i < n; ++i) {
        prevcount = currcount;
        currcount = countfactor(i);
        if(prevcount == currcount) ++count;
    }
    printf("%d\n", count);
}
