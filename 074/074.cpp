#include <iostream>
#include <string>
#include <set>
using namespace std;

inline int nextnum(const int x) {
    const string num = to_string(x);
    int nnum = 0;
    for(char ch : num) {
        int f = 1;
        for(int i = 1; i <= ch - '0'; ++i) f *= i;
        nnum += f;
    }
    return nnum;
}

const int N = 1000000;
int dp[N];
set<int> q;

int main() {
    for(int i = 0; i < N; ++i) {
        int num = i;
        q.clear();
        while(true) {
            if(q.count(num) == 1) {
                dp[i] = q.size();
                break;
            }
            else if(i > num) {
                dp[i] = q.size() + dp[num];
                break;
            }
            q.insert(num);
            num = nextnum(num);
        }
    }
    int count = 0;
    for(int i = 0; i < N; ++i)
        if(dp[i] == 60) count++;
    printf("%d\n", count);
}
