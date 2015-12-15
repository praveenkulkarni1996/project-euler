#include <iostream>
#include <vector>
using namespace std;

const int n = (int)1e9;
vector<bool> prime (n, true);

void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < n; ++i) 
        if(prime[i])
            for(int j = i * i; j < n; j += i)
                prime[j] = false;
}

int main() {
    sieve();
    int count = 0;
    for (int i = 1; (2*i + 1)*(2*i + 1) < n; ++i) {
        if(prime[4*i*i + 1])       count++;
        if(prime[4*i*i - 2*i + 1]) count++;
        if(prime[4*i*i + 2*i + 1]) count++;
        if(prime[4*i*i + 4*i + 1]) count++;
        if(count * 10 <= 4*i + 1) {
            printf("%d\n", 2*i + 1);
            return 0;
        }
    }
}
