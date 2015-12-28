#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

const int n = 1e7 + 1;
unsigned char cfactor[n];
unsigned int sfactor[n], hfactor[n];

long long sieve() {
    for(int i = 0; i < n; ++i) {
        cfactor[i] = 0;
        sfactor[i] = i;
        hfactor[i] = 1;
    }
    for(int i = 2; i < n; ++i) {
        if(sfactor[i] == i) {
            for(int j = i; j < n; j += i) {
                cfactor[j]++;
                sfactor[j] = min((int)sfactor[j], i);
                hfactor[j] = i;
            }
        }
    }
    set<pair<int, int> > q;
    long long answer = 0;
    for(int i = n - 1; i ; --i) {
        if(cfactor[i] != 2) continue;
        int x = sfactor[i], y = hfactor[i];
        if(q.count(make_pair(x, y)) == 0) {
            q.insert(make_pair(x, y));
            answer += i;
        }
    }   
    return answer; 
}

int main() {
    printf("%lld\n", sieve());
}
