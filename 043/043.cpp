#include <iostream>
#include <string>
using namespace std;

int main() {
    char a[] = "0123456789";
    long long count = 0;
    do {
        //  d0
        if(a[0] == '0')     continue;
        
        //  div 2
        int num;
        num = (a[1] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0');
        if(num % 2 != 0)    continue;
        
        //div 3
        num = (a[2] - '0') * 100 + (a[3] - '0') * 10 + (a[4] - '0');
        if(num % 3 != 0)    continue;
        
        //div 5
        num = (a[3] - '0') * 100 + (a[4] - '0') * 10 + (a[5] - '0');
        if(num % 5 != 0)    continue;
        
        //div 7
        num = (a[4] - '0') * 100 + (a[5] - '0') * 10 + (a[6] - '0');
        if(num % 7 != 0)    continue;
        
        //div 11
        num = (a[5] - '0') * 100 + (a[6] - '0') * 10 + (a[7] - '0');
        if(num % 11 != 0)    continue;
        
        //div 13
        num = (a[6] - '0') * 100 + (a[7] - '0') * 10 + (a[8] - '0');
        if(num % 13 != 0)    continue;
        
        //div 17
        num = (a[7] - '0') * 100 + (a[8] - '0') * 10 + (a[9] - '0');
        if(num % 17 != 0)    continue;
        
        count += stoll(a);

    }while(next_permutation(a, a + 10));
    printf("%lld\n", count);

}
