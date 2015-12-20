#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int n = (int)1e8;
vector<bool> prime (n, true);
vector<int> primeset;

void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < n; ++i) if (prime[i]) {
        for(int j = i * i; j < n; j += i)
            prime[j] = false;
    }
    for(int i = 5; i < n; ++i) if (prime[i])
        primeset.push_back(i);
}

int mod(int a, int b) {
      return ((a%b)+b)%b;
}
int extended_euclid(int a, int b, int &x, int &y) {  
    int xx = y = 0;
    int yy = x = 1;
    while (b) {
        int q = a/b;
        int t = b; b = a%b; a = t;
        t = xx; xx = x-q*xx; x = t;
        t = yy; yy = y-q*yy; y = t;
    }
    return a;
}

int mod_inverse(int a, int n) {
    int x, y;
    int d = extended_euclid(a, n, x, y);
    return mod(x,n);
}

int main() {
    sieve();
    long long total = 0;
    for(int p : primeset) {
        long long ans = 0;
        long long inv = mod_inverse(p - 2, p);
        ans += inv;
        inv = (inv * mod_inverse(p - 3, p)) % p;
        ans += inv;
        inv = (inv * mod_inverse(p - 4, p)) % p;
        ans += inv;
        total += ans % p;
    }
    printf("%lld\n", total);
}
//  139602943319822
