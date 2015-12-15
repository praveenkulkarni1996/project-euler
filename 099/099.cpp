#include <cstdio>
#include <cmath>

int main() {
    freopen("p099_base_exp.txt", "r", stdin);
    int linenumber = 0;
    long double ans = 0;
    for(int i = 1; i <= 1000; ++i) {
        long double base, expo;
        scanf("%Lf,%Lf", &base, &expo);
        long double temp = log10(base) * expo;
        //printf("%Lf, %Lf\n", base, expo);
        if(temp > ans)
            linenumber = i,
            ans = temp;
    }
    printf("%d\n", linenumber);
}
