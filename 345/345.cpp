#include <iostream>
#include <algorithm>
#include <cstdio>
#include <ctime>
using namespace std;

const int n = 15;
int p[n];
int num[n][n];

// brute force, should take a day to solve
// should be able to improve this by a factor of n by implementing permutation mechanics
// multithreading would be nice.
// started running at about 6:35 pm on 6 january 2015
// stopped it at ~ 1:30 the following day, 7 january it gave the corrct answer = 13938 
// but hadnt finished running, ill do this with dp and/or the hungarian algorithm 
void solver() {
    for(int i = 0; i < n; ++i) 
        p[i] = i;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            scanf("%d", &num[i][j]);
            printf("%d\t", num[i][j]);
        }
        printf("\n");
    }
    int msum = 0;
    do {
        int sum = 0;
        for(int i = 0; i < n; ++i) {
            sum += num[i][p[i]];
        }
        if(msum < sum) msum = sum, printf("%d\n", msum); 
    } while(next_permutation(p, p + n));
    printf("answer = %d\n", msum);
}

int main() {
    freopen("p345_input.txt", "r", stdin); 
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
