#include <iostream>
using namespace std;

const int n = 15;
const int N = 1 << n;
short int a[n][n];
short int dp[N];

inline void get_dp(int x) {
    int y = 0, p = __builtin_popcount(x) - 1;
    while((1 << y) <= x) {
        int z = x & (1 << y) ;
        if(z and dp[x] < dp[x - z] + a[y][p])
            dp[x] = dp[x - z] + a[y][p];
        ++y;
    }
}
inline void solver() {
    for(int i = 0; i < n; ++i) { for(int j = 0; j < n; ++j) { scanf("%hd", &a[i][j]); } }
    for(int i = 1; i < N; ++i) get_dp(i);
    printf("answer = %d\n", dp[N - 1]); 
}

int main() {
    freopen("p345_input.txt", "r", stdin);
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
