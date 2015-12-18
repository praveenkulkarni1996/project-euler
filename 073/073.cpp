#include <iostream>
using namespace std;
int main() {
    int count = 0;
    for(int i = 4; i <= 12000; ++i) {
        int hi = (i - 1)/ 2;
        int lo = (i + 2) / 3;
        for(int j = lo; j <= hi; ++j) {
            if (__gcd(i, j) == 1) 
                count++;
        }
    }
    printf("%d\n", count);
}
