#include <iostream>
#include <set>
using namespace std;
int grid[80][80];
int mark[80][80];
int dist[80][80];
int main() {
    freopen("p083_matrix.txt", "r", stdin);
    for(int i = 0; i < 80; ++i) for(int j = 0; j < 80; ++j) scanf("%d,", &grid[i][j]);
    for(int i = 0; i < 80; ++i) for(int j = 0; j < 80; ++j) mark[i][j] = false, dist[i][j] = (int)1e8 + 10;
    set<pair<int, pair<int, int> > > q;
    dist[0][0] = grid[0][0];
    for(int i = 0; i < 80; ++i) for(int j = 0; j < 80; ++j) q.insert(make_pair(dist[i][j], make_pair(i, j)));
    while(q.empty() == 0) {
         auto u = *q.begin() ;   q.erase(q.begin());
         int x = u.second.first; 
         int y = u.second.second;
         if(x == 79 && y == 79) printf("%d\n", dist[79][79]);
         mark[x][y] = true;
         
         // up
         int xx, yy;
         xx = max(x - 1, 0);
         yy = y;
         if(mark[xx][yy] == false && dist[xx][yy] > dist[x][y] + grid[xx][yy]) {
             q.erase(q.find(make_pair(dist[xx][yy], make_pair(xx, yy))));
             dist[xx][yy] = dist[x][y] + grid[xx][yy];
             q.insert(make_pair(dist[xx][yy], make_pair(xx, yy)));
         }
         // down
         xx = min(x + 1, 79);
         yy = y;
         if(mark[xx][yy] == false && dist[xx][yy] > dist[x][y] + grid[xx][yy]) {
             q.erase(q.find(make_pair(dist[xx][yy], make_pair(xx, yy))));
             dist[xx][yy] = dist[x][y] + grid[xx][yy];
             q.insert(make_pair(dist[xx][yy], make_pair(xx, yy)));
         }
         // left
         xx = x;
         yy = max(y - 1, 0);
         if(mark[xx][yy] == false && dist[xx][yy] > dist[x][y] + grid[xx][yy]) {
             q.erase(q.find(make_pair(dist[xx][yy], make_pair(xx, yy))));
             dist[xx][yy] = dist[x][y] + grid[xx][yy];
             q.insert(make_pair(dist[xx][yy], make_pair(xx, yy)));
         }
         // right
         xx = x;
         yy = min(y + 1, 79);
         if(mark[xx][yy] == false && dist[xx][yy] > dist[x][y] + grid[xx][yy]) {
             q.erase(q.find(make_pair(dist[xx][yy], make_pair(xx, yy))));
             dist[xx][yy] = dist[x][y] + grid[xx][yy];
             q.insert(make_pair(dist[xx][yy], make_pair(xx, yy)));
         }
    }
}
