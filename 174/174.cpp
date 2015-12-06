//  209566
#include <iostream>
#include <vector>
using namespace std;

const int NMAX = (int)1e6 + 1;
int factor[NMAX];

void sieve() {
    for(int i = 0; i < NMAX; ++i)   factor[i] = i;
    for(int i = 2; i * i < NMAX; ++i) if(factor[i] == i) {
        for(int j = i * i; j < NMAX; j += i) 
            factor[j] = min(factor[j], i);
    }
    factor[1] = -1;
}

int count(int x) {
    int afact = 1 ;
    int cfact = 1;
        
    for(int tfact = factor[x] ; ;) {
        if(tfact != factor[x])  {
            tfact = factor[x];
            afact *= cfact;
            cfact = 1;
        }
        cfact++;
        x /= factor[x] ;
        if(x == -1)  break;
    }
    return afact; 
}


int main() {
    sieve();
    int answer = 0;
    for(int i = 1; i * 4 < NMAX; i++ ) {
        int L_type = count(i);
        answer += (L_type / 2 <= 10 && L_type / 2 >= 1) ? 1 : 0;
    }
    printf("%d\n", answer);
}
