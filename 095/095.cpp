#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;

const int n = (int)1e6 + 1;
int factor[n];
unsigned int small[n];
unsigned char counter[n];
long long sumdiv[n];
int len[n];

void sieve() {
    for(int i = 0; i < n; ++i) factor[i] = i;
    for(int i = 2; i * i < n; ++i) {
        if(factor[i] == i) {
            for(int j = i * i; j < n; j += i) {
                if(factor[j] > i)
                    factor[j] = i;
            }
        }
    }
    for(int i = 1; i < n; ++i) counter[i] = 1;
    for(int i = 2; i < n; ++i) {
        if(factor[i] == factor[i / factor[i]])
            counter[i] += counter[i / factor[i]];
    }
    for(int i = 1; i < n; ++i) sumdiv[i] = 1;
    for(int i = 2; i < n; ++i) {
        int x = pow(factor[i], counter[i]);
        sumdiv[i] = sumdiv[i / factor[i]] + (x * sumdiv[i / x]);
    }
    for(int i = 0; i < n; ++i) sumdiv[i] -= i;
    for(int i = 0; i < n; ++i) small[i] = i;
}
set<int> chain;

int main() {
    clock_t start = clock();
    sieve(); 
    for(int i = 0; i < n; ++i)  {
        len[i] = 0; 
        small[i] = int(1e6) + 10;
    }
    for(int i = 1; i < n; ++i) {
        int l = 0, x = i, smallest = i;
        chain.clear();
        while(chain.count(x) == 0) {
            l++, chain.insert(x);
            x = sumdiv[x];
            smallest = min(smallest, x);
            if(x > 1e6 || x == 0) { 
                l = -1;
                break;
            }
        }
        if(x == i) 
            small[i] = smallest, len[i] = l;
    }
    int longest = 0;
    for(int i = 1; i < n; ++i) if(len[i] > len[longest]) longest = i;
    printf("%d\n", small[longest]);
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
