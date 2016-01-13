#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int peter[37];
int colin[37];
int temp[37];

void solver() {
    colin[1] = colin[2] = colin[3] = colin[4] = colin[5] = colin[6] = 1; 
    for(int roll = 2; roll <= 6; ++roll) {
        for(int i = 0; i <= 36; ++i) {
            if(i - 1 > 0) temp[i] += colin[i - 1];
            if(i - 2 > 0) temp[i] += colin[i - 2];
            if(i - 3 > 0) temp[i] += colin[i - 3];
            if(i - 4 > 0) temp[i] += colin[i - 4];
            if(i - 5 > 0) temp[i] += colin[i - 5];
            if(i - 6 > 0) temp[i] += colin[i - 6];
        } 
        for(int i = 0; i <= 36; ++i) { colin[i] = temp[i]; temp[i] = 0; }
    }
    for(int i = 1; i <= 36; ++i) {
        colin[i] += colin[i - 1];
    }
    peter[1] = peter[2] = peter[3] = peter[4] = 1;
    for(int roll = 2; roll <= 9; ++roll) {
        for(int i = 0; i <= 36; ++i) {
            if(i - 1 > 0) temp[i] += peter[i - 1];
            if(i - 2 > 0) temp[i] += peter[i - 2];
            if(i - 3 > 0) temp[i] += peter[i - 3];
            if(i - 4 > 0) temp[i] += peter[i - 4];
        } 
        for(int i = 0; i <= 36; ++i) { peter[i] = temp[i]; temp[i] = 0; }
    }
    long long wincount = 0;
    long long playcount = (long long) powl(4, 9) * (long long) powl(6, 6);
    for(int i = 1; i <= 36; ++i) {
        wincount += colin[i - 1] * 1LL * peter[i];
        peter[i] += peter[i - 1];
    }  
    printf("answer = %.7Lf\n", (long double)(wincount) / (long double)(playcount));
}
int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
