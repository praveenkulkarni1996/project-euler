#include <iostream>
#include <vector>
using namespace std;

const int n = (int)1e6;
vector<bool> prime (n , true);
vector<int> primeset;

void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < n; ++i)  if (prime[i]) {
        for(int j = i * i; j < n; j += i)
            prime[j] = false;
    }
    primeset.push_back(-1);
    for(int i = 0; i < n; ++i) if(prime[i]) primeset.push_back(i);
}

int main() {
    sieve();
    for(int i = 1; i < primeset.size(); ++i) {
        if((i & 1) == 0) continue;
        if (2LL * i * primeset[i] > 10000000000LL) {
            printf("%d\n", i);
            break;
        }
    }
}
//  21035
