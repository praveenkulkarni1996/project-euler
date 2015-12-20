#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 50000000;

vector<bool> prime(N, true);
vector<int> primeset;
vector<int> make (N, false);

void sieve() {
    prime[0] = prime[1] = false;
    for(int i = 2; i * i < N; ++i) {
        if(prime[i]) {
            for(int j = i * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i * i < N; ++i) if(prime[i])
        primeset.push_back(i);
}

int main() {
    sieve();
    for(int a : primeset) {
        int x = a*a*a*a;
        if(x >= N) break;
        for(int b : primeset) {
            int y = x + b*b*b;
            if(y >= N) break;
            for(int c : primeset) {
               int z = y + c*c;
               if(z >= N) break;
               else make[z] = true;
           }
        }
    }
    int count = 0;
    for(int i = 0; i < N; ++i) {
        if(make[i] == true) count++;
    }
    printf("%d\n", count);
}
