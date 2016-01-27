#include <iostream>
#include <set>
using namespace std;
typedef pair<int, int> ii;
set<pair<ii, ii> > q;
const int n = 50;
inline void solver() {
    for(int a = 0; a <= n; ++a) {
        for(int b = 0; b <= n; ++b) {
            for(int c = 0; c <= n; ++c) {
                for(int d = 0; d <= n; ++d) {
                    ii point1 = make_pair(a, b);
                    ii point2 = make_pair(c, d);
                    if(point1 == point2) continue;
                    if(point1 == make_pair(0, 0)) continue;
                    if(point2 == make_pair(0, 0)) continue;
                    else if(point1 > point2) swap(point1, point2);
                    int x = (a - c) * (a - c) + (b - d) * (b - d);
                    int y = a * a + b * b;
                    int z = c * c + d * d;
                    if((x == y + z or y == x + z or z == z + y) and q.count(make_pair(point1, point2)) == 0) {
                        q.insert(make_pair(point1, point2));
                    }
                }
            }
        }
    }
    printf("answer = %d\n", int(q.size()));
}
int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC );
}
