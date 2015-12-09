#include <iostream>
using namespace std;
const unsigned long long LOWER = 101010101;
const unsigned long long UPPER = 138902662;

inline bool check(unsigned long long ans) {
    if((ans % 1000) - (ans % 100) == 800) 
    if((ans % 100000) - (ans % 10000) == 70000) 
    if((ans % 10000000) - (ans % 1000000) == 6000000) 
    if((ans % 1000000000) - (ans % 100000000) == 500000000) 
    if((ans % 100000000000) - (ans % 10000000000) == 40000000000) 
    if((ans % 10000000000000) - (ans % 1000000000000) == 3000000000000) 
    if((ans % 1000000000000000) - (ans % 100000000000000) == 200000000000000) 
    {
        //printf("%lld\n", ans);
        return true;
    }
   
    return false;
}

int main() {
    unsigned long long x = LOWER - 1;
    for(; x < UPPER ; x += 10) {
        //cout << x << "\n";
        if(check((x + 3) * (x + 3))) { printf("%lld0\n", x + 3); return 0;}
        if(check((x + 7) * (x + 7))) { printf("%lld0\n", x + 7); return 0;}
    }
}
