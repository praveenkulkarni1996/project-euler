#include <iostream>
#include <cstdio>
using namespace std;

const int n = 1e8 + 1;
int factor[n];

int sieve() {
    int count = 0;
    for(int i = 0; i < n; ++i) factor[i] = i;
    for(int i = 2; i * i < n; ++i) {
        if(factor[i] == i) {
            for(int j = i * i; j < n; j += i) {
                if(factor[j] > i)
                    factor[j] = i;
            }
        }
    }
    for(int i = 2; i < n; ++i) {
        if(factor[i] != i) {
            int x = i / factor[i];
            if(x == factor[x]) ++count;
        }
    }
    return count;
}
int main() {
    printf("%d\n", sieve());
}

