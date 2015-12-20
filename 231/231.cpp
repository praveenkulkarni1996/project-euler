#include <cstdio>
using namespace std;

const int n = (int)2e7 + 1;
int factor[n + 1];
int sum[n + 1];

void sieve() {
    for(int i = 0; i < n; ++i)  factor[i] = i;
    for(int i = 2; i * i < n; ++i) {
        if(factor[i] == i) {
            for(int j = i * i; j < n; j += i) {
                factor[j] = i;
            }
        }
    }
    sum[0] = sum[1] = 0;
    for(int i = 2; i < n; ++i) sum[i] = factor[i] + sum[i / factor[i]];
}

int main() {
    sieve();
    long long answer = 0;
    for(int i = 1; i <= (int)15e6; ++i) answer += (sum[n - i] - sum[i]);
    printf("%lld\n", answer);
}
