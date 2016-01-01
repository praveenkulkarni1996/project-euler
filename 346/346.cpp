#include <iostream>
#include <map>
using namespace std;

const long long n = 1e12;
map<long long, unsigned int> ways; 

void solver() {
    long long ans = 1;
    for(int i = 2; i * 1LL * i + i * 1LL + 1LL < n; ++i) {
       long long x = i * 1LL * i + i * 1LL + 1LL; 
       while(x < n) {
           ways[x]++;
           x = (x * i) + 1;
       }
    }
    for(auto ii : ways) {
        ans += ii.first;
    }
    printf("%lld\n", ans);
}

int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
