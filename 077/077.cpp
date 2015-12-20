#include <iostream>
#include <vector>
using namespace std;

const int n = (int)1e2;
vector<bool> prime (n, true);
vector<int> primeset;
vector<int> f[n];

void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < n; ++i) if(prime[i]) {
        for(int j = i * i ; j < n; j += i)
            prime[j] = false;
    }
    primeset.push_back(-1);
    for(int i = 0; i < n; ++i) if (prime[i]) primeset.push_back(i);
}

int main() {
    sieve();
    f[0].push_back(1);
    for(int i = 1; i < n; ++i) {
        f[i].push_back(0);
        for(int j = 1; j < primeset.size(); ++j) {
            int p = primeset[j];
            if(p > i) break;
            else f[i].push_back(f[i].back() + f[i - p][min(j, (int)f[i - p].size() - 1)]);
        }
        if(f[i].back() > 5000) {
            printf("%d\n", i);
            break;
        }
    }
}
