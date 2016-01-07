#include <cstdio>
#include <set>
using namespace std;

set<int> q;
const int n = 1e9;
const int m = 25; // len(primeset) = 25
const unsigned char primeset[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

inline void solver() {
   q.insert(1);
   for(int i = 0; i < 25 ; ++i) {
       int p = primeset[i];
       for(int hnum : q) {
           long long nnum = (long long) hnum * p;
           if(nnum > n) break;
           else q.insert(nnum);
       }
   }
   printf("answer = %lu\n", q.size());
}

int main() {
    clock_t start = clock();
    solver();
    clock_t end = clock();
    printf("time = %f\n", double(end - start) / CLOCKS_PER_SEC);
}
