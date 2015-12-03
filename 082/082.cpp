//	solved on December 3 , 2015
//	
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	const int n = 80;
	const int inf = (int)10000000;
	freopen("p082_matrix.txt", "r", stdin);
	int a[n + 2][n + 2], ubest[n + 2][n + 2], dbest[n + 2][n + 2], best[n + 2][n + 2];

	for (int i = 0; i < n + 2; ++i) {
		for(int j = 0; j < n + 2; ++j) {
			a[i][j] = ubest[i][j] = dbest[i][j] = inf;
			best[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d, ", &a[i][j]);
		}
	}
	for(int i = 0; i <= n + 1; ++i) {
		a[i][n + 1] = 0;	
	}
	for(int j = 1; j <= n + 1; ++j) {
		for(int i = 1; i <= n; ++i) {
			ubest[i][j] = min(ubest[i - 1][j], best[i][j - 1]) + a[i][j];
		}
		for(int i = n; i >= 1; --i) {
			dbest[i][j] = min(dbest[i + 1][j], best[i][j - 1]) + a[i][j];
		}
		for(int i = 1; i <= n; ++i) {
			best[i][j] = min(ubest[i][j], dbest[i][j]);
		}
	}
	printf("%d\n", best[1][n + 1]);
	return 0;
}