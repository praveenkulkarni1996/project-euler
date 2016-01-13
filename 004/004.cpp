#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
inline bool palindrome(int x) {
    const string num = to_string(x);
    for(int i = 0; i < num.length() - 1 - i; ++i) { if(num[i] != num[num.length() - 1 - i]) return false; }
    return true;
}
void solver() {
    int answer = 0;
    for(int i = 100; i <= 999; ++i) {
        for(int j = i; j <= 999; ++j) {
            int x = i * j;
            if(x > answer and palindrome(x)) answer = x;
        }
    }
    printf("answer = %d\n", answer);
}
int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );
}
