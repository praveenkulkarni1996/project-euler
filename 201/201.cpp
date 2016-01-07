#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

const int n = 100;
const int m = 50;
const int maxsum = 297925;

unsigned int setcount[maxsum + 1][m + 1];
unsigned int setsum[maxsum + 1][m + 1];
unsigned int answer = 0;

void solve() {
    memset(setcount, 0, sizeof(setcount));
    memset(setsum, 0, sizeof(setsum));
    setcount[0][0] = 1;
    
    for(int i = 1; i <= n; ++i) {
        int p = i * i;
        for(int j = maxsum; j >= p; j--) {
            for(int k = 1; k <= m; ++k) {
                setsum[j][k] += setsum[j - p][k - 1] + setcount[j - p][k - 1] * p;
                setcount[j][k] += setcount[j - p][k - 1]; 
            }
        }
    }
    for(int i = 1; i <= maxsum; ++i) {
        if(setcount[i][50] == 1) answer += setsum[i][50];
    } 
    printf("answer = %u\n", answer);
}


int main() {
    clock_t start = clock();
    solve();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
