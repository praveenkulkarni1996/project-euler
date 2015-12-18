#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <set>
#include <assert.h>
using namespace std;

const int n = 40;

vector<pair<int, int> > g[n];
set<pair<int, int> > q;
int dist[n];
bool mark[n];
int mst = 0;
int total = 0;

int main() {
    freopen("p107_network.txt", "r", stdin);
    char str[1000];
    
    for(int i = 0; i < n ; ++i) {
        scanf("%s", str);
        int j = 0;
        char *token = strtok(str, "[,\n]");
        while (token != NULL) {
            if(token[0] != '-') {
                g[i].push_back(make_pair(stoi(token), j));
            }     
            token = strtok (NULL, ",");
            ++j; 
        }
    }
    for (int i = 0 ; i < n; ++i) for(int j = 0; j < g[i].size(); ++j) {
        int k = g[i][j].second;
        if(k > i)   total += g[i][j].first;
    }
    for(int i = 1; i < n ; ++i) dist[i] = (int)1e8 + 10;    dist[0] = 0;
    for(int i = 0; i < n ; ++i) mark[i] = false;
    for(int i = 0; i < n ; ++i) q.insert(make_pair(dist[i], i));
    
    while(q.empty() == false) {
        int u = q.begin()->second;  q.erase(q.begin());
        mark[u] = true;
        mst += dist[u];
        for(auto ii : g[u]) {
            int v = ii.second;
            if (mark[v] == false && dist[v] > ii.first) {
                q.erase(q.find(make_pair(dist[v], v)));
                dist[v] = ii.first;
                q.insert(make_pair(dist[v], v));
            }
        }
    }
    printf("%d\n", total - mst);
}

