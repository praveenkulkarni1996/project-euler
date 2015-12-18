#include <iostream>
using namespace std;

long double best = 0;
int num = 0;
int main() {
    for(int i = 4; true; ++i) {
        int d = (7 * i) / 3; d++;
        while(__gcd(d, i) != 1) d++;
        if(d > 1000000) break;
        long double curr = ((long double) (i)/ (long double)(d));
        if(curr > best) best = curr, num = i;
    } 
    printf("%d\n" , num);
}
