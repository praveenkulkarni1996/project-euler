//  228
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    freopen("p102_triangles.txt", "r", stdin);
    int count = 0, x1, x2, x3, y1, y2, y3;
    for(int i = 0; i < 1000; ++i) {
        scanf("%d,%d,%d,%d,%d,%d\n", &x1, &y1, &x2, &y2, &x3, &y3);
        int area1 = abs((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
        int area2 = abs(x1*y2 - x2*y1) + abs(x2*y3 - x3*y2) + abs(x3*y1 - x1*y3);
        //printf("%d == %d\n", area1, area2);
        if(area1 == area2) count++;
    }
    printf("%d\n", count);
}
