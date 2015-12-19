#include <iostream>
#include <string>
using namespace std;
const int n = 10000000;
int etf[n];

void sieve() {
    for(int i = 0; i < n; ++i) etf[i] = i;
    for(int i = 2; i < n; ++i) {
        if(etf[i] == i) {
            for(int j = i; j < n; j += i) {
                etf[j] /= i;
                etf[j] *= i - 1;
            }
        }
    }
}

inline bool permutation(int a) {
    string str1 = to_string(a);
    string str2 = to_string(etf[a]);
    sort(str1.rbegin(), str1.rend());
    sort(str2.rbegin(), str2.rend());
    return (stoi(str1) == stoi(str2));
}

int main() {
    sieve();
    int minn = 0;
    long double ratio = 10000001.0;
    for(int i = 2; i < n; ++i) if (permutation(i)) {
        long double curr = (long double) i / (long double) etf[i];
        if (ratio > curr) ratio = curr, minn = i;
    }
    printf("%d\n", minn);
}
//8319823
