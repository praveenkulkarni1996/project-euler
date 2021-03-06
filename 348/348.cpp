#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

//  returns true if it is a palindrome
inline bool palindrome(long long num) {
    const string str = to_string(num);
    const int len = str.length();
    for(int i = 0; i < len >> 1; ++i) if(str[i] != str[len - 1 - i]) return false;
    return true;
}

//  assuming all the numbers are less than n defined below
const int n = (int)1e9;
unsigned char counter[n];

int main() {
    //  this loop should take a while
    //  itll take a few seconds
    int x, y;
    for(int i = 2; (x = i * i * i) < n; ++i)
        for(int j = 2; (y = x + j * j) < n; ++j)
            counter[y]++;
    

    long long sum = 0;
    int countdown = 5;
    
    for(int i = 0; i < n && countdown; ++i) 
        if (counter[i] == 4 && palindrome(i))
            sum += i, countdown--;

    printf("%lld\n", sum);
}
/*
 * 5229225
 * 37088073
 * 56200265
 * 108909801
 * 796767697
 * sum = 1004195061
 */
